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
