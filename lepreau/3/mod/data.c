#include <stdio.h>

char	_sibuf[BUFSIZ];
char	_sobuf[BUFSIZ];

struct	_iobuf	_iob[_NFILE] = {
	{_sibuf, 0, _sibuf, _IOREAD+_IOTTY,	0100},	/* PRiin */
	{NULL,   0, NULL,   _IOWRT+_IOTTY,	0101},	/* PRiou */
	{NULL,   0, NULL,   _IOWRT+_IONBF+_IOTTY, 0101},	/* PRiou */
};
/*
 * Ptr to end of buffers - actually is one past end (!)
 */
struct	_iobuf	*_lastbuf = &_iob[_NFILE];
