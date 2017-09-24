#include <xc.h>
#include "config.h"
#include "clear_LCD.h"
#include <stdbool.h>
#include "main.h"
#include "pulse_E.h"
#include <stdio.h>
#include "init_ports.h"
#include "init_eusart.h"
#include "lcdInit.h"
#include "lcdData.h"
#include "splash_screen.h"
#include "get_at_code.h"
#include "get_previous_AT_code.h"
#include "get_refreshed_AT_code.h"
#include "putch.h"

uchar main (void)
{   
    init_ports();
    init_eusart();
    lcdInit();
    splash_screen();
    __delay_ms(2000);
    clear_LCD();
    lcdData(0x80,0);// position cursor at column 0 row 1  
    uchar dummy = 'T';
    while(1)
    {
        get_at_code();
        while(UP && DOWN && ENTER != 0); // wait for button press from UP, DOWN or ENTER
        if(UP!=1) // test to see if UP is pressed
        {
            __delay_ms(20);
            clear_LCD();
            get_at_code();
            __delay_ms(250);
            ptr2++;
             
        }
        else
            if(DOWN!=1) // test to see if DOWN is pressed
            {
                 __delay_ms(20);
                 clear_LCD();
                get_previous_AT_code();
                get_at_code();
                __delay_ms(250);
            }    
        if(ENTER !=1)
        {
            __delay_ms(20);
            get_refreshed_AT_code();
            
            while(*ptr2 != ',' && *ptr2 != '\0')// repeat code block while contents of ptr2 does not equal comma or eof
                {  
                    putch(*ptr2);
                    ptr2++;       
                }
            putch(0x0a);
            putch(0x0d);
            __delay_ms(250);
        }
    }
}