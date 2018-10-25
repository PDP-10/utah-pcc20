/* fields of jfn mode word */

#define TT_osp 01:35-0			/* output suppress */
#define TT_mff 01:35-1			/* mechanical formfeed present */
#define TT_tab 01:35-2			/* mechanical tab present */
#define TT_lca 01:35-3			/* lower case capabilities present */
#define TT_len 0177:35-10			/* page length */
#define TT_wid 0177:35-17			/* page width */
#define TT_wak 017:35-23			/* wakeup field */
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


