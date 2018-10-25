/*
 * From Alan Snyder's/Eliot Moss's C library
 *
 * Adapted to new Tops-20 gtjfn capabilities 8/82 by J.Lepreau
 */

# define FNSIZE 100
# define QUOTE	022	/* ^V */
# define EOS	'\0'	/* end-of-string */

/*

	TOPS-20 filename cluster: partial, rest is in fnstd2.c
	These are separate cause required for run-time start-up.

	components:
		DEV:<DIR>NAME.TYP.GEN;ATTR
		All components manipulated without punctuation,
			except ATTR.
	Also accepts UNIX format:
		@DEV/DIR1/DIR2/.../DIRn/NAME.TYP.GEN;ATTR
	as equivalent to:
		DEV:<DIR1.DIR2....DIRn>NAME.TYP.GEN;ATTR

*/

/* declarations of internal procedures */
static char *fnscan();

char *_fnsmove();	/* this is global now */

/**********************************************************************

	FNPARSE - Parse file name into components.

**********************************************************************/

#define chkbar(p)	{if (*p == '/') ++p;}	/* skip adjacent slashes */

fnparse (old, dv, dir, nm, typ, gen, attr)
register char *old;
char *dv, *dir, *nm, *typ, *gen, *attr;
{
	register char *p, *q;

	*dv = *dir = *nm = *typ = *gen = *attr = 0;
	while (old[0] == ' ') ++old;
	p = fnscan (old, ":<");
	if (*p == 0) {		/* must be OK in UNIX format */
#ifndef ABS_GTJFN
		if (old[0] == '@')	/* get device part */
#else
		if (old[0] == '/')	/* get device part */
#endif
			{p = fnscan (old+1, "/");
			_fnsmove (old+1, p, dv);
			old = p + 1;
			chkbar(old);
			}
		q = dir;
		if (*old != '/')
		    *q++ = '.';		/* relative dir */
		else
		    old++;		/* abs dir */
		while (1)		/* get dir parts */
			{p = fnscan (old, "/.;");
			if (*p != '/') break;
			if (q != dir) *q++ = '.';
			_fnsmove (old, p, q);
			q += (p - old);
			old = p + 1;
			chkbar(old);
			}
		_fnsmove (old, p, nm);		/* get name part */
		if (*p == 0) return;
		if (*p == '.')
			{old = p + 1;		/* get type part */
			p = fnscan (old, ".;");
			_fnsmove (old, p, typ);
			if (*p == 0) return;
			}
		if (*p == '.')
			{old = p + 1;		/* get gen part */
			p = fnscan (old, ";");
			_fnsmove (old, p, gen);
			if (*p == 0) return;
			}
		_fnsmove (p, 0, attr);		/* get attr part */
		return;
		}

	if (old[0] != '<')
		{p = fnscan (old, ":");
		if (*p == ':')
			{_fnsmove (old, p, dv);
			old = p+1;
			}
		}
	if (old[0] == '<')
		{p = fnscan (old+1, ">");
		_fnsmove (old+1, p, dir);
		if (*p == 0) return;
		old = p+1;
		}
	p = fnscan (old, ".;");
	_fnsmove (old, p, nm);
	old = p+1;
	if (*p == '.')
		{p = fnscan (old, ".;");
		_fnsmove (old, p, typ);
		old = p+1;
		if (*p == '.')
			{p = fnscan (old, ";");
			_fnsmove (old, p, gen);
			}
		}
	if (*p == ';')
		_fnsmove (p, 0, attr);
	}

/**********************************************************************

	FNCONS - Construct a file name from its components.

**********************************************************************/

char
*fncons (buf, dv, dir, nm, typ, gen, attr)
	register char *buf;
	char *dv, *dir, *nm, *typ, *gen, *attr;
{
	int more;

	if (dv && dv[0]) {
	    buf = _fnsmove (dv, 0, buf);
	    *buf++ = ':';
	}
	if (dir && dir[0]) {
	    *buf++ = '<';
	    buf = _fnsmove (dir, 0, buf);
	    *buf++ = '>';
	}
	if (nm)
	    buf = _fnsmove (nm, 0, buf);
	more = ((typ && typ[0]) || (gen && gen[0]) || (attr && attr[0]));
	if (more) {
	    *buf++ = '.';
	    if (typ && typ[0])
		buf = _fnsmove (typ, 0, buf);
	    *buf++ = '.';
	    if (gen && gen[0])
		buf = _fnsmove (gen, 0, buf);
	    if (attr && attr[0]) {
		if (attr[0] != ';') *buf++ = ';';
		_fnsmove (attr, 0, buf);
	    }
	}
	*buf = '\0';
	return (buf);
}

/****************************************************************

	FNSTD - standardize file name in TOPS-20 format

****************************************************************/

	/* NOTE: params reversed from Snyder - fjl */
fnstd (outs, ins)
	char *outs, *ins;
{			/* make dir longer than allowed to avert blow up */
	char dev[30], dir[60], name[40], type[40], gen[20], attr[30];

	fnparse (ins, dev, dir, name, type, gen, attr);
	fncons (outs, dev, dir, name, type, gen, attr);
}



/******** Internal procedures **********/

static
char *
fnscan (p, m)
register char *p;
char *m;
{
	while (1) {
		register int c;
		register char *q;
		c = *p;
		if (c == QUOTE)
			{c = *++p;
			if (c == 0) return (p);
			++p;
			continue;
			}
		q = m;
		while (1)
			{if (*q == c) return (p);
			if (*q == 0) break;
			++q;
			}
		++p;
		}
	}

/*
 * Internal routine: _FNSMOVE
 *
 * Move characters starting with *FROM up to (but not
 * including) *ENDM1 into *DEST.  If ENDM1 is null, then
 * move characters until a NUL byte is encountered.
 * Always terminate the destination with a NUL byte
 * and return a pointer to the terminating NUL.
 *
 */

char *				/* from, endm1, dest */
_fnsmove (first, after, dest)
register char *first, *after, *dest;
{
	while (!after || first < after)
		if (!(*dest++ = *first++)) return (dest-1);
	*dest = 0;
	return (dest);
	}
