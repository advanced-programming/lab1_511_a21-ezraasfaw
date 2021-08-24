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
void __ISR( _TIMER_2_VECTOR, IPL1SOFT) T2InterruptHandler( void){ 
     IFS0bits.T2IF = 0; 
    
} 

void __ISR( _CHANGE_NOTICE_VECTOR, IPL2SOFT) CNInterrupt( void){
     IFS1bits.CNIF = 0;//Clear the CN flag?

// Do something?

}