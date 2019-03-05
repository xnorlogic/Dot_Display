/*
 * File:   main.c
 * Author: androdrigue2
 *
 * Created on July 13, 2018, 11:25 AM
 */
#include "main_component.h"
#include "application.h"

/*Port configuration*/
/*PORT A -> All OUTPUTS*/
#define PORTA_CONFIG 0x00
/*PORT B -> RB0 and RB1 INPUTS, RB2 RB3 RB4 RB5 RB6 RB7 OUTPUTS*/
#define PORTB_CONFIG 0x03
/*PORT C -> All OUTPUTS*/
#define PORTC_CONFIG 0x00

void PORT_setup(U8 P_A, U8 P_B, U8 P_C);
void PORT_A_setup(U8 configSelect);

void Setup(void){
    /*Port A Analog/Digital configuration*/
    PORT_A_setup(ADCON1_CONFIG_6);
    /*Port assignment configuration*/
    PORT_setup(PORTA_CONFIG,PORTB_CONFIG,PORTC_CONFIG);
    
    /*Application configuration specific*/
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

void PORT_setup(U8 P_A, U8 P_B, U8 P_C){
    STATUS = BANK_1;
    TRISA=P_A;
    TRISB=P_B;
    TRISC=P_C;
    STATUS = BANK_0;
}

void PORT_A_setup(U8 configSelect){
    STATUS = BANK_1;
    ADCON1 = configSelect;
    STATUS = BANK_0;  
}