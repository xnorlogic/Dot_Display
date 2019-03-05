/*
 * File:   application.c
 * Author: androdrigue2
 *
 * Created on July 13, 2018, 2:51 PM
 */

#include "application.h"

F32 Saturation = 12.5f;
F32 Increment = 0.5f;

void Counter_Selector(void){
    switch(selector){
        case 0U:
            Saturated_Counter();
        break;

        case 1U:
            NO_Saturated_Counter();
        break;
        
        default:
            Saturated_Counter();
        break;
    }      
}

void Saturated_Counter(void){
    /*Saturated counter*/
    if(MyFloatTest_Sat >= Saturation){
        MyFloatTest_Sat = Saturation;
    }
    else{
        MyFloatTest_Sat = MyFloatTest_Sat + Increment;  
    }
}

void NO_Saturated_Counter(void){
    /*Non Saturated counter*/
    MyFloatTest_NoSat = MyFloatTest_NoSat + Increment;     
}