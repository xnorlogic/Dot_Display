/*
 * File:   main.c
 * Author: androdrigue2
 *
 * Created on July 13, 2018, 11:25 AM
 */
#include "main_component.h"
#include "application.h"

void Setup(void){
    
    //MAIN TARGET DEVICE CONFIGS-------------
    STATUSbits.RP0=0;
    STATUSbits.RP1=0;
    PORTA =0;
    PORTB =0;
    PORTC =0;
    STATUSbits.RP0=1;
    //CONFIG PORT A AS DIGITAL OUTPUTS
    ADCON1bits.PCFG0=0;
    ADCON1bits.PCFG1=1;
    ADCON1bits.PCFG2=1;
    //PORT B assignments
    TRISB=0x03;
    PORTB=0;
    //PORT A assignments
    TRISA=0;
    PORTA=0;
    //PORT C assignments
    TRISC=0;                   
    PORTC=0;                    
    STATUSbits.RP0=0;
	//--------------------------------------
    
    MyFloatTest_Sat = 0.0f;
    MyFloatTest_NoSat = 0.0f;
    selector = 0U;
}

void Loop(void){    
    /*set the selector from the RB0 RB1 inputs*/
    selector = (RB1 * 2U) + (RB0 * 1U);
    /*call the counter selector*/
    Counter_Selector();   
}

void TestDotDisp(void){
    InitDisplay();
    WriteChar('1', 0);
}