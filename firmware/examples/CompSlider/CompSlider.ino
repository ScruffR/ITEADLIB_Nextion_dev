/**
 * @example CompSlider.ino
 *
 * @par How to Use
 * This example shows that ,when the slider component on the Nextion screen is released,
 * the text value of text component will be changed every time. 
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

NexText   & t0 = (NexText   & )display.add(0, 2, "t0");
NexSlider & h0 = (NexSlider & )display.add(0, 1, "h0");

void h0PopCallback(void *ptr)
{
    uint32_t number = 0;
    char temp[10] = {0};
    
    dbSerialPrintln("h0PopCallback");

    h0.getValue(&number);
    utoa(number, temp, 10);
    t0.setText(temp);
}

void setup(void)
{
    display.init();
    h0.attachPop(h0PopCallback);
    dbSerialPrintln("setup done");
}

void loop(void)
{
   display.nexLoop();
}

