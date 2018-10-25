/* argument block offsets for xsir and xrir jsys's */

#define SIcnt 00		/* length of block */
#define SIlvt 01		/* address of level table */
#define SIcht 02		/* address of channel table */


/* scheduler control flags (jsys not yet defined) */

#define SK_cyt 01:35-18		/* cycle time */
#define SK_ioc 01:35-19		/* io quantum charge */
#define SK_ht1 01:35-20		/* limit hold time */
#define SK_ht2 01:35-21		/* no hold time after skipped fork */
#define SK_hqr 01:35-22		/* high queue fork have priority under load */
/* sk_lqr==:01:35-23			;low queue reserve */
/* sk_bqe==:01:35-24			;balset queue on entry */
#define SK_rsq 01:35-25		/* quick reschedule on wakeups */
#define SK_rq1 01:35-26		/* requeue to queue 1 */
#define SK_ttp 01:35-27		/* tty preference */
#define SK_wcf 01:35-28		/* wait credit proportional to load av */
