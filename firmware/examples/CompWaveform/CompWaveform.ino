/**
 * @example CompWaveform.ino
 *
 * @par How to Use
 * Show how to use API of class NexWaveform.  
 *
 * @author  Wu Pengfei (email:<pengfei.wu@itead.cc>)
 * @date    2015/8/11
 * @copyright 
 * Copyright (C) 2014-2015 ITEAD Intelligent Systems Co., Ltd. \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */ 

#define PARTICLE_BUILD
#if defined(PARTICLE_BUILD)
#include "ITEADLIB_Nextion/ITEADLIB_Nextion.h"
#else
#include "ITEADLIB_Nextion.h"
#endif

NexDisplay   display;                // the display is the root element
//NexDisplay display(Serial1, 9600); // alternativly

#define LEVEL_HIGH      (30)
#define LEVEL_LOW       (0)

#define CH0_OFFSET  (40 - LEVEL_HIGH/2)
#define CH1_OFFSET  (CH0_OFFSET + 40 * 1)
#define CH2_OFFSET  (CH0_OFFSET + 40 * 2)
#define CH3_OFFSET  (CH0_OFFSET + 40 * 3)


NexWaveform & s0 = (NexWaveform &)display.add(0, 1, "s0");

static uint8_t ch0_data = LEVEL_LOW;
static uint8_t ch1_data = LEVEL_LOW;
static uint8_t ch2_data = LEVEL_LOW;
static uint8_t ch3_data = LEVEL_LOW;

void setup(void)
{
    display.init();
    dbSerialPrintln("setup done");
}

void loop(void)
{
    static uint32_t started = 0;
    if (millis() - started >= 2000)
    {
        started = millis();    
        if (LEVEL_HIGH == ch0_data)
        {
            ch0_data = LEVEL_LOW;
        }
        else
        {
            ch0_data = LEVEL_HIGH;
        }
    }
    
    ch1_data = ch0_data + random(0, 2);
    ch2_data = ch0_data + random(0, 5);
    ch3_data = ch0_data + random(0, 8);
    
    s0.addValue(0, CH0_OFFSET + ch0_data);
    s0.addValue(1, CH1_OFFSET + ch1_data);
    s0.addValue(2, CH2_OFFSET + ch2_data);
    s0.addValue(3, CH3_OFFSET + ch3_data);
}

