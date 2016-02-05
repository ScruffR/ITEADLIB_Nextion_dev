/**
 * @example CompPage.ino
 *
 * @par How to Use
 * Show how to use API of class NexPage.  
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

NexPage & page0    = (NexPage & )display.add(0, 0, "page0");
NexPage & page1    = (NexPage & )display.add(1, 0, "page1");
NexPage & page2    = (NexPage & )display.add(2, 0, "page2");
NexPage & page3    = (NexPage & )display.add(3, 0, "page3");

void page0PopCallback(void *ptr)
{
    dbSerialPrintln("page0PopCallback");
    page1.show();
}

void page1PopCallback(void *ptr)
{
    dbSerialPrintln("page1PopCallback");
    page2.show();
}

void page2PopCallback(void *ptr)
{
    dbSerialPrintln("page2PopCallback");
    page3.show();
}

void page3PopCallback(void *ptr)
{
    dbSerialPrintln("page3PopCallback");
    page0.show();
}

void setup(void)
{   
    display.init();
    dbSerialPrintln("setup begin");
    
    page0.attachPop(page0PopCallback);
    page1.attachPop(page1PopCallback);
    page2.attachPop(page2PopCallback);
    page3.attachPop(page3PopCallback);
    
    dbSerialPrintln("setup end");
}

void loop(void)
{
   display.nexLoop();
}
