/* Problems:
 *	--difference between sig_dfl and IGN;
 *	--stack may be getting garbaged
 *	--interection with buffered i/o?  Nede to flush something?  (tsig)
 *	--^Z in tsig doesn't work right after caught ^C.
 */

/* 
 * sig.c - Rudimentary signal support
 *		signal(2), kill(2), alarm(2)
 * 
 * Author:	Jay Lepreau
 * 		Computer Science Dept.
 * 		University of Utah
 * Date:	19 September 1982
 * Copyright (c) 1982 Jay Lepreau
 */

#include <sys/types.h>
#include "tops20.h"
#include "signal.h"
#include "mon_sig.h"

bool	psion;
typedef	int (*FUNCPTR)();

unsigned *pclev3;

static unsigned **levtab[3] = {0, 0, &pclev3};

#define NCHAN	36

static struct chntab {
    unsigned pri	: 18;
    unsigned handler	: 18;
} chntab[NCHAN];
#define UBASE	23			/* start of "assignable by user pgm" */
#define CHNBIT(n) (1 << (35-n))

short _chntab[NCHAN];			/* holds associated signum */

/* Types of signals */
#define TERM	001			/* can be terminal generated */
#define PANIC	002			/* panic channel */
#define NORM	004			/* other psi intr */
#define BJ	010			/*unique to blackjack; not in tops20*/
 
#define CHNHUP	UBASE+0
#define CHNINT	UBASE+1
#define CHNQUIT	UBASE+2
#define CHNKILL	UBASE+3
#define CHNSYS	UBASE+4
#define CHNPIPE	UBASE+5
#define CHNALRM	UBASE+6
#define CHNTERM	UBASE+7

struct sigtab {
    FUNCPTR	fxnp;
    int		chn;			/* chntab index */
    int		termcode;		/* terminal code if TERM intr */
    int		flags;
} _sigtab[NSIG+1] = {0, 0, 0, 0,			/* nothing */
    		  0, CHNHUP, TIcrf, TERM,	/* 1 - hup */
		  0, CHNINT, TIccc, TERM,	/* 2 - int */
		  0, CHNQUIT, TIccb, TERM,	/* 3 - (quit) ^B now */
		  0, ICili, 0, PANIC,		/* 4 - illegal instr */
		  0, 0,	0, 0,			/* 5 - tracetrap */
		  0, 0,	0, 0,			/* 6 - IOT instr */
		  0, 0,	0, 0,			/* 7 - EMT instr */
		  0, ICfov, 0, NORM,		/* 8 - fpe */
		  0, CHNKILL, 0, BJ,		/* 9 - kill */
		  0, ICird, 0, PANIC,		/* 10 - (buserr) */
                  0, ICird, 0, PANIC,		/* 11 - (segmentation) */
		  0, CHNSYS, 0, BJ,		/* 12 - sys */
		  0, CHNPIPE, 0, BJ,		/* 13 - pipe */
		  0, CHNALRM, 0, BJ,		/* 14 - alarm */
		  0, CHNTERM, 0, BJ,		/* 15 - term */
		};

extern struct _handler {
    int filler[1];			/* 1 = length of each asm "routine" */
} _handler[];

int ignore();

(*
signal(sig, func))()
int sig;
FUNCPTR func;
{
    register int c;			/* channel */
    register struct sigtab *ps;
    FUNCPTR  oldfunc;

    if (sig < 0 || sig > NSIG) {
	perror("sig out of range");	/* temporary */
	return BADSIG;
    }

    if (!psion) {			/* initiliaze psi system */
	ac1 = FHslf;
	ac2 = makeword((unsigned)levtab, (unsigned)chntab);
	if (jsys(JSsir, acs) == JSerr)
	    _syserr("sir");
	if (jsys(JSeir, acs) == JSerr)
	    _syserr("eir");
	psion++;
    }

    ps = &_sigtab[sig];
    c = ps->chn;
    oldfunc = ps->fxnp;
    if (func == oldfunc)		/* same as it used to be, all done */
	return oldfunc;
    if (func == SIG_DFL) {		/* deactivate the channel */
	ac1 = FHslf;
	ac2 = CHNBIT(ps->chn);
	if (jsys(JSdic, acs) == JSerr)
	    _syserr("signal - dic");
	if (ps->flags & TERM) {	/* deassign term code for good luck */
	    ac1 = ps->termcode;
	    if (jsys(JSdti, acs) == JSerr)
		_syserr("signal - dti");
	}
	ps->fxnp = 0;
	chntab[c].pri = _chntab[c] = 0;
	return oldfunc;
    }
    ps->fxnp = (func == SIG_IGN) ? &ignore : func;    
    _chntab[c] = sig;			/* set up cross ref */

/* Add entry to chntab */
    chntab[c].handler = (unsigned) &_handler[c];
    chntab[c].pri = 3;			/* fixed at 3 for now */

/* Set up any terminal codes */
    if (ps->flags & TERM) {
	ac1 = makeword(ps->termcode, c);
	if (jsys(JSati, acs) == JSerr)
	    _syserr("signal - ati");
    }

/* Activate channel, finally */
    ac1 = FHslf;
    ac2 = CHNBIT(c);
    if (jsys(JSaic, acs) == JSerr)
	_syserr("signal - aic");

    return oldfunc;
}


int					/* Unix kill(2), sort of */
kill(pid, sig)
{
    if (pid != FHslf)
	perror("kill: Non FHslf may not work");
    ac1 = pid;
    ac2 = CHNBIT(_sigtab[sig].chn);
    if (jsys(JSiic, acs) == JSerr) {
	perror("kill - iic");
	return -1;
    }
    return 0;
}


/* Used to swallow up signals ignored by user */
static
ignore(sig)
{
}


int					/* Unix alarm(2) */
alarm(secs)
unsigned secs;
{
    static time_t	lastatime;
    static unsigned	lastsecs;
    register time_t	currtime;
    register time_t	t;

/* Find time remaining on last alarm.  This is crude but good enuf for now */
    currtime = time(0);
    if (lastatime)
	t = lastsecs - (currtime - lastatime);
    else
	t = 0;
    lastatime = currtime;
    lastsecs = secs;
    
    ac1 = makeword(FHslf, TImel);
    ac2 = secs * 1000;
    ac3 = CHNALRM;
    if (jsys(JStimer, acs) == JSerr)
	_syserr("alarm - timer");
    return t;
}
