/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

#ifndef XC_APPLICATION_H
#define	XC_APPLICATION_H

#include "My_Delays.h"

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

void Counter_Selector(void);
void Saturated_Counter(void);
void NO_Saturated_Counter(void);

#endif	/* XC_APPLICATION_H */

