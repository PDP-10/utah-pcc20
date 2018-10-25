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
#define ARclr 00		/* clear the request */
#define ARset 01		/* set the request */
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

#define REtm 00			/* send retrieve message */
#define REtr 00			/* normal retrieve */
#define REtrw 01		/* user waiting for retrieve */
#define NOtm 01			/* send notification message */
#define FLxp 00			/* archive file expunged */
#define AClr 01			/* archive status cleared */

/* atnvt		      ;tops20an */

#define AN_ntp 01:35-2		/* tops20an	;new telnet protocol */


/* atach */

#define AT_ccj 01:35-0		/* ^c job when attached */
#define AT_nat 01:35-1		/* no attach */
#define AT_trm 01:35-2		/* attach job to terminal in register 4 */
#define AT_job 0777777:35-35	/* job number */
