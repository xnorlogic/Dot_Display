/*
 * File:   My_Delays.c
 * Author: androdrigue2
 *
 * Created on July 13, 2018, 11:05 AM
 */

#include "My_Delays.h"

/*DELAY FUNCTIONS @16Mhz------------------------------------------------------*/
void mydelay_ms(U16 cycles) {
    U16 i;

    for (i = 1; i <= cycles; i++) {
        __delay_ms(1);
    }
}
void mydelay_sec(U16 cycles) {
    U16 i;

    for (i = 1; i <= cycles; i++) {
        mydelay_ms(1000);
    }
}
