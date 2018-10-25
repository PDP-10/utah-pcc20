/* 
 * access.c - Determine accesibility of file. Unix access(2)--not finished
 * 
 * Author:	Jay Lepreau
 * 		Computer Science Dept.
 * 		University of Utah
 * Date:	Feb 81
 * Copyright (c) 1981 Jay Lepreau
 */

# include "mon_gtjfn.h"
# include <stdio.h>

int				/* Unix access(2) */
access(filnam, mode)
char *filnam;
int  mode;
{
	struct {			/* not used yet - for chkac */
		int	acc_want;
		char	*usernam;
		char	*userdir;
		int	capables;
		char	*targetdir;
		int	prot;
	} argblk;
	int	jfn;

	if (mode != 0) {	/* only used by mktemp right now.... */
		perror("access:421 modes NYI");
		exit(2);
	}

	if ((jfn = _gtjfn(filnam, GJ_old | GJ_sht)) == OPENERR) {
		_seterr();	/* puts errcode in errno */
		return(-1);	/* nope... */
	}
	if (_rljfn(jfn) == OPENERR) {
		perror("access: bad _rljfn");
		exit(2);
	}
	return(0);		/* success */
}
