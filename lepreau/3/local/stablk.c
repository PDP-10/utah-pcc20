/*  stablk  --  string table lookup
 *
 *  Usage:  i = stablk (arg,table,quiet);
 *
 *	int i;
 *	char *arg,**table;
 *	int quiet;
 *
 *  Stablk looks for a string in "table" which matches
 *  "arg".  Table is declared like this:
 *    char *table[] = {"string1","string2",...,0};
 *  Each string in the table is checked via stablk() to determine
 *  if its initial characters match arg.  If exactly one such
 *  string matches arg, then the index of that string is returned.
 *  If none match arg, or if several match, then -1 (respectively -2)
 *  is returned.  Also, for either of these errors, if quiet is
 *  FALSE, the user will be asked if he wants a list of the possible
 *  strings.  In the case of multiple matches, the matching strings
 *  will be marked specially.
 *
 *  HISTORY
 * 19-May-80  Steven Shafer (sas) at Carnegie-Mellon University
 *	Added exactmatch and code to recognize exact match in case of
 *	ambiguity from initial prefix matching.
 *
 * 16-Apr-80  Steven Shafer (sas) at Carnegie-Mellon University
 *	Changed listing code to use prstab() instead of just printing
 *	table -- this uses multiple columns when appropriate.  To do this,
 *	it was necessary to add the "matches" array.  Too bad!
 *
 * 20-Nov-79  Steven Shafer (sas) at Carnegie-Mellon University
 *	Rewritten for VAX from Ken Greer's routine.  The error messages are
 *	different now.
 *
 *  Originally from klg (Ken Greer) on IUS/SUS UNIX.
 */

#include <c.h>
#include <string.h>

#define NOTFOUND -1
#define AMBIGUOUS -2
#define MAXSTRINGS 500

int stlmatch();
int strcmp();

int stablk (arg,table,quiet)
char *arg, **table;
int quiet;
{
	register int i,ix,count;
	int wantlist;
	char *matches[MAXSTRINGS];
	int exactmatch;

	count = 0;
	exactmatch = -1;
	for (i=0; table[i] != 0; i++) {
		if (stlmatch (table[i],arg)) {
			ix = i;		/* index of last match */
			matches[count++] = table[i];
			if (strcmp(table[i],arg) == 0)  exactmatch = i;
		}
	}
	matches[count] = 0;

	if (count == 1)  return (ix);
	if (exactmatch >= 0)  return (exactmatch);

	if (!quiet) {
		if (strcmp(arg,"?") == 0) {
			wantlist = TRUE;
		}
		else {
			printf ("%s is %s.  ",arg,(count ? "ambiguous" : "unknown"));
			wantlist = getbool ("Do you want a list?",TRUE);
		}
		if (wantlist) {
			printf ("Must match one of these:\n");
			if (count)  prstab (matches);
			else	    prstab (table);
		}
	}
	return (count ? AMBIGUOUS : NOTFOUND);
}
