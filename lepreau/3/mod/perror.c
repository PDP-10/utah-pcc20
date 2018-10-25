/*
 * Print the error indicated	--changed for pcc-20  Jay Lepreau 2/81
 * in the cerror cell.		--Try use only low-level operations here.
 */

#include "mon_perror.h"
#include "tops20.h"

int	errno;			/* global error number */
int	_errno;			/* errno with more bits for erstr jsys */

perror(str)
char *str;
{
	int inacs[5];

	_seterr();
	if (strlen(str)) {		/* caller supplied msg */
		inacs[1] = POINT(str);
		jsys(JSpsout, inacs);	/* this better be ok! */
		inacs[1] = POINT(": ");
		jsys(JSpsout, inacs);
	}

	if (errno) {
		inacs[1] = PRiou;		/* destination */
		inacs[2] = makeword(FHslf, _errno);
		inacs[3] = 0;
		jsys(JSerstr, inacs);		/* should check this...?? */
	}      /* but can't w/ current jsys fx (erstr can return +2 on err!) */
	else {
		inacs[1] = POINT("No current error");
		jsys(JSpsout, inacs);
	}
	inacs[1] = '\r';	/* now necessary cause LF ccoc bit is off */
	jsys(JSpbout, inacs);
	inacs[1] = '\n';
	jsys(JSpbout, inacs);
}

int
_seterr()	/* returns last error number and assigns to errno */
{
	int inacs[5];

	inacs[1] = FHslf;			/* current process handle */
	if (jsys(JSgeter, inacs) == JSerr)
	    return(errno = 0);
	_errno = getright(inacs[2]);	/* need hi-bits for erstr jsys */
	return(errno = inacs[2] & 07777);
}

_syserr(str)
char *str;
{
    perror(str);
    exit(SYSERR);
}
