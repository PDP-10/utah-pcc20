/* printf.c: Alan Snyder's cprint routine: interface hacked for pcc-20.
 * (And considerably improved!) --J.Lepreau, Univ. of Utah, 3/81
 *
 * If you make any improvements,  I'd like to get them too.
 * Jay Lepreau, harpo!utah-cs!lepreau,  lepreau@utah-cs
 *
 * This version is a little PDP-10/DEC-20 dependent.  Also,
 * since we don't use varargs the arg addressing stuff is implementation
 * dependnent.
 */

# include <stdio.h>
# include "tops20.h"
# include <ctype.h>

#define TRUE  1
#define FALSE 0

/*
	CPRINT - C Formatted Print Routine
	Extendable Format Version:
		Print Routines should expect the following
		arguments (n specified when defined):
			1 to n:	n data arguments
			n+1:	file descriptor
			n+2:	field width (0 if none given)
			n+3:	pad character

	Format options:  (upper case treated identically)
		%s	string
		%c	character
		%o	octal
		%d	decimal
		%u	unsigned (= decimal)
		%x	hexadecimal
		%f	F format floating point (without exponent, if poss)
		%e	E format floating point (always with exponent)
		%z	Like %c except repeat characters width times
	If number preceeds format char (as in %4d) then number will be
	minimum field width in which the argument appears.  If the
	number is followed by a '.' and another number, that number is
	the precision (max # chars from a string, # digits to right of
	decimal point in floating point numbers).
	A positive field width will right justify the arg.
	A negative field width will left justify.

	If a 0 immediately follows the %, then the pad character is
	changed to 0 (instead of space).  If the next character after the
	0 is not a digit, then the pad character is changed to that character.
	For example:
		%09d   --  zero pad, width nine.  -- 000000312
		%0*9d  --  pad with *, width nine -- ******312
		%-0*9d --  left justified         -- 312******
	Note that the 0 does NOT mean that the following number is octal.
*/

#define MAXNUMLEN 64	/* max length in chars a number can turn into */

#ifdef CROSSCOMP
static int OCTMASK;
static int HEXMASK;
#else
# define OCTMASK 077777777777		/* to fix arith right shifts till we */
# define HEXMASK 037777777777		/* get unsigneds */
#endif

/*  # define SMALLEST "-34359738368"  */
/* smallest possible integer as reversed string	 -fjl 3/81 */
#define SMALLREV "86383795343-"

static int _prcf(), _prdf(), _pref(), _prff(),
	   _prof(), _prsf(), _prxf(), _przf();

static int (*form_table[26]) () = {
	/* a */ 0, 0, _prcf, _prdf, _pref, _pref, _pref, 0,
	/* i */ 0, 0, 0, 0, 0, 0, _prof, 0,
	/* q */ 0, 0, _prsf, 0, _prdf, 0, 0, _prxf,
	/* y */ 0, _przf };

	/* length of associated type, or number of args for this format */
static int form_nargs [26] = {
	/* a */ 0, 0, 1, 1, 1, 1, 1, 0,
	/* i */	0, 0, 0, 0, 0, 0, 1, 0,
	/* q */ 0, 0, 1, 0, 1, 0, 0, 1,
	/* y */ 0, 1};

static
fmtf (c, p, n)
int (*p)();
{
#ifdef obsolete
	if (c >= 'A' && c <= 'Z') c += ('a' - 'A');
	if (c >= 'a' && c <= 'z')
#endif
	if (isupper(c))
		c = tolower(c);
	if (islower(c))
		{if (n >= 0 && n <= 3)
			{form_table [c - 'a'] = p;
			form_nargs [c - 'a'] = n;
			}
		else fprintf (stderr, "bad nargs to FMTF: %d\n", n);
		}
	else fprintf (stderr, "bad character to FMTF: %c\n", c);
	}


printf (fmt, args)
char	*fmt;
int	args;
{
	_doprnt(fmt, &args, stdout);
}

fprintf	(fd, fmt, args)
FILE	*fd;
char	*fmt;
int	args;
{
	_doprnt(fmt, &args, fd);
}

char *
sprintf(str, fmt, args)
char	*str,
	*fmt;
int	args;
{
	struct _iobuf _strbuf;

	_strbuf._flag = _IOWRT+_IOSTRG;
	_strbuf._ptr = str;
	_strbuf._cnt = 32767;
	_doprnt(fmt, &args, &_strbuf);
	putc('\0', &_strbuf);
	return(str);
}

_doprnt (fmt, adx, fd)
register char	*fmt;
int	*adx;
FILE	*fd;
{
register int c;
int	width, rjust, prec;
int	(*p)(), n;
int	padc;

#ifdef CROSSCOMP
OCTMASK = makeword(077777, 0777777);		/* for x-compile */	
HEXMASK = makeword(037777, 0777777);		/* for x-compile */	
#endif

while (c = *fmt++)
	{if (c != '%') putc (c, fd);
	else	{width = 0;
		prec = -1;		/* precision not given */
		rjust = FALSE;		/* right justify off */
		padc = ' ';		/* pad with a space  */
		if (*fmt == '-')	/* then right justify */
			{rjust = TRUE;
			fmt++;
			}
		if (*fmt == '0')	/* then change pad character */
			{fmt++;
			if (isdigit(*fmt))
			    padc = '0';
			else
			    padc = *fmt++;
			}
		while (isdigit(*fmt))
			width = (width * 10) + (*fmt++ - '0');
	    	if (rjust) width = -width;
		c = *fmt++;
		if (c == '.')
			{prec = 0;
			while (isdigit(c = *fmt++))
				prec = (prec * 10) + (c - '0');
			}
		if (isupper(c))
			c = tolower(c);
		if (c == 'l' || c == 'h')  /* accept LONG and SHORT prefixes */
			{register int nc;
			if (isupper(nc = *fmt))
				nc = tolower(nc);
			if (nc == 'd' || nc == 'o' || nc == 'x' ||
			    nc == 'u' || nc == 'e' || nc == 'f')
				{c = nc;
				fmt++;
				}
			}
		if (islower(c))
			{p = form_table [c - 'a'];
			n = form_nargs [c - 'a'];
			if (p)
				{switch (n) {
			case 0:	(*p) (fd, width, prec, padc, c);
				break;
			case 1:	(*p) (adx[0], fd, width, prec, padc, c);
				break;
			case 2:	(*p) (adx[-1], adx[0], fd, width, prec, padc, c);
				break;
			case 3:	(*p) (adx[-2], adx[-1], adx[0], /* REVERSE for 20!!*/
				      fd, width, prec, padc, c);
				break;
					}
				adx -= n;	/* backwards for pcc-20!! */
				continue;
				}
			putc (c, fd);
			}
		else	putc (c, fd);
		}
	}
}

/**********************************************************************

	PRZF - Print Character N Times

**********************************************************************/
#define _PRZF(chr, f, num, prec, padc, fc) {\
		register int i = num;\
		while (--i >= 0) putc(chr, f);\
		}
		
#ifndef _PRZF
#define _PRZF	_przf
#endif

static
_przf (chr, f, num, prec, padc, fc)
register int num;
FILE *f;
{
	while (--num >= 0)
		putc (chr, f);
}

/**********************************************************************

	PROF - Print Octal Integer

**********************************************************************/
static
_prof (i, f, w, prec, padc, fc)
register unsigned i;
FILE *f;
int w, padc;
{
	char b[MAXNUMLEN];
	register char *p;
	int nd;

	p = b;
	do	{*p++ = (i & 07) + '0';
		i = (i >> 3) & OCTMASK;	/* beware no unisgned & arith rs */
		} while (i);
	nd = p - b;
	if (w > 0) _PRZF (padc, f, w - nd, prec, padc, fc);
	while (p > b) putc (*--p, f);
	if (w < 0) _PRZF (padc, f, -w - nd, prec, padc, fc);
}

/**********************************************************************

	PRDF - Print Decimal Integer

**********************************************************************/
static
_prdf(i, f, w, prec, padc, fc)
register int i;
FILE *f;
int w, padc;
{
	char b[MAXNUMLEN];
	register char *p;
	int flag, nd;

	flag = 0;
	p = b;
	if (i < 0) {i = -i; flag = 1;}
	if (i < 0)
		{strcpy (b, SMALLREV);
		p = b + strlen (b);
		flag = 0;
		}
	else	{do	{*p++ = i % 10 + '0';
			i /= 10;
			} while (i);
		}
	if (flag) *p++ = '-';
	nd = p - b;
	if (w > 0) _PRZF (padc, f, w - nd, 0, padc, fc);
	while (p > b) putc (*--p, f);
	if (w < 0) _PRZF (padc, f, -w - nd, 0, padc, fc);
}

/**********************************************************************

	PRSF - Print String

**********************************************************************/
static
_prsf(s, f, w, prec, padc, fc)
register char *s;
FILE *f;
int  w, prec, padc;
{
	register int prt;
	register int nd, pad;

	nd = strlen (s);
	if (prec < 0)			/* ==>default, no max */
	    prec = 8192;		/* ought to be big enuf */
	prt = min(nd, prec);		/* number of chars from str to prt */
	pad = (w >= 0 ? w : -w) - prt;	/* number of pad chars */
	if (pad <= 0)
	    w = 0;			/* no padding after all */
	if (w > 0)
	    _PRZF (padc, f, pad, 0, padc, fc);
	while (prt-- && putc(*s++, f))
	    ;
	if (w < 0)
	    _PRZF (padc, f, pad, 0, padc, fc);
}

/**********************************************************************

	PRCF - Print Character

**********************************************************************/
static
_prcf(c, f, w, prec, padc, fc)
	int  w;
	FILE *f;
	int c, padc;

	{if (w > 0) _PRZF (padc, f, w - 1, prec, padc, fc);
	putc (c, f);
	if (w < 0) _PRZF (padc, f, -w - 1, prec, padc, fc);
}

/**********************************************************************

	PRXF - Print Hexadecimal

**********************************************************************/
static
_prxf(i, f, w, prec, padc, fc)
register unsigned i;
FILE *f;
int w, padc;
{
	char b[MAXNUMLEN];
	register char *p;
	int nd;

	p = b;
	do	{register int c;
		c = i & 017;
		if (c < 10) c += '0';
		else	c += ('A' - 10);
		*p++ = c;		/* unsigneds are NYI: */
		i = (i >> 4) & HEXMASK;	/* beware of arith right shifts! */
		} while (i);
	nd = p - b;
	if (w > 0) _PRZF (padc, f, w - nd, prec, padc, fc);
	while (p > b) putc (*--p, f);
	if (w < 0) _PRZF (padc, f, -w - nd, prec, padc, fc);
}

/**********************************************************************

	PREF - Print Floating Point Number, E, F, G formats (more-or-less)

**********************************************************************/
static
_pref(d, f, w, prec, padc, fc)
	double d;
	int w, prec, padc;
	FILE *f;
{
	register int	c;
	char		b[MAXNUMLEN];
	char 		bb[MAXNUMLEN];
	register char	*p = b;
	int		nd, ne, nf;

	if (prec < 0)
	    prec = 6;
	switch (fc) {
	    case 'f':
	        nd = _fprint(d, b, prec);
		break;

	    case 'e':
	        nd = _eprint(d, b, prec);
		break;

	    case 'g':			/* do both, choose shortest */
	        nf = _fprint(d, b, prec);
		ne = _eprint(d, bb, prec);
		if (nf <= ne)
		    nd = nf;
		else {
		    nd = ne;
		    p = bb;
		}
		break;

	    default:
	        perror("_pref - impossible");
		exit(2);
	}
/**	nd = _flout(b, d, prec, fc);	***/

	*(p+nd) = '\0';			/* stick null on the end */
	if (w > 0)
	    _PRZF(padc, f, w - nd, prec, padc, fc);
	while (c = *p++)
	    putc (c, f);
	if (w < 0)
	    _PRZF(padc, f, (-w) - nd, prec, padc, fc);
}
