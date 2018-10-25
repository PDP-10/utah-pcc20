/* This is monsym.h, edited from <bcpl>monsym.bcp by J.Lepreau 2/81 (whew) */

#ifdef CROSSCOMP
static int _shl18 = 18;	/* for cross-compiling so pcc won't fold; make it a */
			/* define later.				    */
#else
#define _shl18 18	/* Cause not cross-compiling */

#endif

	/* JSYS SPECIFIC ARGUMENTS */
	/* THE FOLLOWING ARE ORDERED ALPHABETICALLY BY JSYS NAME */

	/* CRLNM */

#define CLnj1  00	/* DELETE 1 LOGICAL NAME FROM JOB */
#define CLns1  01	/* DELETE 1 LOGICAL NAME FROM SYSTEM */
#define CLnja  02	/* DELETE ALL JOB WIDE LOGICAL NAMES */
#define CLnsa  03	/* DELETE ALL SYSTEM LOGICAL NAMES */
#define CLnjb  04	/* CREATE A JOB WIDE LOGICAL NAME */
#define CLnsy  05	/* CREATE A SYSTEM WIDE LOGICAL NAME */


	/* INLNM */

#define INljb  00	/* GET JOB WIDE LOGICAL NAME FROM INDEX */
#define INlsy  01	/* GET SYSTEM LOGICAL NAME FROM INDEX */


	/* LNMST */

#define LNsjb  00	/* GET JOB WIDE DEFINITION OF A LN */
#define LNssy  01	/* GET SYSTEM DEFINITION OF A LOGICAL NAME */

	/* ERRORS */

#define ERb 0600000		/* "Error base" */

#define ERcrlnx1 (ERb|01000) /* Logical name is not defined */
#define ERinlnx1 (ERb|01001) /* Index is beyond end of logical name table */
#define ERlnstx1 (ERb|01002) /* No such logical name */
#define ERcrlnx2 (ERb|01134) /* WHEEL or OPERATOR capability required */
#define ERinlnx2 (ERb|01135) /* Invalid function */
#define ERlnstx2 (ERb|01136) /* Invalid function */
#define ERcrlnx3 (ERb|01152) /* Invalid function */
