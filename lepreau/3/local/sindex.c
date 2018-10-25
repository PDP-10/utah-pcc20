/*
 * Look for s2 in s1 and return the location in s1 if found, else 0.
 * J.Lepreau 5/82
 */
 
extern char *index();

#define streqn(a,b,c)	(!strncmp(a,b,c))
#define NULL 0

char *
sindex(s1, s2)
register char *s1, *s2;
{
	register int l = strlen(s2);

	for (; s1 = index(s1, *s2); s1++) {
		if (streqn(s1, s2, l))
			return(s1);
	}
	return(NULL);
}
