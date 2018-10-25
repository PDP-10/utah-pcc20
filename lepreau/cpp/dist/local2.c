/* 
 * local2.c - machine-dependent pass2 fxns, Dec-20 version
 * 
 * Based on Steve Johnson's pdp-11 version
 *   and Sam Leffler's Harris/6 version.
 * Author:	Jay Lepreau
 *		Computer Science Dept.
 * 		University of Utah
 * Date:	21 November 1980
 * Copyright (c) 1980,1981 Jay Lepreau for Dec-20 Version
 */

/* 	Dec-20 version 0.1	11/80	J.Lepreau	*/

# include "mfile2"

/*
 * a lot of the machine dependent parts of the second pass
 */

int	toff = 0;		/* number of stack locations used for args */

/*
 *	Table of operators that are too hard to do in-line, the
 *	routine hardops transforms the expression trees when they are
 *	read in, so that these operators are replaced with the
 *	appropriate function calls.
 */
struct functbl{
	int	fop;
	TWORD	ftype;
	char	*func;
} opfunc[] = {				/* none currently - Dec-20 */
	0,		0,	0
};

/*
 *	When the OX macro appears in the code table the hopcode function
 *	is called to extract the correct op code from the hoptab table.
 */
struct hoptab {
	int     opmask;
	char   *opstring;
} ;

struct hoptab ioptab[] = {			/* just OPSIMP's now */
        ASG PLUS,	"add",	/* note these are also used w/o the ASG */
	ASG OR,		"ior",
	ASG AND,	"and",
	ASG MUL,	"imul",
	ASG MINUS,	"sub",	/* NOT an opcomm, but an opsimp: not used for ASG */
	ASG ER,		"xor",
	-1,		""    };

struct hoptab foptab[] = {	/* floating pnt table for hopcode: OF macro */
	ASG PLUS,	"fadr",
	ASG MINUS,	"fsbr",
	ASG MUL,	"fmpr",
	ASG DIV,	"fdvr",
	-1,		""	};

/*
 * keyed to register number tokens
 */
char   *rnames[] = {		/* make these like octal cause of ddt */
	"$0", "$1", "$2", "$3",
	"$4", "$5", "$6", "$7",
	"$10", "$11", "$12", "$13",	/* decimal 8, 9, 10, 11 */
	"$14", "$15", "$fp", "$p"	/* decimal 12, 13	*/
};

/*
 *	Register status table, indexed by the register defines in mac2defs.
 *	(Note that \everthing/ starts out temporary.)
 */
SHAPESZ rstatus[] = {	/* exclude r0 for now cause invalid idx reg */
        	   0, SAREG|STAREG, SAREG|STAREG,	/* 0, 1, 2 */
	SAREG|STAREG, SAREG|STAREG, SAREG|STAREG,	/* 3, 4, 5 */
	SAREG|STAREG, SAREG|STAREG, SAREG|STAREG,	/* 6, 7, 8 */
        SAREG|STAREG, SAREG|STAREG, SAREG|STAREG,	/* 9, 10, 11 */
	SAREG|STAREG, SAREG|STAREG, 			/* 12, 13  */
	SAREG, SAREG,					/* fp, sp */
	};

/*
 * Resource preference table.
 *
 * Used in reclaiming resources when rewriting a tree in reclaim().
 * Left hand side is the cookie the reclaim was done with, the right hand
 * side is the shape(s) preferred.
 */
struct respref  respref[] = {
	INTAREG,	STAREG,
	INAREG,		SAREG,
	INAREG,		SOREG|SNAME|SCON|STARNM,
	INTEMP,		INTEMP,
	FORARG,		FORARG,
	INTAREG,	SOREG|SNAME,		/* this one is doubtful */
	0,		0
};

/*
 *	Conditional branch op code table, used by cbgen for generating
 *	code for the conditional branch sequences.
 */
char   *ccbranches[] = {	/* just suffixes for 'cam' and 'cai' now. */
/* EQ */  "e",
/* NE */  "n",
/* LE */  "le",
/* LT */  "l",
/* GE */  "ge",
/* GT */  "g",
/* ULE */ "ule",		/* unsigned's are error generators for now! */
/* ULT */ "ul",
/* UGE */ "uge",
/* UGT */ "ug"
};

/*
 *	Conditional branch op code table, used (as above) for floating point
 */
char	*fccbranches[] = {""};	/* Deleted for Dec-20 */

/*
 * Table used to reverse relationals; needed in case the order of
 * a comparison with memory ends up reversed. (This avoids placing
 * the other side in a register).
 */		/* also defined in optim.c; ref'ed in order.c */
short revrel[] = {
	EQ, NE,
	GE, GT,
	LE, LT,
	UGE, UGT,
	ULE, ULT
};

/* Table used to get the \negations/ of relationals, as opposed to above. */
/* Defined in reader.c	*/
extern int negrel[];

/*
 * identify line l and file fn
 */
#ifndef lineid
lineid (l, fn)
char   *fn;
{
	printf(";l %d %s\n", l, fn);
}
#endif

/*
 * End a block, and set size of the stack frame needed for local variables
 * and compiler generated temporaries.
 */
eobl2 ()
{
	OFFSZ spoff;		       /* offset from stack pointer */
	spoff = maxoff;
/*****	if (spoff >= AUTOINIT)
		spoff -= AUTOINIT;	*********/
	spoff /= SZCHAR;
	SETOFF (spoff, NCHPERINT);
	spoff /= NCHPERINT;
	printf( "$F%d==%ld\n", ftnno, spoff);		/* %ld if OFFSZ long */
	if (fltused) {
		fltused = 0;
/******		printf("	.globl	fltused\n");     ?? ********/
	}
}

/*
 * output the appropriate string from the hoptab table
 */
hopcode (f, o)
	char	f;
	int	o;
{
	register struct hoptab *q;
	for (q = (f == 'F') ? foptab : ioptab; q->opmask >= 0; ++q) {
		if (q->opmask == o  || q->opmask-1 == o) {    /* w % w/o asg */
			printf ("%s", q->opstring);
			return;
		}
	}
	cerror ("no hoptab for %s", opst[o]);
}
/*
 * Machine independent interface to the code tables,
 * called when expand() runs across a `Z' in the code string.
 */

static ccreg = -1;		/* used by zzzcode & cbgen only */

zzzcode (p, c)
NODE * p;
{
	register        m;
	NODE		*r;
	switch (c) {
		case 'E':	/* Error check for constant LS */
			if (p->right->rval) cerror("Named constant to LS");
			break;

		case '+': 			/* push a single word */
			toff++;			/* always push for dec-20 */
			return;

		case 'A':		/* emit a label */
			printf ( "$%d", p->label);
			return;

		case 'I':
		case 'C':			/* logical compares */
		case 'R':			/* negated logical compares */
			cbgen (p->op, p->label, c);  /* cbgen differentiates */
			return;

		case 'N':	/* logical ops, turned into 0-1		*/
				/* use register given by resource 1	*/
			cbgen(0, m = getlab(), 'I');
			deflab(p->label);
			printf("	setz	%s,\n", rnames[getlr(p, '1')->rval] );
			deflab(m);
			return;

		case 'S':			/* structure arg */
			toff += p->stsize;
			return;

		case 'W':			/* structure size */
			if (p->op == STASG || p->op == STARG)
				printf( "%d", p->stsize);
			    else cerror ("zzzcode, ZW: not a structure");
			return;

		case 'V':	/* save right son reg# from forcc opltype */
			ccreg = getlr(p, 'R')->rval;	/* used by cbgen  */
			return;

		case '0':				/* set ccreg = r0 */
			ccreg = R0;
			return;

		default:
			cerror("illegal zzzcode %c", c);
	}
}

#ifndef rmove
/*
 *	Register transfer, usually called only in reclaim() when
 *	the result is not in a MUSTDO register.
 */
rmove(rt, rs, t)
	TWORD	t;
	int	rt,
		rs;
{
		printf( "	move	%s,%s\n", rnames[rt], rnames[rs]);
}
#endif

/*
 * Set up the number of free registers
 */
setregs(){ /* set up temporary registers */
	register i;

	/* use any unused variable registers as scratch registers */
	/* less 1 on both sides of : cause not including R0 */
	fregs = maxtreg>=MINRVAR ? maxtreg : MINRVAR - 1;
	if( xdebug ){
		/* -x changes number of free regs to 2, -xx to 3, etc. */
		if( (xdebug+1) < fregs ) fregs = xdebug+1;
		}
	if ( fregs > MAXRVAR ) fregs = MAXRVAR;
	for( i=MINRVAR; i<=MAXRVAR; i++ )  /* <= below cause r0 not included */
		rstatus[i] = i <= fregs ? SAREG|STAREG : SAREG;
	}

#ifndef szty
/*
 * Size of type t in registers (sort of)
 */
szty(t)
	TWORD	t;
{
	if(t == DOUBLE) return(SZDOUBLE/SZINT);
	return(1);
}
#endif

#ifndef rewfld
/*
 * Rewrite rules for fields	...ok for now...
 */
rewfld(p)
	NODE	*p;
{
	return(1);
}
#endif

#ifndef callreg
/*
 * What register should be used to call the function under p
 */
callreg(p) NODE *p; {
	return (R1);	/* for now when have floats only */
/****	return( (p->type==DOUBLE||p->type==FLOAT) ? R0 : R1 );	/* ??? */
	}
#endif

/*
 * Boolean, return 1 if p/o represent a leaf node in the tree
 */
shltype(o, p)
	NODE	*p;
{
	if (o == NAME || o == REG || o == ICON || o == OREG) return(1);
	return (o == UNARY MUL && shumul(p->left) );
}

/*
 * Boolean, does the tree p form a field shape?
 */
flshape(p)
	register NODE	*p;
{
	register	 o = p->op;
	if (o == NAME || o == REG || o == ICON || o == OREG) return(1);
	return (o == UNARY MUL && shumul(p->left) == STARNM);
}

/*
 * Boolean, does p represent a temporary shape?
 */
shtemp(p)	/* backwards? no, temps do not include temp. registers! */
	register NODE	*p;
{
	if (p->op == UNARY MUL) p = p->left;
	if (p->op == REG || p->op == OREG)
		return(!istreg(p->rval));
	return(p->op == NAME || p->op == ICON);
}

/*
 * Is v the right value to increment something of type t ?
 */		/* (only for pointers) */
spsz(t, v)
	TWORD	t;
	CONSZ	v;
{
	if ( !ISPTR(t) ) return(0);
	t = DECREF(t);
	if ( ISPTR(t) ) return(v == 1);
	switch(t){
		case UCHAR:		/* bytes */
		case CHAR:		/*  "	 */
		case INT:		/* words */
		case UNSIGNED:		/*  |	 */
		case FLOAT:		/*  \/	 */
			return(v == 1);
		case DOUBLE:
			return(v == 1);	/* just for now, should be 2  ?*/
	}
	return(0);
}

/*
 * Define the shapes that may lie under a UNARY MUL (i.e. STARNM & STREG's)
 */		/* think no STARREGs on Dec-20 */
SHAPESZ
shumul( p ) register NODE *p; {
	register o;

	o = p->op;
	if( o == NAME || o == OREG || o == ICON ) return( STARNM );
	return( 0 );	/* why not REG above? already cnvted to OREG?? */
	}

#ifndef adrcon
adrcon( val ) CONSZ val; {
	printf( CONFMT, val );
	}
#endif

conput( p ) register NODE *p; {		/* very different in /6?? */
	switch( p->op ){

	case ICON:
		acon( p );
		return;

	case REG:
		printf( "%s", rnames[p->rval] );
		return;

	default:
		cerror( "illegal conput" );
		}
	}

insput (p, lrp) NODE *p, *lrp; {		/* added 1st param - fjl */
	if (special(lrp, SACON))		/* works with vadrput	 */
		putchar('i');
	else
		if (logop(p->op)) putchar('m');	/* for cai/cam */
		/* otherwise blank */
	}

vadrput( p ) NODE *p; {				/* distinguish type of node */
	if (special(p, SACON)) conput(p);
	else adrput(p);
	}

upput( p ) NODE *p; {
	cerror( "upput" );
	}

adrput( p ) register NODE *p; {
	/* output an address, with offsets, from p */

	if( p->op == FLD ){
		p = p->left;
		}
	switch( p->op ){

	case NAME:
		acon( p );
		return;

	case ICON:
		/* addressable value of the constant */
/* 		if( szty( p->type ) == 2 ) {
/* 			/* print the high order value */
/* 			CONSZ save;
/* 			save = p->lval;
/* 			p->lval = ( p->lval >> SZINT ) & BITMASK(SZINT);
/* 			printf( "$" );
/* 			acon( p );
/* 			p->lval = save;
/* 			return;
/* 			}
****/

/* in general, must check for bptype(p->type) here when have chars,	*/
/* then build bp.							*/
		putchar ('[');		/* literal */
		acon( p );
		putchar (']');
		return;

	case REG:
		printf( "%s", rnames[p->rval] );
		return;

	case OREG:
		if( p->rval == FP ){  /* in the arg/automatic region */
			if( p->name[0] != '\0' ) werror( "bad arg temp" );
			printf( CONFMT, p->lval );
			printf( "($fp)" );
			return;
			}
		if( p->lval != 0 || p->name[0] != '\0' ) acon( p );
		printf( "(%s)", rnames[p->rval] );
		return;

	case UNARY MUL:
		/* STARNM or STARREG found */
		if( tshape(p, STARNM) ) {
			putchar('@');
			adrput( p->left);
			return;
			}
		else cerror ("bad UNARY MUL to adrput");

	default:
		cerror( "illegal address" );
		return;

		}

	}

acon( p ) register NODE *p; { /* print out a constant */

	if( p->name[0] == '\0' ){	/* constant only */
		printf( CONFMT, p->lval);
		}
	else if( p->lval == 0 ) {	/* name only */
		printf( "%.8s", p->name );
		}
	else {				/* name + offset */
		printf( "%.8s+", p->name );
		printf( CONFMT, p->lval );
		}
	}

#ifndef genscall
/*
 * Generate code for a call of a function returning a structure
 */
genscall(p, cookie)
	register NODE	*p;
	COOKSZ		cookie;
{
	return(gencall(p, cookie));	/* same as gencall now */
}
#endif

/*
 * Generate a call for a normal function call; return 1 on \failure/
 */
gencall(p, cookie)
	register NODE	*p;
	COOKSZ		cookie;
{
	register	temp,
			m,
			o;

	if (p->right) temp = argsize(p->right);
	    else temp = 0;
	if (p->right) genargs(p->right);	/* generate arguments */	

	/*
	 * Insure that we can address the function to be called
	 */
	if( !shltype( p->left->op, p->left ) ) {
		order( p->left, INAREG|SOREG|INTEMP );
		}

	p->op = UNARY CALL;
	m = match( p, INTAREG|INTBREG );

	toff -= temp;

/**	if(toff <= 0 && temp >= 1) *** code for empty stack top ***
		temp--, toff++;		*********/

	if (temp) printf( "	adjsp	$p,-%d\n", temp);

	return(m != MDONE);	/* returns 1 on failure! */
}

/*
 * Generate code for a conditional branch
 */
cbgen(o, lab, mode)
{
	if (o > UGT) cerror("bad conditional branch: %s", opst[o]);
	switch (mode) {
		case 'I':			/* complete branch */
			if(o == 0) printf("	jrst	$%d\n", lab);
			    else {
				if (ccreg < 0 || ccreg > (REGSZ-1))
					cerror("invalid ccreg to cbgen"); 
				printf ("	jump%s	%s,$%d\n",
					ccbranches[o-EQ], rnames[ccreg], lab);
				ccreg = -1;	/* reset to be safe */
				}
			return;

		case 'R':			/* negated compare only */
			o = negrel[o-EQ];
		case 'C':			/* compare only */
			printf (ccbranches[o-EQ]);
	}
}

/*
 * If the template matching fails with one cookie, give another to try
 */
COOKSZ
nextcook(p, cookie)
	register NODE	*p;
	COOKSZ		cookie;
{
	if(cookie == FORREW)
		return( (COOKSZ)0 );	/* hopeless! */
	if( !(cookie&(INTAREG|INTBREG)) )
		return( INTAREG|INTBREG );
	if( !(cookie&INTEMP) && asgop(p->op) )
		return( INTEMP|INAREG|INTAREG|INTBREG|INBREG );

	return(FORREW);
}

#ifndef lastchance
/*
 * Last chance to generate code for a subtree, otherwise halt with a
 * no match error.
 */
lastchance(p, cook)
	register NODE	*p;
	COOKSZ		cook;
{
	return(0);		/* forget it! */
}
#endif

/*
 * Launder the trees read in from the first pass
 */
myreader(p)
	register NODE	*p;
{
/***	walkf(p, hardops);	no hardops on dec-20 ***/
	canon(p);
	toff = 0;		/* walkf with optim2 was also in pdp-11 */
}

/*
 * Boolean, does node p have the special shape shape ?
 */
special(p, shape)
	register NODE	*p;
	SHAPESZ		shape;
{
	if (p->op == ICON) {
		if (p->name[0] == '\0') switch(shape) {
			case SPCON:		/* BOOT problem?? */
			case SACON:
				return(p->lval >= 0 && p->lval <= MAXSHORT);
			case SNCON:	/* note is used as postive #, so can't use full 2**18 */
				return(p->lval <0 && p->lval >= -(MAXSHORT));
			case SONE:
				return(p->lval == 1);
			case SMONE:
				return(p->lval == -1);
			default:
				cerror("bad special shape %o\n", shape);
			}
		    else return(shape == SACON);
		}
	return(0);
	}

# ifndef ONEPASS
main(argc, argv)
int argc;
char **argv;
{
	return(mainp2(argc, argv));
}

where(c)
char c;
{
	extern char	filename[];
	fprintf(stderr, "%s, line %d: ", filename, lineno);
}

dexit(v)
int v;
{
	exit(v);
}
#endif

/*
 * Fix up PACONV for register r		ie, Make Byte Pointer
 */ /*	Must find out if r holds a bp already or just the # of bytes.
	This code currently assumes the latter.??			*/

paconv(p, r)
	register NODE	*p;
	register	r;
{
	CONSZ		words,
			save;
	register	bytes;
	if (p->right->lval < 0 || p->right->name[0] != '\0')
		cerror("unexpected constant to paconv");
	save = p->right->lval;
	bytes = save % NCHPERINT;
	words = save / NCHPERINT;

/* Must do this even if save = 0 cause must \make/ the byte ptr. */
	printf("	lsh	%s,2\n", rnames[r]); /*words -> bytes*/
	printf("	adjbp	%s,[point 9,%d,%d]",
		rnames[r], words, bytes*9 + 8 );    /* cnvt to pnt's bit pos */
}

/*
 * Fix up PSCONV for register r			 not done yet?? 
 */
psconv(p, r)
	register NODE	*p;
	register	r;
{
	CONSZ		words,
			save;
	register	bytes;
	if (p->right->lval <= 0 || p->right->name[0] != '\0')
		cerror("unexpected constant for psconv");
	bytes = NCHPERINT - (p->right->lval-1)%NCHPERINT;
	words = (p->right->lval-1)/NCHPERINT+1;
	save = p->right->lval;
	p->right->lval = words;
	if (words) {
		printf("	so%s	", rnames[r]);
		acon(p->right);
		putchar('\n');
	}
	while (bytes-- > 0)
		printf("\tbb%s\t.+1\n", rnames[r]);
	p->right->lval = save;
}

/*
 * Fix up bpoint + constant		 not done yet?? 
 *	bpoint is in register r
 */
bpadd(p, r)
	register NODE	*p;
	register	r;
{
	CONSZ		words;
	register	bytes;
	if (p->right->lval < 0 || p->right->name[0] != '\0')
		cerror("unexpected constant to bpadd");
	bytes = p->right->lval % NCHPERINT;
	words = p->right->lval/NCHPERINT;
	if (words)
		printf("	ao%s	%ld\n", rnames[r], words);
	while (bytes-- > 0)
		printf("	bb%s	.+1\n", rnames[r]);
}

/*
 * Fix up bpoint - constant		 not done yet?? 
 *	bpoint is in register r
 */
bpsub(p, r)
	register NODE	*p;
	register	r;
{
	CONSZ		words;
	register	bytes;
	if (p->right->lval <= 0 || p->right->name[0] != '\0')
		cerror("unexpected constant to bpsub");
	bytes = 2 - (p->right->lval-1)%NCHPERINT;
	words = (p->right->lval-1)/NCHPERINT+1;
	while(bytes-- > 0)
		printf("	bb%s	.+1\n", rnames[r]);
	if (words)
		printf("	so%s	%ld\n", rnames[r], words);
}
