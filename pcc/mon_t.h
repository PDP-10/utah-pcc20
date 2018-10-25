/* tbluk */

#define TL_nom 01:35-0		/* no match */
#define TL_amb 01:35-1		/* ambiguous */
#define TL_abr 01:35-2		/* legal abbreviation */
#define TL_exm 01:35-3		/* exact match */


/* tfork */

/* function codes in lh ac1 */

#define TFset 00		/* set traps as spec'd by bit table */
#define TFral 01		/* remove all traps set by this fork */
#define TFrtp 02		/* remove traps set by this fork */
#define TFsps 03		/* set jsys trap psi chan in lh(2) */
#define TFrps 04		/* read jsys trap psi chan into lh(2) */
#define TFtst 05		/* test if self monitored */
#define TFres 06		/* remove traps from all inferiors, clr psi */
#define TFuuo 07		/* set uuo traps for fork */
#define TFsju 08		/* set both uuo and jsys traps */
#define TFruu 09		/* remove uuo traps */

/* timer definitions */

#define TImrt 00		/* set time limit */
#define TImel 01		/* set elapsed time clock */
#define TImdt 02		/* set date & time clock */
#define TImdd 03		/* delete an explict date & time clock */
#define TImbf 04		/* delete all entires before d&t */
#define TImal 05		/* delete all (includes time limit) */



/* tlink */

#define TL_cro 01:35-0		/* clear remote to object link */
#define TL_cor 01:35-1		/* clear object to remote link */
#define TL_eor 01:35-2		/* establist object to remote link */
#define TL_ero 01:35-3		/* establish remote to object link */
#define TL_sab 01:35-4		/* set accept bit for object */
#define TL_abs 01:35-5		/* accept bit state */
#define TL_sta 01:35-6		/* set or clear advice */
#define TL_aad 01:35-7		/* accept advice */
#define TL_obj 0777777:35-35	/* object designator */
