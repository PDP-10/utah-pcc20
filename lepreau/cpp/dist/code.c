/* <COS.LEPREAU.CPP.DIST>CODE.C.3, 17-Jan-86 16:11:35, Edit by BEEBE */
/* NHFB01: Surround BLT by PUSH/POP to preserve Ac1 -- code generated */
/* for functions which return a "struct" */

/* 
 * code.c - assembler & machine-dependent output fxns, Dec-20 version
 * 
 * Based on Steve Johnson's pdp-11 version
 * Author:	Jay Lepreau
 *		Computer Science Dept.
 * 		University of Utah
 * Date:	11 August 1980
 * Copyright (c) 1980,1982 Jay Lepreau for Dec-20 Version
 */

/*	Dec-20 version 0.2	8/80	J.Lepreau	*/

/* NHFB01: # include <stdio.h> -- comes in with mfile1 */

#ifndef tops20
# include <signal.h>
# include <time.h>
#endif

# include "mfile1"

#define VERSION	"1,2,36,0\n"  /* pcc v, fxlink v, byte size, unused */

#ifdef tops20
char *tmpname = "/scratch/pcXXXXXX";	/* SCRATCH: */
#else
char *tmpname = "/tmp/pcXXXXXX";    /* TMP: is magic to PA1050, e.g. in LINK */
#endif

int	lastloc = PROG;
#define LABSTART 20		/* must be higher than register# max */ 
int	crslab = LABSTART;

int	proflag;		/* profiling option */
int	traceflag;		/* trace option */
int	strftn = 0;    /* is the current function one which returns a value? */
FILE	*tmpfile;			   /* struct or union value, that is */
FILE	*outfile = stdout;

branch( n ){
	/* output a branch to label n */
	/* exception is an ordinary fx branching to retlab: then, return */
	if( n == retlab && !strftn ){
		printf( ")	jrst	$cret\n" );
		}
	else printf( ")	jrst	$%d\n", n );
	}

#ifndef defalign
defalign(n) {			/* null on dec-20 */
	/* cause the alignment to become a multiple of n */
#ifdef notdef
	n /= SZCHAR;
	if( lastloc != PROG && n > 1 ) printf( ")	.even\n" );
#endif notdef
	}
#endif

locctr( l ){
	register temp;
#ifdef notdef
	static int endflg = 0;
#endif
	static int prog_first = 1;		/* 1st time for PROG? */
	static int data_first = 1;		/* etc.	*/

	/* l is PROG, ADATA, DATA, STRNG, ISTRNG, or STAB, STACK */

	if (l != STRNG && l != ISTRNG) outfile = stdout;  	/* kludge! */
	if( l == lastloc ) return(l);
	temp = lastloc;
	lastloc = l;
	switch( l ){

	case PROG:
#ifdef notdef
		outfile = stdout;		/* done above */
		if (temp == DATA || temp == ADATA) {
		if (endflg) printf( ")	.endps\n");
		printf( ")	.psect	$text\n" );
#endif notdef
		loctr2(PROG, prog_first);	/* for safety */
		prog_first = 0;
		break;

	case DATA:
	case ADATA:
#ifdef notdef
		outfile = stdout;	***done above****/
#endif
		if (temp != DATA && temp != ADATA ) {
#ifdef notdef
			if (endflg) printf( ")	.endps\n");
			printf( ")	.psect	$data\n" );
#endif
			loctr2(DATA, data_first);
			data_first = 0;
		}
		break;

	case STRNG:	/* regular strings - should go in text section */
	case ISTRNG:	/* init'ed strings (global)- must go in data section */
		outfile = tmpfile;
		lastloc = temp; /* added - strings don't affect current (fjl)*/
		break;		/* segment, just outfile;special-cased kludge*/

	case STAB:
		cerror( "locctr: STAB unused" );
		break;

	case STACK:
		cerror ("locctr: STACK unused");
		break;

	default:
		cerror( "illegal location counter" );
		}

#ifdef notdef
	endflg = 1;
#endif
	return( temp );
	}

static			/* added for safety while going to reloc's --fjl */
loctr2(loctyp, firstflg)
int loctyp, firstflg;
{
	static int lastloc = -1;	/* invalid */
	static int prog1 = 1;
	static int data1 = 1;

	switch(loctyp) {
		case PROG:
			if (prog1) {
				if (!firstflg)cerror("loctr2: prog needs 1st");
				prog1 = 0;
				printf(")	reloc	$text\n");
			}
			else {
				if (lastloc != DATA)
					cerror("loctr2: prog mismatch");
				if (firstflg)
					cerror("loctr2: prog extra 1st");
				printf(")	reloc\n");
			}
			break;

		case DATA:
			if (data1) {
				if (!firstflg)cerror("loctr2: data needs 1st");
				data1 = 0;
				printf(")	reloc	$data\n");
			}
			else {
				if (lastloc != PROG)
					cerror("loctr2: data mismatch");
				if (firstflg)
					cerror("loctr2: data extra 1st");
				printf(")	reloc\n");
			}
			break;

		default: cerror("loctr2: bad loctype");
			break;
		}

	lastloc = loctyp;
}


deflab( n ){
	/* output something to define the current position as label n */
	fprintf( outfile, ")$%d:!\n", n );	/* ! means not in debugger */
	}


getlab(){			/* return a number usable for a label */
	if (++crslab >= PASS2LAB)
	    cerror("pass1 label overflow");
	return (crslab);
	}

efcode(){
	/* code for the end of a function */

	if (strftn) {  /* copy output (in r1) to caller, ie for fxs returning
						 strucs (pointed to by r1). */
		register struct symtab *p;
		register int stlab;
		register int count;
		int size;

		p = &stab[curftn];

		deflab( retlab );

		stlab = getlab();
		size = tsize(DECREF(p->stype), p->dimoff, p->sizoff) / SZCHAR;
		count = size / NCHPERINT;    /* what if not integral?? fjl */
		printf( ")\thrl	$1,$1\n)	hrri	$1,$%d\n", stlab );
/* NHFB01: Ac1 gets clobbered by BLT -- need to save and restore */
/*
		printf( ")\tblt	$1,$%d+%d-1\n)	hrrzs	$1,$1\n", stlab,count);
*/
		printf( ")\tpush\t$p,$1\n");
		printf(")\tblt	$1,$%d+%d-1\n",stlab,count);
		printf(")\tpop\t$p,$1\n");
		printf(")\thrrzs\t$1,$1\n");
		printf( ")	reloc\n" );
		printf( ")\tarray\t$%d[%d]\n)	reloc\n", stlab, count );
		/* turn off strftn flag, so return sequence will be generated*/
		strftn = 0;
		}
	branch( retlab );
	printf(")	lit\n");  /* for locality, also make sure in text seg*/

#ifdef ONEPASS
	p2bend();
#else
	printf("]\n");
#endif
	}

bfcode( a, n ) int a[]; {
	/* code for the beginning of a function; a is an array of
		indices in stab for the arguments; n is the number */
	register i;
	register temp;
	register struct symtab *p;
	OFFSZ	off;

	p = &stab[curftn];
	if (!strcmp(p->sname, "main")) {	/* main: gen link code */
		printf (")	extern	$start\n");
		printf (")	byte	(9)");
		printf (VERSION); /* pcc ver,fx linkage ver,byte size,unused */
	}
	printf(")	4($p)\n)	10\n");	/* end for blt; lowregver */
	defnam( p );
	temp = p->stype;
	temp = DECREF(temp);
	strftn = (temp==STRTY) || (temp==UNIONTY);

	retlab = getlab();
	if( proflag ){
		int plab;
		plab = getlab();
		printf( ")	movei	$0,$%d\n", plab );
		printf( ")	pushj	$p,$mcount\n" );
		printf( ")	reloc\n)\tinteger\t$%d\n)reloc\n",plab);
		}

	/* routine prolog */

	printf( ")	pushj	$p,$csv\n" );
	/* adjust stack for autos */
	printf( ")	adjsp	$p,$F%d\n", ftnno ); /* Fx defined in pass2 */
	off = ARGINIT;

	for( i=0; i<n; ++i ){
		p = &stab[a[i]];
		if( p->sclass == REGISTER ){
			temp = p->offset;  /* save register number */
			p->sclass = PARAM;  /* forget that it is a register */
			p->offset = NOOFFSET;
			oalloc( p, &off );
			printf( ")\tmove\t$%o,%d($fp)\n", temp,(int)p->offset/SZINT);
			p->offset = temp;  /* remember register number */
			p->sclass = REGISTER;   /* remember that it is a register */
			}
		else {
			if( oalloc( p, &off ) ) cerror( "bad argument" );
			}

		}
/** insert /6 trace stuff here **/
	}

bccode(){	/* called just before the first executable statment */
		/* by now, the autos and register variables are allocated */
	SETOFF( autooff, SZINT );
	/* set aside store area offset */

#ifdef ONEPASS
	p2bbeg( autooff, regvar );
#else
	printf("[%d\t%ld\t%d\t\n", ftnno, autooff, regvar); /* OFFSZ depend! */
#endif
	}

extern char *ctime();
extern char *rindex();

bjobcode(filnam)	/* called right after got 1st title line: added -fjl */
char *filnam;
{
	long  clock;
	char  *p;

	time(&clock);
#ifdef tops20
	printf(");pcc-20 v1A.4 compilation %s", ctime(&clock));
#else
	printf(");Unix pcc-20 v0.2 cross-compilation %s", ctime(&clock));
#endif
	if (*filnam == EOS) p = "stdin";
	else if ((p = rindex(filnam, '/')) == NULL) p = filnam;
	  else p++;				/* strip off pathname */
	printf(")	title	%s\n", p);
	printf(")\tradix\t10\n)	search	$cdefs(pcc:$cdefs.unv)\n)\t.directive flblst,sfcond,kl10\n)	twoseg	$text\n");
}

ejobcode( flag ){		/* called just before final exit */
				/* flag is 1 if errors, 0 if none */
	}

aobeg(){
	/* called before removing automatics from stab */
	}

aocode(p) struct symtab *p; {
	/* called when automatic p removed from stab */
	}

aoend(){
	/* called after removing all automatics from stab */
	}

defnam( p ) register struct symtab *p; {
	/* define the current location as the name p->sname */

	if( p->sclass == EXTDEF ){
		printf( ")	entry	%s\n", exname( p->sname ) );
		p->sflags |= SDEF;	/* means defined in this file! -fjl */
		}

	if( p->sclass == STATIC && p->slevel>1 ) deflab( (int)p->offset );
	    else printf( ")%s:%c\n", exname(p->sname), 
		p->sclass == STATIC ? ' ' : ':');

	}

bycode( t, i ){
	/* put byte i+1 in a string */

	i &= 017;		/* see below */
	if( t < 0 ){ /* end of the string */
		if( i != 0 ) fprintf( outfile, "\n" );
		}

	else { /* stash byte t into string */
		if (i == 0) fprintf(outfile, ")	byte	(36)");	  /* TEMP!! */
		else fprintf( outfile, "," );
		fprintf( outfile, "%d", t );	     /* decimal for now. fjl */
		if( i == 017 ) fprintf( outfile, "\n" ); /* max 16 on a line */
		}
	}

zecode( n ){
	/* n integer words of zeros */
	OFFSZ temp;
	register i;

	if( n <= 0 ) return;
#if 0
	/* This code is WRONG-- the extra "," at the end of */
	/* each line causes MACRO to supply an extra zero! */
	printf( ")	exp	" );
	for( i=1; i<n; i++ ) {
		if( i%24 == 0 )			/* max 24 on a line */
			printf( "\n)	exp	" );
		printf( "0," );
		}
	printf( "0\n" );
#else
	/* Here is a correct version, which also produces */
	/* much shorter output if n is large */
	if ( n == 1)
	    printf( ")\texp\t0\n");
	else
	{
	    printf( ")\txlist\n");
	    printf( ")\trepeat\t^D%d,<exp 0>\n", n);
	    printf( ")\tlist\n");
	}
#endif

	temp = n;
	inoff += temp*SZINT;
}

fldal( t ) 			/* return the alignment of field of type t */
unsigned t;
{
	uerror( "illegal field type" );
	return( ALINT );
}

fldty( p ) 			/* fix up type of field p */
struct symtab *p;
{
	;
}

/* print location of error
 *  c is either:	'u'	user error
 *			'c'	compiler error
 *			'w'	warning
 */
where(c)
char c;
{
	fprintf( stderr, "%s, line %d: ", ftitle, lineno );
}

main( argc, argv )
int argc; char *argv[];
{
	register int	c;
	register int	i,j;
	int		r;
	extern	 int	dexit();	/* was not extern in 11 */

	for( i=1; i<argc; ++i )
		if( argv[i][0] == '-') {
			if (argv[i][1] == 'X') switch(argv[i][2])
			{
				case 'p':
					proflag = 1;
					break;
				case 'T':
					traceflag = 1;
					break;
			}
		}

	mktemp(tmpname);
#ifndef tops20		/* these are illegal ptr combos now... */
	if(signal( SIGHUP, SIG_IGN) != SIG_IGN) signal(SIGHUP, dexit);
	if(signal( SIGINT, SIG_IGN) != SIG_IGN) signal(SIGINT, dexit);
	if(signal( SIGTERM, SIG_IGN) != SIG_IGN) signal(SIGTERM, dexit);
#endif
	tmpfile = fopen( tmpname, "w" );
	if (tmpfile == NULL) cerror("can't open temp file\n");

	r = mainp1( argc, argv );

	tmpfile = freopen( tmpname, "r", tmpfile );
	if( tmpfile != NULL ) {
		while((c=getc(tmpfile)) != EOF ) putchar(c);
		pextrns();		/* dump out undefined externs */
#ifdef notdef			/* Macro doesn't like this */
	    /* purge local symbols */
		printf(")	purge	");   /* ok if no labels */
		for (j = 0, i = LABSTART+1; i <=crslab; ++i) {
			if (++j > 16) {
				j = 0;
				printf("\n)	purge	");
			}
			printf("$%d,", i);
		}
		printf("\n)	end\n");
#else
		printf(")	end\n");
#endif notdef
	}
	else cerror( "Lost temp file" );
	unlink(tmpname);
	return( r );
}

pextrns() {		/* declare undefined externs to keep macro happy */
	register struct symtab *p;
	register char *cp;

	for (p = stab; p < &stab[SYMTSZ]; ++p) {
		if (p->stype != TNULL && p->sclass == EXTERN
		  && !(p->sflags & SDEF) ) {
			cp = exname(p->sname);
			printf(")	.if	%s,referenced,<extern %s>\n",
				cp, cp);
	}

#ifdef notdef					/* Debug */
		if (p->stype != TNULL) {
			printf(")stype=%o	sclass=%o	sname=%s\n",
			p->stype, p->sclass, p->sname);
		}
#endif notdef
	}
}

dexit( v ) {
	unlink(tmpname);
	exit(v);		/* was exit(1) in 11 */
}

genswitch(p,n)
register struct sw *p;
{
	/*	p points to an array of structures, each consisting
		of a constant value and a label.
		The first is >=0 if there is a default label;
		its value is the label number
		The entries p[1] to p[n] are the nontrivial cases
	*/

	register i;
	register CONSZ j, range;
	register dlab, swlab;
	char	instr[10];

	range = p[n].sval-p[1].sval;

	if( range>0 && range <= 3*n && n>=4 ){ /* implement a direct switch */

		dlab = p->slab >= 0 ? p->slab : getlab();

		if( j = p[1].sval ){
			if (j < 0) {
				strcpy (instr, "add");
				j = -j;
				}
			  else strcpy (instr, "sub");
			if (j > MAXSHORT) printf( ")\t%s\t$1,[%ld]\n", instr, j);
			  else printf( ")	%si	$1,%ld\n", instr, j);
			}

		/* note that this is a cl; it thus checks
		 * for numbers below range as well as out of range.
		 */
		if (range > MAXSHORT)
			printf( ")	camg	$1,[%ld]\n", range );
		else
			printf( ")	caig	$1,%ld\n", range );
	/* NB: Can't use indirect addressing here!!  Cause if we have -2
	 * in r1 here, we'll be in an infinite indirect addr expansion.
	 * Happens before the compare to 0.  Amazing!
	 */
		printf( ")	jumpge	$1,$%d($1)\n", swlab = getlab() );
		printf( ")	jrst	$%d\n", dlab );

		/* output table */

#ifdef notdef
		locctr( ADATA );
#endif
		defalign( ALPOINT );
		deflab( swlab );

		for( i=1,j=p[1].sval; i<=n; ++j ){

			printf( ")	jrst	$%d\n", ( j == p[i].sval ) ?
				p[i++].slab : dlab );
			}

#ifdef notdef
		locctr( PROG );
#endif
		if( p->slab< 0 ) deflab( dlab );
		return;

		}

	/* debugging code */

#ifdef notdef
	if( n >= 4 )
	    werror( "inefficient switch: %d, %d", n, (int) (range/n));
#endif

	/* simple switch code */

	for( i=1; i<=n; ++i ) {
		/* already in r1 */

		if (j = p[i].sval) {
			if ( (j < 0) || (j > MAXSHORT) )
			    printf( ")	camn	$1,[%ld]\n", j );
			  else printf( ")	cain	$1,%ld\n", j );
			strcpy (instr, "jrst	");	/* that's a tab */
			}
		    else strcpy (instr, "jumpe	$1,");	/* and here too */
		printf( ")	%s$%d\n", instr, p[i].slab );
		}

	if( p->slab>=0 ) branch( p->slab );   /* default label for fall thru */
}
