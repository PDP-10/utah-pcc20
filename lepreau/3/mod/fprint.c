/* Hacked from Alan Snyder's library by J.Lepreau, Univ. of Utah, 1/82 */

/*
 * If you make any improvements,  I'd like to get them too.
 * Jay Lepreau, harpo!utah-cs!lepreau,  lepreau@utah-cs
 */

/*
 *
 * _FPRINT - Floating-Point Print Routine (F format)
 * _EPRINT - E format
 * requires:
 *
 * internal routines and tables:
 *
 * fp3, fp4, fp5, fp6, ft0, ft1, ft10
 *
 * Note: this version has some PDP-10 (DEC-20) machine-dependence.
 */

#include "tops20.h"
#include <stdio.h>

/* Like putc, but just tacks onto a string */
#define sputc(c,p)	((int)(*(p)++ = (c)))

static char *fd;			/* a royal kludge! */

#define dtruncate(f) ( (int) (f) )
#define dround(f)   ( (f) >= 0 ? (int) ((f)+.499999) : ((int) ((f)-.499999)) )

static union {
     float ff;
     int   ii;
} fltint;

/* Would prefer to use void cast */
#define dabs(f)	    ( (f) >= 0 ? (f) : (-(f) >= 0 ? -(f) :\
	(fltint.ff = -(f), fltint.ii & makeword(0400000, 0), fltint.ff)) )

static double ft0[] = {1e1, 1e2, 1e4, 1e8, 1e16, 1e32};
static double ft1[] = {1e-1, 1e-2, 1e-4, 1e-8, 1e-16, 1e-32};
static double ft10[] =
	{1e0,  1e1,  1e2,  1e3,  1e4,  1e5,  1e6,  1e7,  1e8,  1e9,
	 1e10, 1e11, 1e12, 1e13, 1e14, 1e15, 1e16, 1e17, 1e18, 1e19,
	 1e20, 1e21, 1e22};

int
_fprint (d, tfd, p)
char *tfd;
double d;
int p;

	{register int cnt;
	fd = tfd;			/* make available to subrs */
	cnt = 0;
	if (p < 0) p = 0;
	else if (p > 22) p = 22;
	if (d < 0)
		{sputc ('-', fd);
		++cnt;
		d = dabs (d);
		}

      /* It appears that the following  escape hatch is necessary--
       * it sure doesn't work without it. -fjl
       */
	if (d > 0)
		{if (d < (1.0 / ft10[p])) return (cnt + fp4 (d, 0, fd, p));
		else if (d >= 1e8) return (cnt + fp4 (d, 1, fd, p));
		}

	return (cnt + fp3 (d, fd, p));
	}

static int
fp3 (d, tfd, p)	/* print positive double */
double d;

	{register int i;
	int n;
	register double fraction;

	i = (int) d;			/* truncate it */
	fraction = d - i;
	n = fp5 (i, fd);	/* return # of digits printed */
	sputc ('.', fd);
	fraction *= ft10[p];
	i = dround (fraction);
	fp6 (i, p, fd);		/* prints p digits */
	return (n + p + 1);
	}

static int
fp4 (d, flag, tfd, p)	/* print with exponent */
register double d;

	{register int c, e;

	c = 6;
	e = 0;
	while (--c >= 0)
		{e <<= 1;
		if (flag ? d >= ft0[c] : d <= ft1[c])
			{++e;
			d *= (flag ? ft1[c] : ft0[c]);
			}
		}
	if (d < 1.0)
		{++e;
		d *= 10.0;
		}
	c = fp3 (d, fd, p);
	sputc ('e', fd);
	if (d == 0)
		{flag = 1;
		e = 0;
		}
	sputc (flag ? '+' : '-', fd);
	if (e < 10) {		/* make sure the leading zero gets printed */
		sputc('0', fd);
		++c;
	}
	return (c + 2 + fp5 (e, fd));
	}

static int
fp5 (i, tfd)	/* print decimal integer, return # of digits printed */
		/* Should be made iterative! */

	{register int a;

	if (a = i / 10) a = fp5 (a, fd);
	else	a = 0;
	sputc (i % 10 + '0', fd);
	return (a + 1);
	}

static					/* make this iterative! */
fp6 (i, n, tfd)	/* print decimal integer given # of digits */

	{if (n > 0)
		{if (n > 1) fp6 (i / 10, n - 1, fd);
		sputc (i % 10 + '0', fd);
		}
	}

int
_eprint (d, tfd, p)
char *tfd;
register double d;
int p;

	{register int cnt;
	fd = tfd;
	cnt = 0;
	if (p < 0) p = 0;
	else if (p > 22) p = 22;
	if (d < 0)
		{sputc ('-', fd);
		++cnt;
		d = dabs (d);
		}
	return (cnt + fp4 (d, (d >= 1.0), fd, p));
	}
