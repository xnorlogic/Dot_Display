/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

#ifndef XC_APPLICATION_H
#define	XC_APPLICATION_H

#include "My_Delays.h"
#include "ks108.h"

/*Port configuration*/
/*PORT A -> All OUTPUTS*/
#define PORTA_CONFIG 0x00
/*PORT B -> RB0 and RB1 INPUTS, RB2 RB3 RB4 RB5 RB6 RB7 OUTPUTS*/
#define PORTB_CONFIG 0x03
/*PORT C -> All OUTPUTS*/
#define PORTC_CONFIG 0x00

/*F32 variables*/
F32 MyFloatTest_Sat;
F32 MyFloatTest_NoSat;

/*U8 variable declaration*/
U8 selector;

/****************************************************************************/
/*This is a calibration value*/
/*TBD is to define the CAL ROM space in the external EEPROM*/
/*TBD implement EEPROM hardware*/
extern F32 Saturation;
extern F32 Increment;
/****************************************************************************/

/*Counter application prototypes*/
void Counter_Selector(void);
void Saturated_Counter(void);
void NO_Saturated_Counter(void);

/*Dot display prototypes*/
void TestDotDisp(void);

#endif	/* XC_APPLICATION_H */

