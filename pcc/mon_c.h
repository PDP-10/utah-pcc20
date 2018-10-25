/* cfork */

#define CR_map 01:35-0		/* set map for new fork to point to */
				/* this process */
#define CR_cap 01:35-1		/* make capabilities identical */
#define CR_acs 01:35-3		/* set acs from block */
#define CR_st 01:35-4		/* start process at pc */
#define CR_pcv 0777777:35-35	/* value of pc */


/* chfdb */

#define CF_nud 01:35-0		/* no update directory */
#define CF_dsp 0777:35-17	/* fdb displacement */
#define CF_jfn 0777777:35-35	/* jfn */


/* chkac jsys definitions */

/* chkac flag definitions */

#define CK_jfn 01:35-0		/* jfn is given as an argument */

/* chkac argument block offset values */

#define CKaac 00		/* access code */
#define CKald 01		/* logged in user number of user */
#define CKacd 02		/* connected dir number of user */
#define CKaec 03		/* enabled capabilities of user being chk'd */
#define CKaud 04		/* dir number of directory containing file */
#define CKapr 05		/* protection of file */

/* chkac access codes */

#define CKard 00		/* read an existing file */
#define CKawt 01		/* write an existing file */
#define CKawr 01		/* (another name for above) */
#define CKaex 02		/* execute an existing file */
#define CKaap 03		/* append to an existing file */
#define CKadl 04		/* get dir listing of an existing file */
#define CKadr 06		/* read the directory */
#define CKaof 07		/* open files in dir (not implemented) */
#define CKacn 010		/* connect to a dir */
#define CKacf 011		/* create files in dir */


/* closf */

#define CO_nrj 01:35-0		/* no release jfn */
#define CO_wcl 01:35-1		/* tops20an	;wait until matching cls is received */
#define CO_jfn 0777777:35-35	/* jfn */


/* clzff */

#define CZ_nif 01:35-0		/* no inferior fork files */
#define CZ_nsf 01:35-1		/* no self fork files */
#define CZ_nrj 01:35-2		/* no release jfn */
#define CZ_ncl 01:35-3		/* no close file */
#define CZ_unr 01:35-4		/* unrestrict */
#define CZ_arj 01:35-5		/* always release jfn */
#define CZ_abt 01:35-6		/* abort */
#define CZ_nud 01:35-7		/* no update directory */
#define CZ_prh 0777777:35-35	/* process handle */


/* cndir */

#define CN_ckp 01:35-0		/* check password only */
#define CN_noc 01:35-1		/* no connect */
#define CN_job 01:35-2		/* doing connect for another job */
#define CN_dir 0777777:35-35	/* directory number */


/* comnd */

/* comnd - command state block */

#define CMflg 00		/* user flags,,reparse dispatch address */
#define CMioj 01		/* injfn,,outjfn */
#define CMrty 02		/* ^r buffer pointer */
#define CMbfp 03		/* ptr to top of buffer */
#define CMptr 04		/* ptr to next input to be parsed */
#define CMcnt 05		/* count of space left in buffer after ptr */
#define CMinc 06		/* count of characters following ptr */
#define CMabp 07		/* atom buffer pointer */
#define CMabc 010		/* atom buffer size */
#define CMgjb 011		/* adr of gtjfn arg block */
#define CM_gjb 0777777	 	/* adr of gtjfn arg block */

/* comnd - function descriptor block */

#define CMfnp 00		/* function and pointer */
#define CM_fnc 0777:35-8	/* function code */
#define CM_ffl 0777:35-17	/* function-specific flags */
#define CM_lst 0777777	 	/* list pointer to other blocks */
#define CMdat 01		/* data for function */
#define CMhlp 02		/* help text pointer */
#define CMdef 03		/* default string pointer */
#define CMbrk 04		/* field break mask pointer */

/* comnd - flags in .cmflg */

#define CM_esc 01:35-0		/* esc seen */
#define CM_nop 01:35-1		/* no parse */
#define CM_eoc 01:35-2		/* end of command seen */
#define CM_rpt 01:35-3		/* repeat parse needed */
#define CM_swt 01:35-4		/* switch terminated with ":" */
#define CM_pfe 01:35-5		/* previous field ended with esc */
#define CM_rai 01:35-6		/* raise input */
#define CM_xif 01:35-7		/* exclude indirect files */
#define CM_wkf 01:35-8		/* wakeup after each field */

/* function block flags (in word .cmfnp) */

#define CM_brk 01:35-13		/* break mask present */
#define CM_po 01:35-14		/* parse-only */
#define CM_hpp 01:35-15		/* help pointer present */
#define CM_dpp 01:35-16		/* default pointer present */
#define CM_sdh 01:35-17		/* suppress default help message */

/* flags for cmdir function */

#define CM_dwc 01:35-0		/* directory wild carding allowed */

/* flags for cmtad function */

#define CM_ida 01:35-0		/* input date */
#define CM_itm 01:35-1		/* input time */
#define CM_nci 01:35-2		/* no convert to internal */

/* flags in keyword table (first word of string if b0-6 = 0) */

#define CM_inv 01:35-35		/* invisible */
#define CM_nor 01:35-34		/* no-recognize (placeholder) */
#define CM_abr 01:35-33		/* abbreviation for another entry */
#define CM_fw 01:35-7		/* flag word (must always be on) */


/* comnd - function codes */

#define CMkey 00		/* keyword */
#define CMnum 01		/* number */
#define CMnoi 02		/* noise word */
#define CMswi 03		/* switch */
#define CMifi 04		/* input file */
#define CMofi 05		/* output file */
#define CMfil 06		/* general filespec */
#define CMfld 07		/* arbitrary field */
#define CMcfm 010		/* confirm */
#define CMdir 011		/* directory name */
#define CMusr 012		/* user name */
#define CMcma 013		/* comma */
#define CMini 014		/* init line */
#define CMflt 015		/* floating point number */
#define CMdev 016		/* device name */
#define CMtxt 017		/* text to action char */
#define CMtad 020		/* time and date */
#define CMqst 021		/* quoted string */
#define CMuqs 022		/* unquoted string */
#define CMtok 023		/* token */
#define CMnux 024		/* number delimited by non-digit */
#define CMact 025		/* account */
#define CMnod 026		/* node name */


/* crdir */

#define CD_len 01:35-0		/* flags ,, length of crdir block */
#define CD_psw 01:35-1		/* set password string */
#define CD_liq 01:35-2		/* set logged in quota */
#define CD_prv 01:35-3		/* set privileges */
#define CD_mod 01:35-4		/* set mode bits */
#define CD_loq 01:35-5		/* set logged out quota */
#define CD_num 01:35-6		/* set directory number from param blk */
#define CD_fpt 01:35-7		/* set default file protection */
#define CD_dpt 01:35-8		/* set directory protection */
#define CD_ret 01:35-9		/* set default retention count */
#define CD_lld 01:35-10		/* set last login date */
#define CD_ugp 01:35-11		/* set user groups */
#define CD_dgp 01:35-12		/* set directory groups */
#define CD_sdq 01:35-13		/* set subdirectory quota */
#define CD_cug 01:35-14		/* set creatable user groups */
#define CD_dac 01:35-15		/* set default account */
#define CD_del 01:35-17		/* delete directory */
#define CD_apb 0777777:35-35	/* address of parameter block */
#define CDlen 00		/* length of argument block */
#define CD_nsq 01:35-0		/* do not update quotas of superior dir */
#define CD_nce 01:35-1		/* do not change parameters of existing dirs */
#define CD_ned 01:35-2		/* set def online exp from .cddne */
#define CD_fed 01:35-3		/* set def offline exp from .cddfe */
#define CDpsw 01		/* pointer to password string  */
#define CDliq 02		/* logged in quota */
#define CDprv 03		/* privilege word */
#define CDmod 04		/* mode word */
#define CD_dir 01:35-0		/* directory name for cndir only (files only) */
#define CD_ana 01:35-1		/* alphanumeric accounts */
#define CD_rlm 01:35-2		/* repeat login messages */
#define CD_dar 01:35-7		/* archived online expired files */
#define CDloq 05		/* logged out quota */
#define CDnum 06		/* directory number */
#define CDfpt 07		/* default file protection */
#define CDdpt 010		/* directory protection */
#define CDret 011		/* default retention count */
#define CDlld 012		/* last login date */
#define CDugp 013		/* user groups */
#define CDdgp 014		/* directory groups */
#define CDsdq 015		/* maximum number of subdirectories */
#define CDcug 016		/* pointer to creatable user group list */
#define CDdac 017		/* pointer to default account */
#define CDdne 020		/* default online expiration */
#define CDdfe 021		/* default offline expiration */


/* crjob */

#define CJ_log 01:35-0		/* attempt to log in the new job */
#define CJ_nam 01:35-1		/* use name and pswd in arg blk */
#define CJ_act 03:35-3		/* where to get account */
#define CJuca 00	 	/* use current acct of creator */
#define CJuaa 01	 	/* use account in arg block */
#define CJuda 02	 	/* use default account of new user */
#define CJ_etf 01:35-4		/* put exec in top fork */
#define CJ_fil 01:35-5		/* get file in arg block */
#define CJ_acs 01:35-6		/* load the acs from arg block */
#define CJ_own 01:35-7		/* retain ownership of new job */
#define CJ_wta 01:35-8		/* new job waits til attached */
#define CJ_npw 01:35-9		/* no password check at login time */
#define CJ_nud 01:35-10		/* no update of last-login date */
#define CJ_spj 01:35-11		/* do spjfn in new job from arg blk */
#define CJ_cap 01:35-12		/* pass enabled capabilities as allowed */
#define CJ_cam 01:35-13		/* capability mask at login */
#define CJ_slo 01:35-14		/* signal (ipcf) at logout time */
#define CJ_dsn 01:35-17		/* disown existing job # in 3 */

#define CJnam 00		/* name string pointer */
#define CJpsw 01		/* password string pointer */
#define CJact 02		/* account designator/string */
#define CJfil 03		/* file name string pointer */
#define CJsfv 04		/* sfrkv offset */
#define CJtty 05		/* tty designator, or null designator */
#define CJtim 06		/* time limit */
#define CJacs 07		/* address of 16. words of ac's */
#define CJexf 010		/* exec flags, for exec ac1 */
#define CJpri 011		/* primary jfn's for spjfn in new job */
#define CJcpu 012		/* cpu limit (0 if none) */
#define CJcam 013		/* capability mask to apply to login */
#define CJslo 014		/* pid to signal at logout time */

#define CR_pra 02545		/* magic # for exec/crjob linkage via prarg */


/* crlnm */

#define CLnj1 00		/* delete 1 logical name from job */
#define CLns1 01		/* delete 1 logical name from system */
#define CLnja 02		/* delete all job wide logical names */
#define CLnsa 03		/* delete all system logical names */
#define CLnjb 04		/* create a job wide logical name */
#define CLnsy 05		/* create a system wide logical name */
