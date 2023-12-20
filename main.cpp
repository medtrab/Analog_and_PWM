/*
 * Copyright (c) 2017-2020 Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0t5 KB
 */

#include "mbed.h"
// this code is built on stm32 nuleo F446RE
// Initialize a pins to perform analog input and PWM output functions
AnalogIn   ain(A0);//A1 could be changed to any pin name 
PwmOut dout(LED1);//led1 built-in led called by name

int main(void)
{
    while (1) {
        // mesure voltage from pin A0 and apply percentage of volyge as pwm pulse width
        dout.period_ms(1);//frequency of sampling eqial 1/priod(s) f=1000hz
        dout=ain;//ain will give value between 0.0 and 1.0, and dout can take value 0.0 to 1.0 (repesnting value * 100 in percentage of duty cycle)
        // print the percentage and 16 bit normalized values of adc
        printf("percentage: %3.3f%%\n", ain.read() * 100.0f);
        printf("normalized: 0x%04X \n", ain.read_u16());
        ThisThread::sleep_for(200);//like delay in arduino, sleep for 200 ms
    }
}
