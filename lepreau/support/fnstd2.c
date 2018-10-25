/* Largely from Alan Snyder's/Eliot Moss's C library */

# define FNSIZE 100
# define QUOTE	022	/* ^V */
# define EOS	'\0'	/* end-of-string */
/*
 *	TOPS-20 filename cluster: partial, rest is in fnstd1.c
 *	These are separate cause NOT required for run-time start-up.
 */

char *_fnsmove();	/* defined in fnstd1.c */

/************************************************************************
 *									*
 * fnunix - Standardize names into unix format - J.Lepreau 3/81		*
 *									*
 ************************************************************************/

	/* fnunix - cnvts *ins to unix fmt in *ux */
fnunix (ux, ins)
register char *ux;
char *ins;
{			/* make dir longer than allowed to avert blow up */
	char dev[30], dir[60], name[40], type[40], gen[20], attr[30];
	register char *p, c;

	fnparse (ins, dev, dir, name, type, gen, attr);
	if (dev[0] != EOS) {			/* have device field */
		*ux++ = '/';
		ux = _fnsmove(dev, 0, ux);
		*ux++ = '/';
	}
	if (dir[0] !=  EOS) {			/* have directory field */
		p = dir;
		while (c = *++p)		/* cnvt .'s to /'s */
			if (c == '.') *p = '/';
		ux = _fnsmove(dir, 0, ux);
		*ux++ = '/';
	}
	if (name[0] != EOS)			/* might as well be thorough */
		ux = _fnsmove(name, 0, ux);
	if (type[0] != EOS) {
		*ux++ = '.';
		ux = _fnsmove(type, 0, ux);
	}
	if (gen[0] != EOS) {
		*ux++ = '.';
		ux = _fnsmove(gen, 0, ux);
	}
	if (attr[0] != EOS)    /* attr returned by fnparse always includes ; */
		_fnsmove(attr, 0, ux);
	*ux = EOS;
}

/**********************************************************************

	FNGxx - Extract a given component.

**********************************************************************/

char
*fngdv (old, buf)
	char *old, *buf;

	{char temp[FNSIZE];
	fnparse (old, buf, temp, temp, temp, temp, temp);
	return (buf);
	}

char
*fngdr (old, buf)
	char *old, *buf;

	{char temp[FNSIZE];
	fnparse (old, temp, buf, temp, temp, temp, temp);
	return (buf);
	}

char
*fngnm (old, buf)
	char *old, *buf;

	{char temp[FNSIZE];
	fnparse (old, temp, temp, buf, temp, temp, temp);
	return (buf);
	}

char
*fngtp (old, buf)
	char *old, *buf;

	{char temp[FNSIZE];
	fnparse (old, temp, temp, temp, buf, temp, temp);
	return (buf);
	}

char
*fnggn (old, buf)
	char *old, *buf;

	{char temp[FNSIZE];
	fnparse (old, temp, temp, temp, temp, buf, temp);
	return (buf);
	}

char
*fngat (old, buf)
	char *old, *buf;

	{char temp[FNSIZE];
	fnparse (old, temp, temp, temp, temp, temp, buf);
	return (buf);
	}

/**********************************************************************

	FNSDF - Make a new file name with specified defaults.
	Nonzero arguments specify defaults; the corresponding
	components will be set if they are null.

**********************************************************************/

char
*fnsdf (buf, old, dv, dir, nm, typ, gen, attr)
	char *old, *buf, *dv, *dir, *nm, *typ, *gen, *attr;

	{char odv[FNSIZE], odir[FNSIZE], onm[FNSIZE],
	      otyp[FNSIZE], ogen[FNSIZE], oattr[FNSIZE];
	fnparse (old, odv, odir, onm, otyp, ogen, oattr);
	if (dv && odv[0]==0) _fnsmove (dv, 0, odv);
	if (dir && odir[0]==0) _fnsmove (dir, 0, odir);
	if (nm && onm[0]==0) _fnsmove (nm, 0, onm);
	if (typ && otyp[0]==0) _fnsmove (typ, 0, otyp);
	if (gen && ogen[0]==0) _fnsmove (gen, 0, ogen);
	if (attr && oattr[0]==0) _fnsmove (attr, 0, oattr);
	fncons (buf, odv, odir, onm, otyp, ogen, oattr);
	return (buf);
	}

/**********************************************************************

	FNSFD - Make a new file name with specified components.
	Nonzero arguments specify components; the corresponding
	components of the file name will be set.

**********************************************************************/

char
*fnsfd (buf, old, dv, dir, nm, typ, gen, attr)
	char *old, *buf, *dv, *dir, *nm, *typ, *gen, *attr;

	{char odv[FNSIZE], odir[FNSIZE], onm[FNSIZE],
	      otyp[FNSIZE], ogen[FNSIZE], oattr[FNSIZE];
	fnparse (old, odv, odir, onm, otyp, ogen, oattr);
	if (dv) _fnsmove (dv, 0, odv);
	if (dir) _fnsmove (dir, 0, odir);
	if (nm) _fnsmove (nm, 0, onm);
	if (typ) _fnsmove (typ, 0, otyp);
	if (gen) _fnsmove (gen, 0, ogen);
	if (attr) _fnsmove (attr, 0, oattr);
	fncons (buf, odv, odir, onm, otyp, ogen, oattr);
	return (buf);
	}
