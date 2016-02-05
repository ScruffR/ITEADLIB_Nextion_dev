
/**
 * @example GraphPrimitives.ino
 *
 * @par How to Use
 * Show how to use API for drawing primitives
 *
 * @author  Andreas Rothenwänder (aka ScruffR <http://community.particle.io>)
 * @date    2015/12/06
 * @copyright 
 * Copyright (C) 2014-2015 ScruffR \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */ 

#define noPARTICLE_BUILD
#if defined(PARTICLE_BUILD)
#include "ITEADLIB_Nextion/ITEADLIB_Nextion.h"
#else
#include "ITEADLIB_Nextion.h"
#endif

NexDisplay   display;                // the display is the root element
//NexDisplay display(Serial1, 9600); // alternativly

void setup(void)
{
    display.init();
    dbSerialPrintln("setup done");
    display.setBaudrate(115200);

    display.clearScreen(0x0000);
    display.drawPic(0, 0, 0);
}

int x;
int y;
void loop(void)
{
    display.cropPic(320-x, y + 25, 50, 50, 1);
    x += 4;
    x %= 320;
    y += 3;
    y %= 215;
    display.drawText(0, 0, 320, 25, NexCENTER, NexCENTER, 0, 0xFFFF, 0xAAAA, NexSOLID, "Particle rocks!");
    display.drawLine(5, 5, 50, 30, 0xF800);
    display.fillRect(250, 25, 50, 25, 0x7E00);
    display.drawRect(20, 105, 50, 25, 0x01FF);
    display.drawCircle(160, 120, 30, 0xF9FF);

    delay(25);
}
