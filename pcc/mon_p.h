/* pmap bit definitions */

#define PM_cnt 01:35-0		/* rh word contains a count */
#define PM_mvp 01:35-1		/* move page instead of indirect pointer */
				/* (not implemented */
#define PM_rd 01:35-2		/* read */
#define PM_wt 01:35-3		/* write */
#define PM_wr 01:35-3		/* (another name for above) */
#define PM_ex 01:35-4		/* execute (reserved for the future) */
#define PM_rwx 07:35-4		/* convenient abbrev for rd+wt+ex */
#define PM_pld 01:35-5		/* preload pages being mapped */
#define PM_ind 01:35-6		/* use indirect ptrs (reserved for the future) */
#define PM_tpu 01:35-8		/* trap to user */
				/* (not implemented -- obsolete) */
#define PM_cpy 01:35-9		/* copy on write */
#define PM_abt 01:35-11		/* abort unmap. */
#define PM_rpt 0777777:35-35	/* repeat count */


/* pmctl - physical memory control */

#define MCrce 00		/* read cache enable */
#define MCsce 01		/* set cache enable */
#define MCcst 00		/* arglist offset for cache state */
#define MC_cen 01		/* cache enabled */
#define MCrps 02		/* read page status */
#define MCsps 03		/* set page status */
#define MCppn 00		/* arglist offset for physical page number */
#define MCpst 01		/* arglist offset for page state */
#define MCpsa 00		/* page available */
#define MCpss 01		/* page in transition state */
#define MCpso 02		/* page offline */
#define MCpse 03		/* page offline due to error */
#define MCrme 04		/* read memory error information */
#define PMmer 01		/* mos memory error */
#define PMmtp 00		/* entry header and type */
#define PMmrg 01		/* error register */
#define PMmsy 02		/* syndrome */
#define PMmbn 03		/* block number */
#define PMmsb 04		/* spare bit number */
#define PMmea 05		/* error address */
#define PMmsn 06		/* start of serial numbers */
#define PMmns 04		/* # of serial numbers to store */


/* prarg - process arguments */

/* function code definitions */

#define PRard 01		/* read argument block */
#define PRast 02		/* set argument block */

