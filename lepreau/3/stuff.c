/* @(#)stuff.c	4.1 (Berkeley) 12/21/80 */
int	yyportlib	=1;

wdleng()
{
#ifdef tops20
	return(36);
#else
	return(32);
#endif

}
