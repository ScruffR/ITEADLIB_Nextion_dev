/**
* @file NexGauge.cpp
*
* The implementation of class NexGauge. 
*
* @author  Wu Pengfei (email:<pengfei.wu@itead.cc>)
* @date    2015/8/13
* @copyright 
* Copyright (C) 2014-2015 ITEAD Intelligent Systems Co., Ltd. \n
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation; either version 2 of
* the License, or (at your option) any later version.
*
* Port for Particle platform (particle.io)
* by BSpranger & ScruffR (Dec. 2015)
*/

#include "NexGauge.h"

NexGauge::NexGauge(NexDisplay& display, NexPage& page, uint8_t cid, const char *name, void *value)
  :NexTouch(display, page, cid, name, value) { }

NexGauge::NexGauge(uint8_t pid, uint8_t cid, const char *name, void *value)
  :NexTouch(pid, cid, name, value) { }

bool NexGauge::getValue(uint32_t *number) 
{
  return NexObject::getNumeric(NexVALUE, number);
}

bool NexGauge::setValue(uint32_t number)
{
  return NexObject::setNumeric(NexVALUE, number);
}

bool NexGauge::setBackColor(uint32_t color)
{
  return NexObject::setNumeric(NexBACKCOLOR, color);
}

bool NexGauge::getBackColor(uint32_t* color)
{
  return NexObject::getNumeric(NexBACKCOLOR, color);
}


bool NexGauge::setForeColor(uint32_t color)
{
  return NexObject::setNumeric(NexFORECOLOR, color);
}

bool NexGauge::getForeColor(uint32_t* color)
{
  return NexObject::getNumeric(NexFORECOLOR, color);
}


bool NexGauge::setCropImage(uint32_t picID)
{
  return NexObject::setNumeric(NexCROPIMAGE, picID);
}

bool NexGauge::getCropImage(uint32_t* picID)
{
  return NexObject::getNumeric(NexCROPIMAGE, picID);
}


bool NexGauge::setWidth(uint32_t width)
{
  return NexObject::setNumeric(NexWIDTH, width);
}

bool NexGauge::getWidth(uint32_t* width)
{
  return NexObject::getNumeric(NexWIDTH, width);
}


