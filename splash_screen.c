#include <xc.h>
#include "pulse_E.h"
#include "config.h"
#include <stdbool.h>
#include "lcdData.h"

void splash_screen(void)
{
    uchar element;
    const uchar splash_line_one[16] = {0x53, 0x65, 0x6e, 0x64, 0x20, 0x41, 0x54, 0x20, 0x63, 0x6f, 0x64, 0x65, 0x73, 0x20, 0x74, 0x6f};// Enter AT codes to
    const uchar splash_line_two[16] = {0x20, 0x45, 0x53, 0x50, 0x38, 0x32, 0x36, 0x36, 0x20, 0x6d, 0x6f, 0x64, 0x75, 0x6c, 0x65, 0x20};// Enter AT codes tp
    lcdData(0x80, 0);   //position cursor at position 0 of first line
    for (element = 0; element < 16; element++)
    {
        lcdData(splash_line_one[element], 1);   
    } 
    lcdData(0xc0, 0);   //position cursor at position 0 of first line
    for (element = 0; element < 16; element++)
    {
        lcdData(splash_line_two[element], 1);   
    }  
    
   
}
