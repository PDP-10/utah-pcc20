/*   monerr.h - Created from monsym.mac by J.Lepreau, Univ. of Utah, 4/10/81 */

#define ERb 0600000		/* "Error base" */

#define ERgfdbx1 (ERb|0424) /* Invalid displacement */
#define ERgfdbx2 (ERb|0425) /* Invalid number of words */
#define ERgfdbx3 (ERb|0426) /* List access required */
#define ERcfdbx1 (ERb|0430) /* Invalid displacement */
#define ERcfdbx2 (ERb|0431) /* Illegal to change specified bits */
#define ERcfdbx3 (ERb|0432) /* Write or owner access required */

#define ERcfdbx4 (ERb|0433) /* Invalid value for specified bits */

/*	Created from monsym.mac, 10/23/81  J.Lepreau, Univ of Utah 	*/

/***		most recent edit history	***/
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


/* acces - access a directory (e.g., by connecting) */

#define AC_con 01:35-0			/* connect to the specified directory */
#define AC_own 01:35-1			/* gain ownership */
#define AC_rem 01:35-2			/* remove ownership */

/* offsets in argument block */

#define ACdir 00	 		/* directory designator */
#define ACpsw 01	 		/* pointer to password string */
#define ACjob 02	 		/* job number (-1 for self) */

/* chfdb */

#define CF_nud 01:35-0			/* no update directory */
#define CF_dsp 0777:35-17			/* fdb displacement */
#define CF_jfn 0777777:35-35		/* jfn */


/* gfust */

#define GFaut 00	 		/* get file author */
#define GFlwr 01	 		/* get file last writer */


/* gtjfn definitions */

/* flags provided to gtjfn on call */

#define GJ_fou 01:35-0			/* file is for output use */
#define GJ_new 01:35-1			/* new file only */
#define GJ_old 01:35-2			/* old file only */
#define GJ_msg 01:35-3			/* print an appropriate message */
#define GJ_cfm 01:35-4			/* confirmation is required */
#define GJ_tmp 01:35-5			/* temporary */
#define GJ_ns 01:35-6			/* dont search search lists */
#define GJ_acc 01:35-7			/* no access by other forks */
#define GJ_del 01:35-8			/* ignore "deleted" bit */
#define GJ_jfn 03:35-10			/* jfn use field */
#define GJdnu 00	 		/* do not use jfn provided */
#define GJerr 02	 		/* error if cannot use jfn provided */
#define GJalt 03	 		/* use alternate if cannot use given jfn */
#define GJ_ifg 01:35-11			/* accept input file group descriptors */
#define GJ_ofg 01:35-12			/* accept output file group descriptors */
#define GJ_flg 01:35-13			/* return flags */
#define GJ_phy 01:35-14			/* physical device only */
#define GJ_xtn 01:35-15			/* extended format (e+11 exists) */
#define GJ_fns 01:35-16			/* accumulator 2 contains job file numbers */
#define GJ_sht 01:35-17			/* short call format */

/* flags provided to gtjfn (in second flag word) */

#define G1_rnd 01:35-0			/* return on null(in alternate flag word) */
#define G1_rbf 01:35-1			/* ^r buffer is disjoint (obsolete) */
#define G1_nln 01:35-2			/* no long names */
#define G1_rcm 01:35-3			/* return confirm message */
#define G1_rie 01:35-4			/* return when main string is empty */
#define G1_iin 01:35-5			/*  ignore invisible status */
#define G1_sln 01:35-6			/* suppress expansion of logical names */



/* flags returned by gtjfn */

#define GJ_dev 01:35-0			/* asterisk was given for device */
#define GJ_unt 01:35-1			/* asterisk was given for unit */
#define GJ_dir 01:35-2			/* asterisk was given for directory */
#define GJ_nam 01:35-3			/* asterisk was given for name */
#define GJ_ext 01:35-4			/* asterisk was given for extension */
#define GJ_ver 01:35-5			/* asterisk was given for generation */
#define GJ_uhv 01:35-6			/* use highest generation */
#define GJ_nhv 01:35-7			/* use next higher generation */
#define GJ_ulv 01:35-8			/* use lowest generation */
#define GJ_pro 01:35-9			/* protection given */
#define GJ_act 01:35-10			/* account given */
#define GJ_tfs 01:35-11			/* temporary file specified (;t) */
#define GJ_gnd 01:35-12			/* complement of gj%del on call */
#define GJ_giv 01:35-17			/*  comp of g1%iiv */

/* gtjfn table offsets */

#define GJgen 00	 		/* flags ,, generation */
#define GJdef <z 0>			/* default generation */
#define GJnhg <z -1>			/* next higher generation */
#define GJleg <z -2>			/* lowest existing generation */
#define GJall <z -3>			/* all generations (i.e., ;*) */
#define GJsrc 01	 		/* source jfn ,, output jfn */
#define GJdev 02	 		/* default device */
#define GJdir 03	 		/* default directory */
#define GJnam 04	 		/* default name */
#define GJext 05	 		/* default extenstion */
#define GJpro 06	 		/* default protection */
#define GJact 07	 		/* default account */
#define GJjfn 010	 		/* desired jfn */
#define GJf2 011	 		/* second group flags,,count */
#define GJcpp 012	 		/* copy buffer pointer */
#define GJcpc 013	 		/* copy buffer count */
#define GJrty 014	 		/* retype (^r) pointer */
#define GJbfp 015	 		/* top of buffer pointer */
#define GJatr 016	 		/* pointer to arbitrary attribute block */

/* gnjfn - flags returned */

#define GN_str 01:35-13			/* structure changed */
#define GN_dir 01:35-14			/* directory changed */
#define GN_nam 01:35-15			/* name changed */
#define GN_ext 01:35-16			/* extension changed */


/* directory protection definitions (3 6-bit fields: owner, group, world) */

#define DP_rd 040	 		/* reading directory is allowed */
#define DP_cn 010	 		/* connect to dir, or change prot/account */
#define DP_cf 04	 		/* creating files in dir is allowed */

/* file protection definitions (3 6-bit fields: owner, group, world) */

#define FP_dir 02	 		/* directory listing */
#define FP_app 04	 		/* append */
#define FP_ex 010	 		/* execute */
#define FP_wr 020	 		/* write */
#define FP_rd 040	 		/* read */


/* getji */

#define JIjno 00	 		/* job number */
#define JItno 01	 		/* terminal number */
#define JIuno 02	 		/* user number */
#define JIdno 03	 		/* directory number */
#define JIsnm 04	 		/* subsys name */
#define JIpnm 05	 		/* program name */
#define JIrt 06	 		/* run time */
#define JIcpj 07	 		/* controlling pty job number */
#define JIrtl 010	 		/* run time limit (set by timer jsys) */
#define JIbat 011	 		/* controlled by batch */
#define JIden 012	 		/* magtape default density */
#define JIpar 013	 		/* magtape default parity */
#define JIdm 014	 		/* magtape default data mode */
#define JIrs 015	 		/* magtape default record size */
#define JIdfs 016	 		/* deferred spooling */
#define JIlno 017	 		/* logged-in directory number */
#define JIsrm 020	 		/* pointer to job session remark */
#define JIlln 021	 		/* last login date & time */
#define JIsrt 022	 		/* job runtime at start of this accounting session */
#define JIsct 023	 		/* job console time at start of this session */
#define JIt20 024	 		/* -1 if at tops20 command level */
#define JIstm 025	 		/* date & time job was initialized */
#define JIbch 026	 		/* batch stream and flags */
#define 	OB_wto 03:35-1		/* write to operator capabilities */
#define 	    OBall 00	 	/* wto and wtor allowed */
#define 	    OBnwr 01	 	/* no wtor allowed */
#define 	    OBnom 02	 	/* no message allowed */
#define 	OB_bss 01:35-10		/* batch stream number set */
#define 	OB_bsn 0177:35-17		/* batch-stream number */
#define JIllo 027	 		/* logical location (node name) */

#define JImax .jillo			/* current highest getji offset */


/* rcusr and rcdir */

/*  flags supplied on call */

#define RC_par 01:35-14			/* partial recognition is allowed */
#define RC_stp 01:35-15			/* step wildcard (rcdir only) */
#define RC_awl 01:35-16			/* allow wildcards (rcdir only) */
#define RC_emo 01:35-17			/* exact match only */

/*  flags returned */

#define RC_dir 01:35-0			/* files-only directory */
#define RC_ana 01:35-1			/* alphanumeric accounts allowed */
#define RC_rlm 01:35-2			/* repeat login message */
#define RC_nom 01:35-3			/* no match found */
#define RC_amb 01:35-4			/* ambiguous */
#define RC_nmd 01:35-5			/* no more dirs - returned if stp is requested */
#define RC_wld 01:35-6			/* wildcard dir was input */

