/*
 * Look for s2 in s1, starting from the right, and return the location in
 * s1 if found, else 0.
 * J.Lepreau 6/82
 */
 
extern char *rindex();

#define streqn(a,b,c)	(!strncmp(a,b,c))
#define NULL 0

char *
rsindex(s1, s2)
register char *s1, *s2;
{
	int l1 = strlen(s1);
	register int l2 = strlen(s2);
	register char *p;

	for (p = s1 + l1 - l2; p > s1; p--) {
		if (*p != *s2)
			continue;
		if (streqn(p, s2, l2))
			return(p);
	}
	return(NULL);
}
