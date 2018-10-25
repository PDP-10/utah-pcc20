/* mktemp - modified for pcc-20 2/81 -Jay Lepreau */

#include "mon_mktemp.h"
#include <jsys.h>

char *	   /* replaces cap X's in as with hi-precision time w/ collision fix */
mktemp(as)
char *as;
{
	register char *s;
	register int pid;
	register i;

	pid = _hptim();	/* was getpid on unix */
	s = as;
	while (*s++)
		;
	s--;
	while (*--s == 'X') {
		*s = (pid%10) + '0';
		pid /= 10;
	}
	s++;
	i = 'a';
	while (access(as, 0) != -1) {
		if (i=='z')
			return("/");	/* force err in caller */
		*s = i++;
	}
	return(as);
}

int
_hptim()		/* returns elapsed time in micro-seconds */
{
	int inacs[5];
	inacs[1] = HPelp;
	if (jsys(JShptim, inacs) == JSerr) {
		perror("get_hptim sys err");
		exit(2);
	}
	return(inacs[1]);
}
