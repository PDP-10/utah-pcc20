/* Unix sleep(3) and nap() directly via disms, not alarm */

#include "tops20.h"

sleep(secs)
unsigned secs;
{
    unsigned Acs[5];		/* use local acs in case interrupt elsewhere */
    Acs[1] = secs * 1000;
    jsys(JSdisms, Acs);
}

nap(ticks)
int ticks;
{
    unsigned Acs[5];		/* use local acs in case interrupt elsewhere */
    Acs[1] = ticks * 17;
    jsys(JSdisms, Acs);
}
