/* 
 * topsdir.h - Layout of Tops-20 crdir argument block
 * 
 * Author:	Jay Lepreau
 * 		Computer Science Dept.
 * 		University of Utah
 * Date:	6 February 1982
 * Copyright (c) 1982 Jay Lepreau
 */

struct topsdir {
    unsigned		: 18;		/* 0 */
    unsigned CDlen	: 18;
    BYTEPTR7 CDpsw;			/* 1 - 7 bit byte ptr */
    int	     CDliq;			/* 2 - working quota(logged-in-quota)*/
    unsigned CDprv;			/* 3 - capabilities */
    unsigned 		: 36;		/* 4 - mode word */
    int	     CDloq;			/* 5 - perm quota (logged-out-quota) */
    unsigned CDnum;			/* 6 - directory number */
    unsigned CDfpt;			/* 7 - default file protection */
    unsigned CDdpt;			/* 10 - directory protection */
    int      CDret;			/* 11 - gen retention count */
    int      CDlld;			/* 12 - last login date */
    int     *CDugp;			/* 13 - addr of user grp list */
    int     *CDdgp;			/* 14 - addr of dir grp list */
    int      CDsdq;			/* 15 - subdir quota */
    /* .... */
};
