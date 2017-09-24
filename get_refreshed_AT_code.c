#include <xc.h>
#include "config.h"
void get_refreshed_AT_code()
{
    ptr2--; // skip backwards over either a comma or null character
    ptr2--;
    while(*ptr2 != ',')
    {
        ptr2--;  // move pointer back one character while there is no comma (repeat))
    }
    ptr2++;
}
