/* *********************************************** */
/* general field and value definitions */
/* used by many jsyses */
/* *********************************************** */


/* general fork handles */

#define FHslf 0400000	 		/* self */
#define FHsup <z -1>			/* superior */
#define FHtop <z -2>			/* top in job */
#define FHsai <z -3>			/* self and inferiors */
#define FHinf <z -4>			/* inferiors */
#define FHjob <z -5>			/* all in job */


/* fields of jfn mode word */

#define TT_osp 01:35-0			/* output suppress */
#define TT_mff 01:35-1			/* mechanical formfeed present */
#define TT_tab 01:35-2			/* mechanical tab present */
#define TT_lca 01:35-3			/* lower case capabilities present */
#define TT_len 0177:35-10		/* page length */
#define TT_wid 0177:35-17		/* page width */
#define TT_wak 017:35-23		/* wakeup field */
#define TT_wk0 01:35-18			/* wakeup class 0 (unused) */
#define TT_ign 01:35-19			/* ignore tt_wak on sfmod */
#define TT_wkf 01:35-20			/* wakeup on formating control chars */
#define TT_wkn 01:35-21			/* wakeup on non-formatting controls */
#define TT_wkp 01:35-22			/* wakeup on punctuation */
#define TT_wka 01:35-23			/* wakeup on alphanumerics */
#define TT_eco 01:35-24			/* echos on */
#define TT_ecm 01:35-25			/* echo mode */
#define TT_alk 01:35-26			/* allow links */
#define TT_aad 01:35-27			/* allow advice (not implemented) */
#define TT_dam 03:35-29			/* data mode */
#define TTbin 00	 		/* binary */
#define TTasc 01	 		/* ascii */
#define TTato 02	 		/* ascii and translate output only */
#define TTate 03	 		/* ascii and translate echos only */
#define TT_uoc 01:35-30			/* upper case output control */
#define TT_lic 01:35-31			/* lower case input control */
#define TT_dum 03:35-33			/* duplex mode */
#define TTfdx 00	 		/* full duplex */
#define TT0dx 01	 		/* not used, reserved */
#define TThdx 02	 		/* half duplex (character) */
#define TTldx 03	 		/* line half duplex */
#define TT_pgm 01:35-34			/* page mode */
#define TT_car 01:35-35			/* carrier state */



/* directory protection definitions (3 6-bit fields: owner, group, world) */

#define DP_rd 040	 		/* reading directory is allowed */
#define DP_cn 010	 		/* connect to dir, or change prot/account */
#define DP_cf 04	 		/* creating files in dir is allowed */

/* file protection definitions (3 6-bit fields: owner, group, world) */

#define FP_dir 02	 		/* directory listing */
#define FP_app 04	 		/* append */
#define FP_ex 010	 		/* execute */
#define FP_wr 020	 		/* write */
#define FP_rd 040	 		/* read */


/* input and output identifiers */

#define PRiin 0100	 		/* primary input */
#define PRiou 0101	 		/* primary output */
#define NUlio 0377777	 		/* null designator */
#define CTtrm 0777777	 		/* job's controlling terminal */
#define DVdes 0600000	 		/* universal device code */
#define TTdes 0400000	 		/* universal terminal code */


/* magtape device status bits */

#define MT_ilw 01:35-18			/* illegal write */
#define MT_dve 01:35-19			/* device error */
#define MT_dae 01:35-20			/* data error */
#define MT_ser 01:35-21			/* suppress error recovery procedures */
#define MT_eof 01:35-22			/* eof (file mark) */
#define MT_irl 01:35-23			/* incorrect record length */
#define MT_bot 01:35-24			/* beginning of tape */
#define MT_eot 01:35-25			/* end of tape */
#define MT_evp 01:35-26			/* even parity */
#define MT_den 03:35-28			/* density (0 is 'normal') */
#define MTlod 01	 		/* low density (200 bpi) */
#define MTmed 02	 		/* medium density (556 bpi) */
#define MThid 03	 		/* high density (800 bpi) */
#define MT_cct 07:35-31			/* character counter */
#define MT_nsh 01:35-32			/* data mode or density not supported by hardware */


/* device data modes */

#define DMasc 01	 		/* ascii */
#define DMimg 010	 		/* image */
#define DMimb 013	 		/* image binary */
#define DMbin 014	 		/* binary */


/* defined psi channels */

#define ICaov 06	 		/* arithmetic overflow */
#define ICfov 07	 		/* floating overflow */
#define ICpov 09	 		/* pdl overflow */
#define ICeof 010	 		/* end of file */
#define ICdae 011	 		/* data error */
#define ICqta 012	 		/* quota/disk exceeded */
#define ICtod 014	 		/* time of day (not implemented) */
#define ICili 015	 		/* illeg instruction */
#define ICird 016	 		/* illegal read */
#define ICiwr 017	 		/* illegal write */
#define ICiex 018	 		/* illegal execute (not implemented) */
#define ICift 019	 		/* inferior fork termination */
#define ICmse 020	 		/* machine size exceeded */
#define ICtru 021	 		/* trap to user (not implemented) */
#define ICnxp 022	 		/* nonexistent page referenced */


/* terminal type numbers */

#define TT33 00				/* model 33 */
#define TT35 01				/* model 35 */
#define TT37 02				/* model 37 */
#define TTexe 03	 		/* execuport */
#define TTdtc 02	 		/* diablo or dtc (tty 37 de-implemented) */
#define TTexe 03	 		/* execuport */
#define TTgtt 04	 		/* glass teletype */
#define TTpe 05				/* perkin elmer fox */
#define TTadm 06	 		/* lsi adm3a */
#define TTtel 07	 		/* teleray 1061 */
#define TTdef 8				/* default */
#define TTidl 9				/* ideal */
#define TTv05 10			/* vt05 */
#define TTv50 11			/* vt50 */
#define TTl30 12			/* la30 */
#define TTg40 13			/* gt40 */
#define TTl36 14			/* la36 */
#define TTv52 15			/* vt52 */
#define TT100 16			/* vt100 */
#define TTl38 17			/* la38 */
#define TT120 18			/* la120 */
#define TThp 24				/* hp 2645/2621 */

/* defined terminal codes */

#define TIcbk 00	 		/* break */
#define TIcca 01	 		/* ^a */
#define TIccb 02	 		/* ^b */
#define TIccc 03	 		/* ^c */
#define TIccd 04	 		/* */
#define TIcce 05	 		/* ^e */
#define TIccf 06	 		/* ^f */
#define TIccg 07	 		/* ^g */
#define TIcch 08	 		/* ^h */
#define TIcci 09	 		/* ^i */
#define TIccj 010	 		/* ^j */
#define TIcck 011	 		/* ^k */
#define TIccl 012	 		/* ^l */
#define TIccm 013	 		/* ^m */
#define TIccn 014	 		/* ^n */
#define TIcco 015	 		/* ^o */
#define TIccp 016	 		/* ^p */
#define TIccq 017	 		/* ^q */
#define TIccr 018	 		/* ^r */
#define TIccs 019	 		/* ^s */
#define TIcct 020	 		/* ^t */
#define TIccu 021	 		/* ^u */
#define TIccv 022	 		/* ^v */
#define TIccw 023	 		/* ^w */
#define TIccx 024	 		/* ^x */
#define TIccy 025	 		/* ^y */
#define TIccz 026	 		/* ^z */
#define TIces 027	 		/* esc */
#define TIcrb 028	 		/* rubout */
#define TIcsp 029	 		/* space */
#define TIcrf 030	 		/* carrier off */
#define TIcti 031	 		/* typein */
#define TIcto 032	 		/* typeout */




/* capabilities */

#define SC_ctc 01:35-0			/* control-c */
#define SC_gtb 01:35-1			/* getab */
#define SC_mmn 01:35-2			/* map monitor */
#define SC_log 01:35-3			/* logging functions */
#define SC_mpp 01:35-4			/* map privileged pages */
#define SC_sdv 01:35-5			/* special devices */
#define SC_sct 01:35-6			/* assign tty as controlling for fork (sctty) */

#define SC_sup 01:35-9			/* superior access */

#define SC_frz 01:35-17			/* freeze on terminating conditions */

#define SC_whl 01:35-18			/* wheel */
#define SC_opr 01:35-19			/* operator */
#define SC_cnf 01:35-20			/* confidential information access */
#define SC_mnt 01:35-21			/* maintenance */
#define SC_ipc 01:35-22			/* ipcf privileges */
#define SC_enq 01:35-23			/* enq/deq privileges */
#define SC_nwz 01:35-24			/* tops20an	;net wizard privileges (asnsq, etc.) */
#define SC_nas 01:35-25			/* tops20an	;network absolute socket privilege */


/* outmoded names for bits in directory mode word - use cd_xxx */
/* equivalents */

#define MD_fo cd_dir			/* files only directory */
#define MD_sa cd_ana			/* string account allowed */
#define MD_rlm cd_rlm			/* repeat login message */


/* fdb definitions */


#define FBhdr 00	 		/* header word */
#define FB_len 0177:35-35		/* length of this fdb */
#define FBctl 01	 		/* flags */
#define FB_tmp 01:35-0			/* file is temporary */
#define FB_prm 01:35-1			/* file is permanent */
#define FB_nex 01:35-2			/* file does not have an extension yet */
#define FB_del 01:35-3			/* file is deleted */
#define FB_nxf 01:35-4			/* file is nonexistent */
#define FB_lng 01:35-5			/* file is a long file */
#define FB_sht 01:35-6			/* file has compressed page table  */
#define FB_dir 01:35-7			/* file is a directory file */
#define FB_nod 01:35-8			/* file is not to be dumped by backup system */
#define FB_bat 01:35-9			/* file has at least one bad page in it */
#define FB_sdr 01:35-10			/* this directory has subdirectories */
#define FB_arc 01:35-11			/* file has archive status */
#define FB_inv 01:35-12			/* file is invisible */
#define FB_off 01:35-13			/* file is offline */
#define FB_fcf 017:35-17		/* file class field */
#define FBnrm 00			/* non-rms */
#define FBrms 01			/* rms files */
#define FBexl 02	 		/* link to fdb of next extension */
#define FBadr 03	 		/* disk address of index block */
#define FBprt 04	 		/* protection of the file */
#define FBcre 05	 		/* time and date of last write */
#define FBuse 06	 		/* last writer ,, author (obs) */
#define FBaut 06	 		/* pointer to author string */
#define FBgen 07	 		/* generation ,, dir # */
#define FB_gen 0777777:35-17		/* generation number */
#define FBdrn 07	 		/* generation ,, dir # */
#define FB_drn 0777777			/* dir number */
#define FBact 010	 		/* account */
#define FBbyv 011	 		/* retention+byte size+mode ,, # of pages */
#define FB_ret 077:35-5			/* retention count */
#define FB_bsz 077:35-11		/* byte size */
#define FB_mod 017:35-17		/* last openf mode */
#define FB_pgc 0777777			/* page count */
#define FBsiz 012	 		/* eof pointer */
#define FBcrv 013	 		/* time and date of creation of file */
#define FBwrt 014	 		/* time and date of last user write */
#define FBref 015	 		/* time and date of last non-write access */
#define FBcnt 016	 		/* # of writes ,, # of references */
#define FBbk0 017	 		/* backup words (5) */
#define FBbk1 20			/*  */
#define FBbk2 21			/*  */
#define FBbbt 022	 		/* bits,,#pages in offline file */
#define AR_rar 01:35-1			/* request archive by user */
#define AR_riv 01:35-2			/* request invol migration by system */
#define AR_ndl 01:35-3			/* do not delete contents of file when archived */
#define AR_nar 01:35-4			/* please don't migrate this file */
#define AR_exm 01:35-5			/* file exempt from migration */
#define AR_1st 01:35-6			/* 1st pass of archive/collection run complete */
#define AR_rfl 01:35-7			/* retrieve failed */
#define AR_wrn 01:35-8			/* user warned of approaching expiration */
#define AR_rsn 07:35-17			/* reason pushed offline */
#define ARexp 01			/* file expired */
#define ARarr 02			/* archive was requested */
#define ARrir 03			/* migration was requested */
#define AR_psz 0777777			/* rh is pg count when file went offline */
#define FBnet 023	 		/* on-line expiration date/interval */
#define FBusw 024	 		/* user settable word */
#define FBgnl 025	 		/* link to next generation file */
#define FBnam 026	 		/* pointer to name block */
#define FBext 027	 		/* pointer to extension block */
#define FBlwr 030	 		/* pointer to last writer string */
#define FBtdt 031	 		/* archive or collection date & time */
#define FBfet 032	 		/* offline expiration date/interval */
#define FBtp1 033	 		/* tape id for run 1 tape */
#define FBss1 034	 		/* saveset #,,tape file # for run 1 tape */
#define FBtp2 035	 		/* tape id for run 2 tape */
#define FBss2 036	 		/* saveset #,,tape file # for run 2 tape */

#define FBln0 030	 		/* length of version 0 fdb */
#define FBln1 037	 		/* length of version 1 fdb */
#define FBlxt 037	 		/* minimum length for archive/virtual dsk sys */
#define FBlen 037	 		/* length of the fdb */

/* card reader definitions */

#define CRilc "\"			/* illegal character code */

/* a word is distinguished from a byte pointer by the value 5 in bits 0-2 */
/* use these definitions to test for a number as follows: */
/* load ac,nmflg,loc */
/* caie ac,numval */

#define NMflg 07:35-2			/*  */
#define NUmval 5			/*  */


/* magtape label types */

#define LTunl 01	 		/* unlabeled */
#define LTans 02	 		/* ansi standard */
#define LTebc 03	 		/* ebcdic */
#define LTt20 04	 		/* tops-20 */
#define LTmax 04	 		/* maximum label type */

/* magtape drive types */

#define TMdr9 01	 		/* 9-track */
#define TMdr7 02	 		/* 7-track */
#define TMdmx 02	 		/* maximum drive-type value */



/* definitions for communications protocols */

/* define the supported protocol types */

#define VN20f 00	 		/* rsx20f protocol */
#define VNmcb 01	 		/* mcb decnet protocol */
#define VNddc 02	 		/* ddcmp protocol */
#define VNmop 03	 		/* mop (ddcmp maintenance) mode */
#define VNcnl 04	 		/* controller loopback */
#define VNcbl 05	 		/* cable loopback */

/* define bits used when reloading an -11 */

#define RM_rom 01:35-0			/* if set, activate rom */

/* *********************************************** */
/* general field and value definitions */
/* used by tops20an jsys's */
/* *********************************************** */

/* states of a connection in arpanet ncp */
/* returned in b0-b3 of gdsts on a net connection */
/* also available in a getab, but that's not the preferred way */
/* to read them, if you have a jfn for the connection. */

#define NSczd 001	 		/* closed */
#define NSpnd 002	 		/* pending */
#define NSlsn 003	 		/* listening */
#define NSrcr 004	 		/* request for connection received */
#define NScw1 005	 		/* close wait sub one (ncp close) */
#define NSrcs 006	 		/* request for connection sent */
#define NSopn 007	 		/* opened */
#define NScsw 010	 		/* close wait (ncp close) */
#define NSdtw 011	 		/* final data wait */
#define NSrf1 012	 		/* rfnm wait sub one (normal ncp close) */
#define NSczw 013	 		/* close wait (program close) */
#define NSrf2 014	 		/* rfnm wait sub two (unexpected ncp close) */
#define NSfre 016	 		/* free */

/* host status bits */

#define HS_up 01:35-0			/* host is up */
#define HS_val 01:35-1			/* valid status */
#define HS_day 07:35-4			/* day when up if down */
#define HS_hr 037:35-9			/* hour */
#define HS_min 017:35-13		/* 5 min interval */
#define HS_rsn 017:35-17		/* reason */
#define HS_srv 01:35-18			/* host is server */
#define HS_usr 01:35-19			/* host is user */
#define HS_nck 01:35-20			/* host name string was nickname */
#define HS_sty 077:35-26		/* system type mask */
#define HS_new 01:35-27			/* host does new protocol */
#define HS_nam 01:35-28			/* host has name */

#define HS10x 01:35-26			/* tenex */
#define HSits 02:35-26			/* its */
#define HSdec 03:35-26			/* tops-10 */
#define HStip 04:35-26			/* tip */
#define HSmtp 05:35-26			/* mtip */
#define HSelf 06:35-26			/* elf */
#define HSant 07:35-26			/* ants */
#define HSmlt 010:35-26			/* multics */
#define HSt20 011:35-26			/* tops-20 */
#define HSunx 012:35-26			/* unix */
