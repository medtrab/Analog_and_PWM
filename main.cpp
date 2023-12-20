/*
 * Copyright (c) 2017-2020 Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0t5 KB
 */

#include "mbed.h"

// Initialize a pins to perform analog input and PWM output functions
AnalogIn   ain(A0);//A1 should be changed ny pin name written on your Board 
PwmOut dout(LED1);//led1 built-in led called by name

int main(void)
{
    while (1) {
        // mesure voltage from pin A0 and apply percentage of volyge as pwm pulse width
        dout.period_ms(1);//frequency of sampling eqial 1/priod(s) f=1000hz
        dout=ain;//ain will give value between 0 and 1
        // print the percentage and 16 bit normalized values
        printf("percentage: %3.3f%%\n", ain.read() * 100.0f);
        printf("normalized: 0x%04X \n", ain.read_u16());
        ThisThread::sleep_for(200);//like delay in arduino
    }
}
