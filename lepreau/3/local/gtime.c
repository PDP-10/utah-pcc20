/*  gtime  --  generate time from buffer
 *
 *  Usage:  t = gtime (buf);
 *	long t;
 *	struct tm *buf;
 *
 *  Gtime reconstructs the time from a buffer as produced by
 *  "localtime" using the algorithm of date (1).  Gtime is, in 
 *  fact, the inverse of "localtime".
 *
 *  HISTORY
 * 20-Nov-79  Steven Shafer (sas) at Carnegie-Mellon University
 *	Written by Mike Accetta.  If you don't like it, complain to him.
 *
 */

#include <sys/types.h>
#include <time.h>
#include <sys/timeb.h>

static	int	dmsize[12] =
{
	31,
	28,
	31,
	30,
	31,
	30,
	31,
	31,
	30,
	31,
	30,
	31
};

struct	tm *localtime();

long gtime(tm)
struct tm *tm;
{
	register int i;
	register secs, mins, day, hours, month, year;
	struct timeb info;
	long	timbuf;

	secs = tm->tm_sec;
	mins = tm->tm_min;
	hours = tm->tm_hour;
	day = tm->tm_mday;
	month = tm->tm_mon + 1;
	year = tm->tm_year;
	if( month<1 || month>12 ||
	    day<1 || day>31 ||
	    hours<0 || hours>24 ||
	    mins<0 || mins>59 ||
	    secs<0 || secs>59)
		return(-1);
	if (hours==24) {
		hours=0; day++;
	}
	timbuf = 0;
	year += 1900;
	for(i=1970; i<year; i++)
		timbuf += dysize(i);
	/* Leap year */
	if (dysize(year)==366 && month >= 3)
		timbuf++;
	while(--month)
		timbuf += dmsize[month-1];
	timbuf += day-1;
	timbuf = 24*timbuf + hours;
	timbuf = 60*timbuf + mins;
	timbuf = 60*timbuf + secs;
	ftime(&info);
	timbuf += (long)info.timezone*60;
	/* now fix up local daylight time */
	if(localtime(&timbuf)->tm_isdst)
		timbuf -= 60*60;
	return(timbuf);

}
