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
