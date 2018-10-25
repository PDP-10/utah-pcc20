/* @(#)rand.c	4.1 (Berkeley) 12/21/80 */
static	long	randx = 1;

#include "tops20.h"

srand(x)
unsigned x;
{
	randx = x;
}

rand()
{
  return((randx = randx * 1103515245 + 12345) & makeword(0377777,0777777));
}
