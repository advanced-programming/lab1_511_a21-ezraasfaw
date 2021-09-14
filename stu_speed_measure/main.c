/**
   	FileName:     main.c
	 
	Name:   
 
	Description: 
      
 * * REVISION HISTORY:
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Author                 Date      	Comments on this revision
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~            
 * Ezra-Fikru Asfaw      24 Aug. 2021		                              
 * Ezra-Fikru Asfaw      31 Aug. 2021 
 * Ezra-Fikru Asfaw       3 Sep. 2021      Made the display show the frequency using the internal generator and display the frequency to 0 when it is disconnected.
 * Ezra-Fikru Asfaw       7 Sep. 2021   1- Made the LED to blink, but stop after 3 second when the function generator is disconnected.
 *                                      2- Made the display show the CPR value of the motor
*******************************************************************************/

#include <stdio.h>
#include "initBoard.h"
#include "console32.h"
#include "Tick_core.h"

#define Ticks_per_second 1

//#define SIMULATION 
//
//#ifdef SIMULATION 
//    #define CONSOLE     C_UART2 
//
//#else 
//    #define CONSOLE     C_LCD  
//
//#endif 
//initUart1();	// initializes simulation UART1 display tab 
//initLCD();		// initializes target LCD display  
//
//fprintf2(CONSOLE,"debugging message 1\n"); 






int frequency;
int buf[100];
extern int timePeriod;
extern int of;
int stamp;
int RPM;
int RPM_GEARBOX;



int main( void){
    // Initialisation starts here
        initT2();
        initCN9();
        initIO();
    //Super loop starts here
        //initUart1();
        initLCD();
        initT3_3kHz();
        //initT3_100Hz();
        //fprintf2(C_UART1,"Hello\n");
    
   LATGbits.LATG8 =1;  //enables the motor at full speed  
    
    while(1){
       
        if (TickDiff(stamp) > Ticks_per_second/2 ){  //WRONG MACRO. See tick_core.h
            frequency = (20000000 / (64/4))/timePeriod; //USE MACROS FOR GEARBOX RATIO, TIMER2 FREQ AND PPR
            RPM = (frequency * 60);
            stamp = TickGet();
            RPM_GEARBOX = RPM/19;
        
    if (of >= 1000){

                LATAbits.LATA0 = 0;       //Led3
                delay_us(500000);
                frequency = 0;    
                sprintf(buf, "RPM: %d    \nGearbox RPM: %d    ", 0, 0);
                fprintf2(C_LCD, buf);
            }
    else{
    
        delay_us(500000); //REMOVE ALL BLOCKING DELAY
        LATAbits.LATA0 ^= 1;       //Led3
        frequency = 20000000/timePeriod; // 1/(timePeriod* 10 uS)}
        
        sprintf(buf, "RPM: %d    \nGearbox RPM: %d    ", RPM, RPM_GEARBOX);
        //fprintf2(C_UART1, buf);
        
        fprintf2(C_LCD, buf);
            }
        }
     //Motor characteristics: 
     //12V brushed DC motor  
     //19:1 metal gearbox ratio  
     //Integrated quadrature encoder: 64 PPR    
            
    }
    

}// main
