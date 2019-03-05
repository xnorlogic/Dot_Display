/*
 * File:   shell.c
 * Author: androdrigue2
 *
 * Created on July 13, 2018, 10:34 AM
 */

#include "main_component.h"

void main(void) { 
    /*Setup function call*/
    Setup();
    /*Call to the dot display test routine*/
    TestDotDisp();
    /*Main loop*/
    while(1){
        Loop();
    }
}