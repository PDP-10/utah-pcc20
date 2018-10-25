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
