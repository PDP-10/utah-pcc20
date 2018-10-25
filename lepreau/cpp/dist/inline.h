/*
 * inline.h - #defines for minimal functions
 *
 * Author:	Jay Lepreau
 *		Computer Science Dept.
 * 		University of Utah
 * Date:	April 81
 * Copyright (c) 1981 Jay Lepreau
 */

/* These first ones are all from local2.c */

#define rmove(to,fr,typ) printf("\tmove\t%s,%s\n", rnames[to], rnames[fr])
#define szty(t)			(1)
#define rewfld(p)		(1)
#define lineid(LINE,fn) 	printf(";l %d %s\n", LINE, fn)
#define adrcon(val)		printf("%ld", val )	/* CONFMT */
#define genscall(p,cookie)	gencall(p, cookie)
#define lastchance(p,cook)	(0)
#define callreg(p)		(1)			/* R1 */

#define defalign(n)					/* code.c: null */
#define checkst(lev)		/* pftn.c: turn on for symtab debugging */
#define setincr(p)		(0)	/* in order.c */
