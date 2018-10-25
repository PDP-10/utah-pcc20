/* efact - fact file entry definitions */

#define EFhdr 00		/* header word */
#define EF_cod 0777:35-8	/* entry type code */
#define EF_job 0777:35-17	/* job number */
#define EF_lin 07777:35-29	/* line number */
#define EF_siz 077:35-35	/* entry size */
#define EFusr 01		/* user number word */
#define EFtad 02		/* time and date of entry */

/* fact file entry type codes */

#define EFlgi 0501		/* login */
#define EFlgo 0141		/* logout */
#define EFcac 0502		/* change account */
#define EFatt 0142		/* console attach */
#define EFdet 0143		/* console detach */
#define EFchk 0201		/* checkpoint */
#define EFsdu 0540		/* start disk-utilization entries */
#define EFdsk 0601		/* disk space utilization */
#define EFtim 0741		/* time set */
#define EFres 0740		/* system restarted */
#define EFlpt 0401		/* line printer usage */
#define EFcdr 0402		/* card reader usage */
