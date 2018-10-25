/*
 *  atot - convert ascii string to time
 *
 **********************************************************************
 * HISTORY
 * 03-Jan-80  Mike Accetta (mja) at Carnegie-Mellon University
 *	Created.
 *
 **********************************************************************
 *
 *  Usage:  t = atot (date);
 *	time_t t;
 *	char *date;
 *
 *     Converts a date string to its corresponding UNIX date/time
 *  format using pdate().  The month, day and year default to
 *  today, hours, minutes and seconds default to 0.
 *
 *     Returns converted time or -1 on error (bad date string).
 */

#include <sys/types.h>
#include <time.h>
#include <c.h>

extern time_t gtime();
extern struct tm *localtime();

time_t atot(str)
char *str;
{

    time_t now;
    register struct tm *tm;

    time(&now);
    tm = localtime(&now);
    tm->tm_sec = tm->tm_min = tm->tm_hour = 0;
    if (pdate(str, tm) < 0)
	return(CERROR);
    return(gtime(tm));

}
