/* 
 * time.c - Time routines, sections 2 & 3
 * 
 * Author:	Jay Lepreau
 * 		Computer Science Dept.
 * 		University of Utah
 * Date:	10 February 1981
 * Copyright (c) 1981,1982 Jay Lepreau
 */

/* Converted to use Unix internal format 2/6/82 */

#include "tops20.h"
#include "mon_time.h"
#include <sys/types.h>
#include <sys/timeb.h>

#define HOUR 3600
#define DAY  (HOUR*24)
#define DAY0 40587     /* number of days between tops20 0 day and Unix 0 day */

static char datbuf[26];		/* 2 spare chars... */

char *				/* convert internal time */
ctime(intime)
long *intime;
{
	char temp[30];

	ac1 = POINT(temp);
	ac2 = _u2ttim(*intime);		/* convert unix to 20 time */
	ac3 = OT_day|OT_4yr|OT_dam|OT_spa;
	jsys(JSodtim, acs);

/* They fixed a bug in R5, so different.
 * R4 doesn't put the comma in after the day as it's sposed to.
 * Figure out on the fly what  we've got.  Don't just use the release#
 * cause maybe somebody fixed their R4.
 */
	if (index(temp, ',')) {		/* must be Release 5 */
	    strncpy(datbuf, temp, 10);		/* copy weekday month day */
	    strncpy(datbuf+10, temp+16, 9);	/* sp time */
	    strncpy(datbuf+19, temp+11, 5);	/* sp year */
	}
	else {
	    strncpy(datbuf, temp, 11);		/* copy weekday month day sp */
	    strncpy(datbuf+11, temp+16, 8);	/* time */
	    strncpy(datbuf+19, temp+10, 5);	/* sp year */
	}
	strncpy(datbuf+24, "\n", 2);
	return(datbuf);
}

long				/* get internal time */
time(tloc)
long *tloc;
{
	register long u;

	jsys(JSgtad, acs);
	u = _t2utim(ac1);
	if (tloc != 0)
	    return(*tloc = u);
	return(u);
}

	/* Unix ftime(2) */
ftime(tp)
register struct timeb *tp;
{
    time(&tp->time);
    tp->millitm = 0;			/* for now */
    ac1 = SFtmz;
    if (jsys(JStmon, acs) == JSerr)
	_syserr("ftime - tmon");
    tp->timezone = 60 * ac2;		/* does this work east of greenwich? */
    ac2 = -1;
    ac4 = 0;
    if (jsys(JSodcnv, acs) == JSerr)
	_syserr("ftime - odcnv");
    tp->dstflag = getfield(ac4, IC_ads);
}


/* 
 * WARNING: These don't currently handle dates earlier than Unix day 0,
 * 1/1/70.  Negative internal dates are legal in Unix; must be fixed...
 */

_u2ttim(u)
register long u;
{
    return makeword( u/DAY + DAY0, ((u%DAY) << 18) / DAY );
}

_t2utim(t)
{
    register ticks, rh, secs;

    ticks = t - makeword(DAY0, 0);
    rh = getright(ticks) * DAY;
    secs = rh >> 18;
    if (rh % makeword(1,0) > 0400000)
	secs++;				/* round up */
    return (getleft(ticks) * DAY) + secs;
}
