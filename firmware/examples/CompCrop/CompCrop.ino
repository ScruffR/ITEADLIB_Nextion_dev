/**
 * @example CompCrop.ino
 *
 * @par How to Use
 * This example shows that when the crop component on the Nextion screen is released,
 * the image of this component will be changed.       
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
 * Declare a crop object [page id:0,component id:1, component name: "q0"]. 
 */
NexCrop & q0 = (NexCrop & )display.add(0, 1, "q0");

/*
 * Crop component pop callback function. 
 * In this example,the image of current crop component will be changed every time when it is released. 
 */
void q0PopCallback(void *ptr)
{
    uint32_t number = 0;
    dbSerialPrintln("q0PopCallback");

    q0.getPic(&number);

    number += 1;
    number %= 2;
    
    q0.setPic(number);
}

void setup(void)
{
    display.init();
    q0.attachPop(q0PopCallback);
    dbSerialPrintln("setup done");
}

void loop(void)
{
   display.nexLoop();
}

