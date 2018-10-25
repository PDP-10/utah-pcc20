#include "tops20.h"

_prterr(str)
char *str;
{
	ac1 = POINT(str);
	jsys(JSpsout, acs);
	ac1 = '\n';
	jsys(JSpbout, acs);
}
