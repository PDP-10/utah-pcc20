/* This is monsym.h, edited from <bcpl>monsym.bcp by J.Lepreau 2/81 (whew) */

/********* deleted for host 20 *******
static int _shl18 = 18;	/* for cross-compiling so pcc won't fold; make it a */
			/* define later.				    */

#define _shl18 18	/* cause not cross-compiling */

	/* JSYS SPECIFIC ARGUMENTS */
	/* THE FOLLOWING ARE ORDERED ALPHABETICALLY BY JSYS NAME */


	/* INPUT AND OUTPUT IDENTIFIERS */

#define PRiin  0100	/* PRIMARY INPUT */
#define PRiou  0101	/* PRIMARY OUTPUT */
#define NUlio  0377777	/* NULL DESIGNATOR */
#define CTtrm  0777777	/* JOB'S CONTROLLING TERMINAL */
#define DVdes  0600000	/* UNIVERSAL DEVICE CODE */
#define TTdes  0400000	/* UNIVERSAL TERMINAL CODE */

	/* GTJFN DEFINITIONS */

	/* FLAGS PROVIDED TO GTJFN ON CALL */

#define GJ_fou  (0400000<<_shl18)	/* FILE IS FOR OUTPUT USE */
#define GJ_new  (0200000<<_shl18)	/* NEW FILE ONLY */
#define GJ_old  (0100000<<_shl18)	/* OLD FILE ONLY */
#define GJ_msg  (0040000<<_shl18)	/* PRINT AN APPROPRIATE MESSAGE */
#define GJ_cfm  (0020000<<_shl18)	/* CONFIRMATION IS REQUIRED */
#define GJ_tmp  (0010000<<_shl18)	/* TEMPORARY */
#define GJ_ns  (0004000<<_shl18)	/* DONT SEARCH SEARCH LISTS */
#define GJ_acc  (0002000<<_shl18)	/* NO ACCESS BY OTHER FORKS */
#define GJ_del  (0001000<<_shl18)	/* IGNORE "DELETED" BIT */
#define GJ_jfn  (0000600<<_shl18)	/* JFN USE FIELD */
#define GJdnu  00	/* DO NOT USE JFN PROVIDED */
#define GJerr  02	/* ERROR IF CANNOT USE JFN PROVIDED */
#define GJalt  03	/* USE ALTERNATE IF CANNOT USE GIVEN JFN */
#define GJ_ifg  (0000100<<_shl18)	/* ACCEPT INPUT FILE GROUP DESCRIPTORS */
#define GJ_ofg  (0000040<<_shl18)	/* ACCEPT OUTPUT FILE GROUP DESCRIPTORS */
#define GJ_flg  (0000020<<_shl18)	/* RETURN FLAGS */
#define GJ_phy  (0000010<<_shl18)	/* PHYSICAL DEVICE ONLY */
#define GJ_xtn  (0000004<<_shl18)	/* EXTENDED FORMAT (E+11 EXISTS) */
#define GJ_fns  (0000002<<_shl18)	/* ACCUMULATOR 2 CONTAINS JOB FILE NUMBERS */
#define GJ_sht  (0000001<<_shl18)	/* SHORT CALL FORMAT */

	/* FLAGS PROVIDED TO GTJFN (IN SECOND FLAG WORD) */

#define G1_rnd  (0400000<<_shl18)	/* RETURN ON NULL(IN ALTERNATE FLAG WORD) */
#define G1_rbf  (0200000<<_shl18)	/* ^R BUFFER IS DISJOINT (OBSOLETE) */
#define G1_nln  (0100000<<_shl18)	/* NO LONG NAMES */
#define G1_rcm  (0040000<<_shl18)	/* RETURN CONFIRM MESSAGE */
#define G1_rie  (0020000<<_shl18)	/* RETURN WHEN MAIN STRING IS EMPTY */




	/* FLAGS RETURNED BY GTJFN */

#define GJ_dev  (0400000<<_shl18)	/* ASTERISK WAS GIVEN FOR DEVICE */
#define GJ_unt  (0200000<<_shl18)	/* ASTERISK WAS GIVEN FOR UNIT */
#define GJ_dir  (0100000<<_shl18)	/* ASTERISK WAS GIVEN FOR DIRECTORY */
#define GJ_nam  (0040000<<_shl18)	/* ASTERISK WAS GIVEN FOR NAME */
#define GJ_ext  (0020000<<_shl18)	/* ASTERISK WAS GIVEN FOR EXTENSION */
#define GJ_ver  (0010000<<_shl18)	/* ASTERISK WAS GIVEN FOR GENERATION */
#define GJ_uhv  (0004000<<_shl18)	/* USE HIGHEST GENERATION */
#define GJ_nhv  (0002000<<_shl18)	/* USE NEXT HIGHER GENERATION */
#define GJ_ulv  (0001000<<_shl18)	/* USE LOWEST GENERATION */
#define GJ_pro  (0000400<<_shl18)	/* PROTECTION GIVEN */
#define GJ_act  (0000200<<_shl18)	/* ACCOUNT GIVEN */
#define GJ_tfs  (0000100<<_shl18)	/* TEMPORARY FILE SPECIFIED (// T) */
#define GJ_gnd  (0000040<<_shl18)	/* COMPLEMENT OF gjDEL ON CALL */

	/* GTJFN TABLE OFFSETS */

#define  GJgen  00	/* FLAGS ,,GENERATION */
#define  GJdef  00	/* DEFAULT GENERATION */
#define  GJnhg  0777777	/* NEXT HIGHER GENERATION */
#define GJleg  0777776	/* LOWEST EXISTING GENERATION */
#define GJall  0777775	/* ALL GENERATIONS (Ie., // *) */
#define GJsrc  01	/* SOURCE JFN ,,OUTPUT JFN */
#define GJdev  02	/* DEFAULT DEVICE */
#define GJdir  03	/* DEFAULT DIRECTORY */
#define GJnam  04	/* DEFAULT NAME */
#define GJext  05	/* DEFAULT EXTENSTION */
#define GJpro  06	/* DEFAULT PROTECTION */
#define GJact  07	/* DEFAULT ACCOUNT */
#define GJjfn  010	/* DESIRED JFN */
#define GJf2  011	/* SECOND GROUP FLAGS,,COUNT */
#define GJcpp  012	/* COPY BUFFER POINTER */
#define GJcpc  013	/* COPY BUFFER COUNT */
#define GJrty  014	/* RETYPE (^R) POINTER */
#define GJbfp  015	/* TOP OF BUFFER POINTER */
#define GJatr  016	/* POINTER TO ARBITRARY ATTRIBUTE BLOCK */

	/* GNJFN - FLAGS RETURNED */

#define GN_str  (0000020<<_shl18)	/* STRUCTURE CHANGED */
#define GN_dir  (0000010<<_shl18)	/* DIRECTORY CHANGED */
#define GN_nam  (0000004<<_shl18)	/* NAME CHANGED */
#define GN_ext  (0000002<<_shl18)	/* EXTENSION CHANGED */


	/* RSCAN */

#define RSini  00	/* MAKE RESCAN BUFFER AVAILABLE FOR INPUT */
#define RScnt  01	/* COUNT CHARACTERS LEFT TO READ FROM RESCAN BUFFER */
