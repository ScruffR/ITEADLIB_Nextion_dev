/**
* @file NexProgressBar.cpp
*
* The implementation of class NexProgressBar. 
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

#include "NexProgressBar.h"

NexProgressBar::NexProgressBar(NexDisplay& display, NexPage& page, uint8_t cid, const char *name, void *value)
  :NexTouch(display, page, cid, name, value) { }

NexProgressBar::NexProgressBar(uint8_t pid, uint8_t cid, const char *name, void *value)
  :NexTouch(pid, cid, name, value) { }

bool NexProgressBar::getValue(uint32_t *number)
{
  return NexObject::getNumeric(NexVALUE, number);
}

bool NexProgressBar::setValue(uint32_t number)
{
  return NexObject::setNumeric(NexVALUE, number);
}
 
bool NexProgressBar::setBackColor(uint32_t color)
{
  return NexObject::setNumeric(NexBACKCOLOR, color);
}

bool NexProgressBar::getBackColor(uint32_t* color)
{
  return NexObject::getNumeric(NexBACKCOLOR, color);
}


bool NexProgressBar::setForeColor(uint32_t color)
{
  return NexObject::setNumeric(NexFORECOLOR, color);
}

bool NexProgressBar::getForeColor(uint32_t* color)
{
  return NexObject::getNumeric(NexFORECOLOR, color);
}


bool NexProgressBar::setActivedPicture(uint32_t picID)
{
  return NexObject::setNumeric(NexFOREPICTURE, picID);
}

bool NexProgressBar::getActivedPicture(uint32_t* picID)
{
  return NexObject::getNumeric(NexFOREPICTURE, picID);
}


bool NexProgressBar::setBackPicture(uint32_t picID)
{
  return NexObject::setNumeric(NexBACKPICTURE, picID);
}

bool NexProgressBar::getBackPicture(uint32_t* picID)
{
  return NexObject::getNumeric(NexBACKPICTURE, picID);
}
