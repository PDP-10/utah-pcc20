/* This is monsym.h, edited from <bcpl>monsym.bcp by J.Lepreau 2/81 (whew) */

/********* deleted for host 20 *******
static int _shl18 = 18;	/* for cross-compiling so pcc won't fold; make it a */
			/* define later.				    */

#define _shl18 18	/* cause not cross-compiling */

	/* JSYS SPECIFIC ARGUMENTS */
	/* THE FOLLOWING ARE ORDERED ALPHABETICALLY BY JSYS NAME */



/* hptim */

#define HPelp 00	 		/* elapsed time */
#define HPrnt 01	 		/* run time */


/* idcnv (also idtnc and odcnv) */

#define IC_dsa 01:35-0			/* daylight savings if appropriate */
#define IC_ads 01:35-1			/* apply daylight savings */
#define IC_utz 01:35-2			/* use time zone given */
#define IC_jud 01:35-3			/* use julian date conversion */
#define IC_tmz 077:35-17			/* time zone */
#define IC_tim 0777777:35-35		/* local time */


/* idtim & idtnc */

#define IT_nda 01:35-0			/* no date */
#define IT_nnm 01:35-1			/* no numeric month */
#define IT_snm 01:35-2			/* second number is month */
#define IT_err 01:35-3			/* error if numbers are not in specified */
				/*  order */
#define IT_nti 01:35-6			/* no time */
#define IT_nis 01:35-7			/* no seconds */
#define IT_ais 01:35-8			/* always include seconds */
#define IT_nac 01:35-9			/* no colon allowed between hh and mm */
#define IT_aac 01:35-10			/* always allow colon */
#define IT_ams 01:35-11			/* always interpret one colon as hhmm:ss */
#define IT_ahm 01:35-12			/* always interpret one colon as hh:mm */
#define IT_n24 01:35-14			/* no 24-hour format */
#define IT_ntm 01:35-15			/* no time modifier (am, pm) */
#define IT_ntz 01:35-16			/* no time zone */

	/* ODTIM */

#define OT_nda  (0400000<<_shl18)	/* DO NOT OUTPUT DATE */
#define OT_day  (0200000<<_shl18)	/* OUTPUT DAY OF WEEK */
#define OT_fdy  (0100000<<_shl18)	/* OUTPUT NUMERIC MONTH */
#define OT_nmn  (0040000<<_shl18)	/* OUTPUT NUMERIC MONTH */
#define OT_fmn  (0020000<<_shl18)	/* OUTPUT MONTH IN FULL */
#define OT_4yr  (0010000<<_shl18)	/* OUTPUT 4-DIGIT YEAR */
#define OT_dam  (0004000<<_shl18)	/* OUTPUT DAY AFTER MONTH */
#define OT_spa  (0002000<<_shl18)	/* OUTPUT SPACES IN DATE */
#define OT_sla  (0001000<<_shl18)	/* OUTPUT SLASHES IN DATE */
#define OT_ntm  (0000400<<_shl18)	/* DO NOT OUTPUT TIME */
#define OT_nsc  (0000200<<_shl18)	/* DO NOT OUTPUT SECONDS */
#define OT_12h  (0000100<<_shl18)	/* OUTPUT 12-HOUR FORMAT */
#define OT_nco  (0000040<<_shl18)	/* DO NOT OUTPUT COLON */
#define OT_tmz  (0000020<<_shl18)	/* OUTPUT TIME ZONE */
#define OT_scl  (0000001<<_shl18)	/* SUPPRESS COLUMNIZATION */


	/* ODTNC -- SEE IDCNV FOR BITS */


	/* OPENF */

#define OF_bsz  (0770000<<_shl18)	/* BYTE SIZE */
#define OF_mod  (0007400<<_shl18)	/* MODE */
#define OFher  0400000	/* HALT ON IO ERROR */
#define OFrd  0200000	/* READ */
#define OFwr  0100000	/* WRITE */
#define OFex  0040000	/* EXECUTE (RESERVED FOR THE FUTURE) */
#define OFapp  0020000	/* APPEND */
#define OFthw  0002000	/* THAWED */
#define OFawt  0001000	/* ALWAYS WAIT */
#define OFpdt  0000400	/* PRESERVE DATES */
#define OFnwt  0000200	/* NEVER WAIT */
#define OFrtd  0000100	/* RESTRICTED */
#define OFpln  0000040	/* SET TO DISABLE LINE NUMBER CHECKING FOR */
  	/*  NON-LINE NUMBER FILES */
#define OFdud  0000020	/* DON'T UPDATE TO DISK BY DDMP */
#define OFofl  0000010	/* ALLOW OPENING THE DEVICE EVEN IF OFFLINE */


/* smon function codes and bit definitions (system flags) */

#define SFfac 00	 		/* allow fact entries */
#define SFcde 01	 		/* checkdisk found errors */
#define SFcdr 02	 		/* checkdisk running */
#define SFmst 03	 		/* manual start in progress */
#define SFrmt 04	 		/* remote logins allowed */
#define SFpty 05	 		/* pty logins allowed */
#define SFcty 06	 		/* cty login allowed */
#define SFopr 07	 		/* operator in attendance */
#define SFlcl 010	 		/* local logins allowed */
#define SFbte 011	 		/* bit table errors found on startup */
#define SFcrd 012	 		/* user can change directory characteristics */
#define SFnvt 013	       /* tops20an	;nvt login allowed */
#define SFwct 014	 		/* wheel login on cty allowed */
#define SFwlc 015	 		/* wheel login on local terminals allowed */
#define SFwrm 016	 		/* wheel login on remote terminals allowed */
#define SFwpt 017	 		/* wheel login on pty's allowed */
#define SFwnv 020	       /* tops20an	;wheel login on nvt's allowed */
#define SFusg 021	 		/* usage file in use */
#define SFflo 022	 		/* full latency optimization */
				/* caution: setting this requires that the */
				/*   system be at revision level 10, and */
				/*   that rh20 board m8555 be at revision level d. */
				/*   otherwise, the file-system may be damaged. */

#define SFmta 023	 		/* magtape allocation enabled */
/* below are function codes that do not map directly into bits */


#define SFntn 044	       /* tops20an	;network on/off control */
#define SFndu 045	       /* tops20an	;net down/up request */
#define SFnhi 046	       /* tops20an	;net host table initialize */
#define SFtmz 047	 		/* set time zone this system is in */
#define SFlhn 050	       /* tops20an	;set local host number of this net site */
#define SFavr 051	 		/* account validation on/off */
#define SFsts 052	 		/* enable/disable status reporting */
#define SFsok 053	 		/* getok/givok default setting */
#define SFmcy 054	 		/* set max ordinary offline exp period */
#define SFrdu 055	 		/* read date update function */
#define SFacy 056	 		/* set max archive exp period */
#define SFrtw 057	 		/* set [no] retrieval waits non-0 => no wait */
#define SFtdf 060	 		/* tape mount controls */
#define   MT_uut 01:35-0			/* unload unreadable tapes */
#define SFwsp 061	 		/* working set preloading */

#define SF_fac 01:35-<.sffac>		/* fact entries allowed */
#define SF_cde 01:35-<.sfcde>		/* checkdisk found errors */
#define SF_cdr 01:35-<.sfcdr>		/* checkdisk running */
#define SF_mst 01:35-<.sfmst>		/* manual start in progress */
#define SF_rmt 01:35-<.sfrmt>		/* remote logins allowed */
#define SF_pty 01:35-<.sfpty>		/* pty logins allowed */
#define SF_cty 01:35-<.sfcty>		/* cty login allowed */
#define SF_opr 01:35-<.sfopr>		/* operator in attendance */
#define SF_lcl 01:35-<.sflcl>		/* local logins allowed */
#define SF_bte 01:35-<.sfbte>		/* bit table errors found on startup */
#define SF_crd 01:35-<.sfcrd>		/* user can change directory characteristics */
#define SF_nvt 01:35-<.sfnvt>   /* tops20an	;nvt logins allowed */
#define SF_usg 01:35-<.sfusg>		/* usage file in use */
#define SF_flo 01:35-<.sfflo>		/* full latency optimization in use */
				/* caution: setting this requires that the */
				/*   system be at revision level 10, and */
				/*   that rh20 board m8555 be at revision level d. */
				/*   otherwise, the file-system may be damaged. */
#define SF_mta 01:35-<.sfmta>		/* magtape allocation enabled */


#define SF_eok 01:35-0			/* enable access checking */
#define SF_dok 01:35-1			/* allow access if checking disabled */

