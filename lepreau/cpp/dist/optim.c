# include "mfile1"

# define SWAP(p,q) {sp=p; p=q; q=sp;}
# define RCON(p) (p->right->op==ICON)
# define RO(p) p->right->op
# define RV(p) p->right->lval
# define LCON(p) (p->left->op==ICON)
# define LO(p) p->left->op
# define LV(p) p->left->lval

int oflag = 0;

/*
 * fortran function arguments
 */
NODE *
fortarg( p )
	NODE	*p;
{

	if( p->op == CM ){
		p->left = fortarg( p->left );
		p->right = fortarg( p->right );
		return(p);
	}

	while( ISPTR(p->type) ){
		p = buildtree( UNARY MUL, p, NIL );
	}
	return( optim(p) );
}

/*
 * mapping relationals when the sides are reversed
 */
short revrel[] = {
	EQ, NE,
	GE, GT,
	LE, LT,
	UGE, UGT,
	ULE, ULT
};

/*
 * local optimizations, most of which are probably machine independent
 */
NODE *
optim(p)
	register NODE	*p;
{
	register	o,
			ty;
	NODE		*sp;
	int		i;
	TWORD		t;
	extern int	xdebug,
			eprint();

	if((t = BTYPE(p->type)) == ENUMTY || t == MOETY)
		econvert(p);
	if( oflag )
		return(p);
	ty = optype(o = p->op);
	if( ty == LTYPE )
		return(p);

	if( ty == BITYPE )
		p->right = optim(p->right);
	p->left = optim(p->left);
	if (xdebug > 2) {
		printf("optim( %o )\n", p);
		fwalk(p, eprint, 0);
	}
	/*
	 * collect constants
	 */
	switch(o){

		case SCONV:
		case PCONV:
			return( clocal(p) );
	
		case FORTCALL:
			p->right = fortarg( p->right );
			break;
	
		case UNARY AND:
			if( LO(p) != NAME )
				cerror( "& error" );
			if( !andable(p->left) )
				return(p);
			LO(p) = ICON;
		setuleft:
			/*
			 * paint over the type of the left hand side with
			 * the type of the top
			 */
			p->left->type = p->type;
			p->left->cdim = p->cdim;
			p->left->csiz = p->csiz;
			p->op = FREE;
			return( p->left );
	
		case UNARY MUL:
			return(clocal(p));
	
		case MINUS:
			if( !nncon(p->right))
				break;
			RV(p) = -RV(p);
			o = p->op = PLUS;
	
		case MUL:
		case PLUS:
		case AND:
		case OR:
		case ER:
			/*
			 * commutative ops; for now, just handle constants
			 *
			 * Take care in swapping constants on +, since it
			 * might be sitting under a PACONV, in which case
			 * it isn't commutative.
			 */
			if(nncon(p->left) || (LCON(p) && !RCON(p))) {
				if (!(o == PLUS && strtype(p->type)))
					SWAP(p->left, p->right);
			}
			/*
			 * Fix up stuff we might have botched above...
			 */
			if (LO(p) == PLUS) {
				register NODE	*q = p->left;

				if (nncon(q->left) || (LCON(q) && !RCON(q)))
					SWAP(q->left, q->right);
			}
			if (RO(p) == PLUS) {
				register NODE	*q = p->right;

				if (nncon(q->left) || (LCON(q) && !RCON(q)))
					SWAP(q->left, q->right);
			}
		case PACONV:		/* note PACONV NOT commutative */
			/*
			 * make ops tower to the left, not the right
			 *
			 * However, don't do this in the case that we
			 * have (char *) op (e1 op e2), since we want
			 * only one costly operation to take place
			 * (assuming (e1 op e2) isn't a constant),
			 * and op isn't a PACONV.
			 */
			if(RO(p) == o && !(o != PACONV && bptype(p->left->type) &&
			   offsetype(p->right->type) && !RCON(p))){
				NODE	*t1,
					*t2,
					*t3;

				t1 = p->left;
				sp = p->right;
				t2 = sp->left;
				t3 = sp->right;
				/*
				 * now, put together again
				 */
				p->left = sp;
				sp->left = t1;
				sp->right = t2;
				p->right = t3;
			}
			/*
			 * Collapse ((e1 - e2) + e3) => e1 + (e3 - e2) when
			 * e2 and e3 are constants
			 */
			if(o == PLUS && LO(p) == MINUS && RCON(p) && RCON(p->left) &&
			   conval(p->right, MINUS, p->left->right)){
		zapleft:
				RO(p->left) = FREE;
				LO(p) = FREE;
				p->left = p->left->left;
			}
			/*
			 * Collapse ((char *)(e1 - e2) + e3) => (char *)(e1 - (e2 - e3))
			 * when e2 and e3 are constants
			 * 
			 * This may not be very good for Dec-20: prefer
			 * (char*)(e1+(e3-e2)) cause use only ADJBP & so would
			 * have to negate (e2 - e3)....
			 */
			if (o == PLUS && LO(p) == PSCONV && RCON(p) &&
			    RCON(p->left) &&
			    conval(p->right, MINUS, p->left->right)) {
				RV(p->left) = -RV(p);
				RO(p) = FREE;
				p->op = FREE;
				p = p->left;
				o = PSCONV;
			}
			/*
			 * Collapse ((char *)(e1 + e2) + e3) => ((char *)(e1 + (e2 + e3))
			 * with above constraints
			 */
			if (o == PLUS && LO(p) == PACONV && RCON(p) &&
			    RCON(p->left) &&
			    conval(p->left->right, PLUS, p->right)) {
				RO(p) = FREE;
				p->op = FREE;
				p = p->left;
				o = PACONV;
			}
			/*
			 * Collapse ((char *)(e1 + e2) + e3) => ((char *)(e1 + (e2 + e3))
			 * but be careful to coerce WORDS => BYTES.
			 */
			if (o == PACONV && (LO(p) == PLUS || LO(p) == MINUS) &&
			    RCON(p) && RCON(p->left) &&
			    coerce(p->right, LO(p), p->left->right)) {
		fixright:
				RO(p->left) = FREE;
				LO(p) = FREE;
				p->left = p->left->left;
			}
			if (o == PSCONV && LO(p) == PLUS &&
			   RCON(p) && RCON(p->left) &&
			   coerce(p->left->right, MINUS, p->right)) {
				p->right->lval = p->left->right->lval;
				goto fixright;
			}
			if (o == PSCONV && LO(p) == MINUS && RCON(p) && RCON(p->left) &&
			    coerce(p->right, PLUS, p->left->right))
				goto fixright;
			/*
			 * Collapse ((e1 op e2) op e3) => (e1 op (e2 op e3))
			 */
			if(RCON(p) && LO(p)==o && RCON(p->left) &&
			   conval(p->right, o, p->left->right))
				goto zapleft;
			/*
			 * change muls to shifts
			 */
			if(o == MUL && nncon(p->right) && (i = ispow2(RV(p))) >= 0){
				if( i == 0 ){ /* multiplication by 1 */
					goto zapright;
				}
				o = p->op = LS;
				p->right->type = p->right->csiz = INT;
				RV(p) = i;
			}
		case PSCONV:
			/*
			 * Collapse constants that fall out of above....
			 */
			if (RCON(p) && LCON(p)) {
				if (o == PSCONV) {
					/*
					 * Fool conval into doing the op by changing
					 * the sign on the subtract, then adding
					 */
					RV(p) = -RV(p);
					if (coerce(p->left, PLUS, p->right)) {
						RO(p) = FREE;
						o = p->op = PCONV;
					} else
						RV(p) = -RV(p);
				} else if (o == PACONV) {
					if (coerce(p->left, PLUS, p->right)) {
						RO(p) = FREE;
						o = p->op = PCONV;
					}
				} else if (conval( p->left, o, p->right)){
			zapright:
					RO(p) = FREE;
					p->left = makety(p->left, p->type,
						p->cdim, p->csiz);
					p->op = FREE;
					return(clocal(p->left));
				}
			}
			/*
			 * Eliminate op's  with 0
			 */
			if (RCON(p) && nncon(p->right) && p->right->lval == 0) {
				switch(o) {

					case PLUS:
						RO(p) = FREE;
						p->op = FREE;
						p = p->left;
						o = p->op;
						break;

					case MUL:
					case AND:
						/*
						 * Tricky, subtree may be quite
						 * large, in which case we must
						 * free everything up!
						 */
						tfree(p->left);
						p->op = FREE;
						p = p->right;
						o = p->op;
						break;

					case OR:
						/*
						 * We just turn it into a noop
						 */
						RO(p) = p->op = FREE;
						p = p->left;
						o = p->op;
						break;

					case PACONV:
					case PSCONV:
						/*
						 * Turn 'em into regular PCONV's
						 */
						RO(p) = FREE;
						o = p->op = PCONV;
						break;

				}
			}
			/*
			 * change +'s of negative consts back to -
			 */
			if(o == PLUS && nncon(p->right) && RV(p) < 0 ){
				RV(p) = -RV(p);
				o = p->op = MINUS;
			}
			/*
			 * change PACONV's to PSCONV's and vice-versa
			 */
			if (o == PACONV && nncon(p->right) && RV(p) < 0) {
				RV(p) = -RV(p);
				o = p->op = PSCONV;
			} else if ( o == PSCONV && nncon(p->right) && RV(p) < 0) {
				RV(p) = -RV(p);
				o = p->op = PACONV;
			}
			return(clocal(p));
	
		case DIV:
			if(nncon(p->right) && p->right->lval == 1)
				goto zapright;
			break;
	
		case EQ:
		case NE:
		case LT:
		case LE:
		case GT:
		case GE:
		case ULT:
		case ULE:
		case UGT:
		case UGE:
			if(!LCON(p))
				break;
			/*
			 * if constant on left, exchange operands
			 *
			 * It's possible that this is not good for Dec-20
			 * since has weird compare instructions...
			 */
			sp = p->left;
			p->left = p->right;
			p->right = sp;
			p->op = revrel[p->op - EQ ];
			break;

		case STASG:		/* give clocal a chance */
	/* don't think necessary now that clocal is not de-refing on D20 */
			return(clocal(p));
	}
	return(p);
}

ispow2(c)
	CONSZ	c;
{
	register	i;

	if(c <= 0 || (c&(c-1)))
		return(-1);
	for( i=0; c>1; ++i)
		c >>= 1;
	return(i);
}

/*
 * is p a constant without a name
 */
#ifndef nncon
nncon(p)
	NODE	*p;
{
	return(p->op == ICON && p->rval == NONAME);
}
#endif nncon

coerce(l, o, r)
register NODE	*l, *r;
{
	register	flag = 0;

	if (l->sym_x == BYTES && r->sym_x == WORDS) {
		r->lval *= NCHPERINT;
		if (!(flag = conval(l, o, r)))	     /* returns 1 if cnvt'ed */
			r->lval /= NCHPERINT;
		return(flag);
	}
	if (l->sym_x == WORDS && r->sym_x == BYTES) {
		l->lval *= NCHPERINT;
		if (!(flag = conval(l, o, r)))
			l->lval /= NCHPERINT;
		else
			l->sym_x = BYTES;
		return(flag);
	}
	return(conval(l, o, r));
}
