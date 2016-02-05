/**
 * @example CompButton.ino
 * 
 * @par How to Use
 * This example shows that when the button component on the Nextion screen is released,
 * the text of this button will plus one every time.      
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
 * Declare a button object [page id:0,component id:1, component name: "b0"]. 
 */

NexButton & b0 = (NexButton &)display.add(0, 1, "b0");

char buffer[100] = {0};

/*
 * Button component pop callback function. 
 * In this example,the button's text value will plus one every time when it is released. 
 */
void b0PopCallback(void *ptr)
{
    uint16_t len;
    uint16_t number;
    NexButton *btn = (NexButton *)ptr;
    dbSerialPrintln("b0PopCallback");
    dbSerialPrint("ptr=");
    dbSerialPrintln((uint32_t)ptr); 
    memset(buffer, 0, sizeof(buffer));

    /* Get the text value of button component [the value is string type]. */
    btn->getText(buffer, sizeof(buffer));
    
    number = atoi(buffer);
    number += 1;

    memset(buffer, 0, sizeof(buffer));
    itoa(number, buffer, 10);

    /* Set the text value of button component [the value is string type]. */
    btn->setText(buffer);
}

void setup(void)
{    
    /* Set the baudrate which is for debug and communicate with Nextion screen. */
    display.init();

    /* Register the pop event callback function of the current button component. */
    b0.attachPop(b0PopCallback, &b0);
    
    dbSerialPrintln("setup done"); 
}

void loop(void)
{   
    /*
     * When a pop or push event occured every time,
     * the corresponding component[right page id and component id] in touch event list will be asked.
     */
   display.nexLoop();
}

