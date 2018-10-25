/* This is monsym.h, edited from <bcpl>monsym.bcp by J.Lepreau 2/81 (whew) */

#ifdef CROSSCOMP
static int _shl18 = 18;	/* for cross-compiling so pcc won't fold; make it a */
			/* define later.				    */
#else
#define _shl18 18	/* Cause not cross-compiling */

#endif

	/* JSYS SPECIFIC ARGUMENTS */
	/* THE FOLLOWING ARE ORDERED ALPHABETICALLY BY JSYS NAME */

	/* CFORK */

#define CR_map  (0400000<<_shl18)	/* SET MAP FOR NEW FORK TO POINT TO */
					/*  THIS PROCESS */
#define CR_cap  (0200000<<_shl18)	/* MAKE CAPABILITIES IDENTICAL */
#define CR_acs  (0040000<<_shl18)	/* SET ACS FROM BLOCK */
#define CR_st   (0020000<<_shl18)	/* START PROCESS AT PC */
#define CR_pcv  0777777		/* VALUE OF PC */


	/* RPACS/SPACS BIT DEFINITIONS */

#define PA_rd  (0100000<<_shl18)	/* READ ACCESS ALLOWED */
#define PA_wt  (0040000<<_shl18)	/* WRITE ACCESS ALLOWED */
#define PA_wr  (0040000<<_shl18)	/*  (ANOTHER NAME FOR ABOVE) */
#define PA_ex  (0020000<<_shl18)	/* EXECUTE ACCESS ALLOWED */
  	/*  (RESERVED FOR THE FUTURE) */

#define PA_pex  (0010000<<_shl18)	/* PAGE EXISTS */
#define PA_ind  (0004000<<_shl18)	/* INDIRECT POINTER */
#define PA_tpu  (0001000<<_shl18)	/* TRAP TO USER */
  	/*  (NOT IMPLEMENTED -- OBSOLETE) */
#define PA_cpy  (0000400<<_shl18)	/* COPY ON WRITE */
#define PA_prv  (0000200<<_shl18)	/* PRIVATE */
#define P1_rd  (0000000<<_shl18 | 0100000)	/* READ ACCESS ALLOWED IN 1ST POINTER */
#define P1_wr  (0000000<<_shl18 | 040000)	/* WRITE ACCESS ALLOWED IN 1ST POINTER */
#define P1_wt  (0000000<<_shl18 | 040000)	/*  (ANOTHER NAME FOR ABOVE) */
#define P1_ex  (0000000<<_shl18 | 040000)	/* EXECUTE ACCESS ALLOWED IN 1ST POINTER */
  	/*  (RESERVED FOR THE FUTURE) */
#define P1pex  0010000	/* PAGE EXISTS IN 1ST POINTER */
#define P1cpy  0000400	/* COPY-ON-WRITE IN 1ST POINTER */


	/* *********************************************** */
	/* GENERAL FIELD AND VALUE DEFINITIONS */
	/* USED BY MANY JSYSES */
	/* *********************************************** */


	/* GENERAL FORK HANDLES */

#define FHslf  0400000	/* SELF */
#define FHsup  0777777	/* SUPERIOR */
#define FHtop  0777776	/* TOP IN JOB */
#define FHsai  0777775	/* SELF AND INFERIORS */
#define FHinf  0777774	/* INFERIORS */
#define FHjob  0777773	/* ALL IN JOB */


	/* GFRKS */

#define GF_gfh  (0400000<<_shl18)	/* GET RELATIVE FORK HANDLES */
#define GF_gfs  (0200000<<_shl18)	/* GET FORK STATUS */


	/* RFSTS */

#define RF_lng  (0400000<<_shl18)	/* LONG FORM OF RFSTS CALL, ARG BLOCK IN 2 */
#define RFprh  0777777 /* PROCESS HANDLE */

	/* RFSTS ARG BLOCK */

#define RFcnt  00	/* XWD COUNT OF WORDS RETURNED, */
  	/*  MAXIMUM WORDS TO RETURN */
#define RFpsw  01	/* PROCESS STATUS WORD */
#define RFpfl  02	/* PROCESS' PC FLAGS */
#define RFppc  03	/* PROCESS' PC */

#define RFsfl  04	/* STATUS FLAGS FOR PROCESS  */
#define RF_exo  (0400000<<_shl18)	/* PROCESS IS EXECUTE-ONLY */

	/* PROCESS STATUS WORD */

#define RF_frz  (0400000<<_shl18)	/* PROCESS IS FROZEN */
#define RF_sts  (0377777<<_shl18) /* PROCESS STATUS CODE */
#define RFrun  00	/* RUNNABLE */
#define RFio  01	/* DISMISSED FOR I/O */
#define RFhlt  02	/* HALTED */
#define RFfpt  03	/* FORCED PROCESS TERMINATION */
#define RFwat  04	/* WAITING FOR INFERIOR PROCESS */
#define RFslp  05	/* SLEEP */
#define RFtrp  06	/* JSYS TRAPPED */
#define RFabk  07	/* ADDRESS BREAK FREEZE */
#define RFsic  0777777 /* SOFTWARE INTERRUPT CHANNNEL */
