/*
 * u2.c - More Unix system calls
 *	  lseek, tell, stat, fstat, getuid, utime, chmod
 *
 * Author:	Jay Lepreau
 *		Computer Science Dept.
 *		University of Utah
 * Date:	1 January 1982
 * Copyright (c) 1982 Jay Lepreau
 */

#include "tops20.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "fdb.h"
#include "topsdir.h"
#include "mon_u2.h"
#include <assert.h>

/* Note the problems caused by cr/lf: relative positioning won't work! */
long
lseek(fd, offset, whence)
long offset;
{
    int jfn = jfnof(fd);
    int Acs[5];			/* can't use acs cause calls another jsys'er */
    
    Acs[1] = jfn;
    switch (whence) {
	case 0:				/* set to offset */
	    Acs[2] = offset;
	    break;

	case 1:
	    if (offset == 0)		/* specal case it for efficiency */
	        return (tell(jfn));
	    Acs[2] = tell(jfn) + offset;
	    break;

	case 2:
	    Acs[2] = _gtfsz(jfn) + offset;
	    break;

	default:
	    perror("Bad arg to lseek");	/* to _seterr later */
	    exit(1);
    }

    if (jsys(JSsfptr, Acs) == JSerr) {
	perror("lseek");
	return(-1);
    }
    return (Acs[2]);
}

long
tell(fd)
{
    int jfn = jfnof(fd);

    ac1 = jfn;
    if (jsys(JSrfptr, acs) == JSerr) {
	perror("tell");
	return(-1);
    }
    return(ac2);
}

int				/* get open file size */
_gtfsz(jfn)
{
    ac1 = jfn;
    if (jsys(JSsizef, acs) == JSerr) {
	perror("_gtfsz");
	exit(2);
    }
    return(ac2);
}

#define WREAD	04			/* "world" read */
#define WWRITE	02
#define WEXEC	01

char *_dirnm();
char *index();

int				/* Unix stat(2) */
stat(name, statp)
char *name;
struct stat *statp;
{
    int		jfn;
    int		retcode;

    if ((jfn = _gtjfn(name, Value(GJ_old) | Value(GJ_sht))) == -1)
	return(-1);
    retcode = fstat(jfn, statp);
    if (_rljfn(jfn) == -1)
	_syserr("stat - rljfn");
    return(retcode);
}

int					/* Unix fstat(2) */
fstat(fd, statp)
register struct stat *statp;
{
    int		jfn;
    struct fdb	fdb;
    register struct fdb	*f = &fdb;
    register unsigned	tprot,		/* tops20 protection field */
    			uprot,		/* unix protection */
			prot;		/* working copy */
    register int	tshift;
    char		user[MAXUSERL];

    ac1 = jfn = jfnof(fd);
    ac2 = makeword(FBlen, 0);		/* get the whole fdb */
    ac3 = (int)f;
    if (jsys(JSgtfdb, acs) == JSerr) {
    	_seterr();
	if (_errno == ERgfdbx3)		/* list access req'd, not error */
	    return(-1);		/* is this right, or can i set some bits? */
	perror("gtfdb");		/* should do a DVCHR now to */
	exit(SYSERR);			/* check for char special: */
    }					/* ttys, ptys, & nul: */
    if (f->FBlnk != 0) {
	perror("stat - links NYI");
	exit(SYSERR);
    }
    statp->st_nlink = 1;		/* for now */
    statp->st_size = f->FBsiz;
    statp->st_atime = _t2utim(f->FBref);	/* convert all these to Unix */
    statp->st_mtime = _t2utim(f->FBwrt);	/*   internal format */
    statp->st_ctime = _t2utim(f->FBcre);

/* Get author name via gfust */
    ac1 = makeword(GFaut, jfn);
    ac2 = POINT(user);
    if (jsys(JSgfust, acs) == JSerr) {
	perror("gfust");
	exit(SYSERR);
    }

    statp->st_uid = _rcusr(user);	/* name to uid, -1 if no good */

    statp->st_mode = 0;
    if (f->FB_dir) {
	statp->st_mode |= S_IFDIR;
	prot = gtdirprot(_dirnm(jfn));	/* returns 20 fmt protection */
	for (tshift=12, uprot=0; tshift >= 0; tshift -= 6) {
	    tprot = prot >> tshift;	/* pick up next field */
	    uprot <<= 3;
	    if (tprot & DP_rd)
		uprot |= WREAD|WEXEC;	/* world read, world execute */
	    if (tprot & (DP_cn|DP_cf))	/* allow write for either conn. */
		uprot |= WWRITE;	/*   access or add files access */
	}
    }
    else {  /* do it this way so easily modified-- i know it could be faster */
	prot = getright(f->FBprt);		/* zap the 500000 */
	statp->st_mode |= S_IFREG;		/* for now */
	for (tshift=12, uprot=0; tshift >= 0; tshift -= 6) {
	    tprot = prot >> tshift;
	    uprot <<= 3;
	    uprot |= (tprot >> 3) & 07;		/* just r,w,x */
	}
    }
    statp->st_mode |= uprot;
    statp->st_dev = getleft(f->FBadr) & 007777;	/* close enuf for now */
    statp->st_ino = getright(f->FBadr);	/* close enuf for now */
    statp->st_gid = 0;			/* zero all unused entries */
    statp->st_rdev = 0;

/* Now for ones unique to tops-20 */
    statp->st_bytesz = f->FB_bsz;

    return (0);
}

int    		/* translate name to uid, returns -1 if no match */
_rcusr(user)
char *user;
{
    ac1 = Value(RC_emo);		/* exact match required */
    ac2 = POINT(user);
    if (jsys(JSrcusr, acs) == JSerr) {
	_seterr();
	if (ac1 & Value(RC_nom))
	    return -1;
	else
	    _syserr("_rcusr");
    }
    else
	return getright(ac3);
}

int
getuid()
{
    return getright(_getji(JIuno));
}

int
_getji(offset)
{
    unsigned stuff;

    ac1 = -1;
    ac2 = makeword(-1, (int)&stuff);
    ac3 = offset;
    if (jsys(JSgetji, acs) == JSerr) {
	perror("getji");
	exit(SYSERR);
    }
    return(stuff);
}


/* stuff for getting protection of a directory */
int
gtdirprot(dir)
char *dir;
{
    struct topsdir dirb;
    int    ugldummy = 0;			/* dummy user grp list */
    int    dgldummy = 0;			/* dummy dir grp list */
    char   junk[40];

    ac1 = Value(RC_emo);		/* exact match */
    ac2 = POINT(dir);
    if (jsys(JSrcdir, acs) == JSerr) {
	perror("stat - rcdir");
	exit(SYSERR);			/* don't think should ever happen */
    }
    ac1 = ac3;				/* dir # */
    ac2 = (int) &dirb;
    ac3 = POINT(junk);			/* password might get put here */
    dirb.CDlen = sizeof(dirb);		/* we don't have whole one yet */
    dirb.CDugp = &ugldummy;
    dirb.CDdgp = &dgldummy;
    if (jsys(JSgtdir, acs) == JSerr) {
	perror("stat - gtdir");
	exit(SYSERR);
    }
    return(dirb.CDdpt);
}

/* This should use the standard file-name parsing routines.
 * It also needs to special-case ROOT-DIRECTORY, and not tack
 * it on the front...
 */

#ifdef notdef
char *		/* cnvt jfn of a .directory file to abs dir path */
_dirnm(jfn)
{
    char buf[FNMAX];
    char dir[FNMAX];
    register int  len;
    register char *p,
    		  *q;

    len = _jfns(buf, jfn, 0, 0);
    if ((p = index(buf, '>')) == 0) {	/* find end of dir */
	perror("dirnm1");
	exit(SYSERR);
    }
    *p = '\0';
    strcpy(dir, buf);			/* copy dir up to the '>' */
    if ((q = index(p+1, '.')) == 0) {	/* find end of fn1 (unless have ^Vs) */
	perror("dirnm2");
	exit(SYSERR);
    }
    *q = '\0';
    strcat(dir, ".");			/* stick a dot between the dirs */
    strcat(dir, p+1);
    strcat(dir, ">");
    return(dir);
}
#endif

char *		/* cnvt jfn of a .directory file to abs dir path */
_dirnm(jfn)
{
    char buf[FNMAX];
    static char dir[FNMAX];		/* should be in caller w/ 2 params */
    char temp[FNMAX];
    register int  len;
    register char *p,
    		  *q;

    ac1 = Value(RC_emo);	/* exact match */
    ac2 = jfn;
    if (jsys(JSrcdir, acs) == JSerr) {
	perror("dirnm - rcdir");
	exit(SYSERR);	/* don't think should ever happen */
    }

    ac2 = ac3;		/* dir # of dir this file is in */
    ac1 = POINT(buf);
    if (jsys(JSdirst, acs) == JSerr) {
	perror("dirnm - dirst");
	exit(SYSERR);
    }
    if ((p = index(buf, '>')) == 0) {	/* find end of dir */
	perror("dirnm1");
	exit(SYSERR);
    }
    *p = '\0';
    strcpy(dir, buf);			/* copy dir up to the '>' */
    strcat(dir, ".");
    len = _jfns(buf, jfn, 0, 0);
    strcat(dir, fngnm(buf, temp));	/* get fn1 and tack it on*/
    strcat(dir, ">");
    return(dir);
}

int					/* Unix utime(2) */
utime(file, timep)
char	*file;
time_t	timep[2];			/* accessed == ref, updated == wrt */
{
    int		jfn;
    int		rc1, rc2;
    struct fdb	fdb;

#define FDBIDX(fld) (&fdb.fld - (int *)&fdb)

    if ((jfn = _gtjfn(file, Value(GJ_old) | Value(GJ_sht))) == -1)
	return(-1);
    rc1 = _chfdb(jfn, FDBIDX(FBref), _u2ttim(timep[0]));
    rc2 = _chfdb(jfn, FDBIDX(FBwrt), _u2ttim(timep[1]));
    if (_rljfn(jfn) == -1)
	_syserr("utime - rljfn");
    return min(rc1, rc2);
}

#ifdef notyet
int
chmod(name, mode)
char *name;
{
    int		jfn;
    int		rc1;
    struct fdb	fdb;

    if ((jfn = _gtjfn(file, Value(GJ_old) | Value(GJ_sht))) == -1)
	return(-1);
    for (tshift=12, tprot=0; tshift >= 0; tshift -= 6) {
	tprot = prot >> tshift;
	uprot <<= 3;
	uprot |= (tprot >> 3) & 07;		/* just r,w,x */
    }


    rc1 = _chfdb(jfn, FDBIDX(FBprt), prot);
    if (_rljfn(jfn) == -1)
	_syserr("chmod - rljfn");
    return rc1;
}
#endif

int
_chfdb(jfn, idx, val)
{
    ac1 = jfn | (idx << Getshift(CF_dsp));
    ac2 = -1;
    ac3 = val;
    if (jsys(JSchfdb, acs) == JSerr) {
	_seterr();
	if (_errno != ERcfdbx3)		/* write or owner access reqd */
	    _syserr("_chfdb");
	return -1;
    }
    return 0;
}
