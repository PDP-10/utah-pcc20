/* 
 * init.c - Initial pcc-20 runtime initialization.
 * 
 * Author:	Jay Lepreau
 * 		Computer Science Dept.
 * 		University of Utah
 * Date:	Feb 81
 * Copyright (c) 1981 Jay Lepreau
 */

#include "mon_init.h"
#include "tops20.h"
#include <stdio.h>
#include <sgtty.h>
#include <file.h>

#define TRUE	1
#define FALSE	0

#define MAXNAMLEN 256			/* max length filnam fron gnjfn */

#define COMBUFSZ 2048
#define MAXARG	 200

static char combuf[COMBUFSZ];

static struct argstruct {	/* put together so can return just 1 thing */
    int	    argc;
    char   *argv[MAXARG];
} argarea;

char toomany[] = "too many args";

#ifdef notdef
static
char   *cinfn = "tty:",		/* standard input file name, if redirected */
       *coutfn = "tty:",	/* standard output file name, if redirected */
       *cerrfn = "tty:";	/* standard errout file name, if redirected */
#else
static
char   *cinfn,		/* standard input file name, if redirected */
       *coutfn,		/* standard output file name, if redirected */
       *cerrfn;		/* standard errout file name, if redirected */
#endif

extern char *malloc();
extern char *skipto();

struct argstruct *
_init()
{
    int	    comlen;

    comlen = fill_combuf();		/* get the command line	 */
    argarea.argc = parse(combuf, comlen, argarea.argv);
 /* parse into argv array */
    setio();				/* initialize io stuff	 */
    return (&argarea);
}


static int
fill_combuf()
{
    register char  *p = combuf;
    int	    inacs[5];
    int	    rcnt;

    inacs[1] = RSini;
    jsys (JSrscan, inacs);

    inacs[1] = RScnt;
    jsys (JSrscan, inacs);		/* get cnt */
    if ((rcnt = inacs[1]) > COMBUFSZ) {
	perror ("Command line too long");
	exit (2);
/***		rcnt = COMBUFSZ;	/* tmp kludge, highly unlikely anyway*/
    }

    while (p < combuf + rcnt) {
	jsys (JSpbin, inacs);
	*p++ = inacs[1];
    }
    if (*--p == '\n')
	*p = EOS;
    else
	*++p = EOS;
    return (rcnt);
}


/**********************************************************************

FROM SNYDER'S C ROUTINES -fjl

Added globbing 1/81.  Note we should glob on re-directed files, but
don't yet.  Also, right now redirection opers have to be adjacent
to filename, which sucks.	--J.Lepreau

	PARSE - Parse Command Arguments

	given:	in -	the command string
		av -	a pointer to a character pointer array
			where pointers to the args should be placed
	returns:	number of arguments

	PJFLAG set to false suppresses parsing and I/O redirection
	RIFLAG set to false suppresses I/O redirection

	Command syntax:
				    *** Used to be %, %%  --fjl ***
		Arguments beginning with <, >, >>, &, && do file
			redirection, a la Unix.
		(A < redirection must not have an unmatched '>'
			in the file name.)
		Arguments are separated by spaces.
		Arguments may be surrounded by "s, in which case
			embedded spaces are allowed and embedded
			"s must be doubled.
		^V and \ both prohibit the special interpretation of
			the next character (i.e., space, ", <, >, &)
		A \ is eaten, a ^V is left in the string unless it
			is followed by a - or a ?.

**********************************************************************/

#define QUOTE	 026		/* ^V */
#define ARGQUOTE '\\'

static int  append,		/* redirected >> flags */
	    errappend;

static int
parse (in, slen, av)
register char   *in;
int		slen;
char		*av[];
{
    int	    pjflag = TRUE;/* set to false in binary file to suppress parsing */
    int	    riflag = TRUE;/* set to false in binary file to suppress redirect*/
			  /* of primary I/O; pjflag false also suppresses it */

    int	    	   ac;
    register char *out;

    ac = 0;
    out = in;
    append = errappend = FALSE;

    if (!pjflag) {		/* don't parse (except hack ^V, \ as usual) */
	int	c;
	av[0] = out;
	while (TRUE) {			/* get program name */
	    c = *in++;
	    if (c == ' ' || c == 0)
		break;
	    *out++ = c;
	}
	*out++ = 0;
	ac++;
	while (c == ' ')
	    c = *in++;
	av[1] = out;
	while (c) {			/* get rest of line */
	    if (c == QUOTE) {
		c = *in++;
		if (c != '?' && c != '-')
		    *out++ = QUOTE;
	    }
	    else if (c == ARGQUOTE)
		c = *in++;
	    *out++ = c;
	    c = *in++;
	}
	if (out != av[1])
	    ac++;
	return (ac);
    }

    while (TRUE) {			/* Normal case loop here */
	int	quoteflag,
		firstch,
		secondch;
	register int	c;
	char   *s;

	quoteflag = FALSE;

    /* find beginning of next arg */

	c = *in++;
	while (c == ' ')
	    c = *in++;			/* skip leading blnks */
	if (c == 0)
	    break;
	if (c == '"') {
	    quoteflag = TRUE;
	    c = *in++;
	}
	if (c == 0)
	    break;
	firstch = c;			/* \< should not be special */
	secondch = *in;			/* >\> should not be special */
	av[ac] = s = out;		/* point to start of arg */

    /* scan arg */

	while (TRUE) {
	    if (c == 0)
		break;
	    if (quoteflag) {
		if (c == '"') {
		    c = *in++;
		    if (c != '"')
			break;
		}
	    }
	    else if (c == ' ')
		break;
	    if (c == QUOTE || c == ARGQUOTE) {
		if (c == QUOTE) {
		    c = *in++;
		    if (c != '?' && c != '-')
			*out++ = QUOTE;
		}
		else
		    c = *in++;
		if (c == 0)
		    break;
	    }
	    *out++ = c;
	    c = *in++;
	}

	*out++ = '\0';

/* Now we have something real pointed to by av[ac]; it ends with EOS.	*/

    /* check for redirection command */

	if (ac == 0 || !riflag)
	    firstch = -1;
	switch (firstch) {
	    case '<':		/* if there is a matching '>' then this */
	    			/* is not a redirection command		*/
		{
		    register char t;
		    char	 *p;
		    int	  	  level;

		    p = s + 1;
		    level = 0;
		    while (t = *p++) {
			if (t == QUOTE && *p) {
			    ++p;
			    continue;
			}
			if (t == '<')
			    ++level;
			if (t == '>') {
			    if (level == 0)
				break;	/* unmatched */
			    --level;
			}
		    }			/* s[1] below says must be adjacent */
		    if (s[1] && (t != '>'))
			cinfn = s + 1;
		    else {
		        ac += maybeglob(&av[ac], MAXARG-ac) - 1;
			if (++ac < MAXARG)
			    av[ac] = out;
			else
			    argovflow();
		    }
		}
		break;
	    case '>': 
		if (secondch == '>') {
		    if (s[2]) {
			coutfn = s + 2;
			append = TRUE;
		    }
		}
		else if (s[1]) {
		    coutfn = s + 1;
		    append = FALSE;
		}
		break;
	    case '&': 
		if (secondch == '&') {
		    if (s[2]) {
			cerrfn = s + 2;
			errappend = TRUE;
		    }
		}
		else if (s[1]) {
		    cerrfn = s + 1;
		    errappend = FALSE;
		}
		break;
	    default: 	    		/* normal argument */
	        ac += maybeglob(&av[ac], MAXARG-ac) - 1;
		if (++ac < MAXARG)
		    av[ac] = out;
		else
		    argovflow();
	}
	if (c == 0)
	    break;
    }
    if (ac > MAXARG)
        argovflow();			/* bombproof it */
    return (ac);
}

static
argovflow()
{
    perror(toomany);
    exit(2);
}

/*
 * Return # of strings found: >= 1.
 * glob if can; allow non-matching strings.
 * takes care of all overflow here.
 */
static int
maybeglob(av, maxarg)
    char *av[];
{
    int nfiles;
			/* for efficiency and to avoid spurious globbing */
    if (*skipto(av[0], "*%") == EOS)
	return(1);			/* no wild cards ==> sort of 1 file */
    if ((nfiles = _glob(av, maxarg)) == -1)
        argovflow();
    return(nfiles ? nfiles : 1);	/* this means we allow no-match */
}

/*
 * Returns # of files found, -1 if > maxarg.
 * Leave global; might be useful.
 */
int
_glob(av, maxarg)
    char *av[];
{
   int	jfn1,
   	len;
   int  curr = 0;
   char buf[MAXNAMLEN];
   register char *p;

#ifdef notdef
   register int  c;
   register int  havq = 0;

   for (p = av[0]; c = *p; p++)		/* replace ? with % */
	if (c == '?') {
	    havq = 1;
            *p = '%';
	}
#endif

    if ((jfn1 = _gtjfn(av[0], GJ_old | GJ_ifg | GJ_sht)) == -1)
	return (0);

    do {			/* must get rid of flag bits for jfns */
	if ((len = _jfns(buf, getright(jfn1), 0, 0)) == 0) { /* can't happen */
	    perror("syserr: _jfns");
	    exit(SYSERR);
	}
	if (len >= MAXNAMLEN-1) {		/* -1 cause of extra null */
	    perror("file name too long");
	    exit(2);
	}
	if ((p = malloc(len+1)) == 0) {		/* one extra for null */
	    perror("no space for args - malloc");
	    exit(2);
	}
	strcpy(p, buf);
	if (curr >= maxarg) {
	    _rljfn(jfn1);
	    return (-1);
	}
	av[curr++] = p;
    } while (_gnjfn(jfn1) != -1);

    return(curr);
}


int				/* returns -1 if error */
_gnjfn(jfn)
{
    ac1 = jfn;
    if (jsys(JSgnjfn, acs) == JSerr)	/* assume just ran out */
	return (-1);
    return(jfn);
}

int		/* returns length of filename, EXCLUDING null (like strlen) */
_jfns(buf, jfn, fmt, prefix)
char	*buf,
	prefix;
{
    ac1 = POINT(buf);
    ac2 = jfn;
    ac3 = fmt;
    ac4 = prefix ? POINT(prefix) : prefix;
    if (jsys(JSjfns, acs) == JSerr) {
	perror("syserr: jfns");
	exit(SYSERR);
    }
    return(GETJUSLEN(buf, ac1));
/** return((char *)UNBPTR(ac1) - buf + 1);	/* 36 char depend?? */
}



/*	SETIO - Setup standard I/O	*/

static
setio()
{
    register int    n;
					/* less to type if do it this way! */
    _fotab[PRiin]._flg |= _FOTTY|CRMOD|ECHO;
    _fotab[PRiou]._flg |= _FOTTY|CRMOD|ECHO;
    _ttynotrn(PRiou);			/* set no translation of output */

/* std files redirected? */
#ifdef notdef				/* when the default was tty: */
	n = fileno(stdin) = mustopen(cinfn, "r");
	n = fileno(stdout) = mustopen(coutfn, append ? "a" : "w");
	n = fileno(stderr) = mustopen(cerrfn, errappend ? "a" : "w");
#endif

	if (cinfn)
	    n = fileno(stdin) = mustopen(cinfn, 0);
	if (coutfn)
	    n = fileno(stdout) = mustopen(coutfn, append ? FATT_APPEND : 1);
	if (cerrfn)
	    n = fileno(stderr) = mustopen(cerrfn, errappend ? FATT_APPEND : 1);
}


static int		/* do lowlevel open, and quit with msg if error */
mustopen (filnam, mode)
char   *filnam,
       *mode;
{
    int	 file;
    char buf[256];

    if ((file = open(filnam, mode)) < 0) {
	perror(strcat(strcpy(buf, "Can't open redirected file "), filnam));
	exit (1);
    }
    return (file);
}
