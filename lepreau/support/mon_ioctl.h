/*	Created from monsym.mac, 10/23/81  J.Lepreau, Univ of Utah 	*/

/***		most recent edit history
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


/* mtopr - function codes */
/* see setjb for various argument values */

#define MOcle 00	 		/* clear errors */
#define MOnop 031	 		/* nop (wait for activity to stop) */
#define MOrew 01	 		/* rewind */
#define MOeof 03	 		/* write eof */
#define MOdte 04	 		/* assign fe device to a dte */
#define MOfwr 06	 		/* forward space record */
#define MObkr 07	 		/* backspace record */
#define MOrul 011	 		/* rewind and unload */
#define MOers 013	 		/* erase tape */
#define MOfwf 016	 		/* forward space file */
#define MObkf 017	 		/* backspace file */
#define MOspd 026	 		/* set tty speed (for kl only) */
#define MOrsp 027	 		/* read line speed (for kl only) */
#define    MO_rmt 01:35-0			/* flag to say line is remote */
#define    MO_aut 01:35-1			/* flag to say line is "auto" speed */

#define MOsnt 034	 		/* set tty non-terminal status */
#define    MOsmn 01	 		/* no system messages(i.e. suppress) */
#define    MOsmy 00	 		/* yes system messages(default) */
#define MOrnt 035	 		/* read tty non-terminal status */

/* pty mtopr numbers */

#define MOapi 024	 		/* assign pty interrupt channels */
#define    MO_wfi 01:35-0			/* enable waiting for input */
#define    MO_oir 01:35-1			/* enable output is waiting */
#define    MO_sic 077:35-17		/* software interrupt channel */
#define MOpih 025	 		/* test pty input hungry */
#define    MOnwi 00	 		/* not waiting for input */
#define    MOwfi -1			/* waiting for input */
#define MObat 026	 		/* set batch bit */
#define   MOjcb 01	 		/* job controlled by batch */
#define   MOncb 00	 		/* job not controlled by batch */


/* tty mode definitions */

#define MOrlw 030	 		/* read width */
#define MOslw 031	 		/* set width */
#define MOrll 032	 		/* read length */
#define MOsll 033	 		/* set length */
#define MOsig 036	 		/* set "ignore input when inactive" bit */
#define MOrbm 037	 		/* read 128 character break mask */

#define 	MO_wn1 (0776117<<18|0777740)	/* bit definitions for non-formatting control  */
#define 	MO_wn2 00	 	/* for ascii codes 40-777 */
#define 	MO_wn3 00	 	/* for ascii codes 100-137 */
#define 	MO_wn4 020	 	/* for ascii codes 137-177 */

#define 	MO_wf1 (0001260<<18|0000420)	/* formatting control bits  */
#define 	MO_wf2 00	 	/* for ascii codes 40-77 */
#define 	MO_wf3 00	 	/* for ascii codes 100-137 */
#define 	MO_wf4 020	 	/* for ascii codes 140-177 */

#define 	MO_wp1 (0000400<<18|0400)	/* punctuation bit definitions  */
#define 	MO_wp2 (0777774<<18|0001760)	/*  for ascii codes 40-77  */
#define 	MO_wp3 (0400000<<18|0000760)	/*  for ascii codes 100-137  */
#define 	MO_wp4 (0400000<<18|0000760)	/*  for ascii codes 140-177  */
 
#define 	MO_wa1 0400	 	/* alphanumerics definitions */
#define 	MO_wa2 (0000003<<18|0776000)	/*  for ascii codes 40-77  */
#define 	MO_wa3 (0377777<<18|0777000)	/*  for ascii codes 100-137  */
#define 	MO_wa4 (0377777<<18|0777020)	/*  for ascii codes 140-177 */
#define MOsbm 040	 		/* set 128 character break mask */
#define MOrfw 041	 		/* read field width */
#define MOsfw 042	 		/* set field width */
#define MOxof 043	 		/* set/clear xoff/xon handling */
#define 	MOoff 00	 	/* turn off xon/xoff processing */
#define 	MOonx 01	 	/* turn on xon/xoff processing */
#define MOrxo 044	 		/* read value of xoff bit */
#define MOslc 045	 		/* set line counter */
#define MOrlc 046	 		/* read line counter */
#define MOslm 047	 		/* set line counter maximum */
#define MOrlm 050	 		/* read line counter maximum */
#define MOtps 051	 		/* psi for non-controlling terminal  */

/* definitions for ats */

/* function codes for mtopr are in column 1 */

#define MOamo 01	 		/* set mode word */
#define 	MOamm 01	 	/* message mode */
#define 	MOadm 02	 	/* data mode */
#define MOaat 02	 		/* acquire terminal */
#define 	MO_aer 01:35-0		/* htn field contains an error code */
#define MOasi 03	 		/* enable interrupts */
#define 	MO_ifl 0777:35-8		/* function to be performed */
#define 	  MOaai 00	 	/* assign interrupt channel */
#define 	  MOadi 01	 	/* deassign interrupt channel */
#define 	MO_iev 0777:35-17		/* event being assigned or deassigned */
#define 	  MOadt 00	 	/* data arrival */
#define 	  MOast 01	 	/* status arrival */
#define 	MO_ach 0777777:35-35	/* channel number */
#define MOrcd 04	 		/* get status */
#define 	MO_wdv 0777:35-35		/* which devices to report on */
#define 	  MOald 00	 	/* all terminals */
#define 	  MOchg 01	 	/* terminals whose status has changed */
#define 	  MOlst 02	 	/* terminals specified in list */
#define 	MO_arm 01:35-0		/* ask the resource manager */
#define 	MO_mda 01:35-1		/* more data available for this jfn */
#define 		AT_opn 01:35-0	/* htn is open and usable */
#define 		AT_tcl 01:35-1	/* nrm closed terminal via status-report */
#define 		AT_dht 01:35-2	/* deassigning htn */
#define 		AT_txf 01:35-3	/* terminal is xoff'd */
#define 		AT_und 01:35-4	/* device requested is undefined */
#define 		AT_nav 01:35-5	/* device requested is not available */
#define 		AT_ofl 01:35-6	/* device requested is offline */
#define 		AT_ful 01:35-7	/* server is full */
#define 		AT_uns 01:35-8	/* device type is unsupported */
#define 		AT_rej 01:35-9	/* node nrm rejected the request */
#define 		AT_mie 01:35-10	/* monitor internal error (node or host) */
#define 		AT_stf 01:35-11	/* vt62 start-up failed */
#define 		AT_crj 01:35-12	/* connection was rejected */
#define 		AT_ndp 01:35-13	/* data pipe is not open */
#define 		AT_ser 0777777:35-35 /* status report error code (18 bits) */
#define MOade 05	 		/* deassign terminal */
#define 	MO_aab 01:35-0		/* don't send remaining data */

/* function codes for aydin display mtopr */

#define MOfle 00	 		/* flush errors */
#define MOrer 01	 		/* return aydin error code */
#define MOwat 02	 		/* wait for activity to stop */
#define 	MO_rwc 0777777:35-17	/* remaining word count */
#define 	MO_ler 0777777:35-35	/* last aydin error code */


/* *********************************************** */
/* general field and value definitions */
/* used by many jsyses */
/* *********************************************** */


/* general fork handles */

#define FHslf 0400000	 		/* self */
#define FHsup -1			/* superior */
#define FHtop -2			/* top in job */
#define FHsai -3			/* self and inferiors */
#define FHinf -4			/* inferiors */
#define FHjob -5			/* all in job */


/* fields of jfn mode word */

#define TT_osp 01:35-0			/* output suppress */
#define TT_mff 01:35-1			/* mechanical formfeed present */
#define TT_tab 01:35-2			/* mechanical tab present */
#define TT_lca 01:35-3			/* lower case capabilities present */
#define TT_len 0177:35-10			/* page length */
#define TT_wid 0177:35-17			/* page width */
#define TT_wak 017:35-23			/* wakeup field */
#define TT_wk0 01:35-18			/* wakeup class 0 (unused) */
#define TT_ign 01:35-19			/* ignore tt%wak on sfmod */
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


/* terminal type numbers */

#define TT33 0	 		/* model 33 */
#define TT35 1	 		/* model 35 */
#define TT37 2	 		/* model 37 */
#define TTexe 3	 		/* execuport */
#define TTdtc 2	 		/* diablo or dtc (tty 37 de-implemented) */
#define TTexe 3	 		/* execuport */
#define TTgtt 4	 		/* glass teletype */
#define TTpe 5	 		/* perkin elmer fox */
#define TTadm 6	 		/* lsi adm3a */
#define TTtel 7	 		/* teleray 1061 */
#define TTdef 8			/* default */
#define TTidl 9			/* ideal */
#define TTv05 10			/* vt05 */
#define TTv50 11			/* vt50 */
#define TTl30 12			/* la30 */
#define TTg40 13			/* gt40 */
#define TTl36 14			/* la36 */
#define TTv52 15			/* vt52 */
#define TT100 16			/* vt100 */
#define TTl38 17			/* la38 */
#define TT120 18			/* la120 */
#define TThp 24			/* hp 2645/2621 */

/* defined terminal codes */

#define TIcbk 0	 		/* break */
#define TIcca 1	 		/* ^a */
#define TIccb 2	 		/* ^b */
#define TIccc 3	 		/* ^c */
#define TIccd 4	 		/*  */
#define TIcce 5	 		/* ^e */
#define TIccf 6	 		/* ^f */
#define TIccg 7	 		/* ^g */
#define TIcch 8	 		/* ^h */
#define TIcci 9	 		/* ^i */
#define TIccj 10	 		/* ^j */
#define TIcck 11	 		/* ^k */
#define TIccl 12	 		/* ^l */
#define TIccm 13	 		/* ^m */
#define TIccn 14	 		/* ^n */
#define TIcco 15	 		/* ^o */
#define TIccp 16	 		/* ^p */
#define TIccq 17	 		/* ^q */
#define TIccr 18	 		/* ^r */
#define TIccs 19	 		/* ^s */
#define TIcct 20	 		/* ^t */
#define TIccu 21	 		/* ^u */
#define TIccv 22	 		/* ^v */
#define TIccw 23	 		/* ^w */
#define TIccx 24	 		/* ^x */
#define TIccy 25	 		/* ^y */
#define TIccz 26	 		/* ^z */
#define TIces 27	 		/* esc */
#define TIcrb 28	 		/* rubout */
#define TIcsp 29	 		/* space */
#define TIcrf 30	 		/* carrier off */
#define TIcti 31	 		/* typein */
#define TIcto 32	 		/* typeout */
