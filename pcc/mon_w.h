/* wild functions */

#define WLstr 00		/* compare two strings */
#define WLjfn 01		/* compare two jfns */

/* wild flags and bits */

#define WL_lcd 01:35-0		/* don't convert lower case to upper case */
#define WL_nom 01:35-0		/* strings did not match */
#define WL_abr 01:35-1		/* non-wild string is abbreviation of wild string */
#define WL_dev 01:35-1		/* device field did not match */
#define WL_dir 01:35-2		/* directory field did not match */
#define WL_nam 01:35-3		/* name field did not match */
#define WL_ext 01:35-4		/* file type did not match */
#define WL_gen 01:35-5		/* generation number did not match */
