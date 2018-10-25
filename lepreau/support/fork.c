/* 
 * fork.c - Unix fork(2), wait(2), and vfork (sort of)
 * 
 * Author:	Jay Lepreau
 * 		Computer Science Dept.
 * 		University of Utah
 * Date:	18 April 1981
 * Copyright (c) 1981 Jay Lepreau
 */

#include "tops20.h"
#include "mon_fork.h"

extern	    _frkretz();
extern	    _frkzap();
extern int *_saveacs();

int
fork()
{
	register int 	page,
			child,
			access,
			private;

	ac1 = CR_cap | CR_acs;
	ac2 = (int)_saveacs();		/* acs not included in shared pages */
	if (jsys(JScfork, acs) == JSerr) {
		_seterr();
		return(-1);
	}
	child = ac1;

	for (page = 0; page <= PAGEMAX; ++page) {
		ac1 = makeword(FHslf, page);
		if (jsys(JSrpacs, acs) == JSerr) {
			perror("fork: rpacs");
			exit(SYSERR);
		}
		if ((access = ac2) & PA_pex) {
			ac1 = makeword(FHslf, page);		/* source */
			ac2 = makeword(child, page);		/* dest	  */
			private = access & PA_prv;		/* private */
			access &= PA_rd|PA_wt|PA_ex|PA_cpy;
			if (access & PA_wt)
				access = (access & ~PA_wt) | PA_cpy;
			ac3 = access;
			if (jsys(JSpmap, acs) == JSerr) {
				perror("fork: pmap");
				exit(SYSERR);
			}
			if (private) {
				ac1 = makeword(FHslf, page);
				ac2 = access;
				if (jsys(JSspacs, acs) == JSerr) {
					perror("fork: spacs");
					exit(SYSERR);
				}
			}
		}
	}

	ac1 = child;
	ac2 = (int) _frkzap;		/* address of assembler subroutine */
	if (jsys(JSsfork, acs) == JSerr) {
		perror("fork: sfork");
		exit(SYSERR);
	}

	ac1 = child;			/* Wait for child to finish */
	if (jsys(JSwfork, acs) == JSerr) {
		perror("fork: wfork");
		exit(SYSERR);
	}

	ac1 = child;			/* Start the child for real   */
	ac2 = (int) _frkretz;		/* external asm micro routine */
	if (jsys(JSsfork, acs) == JSerr) {
		perror("fork: sfork");
		exit(SYSERR);
	}
	return(child);
}


/* same as above execpt no "frkzap" call.  Not use subr until think about
 * stack layout. */
int
vfork()
{
	register int 	page,
			child,
			access,
			private;

	ac1 = CR_acs;
	ac2 = (int)_saveacs();		/* acs not included in shared pages */
	if (jsys(JScfork, acs) == JSerr) {
		_seterr();
		return(-1);
	}
	child = ac1;

	for (page = 0; page <= PAGEMAX; ++page) {
		ac1 = makeword(FHslf, page);
		if (jsys(JSrpacs, acs) == JSerr) {
			perror("fork: rpacs");
			exit(SYSERR);
		}
		if ((access = ac2) & PA_pex) {
			ac1 = makeword(FHslf, page);		/* source */
			ac2 = makeword(child, page);		/* dest	  */
			private = access & PA_prv;		/* private */
			access &= PA_rd|PA_wt|PA_ex|PA_cpy;
			if (access & PA_wt)
				access = (access & ~PA_wt) | PA_cpy;
			ac3 = access;
			if (jsys(JSpmap, acs) == JSerr) {
				perror("fork: pmap");
				exit(SYSERR);
			}
			if (private) {
				ac1 = makeword(FHslf, page);
				ac2 = access;
				if (jsys(JSspacs, acs) == JSerr) {
					perror("fork: spacs");
					exit(SYSERR);
				}
			}
		}
	}

	ac1 = child;			/* Start the child for real   */
	ac2 = (int) _frkretz;		/* external asm micro routine */
	if (jsys(JSsfork, acs) == JSerr) {
		perror("fork: sfork");
		exit(SYSERR);
	}
	return(child);
}

/* kludge to force private copy of page for both parent & child */
/* _frkzap()		/**** done by assembler routine now *****/
/* {
/* 	register int	page;
/* 	register int	*p;
/* 
/* 	for (page = 0; page <= PAGEMAX; ++page) {
/* 		ac1 = makeword(FHslf, page);
/* 		if (jsys(JSrpacs, acs) == JSerr) {
/* 			perror("forkzap: rpacs");
/* 			exit(SYSERR);
/* 		}
/* 		if (ac2 & PA_pex) {		/* page exists */
/* 			p = (int *) pagetoloc(page);
/* 			*p = *p;		/* force private page */
/* 		}
/* 	}
/* }
**************/

int
wait(status)
int *status;
{
	struct frkstruct {		/* need fields here */
		int *parinfp;
		int *sup_han;		/* kludge */
		int  status;
	} frkstat[MAXFORK];

	struct frkstruct *frkend = frkstat + sizeof(frkstat);
	register struct frkstruct *fp;

	int	st,
		child,
		wtflg,
		acblk[020];


	for (fp = frkstat; fp < frkend; ++fp)
		fp->sup_han = 0;		/* so know when done */

	/* make sure SOME children exist, otherwise wfork hangs */
	gfrks(frkstat, sizeof(frkstat));
	if (frkstat[1].sup_han == 0)
		return(-1);			/* no children exist */

	ac1 = getright(FHinf);			/* all children */
	if (jsys(JSwfork, acs) == JSerr) {
		perror("wait: wfork");		/* to seterr later */
		exit(SYSERR);
	}

	gfrks(frkstat, sizeof(frkstat));

	/* loop assumes self in 1st loc */
	wtflg = 0;
	for (fp = frkstat; fp < frkend && fp->sup_han != 0; ++fp) {
		if ( ((int)fp->sup_han) >> 18 == (int)frkstat ) { /* child-1 */
			if ((st = getpleft(fp->status))==RFhlt || st==RFfpt) {
				if (wtflg++) {
					perror("wait: too many halted");
					exit(SYSERR);
				}
				child = (int)(fp->sup_han) & 0777777;
				if (status != 0) {
					ac1 = child;
					ac2 = (int) acblk;
					if (jsys(JSrfacs, acs) == JSerr) {
						perror("wait: rfacs");
						exit(SYSERR);
					}
				/* for now assume halt is always normal */
					*status = makeword(acblk[0],
					    st == RFhlt ? 0 : st);
				}
			}
		}
	}
	if (wtflg) {		/* kill so won't be confused next time */
		ac1 = child;
		if (jsys(JSkfork, acs) == JSerr) {
			perror("wait: kfork");
			exit(SYSERR);
		}
	}
	else {
		perror("wait: lost halted child");
		exit(SYSERR);
	}
	return(child);			/* finally, hurrah! */
}

static
gfrks(blk, size)
{
	ac1 = FHslf;
	ac2 = GF_gfh | GF_gfs;
	ac3 = makeword(getright(-size), blk);
	if (jsys(JSgfrks, acs) == JSerr) {
		perror("wait: gfrks");
		exit(SYSERR);
	}
}
