#include <xc.h>
#include "config.h"

void get_previous_AT_code()
{
    ptr2--; // skip backwards over either a comma or null character
    ptr2--;
    while(*ptr2 != ',')
    {
        ptr2--;  // move pointer back one character while there is no comma (repeat))
    }
    ptr2--;     // skip backwards over comma
    while(*ptr2 != ',')
    {
        ptr2--; // move pointer backwards to the second comma
    }
    ptr2++; // move pointer one position forward  to point at first character
}           // of previous AT code - we are now in the correct position to read the previous AT code!
