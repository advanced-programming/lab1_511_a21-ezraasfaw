/**
   	FileName:     main.c
	 
	Name:   
 
	Description: 
      
 * * REVISION HISTORY:
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Author                 Date      	Comments on this revision
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~            
 * Ezra-Fikru Asfaw      24 Aug. 2021		                              
 *
 *      
 *
 *			 
*******************************************************************************/

#include <stdio.h>
#include "initBoard.h"
#include "console32.h"
#include "Tick_core.h"

//int frequency;
//int buf[999];
//extern int timePeriod;

int main( void){
    // Initialisation starts here
	initT2();
    initCN9 ();
    //Super loop starts here
    initUart1();
    //fprintf2(C_UART1,"Hello\n");
    
    while(1){
//        delay_us(1000);
//        frequency = 100000/timePeriod; // 1/(timePeriod* 10 uS)}
//        sprintf(buf, "frequency: %d\n", frequency);
//        fprintf2(C_UART1, buf);
    }
    

}// main
