/* 
 * ioctl.c - Unix ioctl(2), sort of
 * 
 * Author:	Jay Lepreau
 * 		Computer Science Dept.
 * 		University of Utah
 * Date:	12 January 1982
 * Copyright (c) 1982 Jay Lepreau
 */

#include <sgtty.h>
#include "tops20.h"
#include <stdio.h>
/** #include "sys_ioctl.h" **/
#include "mon_ioctl.h"

static short speedtab[16] = {
	0, 50, 75, 110,
	0, 150, 200, 300,
	600, 1200, 1800, 2400,
	4800, 9600, 19200, 0
	};

#define brkword(c)	( (c)<32?0: (c)<64?1: (c)<96?2: 3 )
#define brkbit(c)	( 1 << (31 - ((c)-32*brkword(c))) )

struct brkblk {
	unsigned foo;
	unsigned brk0 : 32;
	unsigned brk1 : 32;
	unsigned brk2 : 32;
	unsigned brk3 : 32;
};

static struct brkblk stdbrk =
		       {4,
			brkbit('\n') | brkbit('\r'),
			brkbit(CTRL(z)) | brkbit(ESCAPE),
			0,
			0,
		       };

static struct brkblk allbrk = {4, -1, -1, -1, -1};

int
ioctl(fd, code, argp)
register struct sgttyb *argp;
{
    register int i,
    		 flags,
    		 mode;
    register struct _fot *fotp;
    int  spd,
	 jfn,
         fnd,
	 funny,		/* Do we have any kind of funny non-raw mode? */
	 ispeed,
	 ospeed;

/* Terrible kludge here, while don't have any fd->jfn mapping */
    jfn = jfnof(fd);
    fotp = &_fotab[jfn];

    switch(code) {
	case TIOCGETP:			/* get terminal params */
	    ac1 = jfn;
	    ac2 = MOrsp;		/* read speed */
	    if (jsys(JSmtopr, acs) == JSerr)
		goto err1;
	    ispeed = getleft(ac3);
	    ospeed = getright(ac3);
	    fnd = 0;
	    for (i = sizeof(speedtab) / sizeof(speedtab[0]) - 1; i >= 0; --i) {
		if ((spd = speedtab[i]) == ispeed) {
		    argp->sg_ispeed = i;
		    if (fnd)
		        break;
		    else
		        ++fnd;
		}
		if (spd == ospeed) {
		    argp->sg_ospeed = i;
		    if (fnd)
		        break;
		    else
		        ++fnd;
		}
	    }

	    argp->sg_erase = RUBOUT;	/* assume they're fixed for now */
	    argp->sg_kill = CTRL(u);

	    ac1 = jfn;
	    if (jsys(JSrfmod, acs) == JSerr)
		goto err1;
	    argp->sg_mode = mode = ac2;	/* save the real tops20 mode too */
	    flags = 0;
	    if (mode & Value(TT_eco))
	        flags |= ECHO;

	    switch (getfield(mode, TT_dam)) {
		case TTbin:
		    flags |= RAW;
		    flags &= ~(CBREAK | ECHO | CRMOD);
		    break;

		case TTasc:		/* we should have only TTate now */
		case TTato:		/* only in old tty driver, forget it */
		case TTate:		/* this is really std Unix here */
		    flags &= ~RAW;
		    if (fotp->_flg&CBREAK)
			flags |= CBREAK;
		    else
			flags &= ~CBREAK;
		    if (fotp->_flg&CRMOD)
			flags |= CRMOD;
		    else
			flags &= ~CRMOD;
		    break;

		default:
		    perror("ioctl - syserr");
		    exit(SYSERR);
	    }
	    argp->sg_flags = flags;
	    break;


	case TIOCSETP:	     /* set terminal params, but ignore erase & kill */
	    ac1 = jfn;
	    if (jsys(JSdobe, acs) == JSerr) /* wait for any output to drain */
		goto err1;
	/* fall thru */

	case TIOCSETN:
	    if (code == TIOCSETP || (argp->sg_flags&RAW) != (fotp->_flg&RAW)) {
			/* I spose should flush BJ's own buffers here too */
		    ac1 = jfn;
		    if (jsys(JScfibf, acs) == JSerr) /* flush input */
			goto err1;
	    }
	    ac1 = jfn;
	    ac2 = MOspd;		/* set speed */
	    ac3 = makeword(speedtab[argp->sg_ispeed], speedtab[argp->sg_ospeed]);
	    if (jsys(JSmtopr, acs) == JSerr)
		goto err1;

	    ac1 = jfn;			/* to be safe */
	    if (jsys(JSrfmod, acs) == JSerr)
		goto err1;
	    mode = ac2;			/* now we have current mode */

	    flags = argp->sg_flags;
	    funny = 0;
	    if (flags & RAW) {
		if (!(fotp->_flg & RAW))
		    _ttyraw(jfn, fotp);
		fotp->_flg |= RAW;
		setfield(mode, TT_dam, TTbin);
		mode &= ~Value(TT_pgm);
		mt_ps_brk(jfn, MOoff, &allbrk);	/* no pause, all break */
	    }
	    else {			/* anything but RAW mode */
	    	if (fotp->_flg & RAW)
		    _ttyunraw(jfn, fotp);
		fotp->_flg &= ~RAW;
		setfield(mode, TT_dam, TTate);	/* THIS DOESN'T WORK- WHY?? */
		mode |= Value(TT_pgm);	/* set pause on cmd mode */

		if (flags & ECHO) {
		    fotp->_flg |= ECHO;
		    mode |= Value(TT_eco);
		}
		else {
		    fotp->_flg &= ~ECHO;
		    mode &= ~Value(TT_eco);
		    ++funny;
		}

		if (flags & CRMOD)
		    fotp->_flg |= CRMOD;
		else {
		    fotp->_flg &= ~CRMOD;
		    ++funny;
		}
		if (flags & CBREAK) {
		    fotp->_flg |= CBREAK;
		    mt_ps_brk(jfn, MOoff, &allbrk);   /* no pause, all break */
		    ++funny;
		}
		else {
		    fotp->_flg &= ~CBREAK;
		    mt_ps_brk(jfn, MOonx, &stdbrk); /* pause, standard break */
		}	   /* if user don't want page, he should set len = 0 */

		/*
		 * This is a kludge, but should work for almost all programs.
		 * I.e., if anything is funny about the mode, turn all special
		 * tops-20 stuff off, namely the terminal width & length.
		 * NOTE that "funny" is not set for raw, to avoid screwing
		 * up the break mask.
		 */
		if (funny) {
		    setfield(mode, TT_wid, 0);
		    mt_ps_brk(jfn, MOoff, (flags&CBREAK) ? &allbrk : &stdbrk);
		}
		else {
		    setfield(mode, TT_wid, 80);	/* KLUDGE!! */
		    mt_ps_brk(jfn, MOonx, &stdbrk);
		}
	    }

	    ac1 = jfn;			/* now do all this */
	    ac2 = mode;
	    if (jsys(JSsfmod, acs) == JSerr)
		goto err1;
	    ac1 = jfn;		/* to be safe */
	    if (jsys(JSstpar, acs) == JSerr)
		goto err1;

	    /*
	     * Now we go and check all the other normal jfns which might
	     * be terminals and set same mode.  This is incredible kludge.
	     */
	   for (i = 0; i < 3; ++i) {
	       jfn = fileno(&_iob[i]);
	       if (isatty(jfn))
		   _fotab[jfn]._flg = fotp->_flg;
	   }
	   break;

	default:
	    return(-1);
    }
    return(0);

err1:
    _seterr();
    return(-1);
}

	
static		    /* MTopr fxns: Set pause/no pause & char break mask */
mt_ps_brk(jfn, pause_fx, brkptr)
struct brkblk *brkptr;
{
    ac1 = jfn;
#ifdef notdef			/* done above; this seems to be too late */
    if (jsys(JSdobe, acs) == JSerr)	/* wait for any output to drain */
	goto err;
#endif
    ac2 = MOxof;
    ac3 = pause_fx;
    if (jsys(JSmtopr, acs) == JSerr)
	goto err;
    ac2 = MOsbm;			/* set break mask */
    ac3 = (int) brkptr;
    return(0);

err:
    _seterr();
    return(-1);
}

int
_sfbsz(jfn, size)
{
    ac1 = jfn;
    ac2 = size;
    if (jsys(JSsfbsz, acs) == JSerr)
    	_syserr("ioctl - sfbsz");
}

_ttyraw(jfn, fotp)
struct _fot *fotp;
{
    _savetiw(jfn, fotp);
    _settiw(jfn, 0);
}

_ttyunraw(jfn, fotp)
struct _fot *fotp;
{
    _settiw(jfn, fotp->_tiw);
}

_savetiw(jfn, fotp)
struct _fot *fotp;
{
    ac1 = -5;
    if (jsys(JSrtiw, acs) == JSerr)
    	_syserr("rtiw");
    return (fotp->_tiw = ac3);
}

_settiw(jfn, tiw)
{
    ac1 = -5;
    ac2 = tiw;
    if (jsys(JSstiw, acs) == JSerr)
    	_syserr("stiw");
}
