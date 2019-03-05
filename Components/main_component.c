/*
 * File:   main.c
 * Author: androdrigue2
 *
 * Created on July 13, 2018, 11:25 AM
 */
#include "main_component.h"
#include "application.h"

/*Bank selectors*/
#define BANK_0 0x00
#define BANK_1 0x01
#define BANK_2 0x02
#define BANK_3 0x03

/*Configuration for the AD port A*/
#define ADCON1_CONFIG_0 0x00 /*All Analog*/
#define ADCON1_CONFIG_1 0x01 /*refere to page 84 of pic16f73 manual*/
#define ADCON1_CONFIG_2 0x02 /*refere to page 84 of pic16f73 manual*/
#define ADCON1_CONFIG_3 0x03 /*refere to page 84 of pic16f73 manual*/
#define ADCON1_CONFIG_4 0x04 /*refere to page 84 of pic16f73 manual*/
#define ADCON1_CONFIG_5 0x05 /*refere to page 84 of pic16f73 manual*/
#define ADCON1_CONFIG_6 0x06 /*All Digital*/

void Setup(void){
    
    /*Select bank 0 to setup the PORTs*/
    STATUS = BANK_0;
    PORTA = 0x00;
    PORTB = 0x00;
    PORTC = 0x00;
    /*Select bank 1 to setup the TRIS and the ADCON1*/
    STATUS = BANK_1;
    /*Port A as all digital*/
    ADCON1 = ADCON1_CONFIG_6;
    /*Port assignment*/
    TRISB=0x03;
    TRISA=0x00;
    TRISC=0x00;
    /*Return to bank 0*/
    STATUS = BANK_0;
    
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