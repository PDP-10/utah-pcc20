/* 
 * f1.c - Support routines for the sys calls.
 *	  _gtjfn, _rljfn, _open, _ttynotrn, open
 * 
 * Author:	Jay Lepreau
 * 		Computer Science Dept.
 * 		University of Utah
 * Date:	26 February 1981
 * Copyright (c) 1981,1982 Jay Lepreau
 */

#include "mon_files.h"
#include <stdio.h>
#include <sgtty.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <file.h>
#include "tops20.h"
#include "mon_ioctl.h"
#include "mon_u2.h"

#define IOX4	0220			/* tops20 error code for eof */

int					/* _gtjfn -  internal routine */
_gtjfn(filnam, flags)
char	*filnam;
int	flags;
{
	register int	jfn;
	char	stdnam[FNMAX];

	fnstd(stdnam, filnam);		/* put in std form */
	ac2 = POINT(stdnam);
	ac1 = flags;
	if (jsys(JSgtjfn, acs) == JSerr) {
		_seterr();	/* puts errcode in errno */
#ifdef notyet
		if (makdir(stdnam, filnam) < 0)
#endif
		    return(-1);
	}
	if (ac1 == 2) {		/* incredible kludge right now... */
	    if ((jfn = _gtjfn("nul:", flags)) == -1)
		_syserr("Can't gtjfn on NUL:");
	    ac1 = jfn;			/* Now make jfn 2 point to NUL: */
	    ac2 = 2;
	    if (jsys(JSswjfn, acs) == JSerr)	/* by swapping them */
		_syserr("swjfn");
	    return(jfn);
	}
	else return(ac1);	/* the jfn! */
}

int
_rljfn(jfn)
int jfn;
{

	ac1 = jfn;
	if (jsys(JSrljfn, acs) == JSerr) {
		_seterr();
		return(-1);
	}
	return(0);
}

/*
 * Unix open(2), returns jfn.  3rd param is optional.
 */
int		
open(filnam, type, bytesize)
char	*filnam;
int	type;
{
	struct	stat	statb;
	int	flags,
		oflags,
		bastype,
		jfn;

	bastype = type & (FATT_RDONLY|FATT_WRONLY|FATT_RDWR|FATT_APPEND);

	switch (bastype) {
	    case FATT_RDONLY:
		flags = Value(GJ_old) | Value(GJ_sht);
		oflags = Value(OF_rd);
		break;

	    case FATT_WRONLY:
		flags = Value(GJ_fou) | Value(GJ_sht);
		oflags = Value(OF_wr);
		break;

	    case FATT_RDWR:
		flags = Value(GJ_sht);
		oflags = Value(OF_rd) | Value(OF_wr);
		break;

	    case FATT_APPEND:
		flags = Value(GJ_sht);
		oflags = Value(OF_app);
		break;

	    default:
		perror("Invalid mode to open");
		return(-1);
	}

	if ((jfn = _gtjfn(filnam, flags)) == -1) {
		_seterr();
		return(-1);
	}

#define BYTESIZE ( 36 / (sizeof(int)/sizeof(char)) )

	if (type & (FATT_RDLOCK|FATT_WRLOCK))	/* temp kluge, sort of */
	    oflags |= Value(OF_rtd);

	ac1 = jfn = getright(jfn);			/* clear left half */
	ac2 = makefield(OF_bsz, type & FATT_BINARY ? BYTESIZE : 7) | oflags;
	if (jsys(JSopenf, acs) == JSerr) {  /* could be dir, check for that */
	    _seterr();
#ifdef notyet
	    if (_errno == ERopnx13) {	/* invalid access */
		if (fstat(jfn, &statb) < 0)
		    goto badopen;
		if (statb.st_mode & S_IFDIR) {	/* must check protection */
		    if (statb.st_mode    )
			....		    
		}

	    }
#endif notyet
	    goto badopen;
	}

	if (type & (FATT_DEFSIZE|FATT_SETSIZE)) {/* reset byte size of this open */
	    if (type & FATT_DEFSIZE) {
		if (fstat(jfn, &statb) < 0)
		    _syserr("open defsize - fstat");
		ac2 = statb.st_bytesz;
	    }
	    else {
		if (nargs() != 3)
		    return -1;
		ac2 = bytesize;
	    }
	    ac1 = jfn;
	    if (jsys(JSsfbsz, acs) == JSerr)
		_syserr("open defsize - sfbsz"); /* can be user err, chg this*/
	}

	ac1 = jfn;
	if (jsys(JSdvchr, acs) == JSerr) {
		perror("dvchr");	/* to _seterr later */
		goto badopen;
	}
	if (getfield(ac2, DV_typ) == DVtty) {
		_fotab[jfn]._flg |= _FOTTY|ECHO|CRMOD;	/* defaults */
		_ttynotrn(jfn);		/* set it not to translate output */
	}
	else
		_fotab[jfn]._flg &= ~_FOTTY;
	if (type & FATT_BINARY)
		_fotab[jfn]._flg |= _FOBINARY;
	return(jfn);

badopen:
	_rljfn(jfn);
	return(-1);
}


#ifdef notdef				/* old */
/*
 * low-level open, returns jfn.
 * NB: this is NOT Unix open(2), thus the _name.
 */
int		
_open(filnam, mode)
char		*filnam;
register char	*mode;
{
	struct	stat	statb;
	int	flags,
		oflags,
		jfn;

	if (*mode == 'R') {			/* temporary! */
		flags = Value(GJ_old) | Value(GJ_sht);
		oflags = Value(OF_rd) | Value(OF_pdt);
	}
	else if (*mode == 'r') {
		flags = Value(GJ_old) | Value(GJ_sht);
		oflags = Value(OF_rd);
	}
	else if (*mode == 'w') {
		flags = Value(GJ_fou) | Value(GJ_sht);
		oflags = Value(OF_wr);
	}
	else if (*mode == 'a') {
		flags = Value(GJ_sht);
		oflags = Value(OF_app);
	}
	else {
		perror("Invalid mode to _open");
		return(-1);
	}
	if ((jfn = _gtjfn(filnam, flags)) == -1) {
		_seterr();
		return(-1);
	}

	ac1 = jfn = getright(jfn);			/* clear left half */
	ac2 = makefield(OF_bsz, 7) | oflags;
	if (jsys(JSopenf, acs) == JSerr) {  /* could be dir, check for that */
	    _seterr();
#ifdef notyet
	    if (_errno == ERopnx13) {	/* invalid access */
		if (fstat(jfn, &statb) < 0)
		    goto badopen;
		if (statb.st_mode & S_IFDIR) {	/* must check protection */
		    if (statb.st_mode    )
			....		    
		}

	    }
#endif notyet
	    goto badopen;
	}

	ac1 = jfn;
	if (jsys(JSdvchr, acs) == JSerr) {
		perror("dvchr");	/* to _seterr later */
		goto badopen;
	}
	if (getfield(ac2, DV_typ) == DVtty) {
		_fotab[jfn]._flg |= _FOTTY|ECHO|CRMOD;	/* defaults */
		_ttynotrn(jfn);		/* set it not to translate output */
	}
	else
		_fotab[jfn]._flg &= ~_FOTTY;
	return(jfn);

badopen:
	_rljfn(jfn);
	return(-1);
}

#endif

	/* ttynotrn - disables output translation  */
_ttynotrn(jfn)
{		/* This doesn't work for <escape>, WHY?? */
    ac1 = jfn;
    jsys(JSrfmod, acs);			/* should really check for error */
    setfield(ac2, TT_dam, TTate);
    ac1 = jfn;				/* to be safe */
    jsys(JSsfmod, acs);			/* should check here too */

/* Since the above doesn't work, we will kludge for now via the CCOC word */
    ac1 = jfn;				/* ugh, this sucks */
#ifdef notdef
    ac2 = makeword(052525252, 0525252);	/* all ctrl char echoing off */
    ac3 = makeword(052525252, 0525000);
#endif
    ac2 = makeword(0252532, 0513125);  /* Normal ccoc except turn on ^@ echo */
    ac3 = makeword(0252525, 0452400);  /* (was ignore) and make escape, LF, */
    jsys(JSsfcoc, acs);		  	/* & backspace binary cause tops20s */
}	/* is so fucked up: in tt%ate, it translates backspace to CR! */


#ifdef notyet
static			/* return 0 if successfull, -1 if not */
makdir(dirout, file)
char *file;
char *dirout;
{
    char dev[30], dir[60], name[40], type[40], gen[20], attr[30];


    fnparse (file, dev, dir, name, type, gen, attr);
    if (!(dir && *dir)) {		/* make it absolute */
	dirno = _getji(JIdno);		/* current dir num */
	if ((p = _numtodir(dirno)) == 0)
	    syserr("_numtodir");
	strcpy(dir, p);
    }
    
    


    if (*type == EOS) {
	strcpy(type, "directory");
	fncons (dirout, dev, dir, name, type, gen, attr);
	return(0);
    }
    return(-1);
}
#endif


char *
_numtodir(dirnum)
{
    static char buf[MAXUSERL];

    ac2 = makeword(0500000, dirnum);
    ac1 = POINT(buf);
    if (jsys(JSdirst, acs) == JSerr)
	return (0);			/* retcodes like getlogin() */
    return (buf);
}
