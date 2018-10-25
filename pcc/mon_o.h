/* odcnv -- see idcnv for bits */


/* odtim */

#define OT_nda 01:35-0		/* do not output date */
#define OT_day 01:35-1		/* output day of week */
#define OT_fdy 01:35-2		/* output numeric month */
#define OT_nmn 01:35-3		/* output numeric month */
#define OT_fmn 01:35-4		/* output month in full */
#define OT_4yr 01:35-5		/* output 4-digit year */
#define OT_dam 01:35-6		/* output day after month */
#define OT_spa 01:35-7		/* output spaces in date */
#define OT_sla 01:35-8		/* output slashes in date */
#define OT_ntm 01:35-9		/* do not output time */
#define OT_nsc 01:35-10		/* do not output seconds */
#define OT_12h 01:35-11		/* output 12-hour format */
#define OT_nco 01:35-12		/* do not output colon */
#define OT_tmz 01:35-13		/* output time zone */
#define OT_scl 01:35-17		/* suppress columnization */


/* odtnc -- see idcnv for bits */


/* openf */

#define OF_bsz 077:35-5		/* byte size */
#define OF_mod 017:35-9		/* mode */
#define OF_her 01:35-18		/* halt on io error */
#define OF_rd 01:35-19		/* read */
#define OF_wr 01:35-20		/* write */
#define OF_ex 01:35-21		/* execute (reserved for the future) */
#define OF_app 01:35-22		/* append */
#define OF_thw 01:35-25		/* thawed */
#define OF_awt 01:35-26		/* always wait */
#define OF_pdt 01:35-27		/* preserve dates */
#define OF_nwt 01:35-28		/* never wait */
#define OF_rtd 01:35-29		/* restricted */
#define OF_pln 01:35-30		/* set to disable line number checking for */
				/* non-line number files */
#define OF_dud 01:35-31		/* don't update to disk by ddmp */
#define OF_ofl 01:35-32		/* allow opening the device even if offline */
#define OF_fdt 01:35-33		/* force date update */
#define OF_rar 01:35-34		/* wait if file is off-line */
