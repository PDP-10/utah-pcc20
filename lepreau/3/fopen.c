/* @(#)fopen.c	4.2 (Berkeley) 3/9/81 */
#include	<stdio.h>

extern FILE *_endopen();

FILE *
fopen(file, mode)
char *file;
char *mode;
{
	extern int errno;
	register f, rw;
	register FILE *iop;
	extern FILE *_lastbuf;

	for (iop = _iob; iop->_flag&(_IOREAD|_IOWRT|_IORW); )
		if (++iop >= _lastbuf)
			return(NULL);

	return(_endopen(file, mode, iop));
}
