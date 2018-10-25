/*----------------------------------------------------------------------*\
 |
 |	debug.h
 |
 |	this file contains the defines necessary to implement the
 |	conditional compilation of debugging macros.
 |
 |	86/01/25		tjk & gsm
 |
 |	XENIX 3.01.00		Tandy 6000
 |
 |	USAGE:  to utilize this debugging tool, simply include instances
 |	of the type specific debug macros liberally throughout your code.
 |	If you are using types not included, create a debug macro for the
 |	type you wish to include by following the format of the existing
 |	macros.  Then simply use a -DDEBUG in your cc call to enable the
 |	debugging macros.  It is necessary that debug.h be included in
 |	your source AFTER stdio.h.
 |
 |	Copyright 1986 Thomas J Keller, Gregory S. Melancon
 |
 |	NOTE:  the macros in this package are based on material published
 |	by Thomas D. Webb in Vol 3, No 2 of Computer Language Magazine.
 |
 |	Permission is hereby granted for the use of this software for
 |	any use, with the stipulation that the copyright and attribution
 |	notices remain intact, and that the authors and Thomas D. Webb
 |	are credited if used in commercial software.
 |
\*----------------------------------------------------------------------*/


#ifdef DEBUG

/*	in DEBUG mode, PASSTHRU translates debug macros to fprintf statements
 *	by macro substitution.
 */

#    define	PASSTHRU(statements) statements
#    ifdef OCTAL
#        define	SPEC	'%03o'
#    else
#	define	SPEC	0x%02x
#    endif

#else

/*	in normal mode, PASSTHRU translates debug macros into null strings
 *	by macro substitution.
 */

#    define	PASSTHRU(statements)	/* empty */
#endif

/*	debug macro definitions      */


/* print a char variable */

# define	DCHAR(userText, charVar) \
		PASSTHRU(if (charVar == '\040') \
			    fprintf(stderr, "DEBUG: %s: BLANK char\n", \
				    userText); \
			else if (charVar == '\000') \
			    fprintf(stderr, "DEBUG: %s: NULL char\n", \
			    	    userText); \
			else \
			    fprintf(stderr, "DEBUG: %s: SPEC\n", \
				    userText, charVar))


/* print a short integer variable */
# define	DSHORT(userText, shortVar) \
		PASSTHRU(fprintf(stderr, "DEBUG: %s: %d\n", userText, shortVar))


/* print an integer variable */
# define	DINT(userText, intVar) \
		PASSTHRU(fprintf(stderr, "DEBUG: %s: %d\n", userText, intVar))


/* print a long integer variable */
# define	DLONG(userText, longVar) \
		PASSTHRU(fprintf(stderr, "DEBUG: %s: %ld\n", userText, longVar))


/* print an unsigned char variable */
# define	DUCHAR(userText, ucharVar) \
		PASSTHRU(fprintf(stderr, "DEBUG: %s: %u\n", userText, ucharVar))


/* print an unsigned short integer variable */
# define	DUSHORT(userText, ushortVar) \
		PASSTHRU(fprintf(stderr, "DEBUG: %s: %u\n", \
			 userText, ushortVar))


/* print an unsigned integer variable */
# define	DUINT(userText, uintVar) \
		PASSTHRU(fprintf(stderr, "DEBUG: %s: %u\n", userText, uintVar))


/* print an unsigned long integer variable */
# define	DULONG(userText, ulongVar) \
		PASSTHRU(fprintf(stderr, "DEBUG: %s: %ul\n", \
			 userText, ulongVar))


/* print a float variable */
# define	DFLOAT(userText, floatVar) \
		PASSTHRU(fprintf(stderr, "DEBUG: %s: %f\n", userText, floatVar))


/* print a double float variable /*
# define	DDOUBLE(userText, doubleVar) \
		PASSTHRU(fprintf(stderr, "DEBUG: %s: %fl\n", \
			 userText, doubleVar))


/* print a string variable */
# define	DSTRING(userText, stringVar) \
		PASSTHRU(if (stringVar[0] == NULL) \
			     fprintf(stderr, "DEBUG: %s: NULL string\n", \
				     userText); \
			 else \
			     fprintf(stderr, "DEBUG: %s: \"%s\"\n", \
				     userText, stringVar))


/* print a debug message, no variables */
# define	DMSG(userText) \
		PASSTHRU(fprintf(stderr, "DEBUG: %s\n", userText))


/* print a function entry message */
# define	DENTER(funcName)\
		PASSTHRU(fprintf(stderr, "DEBUG: %s >>>>>>>>\n", \
				 funcName))


/* print a function exit message */
# define	DEXIT(funcName) \
		PASSTHRU(fprintf(stderr, "DEBUG: %s <<<<<<<<\n", \
			 funcName))


/* print a function failure stop message */
# define	DSTOP(funcName) \
		PASSTHRU(fprintf(stderr, "DEBUG: %s FAILURE #########\n",\
			 funcName))


/* print an errno error message */
#define		DERROR(userText, funcName) \
		PASSTHRU(fprintf(stderr, "DEBUG: %s: ", \
		funcName);\
		perror(userText))
