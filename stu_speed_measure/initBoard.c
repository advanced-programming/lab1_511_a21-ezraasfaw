/***********************************************************************************************
*
*
* FileName:  initBoard.c      
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date            Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Serge Hould      14 Jan. 2021		v1.0.0      Setup for PIC32    
* Serge Hould      27 Apr. 2021     v1.1        Set PBCLK to 80MHz to facilitate simulation.  Both sysclk and pbclk are the same.
*                                               
* 
*
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include "initBoard.h"
#include <stdint.h>
#include <xc.h>
#include <sys/attribs.h>


 // Configuration Bit settings
// SYSCLK = 80 MHz 
//(8MHz Crystal/ FPLLIDIV * FPLLMUL / FPLLODIV)
// PBCLK = 40 MHz
// Primary Osc w/PLL (HS+PLL)
// WDT OFF, Peripheral Bus is CPU clock÷8
// Other options are default as per datasheet
// see file:C:\Program Files (x86)\Microchip\xc32\v1.40\docs\config_docs\32mx795f512l.html
 

#pragma config FPLLMUL = MUL_20
#pragma config FPLLIDIV = DIV_2
#pragma config FPLLODIV = DIV_1 
#pragma config POSCMOD = HS, FNOSC = PRIPLL
#pragma config FPBDIV = DIV_1  // PBCLK = SYSCLK/DIV_1
#pragma config FWDTEN =  OFF    // disable

/* Sets up the IOs */
void initIO(void)
{
    /* LEDs */
    TRISAbits.TRISA7 = 0;       //LED10
    TRISAbits.TRISA5 = 0;       //Led8
    TRISAbits.TRISA4 = 0;       //Led7
    TRISAbits.TRISA3 = 0;       //Led6
    TRISAbits.TRISA2 = 0;       //Led5
    TRISAbits.TRISA1 = 0;       //Led4
    TRISAbits.TRISA0 = 0;       //Led3
    
    TRISGbits.TRISG8 = 0;       //Motor enable pin
    TRISGbits.TRISG13 = 0;       //external generator pin
    
    TRISDbits.TRISD6 =1; //S3
    TRISDbits.TRISD7 =1;//S6
    TRISDbits.TRISD13 =1;//S4
    TRISAbits.TRISA6 =1; //S5
       
}


