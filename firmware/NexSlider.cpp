/**
* @file NexSlider.cpp
*
* The implementation of class NexSlider. 
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

#include "NexSlider.h"

NexSlider::NexSlider(NexDisplay& display, NexPage& page, uint8_t cid, const char *name, void *value)
  :NexTouch(display, page, cid, name, value) { }

NexSlider::NexSlider(uint8_t pid, uint8_t cid, const char *name, void *value)
  :NexTouch(pid, cid, name, value) { }

bool NexSlider::getValue(uint32_t *number)
{
  return NexObject::getNumeric(NexVALUE, number);
}

bool NexSlider::setValue(uint32_t number)
{
  return NexObject::setNumeric(NexVALUE, number);
}


bool NexSlider::setMaxVal(uint32_t number)
{
  return NexObject::setNumeric(NexMAXVALUE, number);
}

bool NexSlider::getMaxVal(uint32_t *number)
{
  return NexObject::getNumeric(NexMAXVALUE, number);
}


bool NexSlider::setMinVal(uint32_t number)
{
  return NexObject::setNumeric(NexMINVALUE, number);
}

bool NexSlider::getMinVal(uint32_t *number)
{
  return NexObject::getNumeric(NexMINVALUE, number);
}


bool NexSlider::setBackColor(uint32_t color)
{
  return NexObject::setNumeric(NexBACKCOLOR, color);
}

bool NexSlider::getBackColor(uint32_t* color)
{
  return NexObject::getNumeric(NexBACKCOLOR, color);
}


bool NexSlider::setForeColor(uint32_t color)
{
  return NexObject::setNumeric(NexFORECOLOR, color);
}

bool NexSlider::getForeColor(uint32_t* color)
{
  return NexObject::getNumeric(NexFORECOLOR, color);
}


bool NexSlider::setPicture(uint32_t picID)
{
  return NexObject::setNumeric(NexPICTURE, picID);
}

bool NexSlider::getPicture(uint32_t* picID)
{
  return NexObject::getNumeric(NexPICTURE, picID);
}


bool NexSlider::setThumbPicture(uint32_t picID)
{
  return NexObject::setNumeric(NexPICTUREACT, picID);
}

bool NexSlider::getThumbPicture(uint32_t* picID)
{
  return NexObject::getNumeric(NexPICTUREACT, picID);
}


bool NexSlider::setCropImage(uint32_t picID)
{
  return NexObject::setNumeric(NexCROPIMAGE, picID);
}

bool NexSlider::getCropImage(uint32_t* picID)
{
  return NexObject::getNumeric(NexCROPIMAGE, picID);
}


bool NexSlider::setThumbWidth(uint32_t width)
{
  return NexObject::setNumeric(NexTHUMBWIDTH, width);
}

bool NexSlider::getThumbWidth(uint32_t* width)
{
  return NexObject::getNumeric(NexTHUMBWIDTH, width);
}


bool NexSlider::setThumbHeight(uint32_t height)
{
  return NexObject::setNumeric(NexTHUMBHEIGHT, height);
}

bool NexSlider::getThumbHeight(uint32_t* height)
{
  return NexObject::getNumeric(NexTHUMBHEIGHT, height);
}
