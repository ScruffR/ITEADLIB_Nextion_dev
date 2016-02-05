/**
 * @example CompPicture.ino
 *
 * @par How to Use
 * This example shows that ,when the picture component on the Nextion screen is released,
 * the picture of current component will be changed every time.  
 *
 * @author  Wu Pengfei (email:<pengfei.wu@itead.cc>)
 * @date    2015/7/10
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

/*
 * Declare a picture object [page id:0,component id:1, component name: "p0"]. 
 */
NexPicture & p0 = (NexPicture &)display.add(0, 1, "p0");

void p0PopCallback(void *ptr)
{
    uint32_t number = 0;
    dbSerialPrintln("p0PopCallback");

    p0.getPic(&number);

    if (number == 1)
    {
        number = 2;    
    }
    else
    {
        number = 1;
    }
    
    p0.setPic(number);
}

void setup(void)
{
    display.init();
    p0.attachPop(p0PopCallback);
    dbSerialPrintln("setup done");
}

void loop(void)
{
   display.nexLoop();
}

