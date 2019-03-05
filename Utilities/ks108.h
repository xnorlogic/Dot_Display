/* 
 * File:   ks108.h
 * Author: androdrigue2
 *
 * Created on February 26, 2019, 1:07 PM
 */

#ifndef KS108_H
#define	KS108_H

#include "My_Delays.h"

/******************************************************************************/
/*LCD DOT Display*/
#define 	LCD_WIDTH			128
#define 	LCD_HEIGHT			64

#define 	CH_WIDTH     		8      //8x8 Font
#define 	COLS	      		LCD_WIDTH/CH_WIDTH
#define 	ROWS	      		LCD_HEIGHT/8

#define 	E					PORTCbits.RC7
#define 	E_TRIS				TRISCbits.TRISC7

#define 	RW					PORTCbits.RC1
#define 	RW_TRIS				TRISCbits.TRISC1

#define 	RS					PORTCbits.RC0
#define 	RS_TRIS				TRISCbits.TRISC0

#define 	CSA					PORTCbits.RC2
#define 	CSA_TRIS			TRISCbits.TRISC2

#define 	CSB					PORTCbits.RC6
#define 	CSB_TRIS			TRISCbits.TRISC6

#define 	DATA_DIR_IN()		TRISB=0xFF
#define 	DATA_DIR_OUT()	  	TRISB=0
#define 	WR_DATA(a)			PORTB=(a)		
#define 	RD_DATA()			PORTB

#define 	DATA				0
#define 	COMMAND				1

#define		OUT					0
#define		IN					1
/******************************************************************************/

extern char Font8x8[];

void InitDisplay(void);
void ChipSelect(U8 chip);
void PageSelect(U8 page);
void RowSelect(U8 row);
void StartLine(U8 line);
void WriteByte(U8 byt);
void WriteChar(U8 ch, U8 rev);
void ClearDisplay(void);

#endif	/* KS108_H */


