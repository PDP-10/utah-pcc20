#define abs(x)	((x) < 0 ? -(x) : (x))

double
modf(val, iptr)
double val, *iptr;
{
	register int	i;
	register double d;
	i = val;
	*iptr = i;
	d = val - *iptr;
	return(abs(d));
}
