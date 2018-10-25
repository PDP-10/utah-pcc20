
# line 18 "pdate.y"
#include <sys/types.h>
#include <setjmp.h>
#include <time.h>
#include <c.h>

static struct tm *tm;			/* parsed time structure */
static char *strp;			/* current position in date string */
static int delim;			/* previous field delimiter */
static jmp_buf errbuf;			/* jump location for parse errors */
extern char *nxtarg();

/*
 *  Month and week day names (upper case only)
 */
static char *strings[] =
{
    "JANUARY",				/* months (0-11) */
    "FEBRUARY",
    "MARCH",
    "APRIL",
    "MAY",
    "JUNE",
    "JULY",
    "AUGUST",
    "SEPTEMBER",
    "OCTOBER",
    "NOVEMBER",
    "DECEMBER",
    "MONDAY",				/* days of the week (12-18) */
    "TUESDAY",
    "WEDNESDAY",
    "THURSDAY",
    "FRIDAY",
    "SATURDAY",
    "SUNDAY",
    "EST",				/* timezones */
    "EDT",
    "CST",
    "CDT",
    "MST",
    "MDT",
    "PST",
    "PDT",
    0
};
# define NUMBER 257
# define WEEKDAY 258
# define MONTH 259
# define AM 260
# define PM 261
# define TIMEZONE 262
#define yyclearin yychar = -1
#define yyerrok yyerrflag = 0
extern int yychar;
extern short yyerrflag;
#ifndef YYMAXDEPTH
#define YYMAXDEPTH 150
#endif
#ifndef YYSTYPE
#define YYSTYPE int
#endif
static YYSTYPE yylval, yyval;
# define YYERRCODE 256

# line 142 "pdate.y"


/*
 *  pdate - parse date specification into time structure
 *
 *  str = date specification string
 *  tmp = pointer to time structure to receive parsed fields
 *
 *      Parses the supplied date string and sets the appropriate
 *  fields into the time structure.  Fields which are not specified
 *  in the string are not changed in the structure (I think).
 *  The date string is copied into a temporary buffer before
 *  being parsed (maximum of 50 characters).
 *
 *     Returns 0 on a successful parse, -1 on error.
 */

pdate(str, tmp)
char *str;
struct tm *tmp;
{

    char tstr[51];

    /*  initialize lexical analyzer  */
    strncpy(strp = tstr, str, 50);
    tstr[51] = 0;
    tm = tmp;
    delim = 0;

    if (setjmp(errbuf) == 0)
    {
	yyparse();
	return(0);			/* return here on successful parse */
    }
    else
	return(CERROR);			/* return here on error */

}

/*
 *  yyerror - error routine (called by yyparse)
 *
 *     Performs a jump to the error return location established
 *  by pdate().
 */

static yyerror()
{

    longjmp(errbuf);

}



/*
 *  yylex - return next token in date string
 *
 *     Uses nxtarg() to parse the next field of the date string.
 *  If a non-space, tab, comma or newline delimiter terminated the
 *  previous field it is returned before the next field is parsed.
 *
 *     Returns either one of the delimiter characters " -:/", NUMBER
 *  for a numeric field with its valus in yylval, MONTH for an ascii
 *  field which matches one of the twelve month names with its month
 *  index (0-11) in yylval, WEEKDAY for an ascii field which matches
 *  one of the seven day-of-week names, or -1 for any other ascii
 *  field.
 */

static int yylex()
{

    register int ret;			/* temp for previous delimiter */
    register char *fp;			/* current field */
    extern char _argbreak;		/* current delimiter */

    if (ret=delim)
    {
	delim = 0;
	if (ret != ' ' && ret != '\t' && ret != ',' && ret != '\n')
	    return(ret);
    }
    fp = nxtarg(&strp, " \t,-:/\n");
    delim = _argbreak;
    if (*fp == 0 && delim == 0) return (0);
    foldup(fp, fp);
    if (strcmp(fp, "AM") == 0)
	return AM;
    if (strcmp(fp, "PM") == 0)
	return PM;
    if (*fp < '0' || *fp > '9')
    {
	if ((yylval=stablk(fp, strings, TRUE)) >= 0)
		return(yylval < 12?MONTH:(yylval < 19?WEEKDAY:TIMEZONE));
	return(-1);
    }
    yylval = atoi(fp);
    return(NUMBER);

}
static short yyexca[] ={
-1, 1,
	0, -1,
	-2, 0,
-1, 12,
	47, 27,
	58, 29,
	-2, 28,
-1, 22,
	58, 29,
	-2, 26,
	};
# define YYNPROD 32
# define YYLAST 226
static short yyact[]={

  34,  34,  23,  24,  28,  36,  33,  12,   3,  13,
  12,  13,  13,  20,  34,  21,  44,  42,  27,  17,
  31,  30,  25,  19,   9,   4,  10,  43,  14,   2,
  41,  16,  18,  15,  11,  29,  26,   7,   8,   6,
  32,   5,  35,   1,  37,  38,   0,   0,   0,   0,
   0,   0,  39,  40,   0,   0,   0,  45,   0,   0,
  46,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,  13,   0,
   0,   0,   0,   0,   0,  22 };
static short yypact[]={

-250,-1000,-1000,-247,-1000,-238, -32,-258, -25,-239,
 -41, -37,-1000,-1000, -38,-1000,-256,-1000,-257,-1000,
-243,-243,-1000,-1000,-1000,-239,-1000,-1000,-248,-1000,
-240,-241,-1000,-243,-1000,-1000,-243,-1000,-1000,-1000,
-1000,-1000,-1000,-1000,-1000,-1000,-1000 };
static short yypgo[]={

   0,  43,  29,  25,  41,  23,  39,  38,  26,  24,
  37,  34,  30,  28,  27 };
static short yyr1[]={

   0,   1,   1,   2,   2,   2,   2,   2,   2,   2,
   2,   2,   4,   4,   4,   6,   6,   6,   6,   3,
   3,   3,  10,  10,  11,   9,   5,   7,   8,  13,
  14,  12 };
static short yyr2[]={

   0,   1,   2,   1,   1,   2,   3,   4,   1,   2,
   3,   4,   2,   3,   3,   3,   2,   3,   2,   1,
   2,   2,   1,   3,   3,   1,   1,   1,   1,   1,
   1,   1 };
static short yychk[]={

-1000,  -1,  -2, 258,  -3,  -4,  -6, -10,  -7,  -9,
  -8, -11, 257, 259, -13,  -2,  -3, 257,  -3,  -5,
  45,  47, 257, 260, 261,  47,  -8, 257,  45,  -9,
  58,  58,  -5, 262, 257,  -5, 262,  -5,  -5,  -8,
  -9, -12, 257, -14, 257,  -5,  -5 };
static short yydef[]={

   0,  -2,   1,   0,   3,   4,   8,  19,   0,   0,
   0,  22,  -2,  25,   0,   2,   5,  29,   9,  12,
   0,   0,  -2,  20,  21,   0,  16,  28,   0,  18,
   0,   0,   6,   0,  26,  10,   0,  13,  14,  15,
  17,  23,  31,  24,  30,   7,  11 };
#
# define YYFLAG -1000
# define YYERROR goto yyerrlab
# define YYACCEPT return(0)
# define YYABORT return(1)

/*	parser for yacc output	*/

#ifdef YYDEBUG
static int yydebug = 0; /* 1 for debugging */
#endif
static YYSTYPE yyv[YYMAXDEPTH]; /* where the values are stored */
static int yychar = -1; /* current input token number */
static int yynerrs = 0;  /* number of errors */
static short yyerrflag = 0;  /* error recovery flag */

static yyparse() {

	short yys[YYMAXDEPTH];
	short yyj, yym;
	register YYSTYPE *yypvt;
	register short yystate, *yyps, yyn;
	register YYSTYPE *yypv;
	register short *yyxi;

	yystate = 0;
	yychar = -1;
	yynerrs = 0;
	yyerrflag = 0;
	yyps= &yys[-1];
	yypv= &yyv[-1];

 yystack:    /* put a state and value onto the stack */

#ifdef YYDEBUG
	if( yydebug  ) printf( "state %d, char 0%o\n", yystate, yychar );
#endif
		if( ++yyps> &yys[YYMAXDEPTH] ) { yyerror( "yacc stack overflow" ); return(1); }
		*yyps = yystate;
		++yypv;
		*yypv = yyval;

 yynewstate:

	yyn = yypact[yystate];

	if( yyn<= YYFLAG ) goto yydefault; /* simple state */

	if( yychar<0 ) if( (yychar=yylex())<0 ) yychar=0;
	if( (yyn += yychar)<0 || yyn >= YYLAST ) goto yydefault;

	if( yychk[ yyn=yyact[ yyn ] ] == yychar ){ /* valid shift */
		yychar = -1;
		yyval = yylval;
		yystate = yyn;
		if( yyerrflag > 0 ) --yyerrflag;
		goto yystack;
		}

 yydefault:
	/* default state action */

	if( (yyn=yydef[yystate]) == -2 ) {
		if( yychar<0 ) if( (yychar=yylex())<0 ) yychar = 0;
		/* look through exception table */

		for( yyxi=yyexca; (*yyxi!= (-1)) || (yyxi[1]!=yystate) ; yyxi += 2 ) ; /* VOID */

		while( *(yyxi+=2) >= 0 ){
			if( *yyxi == yychar ) break;
			}
		if( (yyn = yyxi[1]) < 0 ) return(0);   /* accept */
		}

	if( yyn == 0 ){ /* error */
		/* error ... attempt to resume parsing */

		switch( yyerrflag ){

		case 0:   /* brand new error */

			yyerror( "syntax error" );
		yyerrlab:
			++yynerrs;

		case 1:
		case 2: /* incompletely recovered error ... try again */

			yyerrflag = 3;

			/* find a state where "error" is a legal shift action */

			while ( yyps >= yys ) {
			   yyn = yypact[*yyps] + YYERRCODE;
			   if( yyn>= 0 && yyn < YYLAST && yychk[yyact[yyn]] == YYERRCODE ){
			      yystate = yyact[yyn];  /* simulate a shift of "error" */
			      goto yystack;
			      }
			   yyn = yypact[*yyps];

			   /* the current yyps has no shift onn "error", pop stack */

#ifdef YYDEBUG
			   if( yydebug ) printf( "error recovery pops state %d, uncovers %d\n", *yyps, yyps[-1] );
#endif
			   --yyps;
			   --yypv;
			   }

			/* there is no state on the stack with an error shift ... abort */

	yyabort:
			return(1);


		case 3:  /* no shift yet; clobber input char */

#ifdef YYDEBUG
			if( yydebug ) printf( "error recovery discards char %d\n", yychar );
#endif

			if( yychar == 0 ) goto yyabort; /* don't discard EOF, quit */
			yychar = -1;
			goto yynewstate;   /* try again in the same state */

			}

		}

	/* reduction by production yyn */

#ifdef YYDEBUG
		if( yydebug ) printf("reduce %d\n",yyn);
#endif
		yyps -= yyr2[yyn];
		yypvt = yypv;
		yypv -= yyr2[yyn];
		yyval = yypv[1];
		yym=yyn;
			/* consult goto table to find next state */
		yyn = yyr1[yyn];
		yyj = yypgo[yyn] + *yyps + 1;
		if( yyj>=YYLAST || yychk[ yystate = yyact[yyj] ] != -yyn ) yystate = yyact[yypgo[yyn]];
		switch(yym){
			
case 21:
# line 104 "pdate.y"
{ if (tm->tm_hour <= 12 && tm->tm_hour > 0)
				tm->tm_hour = (tm->tm_hour + 12) % 24; } break;
case 25:
# line 116 "pdate.y"
{ tm->tm_mon = yypvt[-0]; } break;
case 26:
# line 120 "pdate.y"
{ tm->tm_year = yypvt[-0] + ((yypvt[-0]>=1900)?-1900:0); } break;
case 27:
# line 124 "pdate.y"
{ tm->tm_mon = yypvt[-0]; } break;
case 28:
# line 128 "pdate.y"
{ tm->tm_mday = yypvt[-0]; } break;
case 29:
# line 132 "pdate.y"
{ tm->tm_hour = yypvt[-0]; } break;
case 30:
# line 136 "pdate.y"
{ tm->tm_min = yypvt[-0]; } break;
case 31:
# line 140 "pdate.y"
{ tm->tm_sec = yypvt[-0]; } break;
		}
		goto yystack;  /* stack new state and value */

	}
