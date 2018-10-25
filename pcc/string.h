/*  string --  declarations for string-handling routines at CMU
 *
 *  HISTORY
 */

/* index function; case-folding */
char *sindex(), *index(), *rindex();
char *fold(), *foldup(), *folddown();

/* conversion to numerals */
unsigned int atoo(), atoh();

/* string table lookup */
int stlmatch(), stablk();

/* parsing routines */
char *skipto(), *skipover(), *nxtarg();

/* ask user for value; parse value */
int getbool(), boolarg();
int getchr(), chrarg();
int getint(), intarg();
short getshort(), shortarg();
long getlong(), longarg();
unsigned int getoct(), octarg();
unsigned int gethex(), hexarg();
float getfloat(), floatarg();
double getdouble(), doublearg();
char *getstr(), *strarg();
int getstab(), stabarg();
