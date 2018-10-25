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
