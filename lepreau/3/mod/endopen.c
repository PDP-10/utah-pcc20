#include	<stdio.h>
#include	<errno.h>
#include	<file.h>

FILE *
_endopen(file, mode, iop)
	char *file, *mode;
	register FILE *iop;
{
	extern int errno;
	int binary;
	register int rw, f;

	if (iop == NULL)
		return(NULL);

	rw = index(mode, '+');
	binary = index(mode, 'b') ? FATT_BINARY : 0;

	switch (*mode) {

	case 'w':
		f = open(file, (rw ? FATT_RDWR : FATT_WRONLY) | binary);
		break;

	case 'a':
#ifdef notdef				/* old stuff */
		if ((f = open(file, rw? 2: 1)) < 0) {
			if (errno == ENOENT)
				f = create(file, rw);
		}
		if (f < 0)	/* added so perror is meaningful --fjl 7/81 */
			return(NULL);
		lseek(f, 0L, 2);
#endif
		if (rw) {
			perror("'a+' mode not supported");	/* for now */
			return(NULL);
		}

		f = open(file, FATT_APPEND | binary);
		break;

	case 'r':
		f = open(file, (rw ? FATT_RDWR : FATT_RDONLY) | binary);
		break;

	default:
		return(NULL);
	}

	if (f < 0)
		return(NULL);

	iop->_cnt = 0;
	iop->_file = f;

	if (rw)
		iop->_flag |= _IORW;
	else if(*mode == 'r')
		iop->_flag |= _IOREAD;
	else
		iop->_flag |= _IOWRT;
	if (binary)
		iop->_flag |= _IOBINARY;
	return(iop);
}
