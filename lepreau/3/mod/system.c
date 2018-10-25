/* 
 * system.c - Simulate invocation by exec, tops-20 version
 * 
 * Author:	Jay Lepreau
 * 		Computer Science Dept.
 * 		University of Utah
 * Date:	8 February 1982
 * Copyright (c) 1982 Jay Lepreau for tops-20 version
 */

/* based on @(#)system.c	4.1 (Berkeley) 12/21/80 */

#include	<signal.h>

#include <stdio.h> 
#define vfork fork
#define _exit exit
#define MAXARG 200			/* should be same as in init.c */

extern char *skipto(),
 	    *skipover();

system(s)
register char *s;
{
    register char *p;
    register char **q;
    register int i;
    char *argv[MAXARG];
    char filnam[FNMAX];
    char wkbuf[FNMAX];
    int status, pid, w;
    register int (*istat)(), (*qstat)();

/* Do a dumb version for now, forget about quoted strings, ^Vs, \s, etc. */

    p = filnam;			/* dummy cause gets zapped 1st time thru */
    q = argv;
    for (;;) {
	if (*(s = skipover(s, " \t")) == '\0')	/* first non-ws */
	    break;
	*p = '\0';
	*q++ = s;	
	if (*(s = p = skipto(s, " \t")) == '\0')	/* first whitespace */
	    break;
    }
    *p = '\0';				/* make it a proper string */
    *q = 0;

    		 /* sys:<foo>bar.exe seems to work ok, so forget the dir part*/
    fngdv(argv[0], wkbuf);		/* check for dev field already there */
    if (*wkbuf == '\0') {		/* no, add sys: */
	strcpy(filnam, "SYS:");
	fnstd(filnam+4, argv[0]);	/* canonicalize into spot after sys: */
    }
    else
	strcpy(filnam, argv[0]);
    fngtp(argv[0], wkbuf);		/* get type field of filename */
    if (*wkbuf == '\0')			/* assume fn1 only, no gen */
	strcat(filnam, ".EXE");

    if ((pid = vfork()) == 0) {
	    execv(filnam, argv);
	    _exit(127);
    }
    istat = signal(SIGINT, SIG_IGN);
    qstat = signal(SIGQUIT, SIG_IGN);
    while ((w = wait(&status)) != pid && w != -1)
	    ;
    if (w == -1)
	    status = -1;
    signal(SIGINT, istat);
    signal(SIGQUIT, qstat);
    return(status);
}
