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

int frequency;
int buf[100];
extern int timePeriod;
extern int of;

int main( void){
    // Initialisation starts here
	initT2();
    initCN9();
    initIO();
    //Super loop starts here
    //initUart1();
    initLCD();
    //initT3_3kHz();
    initT3_100Hz();
    //fprintf2(C_UART1,"Hello\n");
    
    while(1){
       
        delay_us(1000);
        frequency = 20000000/timePeriod; // 1/(timePeriod* 10 uS)}
        sprintf(buf, "frequency: %d   \n", frequency);
        //fprintf2(C_UART1, buf);
        fprintf2(C_LCD, buf);
        
            if (of = 1000){
            timePeriod = 0;
            }
    }
    

}// main
