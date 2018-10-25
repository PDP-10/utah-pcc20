#include <file.h>

/*
 * Unix open(2), returns jfn.
 */
int		
open(filnam, type)
char	*filnam;
int	type;
{
	struct	stat	statb;
	int	flags,
		oflags,
		bastype,
		jfn;

	bastype = type & ~FATT_BINARY;

	switch (bastype) {
	    case FATT_RDONLY:
		flags = Value(GJ_old) | Value(GJ_sht);
		oflags = Value(OF_rd);
		break;

	    case FATT_WRONLY:
		flags = Value(GJ_fou) | Value(GJ_sht);
		oflags = Value(OF_wr);
		break;

	    case FATT_RDWR:
		flags = Value(GJ_sht);
		oflags = Value(OF_rd) | Value(OF_wr);
		break;

	    case FATT_APPEND:
		flags = Value(GJ_sht);
		oflags = Value(OF_app);

	    default:
		perror("Invalid mode to open");
		return(-1);
	}

	if ((jfn = _gtjfn(filnam, flags)) == -1) {
		_seterr();
		return(-1);
	}

#define BYTESIZE ( 36 / (sizeof(int)/sizeof(char)) )

	ac1 = jfn = getright(jfn);			/* clear left half */
	ac2 = makefield(OF_bsz, type & FATT_BINARY ? BYTESIZE : 7) | oflags;
	if (jsys(JSopenf, acs) == JSerr) {  /* could be dir, check for that */
	    _seterr();
#ifdef notyet
	    if (_errno == ERopnx13) {	/* invalid access */
		if (fstat(jfn, &statb) < 0)
		    goto badopen;
		if (statb.st_mode & S_IFDIR) {	/* must check protection */
		    if (statb.st_mode    )
			....		    
		}

	    }
#endif notyet
	    goto badopen;
	}

	ac1 = jfn;
	if (jsys(JSdvchr, acs) == JSerr) {
		perror("dvchr");	/* to _seterr later */
		goto badopen;
	}
	if (getfield(ac2, DV_typ) == DVtty) {
		_fotab[jfn]._flg |= _FOTTY|ECHO|CRMOD;	/* defaults */
		_ttynotrn(jfn);		/* set it not to translate output */
	}
	else
		_fotab[jfn]._flg &= ~_FOTTY;
	return(jfn);

badopen:
	_rljfn(jfn);
	return(-1);
}
