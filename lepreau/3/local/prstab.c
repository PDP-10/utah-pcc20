/*  prstab  --  print list of strings
 *
 *  Usage:  prstab (table);
 *	char **table;
 *
 *  table is an array of pointers to strings, ending with a 0
 *  value.  This is the same format as "stablk" tables.
 *
 *  prstab will attempt to print the strings in a concise format,
 *  using multiple columns if its heuristics indicate that this is
 *  desirable.
 *
 *  The heuristics are these:  assume that each column must be at
 *  least as wide as the longest string plus three blanks.  Figure
 *  out how many columns can fit on a line, and suppose that we use
 *  that many columns.  This represents the "widest" useable format.
 *  Now, see if this is too wide.  This means that there are just a
 *  few strings, and we would like them to be printed in fewer columns,
 *  with each column being a little bit longer.  The heuristic rule is
 *  that we will always use at least some minimum number of rows (8)
 *  if there are at least that many strings.
 *
 *  HISTORY
 * 16-Apr-80  Steven Shafer (sas) at Carnegie-Mellon University
 *	Created.
 *
 */

#define SPACE 5			/* min. space between columns */
#define MAXCOLS 71		/* max. cols on line */
#define MINROWS 8		/* min. rows to be printed */

prstab (list)
char **list;
{
	register int nelem;	/* # elements in list */
	register int maxwidth;	/* widest element */
	register int i,l;	/* temps */
	register int row,col;	/* current position */
	register int nrow,ncol;	/* desired format */
	char format[20];	/* format for printing strings */

	maxwidth = 0;
	for (i=0; list[i]; i++) {
		l = strlen (list[i]);
		if (l > maxwidth)  maxwidth = l;
	}

	nelem = i;
	if (nelem <= 0)  return;

	ncol = MAXCOLS / (maxwidth + SPACE);
	if (ncol > (nelem + MINROWS - 1) / MINROWS)
		ncol = (nelem + MINROWS - 1) / MINROWS;
	nrow = (nelem + ncol - 1) / ncol;

	sprintf (format,"%%-%ds",maxwidth+SPACE);

	for (row=0; row<nrow; row++) {
		printf ("\t");
		for (col=0; col<ncol; col++) {
			i = row + (col * nrow);
			if (i < nelem)  printf (format,list[i]);
		}
		printf ("\n");
	}
}
