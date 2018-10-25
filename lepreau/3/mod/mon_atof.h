/* This is monsym.h, edited from <bcpl>monsym.bcp by J.Lepreau 2/81 (whew) */

/********* deleted for host 20 *******
static int _shl18 = 18;	/* for cross-compiling so pcc won't fold; make it a */
			/* define later.				    */

#define _shl18 18	/* cause not cross-compiling */

	/* JSYS SPECIFIC ARGUMENTS */
	/* THE FOLLOWING ARE ORDERED ALPHABETICALLY BY JSYS NAME */

	/* FLOUT/DFOUT */
	/* FORMAT CONTROL WORD */

#define FL_sgn  (0600000<<_shl18)	/* FIRST FIELD SIGN CONTROL */
#define FLdig  00	/* DIGIT */
#define FLspc  01	/* SPACE */
#define FLpls  02	/* PLUS SIGN */
#define FLspa  03	/* SPACE */
#define FL_jus  (0140000<<_shl18)	/* FIRST FIELD JUSTIFICATION CONTROL */
#define FLlsp  00	/* LEADING SPACES */
#define FLlzr  01	/* LEADING ZEROS */
#define FLlas  02	/* LEADING ASTERISKS */
#define FLtsp  03	/* TRAILING SPACES */
#define FL_one  (0020000<<_shl18)	/* FIRST FIELD NONBLANK */
#define FL_dol  (0010000<<_shl18)	/* DOLLAR SIGN PREFIX */
#define FL_pnt  (0004000<<_shl18)	/* DECIMAL POINT */
#define FL_exp  (0003000<<_shl18)	/* THIRD FIELD EXPONENT CONTROL */
#define FLexn  00	/* NO EXPONENT */
#define FLexe  01	/* E EXPONENT PREFIX */
#define FLexd  02	/* D EXPONENT PREFIX */
#define FLexm  03	/* *10^ EXPONENT PREFIX */
#define FL_esg  (0000600<<_shl18)	/* EXPONENT SIGN CONTROL */
#define FLdge  00	/* DIGIT */
#define FLple  01	/* PLUS SIGN */
#define FLspe  02	/* SPACE */
#define FLdgt  03	/* DIGIT */
#define FL_ovl  (0000100<<_shl18)	/* COLUMN OVERFLOW */
#define FL_rnd  (0000037<<_shl18)	/* DIGIT POSITION FOR ROUNDING */
#define FLfst  0770000	/* FIRST FIELD WIDTH */
#define FLsnd  0007700	/* SECOND FIELD WIDTH */
#define FLthd  0000077	/* THIRD FIELD WIDTH */
