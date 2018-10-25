/* This is monsym.h, edited from <bcpl>monsym.bcp by J.Lepreau 2/81 (whew) */

/********* deleted for host 20 *******
static int _shl18 = 18;	/* for cross-compiling so pcc won't fold; make it a */
			/* define later.				    */

#define _shl18 18	/* cause not cross-compiling */

	/* JSYS SPECIFIC ARGUMENTS */
	/* THE FOLLOWING ARE ORDERED ALPHABETICALLY BY JSYS NAME */


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


	/* FIELDS OF JFN MODE WORD */

#define TT_osp  (0400000<<_shl18)	/* OUTPUT SUPPRESS */
#define TT_mff  (0200000<<_shl18)	/* MECHANICAL FORMFEED PRESENT */
#define TT_tab  (0100000<<_shl18)	/* MECHANICAL TAB PRESENT */
#define TT_lca  (0040000<<_shl18)	/* LOWER CASE CAPABILITIES PRESENT */
#define TT_len  (0037600<<_shl18)	/* PAGE LENGTH */
#define TT_wid  (0000177<<_shl18)	/* PAGE WIDTH */
#define TTwak  0170000	/* WAKEUP FIELD */
#define TTwk0  0400000	/* WAKEUP CLASS 0 (UNUSED) */
#define TTign  0200000	/* IGNORE ttWAK ON SFMOD */
#define TTwkf  0100000	/* WAKEUP ON FORMATING CONTROL CHARS */
#define TTwkn  0040000	/* WAKEUP ON NON-FORMATTING CONTROLS */
#define TTwkp  0020000	/* WAKEUP ON PUNCTUATION */
#define TTwka  0010000	/* WAKEUP ON ALPHANUMERICS */
#define TTeco  0004000	/* ECHOS ON */
#define TTecm  0002000	/* ECHO MODE */
#define TTalk  0001000	/* ALLOW LINKS */
#define TTaad  0000400	/* ALLOW ADVICE (NOT IMPLEMENTED) */
#define TTdam  0000300	/* DATA MODE */
#define TTbin  00	/* BINARY */
#define TTasc  01	/* ASCII */
#define TTato  02	/* ASCII AND TRANSLATE OUTPUT ONLY */
#define TTate  03	/* ASCII AND TRANSLATE ECHOS ONLY */
#define TTuoc  0000040	/* UPPER CASE OUTPUT CONTROL */
#define TTlic  0000020	/* LOWER CASE INPUT CONTROL */
#define TTdum  0000014	/* DUPLEX MODE */
#define TTfdx  00	/* FULL DUPLEX */
#define TT0dx  01	/* NOT USED, RESERVED */
#define TThdx  02	/* HALF DUPLEX (CHARACTER) */
#define TTldx  03	/* LINE HALF DUPLEX */
#define TTpgm  0000002	/* PAGE MODE */
#define TTcar  0000001	/* CARRIER STATE */




  /* DIRECTORY PROTECTION DEFINITIONS (3 6-BIT FIELDS = OWNER, GROUP, WORLD) */

#define DP_rd  040	/* READING DIRECTORY IS ALLOWED */
#define DP_cn  010	/* CONNECT TO DIR, OR CHANGE PROT/ACCOUNT */
#define DP_cf  04	/* CREATING FILES IN DIR IS ALLOWED */

  /* FILE PROTECTION DEFINITIONS (3 6-BIT FIELDS = OWNER, GROUP, WORLD) */

#define FP_dir  02	/* DIRECTORY LISTING */
#define FP_app  04	/* APPEND */
#define FP_ex  010	/* EXECUTE */
#define FP_wr  020	/* WRITE */
#define FP_rd  040	/* READ */


	/* INPUT AND OUTPUT IDENTIFIERS */

#define PRiin  0100	/* PRIMARY INPUT */
#define PRiou  0101	/* PRIMARY OUTPUT */
#define NUlio  0377777	/* NULL DESIGNATOR */
#define CTtrm  0777777	/* JOB'S CONTROLLING TERMINAL */
#define DVdes  0600000	/* UNIVERSAL DEVICE CODE */
#define TTdes  0400000	/* UNIVERSAL TERMINAL CODE */
