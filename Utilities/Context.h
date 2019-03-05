/* 
 * File: Context.h   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_CONTEXT_H
#define	XC_CONTEXT_H

#include <xc.h>

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

#define _XTAL_FREQ 16000000

typedef unsigned int U16;
typedef unsigned char U8;
typedef float        F32;

#endif	/* XC_CONTEXT_H */