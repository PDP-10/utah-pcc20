/*
 * Standard C macros
 *
 **********************************************************************
 * HISTORY
 * 23-Apr-81  Mike Accetta (mja) at Carnegie-Mellon University
 *	Added "sizeofS" and "sizeofA" macros which expand to the size
 *	of a string constant and array respectively.
 *
 **********************************************************************
 */

#define ABS(x)		((x) >= 0 ? (x):-(x))
#define MAX(a,b)	((a) > (b) ? (a):(b))
#define MIN(a,b)	((a) < (b) ? (a):(b))

#define FALSE		0
#define TRUE		1
#define	CERROR		(-1)

#define	sizeofS(string)	(sizeof(string) - 1)
#define sizeofA(array)	(sizeof(array)/sizeof(array[0]))
