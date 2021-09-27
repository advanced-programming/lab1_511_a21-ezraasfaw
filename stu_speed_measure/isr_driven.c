/***********************************************************************************************
*
*
* FileName:  isr_driven.c      
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date            Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Ezra-Fikru Asfaw  24 Aug. 2021  v1.0.0      Setup ISR timer 2    
* 
*                                               
* 
*
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <xc.h>
#include <sys/attribs.h>

/*Global variables*/
signed int of = 0;
extern int timePeriod= 1;
PROLOG HEADEWR NEEDED
void __ISR( _TIMER_2_VECTOR, IPL1SOFT) T2InterruptHandler( void){ 
     IFS0bits.T2IF = 0; 
     of++; // Timer overflows
     
} 

//void __ISR( _CHANGE_NOTICE_VECTOR, IPL2SOFT) CNInterrupt( void){
//     IFS1bits.CNIF = 0;//Clear the CN flag?

// Do something?
EXPLAIN HERE
/*Interrupt Service Routine for Change Notification */
     void __ISR( _CHANGE_NOTICE_VECTOR, IPL2SOFT) CNInterrupt(void){
         static signed  start,final;
         if(PORTGbits.RG7){// Rising edge detection
            final=TMR2;
            timePeriod= (of*0x10000)+final-start;
            start=final; 
            of=0; 
         }
         IFS1bits.CNIF=0; //clear the change notification interrupt bit
}
