/* 
 * order.c - machine-dependent fxns to heuristically control code-gen,
 *	     Dec-20 version
 * 
 * Based on Steve Johnson's pdp-11 version
 * Author:	Jay Lepreau
 *		Computer Science Dept.
 * 		University of Utah
 * Date:	22 November 1980
 * Copyright (c) 1980,1981 Jay Lepreau for Dec-20 Version
 */

/* 	Dec-20 version 0.1 	11/80	J.Lepreau */

# include "mfile2"

# define max(x,y) ((x)<(y)?(y):(x))
# define min(x,y) ((x)<(y)?(x):(y))

# define regnode(p)	( (p)->op == REG )

# define commop(op)	( dope[op] & COMMFLG )	/* commutative op? */
# define simpop(op)	( dope[op] & SIMPFLG )	/* simple op ?	   */
# define shiftop(op)	( dope[op] & SHFFLG )	/* shift operator? */
# define umulop(op)	( (op) == UNARY MUL )

# define FLOATING(t)	((t) == FLOAT || (t) == DOUBLE)
# define CHARACTER(t)	((t) == CHAR)	/*** || (t) == UCHAR) ***/

extern int  negrel[];	/* negatives of ralationals, defined in reader.c */
extern short revrel[];	/* reverse of relationals, defined in local2.c */

int     fltused = 0;
int     radebug = 0;
int     crslab = PASS2LAB;	/* start off higher than pass1 labels */

/*
 * should the assignment op p be stored,
 * given that it lies as the right operand of o
 * (or the left, if o==UNARY MUL)
 */
stoasg (p, o)
register    NODE *p;
{
    return (shltype (p->left->op, p->left));
}

/*
 * should we delay the INCR or DECR operation p
 */
deltest (p)
register    NODE *p;
{
    switch (p->type) {
	case (PTR + CHAR): 
	case CHAR: 
#ifdef notdef
	case LONG: 
	case ULONG: 
#endif notdef
	    return (0);

	default: 
	    if (p->op == FLD)
		return (0);
	    p = p->left;
	    if (umulop (p->op))
		p = p->left;
	    return (p->op == NAME || p->op == OREG || p->op == REG);
    }
 /* NOTREACHED */
}

mkadrs (p)
register NODE *p;
{
    register    o;

    o = p->op;

    if (asgop (o)) {
	if (p->left->su >= p->right->su) {
	    if (p->left->op == UNARY MUL) {
		if (p->left->su > 0)
		    SETSTO (p->left->left, INTEMP);
		else {
		    if (p->right->su > 0)
			SETSTO (p->right, INTEMP);
		    else
			cerror ("store finds both sides trivial");
		}
	    }
	    else
		if (p->left->op == FLD && p->left->left->op == UNARY MUL) {
		    SETSTO (p->left->left->left, INTEMP);
		}
		else {		/* should be only structure assignment */
		    SETSTO (p->left, INTEMP);
		}
	}
	else
	    SETSTO (p->right, INTEMP);
    }
    else {
	if (p->left->su > p->right->su) {
	    SETSTO (p->left, INTEMP);
	}
	else {
	    SETSTO (p->right, INTEMP);
	}
    }
}

notoff (t, r, off, cp)
TWORD t;
CONSZ off;
char   *cp;
{
 /* is it legal to make an OREG or NAME entry which has an /* offset of off,
    (from a register of r), if the /* resulting thing had type t */

    return (t == TCHAR);		/* 1 = NO, 0 = YES!! */
}


# define ZCHAR	01
#ifdef notdef
# define ZLONG	02
#endif notdef
# define ZFLOAT	04

/*
 * zap Sethi-Ullman number for chars, longs, floats
 * in the case of longs, only STARNM's are zapped
 * ZCHAR, ZLONG, ZFLOAT are used to select the zapping
 */
zum (p, zap)
register   NODE *p;
{
    register    su;

    su = p->su;

    switch (p->type) {
	case CHAR: 
	case UCHAR: 
	    if (!(zap & ZCHAR))
		break;
	    if (*(p->name))
		break;			/* NAME, must be full word */
	    if (su == 0)
		p->su = su = 1;
	    break;

	case LONG: 
	case ULONG: 
	    break;

	case FLOAT: 
#ifdef notdef
	    if (!(zap & ZFLOAT))
		break;
	    if (su == 0)
		p->su = su = 1;
#endif notdef
	    break;
    }

    return (su);
}

/* sucomp is not right for ASG RS and RS: may need one morereg than LS's... */
/* set the su field in the node to the sethi-ullman num, or local equivalent */

sucomp (p)			/* this is done bottom-up, of course */
register NODE *p;
{
    register    o,
                ty,
                sul,
                sur;
    register    nr;
    register    NODE *l,
                     *r;

    l = p->left;
    r = p->right;
    ty = optype (o = p->op);
    nr = szty (p->type);
    p->su = 0;

    if (ty == LTYPE) {
#ifdef notdef			/* Back when have doubles */
	if (p->type == FLOAT)
	    p->su = 1;
#endif notdef
	return;
    }
    else
	if (ty == UTYPE) {
	    switch (o) {
		case UNARY CALL: 
		case UNARY STCALL: 
		    p->su = fregs;	/* all regs needed */
		    return;

		case UNARY MUL: 
		    if (shumul (l))
			return;

		default: 
		    p->su = max (l->su, nr);
		    return;
	    }
	}


 /* If rhs needs n, lhs needs m, regular su computation */

    sul = l->su;
    sur = r->su;

    if (o == ASSIGN) {
commutop: 				/* also used for asg opcomm */
	if (regnode (r))
	    p->su = sul;
	else if (sul == 0)
	    p->su = max (sur, (regnode (l) ? 0 : nr));
	else
	    p->su = max (sul, max (sur, nr) + 1);
	return;
    }

    if (o == CALL || o == STCALL) {
    /* in effect, takes all free registers */
	p->su = fregs;
	return;
    }

    if (o == STASG) {
    /* harder 1st, right shares at end */
	p->su = max (sur, sul + 1);	/* ?? */
	return;
    }

    switch (o) {
	case ANDAND: 
	case OROR: 
	case QUEST: 
	case COLON: 
	case COMOP: 
	    p->su = max (max (sul, sur), nr);
	    return;
    }

    if (logop (o)) {		/* only compares are left at this point */
    /* do the harder side, then the easier side, into registers */
    /* left then right, max(sul,sur+nr) */
    /* right then left, max(sur,sul+nr) */
    /* to hold both sides in regs: nr+nr */

/* Since Dec-20 requires left operand in reg, swap children if necessary  */
/* in order to get harder on left.					  */
	sul = zum (l, ZCHAR | ZFLOAT);
	sur = zum (r, ZCHAR | ZFLOAT);

	if (!regnode (l) && sur > sul) {	/* then swap */
	    NODE *s;
	    int     ssu;	/* Note that REVerse here, not NEGate! */

	    p->op = revrel[o - EQ];
	    ssu = sul;
	    sul = sur;
	    sur = ssu;
	    s = l;
	    p->left = r;
	    p->right = s;
	}

	nr = szty (p->left->type);	/* leave this as p->left !! */
	p->su = max (sul, sur + (regnode (l) ? 0 : nr));/* lft, then rt */
	return;
    }

    if (asgop (o)) {
	if (commop (o))
	    goto commutop;

	if (FLOATING (ty))
	    goto leftreg;

	switch (o) {
	    case INCR: 
#ifdef notdef			/* Converted to INCR in 1st pass */
	    case DECR: 
#endif notdef
	    /* NB: Will screw up if ordered not foreff and is reg. var *  */
	    /* and is incr != SONE or SMONE, so got to commutop.... */
		if (tshape (r, SONE) || tshape (r, SMONE)) {
		    p->su = max (sul, nr); /* I think this is right, for now */
		    return;
		}
		else	/* ****** if (o == INCR) ******** */
		    goto commutop;

	    case ASG LS: 
	    case ASG RS: 
	leftreg: 			/* get left into reg & rhs addr. */
		if (regnode (l))
		    p->su = sur;
		else
		    p->su = max (max (sul, nr), sur);
		return;

	    case ASG DIV: 
	    case ASG MOD: 
	    /* this is temporary: should check for regnodes;	 */
	    /* & what about extra reg for target of assignment?	 */
	divcomp: p->su = max (min (max (sul, nr + sur), max (sur, nr + sul)), nr + nr);
		return;

	    default: 
		cerror ("sucomp asgop: unexpected op %s\n", opst[o]);
	}
    }					/* end of asop computations */


/* default: should only be opsimps, / % and LS,RS  (maybe) */

    if (o == DIV && !FLOATING (ty))
	goto divcomp;			/* temporary? */

    if (istnode (l))
	p->su = sur;
    else if (sur == 0)
	p->su = max (sul, nr);
    else
	p->su = max (sur, max (sul, nr) + 1);
    return;
}

 /* insure that the use of p gets done with register r; in effect, */
 /* simulate offstar */

mkrall (p, r)
register  NODE *p;
{

    if (p->op == FLD) {
	p->left->rall = p->rall;
	p = p->left;
    }

    if (p->op != UNARY MUL)
	return;				/* no more to do */
    p = p->left;
    if (p->op == UNARY MUL) {
	p->rall = r;
	p = p->left;
    }
    if (p->op == PLUS && p->right->op == ICON) {
	p->rall = r;
	p = p->left;
    }
    rallo (p, r);
}

rallo (p, down)			/* do register allocation */
register    NODE *p;
{

/* down is reg & flag for this node; down1 is for left child, down2 for right*/
    register    o,
                type,
                down1,
                down2,
                ty;

    if (radebug)
	printf ("rallo( %o, %o )\n", p, down);

    down2 = NOPREF;
    p->rall = down;
    down1 = (down &= ~MUSTDO);		/* turn off MUSTDO flag */

    ty = optype (o = p->op);
    type = p->type;


    if (type == DOUBLE || type == FLOAT) {
	++fltused;		/* how say r0 too when have doubles later? */
	if (o == FORCE)
	    down1 = R1|MUSTDO;	/* left = return reg & they ain't no right */
    }
    else
	switch (o) {

	    case ASSIGN: 
	    case ASG DIV: 
	    case DIV: 		/* left = nopref, right = me */
		down1 = NOPREF;
		down2 = down;
		break;

	    case CALL: 
	    case STASG: 	/* not sure if this one should stay here?? */
	    case EQ: 
	    case NE: 
	    case GT: 
	    case GE: 
	    case LT: 
	    case LE: 
	    case NOT: 
	    case ANDAND: 
	    case OROR: 
		down1 = NOPREF;		/* both = nopref */
		break;

	    case FORCE: 
		down1 = R1 | MUSTDO; /* left = return reg & they ain't no right */
		break;
	}

    if (ty != LTYPE)
	rallo (p->left, down1);	/* left default = myreg */
    if (ty == BITYPE)
	rallo (p->right, down2);	/* rt default =  nopref */

}

offstar (p)			 /* handle indirections */
register    NODE *p;
{

    if (p->op == UNARY MUL)
	p = p->left;

    if (p->op == PLUS || p->op == MINUS) {
	if (p->right->op == ICON) {
	    order (p->left, INTAREG | INAREG);
	    return;
	}
    }
    order (p, INTAREG | INAREG);
}

#ifndef setincr
setincr (p)
NODE *p;
{
    return (0);				/* for the moment, don't bother */
}
#endif setincr

/* Have wee got a nice UNARY MUL node to feed to offstar? */
niceuty (p)
register    NODE *p;
{
    register    TWORD t;

    return (p->op == UNARY MUL && (t = p->type) != CHAR &&
	    t != UCHAR && t != FLOAT &&
	    shumul (p->left) != STARREG);	/* this last is ALWAYS true! */
}

setbin (p)
register NODE *p;
{
    register NODE *r,
                  *l;

    r = p->right;
    l = p->left;

#ifdef notdef
    if (logop (p->op)) {
	if (l->op == UNARY MUL && l->type != FLOAT && shumul (l->left) != STARREG)
	    offstar (l->left);
	else
	    order (l, INAREG | INTAREG | INBREG | INTBREG | INTEMP);
	return (1);
    }

 /* now, rhs is complicated: must do both sides into registers */
 /* do the harder side first */

    if (logop (p->op)) {
    /* relational: do both sides into regs if need be */

	if (r->su > l->su) {
	    if (niceuty (r)) {
		offstar (r->left);
		return (1);
	    }
	    else
		if (!istnode (r)) {
		    order (r, INTAREG | INAREG | INTBREG | INBREG | INTEMP);
		    return (1);
		}
	}
	if (niceuty (l)) {
	    offstar (l->left);
	    return (1);
	}
	else
	    if (niceuty (r)) {
		offstar (r->left);
		return (1);
	    }
	    else
		if (!istnode (l)) {
		    order (l, INTAREG | INAREG | INTBREG | INBREG | INTEMP);
		    return (1);
		}
	if (!istnode (r)) {
	    order (r, INTAREG | INAREG | INTBREG | INBREG | INTEMP);
	    return (1);
	}
	cerror ("setbin can't deal with %s", opst[p->op]);
    }
#endif notdef

/* Ordinary operator.  Include relationals here for dec-20 */

    if (p->op == DIV && !FLOATING (p->type)) {
    /* problem here if fx call on one side(??) */
	if ((!istnode (r)) && (r->su >= l->su)) {
	    order (r, INTAREG);
	    return (1);
	}
	if (!regnode (l)) {
	    order (l, INAREG | INTAREG);
	    return (1);
	}
	return (0);			/* shouldn't happen */
    }

    if (r->su == 0) {			/* rhs is addressable */
	if (!istnode (l)) {
	    order (l, logop (p->op) ? INTAREG | INAREG : INTAREG);
	    return (1);
	}
	if (optype (r->op) == BITYPE) {		/* kludge?? rhs may be ++reg */
	    order (r, INTAREG | INAREG);
	    return (1);
	}
    /* rewrite */
	return (0);
    }

    if (!istnode (r) && r->su > l->su) {
    /* if there is a chance of making it addressable, try it... */
	if (niceuty (r)) {
	    offstar (r->left);
	    return (1);		/* hopefully, it is addressable by now */
	}
	order (r, INTAREG | INAREG | INTBREG | INBREG | INTEMP); 
					/* anything goes on rhs */
	return (1);
    }
    else {
	if (!istnode (l)) {		/* could loop on logops.... */
	    order (l, logop (p->op) ? INTAREG | INAREG : INTAREG);
	    return (1);
	}
    /* rewrite */
	return (0);
    }
}

setstr (p)				/* structure assignment */
register NODE *p;
{
    if (!regnode (p->right)) {
	order (p->right, INTAREG);
	return (1);
    }
    p = p->left;
    if (p->op != NAME && p->op != OREG) {
	if (p->op != UNARY MUL)
	    cerror ("bad setstr");
	order (p->left, INTAREG);
	return (1);
    }
    return (0);				/* == failure */
}

setasg (p)			/* setup for assignment operator */
NODE *p;
{
    register    NODE *l,
                     *r;

/* Should check and do hardest side 1st.  Later... */
    r = p->right;
    if (!regnode (r)) {			/* get it into a reg */
	order (r, INAREG | INTAREG);
	return (1);
    }

    l = p->left;
    if (l->op == UNARY MUL && !tshape (l, STARNM)) {
	offstar (l->left);
	return (1);
    }
    if (l->op == FLD && l->left->op == UNARY MUL) {
	offstar (l->left->left);
	return (1);
    }
    return (0);
}

setasop (p)				/* setup for op='s */
NODE *p;
{
    register    NODE *l = p->left;
    register    NODE *r = p->right;
    register	int   o = p->op;

    if (regnode (r)) {
	if (l->su > 0) {		/* make lhs addr */
	    if (umulop (l->op)) {
		offstar (l->left);
		return (1);
	    }
	    return (0);			/* can't be lvalue (except field) */
	}				/* so let reader rewrit as ASSIGN */
	if (commop (o))
	    cerror ("setasop commutop: r=reg, sul=0");
	return (0); /* lhs addressable so no side effects when goes to assign*/
    }

    if (regnode (l)) {
	if (simpop (o) || shiftop (o)) {       /* not addr since not matched */
	    if (umulop (r->op))
		offstar (r->left);
	    else
		order (r, INAREG | INTAREG);
	    return (1);
	}
	return (0);			/* just asg div & asg mod left */
    }

/* rhs not in treg and lhs not in reg */
    if (commop (o))
	order (r, INTAREG);
    else if (umulop (l->op))
	offstar (l->left);	/* make lhs address */
    else if (l->su == 0)
	return (0);		/* rewrite before lose lval */
    else {
	printf ("WARNING: setasop fall thru to order(l, INTAREG)");
	order (l, INAREG | INTAREG);/* wrong?? */
    }
    return (1);
}

getlab ()
{
    return (crslab++);
}


deflab (l)
{
    printf ("$%d:!\n", l);
}

genargs (p)
register NODE *p;
{
    register    size;

/* generate code for the arguments */

/*  first, do the arguments on the right (last->first) */
    while (p->op == CM) {
	genargs (p->right);
	p->op = FREE;
	p = p->left;
    }

#ifdef notdef
    if (p->op == STARG) {		/* structure valued argument */
	size = p->stsize;
	if (p->left->op == ICON) {
	/* make into a name node */
	    p->op = FREE;
	    p = p->left;
	    p->op = NAME;
	}
	else {
	/* make it look beautiful... */
	    p->op = UNARY MUL;
	    canon (p);			/* turn it into an oreg */
	    if (p->op != OREG) {
		offstar (p->left);
		canon (p);
		if (p->op != OREG)
		    cerror ("stuck starg");
	    }
	}

	p->lval += size;		/* end of structure */
    /* put on stack backwards */
	for (; size > 0; size -= 2) {
	    p->lval -= 2;
	    expand (p, RNOP, "	mov	AR,Z-\n");
	}
	reclaim (p, RNULL, 0);
	return;
    }
#endif notdef

 /* ordinary case */
    order (p, FORARG);
}

argsize (p)
register    NODE *p;
{
    register    t;
    t = 0;
    if (p->op == CM) {
	t = argsize (p->left);
	p = p->right;
    }
#ifdef notdef
    if (p->type == DOUBLE || p->type == FLOAT) {
	SETOFF (t, 2);
	return (t + 8);
    }
    else if (p->type == LONG || p->type == ULONG) {
	SETOFF (t, 2);
	return (t + 4);
    }
    else
#endif notdef

    if (p->op == STARG) {
        SETOFF (t, p->stalign);/* alignment */
	return (t + p->stsize);/* size */
    }
    else {
	SETOFF (t, 1);
	return (t + 1);
    }
}
