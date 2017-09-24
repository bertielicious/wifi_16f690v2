#include<xc.h>
#include "config.h"
#include "pulse_E.h"
#include "clear_LCD.h"
void clear_LCD (void)
{
    /*************************************************************/
    RS = 0;                 // RS   RW  D7  D6  D5  D4 - step 8b - clear display
    PORTAbits.RA4 = 0;      //  0   0   0   0   0   0
    PORTAbits.RA2 = 0;
    PORTAbits.RA1 = 0;
    PORTAbits.RA0 = 0;
    __delay_us(200);
    pulse_E();
    /*************************************************************/
    /*************************************************************/
    RS = 0;                 // RS   RW  D7  D6  D5  D4 - step 9a
    PORTAbits.RA4 = 0;      //  0   0   0   0   0   1
    PORTAbits.RA2 = 0;
    PORTAbits.RA1 = 0;
    PORTAbits.RA0 = 1;
   __delay_ms(5);
    pulse_E();
    /*************************************************************/
}
