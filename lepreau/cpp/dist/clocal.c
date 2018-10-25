/*
 * clocal.c - based on Sam Leffler's Harris/6 version
 *
 * Author:	Jay Lepreau
 *		Computer Science Dept.
 * 		University of Utah
 * Date:	August  80
 * Copyright (c) 1980 Jay Lepreau for Dec-20 version
 */

# include "mfile1"

/*
 *	this file contains pass1 code which is dependent
 *	on the target machine
 */

#define FLOATING(t)	((t) == FLOAT || (t) == DOUBLE)

extern int  eprint ();
extern int  xdebug;

/*
 * Walk the tree (or at least part of the tree), fixing word offsets that
 * should be byte offsets.
 */
static  NODE *
bytefix(p)
register NODE *p;
{
    register    ty;
    register    o = p->op;
    NODE	*r;

#if DEBUG & CLOCAL
    if (xdebug > 2) {
	printf ("bytefix( %o )\n", p);
	fwalk (p, eprint, 0);
    }
#endif
    switch (o) {
	default: 	/* if !(asgop || logop || callop) keep looking */
	    if (!asgop (o) && !logop (o) && !callop (o))
		break;
	/* FALL THRU */
	case PCONV: 
	case PACONV: 
	case PSCONV: 
	case UNARY MUL: 
	case UNARY AND: 
	case SCONV: 
	    return (p);			/* we've gone far enough */
    }
    ty = optype (o);
    if (ty == LTYPE) {
	if (o == ICON && p->sym_x == WORDS) {
	    p->sym_x = BYTES;
	    p->lval *= NCHPERINT;	/* was sizeof */
	}
	return (p);
    }
    if (ty == BITYPE) {
	if ((o == PLUS || o == MINUS) && strtype (p->type)) {
	/* 
	 * Don't do the multiply to a * or << node
	 */
	    o = p->right->op;
	    if (o != MUL && o != LS && o != ICON) {
		register    NODE *q;
		q = bcon (NCHPERINT);		/* was sizeof */
		q->sym_x = BYTES;
		p->right = buildtree (MUL, p->right, q);
	    }
	}
	else if (o == LS) {
	    if (p->right->op == ICON && p->right->sym_x == WORDS) {
		register    NODE *q;
	    /* cnvt shift to mult */
		q = bcon (0);
		q->lval = (2 << (p->right->lval - 1)) * NCHPERINT;
				    /* was sizeof, check ?? */
		q->sym_x = BYTES;
		p->right->op = FREE;
		p->op = FREE;
		p = buildtree (MUL, p->left, q);
		goto skipright;
	    }
	}
	p->right = bytefix (p->right);
    }
skipright: 
    p->left = bytefix (p->left);
    return (p);
}

/*
 * Perform address calculation optimizations on character references.
 * Specifically we look for the following:
 *	1. (p + e1) + e2 => p + (e1 + e2)
 *	2. (p + e1) - e2 => p + (e1 - e2)
 *	3. (p - e1) + e2 => p + (e2 - e1)
 *	4. (p - e1) - e2 => p - (e1 + e2)
 *
 * These transformations are neccessary if any kind of 'decent' code is
 * is to be generated in the second pass for addresses.
 * 
 * Reduces number of generated instructions from 4 to 3 on Dec-20:
 * move,adjbp,move,adjbp -> move,add,adjbp.
 */
static NODE *
optim1(p)
register NODE *p;
{
    register    o = p->op;
    register    NODE *q,
               	     *r;
    register    TWORD rt = p->right->type;
    register    TWORD lt = p->left->type;
    register    TWORD lrt;

    switch (o) {
	case PLUS: 
	    if (bptype (lt) && offsetype (rt))
		q = p->left, r = p->right;
	    else if (bptype (rt) && offsetype (lt))
		q = p->right, r = p->left;
	    else
		break;
	    switch (q->op) {
		case PLUS: 
		    lrt = q->right->type;
		    if (offsetype (lrt))
			q->right = buildtree (PLUS, q->right, r);
		    else
			q->left = buildtree (PLUS, q->left, r);
		    p->op = FREE;
		    return (q);

		case MINUS: 
		    lrt = q->right->type;
		    if (offsetype (lrt))
			q->right = buildtree (MINUS, r, q->right);
		    else
			q->left = buildtree (MINUS, r, q->left);
		    p->op = FREE;
		    q->op = PLUS;
		    return (q);
	    }
	    break;

	case MINUS: 
	    if (bptype (lt) && offsetype (rt))
		q = p->left, r = p->right;
	    else
		break;
	    switch (q->op) {
		case PLUS: 
		    lrt = q->right->type;
		    if (offsetype (lrt))
			q->right = buildtree (MINUS, q->right, r);
		    else
			q->left = buildtree (MINUS, q->left, r);
		    p->op = FREE;
		    q->op = PLUS;
		    return (q);

		case MINUS: 
		    lrt = q->right->type;
		    if (offsetype (lrt))
			q->left = buildtree (PLUS, q->left, r);
		    else
			break;		/* impossible */
		    p->op = FREE;
		    return (q);

	    }
	    break;
    }
    return (p);
}

/*
 * this is called to do local transformations on
 * an expression tree preparatory to its being
 * written out in intermediate code.
 *
 * the major essential job is rewriting the
 * automatic variables and arguments in terms of
 * REG and OREG nodes.
 *
 * conversion ops which are not necessary are also clobbered here
 *
 * in addition, any special features (such as rewriting
 * exclusive or) are easily handled here as well
 */
NODE *
clocal(p)
register NODE *p;
{
    register struct symtab *q;
    register    NODE *r;
    register    o;
    register    TWORD m,
                      ml;
    extern	NODE *cast();

    switch (o = p->op) {
	case STASG: 
	/* 
	 * Rewrite structure assignments by decrementing the
	 * reference to the left hand side by one. This
	 * allows the second pass to build loops to perform
	 * the assignment.
	 * 
	 * May not need this for Dec-20, but leave in for now.
	 * OUT of DEC-20....
	 */
#ifdef notdef
	    switch(o = p->left->op) {
	        case NAME:
		    p->left->op = ICON;
		    break;

	        case UNARY MUL:
		    p->left->op = FREE;
		    p->left = p->left->left;
		    break;

	        case PLUS:
	        case MINUS:
		    /*
		     * References to local structures
		     */
	        case ICON:
		    break;

	        default:
		    cerror("unexpected node %s for STASG rewrite", opst[o]);
	    }
#endif notdef
	    break;

	case UNARY AND: 
	/* 
	 * Fix up static chars, so that they appear to be
	 * in the last byte of the word they allocate.
	 */
	    r = p->left;
	    if (r->rval >= 0)			/* external */
		q = &stab[r->rval];
	    else			 /* for STATICs that were kludged in */
		q = &stab[r->sym_x];		/* NAME below */
	    if ((q->stype == CHAR || q->stype == UCHAR) &&
		    (q->sclass == EXTERN || q->sclass == EXTDEF ||
			q->sclass == STATIC))
		r->lval = NCHPERINT - 1;	/* last byte in word */
	    break;				/* should be bits??? */

	case UNARY MUL: 
	/* 
	 * Don't fold those ICON's that deal with chars
	 * on odd byte boundaries.
	 * By allowing the
	 * U* ICON trees to be folded to a NAME node
	 * we lose the addressing structure.
	 *
	 * This applies to all chars, whether in arrays,
	 * structures, or whatever, unless they lie 
	 * on word boundaries.
	 *
	 * DON'T FOLD ANY FOR NOW ON DEC-20.
	 */
	    if (p->left->op != ICON)
		return (p);
	    if (p->type == CHAR || p->type == UCHAR) {
#ifdef notdef
		CONSZ	val;
		val = p->left->lval;
		if (val == 0 || ((val+1) % NCHPERINT) != 0)
		    return(p);
	    /*
	     * Now fix up the lval
	     */
		p->left->lval = val/NCHPERINT;
		if (val < 0)
		    --p->left->lval;  		/* decr if was neg */
#endif notdef
#if SZCHAR!=SZINT	/* continue on and fold if chars are word sized... */
		return (p);
#endif
	    }
	    p->left->op = NAME;
	    p->left->type = p->type;
	    goto setuleft;

	case NAME: 
	    if (p->rval < 0)		/* already processed; ignore */
		return (p);
	    q = &stab[p->rval];
	    switch (q->sclass) {
		case AUTO: 
		case PARAM: 
		/* 
		 * fake up a structure reference
		 */
		    r = block (REG, NIL, NIL, PTR + STRTY, 0, 0);
		    r->lval = 0;
		    r->rval = (q->sclass == AUTO ? STKREG : ARGREG);
		    p = stref (block (STREF, r, p, 0, 0, 0));
		    break;

		case ULABEL: 
		case LABEL: 
		case STATIC: 
		    if (q->slevel == 0)
			break;
		    p->lval = 0;
		    if (q->sclass == STATIC) /* kludge it for UNARY AND above*/
			p->sym_x = p->rval;
		    p->rval = -q->offset;
		    break;

		case REGISTER: 
		    p->op = REG;
		    p->lval = 0;
		    p->rval = q->offset;
		    break;
	    }
	    break;
	case LT: 
	case LE: 
	case GT: 			/* make ptr comparisons unsigned */
	case GE: 
#ifdef notdef
	    if (ISPTR (p->left->type) || ISPTR (p->right->type))
		p->op += (ULT - LT);
#endif notdef
	     break;

	case ASG MINUS: 		/* Convert to asg plus on negative */
	    p->op = ASG PLUS;
	    negater (p);
	    break;

	case DECR: 			/* Convert to incr on negative */
	    p->op = INCR;
	    negater (p);
	    break;

	case CBRANCH: 	/* cnvt those above asgops cause no cond.codes on 20 */
	    if (asgop (p->left->op)) {
		NODE *l;
		l = p->left;
		p->left = block (NE, l, bcon (0), l->type, l->cdim, l->csiz);
	    }
	    break;

	case PCONV: 
	/* 
	 * do pointer conversions for most everything,
	 *	only things with the same shape are
	 *	ints,unsigneds,pointers to stuff not a char
	 */
	    ml = p->left->type;
	    m = p->type;
	    o = p->left->op;
	    if (o != REG && o != ICON) {
		if (ml == LONG || ml == ULONG)
		    goto doit;
		else if (bptype (ml)) {
		    if (!bptype (m))
			goto doit;
		}
		else {
			if (bptype (m)) {
#if DEBUG & CLOCAL
			    if (xdebug > 1) {
				printf ("clocal: convert to P?CONV\n");
				fwalk (p, eprint, 0);
			    }
#endif
			    if (o == PLUS)
				p->op = PACONV;
			    else
				if (o == MINUS)
				    p->op = PSCONV;
				else
				    goto doit;
			    r = bytefix (p->left);
			    p->left->op = FREE;
			    p->left = r->left;
			    p->right = r->right;
			    p = optim (p);
#if DEBUG & CLOCAL
			    if (xdebug > 1) {
				printf ("after conversion:\n");
				fwalk (p, eprint, 1);
			    }
#endif
			    goto doit;
			}
		    }
	    }
	    else if (o == ICON) {
	    /*
	     * Handle coercion from BYTES to WORDS in the
	     * case of character pointers..simple constants
	     * (i.e. those without a name) must be handled
	     * as in address.c of the second pass.
	     *
	     * I DON'T REALLY UNDERSTAND THIS.... fjl
	     */
	         if (bptype (m)) {		/* x -> bp */
		    if (ISPTR (ml)) {
			if (p->left->rval != NONAME) {	/* ptr -> bp */
			    if (p->left->sym_x == WORDS) { /* symbolicP -> bp*/
				p->left->lval *= NCHPERINT;
				p->left->sym_x = BYTES;
			    }
			}
			else {		/* consP -> bp */
			    p->left->lval = BUILDBP
				(POS0, p->left->lval);
#if pdp11
			    cerror ("clocal: bad x-compile 1");
#endif
			    p->left->sym_x = NOTYPE;
			}
		    }
		    else {		/* notP -> bp */
			CONSZ words,
			      val = p->left->lval,
			      bytes;

			words = val / NCHPERINT;
			bytes = val % NCHPERINT;
			if (val != 0 && val != -1) /*are these special flags?*/
				/* in next stmnt, should POS0 be POS[bytes]? */
			    p->left->lval = BUILDBP (POS0, words);
#if pdp11
			cerror ("clocal: bad x-compile 2");
#endif
		    }
		}
		else {
		    if (bptype (ml)) {
			if (p->left->rval != NONAME &&
				p->left->sym_x == BYTES) {
			    p->left->lval /= NCHPERINT;
			    p->left->sym_x = WORDS;
			}
			p->left->lval &= ADDRFLD;
		    }
		}
	    }
	    p->left->type = m;
    setuleft:		/* move left child to current node, delete current */
	    p->left->cdim = p->cdim;
	    p->left->csiz = p->csiz;
	    p->op = FREE;
	    return (p->left);

	case SCONV: 
	    m = p->type;
	    m = FLOATING (m);
	    ml = p->left->type;
	    ml = FLOATING (ml);
	    if (m != ml)		/* if either is float, must cnvt */
		break;
	    else if (m & ml)		/* both are floating */
		goto remove;		/* so get rid of conversion */

	/* Neither is floating. * now, look for conversions downwards */
	    m = p->type;
	    ml = p->left->type;
	    if (nncon (p->left)) {	/* "Is it an ICON w/o a name?" */
				        /* so simluate the conversion here */
		CONSZ val = p->left->lval;
	    /* 
	     * If it's a byte pointer, first we must
	     * convert it to an offset in bytes from
	     * 0 (origin).
	     * [Should we really do this?]
	     */
		if (bptype (ml)) {
		    CONSZ   words;
		    int     bytes;
#if pdp11
		    cerror ("clocal: bad x-compile 3");
#endif
		    bytes = (POS0 - (val >> POSLOC)) / SZCHAR;
		    words = val & ADDRFLD;
		    val = p->left->lval = words * NCHPERINT + bytes;
		}
		switch (m) {
		    case UCHAR: 
		    case CHAR: 
		        p->left->lval = CHARCAST (val);	    /* was (char)val */
			break;

		    case UNSIGNED: 
#ifdef notdef
#if pdp11
			p->left->lval = val & 0xffffffL;
#else
			p->left->lval = (unsigned)val;
#endif pdp11
#endif notdef
			if (val < 0)
			    cerror ("clocal: unsigned too big;");
			break;
		    case INT: 
#ifdef notdef
#if pdp11
			if (p->left->lval < 0) {
			    val  = -val;
			    val = -(val & 0xffffffL);
			}
			else
			    val &= 0xffffffL;
			p->left->lval = val;
#else
			p->left->lval = (int)val;
#endif pdp11
#endif notdef
			break;
		}
		p->left->type = m;
	    }
	    else {		/* zap if NOT(long or bp) -> (char or int) */
		if (offsetype (m) && 
			!(ml == LONG || ml == ULONG || bptype (ml)))
		    goto remove;
		break;			/* leave the conversion there */
	    }
	/* 
	 * clobber conversion
	 */
    remove: 
	    p->op = FREE;
#if DEBUG & CLOCAL
	    if (xdebug == 1)
		fwalk (p->left, eprint, 0);
#endif
	    return (p->left);

	case PMCONV: 
	case PVCONV: 
	    if (p->right->op != ICON)
		cerror ("bad conversion", 0);
	    p->op = FREE;
	    return (buildtree (o == PVCONV ? DIV : MUL, p->left, p->right));

	case PLUS: 
	case MINUS: 
	    if (bptype (p->type)) {
#if DEBUG & CLOCAL
		if (xdebug > 1) {
		    printf ("clocal, convert\n");
		    fwalk (p, eprint, 0);
		}
#endif
		if (p->left->op == PCONV) {
		    ml = p->left->left->type;
		    r = p->left->left;
		    p->op = (o == MINUS ? PSCONV : PACONV);
		    p->left->op = FREE;
		    p->left = r;
		    if (strtype (ml))
			p->right = optim (bytefix (p->right));
		}
		else if (p->left->op == PACONV) {
		/* 
		 * Bubble PACONV's to the top
		 * Take care in coercing types:
		 *   beware of (int)+(long)
		 */
		    r = p->left;
		    r->right = buildtree (o, r->right, p->right);
		    p->op = FREE;
		    p = r;
		}
#if DEBUG & CLOCAL
		if (xdebug > 1) {
		    printf ("to:\n");
		    fwalk (p, eprint, 1);
		}
#endif
	    }				/* USED TO fall thru to below... */
	    break;

	case RS: 			/* (rs, asg rs weren't in pcc-11) */
	    p->op = LS;
	    negater(p);
	    break;
	case ASG RS: 
	    p->op = ASG LS;
	    negater (p);		/* negate right child */
	    break;

	case LS:			/* should we put NEG_RS here too? */
	case MUL: 
	/* 
	 * optimize address calculations with long indexes
	 */
#ifdef notdef				/* for D-20 long = int. */
	    m = p->type;
	    if (ISPTR (m) || ISARY (m)) {
		ml = p->left->type;
		if (ml == LONG || ml == ULONG)
		    p->left = cast (p->left, INT);
		ml = p->right->type;
		if (ml == LONG || ml == ULONG)
		    p->right = cast (p->right, INT);
	    }
#endif notdef
	    break;

/* I think we need a switch default here:
	default: return(p); */
    }
/* And also here, just:
    return(p); */

doit: 					/* jump location to do PCONV's */
    if (o == PLUS || o == MINUS)
	return (optim1 (p));
    return (p);
}

#ifndef strtype
strtype(t)			/* is this a structure type? */
register TWORD t;
{
    return (t == (PTR + STRTY) || t == (PTR + UNIONTY) ||
	    t == INCREF (ARY + STRTY) || t == INCREF (ARY + UNIONTY));
}
#endif strtype

#ifndef bptype
bptype(t)			/* is this a byte pointer type? */
register TWORD t;
{
#if SZCHAR==SZINT
    return (0);				/* NO, when chars are words  */
#else
    return (t == (PTR + CHAR) || t == (PTR + UCHAR) ||
	    t == INCREF (ARY + CHAR) || t == INCREF (ARY + UCHAR));
#endif
}
#endif bptype

#ifndef offsetype
offsetype(t)			/* is this an 'offset' type? */
register TWORD t;
{
    return (t == CHAR || t == INT || t == UCHAR || t == UNSIGNED);
}
#endif offsetype

negater(p)			/* negate the right child of p */
NODE *p;
{
    register    NODE * r;

    r = p->right;
    if (nncon (r))
	r->lval = -r->lval;
    else
	p->right = block (UNARY MINUS, r, NIL, r->type, r->cdim, r->csiz);
}
