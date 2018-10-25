/* 
 * table.c - code-gen tables for Dec-20 Macro assembler
 * 
 * Author:	Jay Lepreau
 *		Computer Science Dept.
 * 		University of Utah
 * Date:	3 February 1981
 * Copyright (c) 1981,1982 Jay Lepreau for Dec-20 Version
 */

/*	Dec-20 version 0.2	2/81	J.Lepreau	*/

/* note there must be one & only one blank line between templates */
/* so that 'numtab.c' works properly...				  */

# include "mfile2"

# define AWD	SNAME|SOREG|SCON|STARNM|SAREG	/* addressable word	*/
# define LWD	SNAME|SOREG|SCON|SAREG		/* directly addr word	*/
# define SMEM	SNAME|SOREG|SCON|STARNM		/* in memory		*/

# define TWD	TINT|TFLOAT|TPOINT|TDOUBLE|TCHAR   /*tmp type 'word' (tptrto deleted) */
# define TNORM	TINT|TFLOAT|TPOINT|TDOUBLE	/* 'normal' word types	*/

struct optab  table[] = {

ASSIGN,	INAREG|FOREFF,				/* zero -> stg */
	AWD,	TWD,
	SZERO,	TANY,
		0,	RRIGHT,
		"	setzm	AL\n",

ASSIGN,	INAREG|FOREFF,				/* reg -> stg */
	SMEM,	TWD,
	SAREG,	TWD,
		0,	RRIGHT,
		"	movem	AR,AL\n",

ASSIGN,	INAREG|FOREFF,				/* con/stg -> reg */
	SAREG,	TWD,
	AWD,	TWD,			/* SACON won't match floats (i hope) */
		0,	RLEFT,
		"	moveIR	AL,VR\n",

ASSIGN,	INAREG|FOREFF,				/* Reg -> field */
	SFLD,	TANY,
	SAREG,	TINT|TPOINT|TCHAR,
		0,	RRIGHT,
		"	dpb	AR,[point S,AL,H]\n",

/* put this here so unary mul will match opltype when it should */
UNARY MUL,	INTAREG|INAREG,	
	SANY,	TANY,
	SANY,	TULONG,				/* no such type on 20 */
		0,	RNOP,
		"dummy entry-- will never match",

OPLTYPE,	FOREFF,				/* foreff on leaf = zilch */
	SANY,	TANY,
	LWD,	TANY,
		0,	RRIGHT,			/* not RNULL?? */
		"",	/* this entry throws away computations which don't do anything */

OPLTYPE,	INTAREG|INAREG,
	SANY,	TANY,
	SNCON,	TWD,			/* negative constant > -2**18 */
		NAREG|NASR,	RESC1,
		"	movni	A1,-CR\n",

OPLTYPE,	INTAREG|INAREG,				/* con/word -> reg */
	SANY,	TANY,
	AWD,	TWD,		/* maybe should be AWD vs SANY? (FLD) */
		NAREG|NASR,	RESC1,
		"	moveIR	A1,VR\n",

FLD,		INTAREG|INAREG,		/* Field -> register */
	AWD,	TANY,
	SANY,	TANY,
		NAREG|NASL,	RESC1,
		"	ldb	A1,[point S,AL,H]\n",

OPLTYPE,	FORCC,
	SANY,	TANY,
	SAREG,	TWD,
		0,	RESCC,
		"ZV",				/* remember cond code reg */

OPLTYPE,	FORCC,
	SANY,	TANY,
	SANY,	TWD,
		0,	RESCC,
		"Z0	move	$0,AR\n", /* use r0 cause why waste another? */

OPLTYPE,	INTEMP,				/* mem -> mem */
	SANY,	TANY,
	SMEM,	TWD,
		NTEMP,	RESC1,
		"	move	$0,AR\n	movem	$0,A1\n",	/* r0 */

OPLTYPE,	INTEMP,					/* reg -> mem */
	SANY,	TANY,
	SAREG,	TWD,
		NTEMP,	RESC1,
		"	movem	AR,A1\n",

OPLTYPE,	FORARG,				/* word -> stack */
	SANY,	TANY,
	SANY,	TWD,
		0,	RNULL,
		"	push	$p,ARZ+\n",	/* Z+ does bookeeping only */

OPLOG,	FORCC,
	SAREG,	TNORM,
	SZERO,	TANY,				/* look for constant 0 */
		0,	RESCC,
		"	jumpZC	AL,$L\n",	/* L = print p->label  */

OPLOG,	FORCC,
	SAREG,	TNORM,
	AWD,	TNORM|TCHAR,		/* tmp */
		0,	RESCC,
		"	caIRZR	AL,VR\n	jrst	$L\n",	/* ZR = negated cmp */

CCODES,	INTAREG|INAREG,
	SANY,	TANY,
	SANY,	TINT|TPOINT|TCHAR,
		NAREG,	RESC1,
		"	movei	A1,1\nZN",	/* ZN = emit branch */

UNARY MINUS,	INTAREG|INAREG,				/* -stg -> reg */
	AWD,	TINT|TFLOAT|TDOUBLE,
	SANY,	TANY,
		NAREG|NASL,	RESC1,
		"	movn	A1,AL\n",

COMPL,	INTAREG|INAREG,					/* ~stg -> reg */
	AWD,	TINT,
	SANY,	TANY,
		NAREG|NASL,	RESC1,
		"	setcm	A1,AL\n",

INCR,	INAREG|FOREFF,
	AWD,	TINT|TPOINT|TCHAR,	/* tmp -- is this defined on chars? */
	SONE,	TANY,
		NAREG,	RESC1,
		"F	move	A1,AL\n	aos	AL\n",

INCR,	INAREG|FOREFF,			/* really was DECR */
	AWD,	TINT|TPOINT|TCHAR,		/* tmp */
	SMONE,	TANY,
		NAREG,	RESC1,
		"F	move	A1,AL\n	sos	AL\n",

OPSIMP,	INTAREG|INAREG,
	STAREG,	TINT|TPOINT,
	AWD,	TINT|TPOINT|TCHAR,	/* tmp */
		0,	RLEFT,
		"	OXIR	AL,VR\n",

PLUS,	INTAREG|INAREG,		      /* for OREGS that aren't de-referenced */
	SAREG,	TPOINT,			/* really want SFP on left, perhaps? */
	SACON,	TINT,
		NAREG,	RESC1,
		"	movei	A1,CR(CL)\n",

MINUS,	INTAREG|INAREG,		/* perhaps should have these just as SCONS? */
	SAREG,	TPOINT,		/* then would handle negatives.		    */
	SACON,	TINT,
		NAREG,	RESC1,
		"	movei	A1,-CR(CL)\n",

DIV,	INTAREG|INAREG,
	SAREG,	TINT|TPOINT,
	STAREG,	TINT|TPOINT,
		0,	RRIGHT,
		"	idivm	AL,AR\n",		/* r = r/l */

MOD,	INTAREG|INAREG,			/* simulate so avoid reg pairs */
	STAREG,	TINT|TPOINT,		/* l - (l/r * r) */
	AWD,	TINT|TPOINT|TCHAR,	/* tmp */
		0,	RLEFT,					/* r0 */
		"\tmove	$0,AR\n	idivm	AL,$0\n	imul	$0,AR\n	sub\tAL,$0\n",

OPCOMM,	INTAREG|INAREG,
	AWD,	TINT|TPOINT|TCHAR,	/* tmp */
	STAREG,	TINT|TPOINT,
		0,	RRIGHT,
		"	OXIL	AR,VL\n",

ASG MOD,	INAREG|FOREFF,			/* only for reg. var */
	SAREG,	TINT|TPOINT,
	AWD,	TINT|TPOINT|TCHAR,	/* tmp */
		0,	RLEFT,				/* r0 */
		"\tmove	$0,AR\n	idivm	AL,$0\n	imul	$0,AR\n	sub\tAL,$0\n",

ASG PLUS,	INAREG|FOREFF,
	AWD,	TINT|TPOINT|TCHAR,	/* tmp */
	SONE,	TANY,
		0,	RLEFT,
		"	aos	AL\n",

ASG PLUS,	INAREG|FOREFF,	/* to catch var -= 1 after conversion*/
	AWD,	TINT|TPOINT|TCHAR,	/* tmp */
	SMONE,	TANY,
		0,	RLEFT,
		"	sos	AL\n",
/**** ASG MINUS,	INAREG|FOREFF,
	AWD,	TINT|TPOINT|TCHAR,	/* tmp */
/***	SONE,	TANY,
		0,	RLEFT,
		"	sos	AL\n",
Shouldn't need this *********/

ASG OPSIMP,	INAREG|FOREFF,
	SAREG,	TINT|TPOINT,
	AWD,	TINT|TPOINT|TCHAR,	/* tmp */
		0,	RLEFT,
		"	OXIR	AL,VR\n",

ASG OPCOMM,	INAREG,			/* -= cnvted to += in pass1 */
	AWD,	TINT|TPOINT|TCHAR,	/* tmp */
	STAREG,	TINT|TPOINT,
		0,	RRIGHT,
		"	OXb	AR,AL\n",

ASG OPCOMM,	INAREG|FOREFF,		/* -= cnvted to += in pass1 */
	AWD,	TINT|TPOINT|TCHAR,	/* tmp */
	SAREG,	TINT|TPOINT,
		0,	RLEFT,
		"	OXm	AR,AL\n",

OPFLOAT,	INAREG|INTAREG,
	STAREG,	TFLOAT|TDOUBLE,
	AWD,	TFLOAT|TDOUBLE,
		0,	RLEFT,
		"	OF	AL,AR\nT",  /* T means suppress cnvt to dble */

OPCOMM,		INAREG|INTAREG,
	AWD,	TFLOAT|TDOUBLE,
	STAREG,	TFLOAT|TDOUBLE,
		0,	RRIGHT,
		"	OF	AR,AL\nT",

ASG OPFLOAT,	INAREG|FOREFF,
	SAREG,	TFLOAT|TDOUBLE,
	AWD,	TFLOAT|TDOUBLE,
		0,	RLEFT,
		"	OF	AL,AR\nT",

ASG PLUS,	INAREG,				/* and INTAREG also? */
	AWD,	TFLOAT|TDOUBLE,
	STAREG,	TFLOAT|TDOUBLE,
		0,	RRIGHT,
		"	fadrb	AR,AL\nT",

ASG PLUS,	INAREG|FOREFF,			/* and INTAREG also? */
	AWD,	TFLOAT|TDOUBLE,
	SAREG,	TFLOAT|TDOUBLE,
		0,	RLEFT,
		"	fadrm	AR,AL\nT",

ASG MUL,	INAREG,				/* and INTAREG also? */
	AWD,	TFLOAT|TDOUBLE,
	STAREG,	TFLOAT|TDOUBLE,
		0,	RRIGHT,
		"	fmprb	AR,AL\nT",

ASG MUL,	INAREG|FOREFF,			/* and INTAREG also? */
	AWD,	TFLOAT|TDOUBLE,
	SAREG,	TFLOAT|TDOUBLE,
		0,	RLEFT,
		"	fmprm	AR,AL\nT",

ASG OPSHFT, 	INAREG,		/* RS cnvted to RS on negated val in pass1 */
	SAREG,	TINT|TPOINT,
	SCON,	TINT,	 		/*  constant */
		0,	RLEFT,
		"	lsh	AL,CR\nZE",  /* ZE is named cons error check */

ASG OPSHFT, 	INAREG,	      /* RS can't be indirect cause of indirect bit! */
	SAREG,	TINT|TPOINT,
	SAREG,	TINT,		/* for now, easier here than in setasop */
		0,	RLEFT,
		"	lsh	AL,(AR)\n",

ASG OPSHFT, 	INAREG,	      /* RS can't be indirect cause of indirect bit! */
	SAREG,	TINT|TPOINT,
	AWD,	TINT,		/* for now, easier here than in setasop */
		NAREG|NASR,	RLEFT,
		"	move	A1,AR\n	lsh	AL,(A1)\n",

UNARY CALL,	INTAREG,
	SCON,	TANY,
	SANY,	TWD|TCHAR,				/* not TANY? */
		NAREG|NASL,	RESC1,		/* should be register 1 */
		"	pushj	$p,CL\n",

UNARY CALL,	INTAREG,
	AWD,	TANY,
	SANY,	TWD|TCHAR,			/* not TANY? */
		NAREG|NASL,	RESC1,		/* should be register 1 */
		"	pushj	$p,@AL\n",

PACONV,	INAREG|INTAREG,
	STAREG,	TINT|TPOINT,
	AWD,	TINT|TPOINT,		/* types right? */
		0,	RLEFT,
		"	addIR	AL,VR\n",

PACONV,	INAREG|INTAREG,
	AWD,	TINT|TPOINT,
	STAREG,	TINT|TPOINT,
		0,	RRIGHT,
		"	addIL	AR,VL\n",

PSCONV,	INAREG|INTAREG,
	STAREG,	TINT|TPOINT,
	AWD,	TINT|TPOINT,		/* types right? */
		0,	RLEFT,
		"	subIR	AL,VR\n",

PCONV,	INAREG|INTAREG,		/* tmp */
	SANY,	TWD,
	SANY,	TWD,
		0,	RLEFT,		/* lhs is single descendant */
		"",		/* throw this away-- nop */

SCONV,	INTAREG,				/* int -> float */
	AWD,	TINT|TPOINT|TCHAR,	/* tmp */
	SANY,	TFLOAT|TDOUBLE,
		NAREG|NASL,	RESC1,
		"	fltr	A1,AL\nT",

SCONV,	INTAREG,				/* float -> int */
	AWD,	TFLOAT|TDOUBLE,
	SANY,	TINT|TPOINT|TCHAR,	/* tmp */
		NAREG|NASL,	RESC1,
		"	fix	A1,AL\nT",

STARG,	FORARG,
	AWD,	TANY,
	SANY,			TANY,
		0,	RNULL,			/* ZS = stack accounting */
		"ZS	hrl	$0,AL\n\thrri\t$0,1($p)\n\tblt	$0,ZW($p)\n	adjsp	$p,ZW\n",

STASG,	FOREFF,
	LWD,	TANY,
	AWD,	TANY,
		0,	RNULL,
		"	hrl	$0,AR\n	hrri	$0,AL\n	blt	$0,ZW-1+AL\n",

STASG,	FOREFF,			/* Temp. kludge!! */
	AWD,	TANY,
	AWD,	TANY,
		NAREG|NASL,	RNULL,
		"\thrl\t$0,AR\n\tmovei\tA1,AL\n\thrr\t$0,A1\n\tblt\t$0,ZW-1(A1)\n",

INIT,	FOREFF,
	SCON,	TANY,
	SANY,	TINT|TPOINT|TCHAR,	/* tmp */
		0,	RNOP,
		"	CL\n",

	/* Default actions for hard trees ... */
# define DF(x) FORREW,SANY,TANY,SANY,TANY,REWRITE,x,""
UNARY MUL, DF( UNARY MUL ),

INCR, DF(INCR),
/**** DECR, DF(INCR), ****/

ASSIGN, DF(ASSIGN),

STASG, DF(STASG),

OPLEAF, DF(NAME),

OPLOG,	FORCC,
	SANY,	TANY,
	SANY,	TANY,
		REWRITE,	BITYPE,
		"",

OPLOG,	DF(NOT),

COMOP, DF(COMOP),

INIT, DF(INIT),

OPUNARY, DF(UNARY MINUS),

ASG OPANY, DF(ASG PLUS),

OPANY, DF(BITYPE),

FREE,	FREE,	FREE,	FREE,	FREE,	FREE,	FREE,	FREE,	"help; I'm in trouble\n" };
