/* rcusr and rcdir */

/* flags supplied on call */

#define RC_par 01:35-14		/* partial recognition is allowed */
#define RC_stp 01:35-15		/* step wildcard (rcdir only) */
#define RC_awl 01:35-16		/* allow wildcards (rcdir only) */
#define RC_emo 01:35-17		/* exact match only */

/* flags returned */

#define RC_dir 01:35-0		/* files-only directory */
#define RC_ana 01:35-1		/* alphanumeric accounts allowed */
#define RC_rlm 01:35-2		/* repeat login message */
#define RC_nom 01:35-3		/* no match found */
#define RC_amb 01:35-4		/* ambiguous */
#define RC_nmd 01:35-5		/* no more dirs - returned if stp is requested */
#define RC_wld 01:35-6		/* wildcard dir was input */



/* rcvok */

#define RCfcj 00		/* function code,, job number */
#define RCuno 01		/* user number */
#define RCcdr 02		/* connected directory */
#define RCrqn 03		/* request number */
#define RCnua 04		/* number of user args */
#define RCara 05		/* pointer to user args */
#define RCcap 06		/* current capabilities */
#define RCter 07		/* terminal number */
#define RCrjb 010		/* requested job */

/* rdtty and texti */

#define RD_brk 01:35-0		/* break on regular break set */
#define RD_top 01:35-1		/* break on tops10 break set */
#define RD_pun 01:35-2		/* break on punctuation */
#define RD_bel 01:35-3		/* break on end of line */
#define RD_crf 01:35-4		/* suppress cr (returns lf only) */
#define RD_rnd 01:35-5		/* return if nothing to delete */
#define RD_jfn 01:35-6		/* jfns given for source */
#define RD_rie 01:35-7		/* return on input (buffer) empty */
#define RD_bbg 01:35-8		/* beginning of (dest) buffer given */
#define RD_beg 01:35-9		/* return immediately when typist edits to .rdbkl */
#define RD_rai 01:35-10		/* raise lowercase input */
#define RD_sui 01:35-11		/* suppress ^u indication */
#define RD_btm 01:35-12		/* break character terminated input */
#define RD_bfe 01:35-13		/* returned because buffer empty */
#define RD_blr 01:35-14		/* backup limit reached */

/* texti arg block */

#define RDcwb 00		/* count of words in block */
#define RDflg 01		/* flags */
#define RDioj 02		/* io jfns */
#define RDdbp 03		/* dest byte pointer */
#define RDdbc 04		/* dest byte count */
#define RDbfp 05		/* top of buffer pointer */
#define RDrty 06		/* retype (^r) pointer */
#define RDbrk 07		/* break set mask pointer */
#define RDbkl 010		/* backup limit pointer */



/* rfsts */

#define RF_lng 01:35-0		/* long form of rfsts call, arg block in 2 */
#define RF_prh 0777777:35-35	/* process handle */

/* rfsts arg block */

#define RFcnt 00		/* xwd count of words returned, */
				/* maximum words to return */
#define RFpsw 01		/* process status word */
#define RFpfl 02		/* process' pc flags */
#define RFppc 03		/* process' pc */
#define RFsfl 04		/* status flags for process: */
#define RF_exo 01:35-0		/* process is execute-only */

/* process status word */

#define RF_frz 01:35-0		/* process is frozen */
#define RF_sts 0377777:35-17	/* process status code */
#define RFrun 00		/* runnable */
#define RFio 01	 		/* dismissed for i/o */
#define RFhlt 02		/* halted */
#define RFfpt 03		/* forced process termination */
#define RFwat 04		/* waiting for inferior process */
#define RFslp 05		/* sleep */
#define RFtrp 06		/* jsys trapped */
#define RFabk 07		/* address break freeze */
#define RF_sic 0777777:35-35	/* software interrupt channnel */


/* rftad/sftad */

#define RSwrt 00		/* write date word */
#define RScrv 01		/* creation date word */
#define RSref 02		/* reference date word */
#define RScre 03		/* internal system write date word */
#define RStdt 04		/* tape write date word */
#define RSnet 05		/* online expiration date/interval word */
#define RSfet 06		/* offline expiration date/interval word */


/* rmap */

#define RM_rd 01:35-2		/* read access allowed */
#define RM_wr 01:35-3		/* write access allowed */
#define RM_ex 01:35-4		/* execute access allowed */
#define RM_pex 01:35-5		/* page exists */
#define RM_cpy 01:35-9		/* copy on write */


/* rpacs/spacs bit definitions */

#define PA_rd 01:35-2		/* read access allowed */
#define PA_wt 01:35-3		/* write access allowed */
#define PA_wr 01:35-3		/* (another name for above) */
#define PA_ex 01:35-4		/* execute access allowed */
				/* (reserved for the future) */
#define PA_pex 01:35-5		/* page exists */
#define PA_ind 01:35-6		/* indirect pointer */
#define PA_tpu 01:35-8		/* trap to user */
				/* (not implemented -- obsolete) */
#define PA_cpy 01:35-9		/* copy on write */
#define PA_prv 01:35-10		/* private */
#define P1_rd 01:35-20		/* read access allowed in 1st pointer */
#define P1_wr 01:35-21		/* write access allowed in 1st pointer */
#define P1_wt 01:35-21		/* (another name for above) */
#define P1_ex 01:35-22		/* execute access allowed in 1st pointer */
				/* (reserved for the future) */
#define P1_pex 01:35-23		/* page exists in 1st pointer */
#define P1_cpy 01:35-27		/* copy-on-write in 1st pointer */



/* rscan */

#define RSini 00		/* make rescan buffer available for input */
#define RScnt 01		/* count characters left to read from rescan buffer */


/* rtiw */

#define RT_dim 01:35-0		/* deferred terminal interrupt mask given */
#define RT_prh 0777777		/* process handle */
