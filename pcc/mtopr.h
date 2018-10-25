
#define MOlvf 032	 		/* load device's vfu */
#define MOrvf 033	 		/* read vfu file name */
#define MOltr 034	 		/* load translation ram */
#define MOrtr 035	 		/* read ram file name */
#define MOsts 036	 		/* set software status */
#define MOrst 037	 		/* read software status */
#define    MO_lpc 01	 		/* page counter overflow */
#define    MO_lci 02	 		/* character interrupt (hard error) */
#define    MO_lvf 04	 		/* vfu error.  paper must be re-aligned */
#define    MO_lvu 020	 		/* line printer has optical vfu */
#define    MO_rpe 040	 		/* ram parity error */

#define    MO_rck 01	 		/* read check */
#define    MO_pck 02	 		/* pick check */
#define    MO_sck 04	 		/* stack check */
#define    MO_hem 010	 		/* hopper empty */
#define    MO_sfl 020	 		/* stacker full */

#define    MO_fnx 01:35-17		/* non-existent device */
#define    MO_ol 01:35-16			/* device is off-line */
#define    MO_he 01:35-15			/* hardware error */
#define    MO_ser 01:35-14		/* software error */
#define    MO_iop 01:35-13		/* i/o in progress */
#define    MO_eof 01:35-12		/* end of file */
/*   1b11				;reserved */
#define    MO_fer 01:35-10		/* fatal error */
#define    MO_lcp 01:35-0			/* lower case printer */
#define    MO_rld 01:35-1			/* front-end was reloaded */
#define MOflo 040	 		/* flush output */

/* see setjb for various argument values */

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

/* net mtopr numbers */

#define MOacp 020	       /* tops20an	;accept connection on socket */
#define MOsnd 021	       /* tops20an	;send all curently buffered bytes */
#define MOsin 022	       /* tops20an	;send ins/inr command */
#define MOain 024	       /* tops20an	;assign ins/inr and fsm psi channels */
#define    MO_nin 077:35-5      /* tops20an	;ins/inr software interrupt channel */
#define    MO_fsm 077:35-17     /* tops20an	;fsm change of state interrupt channel */


/* definitions for decnet */

#define MOacn 024	 		/* assign connect interrupt channel */
#define    MO_cdn 0777:35-8		/* connect interrupt channel */
#define    MO_ina 0777:35-17		/* interrupt message channel */
#define    MO_dav 0777:35-26		/* data available channel */
#define      MOnci 0777	 	/* no change */
#define      MOcia 0776	 	/* clear interrupt assignment */

#define MOrls 025	 		/* read link status */
#define    MO_con 01:35-0			/* link is connected */
#define    MO_srv 01:35-1			/* link is a server */
#define    MO_wfc 01:35-2			/* waiting for a connect */
#define    MO_wcc 01:35-3			/* waiting for this link to confirm */
#define    MO_eom 01:35-4			/* eom present in input buffer */
#define    MO_abt 01:35-5			/* connection aborted */
#define    MO_syn 01:35-6			/* synch di recieved */
#define    MO_int 01:35-7			/* int message available */
#define    MO_lwc 01:35-8			/* link was connected */
#define MOrhn 026	 		/* read host name */
#define MOrtn 027	 		/* read task name */
#define MOrus 030	 		/* read user data */
#define MOrpw 031	 		/* read password */
#define MOrac 032	 		/* read account */
#define MOrda 033	 		/* read optional data */
#define MOrcn 034	 		/* read connect object number */
#define MOrim 035	 		/* read interrupt message */
#define MOsim 036	 		/* send interrupt message */
#define MOrod 037	 		/* read obj-desc of connection */
#define MOclz 040	 		/* close/reject a connection */
#define MOcc 041	 		/* accept a connection */
#define MOrss 042	 		/* read segment size */

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
