/* ufpgs */

#define UF_now 01:35-0		/* no wait on update */

/* utest function codes */

#define UTset 00		/* start testing */
#define UTclr 01		/* stop testing and return results */

/* utest argument block */

#define UTadr 00		/* starting address of code */
#define UTlen 01		/* length of code */
#define UTmap 02		/* start of bit map */

/* usage */

#define USent 00		/* write entry */
#define UScls 01		/* close out current file */
#define USckp 02		/* perform checkpoint */
#define USlgi 03		/* login */
#define USlgo 04		/* logout */
#define USsen 05		/* session end */
#define UScki 06		/* set checkpoint interval */
#define USena 07		/* enable account validation */
#define UScas 010		/* change accounting shift now */
#define USsas 011		/* set automatic accounting shift change times */
#define USras 012		/* read automatic accounting shift change times */
				/* table entry format for .ussas/.usras: */
#define US_dow 0177:35-6	/* day-of-week bits */
#define US_ssm 0777777	 	/* time in seconds since midnight */

/* utfrk */

#define UT_trp 01:35-0		/* itrap (or do erjmp/ercal) trapped jsys */
