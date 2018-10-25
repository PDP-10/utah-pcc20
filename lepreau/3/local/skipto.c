/*  skipover and skipto -- skip over characters in string
 *
 *  Usage:	p = skipto (string,charset);
 *		p = skipover (string,charset);
 *
 *  char *p,*charset,*string;
 *
 *  Skipto returns a pointer to the first character in string which
 *  is in the string charset; it "skips until" a character in charset.
 *  Skipover returns a pointer to the first character in string which
 *  is not in the string charset; it "skips over" characters in charset.
 *
 *  HISTORY
 * 20-Nov-79  Steven Shafer (sas) at Carnegie-Mellon University
 *	Adapted for VAX from skip() and skipx() on the PDP-11 (from
 *	Ken Greer).  The names are more mnemonic.
 *
 */

char *skipover (string,charset)
char *charset,*string;
{
	register char *setp,*strp;
	register int found;

	found = 0;			/* not found yet */
	strp = string;			/* start at first char */

	while (*strp && !found) {	/* until null or found */
		/* find first char in charset matching *strp */
		for (setp=charset; (*setp) && (*setp != *strp); setp++) ;
		if (*setp)	strp++;	/* not found yet */
		else		found = 1;
	}

	return (strp);
}

char *skipto (string,charset)
char *charset,*string;
{
	register char *setp,*strp;
	register int found;

	found = 0;			/* not found yet */
	strp = string;			/* start at first char */

	while (*strp && !found) {	/* until null or found */
		/* find first char in charset matching *strp */
		for (setp=charset; (*setp) && (*setp != *strp); setp++) ;
		if (*setp)	found = 1;	/* matches a char */
		else		strp++;		/* else keep looking */
	}

	return (strp);
}
