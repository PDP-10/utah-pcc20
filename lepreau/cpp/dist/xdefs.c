# include "mfile1"

/*
 *	communication between lexical routines
 */
char	ftitle[100] = "";	/* title of the file */
int	lineno;			/* line number of the input file */

CONSZ	lastcon;	/* the last constant read by the lexical analyzer */
double	dcon;		/* the last double read by the lexical analyzer */

/*
 *	symbol table maintainence
 */
struct symtab	stab[SYMTSZ+1];	/* one extra slot for scratch */

int	curftn;			/* "current" function */
int	ftnno;			/* "current" function number */
int	curclass,	/* current storage class */
	instruct,	/* "in structure" flag */
	stwart,		/* for accessing names which are structure members or names */
	blevel,		/* block level: 0 for extern, 1 for ftn args, >=2 inside function */
	curdim;		/* current offset into the dimension table */
	
int	dimtab[ DIMTABSZ ];

int	paramstk[PARAMSZ];  /* used in the definition of function parameters */
int	paramno;	/* the number of parameters */

OFFSZ	autooff,	/* the next unused automatic offset */
	argoff,		/* the next unused argument offset */
	inoff,		/* offset of external element being initialized */
	strucoff;	/* the next structure offset position */
			/* NB: altho strucoff is OFFSZ, other work vars which 
			 * it uses, & siztab, paramstk, etc are NOT, so will
			 * not work for structs with elts > 900 length...fjl
			 */

int	regvar;		/* the next free register for register variables */
int	minrvar;	/* the smallest that regvar gets within a function */

int	brkflag = 0;	/* complain about break statements not reached */

struct sw	swtab[SWITSZ],	/* table for cases within a switch */
		*swp;	/* pointer to next free entry in swtab */
int	swx;		/* index of beginning of cases for current switch */

/*
 * debugging flag
 */
int	xdebug = 0;

int	strflg;			/* if on, strings are to be treated as lists */
int	reached;		/* true if statement can be reached... */
int	idname;			/* tunnel to buildtree for name id's */

NODE	node[TREESZ];

int	cflag = 0,	/* do we check for funny casts */
	hflag = 0,	/* do we check for various heuristics which may indicate errors */
	pflag = 0;	/* do we check for portable constructions */

int	brklab,
	contlab,
	flostat,
	retlab = NOLAB,
	retstat;

/*
 * save array for break, continue labels, and flostat
 */
OFFSZ	asavbc[BCSZ],		/* OFFSZ cause also holds autooff -fjl */
	*psavbc = asavbc;

static char *
ccnames[] = {			/* names of storage classes */
	"SNULL",
	"AUTO",
	"EXTERN",
	"STATIC",
	"REGISTER",
	"EXTDEF",
	"LABEL",
	"ULABEL",
	"MOS",
	"PARAM",
	"STNAME",
	"MOU",
	"UNAME",
	"TYPEDEF",
	"FORTRAN",
	"ENAME",
	"MOE",
	"UFORTRAN",
	"USTATIC",
};

/*
 * return the name for storage class c
 */
char *scnames(c)
	register c;
{
	static char buf[12];
	if( c&FIELD ){
		sprintf( buf, "FIELD[%d]", c&FLDSIZ );
		return( buf );
	}
	return( ccnames[c] );
}
