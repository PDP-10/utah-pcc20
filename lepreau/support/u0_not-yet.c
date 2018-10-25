/* This module not used now, cruft */

/* Super kludge time here */

#include <stdio.h>

int
jfnof(fd)
{
    register int jfn;

    switch (fd) {
	case 0:
	    jfn = fileno(stdin);
	    break;
	case 1:
	    jfn = fileno(stdout);
	    break;
	case 2:
	    jfn = fileno(stderr);
	    break;
	default:
	    jfn = fd;
    }
    return (jfn);
}
