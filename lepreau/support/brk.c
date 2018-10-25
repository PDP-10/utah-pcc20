/* 
 * brk.c - Unix brk, sbrk (2)
 * 
 * Author:	Jay Lepreau
 * 		Computer Science Dept.
 * 		University of Utah
 * Date:	April 81
 * Copyright (c) 1981 Jay Lepreau
 *
 * Gross error fixed 11/10/82
 */
 /* 	For efficiency reasons, maybe should change defs of these to
 *	return int *.
 */

#include "tops20.h"

#define	HISEGSTART 0400000

extern int _jbff;			/* holds current program break */

char *					/* no reason this should be char * */
brk(addr)
int addr;
{
	register int newff = (addr + PAGESIZE-1) & ~(PAGESIZE-1);

	if (newff > HISEGSTART)
		return (char *) -1;
	_jbff = newff;
	return 0;
}

char *		/* NB: return ptr to start of additional area of size incr */
sbrk(incr)
int incr;
{
	register int oldff = _jbff;
	register int newff = (_jbff + incr + PAGESIZE-1) & ~(PAGESIZE-1);

	if (newff > HISEGSTART)
		return (char *) -1;
	_jbff = newff;
	return (char *) oldff;
}
