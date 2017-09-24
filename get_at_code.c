#include <xc.h>
#include<stdbool.h>
#include "config.h"
#include "init_ports.h"
#include "init_eusart.h"
#include "lcdData.h"
#include "putch.h"
#include "get_previous_AT_code.h"
void get_at_code(void)
{
   
    while(*ptr2 != ',' && *ptr2 != '\0')// repeat code block while contents of ptr2 does not equal comma or eof
    {  
        lcdData(*ptr2, 1);
        ptr2++;                            
    }
}
