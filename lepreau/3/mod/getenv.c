/* <COS.LEPREAU.3.MOD>GETENV.C.9, 18-Nov-85 16:26:24, Edit by BEEBE */
/* Add code to check system-wide definitions too -- important for TERMCAP and TERM */
/* 
 * getenv.c - tops20 version accessing logical names directly.
 * Note this won't work in the long run, cause loical name formats are
 * are way to restricted.
 *
 * Author:	Jay Lepreau
 * 		Computer Science Dept.
 * 		University of Utah
 * Date:	Januray 82
 * Copyright (c) 1982 Jay Lepreau
 */

/*
 *	getenv(name)
 *	returns ptr to value associated with name, if any, else NULL
 */
#define NULL	0

#include "tops20.h"
#include "mon_env.h"

extern char *malloc(),
	    *realloc();

#define MAXLOGNAME	511		/* enuf for now */

char *
getenv(name)
char *name;
{
    register char *p;
    register int  len;

    if ((p = malloc(MAXLOGNAME)) == NULL) {
	perror("getenv - no mem");
	exit(2);
    }

    ac1 = LNsjb;			/* try job-wide first */
    ac2 = POINT(name);
    ac3 = POINT(p);
    if (jsys(JSlnmst, acs) == JSerr) 
    {
        ac1 = LNssy;			/* try system-wide second */
	ac2 = POINT(name);
	ac3 = POINT(p);
	if (jsys(JSlnmst, acs) == JSerr) 
	{
	    if (ac1 == ERlnstx1)	/* no such name */
	        return(NULL);
	    perror("getenv - syserr");
	    exit(SYSERR);
	}
    }
    if ((len = GETJUSLEN(p, ac3)) >= MAXLOGNAME) 	/* 1 extra for null */
    {
	perror("getenv - value too long");
	exit(2);
    }
    return(realloc(p, len+1));		/* room for null on the end */
}
