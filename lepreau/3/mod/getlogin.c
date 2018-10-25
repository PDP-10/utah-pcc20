/* 
 * getlogin.c - Unix getlogin(3)
 * 
 * Author:	Jay Lepreau
 * 		Computer Science Dept.
 * 		University of Utah
 * Date:	28 February 1982
 * Copyright (c) 1982 Jay Lepreau
 */

#include "tops20.h"

static   char buf[MAXUSERL+1];

char *
getlogin()
{
    ac2 = makeleft(0500000) | getuid();	/* watch the order of these stnts! */
    ac1 = POINT(buf);
    if (jsys(JSdirst, acs) == JSerr)
	return (0);
    return (buf);
}
