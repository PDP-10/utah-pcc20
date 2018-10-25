/* 
 * local.c - machine-dependent pass1 fxns, Dec-20 version
 * 
 * Based on Steve Johnson's pdp-11 version
 *   and Sam Leffler's Harris/6 version.
 * Author:	Jay Lepreau
 *		Computer Science Dept.
 * 		University of Utah
 * Date:	14 August 1980
 * Copyright (c) 1980,1981 Jay Lepreau for Dec-20 Version
 */

# include "mfile1"

/*
 *	this file contains code which is dependent
 *	on the target machine
 */

static		inwd;			/* current bit offset in word */
static CONSZ	word;			/* word being built from fields */
extern int	idebug;
int		initkluge = 0;		/* see pftn.c - endinit() */
extern int	xdebug;

# define BITMASK(n)	((1L<<n)-1)

/*
 *	Cast node p to type t
 */
NODE *
cast (p, t)
	register NODE	*p;
	TWORD		t;
{

	p = buildtree (CAST, block (NAME, NIL, NIL, t, 0, (int) t), p);
	p->left->op = FREE;
	p->op = FREE;
	return (p->right);
}

andable (p)
	NODE	*p;
{
	return (1);	/* all names can have & taken on them */
}			/* (for now since static chars fill a word?) */

/*
 * at the end of the arguments of a ftn,
 * set the automatic offset
 */
cendarg()
{
	autooff = AUTOINIT;
}

/*
 * is an automatic variable of type t
 * OK for a register variable?
 */
cisreg (t)
	TWORD	t;
{
	if ( t==INT || t==FLOAT || ISPTR(t) || t==CHAR ) return(1);
	return(0);
}			/* everything else has been ctype'd to INT.	*/

/*
 * return a node, for structure references, which is suitable for
 * being added to a pointer of type t, in order to be off bits offset
 * into a structure
 * Convert from bits to bytes/words here!!	--fjl
 */
NODE *
offcon (off, t, d, s)
	OFFSZ	off;
	TWORD	t;
{
	register NODE	*p;
	extern int eprint();

	if (xdebug > 2) {
		printf("offcon( %ld, ", off);
		tprint(t);
		printf(", %d, %d )\n", d, s);
	}
	/*
	 * t, d, and s are the type, dimension offset, and sizeoffset
	 * in general they  are necessary for offcon, but not on H'well
	 */
	p = bcon (0);
	/*
	 * We want to put out byte offsets for those nodes involving
	 * chars in arrays or structures.  Otherwise use a word offset
	 * or we'll have to optimize the tree before it's written out.
	 * [to avoid multiplies and divides by 3.] 4 for d20. is this
	 * leffler's only reason?
	 */
	if (bptype(t)) {	/* bptype lives in clocal.c */
		p->lval = off/SZCHAR;
		p->sym_x = BYTES;
	} else {
		p->lval = off/SZINT;
		p->sym_x = WORDS;
	}
	if (xdebug > 2) {
		printf("offcon returns\n");
		fwalk(p, eprint, 1);
	}
	return (p);
}

/*
 * generate initialization code for assigning a constant c
 * to a field of width sz
 */
incode (p, sz)
	register NODE	*p;
{
	extern CONSZ	word;	/* not needed?? watch out for printfs	*/
				/* if this is no longer long...		*/
	/*
	 * we assume that the proper alignment has been obtained
	 * inoff is updated to have the proper final value
	 * we also assume sz  < SZINT
	 */
/* inwd apparently goes from right to left. On /6, succesive fields end */
/* up from left to right (properly, i think). But on 11, they ended up	*/
/* from right to left.		fjl 					*/

	if ((sz + inwd) > SZINT)
		cerror ("incode: field > int");
	word = (word << sz) | (p->lval & BITMASK(sz));
	inwd += sz;
	inoff += sz;
	if (inoff % SZINT == 0) {
		printf(")	oct	%lo\n", word);	/* CONSZ dependent */
		word = 0, inwd = 0;
	}
}

/*
 * Initializition of floating points....
 * output code to initialize space of size sz to the value d
 * the proper alignment has been obtained
 * inoff is updated to have the proper final value
 * on the target machine, write it out in octal!
 * ie, when cross-compiling, write in floating pnt fmt.
 */
fincode (d, sz)
	double	 d;
{
/*****	printf(")	%.19e\n", d);	/* dble's prec. on 20 =	 */
#ifdef CROSSCOMP
	printf(")	%.8e\n", d);	/* sngle prec 2^27 ~= 10^8 */
#else
	printf(")	^o%o\n", d);	/* make %O later */
#endif
	inoff += sz;			/* 2**62 approx = 10**19 */
}

/*
 * arrange for the initialization of p into a space of
 * size sz.
 * the proper alignment has been obtained
 * inoff is updated to have the proper final value
 */
cinit (p, sz)
	NODE	*p;
{
	ecode (p);
	inoff += sz;
}

/*
 * define n bits of zeros in a vfd
 */
vfdzero (n)
{
	if (n <= 0)
		return;

	inwd += n;
	inoff += n;
	if (initkluge == 0)	/* kludge to force to rightmost byte in word */
		word <<= n;
	if (inoff % ALINT == 0) {
		printf(")	oct	%lo\n", word);	/* CONSZ dependent */
		word = 0, inwd = 0;
	}
}


/*
 * make a name look like an external name in the local machine
 */
char *
exname (p)
	char	*p;
{	

	static char     text[NCHNAM + 2];
	register	i;

	for (i = 0; *p && i < NCHNAM+1; ++i) {
		if ((text[i] = *p++) == '_') text[i] = '.';
	}

	text[i] = '\0';
/***	text[NCHNAM+1] = '\0';	       /* truncate */

	return (text);

}

/*
 * map types which are not defined on the local machine
 */	/* what about chars? where do they get zapped?? */
ctype (type)
	TWORD	type;
{
	switch (BTYPE (type)) {
		case SHORT:
		case LONG:
			MODTYPE (type, INT);
			break;
		case UNSIGNED:
		case USHORT:
		case ULONG:
			MODTYPE (type, INT);	/* temporary??later UNSIGNED */
			break;
		case DOUBLE:
			MODTYPE (type, FLOAT);	/* temporary */
			break;
		case UCHAR:
/***		case CHAR:	***/
			MODTYPE (type, CHAR);
	}
	return (type);
}

/*
 * curid is a variable which is defined but
 * is not initialized (and not a function );
 * This routine returns the storage class for an uninitialized declaration
 */
noinit ()
{
	return (EXTERN);
}

/*
 * make a common declaration for id, if reasonable
 * Called from pftn.c for unitialized declarations.	fjl
 * (Actually, for DEFINITIONS, always...)
 */
commdec (id)
{
	register struct symtab *q;
	OFFSZ off;

	q = &stab[id];
	off = tsize (q->stype, q->dimoff, q->sizoff);
	off = ((off-1)/SZINT)+1;	/* round up for words */

	/* make this look different than defnam's 'intern' so can */
	printf(")	entry	%s\n", exname(q->sname));
	/* tell where it came from.				  */
	printf(")%s::	block	%ld\n", exname(q->sname), off);
	q->sflags |= SDEF;			/* means defined here */
}

/*
 * is lastcon to be long or int?
 */
isitlong ()
{
/***	return(lastcon >= (1L << SZINT));  won't work for cross-compiling ***/
	return(0);
}


isitfloat (s)
	char	*s;
{
	double	atof();

	dcon = atof (s);
	return (FCON);
}

/*
 * walk the tree and write out the nodes..
 */
ecode (p)
	NODE	*p;
{

	if (nerrors)
		return;
#ifdef ONEPASS
	p2tree (p);
	p2compile (p);
#else
	printf(".%d\t%s\n", lineno, ftitle);
	prtree(p);
#endif
}
