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
