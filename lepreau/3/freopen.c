#include <stdio.h>

extern FILE *_endopen();

FILE *
freopen(file, mode, iop)
	char *file, *mode;
	register FILE *iop;
{
	FILE *_endopen();

	fclose(iop);
	return(_endopen(file, mode, iop));
}
