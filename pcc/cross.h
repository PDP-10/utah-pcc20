/* 
 * cross.h - Stuff to allow big constants for cross-compile.
 * 
 * Author:	Jay Lepreau
 * 		Computer Science Dept.
 * 		University of Utah
 * Date:	Feb 1981
 * Copyright (c) 1981 Jay Lepreau
 */

#ifdef CROSSCOMP
  static int ccbits;
  static int ccsh18 = 18;
# define makeword(b, shift) (ccbits = (b), ccbits << (shift))
# define makeleft(b) ((b) << ccsh18)

#else
/* # define makeword(b, shift) ((b) << (shift)) */
# define makeleft(b) ((b) << 18)

#endif

#define getright(b) ((b) & 0777777)	/* this should probably be elsewhere */
#define getpleft(b)  ((b) >> 18)	/* get positive left half.	     */
#define getnleft(b)  (((b)>>18) | ~0777777)     /* neg lhs. not arith shift! */
