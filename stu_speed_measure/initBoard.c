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
* Ezra-Fikru Asfaw 24 Aug. 2021		v1.0.0      Implement initT2 and initCN9                                             
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
    DDPCONbits.JTAGEN = 0;
    
    LATAbits.LATA7 = 0;       //LED10
    LATAbits.LATA5 = 0;       //Led8
    LATAbits.LATA4 = 0;       //Led7
    LATAbits.LATA3 = 0;       //Led6
    LATAbits.LATA2 = 0;       //Led5
    LATAbits.LATA1 = 0;       //Led4
    LATAbits.LATA0 = 0;       //Led3
    
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


void initT2( void) 
{ 
    // Initialize and enable Timer2 
    T2CONbits.TON = 0; // Disable Timer 
    T2CONbits.TCS = 0; // Select internal inst. cycle clock 
    T2CONbits.TGATE = 0; // Disable Gated Timer mode 
    T2CONbits.TCKPS = 0b010;  
    TMR2 = 0x00; // Clear timer register 
    PR2=0xFFFF; // Load the period value.  
    INTCONbits.MVEC = 1;
    __builtin_disable_interrupts();   // disable interrupt 
    IPC2bits.T2IP = 0x01; // Set Timer 2 Inter Priority  
    IFS0bits.T2IF = 0; // Clear Timer 2 Interrupt Flag 
    IEC0bits.T2IE = 1; // Enable Timer 2 interrupt 
    T2CONbits.TON = 1; // Start Timer  
    __builtin_enable_interrupts();// enable Inter.
} // init 

void initCN9 (void)
{ 
    TRISGbits.TRISG7 =1; // input CN9/RG7 pin 11 
    CNENbits.CNEN9 = 1; //  CN9 
    __builtin_disable_interrupts();   // disable interrupt 
    CNCONbits.ON = 1; // turn on CN 
    IPC6bits.CNIP=2;     
    IFS1bits.CNIF=0;        
    INTCONbits.MVEC=1; 
    IEC1bits.CNIE=1; 
    __builtin_enable_interrupts();// enable Inter. 
} 

