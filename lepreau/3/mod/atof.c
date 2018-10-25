/* 
 * C library - ascii to floating	2/81 fjl
 * pcc-20 version: only good while doubles ain't here; then must use dlfin
 * 
 * Author:	Jay Lepreau
 * 		Computer Science Dept.
 * 		University of Utah
 * Date:	Feb 81
 * Copyright (c) 1981 Jay Lepreau
 */

#include "mon_atof.h"
#include <stdio.h>
#include <byteptr.h>
#include <jsys.h>
#include <cross.h>
#include <ctype.h>

union ifacs {
	int	i;
	float	f;
};

double
atof(p)
register char *p;
{
	union	ifacs Acs[5]; /* can't use 'acs', will collide with tops20.h */
	char	str[50];		/* should be plenty till have dbles */
	register char *strp = str;
	register int i;

	while (i = *strp++ = *p++)		/* cnvt to upper case */
		if (islower(i)) *(strp-1) = toupper(i);

	Acs[1].i = POINT(str);
	if (jsys(JSflin, Acs) == JSerr) {
		perror("atof");			/* shouldn't happen */
		return(0.0);			/* best i can do */
	}
	return(Acs[2].f);	/* avoid conversion of output */
}

int
_flout(buf, d, prec, type)		/* returns # of chars printed */
char	*buf;
double	d;
int	prec;
{
	union ifacs Acs[5];

	Acs[1].i = POINT(buf);
	Acs[2].f = d;
	switch (type) {
		case 'e':		/* This is exactly right */
		    Acs[3].i = FL_one | FL_pnt
		    	| FLlzr << (35-3)	/* FL_jus = justif. & fill */
			| FLexe << (35-8)	/* FL_exp = exp. cntrl  */
			| FLple << (35-10)	/* FL_esg = exp. sign cntrl */
			| 1 << (35-23)	   /* FL_fst = #chars in 1st field */
			| prec << (35-29)  /* FL_snd =   "       2nd  "	*/
			| 4;		   /* FL_thd =   "       3rd  "	*/
		    break;
		    
			/* Because need set FL_fst to override free-format, */
		case 'f':		/* This is wrong for 0 <= n < 1 */
		    Acs[3].i = FL_ovl
		    	| FLtsp << (35-3)	/* FL_jus = right justify */
			| 1 << (35-23)	   /* FL_fst = #chars in 1st field */
			| prec << (35-29); /* FL_snd =   "       2nd  "	*/
		    break;
		    
		    /* Need to do both e and f, compare, and return shorter */
		case 'g':		/* I don't think this will work */
		    Acs[3].i =
		    	  FLtsp << (35-3)	/* FL_jus = justif. & fill */
			| FLple << (35-10)	/* FL_esg = exp. sign cntrl */
			| 1 << (35-23)	   /* FL_fst = #chars in 1st field */
			| prec << (35-29); /* FL_snd =   "       2nd  "	*/
		    break;

	}
	if (jsys(JSflout, Acs) == JSerr) {
		perror("flout");
		exit(2);
	}
	return(UNBPTR(Acs[1].i) - (int)buf + 1);  /* char size dependent!! ??*/
}

