/* jfns */

#define JS_dev 07:35-2		/* device  field output control */
#define JS_dir 07:35-5		/* directory field output control */
#define JS_nam 07:35-8		/* name field output control */
#define JS_typ 07:35-11		/* file type field output control */
#define JS_gen 07:35-14		/* generation field output control */
#define JS_pro 07:35-17		/* protection field output control */
#define JS_act 07:35-20		/* account field output control */
	/* values for above 7 fields: */
#define JSnof 00	 	/* never output field */
#define JSaof 01	 	/* always output field */
#define JSssd 02	 	/* suppress if system default */
#define JS_tmp 01:35-21		/* return ;t if temp file */
#define JS_siz 01:35-22		/* return size */
#define JS_cdr 01:35-23		/* return creation date */
#define JS_lwr 01:35-24		/* return last write */
#define JS_lrd 01:35-25		/* return last read */
#define JS_ptr 01:35-26		/* ac 2 holds string pointer not jfn */
#define JS_atr 01:35-27		/* return attributes */
#define JS_at1 01:35-28		/* return 1 specific attribute */
#define JS_ofl 01:35-29		/* return ;off-line if offline file */
#define JS_psd 01:35-32		/* punctuate size and date */
#define JS_tbr 01:35-33		/* tab before fields returned */
#define JS_tbp 01:35-34		/* tab before possible fields */
#define JS_paf 01:35-35		/* punctuate all fields */

