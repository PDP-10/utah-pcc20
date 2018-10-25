/*	Created from monsym.mac, 10/23/81  J.Lepreau, Univ of Utah 	*/
/*	Improved 1/82 */


/* *********************************************** */
/* general field and value definitions */
/* used by many jsyses */
/* *********************************************** */


/* general fork handles */

#define FHslf 0400000	 		/* self */

/* defined psi channels */

#define ICaov 6	 		/* arithmetic overflow */
#define ICfov 7	 		/* floating overflow */
#define ICpov 9	 		/* pdl overflow */
#define ICeof 10	 		/* end of file */
#define ICdae 11	 		/* data error */
#define ICqta 12	 		/* quota/disk exceeded */
#define ICtod 14	 		/* time of day (not implemented) */
#define ICili 15	 		/* illeg instruction */
#define ICird 16	 		/* illegal read */
#define ICiwr 17	 		/* illegal write */
#define ICiex 18	 		/* illegal execute (not implemented) */
#define ICift 19	 		/* inferior fork termination */
#define ICmse 20	 		/* machine size exceeded */
#define ICtru 21	 		/* trap to user (not implemented) */
#define ICnxp 22	 		/* nonexistent page referenced */

/* rtiw */

#define RT_dim 01:35-0			/* deferred terminal interrupt mask given */
#define RT_prh 0777777	 		/* process handle */

/* sir jsys (new form) */

#define SI_ver 07:35-17			/* version of sir in t1 */
#define SI_lev 077:35-5			/* level field in chntab */
#define SI_adr 7777,,-1		/* address of interrupt routine in chntab */

/* stiw */

#define ST_dim 01:35-0			/* set deferred interrupt mask */
#define ST_prh 0777777:35-35		/* process handle */

/* swtrp definitions */

#define SWart 00	 		/* set arithmetic trap */
#define SWrat 01	 		/* read arithmetic trap */
#define SWlut 02	 		/* set luuo address */
#define SWrlt 03	 		/* read luuo address */
#define 	ARpfl 00	 	/* offset in trap block for pc flags */
#define 	ARopc 01	 	/* offset for old pc value */
#define 	ARefa 02	 	/* offset for e */
#define 	ARnpc 03	 	/* offset for new pc word */

/* defined terminal codes */

#define TIcbk 0	 		/* break */
#define TIcca 1	 		/* ^a */
#define TIccb 2	 		/* ^b */
#define TIccc 3	 		/* ^c */
#define TIccd 4	 		/*  */
#define TIcce 5	 		/* ^e */
#define TIccf 6	 		/* ^f */
#define TIccg 7	 		/* ^g */
#define TIcch 8	 		/* ^h */
#define TIcci 9	 		/* ^i */
#define TIccj 10	 		/* ^j */
#define TIcck 11	 		/* ^k */
#define TIccl 12	 		/* ^l */
#define TIccm 13	 		/* ^m */
#define TIccn 14	 		/* ^n */
#define TIcco 15	 		/* ^o */
#define TIccp 16	 		/* ^p */
#define TIccq 17	 		/* ^q */
#define TIccr 18	 		/* ^r */
#define TIccs 19	 		/* ^s */
#define TIcct 20	 		/* ^t */
#define TIccu 21	 		/* ^u */
#define TIccv 22	 		/* ^v */
#define TIccw 23	 		/* ^w */
#define TIccx 24	 		/* ^x */
#define TIccy 25	 		/* ^y */
#define TIccz 26	 		/* ^z */
#define TIces 27	 		/* esc */
#define TIcrb 28	 		/* rubout */
#define TIcsp 29	 		/* space */
#define TIcrf 30	 		/* carrier off */
#define TIcti 31	 		/* typein */
#define TIcto 32	 		/* typeout */

/* timer definitions */

#define TImrt 00	 		/* set time limit */
#define TImel 01	 		/* set elapsed time clock */
#define TImdt 02	 		/* set date & time clock */
#define TImdd 03	 		/* delete an explict date & time clock */
#define TImbf 04	 		/* delete all entires before d&t */
#define TImal 05	 		/* delete all (includes time limit) */

