/* <SUBSYS.PCC>MONSYM.H.8, 30-Mar-84 19:44:45, Edit by BEEBE */
/* Modified to replace % in names with _; CPP does not accept % in token */
/*
 * monsym.h - C version of monsym
 *
 * Based on DEC's monsym.mac
 * Author:	Jay Lepreau
 * 		Computer Science Dept.
 * 		University of Utah
 * Date:	23 October 1981
 * Copyright (c) 1981,1982 Jay Lepreau for C version
 */

/* Created from monsym.mac, 10/23/81  J.Lepreau, Univ of Utah 	*/
/* Improved 1/82 */

/* **		most recent edit history	***/
/* add .goatc for attach */
/* ps:<4.subsys-sources>monsym.mac.3  7-oct-80 20:22:30, edit by frank */
/* add smap jsys to monitor */
/* <4.utilities>monsym.mac.262,  3-jan-80 15:26:07, edit by r.ace */
/* update copyright date */
/* <4.utilities>monsym.mac.261, 24-oct-79 18:17:04, edit by murphy */
/* smapx1 */



/* ***************************************** */
/* jsys specific arguments */
/* the following are ordered alphabetically by jsys name */
/* ***************************************** */


/* acces - access a directory (e.g., by connecting) */

#define AC_con 01:35-0		/* connect to the specified directory */
#define AC_own 01:35-1		/* gain ownership */
#define AC_rem 01:35-2		/* remove ownership */

/* offsets in argument block */

#define ACdir 00		/* directory designator */
#define ACpsw 01		/* pointer to password string */
#define ACjob 02		/* job number (-1 for self) */


/* adbrk - address break jsys function codes and bits */

/* function codes */

#define ABset 00		/* set user address break */
#define ABred 01		/* read user address break */
#define ABclr 02		/* clear user address break */
#define ABgad 03		/* get address of trapped instruction */

/* function bits for function .abset */

#define AB_red 01:35-0		/* read */
#define AB_wrt 01:35-1		/* write */
#define AB_xct 01:35-2		/* execute */


/* alloc jsys function codes */

#define ALcal 00		/* allocate a device */


/* arcf */

#define ARrar 00		/* request file archive (user) */
#define ARclr 00	 	/* clear the request */
#define ARset 01	 	/* set the request */
/* ar_1ndl can be specified in ac2, defined elsewhere */
#define ARriv 01		/* request file migration (system) */
#define ARexm 02		/* file exempt from migration (system) */
#define ARrfr 03		/* request file's contents be restored to disk */
#define AR_nms 01:35-0		/* request no msg on restoration */
#define AR_wat 01:35-1		/* wait for file to be restored to disk */
#define ARdis 04		/* clear archive status for file */
#define AR_cr1 01:35-0		/* clear 1st run info */
#define AR_cr2 01:35-1		/* clear 2nd run info */
#define ARsst 05		/* set archive status for file */
#define ARofl 00		/* flags */
#define AR_o1 01:35-0		/* set run 1 info */
#define AR_o2 01:35-1		/* set run 2 info */
#define AR_ofl 01:35-2		/* flush contents of file */
#define AR_arc 01:35-3		/* set fb_arc (archive the file) */
#define AR_crq 01:35-4		/* clear archive/migration request */
#define ARtp1 01		/* tape 1 id */
#define ARsf1 02		/* xwd tsn 1, tfn 1 */
#define AR_tsn 0777777:35-17	/* tape saveset number */
#define AR_tfn 0777777:35-35	/* tape file number */
#define ARtp2 03		/* tape 2 id */
#define ARsf2 04		/* xwd tsn 2, tfn 2 */
/* ;;    ar_tsn==:0777777:35-17	; tape saveset number */
/* ;;    ar_tfn==:0777777:35-35	; tape file number */
#define ARodt 05		/* date and time */
#define ARpsz 06		/* number of pages in the file (.argst only) */
#define ARrst 06		/* restore contents to archived file */
#define ARgst 07		/* get tape info for file (blk as for arsst) */
#define ARrfl 010		/* retrieve failed */
#define ARnar 011		/* set/clear resist archive */

/* function & reason codes for ipcf msgs */

#define REtm 00	 		/* send retrieve message */
#define REtr 00	 		/* normal retrieve */
#define REtrw 01		/* user waiting for retrieve */
#define NOtm 01	 		/* send notification message */
#define FLxp 00	 		/* archive file expunged */
#define AClr 01	 		/* archive status cleared */

/* atnvt		      ;tops20an */

#define AN_ntp 01:35-2		/* tops20an	;new telnet protocol */


/* atach */

#define AT_ccj 01:35-0		/* ^c job when attached */
#define AT_nat 01:35-1		/* no attach */
#define AT_trm 01:35-2		/* attach job to terminal in register 4 */
#define AT_job 0777777:35-35	/* job number */



/* boot */

#define BTrom 00		/* activate rom boot */
#define BTdte 00	 	/* dte-20 number */
#define BTlds 01		/* load secondary bootstrap program */
#define BTerr 01	 	/* error flags */
#define BTsec 02	 	/* address of secondary bootstrap program */
#define BTlod 02		/* load memory (obsolete) */
#define BTsmp 02		/* send mop message */
#define BTflg 03	 	/* flags */
#define BT_bel 01:35-0		/* send to -11 doorbell after setup */
#define BTcnt 04	 	/* number of bytes to be transferred */
#define BTlpt 05	 	/* byte pointer to data to be loaded */
#define BTdmp 03		/* dump memory */
#define BTdpt 05	 	/* byte pointer to destination of dumped data */
#define BTipr 04		/* initialize communications protocol */
#define BTprv 01	 	/* protocol version number */
#define BTtpr 05		/* terminate communications protocol */
#define BTsts 06		/* return protocol status */
#define BTcod 01	 	/* status code */
#define BTbel 07		/* wait for doorbell */
#define BTrmp 010		/* read mop message */
#define BTmpt 05	 	/* pointer to destination for mop message */
#define BTkml 011		/* load kmc11 */
#define BTkmc 00	 	/* kmc11 address */
#define BTker 01	 	/* error flags */
#define BT_cve 01:35-0		/* cram verify error (rh is bad data) */
#define BT_dve 01:35-1		/* dram verify error (rh is bad data) */
#define BT_rve 01:35-2		/* reg verify error (rh is bad data) */
#define BTkcc 02	 	/* count of cram data */
#define BTkcp 03	 	/* pointer to cram data (16 bit data) */
#define BTkdc 04	 	/* count of dram data */
#define BTkdp 05	 	/* pointer to dram data (8 bit data) */
#define BTkrc 06	 	/* count of register data */
#define BTkrp 07	 	/* pointer to register data (16 bit data) */
#define BTksa 010	 	/* rh is starting address */
#define BT_ksa 01:35-0		/* is set rh want to start kmc11 */
#define BTkmd 012		/* dump kmc11 */
#define BTrlc 013		/* return line counters */
#define BTprt 00	 	/* port number */
#define BT_zro 01:35-0		/* clear counters after reading */
#define BTztm 01	 	/* time since counters have been zeroed */
#define BTscc 02	 	/* status count count */
#define BTscp 03	 	/* status count pointer */
#define BTrcc 04	 	/* receive count count */
#define BTrcp 05	 	/* receive count pointer */
#define BTtcc 06	 	/* transmit count count */
#define BTtcp 07	 	/* transmit count pointer */
#define BTcli 014		/* convert lineid to port number */
#define BTlid 01	 	/* pointer to asciz line-id */
#define BTcpn 015		/* convert port number to line-id */
#define BTsta 016		/* set station polling status */
#define BTssp 017		/* set line startup priority */
#define BTpri 01	 	/* priority value */
#define BTstp 020		/* set station polling priority */
#define BTsdd 021		/* send ddcmp message */
#define BTmsg 01	 	/* addr of message */
#define BTlen 02	 	/* byte count of message */
#define BTrdd 022		/* receive a message from ddcmp */
#define BTsup 01	 	/* station came up */
#define BTsdw 02	 	/* station went down */
#define BTcmp 03	 	/* xmit complete */
#define BTssf 04	 	/* startup failed */
#define BT_ctl 01:35-0		/* control message */
#define BTchn 023		/* assign a software interrupt channel */
#define BTesi 01	 	/* channel number */

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


/* deldf */

#define DD_dtf 01:35-0		/* delete temporary files */
#define DD_dnf 01:35-1		/* delete nonexistent files */
#define DD_rst 01:35-2		/* rebuild the symbol table */
#define DD_chk 01:35-3		/* check the dir for consistency only */


/* delf */

#define DF_nrj 01:35-0		/* don't release jfn */
#define DF_exp 01:35-1		/* expunge contents */
#define DF_fgt 01:35-2		/* forget (expunge w/o deassigning addresses) */
#define DF_dir 01:35-3		/* delete, forget, and expunge a directory */
				/* file.  (only if ^e-create kill failed) */
#define DF_arc 01:35-4		/* delete of archive status file allowed */
#define DF_cno 01:35-5		/* delete only contents of file */
				/* immediate expunge implied */

#define DF_jfn 0777777:35-35	/* jfn */


/* diag jsys definitions */

#define DG_adt 07:35-2		/* address type field */
#define DG_dvc 0177:35-9	/* device code field */
#define DGrh0 0130	 	/* mbc0 */
#define DGrh7 0137	 	/* mbc7 */
#define DG_uni 077:35-29	/* unit number */
#define DG_sun 077:35-35	/* subunit number */

/* diag jsys function codes   */

#define DGacu 01		/* assign device */
#define DGach 02		/* assign controller and all devices */
#define DGrch 03		/* release device(s) */
#define DGscp 04		/* setup channel program */
#define DGrcp 05		/* release channel program */
#define DGgcs 06		/* get channel status */

/* diag new control functions */

#define DGgem 0100		/* leave large hole for more rh20 functions */
				/* get mem (for tgha) */
#define DGrem 0101		/* release mem (for tgha) */
#define DGpdl 0102		/* unit online */


/* dskas */

#define DA_dea 01:35-0		/* deassign disk address */
#define DA_asf 01:35-1		/* assign free page */
#define DA_cnv 01:35-2		/* convert software to hardware address */
#define DA_hwa 01:35-3		/* hardware address given */
#define DA_ini 01:35-4		/* initialize the bit table */
#define DA_wrt 01:35-5		/* write the bit table file */
#define DA_adr 0777777:35-35	/* disk address */


/* dvchr, devunt and dvch1 bit definitions */

#define DV_out 01:35-0		/* device can do output */
#define DV_in 01:35-1		/* device can do input */
#define DV_dir 01:35-2		/* device has a directory */
#define DV_as 01:35-3		/* device is assignable */
#define DV_mdd 01:35-4		/* device is a multiple directory device */
#define DV_av 01:35-5		/* device is available to this job */
#define DV_asn 01:35-6		/* device is assigned by asnd */
#define DV_mdv 01:35-7		/* reserved (historical) */
#define DV_mnt 01:35-8		/* device is mounted */
#define DV_typ 0777:35-17	/* device type field */
#define DV_psd 01:35-18		/* pseudo device */
#define DV_unt 077777		/* unit mask */
#define DV_mod 0177777:35-35	/* device data mode */
#define DV_m0 01:35-35		/* device can be opened in mode 0 */
#define DV_m1 01:35-34		/* device can be opened in mode 1 */
#define DV_m2 01:35-33		/* device can be opened in mode 2 */
#define DV_m3 01:35-32		/* device can be opened in mode 3 */
#define DV_m4 01:35-31		/* device can be opened in mode 4 */
#define DV_m5 01:35-30		/* device can be opened in mode 5 */
#define DV_m6 01:35-29		/* device can be opened in mode 6 */
#define DV_m7 01:35-28		/* device can be opened in mode 7 */
#define DV_m10 01:35-27		/* device can be opened in mode 10 */
#define DV_m11 01:35-26		/* device can be opened in mode 11 */
#define DV_m12 01:35-25		/* device can be opened in mode 12 */
#define DV_m13 01:35-24		/* device can be opened in mode 13 */
#define DV_m14 01:35-23		/* device can be opened in mode 14 */
#define DV_m15 01:35-22		/* device can be opened in mode 15 */
#define DV_m16 01:35-21		/* device can be opened in mode 16 */
#define DV_m17 01:35-20		/* device can be opened in mode 17 */
#define D1_spl 01:35-0		/* device is spooled */
#define D1_alc 01:35-1		/* device is under control of allocator */
#define D1_vvl 01:35-2		/* volume valid */
#define D1_niu 01:35-3		/* device slot is not in use (for structures  */
				/* not yet mounted) */
#define D1_ini 01:35-4		/* device is being initialized (structure */
				/* is available only to the fork whose number */
				/* is stored in sdbsts) */



/* device type definitions */

#define DVdsk 00		/* disk */
#define DVmta 02		/* magtape */
#define DVdta 03		/* dectape */
#define DVptr 04		/* paper tape reader */
#define DVptp 05		/* paper tape punch */
#define DVdsp 06		/* display */
#define DVlpt 07		/* line printer */
#define DVcdr 010		/* card reader */
#define DVfe 011		/* front end device */
#define DVtty 012		/* terminal */
#define DVpty 013		/* pty */
#define DVnul 015		/* null device */
#define DVnet 016		/* arpa network */
#define DVplt 017		/* plotter */
#define DVcdp 021		/* card punch */
#define DVdcn 022		/* decnet active component */
#define DVsrv 023		/* decent passive component */
#define DVats 024		/* applications terminal service */
#define DVads 025		/* aydin display */


/* dskop */

#define DOp_sa 01:35-0		/* software address */
#define DOp_at 03:35-1		/* address type field */
#define DOppu 01		/* physical channel and unit */
#define DOp_cn 037:35-6		/* channel number */
#define DOp_un 077:35-12	/* unit number */
#define DOp_ua 037777777	/* unit address */
#define DOpsr 02		/* structure and relative address */
#define DOp_sn 0777:35-10	/* structure number */
#define DOp_ra 0177777777	/* relative address */
#define DOp_eo 01:35-10		/* error if unit offline */
#define DOp_il 01:35-11		/* inhibit error logging */
#define DOp_ir 01:35-12		/* inhibit error recovery */
#define DOp_wr 01:35-14		/* write */
#define DOp_ct 0777777:35-35	/* word count */


/* dumpi/dumpo */

#define DM_nwt 01:35-0		/* no wait for completion */
#define DM_fin 01:35-1		/* finish previous request */
				/* ***not inplemented yet*** */
#define DM_ptr 0777777:35-35	/* pointer to command list */



/* define decnet disconnect codes. these are stipulated by the nsp spec */
/* and may have meaninings not implied by the comments */

#define DCx0 00	 		/* no special error */
#define DCx1 01	 		/* resource allocation failure */
#define DCx2 02	 		/* destination node does not exist */
#define DCx3 03	 		/* node shutting down */
#define DCx4 04	 		/* destination process does not exist */
#define DCx5 05	 		/* invalid name field */
#define DCx6 06	 		/* destination process queue overflow */
#define DCx7 07	 		/* unspecified error */
#define DCx8 8			/* third party aborted link */
#define DCx9 9			/* user abort (asynchronous disconnect) */
#define DCx11 11		/* undefined error code */
#define DCx21 21		/* ci with illegal destination address */
#define DCx22 22		/* cc with illegal destination address */
#define DCx23 23		/* ci or cc with zero source address */
#define DCx24 24		/* flow control violation */
#define DCx32 32		/* too many connections to node */
#define DCx33 33		/* too many connections to dest. process */
#define DCx34 34		/* access not permitted */
#define DCx35 35		/* logical link services mismatch */
#define DCx36 36		/* invalid account */
#define DCx37 37		/* segsize too small */
#define DCx38 38		/* process aborted */
#define DCx39 39		/* no path to destination node */
#define DCx40 40		/* link aborted due to data loss */
#define DCx41 41		/* destination process does not exist */
#define DCx42 42		/* confirmation if di */
#define DCx43 43		/* image data field too long */


/* efact - fact file entry definitions */

#define EFhdr 00		/* header word */
#define EF_cod 0777:35-8	/* entry type code */
#define EF_job 0777:35-17	/* job number */
#define EF_lin 07777:35-29	/* line number */
#define EF_siz 077:35-35	/* entry size */
#define EFusr 01		/* user number word */
#define EFtad 02		/* time and date of entry */

/* fact file entry type codes */

#define EFlgi 0501		/* login */
#define EFlgo 0141		/* logout */
#define EFcac 0502		/* change account */
#define EFatt 0142		/* console attach */
#define EFdet 0143		/* console detach */
#define EFchk 0201		/* checkpoint */
#define EFsdu 0540		/* start disk-utilization entries */
#define EFdsk 0601		/* disk space utilization */
#define EFtim 0741		/* time set */
#define EFres 0740		/* system restarted */
#define EFlpt 0401		/* line printer usage */
#define EFcdr 0402		/* card reader usage */


/* enq/deq bit definitions and function codes */

/* function codes */

#define ENqbl 00		/* enq block option */
#define ENqaa 01		/* enq allocate only if available */
#define ENqsi 02		/* enq software interrupt when locked */
#define ENqma 03		/* enq modify access */
#define DEqdr 00		/* deq resource */
#define DEqda 01		/* deq all resources of this fork */
#define DEqid 02		/* deq this id number */
#define ENqcs 00		/* enqc status */
#define ENqcg 01		/* enqc get enq/deq quota for a job */
#define ENqcc 02		/* enqc change enq/deq quota for a job */
#define ENqcd 03		/* enqc dump locks and queue entries */



/* bit definitions */

#define EN_shr 01:35-0		/* sharable request */
#define EN_bln 01:35-1		/* bypass level number */
#define EN_nst 01:35-2		/* allow nesting */
#define EN_ltl 01:35-3		/* long term lock */
#define EN_lvl 0777:35-17	/* level number */
#define EN_job 0777777:35-35	/* job number */
#define EN_qce 01:35-0		/* error code in rh of status word */
#define EN_qcl 01:35-0		/* lock dump (.enqcd only) */
#define EN_qco 01:35-1		/* this fork owns the lock */
#define EN_qcq 01:35-2		/* this fork is in the queue for this lock */
#define EN_qct 01:35-2		/* lock contains a text string  */
#define EN_qcx 01:35-3		/* the lock is locked exclusively */
#define EN_qcb 01:35-4		/* user is blocked for lock  */


/* enq/deq argument block data structure */

#define ENqln 00		/* # of locks ,, length of argument block */
#define ENhln 077:35-5		/* length of header area */
#define ENnlk 07777:35-17	/* number of locks */
#define ENaln 0777777:35-35	/* length of argument block */
#define ENqid 01		/* psi channel # ,, request id */
#define ENqlv 02		/* flags & level number ,, jfn, -1, -2, or -3 */
#define ENquc 03		/* string pointer or user code */
#define ENqrs 04		/* # of resources in pool ,, # of resources wanted */
#define ENqms 05		/* address of resource block */



/* enqc dump data structure */

#define ENqdf 00		/* flags + level # ,, ofn, 400000+job #, -2, or -3 */
				/* or:  flags + psi # ,, job # of q-entry creator */

#define ENqdr 01		/* total resources in pool ,, resources remaining */
#define ENqdt 02		/* time stamp of last request locked */
#define ENqdc 03		/* user code of lock or start of text string */

#define ENqdi 01		/* group # or # requested ,, enq id */


/* flout/dfout */
/* format control word */

#define FL_sgn 03:35-1		/* first field sign control */
#define FLdig 00		/* digit */
#define FLspc 01		/* space */
#define FLpls 02		/* plus sign */
#define FLspa 03		/* space */
#define FL_jus 03:35-3		/* first field justification control */
#define FLlsp 00		/* leading spaces */
#define FLlzr 01		/* leading zeros */
#define FLlas 02		/* leading asterisks */
#define FLtsp 03		/* trailing spaces */
#define FL_one 01:35-4		/* first field nonblank */
#define FL_dol 01:35-5		/* dollar sign prefix */
#define FL_pnt 01:35-6		/* decimal point */
#define FL_exp 03:35-8		/* third field exponent control */
#define FLexn 00		/* no exponent */
#define FLexe 01		/* e exponent prefix */
#define FLexd 02		/* d exponent prefix */
#define FLexm 03		/* *10^ exponent prefix */
#define FL_esg 03:35-10		/* exponent sign control */
#define FLdge 00		/* digit */
#define FLple 01		/* plus sign */
#define FLspe 02		/* space */
#define FLdgt 03		/* digit */
#define FL_ovl 01:35-11		/* column overflow */
#define FL_rnd 037:35-17	/* digit position for rounding */
#define FL_fst 077:35-23	/* first field width */
#define FL_snd 077:35-29	/* second field width */
#define FL_thd 077:35-35	/* third field width */



/* gdsts */

/* see mtopr for card reader and line printer status bits */
/* see general field and value section for magtape status bits */
/* see tops20an section for network status bits */

#define GDfsm 017:35-3		/* tops20an	;finite machine state */

/* tty bits */

#define GD_par 01:35-35		/* if on, terminal accepts parity */


/* get */

#define GT_adr 01:35-19		/* use address limits in ac2 */
#define GT_prl 01:35-20		/* preload pages */
#define GT_nov 01:35-21		/* don't overlay existing pages */
#define GT_fl2 01:35-22		/* if on, ac3 contains flags */
#define G2_fch 01:35-0		/* make fast-cache entry */
#define GT_jfn 07777:35-35	/* jfn */



/* getab - table indices */

#define JObtt 00		/* job number to tty number */
#define JObrt 01		/* job runtime */
#define TIckp 02		/* ticks per second */
#define JObdi 03		/* job number to directory numbers (obs) */
#define TTyjo 04		/* tty number to job number */
#define NCpgs 05		/* number physical core pages */
#define DEvna 06		/* device name */
#define DEvch 07		/* device characteristics */
#define DEvun 010		/* device unit numbers */
#define DSker 011		/* disk error words */
#define DRmer 012		/* drum error words */
#define SYsve 013		/* version text */
#define SYsta 014		/* statistics */
#define QTime 015		/* sched queue times */
#define JObna 016		/* job number to program name */
#define SName 017		/* subsystem name */
#define STime 020		/* " time */
#define SPflt 021		/* " page faults */
#define SSize 022		/* " size integral */
#define SNblk 023		/* " number wakeups */
#define DBugs 024		/* dbugsw, dchksw */
#define LOgde 025		/* log, job 0 designators */
#define PTypa 026		/* pty parameters */
#define SYmta 027		/* gttab symbol table */
#define DWnti 030		/* hsys variables */
#define JObpn 031		/* job number to program name */
#define BLdtd 032		/* monitor build time and date */
#define LStdr 033		/* last dir number assigned (obs) */
#define APrid 034		/* apr serial number */
#define HQlav 035		/* high queue load averages */
#define LQlav 036		/* low queue load averages */
#define NEtrd 037		/* tops20an	;arpanet status */
#define IMphr 040		/* tops20an	;host ready */
#define HStst 041		/* tops20an	;dead host status */
#define HStna 042		/* tops20an	;host names */
#define HOstn 043		/* tops20an	;host name index */
#define NEtls 044		/* tops20an	;local socket */
#define NEtfs 045		/* tops20an	;foreign socket */
#define NEtaw 046		/* tops20an	;arpa connection address */
#define NEtba 047		/* tops20an	;bit allocation */
#define NEtst 050		/* tops20an	;connection status */
#define NEtbu 051		/* tops20an	;arpanet buffers */
#define NEtbt 052		/* tops20an	;byte count statistics */
#define IMpl1 053		/* tops20an	;imp link table one */
#define IMpl2 054		/* tops20an	;imp link table two */
#define IMpl3 055		/* tops20an	;imp link table three */
#define IMpl4 056		/* tops20an	;imp link table four */
#define LHost 057		/* tops20an	;local host number */
#define JBont 060		/* owning job */
#define NSwpg 061		/* default swapping pages */



/* getji */

#define JIjno 00		/* job number */
#define JItno 01		/* terminal number */
#define JIuno 02		/* user number */
#define JIdno 03		/* directory number */
#define JIsnm 04		/* subsys name */
#define JIpnm 05		/* program name */
#define JIrt 06	 		/* run time */
#define JIcpj 07		/* controlling pty job number */
#define JIrtl 010		/* run time limit (set by timer jsys) */
#define JIbat 011		/* controlled by batch */
#define JIden 012		/* magtape default density */
#define JIpar 013		/* magtape default parity */
#define JIdm 014		/* magtape default data mode */
#define JIrs 015		/* magtape default record size */
#define JIdfs 016		/* deferred spooling */
#define JIlno 017		/* logged-in directory number */
#define JIsrm 020		/* pointer to job session remark */
#define JIlln 021		/* last login date & time */
#define JIsrt 022		/* job runtime at start of this accounting session */
#define JIsct 023		/* job console time at start of this session */
#define JIt20 024		/* -1 if at tops20 command level */
#define JIstm 025		/* date & time job was initialized */
#define JIbch 026		/* batch stream and flags */
#define OB_wto 03:35-1		/* write to operator capabilities */
#define OBall 00	 	/* wto and wtor allowed */
#define OBnwr 01	 	/* no wtor allowed */
#define OBnom 02	 	/* no message allowed */
#define OB_bss 01:35-10		/* batch stream number set */
#define OB_bsn 0177:35-17	/* batch-stream number */
#define JIllo 027		/* logical location (node name) */

#define JImax .jillo		/* current highest getji offset */


/* gfrks */

#define GF_gfh 01:35-0		/* get relative fork handles */
#define GF_gfs 01:35-1		/* get fork status */


/* gfust */

#define GFaut 00		/* get file author */
#define GFlwr 01		/* get file last writer */

/* gthst				;tops20an */

#define GThsz 00		/* host table sizes */
#define GThix 01		/* index to string conversion */
#define GThns 02		/* number to string conversion */
#define GThsn 03		/* string to number conversion */
#define GThhn 04		/* host number to status */
#define GThhi 05		/* host index to status */

/* getok definitions */
#define GOasd 01		/* assign device */
#define GEerb 00		/* error block address */
#define GEadd 01		/* device designator */
#define GOcap 02		/* enable capabilities */
#define GEncp 01		/* new capabilities */
#define GOcjb 03		/* allow crjob jsys */
#define GOlog 04		/* allow logins */
#define GElun 01		/* user number */
#define GOcfk 05		/* allow cfork jsys */
#define GEfct 01		/* number of forks */
#define GOtbr 06		/* allow set terminal baud rate */
#define GElin 01		/* line number */
#define GEspd 02		/* speed */
#define GOlgo 07		/* allow logout  */
#define GEusd 01		/* pages used */
#define GEquo 02		/* quota */
#define GErlg 03		/* user requesting logout */
#define GOenq 010		/* allow set enq quota */
#define GEequ 01		/* desired quota */
#define GEeun 02		/* job number */
#define GOcrd 011		/* allow credir */
#define GOsmt 012		/* allow smount */
#define GEsde 01		/* device designator */

#define GOmdd 013		/* allow mddt entry */
#define GOcls 014		/* verify class assignment for a job */
#define GEjob 01		/* job # */
#define GEcls 02		/* class desired */
#define GOcl0 015		/* set class at login */
#define GOmta 016		/* mt access request */

#define GEacc 01		/* access code from hdr1 */
#define GEusn 02		/* user number */
#define GEunt 03		/* mt unit number */
#define GEacd 04		/* desired access (bits) */
#define GEltp 05		/* label type */
#define GOacc 017		/* access and connect */
#define GOac0 01	 	/* flags from acess jsys */
#define GOac1 02	 	/* directory number */
#define GOoad 020		/* assign due to openf */
				/* .geadd is the arg offset for the */
				/* device designator */
#define GOatc 021		/* attach to a job */
#define GEatu 01	 	/* user attempting attach */


/* user access control types */
#define GOplt 0400000		/* plot request */
#define GOprt 0400001		/* print request */
#define GOspl 0400002		/* entry from spooler */
#define GEspt 01	 	/* spooler type (1=plot, 2=print) */
#define GEspt 01	 	/* spooler type (1=plot, 2=print) */

#define GOkmz 20		/* max argument block size for getok request */

/* error block address offsets */

#define GEsiz 00		/* size of this block */
#define GEern 01		/* error number */
#define GEptr 02		/* pointer to error string */
#define GEbsz 03		/* string size */

/* gtjfn definitions */

/* flags provided to gtjfn on call */

#define GJ_fou 01:35-0		/* file is for output use */
#define GJ_new 01:35-1		/* new file only */
#define GJ_old 01:35-2		/* old file only */
#define GJ_msg 01:35-3		/* print an appropriate message */
#define GJ_cfm 01:35-4		/* confirmation is required */
#define GJ_tmp 01:35-5		/* temporary */
#define GJ_ns 01:35-6		/* dont search search lists */
#define GJ_acc 01:35-7		/* no access by other forks */
#define GJ_del 01:35-8		/* ignore "deleted" bit */
#define GJ_jfn 03:35-10		/* jfn use field */
#define GJdnu 00		/* do not use jfn provided */
#define GJerr 02		/* error if cannot use jfn provided */
#define GJalt 03		/* use alternate if cannot use given jfn */
#define GJ_ifg 01:35-11		/* accept input file group descriptors */
#define GJ_ofg 01:35-12		/* accept output file group descriptors */
#define GJ_flg 01:35-13		/* return flags */
#define GJ_phy 01:35-14		/* physical device only */
#define GJ_xtn 01:35-15		/* extended format (e+11 exists) */
#define GJ_fns 01:35-16		/* accumulator 2 contains job file numbers */
#define GJ_sht 01:35-17		/* short call format */

/* flags provided to gtjfn (in second flag word) */

#define G1_rnd 01:35-0		/* return on null(in alternate flag word) */
#define G1_rbf 01:35-1		/* ^r buffer is disjoint (obsolete) */
#define G1_nln 01:35-2		/* no long names */
#define G1_rcm 01:35-3		/* return confirm message */
#define G1_rie 01:35-4		/* return when main string is empty */
#define G1_iin 01:35-5		/* ignore invisible status */
#define G1_sln 01:35-6		/* suppress expansion of logical names */



/* flags returned by gtjfn */

#define GJ_dev 01:35-0		/* asterisk was given for device */
#define GJ_unt 01:35-1		/* asterisk was given for unit */
#define GJ_dir 01:35-2		/* asterisk was given for directory */
#define GJ_nam 01:35-3		/* asterisk was given for name */
#define GJ_ext 01:35-4		/* asterisk was given for extension */
#define GJ_ver 01:35-5		/* asterisk was given for generation */
#define GJ_uhv 01:35-6		/* use highest generation */
#define GJ_nhv 01:35-7		/* use next higher generation */
#define GJ_ulv 01:35-8		/* use lowest generation */
#define GJ_pro 01:35-9		/* protection given */
#define GJ_act 01:35-10		/* account given */
#define GJ_tfs 01:35-11		/* temporary file specified (;t) */
#define GJ_gnd 01:35-12		/* complement of gj_del on call */
#define GJ_giv 01:35-17		/* comp of g1_iiv */

/* gtjfn table offsets */

#define GJgen 00		/* flags ,, generation */
#define GJdef <z 0>		/* default generation */
#define GJnhg <z -1>		/* next higher generation */
#define GJleg <z -2>		/* lowest existing generation */
#define GJall <z -3>		/* all generations (i.e., ;*) */
#define GJsrc 01		/* source jfn ,, output jfn */
#define GJdev 02		/* default device */
#define GJdir 03		/* default directory */
#define GJnam 04		/* default name */
#define GJext 05		/* default extenstion */
#define GJpro 06		/* default protection */
#define GJact 07		/* default account */
#define GJjfn 010		/* desired jfn */
#define GJf2 011		/* second group flags,,count */
#define GJcpp 012		/* copy buffer pointer */
#define GJcpc 013		/* copy buffer count */
#define GJrty 014		/* retype (^r) pointer */
#define GJbfp 015		/* top of buffer pointer */
#define GJatr 016		/* pointer to arbitrary attribute block */

/* gnjfn - flags returned */

#define GN_str 01:35-13		/* structure changed */
#define GN_dir 01:35-14		/* directory changed */
#define GN_nam 01:35-15		/* name changed */
#define GN_ext 01:35-16		/* extension changed */

/* gtncp				;tops20an */

#define GTnsz 00		/* size of table */
#define GTnix 01		/* ncp index */
#define GTnni 02		/* nvt input */
#define GTnno 03		/* nvt output */
#define GTnjf 04		/* jfn */

#define NCidx 00		/* ncp index */
#define NCfhs 01		/* foreign host */
#define NClsk 02		/* local socket */
#define NCfsk 03		/* foreign socket */
#define NCfsm 04		/* finite state machine state */
#define NClnk 05		/* link */
#define NCnvt 06		/* nvt, -1 if not a telnet connection */
#define NCsiz 07		/* byte size of connection */
#define NCmsg 010		/* msg alloc */
#define NCbal 011		/* bit alloc */
#define NCdal 012		/* desired alloc */
#define NCbtc 013		/* bits xferred */
#define NCbpb 014		/* bytes/buffer */
#define NCclk 015		/* time-out countdown */
#define NCsts 016		/* connection status */


/* gtrpw */

#define PF_usr 01:35-0		/* page fail word - user mode reference */
#define PF_wrt 01:35-5		/* " - write reference */
#define TSw_rd 01:35-14		/* trap status word - read */
#define TSw_wt 01:35-15		/* " - write */
#define TSw_wr 01:35-15		/* (another name for above) */
#define TSw_ex 01:35-16		/* " - execute */
#define TSw_mn 01:35-17		/* " - monitor mode reference */


/* gtsts bits returned in 2 */

#define GS_opn 01:35-0		/* file is open */
#define GS_rdf 01:35-1		/* if open, file is open for read */
#define GS_wrf 01:35-2		/* if open, file is open for write */
#define GS_xcf 01:35-3		/* if open, file is open for execute */
#define GS_rnd 01:35-4		/* ok to reset byte pointer */
				/* (file is not append) */
#define GS_apt 01:35-5		/* access per page table */
				/* (not implemented -- obsolete) */
#define GS_cal 01:35-6		/* ok to call as a procedure */
				/* (not implemented -- obsolete) */
#define GS_lng 01:35-7		/* file is long */
#define GS_eof 01:35-8		/* at end of file on read */
#define GS_err 01:35-9		/* file may be in error */
#define GS_nam 01:35-10		/* file has a name (jfn exists) */
#define GS_ast 01:35-11		/* one or more fields of name */
				/* is wild */
#define GS_asg 01:35-12		/* jfn is being assigned */
#define GS_hlt 01:35-13		/* terminate on i/o error */
#define GS_frk 01:35-17		/* jfn is restricted to creating fork */
#define GS_pln 01:35-18		/* don't strip line numbers on sin/bin */
#define GS_mod 017:35-35	/* data mode */
#define GSnrm 00	 	/* normal mode */
#define GSimg 010	 	/* image (binary) mode */
#define GSdmp 017	 	/* dump mode */



/* hptim */

#define HPelp 00		/* elapsed time */
#define HPrnt 01		/* run time */


/* idcnv (also idtnc and odcnv) */

#define IC_dsa 01:35-0		/* daylight savings if appropriate */
#define IC_ads 01:35-1		/* apply daylight savings */
#define IC_utz 01:35-2		/* use time zone given */
#define IC_jud 01:35-3		/* use julian date conversion */
#define IC_tmz 077:35-17	/* time zone */
#define IC_tim 0777777:35-35	/* local time */


/* idtim & idtnc */

#define IT_nda 01:35-0		/* no date */
#define IT_nnm 01:35-1		/* no numeric month */
#define IT_snm 01:35-2		/* second number is month */
#define IT_err 01:35-3		/* error if numbers are not in specified */
				/* order */
#define IT_nti 01:35-6		/* no time */
#define IT_nis 01:35-7		/* no seconds */
#define IT_ais 01:35-8		/* always include seconds */
#define IT_nac 01:35-9		/* no colon allowed between hh and mm */
#define IT_aac 01:35-10		/* always allow colon */
#define IT_ams 01:35-11		/* always interpret one colon as hhmm:ss */
#define IT_ahm 01:35-12		/* always interpret one colon as hh:mm */
#define IT_n24 01:35-14		/* no 24-hour format */
#define IT_ntm 01:35-15		/* no time modifier (am, pm) */
#define IT_ntz 01:35-16		/* no time zone */


/* .imopr - monitor routine used by mddt and snoop.  this is not */
/* a jsys so that calls are fast. */

#define IMalc 01		/* allocate pages for use in mapping symbols */
#define IMmap 02		/* map pages of the symbol table */
#define IMump 03		/* unmap pages of the symbol table */


/* inlnm */

#define INljb 00		/* get job wide logical name from index */
#define INlsy 01		/* get system logical name from index */

/* ipcf bit definitions and data structures */

/* packet format */

#define IPcfl 00		/* flags word */
#define IP_cfb 01:35-0		/* don't block read */
#define IP_cfs 01:35-1		/* indirect sender's pid */
#define IP_cfr 01:35-2		/* indirect receiver's pid */
#define IP_cfo 01:35-3		/* overdraw send */
#define IP_ttl 01:35-4		/* truncate on too large message */
#define IP_cpd 01:35-5		/* create a pid on the send */
#define IP_jwp 01:35-6		/* make the created pid be job wide */
#define IP_noa 01:35-7		/* no access of pid by other forks */
#define IP_cfp 01:35-18		/* sender is priv'd and is envoking privs */
#define IP_cfv 01:35-19		/* page transfer mode */
#define IP_cfz 01:35-20		/* zero length message was sent */
#define IP_int 01:35-21		/* internal call - unavailable to users */
#define IP_cfe 077:35-29	/* error field */

/* errors sent by info */

#define IPcpi 015		/* insufficient privilege */
#define IPcuf 016		/* illegal function */
#define IPcsn 067		/* send info your name */
#define IPcff 072		/* info free space exhausted */
#define IPcbp 074		/* pid has no name or is illegal */
#define IPcdn 075		/* duplicate name */
#define IPcnn 076		/* unknown name */
#define IPcen 077		/* illegal name */
#define IPckm 066		/* notification that pid has been deleted */
#define IP_cfc 07:35-32		/* system sender code */
#define IPccc 01		/* sent by [system]ipcf */
#define IPccf 02		/* sent by system wide [system]info */
#define IPccp 03		/* sent by receiver's [system]info */
#define IP_cfm 07:35-35		/* special message return field */
#define IPcfn 01		/* message was not delivered */
#define IPcfs 01		/* pid of sender */
#define IPcfr 02		/* pid of receiver */
#define IPcfp 03		/* pointer to message block */
#define IPcfd 04		/* logged in dir of sender */
#define IPcfc 05		/* enabled capabilities of sender */
#define IPcsd 06		/* connected directory number of sender */
#define IPcas 07		/* pointer to account string of sender */
#define IPcll 010		/* pointer to logical location of sender */

#define IPcsu 026		/* spool message code from ipcc */
#define IPcsl 027		/* logout message code from ipcc */
#define IPcsa 030		/* resource allocator message code */
#define IPcds 031		/* structure dismount message code from ipcc */
#define IPcli 032		/* login message code from ipcc */
#define IPclo 033		/* logout message to creator from ipcc */
#define IPckp 034		/* deleted pid message from ipcc */
#define IPcca 035		/* create an application (reserved for tps use) */
#define IPctr 036		/* request from tape */
#define IPcms 037		/* structure mount message code from ipcc */
#define IPcrs 040		/* structure removal mssg code from ipcc */
#define IPcsr 041		/* archive message code from ipcc */

#define IPcss 015		/* ipcc request to info to delete pids */


/* [system] info definitions */

#define IPci0 00		/* code,,function */
#define IPciw 01		/* find pid for name */
#define IPcig 02		/* find name for pid */
#define IPcii 03		/* assign name to pid */
#define IPcij 04		/* assign name to pid */
#define IPcik 05		/* notify when specified pid is killed */
#define IPcis 015		/* monitor drop pid function */
#define IPci1 01		/* pid to get a copy of reply */
#define IPci2 02		/* start of data */


/* jfns */

#define JS_dev 07:35-2		/* device  field output control */
#define JS_dir 07:35-5		/* directory field output control */
#define JS_nam 07:35-8		/* name field output control */
#define JS_typ 07:35-11		/* file type field output control */
#define JS_gen 07:35-14		/* generation field output control */
#define JS_pro 07:35-17		/* protection field output control */
#define JS_act 07:35-20		/* account field output control */
	/* values for above 7 fields: */
#define JSnof 00	 	/* never output field */
#define JSaof 01	 	/* always output field */
#define JSssd 02	 	/* suppress if system default */
#define JS_tmp 01:35-21		/* return ;t if temp file */
#define JS_siz 01:35-22		/* return size */
#define JS_cdr 01:35-23		/* return creation date */
#define JS_lwr 01:35-24		/* return last write */
#define JS_lrd 01:35-25		/* return last read */
#define JS_ptr 01:35-26		/* ac 2 holds string pointer not jfn */
#define JS_atr 01:35-27		/* return attributes */
#define JS_at1 01:35-28		/* return 1 specific attribute */
#define JS_ofl 01:35-29		/* return ;off-line if offline file */
#define JS_psd 01:35-32		/* punctuate size and date */
#define JS_tbr 01:35-33		/* tab before fields returned */
#define JS_tbp 01:35-34		/* tab before possible fields */
#define JS_paf 01:35-35		/* punctuate all fields */



/* lnmst */

#define LNsjb 00		/* get job wide definition of a ln */
#define LNssy 01		/* get system definition of a logical name */


/* lock */

#define LK_cnt 01:35-0		/* use count in ac3 */
#define LK_phy 01:35-1		/* use ac1 as physical page number */
#define LK_nch 01:35-2		/* map pages cache inhibited */
#define LK_aol 01:35-3		/* allow locking in offline pages */



/* meter jsys defs. */

#define MErea 01		/* read ebox ticks */
#define MErma 02		/* read mbox ticks */

/* mstr */

#define MSrnu 00		/* read status of next disk unit */
#define MSrus 01		/* read status of a disk unit */
#define MSrch 00		/* channel number */
#define MSrct 01		/* controller number */
#define MSrun 02		/* unit number */
#define MSrst 03		/* status */
#define MS_mnt 01:35-0		/* this unit is part of a mounted structure */
#define MS_16b 01:35-1		/* this unit written in 16-bit mode */
				/* (reserved for future) */
#define MS_dia 01:35-2		/* this unit is currently in use by an */
				/* on-line diagnostic */
#define MS_ofl 01:35-3		/* this unit is off-line */
#define MS_err 01:35-4		/* there was an error reading this unit */
#define MS_bbb 01:35-5		/* one of the bat blocks is bad */
#define MS_hbb 01:35-6		/* one of the home blocks is bad */
#define MS_wlk 01:35-7		/* unit is write-locked */
#define MS_typ 0777:35-17	/* disk type code */
/* defined the same as .uttxx in phypar */
#define MSrp4 01		/* rp04 */
#define MSrp5 05		/* rp05 */
#define MSrp6 06		/* rp06 */
#define MSrp7 07		/* rp07 */
#define MSrm3 011		/* rm03 */
#define MSrsn 04		/* structure name */
#define MSrsa 05		/* structure alias */
#define MSrns 06		/* unit # in structure,,# of units in structure */
#define MSrsw 07		/* number of pages for swapping */
#define MSrui 010		/* unit id */
#define MSroi 013		/* owner id */
#define MSrfi 016		/* file-system id */
#define MSrsp 021		/* number of sectors per page */
#define MSrsc 022		/* number of sectors per cylinder */
#define MSrpc 023		/* number of pages per cylinder */
#define MSrcu 024		/* number of cylinders per unit */
#define MSrsu 025		/* number of sectors per unit */
#define MSrbt 026		/* number of bit-words in bit table per cylinder */
#define MSrln 027		/* max length of argument block in words */

#define MSmnt 02		/* mount a structure */
#define MStnm 00		/* name of structure */
#define MStal 01		/* alias name */
#define MStnu 02		/* number of units in structure */
#define MStfl 02		/* flags (lhs) */
#define MS_flg (0777777<<18|00)	/* mask for .mstfl */
#define MS_nfh 01:35-0		/* no fix bad home block */
#define MS_nfb 01:35-1		/* no fix bad bat block */
#define MS_xcl 01:35-2		/* mount for exclusive use by job */
#define MS_ign 01:35-3		/* ignore errors */
#define MStui 03		/* start of unit information */
#define MStch 00		/* channel number */
#define MStct 01		/* controller number */
#define MStun 02		/* unit number */
#define MStno 03		/* # of argument words/unit */

#define MSdis 03		/* dismount a structure */
#define MSdnm 00		/* name of structure */

#define MSgss 04		/* get status of a structure */
#define MSgsn 00		/* structure name (alias) */
#define MSgst 01		/* status */
#define MS_ps 01:35-0		/* structure is a public structure */
#define MS_dis 01:35-1		/* structure is being dismounted */
#define MS_dom 01:35-2		/* structure is domestic */
#define MS_pps 01:35-3		/* structure is the primary public structure */
#define MS_ini 01:35-4		/* structure is being initialized */
#define MS_lim 01:35-5		/* structure limited to 2050 sizes */
#define MS_nrs 01:35-6		/* structure is not regulated */
#define MSgnu 02		/* number of units in structure */
#define MSgmc 03		/* mount count */
#define MSgfc 04		/* open file count */
#define MSgsi 05		/* structure id */
#define MSgln 06		/* length of argument block */

#define MSsss 05		/* set status of a structure */
#define MSssn 00		/* structure name */
#define MSsst 01		/* new status bits */
#define MSsmw 02		/* mask word of bits to be changed */
#define MSsln 03		/* length of argument block */

#define MSini 06		/* initialize a structure */
#define MSinm 00		/* name of structure */
#define MSial 01		/* alias name */
#define MSinu 02		/* number of units in structure */
#define MSifl 02		/* flags (lhs) */
				/* flags defined in .msmnt function */
#define MS_fcn 077:35-17	/* function code */
#define MScre 01	 	/* create new file system */
#define MSrrd 02	 	/* reconstruct the root-directory */
#define MSwhb 03	 	/* write the home blocks */
#define MSrix 04		/* rebuild index table (idxfil) */
#define MSisu 03		/* start of unit information */
#define MSich 00		/* channel number */
#define MSict 01		/* controller number */
#define MSiun 02		/* unit number */
#define MSino 03		/* # of argument words/unit */
#define MSist 06		/* status word */
#define MSisw 07		/* number of pages for swapping on this unit */
#define MSife 010		/* number of pages for front-end file system */
#define MSiui 011		/* unit id */
#define MSioi 014		/* owner id */
#define MSifi 017		/* file system id */
#define MSifb 022		/* number of pages for  bootstrap.bin (optional) */

#define MSimc 07		/* increment mount count */
#define MSdmc 010		/* decrement mount count */
#define MSdev 00		/* device designator or structure */
#define MSjob 01		/* job number for which to change count */

#define MSgsu 011		/* get structure users */
#define MSual 00		/* pointer to alias of structure */
#define MSufl 01		/* flags,,# of items returned */
#define MS_gta 01:35-0		/* get users who have accessed structure */
#define MS_gtm 01:35-1		/* get users who have mounted structure */
#define MS_gtc 01:35-2		/* get users who are connected to structure */
#define MSuj1 02		/* first job number returned */

#define MShom 012		/* modify homeblock word */
#define MShnm 00		/* pointer to alias, or designator for alias */
#define MShof 01		/* offset into homeblock of word being changed */
#define MShvl 02		/* new values for bits being changed */
#define MShmk 03		/* mask declaring which bits being changed */

#define MSicf 013		/* increment mount count on a fork basis */
#define MSdcf 014		/* decrement mount count on a fork basis */
#define MSdev 00		/* device designator or structure */

#define MSofl 015		/* enable psi interrupts interrupts for */
				/* disk (for device allocator) */
#define MSchn 00		/* channel on which to receive interrupt */


#define MSiic 016		/* ignore increment check for structure use */

/* mtopr - function codes */

#define MOcle 00		/* clear errors */
#define MOnop 031		/* nop (wait for activity to stop) */
#define MOrew 01		/* rewind */
#define MOeof 03		/* write eof */
#define MOdte 04		/* assign fe device to a dte */
#define MOfwr 06		/* forward space record */
#define MObkr 07		/* backspace record */
#define MOrul 011		/* rewind and unload */
#define MOers 013		/* erase tape */
#define MOfwf 016		/* forward space file */
#define MObkf 017		/* backspace file */
#define MOspd 026		/* set tty speed (for kl only) */
#define MOrsp 027		/* read line speed (for kl only) */
#define MO_rmt 01:35-0		/* flag to say line is remote */
#define MO_aut 01:35-1		/* flag to say line is "auto" speed */
				/* (rsx20f only) */
#define MOsdr 02		/* set read direction */
#define MOrdr 026		/* read read direction */
#define MOeot 010		/* skip to logical end of tape */
#define MOsrs 05		/* set record size */
#define MOrrs 015		/* read record size */
#define MOsdn 024		/* set density */
#define MOrdn 012		/* read density */
#define MOsdm 04		/* set data mode */
#define MOrdm 014		/* read data mode */
#define MOspr 020		/* set parity */
#define MOrpr 021		/* read parity */
#define MOnrb 022		/* get number of remaining bytes in record */
#define MOfou 023		/* force out record */
#define MOinf 025		/* get information about tape */
#define MOict 00		/* count of arguments to be returned */
#define MOitp 01		/* magtape type code */
/* defined the same as .uttxx in phypar */
#define MTt45 03	 	/* magtape type tu45  */
#define MTt77 013	 	/* magtape type tu77 */
#define MTt78 015	 	/* magtape type tu78 */
#define MTt70 017	 	/* magtape type tu70 */
#define MTt71 020	 	/* magtape type tu71 */
#define MTt72 021	 	/* magtape type tu72 */
#define MTt73 022	 	/* reserved for 200 ips stc gcr drive */
#define MOiid 02		/* magtape reel id */
#define MOisn 03		/* chan,controller,unit ,, serial # */
#define MOird 04		/* # of reads done */
#define MOiwt 05		/* # of writes done */
#define MOirc 06		/* record # from bot */
#define MOifc 07		/* file count on tape */
#define MOisr 010		/* # of soft read errors */
#define MOisw 011		/* # of soft write errors */
#define MOihr 012		/* # of hard read errors */
#define MOihw 013		/* # of hard write errors */
#define MOirf 014		/* # records read */
#define MOiwf 015		/* # of frames written */
#define MOloc 032		/* attach mt to mta */
#define MOcnt 00	 	/* offset for count */
#define MOmtn 01	 	/* offset for mt number */
#define MOlbt 02	 	/* label type (.ltxxx) */
#define MOdns 03	 	/* density (.sjdxx) */
#define MOavl 04	 	/* address of volume labels */
#define MOnvl 05	 	/* # of volume labels (vol1 + uvlss) */
#define MOcvn 06	 	/* current volume number within set */
#define MOvsn 07	 	/* volume set name */
#define MOsta 037		/* current magtape status */
#define MOddn 01		/* 1st word of .mosta densities capable */

#define SJ_cp2 01:35-1		/* 200 bpi */
#define SJ_cp5 01:35-2		/* 556 bpi */
#define SJ_cp8 01:35-3		/* 800 bpi */
#define SJ_c16 01:35-4		/* 1600 bpi */
#define SJ_c62 01:35-5		/* 6250 bpi */

#define MOddm 02		/* 2nd word of .mosta data modes capable */
#define SJ_cmc 01:35-1		/* core dump mode */
#define SJ_cm6 01:35-2		/* sixbit */
#define SJ_cma 01:35-3		/* ansi ascii */
#define SJ_cm8 01:35-4		/* industry compatable */
#define SJ_cmh 01:35-5		/* high density mode */
#define MOtrk 03		/* 3rd word of .mosta number of tracks */
#define SJ_7tr 01:35-1		/* 7 track drive */
#define SJ_9tr 01:35-2		/* 9 track drive */

#define MOcst 04		/* 4th word of .mosta tape status */
#define SJ_ofs 01:35-0		/* off line */
#define SJ_mai 01:35-1		/* maintenance mode enabled */
#define SJ_mrq 01:35-2		/* maintenance mode requested */
#define SJ_bot 01:35-3		/* bot */
#define SJ_rew 01:35-4		/* rewinding */
#define SJ_wlk 01:35-5		/* write locked */

#define MOdvt 05		/* 5th word of .mosta device type */

/* definitions for this are same as used in .mtaln */
#define MOofl 040		/* psi for magtapes */
#define MOpst 042		/* psi for eot on mt's */
/* t3/ psi assignment (-1 => clear) */
#define MOrvs .morew		/* rewind volume set */
#define MOrvl 043		/* rewind current volume */
#define MOvls 044		/* volume switch for unlabeled tapes */
#define MOntr 045		/* set/clear no translate flag */
/* t3/ -1 => don't convert ebcdic to ascii */
/* t3/0=> convert */
#define MOrdl 046		/* read user labels */
/* t2/ gets label i.d. */
/* t3/ sp to where 76 charcters are to be placed */
#define MOwul 047		/* write user labels */
/* t2/ label i.d. */
/* t3/ sp to 76 characters of data */
#define MOrli 050		/* read label information for mt */
#define MOmtp 01	 	/* type of label */
#define MOmvn 02	 	/* volume name */
#define MOmow 03	 	/* owner */
#define MOmfm 04	 	/* format of tape file */
#define MOmrl 05	 	/* record length */
#define MOmbl 06	 	/* block length */
#define MOmcd 07	 	/* creation date */
#define MOmed 010	 	/* expiration date */
#define MOmfi 011	 	/* file name */
#define MOmgn 012	 	/* generation number */
#define MOmgv 013	 	/* generation version number */
#define MOvmb 014	 	/* value of mode byte */
#define MOsmv 051		/* set mode value */
#define TPfst 00	 	/* stream mode */
#define TPfcp 01	 	/* all formatting controls present */
#define TPffc 02	 	/* fortran controls present */
#define TPfnc 03	 	/* no controls present */
#define TPfmx 03	 	/* max value of field */
#define MOsds 052		/* set deferred volume-switch mode */
#define MOpsi 027		/* set error psi for lpt and cdr */
#define MO_msg 01:35-0		/* suppress standard cty messages */
#define MOsid 027		/* set reel i.d. */
#define MOiel 030		/* inhibit error logging */
#define MOshv 045		/* set hdr1 and hdr2 values for mt */
#define MOfmt 01	 	/* offset for format */
#define MOepd 02	 	/* expiration date */
#define MObsz 03	 	/* block size */
#define MOrsz 04	 	/* record size */

/* def for ipcf message sent on a volume switch or other condition */
/* message code is .ipctr. offsets that follow are */
/* relative to word containing .ipctr. */

#define VMcod 00		/* code for this message */
				/* is subcode of .ipctr function */
#define VMabt 01	 	/* abort close */
#define VMicn 02	 	/* internal error (hopefully not used) */
#define VMerr 03	 	/* label r/w error */
#define VMvsm 04	 	/* volume switch */
#define VMsts 05	 	/* unit status change (not used yet) */
#define VMunl 06	 	/* unit unload */
#define VMrew 07	 	/* rewind */
#define VSmtn 01		/* mt number */
#define VSflg 02		/* flags */
#define VS_flg -1b17		/* flags part of word */
#define VS_wrt 01:35-0		/* write previous volume was opened for write */
#define VS_cod 0777777	 	/* code */
#define VSmnv 01	 	/* mount nth volume */
#define VSfst 02	 	/* mount first volume */
#define VSlst 03	 	/* mount last volume */
#define VSmrv 04	 	/* mount relative volume number (signed) */
#define VSfls 05	 	/* force labeled tape volume-switch */
#define VScnt 03		/* volume number (signed if vs_mrv is on) */

#define MOlvf 032		/* load device's vfu */
#define MOrvf 033		/* read vfu file name */
#define MOltr 034		/* load translation ram */
#define MOrtr 035		/* read ram file name */
#define MOsts 036		/* set software status */
#define MOrst 037		/* read software status */
#define MO_lpc 01		/* page counter overflow */
#define MO_lci 02		/* character interrupt (hard error) */
#define MO_lvf 04		/* vfu error.  paper must be re-aligned */
#define MO_lvu 020		/* line printer has optical vfu */
#define MO_rpe 040		/* ram parity error */

#define MO_rck 01		/* read check */
#define MO_pck 02		/* pick check */
#define MO_sck 04		/* stack check */
#define MO_hem 010		/* hopper empty */
#define MO_sfl 020		/* stacker full */

#define MO_fnx 01:35-17		/* non-existent device */
#define MO_ol 01:35-16		/* device is off-line */
#define MO_he 01:35-15		/* hardware error */
#define MO_ser 01:35-14		/* software error */
#define MO_iop 01:35-13		/* i/o in progress */
#define MO_eof 01:35-12		/* end of file */
/* 1b11				;reserved */
#define MO_fer 01:35-10		/* fatal error */
#define MO_lcp 01:35-0		/* lower case printer */
#define MO_rld 01:35-1		/* front-end was reloaded */
#define MOflo 040		/* flush output */

/* see setjb for various argument values */

#define MOsnt 034		/* set tty non-terminal status */
#define MOsmn 01		/* no system messages(i.e. suppress) */
#define MOsmy 00		/* yes system messages(default) */
#define MOrnt 035		/* read tty non-terminal status */

/* pty mtopr numbers */

#define MOapi 024		/* assign pty interrupt channels */
#define MO_wfi 01:35-0		/* enable waiting for input */
#define MO_oir 01:35-1		/* enable output is waiting */
#define MO_sic 077:35-17	/* software interrupt channel */
#define MOpih 025		/* test pty input hungry */
#define MOnwi 00		/* not waiting for input */
#define MOwfi -1		/* waiting for input */
#define MObat 026		/* set batch bit */
#define MOjcb 01		/* job controlled by batch */
#define MOncb 00		/* job not controlled by batch */


/* tty mode definitions */

#define MOrlw 030		/* read width */
#define MOslw 031		/* set width */
#define MOrll 032		/* read length */
#define MOsll 033		/* set length */
#define MOsig 036		/* set "ignore input when inactive" bit */
#define MOrbm 037		/* read 128 character break mask */

#define MO_wn1 (0776117<<18|0777740)	/* bit definitions for non-formatting control  */
#define MO_wn2 00	 	/* for ascii codes 40-777 */
#define MO_wn3 00	 	/* for ascii codes 100-137 */
#define MO_wn4 020	 	/* for ascii codes 137-177 */

#define MO_wf1 (0001260<<18|0000420)	/* formatting control bits  */
#define MO_wf2 00	 	/* for ascii codes 40-77 */
#define MO_wf3 00	 	/* for ascii codes 100-137 */
#define MO_wf4 020	 	/* for ascii codes 140-177 */

#define MO_wp1 (0000400<<18|0400)	/* punctuation bit definitions  */
#define MO_wp2 (0777774<<18|0001760)	/* for ascii codes 40-77  */
#define MO_wp3 (0400000<<18|0000760)	/* for ascii codes 100-137  */
#define MO_wp4 (0400000<<18|0000760)	/* for ascii codes 140-177  */

#define MO_wa1 0400	 	/* alphanumerics definitions */
#define MO_wa2 (0000003<<18|0776000)	/* for ascii codes 40-77  */
#define MO_wa3 (0377777<<18|0777000)	/* for ascii codes 100-137  */
#define MO_wa4 (0377777<<18|0777020)	/* for ascii codes 140-177 */
#define MOsbm 040		/* set 128 character break mask */
#define MOrfw 041		/* read field width */
#define MOsfw 042		/* set field width */
#define MOxof 043		/* set/clear xoff/xon handling */
#define MOoff 00	 	/* turn off xon/xoff processing */
#define MOonx 01	 	/* turn on xon/xoff processing */
#define MOrxo 044		/* read value of xoff bit */
#define MOslc 045		/* set line counter */
#define MOrlc 046		/* read line counter */
#define MOslm 047		/* set line counter maximum */
#define MOrlm 050		/* read line counter maximum */
#define MOtps 051		/* psi for non-controlling terminal  */

/* net mtopr numbers */

#define MOacp 020		/* tops20an	;accept connection on socket */
#define MOsnd 021		/* tops20an	;send all curently buffered bytes */
#define MOsin 022		/* tops20an	;send ins/inr command */
#define MOain 024		/* tops20an	;assign ins/inr and fsm psi channels */
#define MO_nin 077:35-5		/* tops20an	;ins/inr software interrupt channel */
#define MO_fsm 077:35-17	/* tops20an	;fsm change of state interrupt channel */


/* definitions for decnet */

#define MOacn 024		/* assign connect interrupt channel */
#define MO_cdn 0777:35-8	/* connect interrupt channel */
#define MO_ina 0777:35-17	/* interrupt message channel */
#define MO_dav 0777:35-26	/* data available channel */
#define MOnci 0777	 	/* no change */
#define MOcia 0776	 	/* clear interrupt assignment */

#define MOrls 025		/* read link status */
#define MO_con 01:35-0		/* link is connected */
#define MO_srv 01:35-1		/* link is a server */
#define MO_wfc 01:35-2		/* waiting for a connect */
#define MO_wcc 01:35-3		/* waiting for this link to confirm */
#define MO_eom 01:35-4		/* eom present in input buffer */
#define MO_abt 01:35-5		/* connection aborted */
#define MO_syn 01:35-6		/* synch di recieved */
#define MO_int 01:35-7		/* int message available */
#define MO_lwc 01:35-8		/* link was connected */
#define MOrhn 026		/* read host name */
#define MOrtn 027		/* read task name */
#define MOrus 030		/* read user data */
#define MOrpw 031		/* read password */
#define MOrac 032		/* read account */
#define MOrda 033		/* read optional data */
#define MOrcn 034		/* read connect object number */
#define MOrim 035		/* read interrupt message */
#define MOsim 036		/* send interrupt message */
#define MOrod 037		/* read obj-desc of connection */
#define MOclz 040		/* close/reject a connection */
#define MOcc 041		/* accept a connection */
#define MOrss 042		/* read segment size */

/* definitions for ats */

/* function codes for mtopr are in column 1 */

#define MOamo 01		/* set mode word */
#define MOamm 01	 	/* message mode */
#define MOadm 02	 	/* data mode */
#define MOaat 02		/* acquire terminal */
#define MO_aer 01:35-0		/* htn field contains an error code */
#define MOasi 03		/* enable interrupts */
#define MO_ifl 0777:35-8	/* function to be performed */
#define MOaai 00	 	/* assign interrupt channel */
#define MOadi 01	 	/* deassign interrupt channel */
#define MO_iev 0777:35-17	/* event being assigned or deassigned */
#define MOadt 00	 	/* data arrival */
#define MOast 01	 	/* status arrival */
#define MO_ach 0777777:35-35	/* channel number */
#define MOrcd 04		/* get status */
#define MO_wdv 0777:35-35	/* which devices to report on */
#define MOald 00	 	/* all terminals */
#define MOchg 01	 	/* terminals whose status has changed */
#define MOlst 02	 	/* terminals specified in list */
#define MO_arm 01:35-0		/* ask the resource manager */
#define MO_mda 01:35-1		/* more data available for this jfn */
#define AT_opn 01:35-0		/* htn is open and usable */
#define AT_tcl 01:35-1		/* nrm closed terminal via status-report */
#define AT_dht 01:35-2		/* deassigning htn */
#define AT_txf 01:35-3		/* terminal is xoff'd */
#define AT_und 01:35-4		/* device requested is undefined */
#define AT_nav 01:35-5		/* device requested is not available */
#define AT_ofl 01:35-6		/* device requested is offline */
#define AT_ful 01:35-7		/* server is full */
#define AT_uns 01:35-8		/* device type is unsupported */
#define AT_rej 01:35-9		/* node nrm rejected the request */
#define AT_mie 01:35-10		/* monitor internal error (node or host) */
#define AT_stf 01:35-11		/* vt62 start-up failed */
#define AT_crj 01:35-12		/* connection was rejected */
#define AT_ndp 01:35-13		/* data pipe is not open */
#define AT_ser 0777777:35-35	/* status report error code (18 bits) */
#define MOade 05		/* deassign terminal */
#define MO_aab 01:35-0		/* don't send remaining data */

/* function codes for aydin display mtopr */

#define MOfle 00		/* flush errors */
#define MOrer 01		/* return aydin error code */
#define MOwat 02		/* wait for activity to stop */
#define MO_rwc 0777777:35-17	/* remaining word count */
#define MO_ler 0777777:35-35	/* last aydin error code */

/* defs for mtu jsys */

/* functions: */

#define MTnvv 01		/* set no volume valid */
#define MTcnt 00	 	/* count word */
#define MTcod 01	 	/* error code */
#define MTptr 02	 	/* sp to operator response */

#define MTral 02		/* read all labels */
#define MTvl1 01	 	/* sp to vol1 area */
#define MTvl2 02	 	/* sp to vol2 area */
#define MThd1 03	 	/* sp to hdr1 area */
#define MThd2 04	 	/* sp to hdr2 area */
#define MTasi 03		/* return mt to mta association */
#define MTphu 01	 	/* return mta unit number here */
#define MTnul -1		/* no assignment code */
#define MTcvv 04		/* clear vv */

/* mutil jsys function codes */

#define MUenb 01		/* enable pid for receiving */
#define MUdis 02		/* disable pid from receiving */
#define MUgti 03		/* get pid of [system]info */
#define MUcpi 04		/* create a private info for a job */
#define MUdes 05		/* destroy a pid */
#define MUcre 06		/* create a pid */
#define MUssq 07		/* set send and receive quotas */
#define MUcho 010		/* change owner of a pid */
#define MUfoj 011		/* find owner's job number */
#define MUfjp 012		/* find job's pids */
#define MUfsq 013		/* find send and receive quotas */
#define MUffp 015		/* find fork's pids */
#define MUspq 016		/* set pid quota */
#define MUfpq 017		/* find pid quota */
#define MUqry 020		/* query */
#define MUapf 021		/* associate a pid with a fork */
#define MUpic 022		/* put pid on an interrupt channel */
#define MUdfi 023		/* define pid of [system]info */
#define MUssp 024		/* set system pid table */
#define MUrsp 025		/* read system pid table */
#define MUmps 026		/* get maximum packet size */
#define MUskp 027		/* set pid to receive killed pid message */
#define MUrkp 030		/* read pid that receives killed pid messages */
#define MUsps 031		/* get system maximum packet size */


/* system pid table index values */

#define SPipc 00		/* pid of ipcc */
#define SPinf 01		/* pid of info */
#define SPqsr 02		/* pid of quasar */
#define SPmda 03		/* pid of qsrmda */
#define SPopr 04		/* pid of operator job (orion) */
#define SPnsr 05		/* pid of netser */


/* node */

#define NDsln 00		/* set local node name */
#define NDgln 01		/* get local node name */
#define NDnod 00		/* pointer to node name */
#define NDsnm 02		/* set local node number */
#define NDgnm 03		/* get local node number */
#define NDslp 04		/* set loopback on port */
#define NDprt 00	 	/* port to set in loopback */
#define NDclp 05		/* clear loopback on port */
#define NDflp 06		/* find loopback port */
#define ND_lpr 01:35-0		/* loopback running */
#define ND_lpa 01:35-1		/* loopback assigned to port */
#define NDsnt 07		/* set network topology information */
#define NDgnt 010		/* get network topology information */
#define NDnnd 00	 	/* number of node block pointers following */
#define NDcnt 01	 	/* number of words in a node block */
#define NDbk1 02	 	/* first address of a node block */

	/* node block definitions */
#define NDnam 00	 	/* pointer to asciz node name */
#define NDsta 01	 	/* node state */
#define NDson 00		/* on */
#define NDsof 01		/* off */
#define NDnxt 02	 	/* pointer to asciz nearer neighbor string */
#define NDnbs 03	 	/* node block size */

#define NDsic 011		/* set topology change interrupt channel */
#define NDchn 00	 	/* channel number */
#define NDcic 012		/* clear network topology interrupt */
#define NDgvr 013		/* get nsp version information */
#define NDnvr 00	 	/* number of versions returned */
#define NDcvr 01	 	/* pointer to communicatons version block */
#define NDrvr 02	 	/* pointer to routing version block */

#define NDver 00	 	/* version number */
#define NDeco 01	 	/* eco number */
#define NDcst 02	 	/* customer level */
#define NDgli 014		/* get line information */
#define NDnln 00	 	/* <# of entries following>,,<# line returned> */
#define NDcnt 01	 	/* number of words in a line block */

	/* line block definition */
#define NDlnm 00	 	/* nsp port (line) number */
#define NDlst 01	 	/* state of line */
#define NDlon 01		/* on */
#define NDlof 02		/* off */
#define NDlcn 03		/* controller loopback */
#define NDlcb 04		/* cable loopback */
#define NDlnd 02	 	/* byte pointer node at end of line */
#define NDlsz 03	 	/* size of block */
#define NDvfy 015		/* verify node name */
#define NDflg 01	 	/* flags returned by monitor */
#define ND_exm 01:35-0		/* node specfied exactly matches a known node */

/* nout */

#define NO_mag 01:35-0		/* output magnitude */
#define NO_sgn 01:35-1		/* output sign */
#define NO_lfl 01:35-2		/* leading filler */
#define NO_zro 01:35-3		/* fill with zero's */
#define NO_oov 01:35-4		/* output on column overflow */
#define NO_ast 01:35-5		/* output asterisks on overflow */
#define NO_col 0177:35-17	/* number of columns to use */
#define NO_rdx 0777777		/* radix */


#define OF_fdt 01:35-33		/* force date update */

/* odcnv -- see idcnv for bits */


/* odtim */

#define OT_nda 01:35-0		/* do not output date */
#define OT_day 01:35-1		/* output day of week */
#define OT_fdy 01:35-2		/* output numeric month */
#define OT_nmn 01:35-3		/* output numeric month */
#define OT_fmn 01:35-4		/* output month in full */
#define OT_4yr 01:35-5		/* output 4-digit year */
#define OT_dam 01:35-6		/* output day after month */
#define OT_spa 01:35-7		/* output spaces in date */
#define OT_sla 01:35-8		/* output slashes in date */
#define OT_ntm 01:35-9		/* do not output time */
#define OT_nsc 01:35-10		/* do not output seconds */
#define OT_12h 01:35-11		/* output 12-hour format */
#define OT_nco 01:35-12		/* do not output colon */
#define OT_tmz 01:35-13		/* output time zone */
#define OT_scl 01:35-17		/* suppress columnization */


/* odtnc -- see idcnv for bits */


/* openf */

#define OF_bsz 077:35-5		/* byte size */
#define OF_mod 017:35-9		/* mode */
#define OF_her 01:35-18		/* halt on io error */
#define OF_rd 01:35-19		/* read */
#define OF_wr 01:35-20		/* write */
#define OF_ex 01:35-21		/* execute (reserved for the future) */
#define OF_app 01:35-22		/* append */
#define OF_thw 01:35-25		/* thawed */
#define OF_awt 01:35-26		/* always wait */
#define OF_pdt 01:35-27		/* preserve dates */
#define OF_nwt 01:35-28		/* never wait */
#define OF_rtd 01:35-29		/* restricted */
#define OF_pln 01:35-30		/* set to disable line number checking for */
				/* non-line number files */
#define OF_dud 01:35-31		/* don't update to disk by ddmp */
#define OF_ofl 01:35-32		/* allow opening the device even if offline */
#define OF_fdt 01:35-33		/* force date update */
#define OF_rar 01:35-34		/* wait if file is off-line */



/* pmap bit definitions */

#define PM_cnt 01:35-0		/* rh word contains a count */
#define PM_mvp 01:35-1		/* move page instead of indirect pointer */
				/* (not implemented */
#define PM_rd 01:35-2		/* read */
#define PM_wt 01:35-3		/* write */
#define PM_wr 01:35-3		/* (another name for above) */
#define PM_ex 01:35-4		/* execute (reserved for the future) */
#define PM_rwx 07:35-4		/* convenient abbrev for rd+wt+ex */
#define PM_pld 01:35-5		/* preload pages being mapped */
#define PM_ind 01:35-6		/* use indirect ptrs (reserved for the future) */
#define PM_tpu 01:35-8		/* trap to user */
				/* (not implemented -- obsolete) */
#define PM_cpy 01:35-9		/* copy on write */
#define PM_abt 01:35-11		/* abort unmap. */
#define PM_rpt 0777777:35-35	/* repeat count */


/* pmctl - physical memory control */

#define MCrce 00		/* read cache enable */
#define MCsce 01		/* set cache enable */
#define MCcst 00		/* arglist offset for cache state */
#define MC_cen 01		/* cache enabled */
#define MCrps 02		/* read page status */
#define MCsps 03		/* set page status */
#define MCppn 00		/* arglist offset for physical page number */
#define MCpst 01		/* arglist offset for page state */
#define MCpsa 00		/* page available */
#define MCpss 01		/* page in transition state */
#define MCpso 02		/* page offline */
#define MCpse 03		/* page offline due to error */
#define MCrme 04		/* read memory error information */
#define PMmer 01		/* mos memory error */
#define PMmtp 00		/* entry header and type */
#define PMmrg 01		/* error register */
#define PMmsy 02		/* syndrome */
#define PMmbn 03		/* block number */
#define PMmsb 04		/* spare bit number */
#define PMmea 05		/* error address */
#define PMmsn 06		/* start of serial numbers */
#define PMmns 04		/* # of serial numbers to store */


/* prarg - process arguments */

/* function code definitions */

#define PRard 01		/* read argument block */
#define PRast 02		/* set argument block */



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


/* sctty */

#define SCret 00		/* return designator (ctty) for fork */
#define SCset 01		/* set sctty for fork */
#define SCrst 02		/* clear fork ctty (restore job ctty) */

/* scvec */

#define SVead 00		/* entry address */
#define SVine 01		/* initial entry for setup */
#define SVget 02		/* entry address for get share file routine */
#define SV40 03	 		/* address to get location 40 */
#define SVrpc 04		/* address to get return pc */
#define SVmak 05		/* entry for make share file routine */
#define SVcst 06		/* 2 word block for control-c/start processing */


/* sdvec */

#define SDead 00		/* entry address */
#define SDine 01		/* initial entry */
#define SDver 02		/* dms version */
#define SDdms 03		/* address to store dms jsys */
#define SDrpc 04		/* address to store return pc */



/* setjb function codes */

#define SJden 00		/* set default magtape density */
#define SJddn 00		/* system default density */
#define SJdn2 01		/* 200 bpi */
#define SJdn5 02		/* 556 bpi */
#define SJdn8 03		/* 800 bpi */
#define SJd16 04		/* 1600 bpi */
#define SJd62 05		/* 6250 bpi */
#define SJpar 01		/* set default magtape parity */
#define SJpro 00		/* odd parity */
#define SJpre 01		/* even parity */
#define SJdm 02	 		/* set default magtape data mode */
#define SJddm 00		/* system default data mode */
#define SJdmc 01		/* core dump mode */
#define SJdm6 02		/* six bit byte mode (for 7-track drives) */
#define SJdma 03		/* ansi ascii mode (7 bits in 8 bit byte) */
#define SJdm8 04		/* industry compatible mode */
#define SJdmh 05		/* hi-density mode (9 eight bit */
				/* bytes in 2 words) */
#define SJrs 03	 		/* set default magtape record size */
#define SJdfs 04		/* set deferred spooling */
#define SJspi 00		/* immediate mode spooling */
#define SJspd 01		/* deferred mode spooling */
#define SJsrm 05		/* set job session remark */
#define SJt20 06		/* declare whether tops20 command level or not */
#define SJdfr 07		/* set default job retrieval mode */
#define SJrfa 00		/* openf should always fail */
#define SJrwa 01		/* openf should always request & wait */
#define SJbat 010		/* set batch flags and stream */
				/* see .jibch for field definitions */
#define SJllo 011		/* set job location */


/* sfork */

#define SF_con 01:35-0		/* continue process, ignore pc in ac2 */
#define SF_prh 0777777:35-35	/* process handle */


/* sfust */

#define SFaut 00		/* set author string */
#define SFlwr 01		/* set last writer string */



/* smon function codes and bit definitions (system flags) */

#define SFfac 00		/* allow fact entries */
#define SFcde 01		/* checkdisk found errors */
#define SFcdr 02		/* checkdisk running */
#define SFmst 03		/* manual start in progress */
#define SFrmt 04		/* remote logins allowed */
#define SFpty 05		/* pty logins allowed */
#define SFcty 06		/* cty login allowed */
#define SFopr 07		/* operator in attendance */
#define SFlcl 010		/* local logins allowed */
#define SFbte 011		/* bit table errors found on startup */
#define SFcrd 012		/* user can change directory characteristics */
#define SFnvt 013		/* tops20an	;nvt login allowed */
#define SFwct 014		/* wheel login on cty allowed */
#define SFwlc 015		/* wheel login on local terminals allowed */
#define SFwrm 016		/* wheel login on remote terminals allowed */
#define SFwpt 017		/* wheel login on pty's allowed */
#define SFwnv 020		/* tops20an	;wheel login on nvt's allowed */
#define SFusg 021		/* usage file in use */
#define SFflo 022		/* full latency optimization */
				/* caution: setting this requires that the */
				/* system be at revision level 10, and */
				/* that rh20 board m8555 be at revision level d. */
				/* otherwise, the file-system may be damaged. */

#define SFmta 023		/* magtape allocation enabled */
/* below are function codes that do not map directly into bits */


#define SFntn 044		/* tops20an	;network on/off control */
#define SFndu 045		/* tops20an	;net down/up request */
#define SFnhi 046		/* tops20an	;net host table initialize */
#define SFtmz 047		/* set time zone this system is in */
#define SFlhn 050		/* tops20an	;set local host number of this net site */
#define SFavr 051		/* account validation on/off */
#define SFsts 052		/* enable/disable status reporting */
#define SFsok 053		/* getok/givok default setting */
#define SFmcy 054		/* set max ordinary offline exp period */
#define SFrdu 055		/* read date update function */
#define SFacy 056		/* set max archive exp period */
#define SFrtw 057		/* set [no] retrieval waits non-0 => no wait */
#define SFtdf 060		/* tape mount controls */
#define MT_uut 01:35-0		/* unload unreadable tapes */
#define SFwsp 061		/* working set preloading */

#define SF_fac 01:35-<.sffac>	/* fact entries allowed */
#define SF_cde 01:35-<.sfcde>	/* checkdisk found errors */
#define SF_cdr 01:35-<.sfcdr>	/* checkdisk running */
#define SF_mst 01:35-<.sfmst>	/* manual start in progress */
#define SF_rmt 01:35-<.sfrmt>	/* remote logins allowed */
#define SF_pty 01:35-<.sfpty>	/* pty logins allowed */
#define SF_cty 01:35-<.sfcty>	/* cty login allowed */
#define SF_opr 01:35-<.sfopr>	/* operator in attendance */
#define SF_lcl 01:35-<.sflcl>	/* local logins allowed */
#define SF_bte 01:35-<.sfbte>	/* bit table errors found on startup */
#define SF_crd 01:35-<.sfcrd>	/* user can change directory characteristics */
#define SF_nvt 01:35-<.sfnvt>   /* tops20an	;nvt logins allowed */
#define SF_usg 01:35-<.sfusg>	/* usage file in use */
#define SF_flo 01:35-<.sfflo>	/* full latency optimization in use */
				/* caution: setting this requires that the */
				/* system be at revision level 10, and */
				/* that rh20 board m8555 be at revision level d. */
				/* otherwise, the file-system may be damaged. */
#define SF_mta 01:35-<.sfmta>	/* magtape allocation enabled */


#define SF_eok 01:35-0		/* enable access checking */
#define SF_dok 01:35-1		/* allow access if checking disabled */


/* sinm jsys definitions */

#define SI_tmg 01:35-0		/* truncate message */
#define SI_eom 01:35-1		/* end-of-message found */

/* sir jsys (new form) */

#define SI_ver 07:35-17		/* version of sir in t1 */
#define SI_lev 077:35-5		/* level field in chntab */
#define SI_adr 7777,,-1		/* address of interrupt routine in chntab */

/* sked jsys */

#define SAcnt 00	 	/* argument block offset for count */

	/* function codes */

#define SKrbc 01		/* read bias control knob */
#define SAknb 01	 	/* offset for knob value */
#define SKsbc 02		/* set bias control knob */
#define SKrcs 03		/* read share of a class */
#define SAcls 01	 	/* class */
#define SAshr 02	 	/* share */
#define SAuse 03	 	/* use */
#define SA1ml 04	 	/* 1 minute load average */
#define SA5ml 05	 	/* 5 minute load average */
#define SA15l 06	 	/* 15 minute load */
#define SKscs 04		/* set share of a class */
#define SKics 05		/* start or stop class scheduling */
#define SActl 01	 	/* word for control bits */
#define SKscj 06		/* set class of a job */
#define SAjob 01	 	/* job */
#define SAjcl 02	 	/* class of job */
#define SAwa 03			/* wa on/off switch */
#define SKrjp 07		/* read class parameters for a job */
#define SAjsh 03	 	/* job's share allotment */
#define SAjus 04	 	/* job's current use */
#define SKbcr 010		/* read class setting for batch jobs */
#define SAbcl 01	 	/* batch class */
#define SKbcs 011		/* set class for batch jobs */
#define SKbbg 012		/* run batch jobs on dregs queue */
#define SAdrg 01	 	/* word to specify dregs or not */
#define SKddc 013		/* set system class default */
#define SAdcl 01	 	/* default class word */
#define SKrcv 014		/* read status */
#define SK_act 01:35-0		/* class by accounts */
#define SK_wdf 01:35-1		/* withhold windfall */
#define SK_stp 01:35-2		/* class scheduler off */
#define SK_drg 01:35-3		/* batch jobs are being run on dregs queue */

/* snoop jsys definitions */

/* snoop function codes */

#define SNplc 00		/* lock code into monitor virt memory */
#define SNpls 01		/* lock down the swappable monitor */
#define SNpdb 02		/* define a break point */
#define SNpib 03		/* insert the break points */
#define SNprb 04		/* remove the break points */
#define SNpul 05		/* unlock and release all snoop resources */
#define SNpsy 06		/* look up a monitor symbol */
#define SNpad 07		/* look up address in symbol table */

/* soutm jsys definitions */

#define SO_wmg 01:35-0		/* write end-of-message */

/* spool jsys function codes */

#define SPldi 00		/* define an input spooling device */
#define SPlsd 01		/* set directory of spooled device */
#define SPlrd 02		/* read directory of spooled device */

/* flags in spool message on logout and spooled file close */

#define SP_bat 01:35-0		/* job is a batch job */
#define SP_dfs 01:35-1		/* spooling is deferred */
#define SP_elo 01:35-2		/* job executed lgout jsys itself */
#define SP_flo 01:35-3		/* job forced to log out by trap in top fk */
#define SP_olo 01:35-4		/* other job aimed lgout at this one */

/* spool argument block */

#define SPldv 00		/* device designator */
#define SPlna 01		/* name string */
#define SPldr 01		/* directory number */
#define SPlgn 02		/* generation number */


/* ssave */

#define SS_nnp 0777777:35-17	/* negative number of pages */
#define SS_cpy 01:35-18		/* allow copy-on-write */
#define SS_uca 01:35-19		/* use current access */
#define SS_rd 01:35-20		/* allow read access */
#define SS_wr 01:35-21		/* allow write access */
#define SS_exe 01:35-22		/* allow execute access */
#define SS_fpn 0777:35-35	/* first page number */


/* stcmp */

#define SC_lss 01:35-0		/* t1 less than t2 */
#define SC_sub 01:35-1		/* t1 substring of t2 */
#define SC_gtr 01:35-2		/* t1 greater than t2 */



/* stdir */

#define ST_dir 01:35-0		/* files only directory */
#define ST_ana 01:35-1		/* alphanumeric accounts */
#define ST_rlm 01:35-2		/* repeat login message */


/* stiw */

#define ST_dim 01:35-0		/* set deferred interrupt mask */
#define ST_prh 0777777:35-35	/* process handle */

/* swtrp definitions */

#define SWart 00		/* set arithmetic trap */
#define SWrat 01		/* read arithmetic trap */
#define SWlut 02		/* set luuo address */
#define SWrlt 03		/* read luuo address */
#define ARpfl 00	 	/* offset in trap block for pc flags */
#define ARopc 01	 	/* offset for old pc value */
#define ARefa 02	 	/* offset for e */
#define ARnpc 03	 	/* offset for new pc word */


/* tbluk */

#define TL_nom 01:35-0		/* no match */
#define TL_amb 01:35-1		/* ambiguous */
#define TL_abr 01:35-2		/* legal abbreviation */
#define TL_exm 01:35-3		/* exact match */


/* tfork */

/* function codes in lh ac1 */

#define TFset 00		/* set traps as spec'd by bit table */
#define TFral 01		/* remove all traps set by this fork */
#define TFrtp 02		/* remove traps set by this fork */
#define TFsps 03		/* set jsys trap psi chan in lh(2) */
#define TFrps 04		/* read jsys trap psi chan into lh(2) */
#define TFtst 05		/* test if self monitored */
#define TFres 06		/* remove traps from all inferiors, clr psi */
#define TFuuo 07		/* set uuo traps for fork */
#define TFsju 08		/* set both uuo and jsys traps */
#define TFruu 09		/* remove uuo traps */

/* timer definitions */

#define TImrt 00		/* set time limit */
#define TImel 01		/* set elapsed time clock */
#define TImdt 02		/* set date & time clock */
#define TImdd 03		/* delete an explict date & time clock */
#define TImbf 04		/* delete all entires before d&t */
#define TImal 05		/* delete all (includes time limit) */



/* tlink */

#define TL_cro 01:35-0		/* clear remote to object link */
#define TL_cor 01:35-1		/* clear object to remote link */
#define TL_eor 01:35-2		/* establist object to remote link */
#define TL_ero 01:35-3		/* establish remote to object link */
#define TL_sab 01:35-4		/* set accept bit for object */
#define TL_abs 01:35-5		/* accept bit state */
#define TL_sta 01:35-6		/* set or clear advice */
#define TL_aad 01:35-7		/* accept advice */
#define TL_obj 0777777:35-35	/* object designator */



/* ufpgs */


#define UF_now 01:35-0		/* no wait on update */

/* utest function codes */

#define UTset 00		/* start testing */
#define UTclr 01		/* stop testing and return results */

/* utest argument block */

#define UTadr 00		/* starting address of code */
#define UTlen 01		/* length of code */
#define UTmap 02		/* start of bit map */

/* usage */

#define USent 00		/* write entry */
#define UScls 01		/* close out current file */
#define USckp 02		/* perform checkpoint */
#define USlgi 03		/* login */
#define USlgo 04		/* logout */
#define USsen 05		/* session end */
#define UScki 06		/* set checkpoint interval */
#define USena 07		/* enable account validation */
#define UScas 010		/* change accounting shift now */
#define USsas 011		/* set automatic accounting shift change times */
#define USras 012		/* read automatic accounting shift change times */
				/* table entry format for .ussas/.usras: */
#define US_dow 0177:35-6	/* day-of-week bits */
#define US_ssm 0777777	 	/* time in seconds since midnight */

/* utfrk */

#define UT_trp 01:35-0		/* itrap (or do erjmp/ercal) trapped jsys */


/* wild functions */

#define WLstr 00		/* compare two strings */
#define WLjfn 01		/* compare two jfns */

/* wild flags and bits */

#define WL_lcd 01:35-0		/* don't convert lower case to upper case */
#define WL_nom 01:35-0		/* strings did not match */
#define WL_abr 01:35-1		/* non-wild string is abbreviation of wild string */
#define WL_dev 01:35-1		/* device field did not match */
#define WL_dir 01:35-2		/* directory field did not match */
#define WL_nam 01:35-3		/* name field did not match */
#define WL_ext 01:35-4		/* file type did not match */
#define WL_gen 01:35-5		/* generation number did not match */


/* argument block offsets for xsir and xrir jsys's */

#define SIcnt 00		/* length of block */
#define SIlvt 01		/* address of level table */
#define SIcht 02		/* address of channel table */


/* scheduler control flags (jsys not yet defined) */

#define SK_cyt 01:35-18		/* cycle time */
#define SK_ioc 01:35-19		/* io quantum charge */
#define SK_ht1 01:35-20		/* limit hold time */
#define SK_ht2 01:35-21		/* no hold time after skipped fork */
#define SK_hqr 01:35-22		/* high queue fork have priority under load */
/* sk_lqr==:01:35-23			;low queue reserve */
/* sk_bqe==:01:35-24			;balset queue on entry */
#define SK_rsq 01:35-25		/* quick reschedule on wakeups */
#define SK_rq1 01:35-26		/* requeue to queue 1 */
#define SK_ttp 01:35-27		/* tty preference */
#define SK_wcf 01:35-28		/* wait credit proportional to load av */

/* *********************************************** */
/* general field and value definitions */
/* used by many jsyses */
/* *********************************************** */


/* general fork handles */

#define FHslf 0400000		/* self */
#define FHsup <z -1>		/* superior */
#define FHtop <z -2>		/* top in job */
#define FHsai <z -3>		/* self and inferiors */
#define FHinf <z -4>		/* inferiors */
#define FHjob <z -5>		/* all in job */


/* fields of jfn mode word */

#define TT_osp 01:35-0		/* output suppress */
#define TT_mff 01:35-1		/* mechanical formfeed present */
#define TT_tab 01:35-2		/* mechanical tab present */
#define TT_lca 01:35-3		/* lower case capabilities present */
#define TT_len 0177:35-10	/* page length */
#define TT_wid 0177:35-17	/* page width */
#define TT_wak 017:35-23	/* wakeup field */
#define TT_wk0 01:35-18		/* wakeup class 0 (unused) */
#define TT_ign 01:35-19		/* ignore tt_wak on sfmod */
#define TT_wkf 01:35-20		/* wakeup on formating control chars */
#define TT_wkn 01:35-21		/* wakeup on non-formatting controls */
#define TT_wkp 01:35-22		/* wakeup on punctuation */
#define TT_wka 01:35-23		/* wakeup on alphanumerics */
#define TT_eco 01:35-24		/* echos on */
#define TT_ecm 01:35-25		/* echo mode */
#define TT_alk 01:35-26		/* allow links */
#define TT_aad 01:35-27		/* allow advice (not implemented) */
#define TT_dam 03:35-29		/* data mode */
#define TTbin 00		/* binary */
#define TTasc 01		/* ascii */
#define TTato 02		/* ascii and translate output only */
#define TTate 03		/* ascii and translate echos only */
#define TT_uoc 01:35-30		/* upper case output control */
#define TT_lic 01:35-31		/* lower case input control */
#define TT_dum 03:35-33		/* duplex mode */
#define TTfdx 00		/* full duplex */
#define TT0dx 01		/* not used, reserved */
#define TThdx 02		/* half duplex (character) */
#define TTldx 03		/* line half duplex */
#define TT_pgm 01:35-34		/* page mode */
#define TT_car 01:35-35		/* carrier state */



/* directory protection definitions (3 6-bit fields: owner, group, world) */

#define DP_rd 040		/* reading directory is allowed */
#define DP_cn 010		/* connect to dir, or change prot/account */
#define DP_cf 04		/* creating files in dir is allowed */

/* file protection definitions (3 6-bit fields: owner, group, world) */

#define FP_dir 02		/* directory listing */
#define FP_app 04		/* append */
#define FP_ex 010		/* execute */
#define FP_wr 020		/* write */
#define FP_rd 040		/* read */


/* input and output identifiers */

#define PRiin 0100		/* primary input */
#define PRiou 0101		/* primary output */
#define NUlio 0377777		/* null designator */
#define CTtrm 0777777		/* job's controlling terminal */
#define DVdes 0600000		/* universal device code */
#define TTdes 0400000		/* universal terminal code */


/* magtape device status bits */

#define MT_ilw 01:35-18		/* illegal write */
#define MT_dve 01:35-19		/* device error */
#define MT_dae 01:35-20		/* data error */
#define MT_ser 01:35-21		/* suppress error recovery procedures */
#define MT_eof 01:35-22		/* eof (file mark) */
#define MT_irl 01:35-23		/* incorrect record length */
#define MT_bot 01:35-24		/* beginning of tape */
#define MT_eot 01:35-25		/* end of tape */
#define MT_evp 01:35-26		/* even parity */
#define MT_den 03:35-28		/* density (0 is 'normal') */
#define MTlod 01		/* low density (200 bpi) */
#define MTmed 02		/* medium density (556 bpi) */
#define MThid 03		/* high density (800 bpi) */
#define MT_cct 07:35-31		/* character counter */
#define MT_nsh 01:35-32		/* data mode or density not supported by hardware */


/* device data modes */

#define DMasc 01		/* ascii */
#define DMimg 010		/* image */
#define DMimb 013		/* image binary */
#define DMbin 014		/* binary */


/* defined psi channels */

#define ICaov 06		/* arithmetic overflow */
#define ICfov 07		/* floating overflow */
#define ICpov 09		/* pdl overflow */
#define ICeof 010		/* end of file */
#define ICdae 011		/* data error */
#define ICqta 012		/* quota/disk exceeded */
#define ICtod 014		/* time of day (not implemented) */
#define ICili 015		/* illeg instruction */
#define ICird 016		/* illegal read */
#define ICiwr 017		/* illegal write */
#define ICiex 018		/* illegal execute (not implemented) */
#define ICift 019		/* inferior fork termination */
#define ICmse 020		/* machine size exceeded */
#define ICtru 021		/* trap to user (not implemented) */
#define ICnxp 022		/* nonexistent page referenced */


/* terminal type numbers */

#define TT33 00	 		/* model 33 */
#define TT35 01	 		/* model 35 */
#define TT37 02	 		/* model 37 */
#define TTexe 03		/* execuport */
#define TTdtc 02		/* diablo or dtc (tty 37 de-implemented) */
#define TTexe 03		/* execuport */
#define TTgtt 04		/* glass teletype */
#define TTpe 05	 		/* perkin elmer fox */
#define TTadm 06		/* lsi adm3a */
#define TTtel 07		/* teleray 1061 */
#define TTdef 8			/* default */
#define TTidl 9			/* ideal */
#define TTv05 10		/* vt05 */
#define TTv50 11		/* vt50 */
#define TTl30 12		/* la30 */
#define TTg40 13		/* gt40 */
#define TTl36 14		/* la36 */
#define TTv52 15		/* vt52 */
#define TT100 16		/* vt100 */
#define TTl38 17		/* la38 */
#define TT120 18		/* la120 */
#define TThp 24			/* hp 2645/2621 */

/* defined terminal codes */

#define TIcbk 00		/* break */
#define TIcca 01		/* ^a */
#define TIccb 02		/* ^b */
#define TIccc 03		/* ^c */
#define TIccd 04		/* */
#define TIcce 05		/* ^e */
#define TIccf 06		/* ^f */
#define TIccg 07		/* ^g */
#define TIcch 08		/* ^h */
#define TIcci 09		/* ^i */
#define TIccj 010		/* ^j */
#define TIcck 011		/* ^k */
#define TIccl 012		/* ^l */
#define TIccm 013		/* ^m */
#define TIccn 014		/* ^n */
#define TIcco 015		/* ^o */
#define TIccp 016		/* ^p */
#define TIccq 017		/* ^q */
#define TIccr 018		/* ^r */
#define TIccs 019		/* ^s */
#define TIcct 020		/* ^t */
#define TIccu 021		/* ^u */
#define TIccv 022		/* ^v */
#define TIccw 023		/* ^w */
#define TIccx 024		/* ^x */
#define TIccy 025		/* ^y */
#define TIccz 026		/* ^z */
#define TIces 027		/* esc */
#define TIcrb 028		/* rubout */
#define TIcsp 029		/* space */
#define TIcrf 030		/* carrier off */
#define TIcti 031		/* typein */
#define TIcto 032		/* typeout */




/* capabilities */

#define SC_ctc 01:35-0		/* control-c */
#define SC_gtb 01:35-1		/* getab */
#define SC_mmn 01:35-2		/* map monitor */
#define SC_log 01:35-3		/* logging functions */
#define SC_mpp 01:35-4		/* map privileged pages */
#define SC_sdv 01:35-5		/* special devices */
#define SC_sct 01:35-6		/* assign tty as controlling for fork (sctty) */

#define SC_sup 01:35-9		/* superior access */

#define SC_frz 01:35-17		/* freeze on terminating conditions */

#define SC_whl 01:35-18		/* wheel */
#define SC_opr 01:35-19		/* operator */
#define SC_cnf 01:35-20		/* confidential information access */
#define SC_mnt 01:35-21		/* maintenance */
#define SC_ipc 01:35-22		/* ipcf privileges */
#define SC_enq 01:35-23		/* enq/deq privileges */
#define SC_nwz 01:35-24		/* tops20an	;net wizard privileges (asnsq, etc.) */
#define SC_nas 01:35-25		/* tops20an	;network absolute socket privilege */


/* outmoded names for bits in directory mode word - use cd_xxx */
/* equivalents */

#define MD_fo cd_dir		/* files only directory */
#define MD_sa cd_ana		/* string account allowed */
#define MD_rlm cd_rlm		/* repeat login message */


/* fdb definitions */


#define FBhdr 00		/* header word */
#define FB_len 0177:35-35	/* length of this fdb */
#define FBctl 01		/* flags */
#define FB_tmp 01:35-0		/* file is temporary */
#define FB_prm 01:35-1		/* file is permanent */
#define FB_nex 01:35-2		/* file does not have an extension yet */
#define FB_del 01:35-3		/* file is deleted */
#define FB_nxf 01:35-4		/* file is nonexistent */
#define FB_lng 01:35-5		/* file is a long file */
#define FB_sht 01:35-6		/* file has compressed page table  */
#define FB_dir 01:35-7		/* file is a directory file */
#define FB_nod 01:35-8		/* file is not to be dumped by backup system */
#define FB_bat 01:35-9		/* file has at least one bad page in it */
#define FB_sdr 01:35-10		/* this directory has subdirectories */
#define FB_arc 01:35-11		/* file has archive status */
#define FB_inv 01:35-12		/* file is invisible */
#define FB_off 01:35-13		/* file is offline */
#define FB_fcf 017:35-17	/* file class field */
#define FBnrm 00	 	/* non-rms */
#define FBrms 01	 	/* rms files */
#define FBexl 02		/* link to fdb of next extension */
#define FBadr 03		/* disk address of index block */
#define FBprt 04		/* protection of the file */
#define FBcre 05		/* time and date of last write */
#define FBuse 06		/* last writer ,, author (obs) */
#define FBaut 06		/* pointer to author string */
#define FBgen 07		/* generation ,, dir # */
#define FB_gen 0777777:35-17	/* generation number */
#define FBdrn 07		/* generation ,, dir # */
#define FB_drn 0777777	 	/* dir number */
#define FBact 010		/* account */
#define FBbyv 011		/* retention+byte size+mode ,, # of pages */
#define FB_ret 077:35-5		/* retention count */
#define FB_bsz 077:35-11	/* byte size */
#define FB_mod 017:35-17	/* last openf mode */
#define FB_pgc 0777777		/* page count */
#define FBsiz 012		/* eof pointer */
#define FBcrv 013		/* time and date of creation of file */
#define FBwrt 014		/* time and date of last user write */
#define FBref 015		/* time and date of last non-write access */
#define FBcnt 016		/* # of writes ,, # of references */
#define FBbk0 017		/* backup words (5) */
#define FBbk1 20		/* */
#define FBbk2 21		/* */
#define FBbbt 022		/* bits,,#pages in offline file */
#define AR_rar 01:35-1		/* request archive by user */
#define AR_riv 01:35-2		/* request invol migration by system */
#define AR_ndl 01:35-3		/* do not delete contents of file when archived */
#define AR_nar 01:35-4		/* please don't migrate this file */
#define AR_exm 01:35-5		/* file exempt from migration */
#define AR_1st 01:35-6		/* 1st pass of archive/collection run complete */
#define AR_rfl 01:35-7		/* retrieve failed */
#define AR_wrn 01:35-8		/* user warned of approaching expiration */
#define AR_rsn 07:35-17		/* reason pushed offline */
#define ARexp 01	 	/* file expired */
#define ARarr 02	 	/* archive was requested */
#define ARrir 03	 	/* migration was requested */
#define AR_psz 0777777		/* rh is pg count when file went offline */
#define FBnet 023		/* on-line expiration date/interval */
#define FBusw 024		/* user settable word */
#define FBgnl 025		/* link to next generation file */
#define FBnam 026		/* pointer to name block */
#define FBext 027		/* pointer to extension block */
#define FBlwr 030		/* pointer to last writer string */
#define FBtdt 031		/* archive or collection date & time */
#define FBfet 032		/* offline expiration date/interval */
#define FBtp1 033		/* tape id for run 1 tape */
#define FBss1 034		/* saveset #,,tape file # for run 1 tape */
#define FBtp2 035		/* tape id for run 2 tape */
#define FBss2 036		/* saveset #,,tape file # for run 2 tape */

#define FBln0 030		/* length of version 0 fdb */
#define FBln1 037		/* length of version 1 fdb */
#define FBlxt 037		/* minimum length for archive/virtual dsk sys */
#define FBlen 037		/* length of the fdb */

/* card reader definitions */

#define CRilc "\"		/* illegal character code */

/* a word is distinguished from a byte pointer by the value 5 in bits 0-2 */
/* use these definitions to test for a number as follows: */
/* load ac,nmflg,loc */
/* caie ac,numval */

#define NMflg 07:35-2		/* */
#define NUmval 5		/* */


/* magtape label types */

#define LTunl 01		/* unlabeled */
#define LTans 02		/* ansi standard */
#define LTebc 03		/* ebcdic */
#define LTt20 04		/* tops-20 */
#define LTmax 04		/* maximum label type */

/* magtape drive types */

#define TMdr9 01		/* 9-track */
#define TMdr7 02		/* 7-track */
#define TMdmx 02		/* maximum drive-type value */



/* definitions for communications protocols */

/* define the supported protocol types */

#define VN20f 00		/* rsx20f protocol */
#define VNmcb 01		/* mcb decnet protocol */
#define VNddc 02		/* ddcmp protocol */
#define VNmop 03		/* mop (ddcmp maintenance) mode */
#define VNcnl 04		/* controller loopback */
#define VNcbl 05		/* cable loopback */

/* define bits used when reloading an -11 */

#define RM_rom 01:35-0		/* if set, activate rom */

/* *********************************************** */
/* general field and value definitions */
/* used by tops20an jsys's */
/* *********************************************** */

/* states of a connection in arpanet ncp */
/* returned in b0-b3 of gdsts on a net connection */
/* also available in a getab, but that's not the preferred way */
/* to read them, if you have a jfn for the connection. */

#define NSczd 001		/* closed */
#define NSpnd 002		/* pending */
#define NSlsn 003		/* listening */
#define NSrcr 004		/* request for connection received */
#define NScw1 005		/* close wait sub one (ncp close) */
#define NSrcs 006		/* request for connection sent */
#define NSopn 007		/* opened */
#define NScsw 010		/* close wait (ncp close) */
#define NSdtw 011		/* final data wait */
#define NSrf1 012		/* rfnm wait sub one (normal ncp close) */
#define NSczw 013		/* close wait (program close) */
#define NSrf2 014		/* rfnm wait sub two (unexpected ncp close) */
#define NSfre 016		/* free */

/* host status bits */

#define HS_up 01:35-0		/* host is up */
#define HS_val 01:35-1		/* valid status */
#define HS_day 07:35-4		/* day when up if down */
#define HS_hr 037:35-9		/* hour */
#define HS_min 017:35-13	/* 5 min interval */
#define HS_rsn 017:35-17	/* reason */
#define HS_srv 01:35-18		/* host is server */
#define HS_usr 01:35-19		/* host is user */
#define HS_nck 01:35-20		/* host name string was nickname */
#define HS_sty 077:35-26	/* system type mask */
#define HS_new 01:35-27		/* host does new protocol */
#define HS_nam 01:35-28		/* host has name */

#define HS10x 01:35-26		/* tenex */
#define HSits 02:35-26		/* its */
#define HSdec 03:35-26		/* tops-10 */
#define HStip 04:35-26		/* tip */
#define HSmtp 05:35-26		/* mtip */
#define HSelf 06:35-26		/* elf */
#define HSant 07:35-26		/* ants */
#define HSmlt 010:35-26		/* multics */
#define HSt20 011:35-26		/* tops-20 */
#define HSunx 012:35-26		/* unix */
