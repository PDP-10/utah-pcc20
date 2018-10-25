/* deldf */

#define DD_dtf 01:35-0		/* delete temporary files */
#define DD_dnf 01:35-1		/* delete nonexistent files */
#define DD_rst 01:35-2		/* rebuild the symbol table */
#define DD_chk 01:35-3		/* check the dir for consistency only */


/* delf */

#define DF_nrj 01:35-0		/* don't release jfn */
#define DF_exp 01:35-1		/* expunge contents */
#define DF_fgt 01:35-2		/* forget (expunge w/o deassigning addresses) */
#define DF_dir 01:35-3		/* delete, forget, and expunge a directory */
				/* file.  (only if ^e-create kill failed) */
#define DF_arc 01:35-4		/* delete of archive status file allowed */
#define DF_cno 01:35-5		/* delete only contents of file */
				/* immediate expunge implied */

#define DF_jfn 0777777:35-35	/* jfn */


/* diag jsys definitions */

#define DG_adt 07:35-2		/* address type field */
#define DG_dvc 0177:35-9	/* device code field */
#define DGrh0 0130	 	/* mbc0 */
#define DGrh7 0137	 	/* mbc7 */
#define DG_uni 077:35-29	/* unit number */
#define DG_sun 077:35-35	/* subunit number */

/* diag jsys function codes   */

#define DGacu 01		/* assign device */
#define DGach 02		/* assign controller and all devices */
#define DGrch 03		/* release device(s) */
#define DGscp 04		/* setup channel program */
#define DGrcp 05		/* release channel program */
#define DGgcs 06		/* get channel status */

/* diag new control functions */

#define DGgem 0100		/* leave large hole for more rh20 functions */
				/* get mem (for tgha) */
#define DGrem 0101		/* release mem (for tgha) */
#define DGpdl 0102		/* unit online */


/* dskas */

#define DA_dea 01:35-0		/* deassign disk address */
#define DA_asf 01:35-1		/* assign free page */
#define DA_cnv 01:35-2		/* convert software to hardware address */
#define DA_hwa 01:35-3		/* hardware address given */
#define DA_ini 01:35-4		/* initialize the bit table */
#define DA_wrt 01:35-5		/* write the bit table file */
#define DA_adr 0777777:35-35	/* disk address */


/* dvchr, devunt and dvch1 bit definitions */

#define DV_out 01:35-0		/* device can do output */
#define DV_in 01:35-1		/* device can do input */
#define DV_dir 01:35-2		/* device has a directory */
#define DV_as 01:35-3		/* device is assignable */
#define DV_mdd 01:35-4		/* device is a multiple directory device */
#define DV_av 01:35-5		/* device is available to this job */
#define DV_asn 01:35-6		/* device is assigned by asnd */
#define DV_mdv 01:35-7		/* reserved (historical) */
#define DV_mnt 01:35-8		/* device is mounted */
#define DV_typ 0777:35-17	/* device type field */
#define DV_psd 01:35-18		/* pseudo device */
#define DV_unt 077777		/* unit mask */
#define DV_mod 0177777:35-35	/* device data mode */
#define DV_m0 01:35-35		/* device can be opened in mode 0 */
#define DV_m1 01:35-34		/* device can be opened in mode 1 */
#define DV_m2 01:35-33		/* device can be opened in mode 2 */
#define DV_m3 01:35-32		/* device can be opened in mode 3 */
#define DV_m4 01:35-31		/* device can be opened in mode 4 */
#define DV_m5 01:35-30		/* device can be opened in mode 5 */
#define DV_m6 01:35-29		/* device can be opened in mode 6 */
#define DV_m7 01:35-28		/* device can be opened in mode 7 */
#define DV_m10 01:35-27		/* device can be opened in mode 10 */
#define DV_m11 01:35-26		/* device can be opened in mode 11 */
#define DV_m12 01:35-25		/* device can be opened in mode 12 */
#define DV_m13 01:35-24		/* device can be opened in mode 13 */
#define DV_m14 01:35-23		/* device can be opened in mode 14 */
#define DV_m15 01:35-22		/* device can be opened in mode 15 */
#define DV_m16 01:35-21		/* device can be opened in mode 16 */
#define DV_m17 01:35-20		/* device can be opened in mode 17 */
#define D1_spl 01:35-0		/* device is spooled */
#define D1_alc 01:35-1		/* device is under control of allocator */
#define D1_vvl 01:35-2		/* volume valid */
#define D1_niu 01:35-3		/* device slot is not in use (for structures  */
				/* not yet mounted) */
#define D1_ini 01:35-4		/* device is being initialized (structure */
				/* is available only to the fork whose number */
				/* is stored in sdbsts) */



/* device type definitions */

#define DVdsk 00		/* disk */
#define DVmta 02		/* magtape */
#define DVdta 03		/* dectape */
#define DVptr 04		/* paper tape reader */
#define DVptp 05		/* paper tape punch */
#define DVdsp 06		/* display */
#define DVlpt 07		/* line printer */
#define DVcdr 010		/* card reader */
#define DVfe 011		/* front end device */
#define DVtty 012		/* terminal */
#define DVpty 013		/* pty */
#define DVnul 015		/* null device */
#define DVnet 016		/* arpa network */
#define DVplt 017		/* plotter */
#define DVcdp 021		/* card punch */
#define DVdcn 022		/* decnet active component */
#define DVsrv 023		/* decent passive component */
#define DVats 024		/* applications terminal service */
#define DVads 025		/* aydin display */


/* dskop */

#define DOp_sa 01:35-0		/* software address */
#define DOp_at 03:35-1		/* address type field */
#define DOppu 01		/* physical channel and unit */
#define DOp_cn 037:35-6		/* channel number */
#define DOp_un 077:35-12	/* unit number */
#define DOp_ua 037777777	/* unit address */
#define DOpsr 02		/* structure and relative address */
#define DOp_sn 0777:35-10	/* structure number */
#define DOp_ra 0177777777	/* relative address */
#define DOp_eo 01:35-10		/* error if unit offline */
#define DOp_il 01:35-11		/* inhibit error logging */
#define DOp_ir 01:35-12		/* inhibit error recovery */
#define DOp_wr 01:35-14		/* write */
#define DOp_ct 0777777:35-35	/* word count */


/* dumpi/dumpo */

#define DM_nwt 01:35-0		/* no wait for completion */
#define DM_fin 01:35-1		/* finish previous request */
				/* ***not inplemented yet*** */
#define DM_ptr 0777777:35-35	/* pointer to command list */



/* define decnet disconnect codes. these are stipulated by the nsp spec */
/* and may have meaninings not implied by the comments */

#define DCx0 00	 		/* no special error */
#define DCx1 01	 		/* resource allocation failure */
#define DCx2 02	 		/* destination node does not exist */
#define DCx3 03	 		/* node shutting down */
#define DCx4 04	 		/* destination process does not exist */
#define DCx5 05	 		/* invalid name field */
#define DCx6 06	 		/* destination process queue overflow */
#define DCx7 07	 		/* unspecified error */
#define DCx8 8			/* third party aborted link */
#define DCx9 9			/* user abort (asynchronous disconnect) */
#define DCx11 11		/* undefined error code */
#define DCx21 21		/* ci with illegal destination address */
#define DCx22 22		/* cc with illegal destination address */
#define DCx23 23		/* ci or cc with zero source address */
#define DCx24 24		/* flow control violation */
#define DCx32 32		/* too many connections to node */
#define DCx33 33		/* too many connections to dest. process */
#define DCx34 34		/* access not permitted */
#define DCx35 35		/* logical link services mismatch */
#define DCx36 36		/* invalid account */
#define DCx37 37		/* segsize too small */
#define DCx38 38		/* process aborted */
#define DCx39 39		/* no path to destination node */
#define DCx40 40		/* link aborted due to data loss */
#define DCx41 41		/* destination process does not exist */
#define DCx42 42		/* confirmation if di */
#define DCx43 43		/* image data field too long */
