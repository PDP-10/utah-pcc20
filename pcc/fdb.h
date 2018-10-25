/* 
 * fdb.h - layout of Tops-20 File Descriptor Block
 * 
 * Author:	Jay Lepreau
 * 		Computer Science Dept.
 * 		University of Utah
 * Date:	20 January 1982
 * Copyright (c) 1982 Jay Lepreau
 */

struct fdb {
    unsigned		: 29;		/* 0 - FBhdr */
    unsigned FB_len	: 7;

/*  unsigned FBctl;			/* 1 */
    unsigned 		: 7;		/* 0-6 */
    unsigned FB_dir	: 1;		/* 7 - directory */
    unsigned		: 2;		/* 8-9 */
    unsigned FB_sdr	: 1;		/* 10 - dir has subdirs */
    unsigned FB_arc	: 1;		/* 11 - archive status */
    unsigned FB_inv	: 1;		/* 12 - invisible */
    unsigned FB_off	: 1;		/* 13 = offline */
    unsigned FB_fcf	: 4;		/* 14-17 - class field */
    unsigned FB_unus1	: 18;		/* 18-35 - unused */

    unsigned FBexl;			/* 2 */
    unsigned FBadr;			/* 3 */
    unsigned FBprt;			/* 4 - protection; LH 500000 */
    unsigned FBcre;			/* 5 - last write time */
    unsigned FBaut;			/* 6 - ptr to author name str,7 bit! */

    unsigned FB_gen	: 18;		/* 7a - generation number */
    unsigned FB_drn	: 18;

    unsigned FBact;			/* 10 */

    unsigned FB_ret	: 6;		/* 11a - gen retention cnt */
    unsigned FB_bsz	: 6;		/* 11b - File bye size */
    unsigned		: 2;
    unsigned FB_mod	: 4;		/* 11c - Data mode of last open */
    unsigned FB_pgc	: 18;		/* 11d - page count */

    unsigned FBsiz;			/* 12 - size in bytes */
    unsigned FBcrv;			/* 13 - creation time */
    unsigned FBwrt;			/* 14 - last user write time */
    unsigned FBref;			/* 15 - last non-write time */
    WORD     FBcnt;			/* 16 - LH # writes, RH # refs */
    unsigned FBbk0;			/* 17 - for dumper */
    unsigned FBbk1;			/* 20 - reserved */
    unsigned FBbk2;			/* 21 - reserved */

    unsigned		: 18;		/* 22a - archive stuff */
    unsigned AR_psz	: 18;		/* 22b - pages pre-archive */

    unsigned FBnet;			/* 23 - expiration time */

/*  unsigned FBusw;			/* 24 - for user = link table idx */
    unsigned FBlnk;

    unsigned FBgnl;			/* 25 - adr of fdb of next gen:type? */
    unsigned FBnam;			/* 26 - ptr to filename block :type? */
    unsigned FBext;			/* 27 - ptr to filetype blk   :type? */
    unsigned FBlwr;			/* 30 - ptr to last writer str,7 bit!*/
    unsigned FBmisc_arc[6];		/* 31-36 more archive stuff */
};
#define FBlen 037	 		/* length of the fdb */
