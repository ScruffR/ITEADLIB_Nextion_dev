/**
* @file NexNumber.cpp
*
* The implementation of class NexNumber. 
*
* @author  huang xianming (email:<xianming.huang@itead.cc>)
* @date    2015/8/13
* @copyright 
* Copyright (C) 2014-2015 ITEAD Intelligent Systems Co., Ltd. \n
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation; either version 2 of
* the License, or (at your option) any later version.
*
* Port for Particle platform (particle.io)
* by ScruffR (Dec. 2015)
*/

#include "NexNumber.h"

NexNumber::NexNumber(NexDisplay& display, NexPage& page, uint8_t cid, const char *name, void *value)
  :NexTouch(display, page, cid, name, value) { }

NexNumber::NexNumber(uint8_t pid, uint8_t cid, const char *name, void *value)
  :NexTouch(pid, cid, name, value) { }

bool NexNumber::getValue(uint32_t *number)
{
  return NexObject::getNumeric(NexVALUE, number);
}

bool NexNumber::setValue(uint32_t number)
{
  return NexObject::setNumeric(NexVALUE, number);
}

bool NexNumber::setBackColor(uint32_t color)
{
  return NexObject::setNumeric(NexBACKCOLOR, color);
}

bool NexNumber::getBackColor(uint32_t* color)
{
  return NexObject::getNumeric(NexBACKCOLOR, color);
}


bool NexNumber::setForeColor(uint32_t color)
{
  return NexObject::setNumeric(NexFORECOLOR, color);
}

bool NexNumber::getForeColor(uint32_t* color)
{
  return NexObject::getNumeric(NexFORECOLOR, color);
}


bool NexNumber::setPicture(uint32_t picID)
{
  return NexObject::setNumeric(NexPICTURE, picID);
}

bool NexNumber::getPicture(uint32_t* picID)
{
  return NexObject::getNumeric(NexPICTURE, picID);
}


bool NexNumber::setCropImage(uint32_t picID)
{
  return NexObject::setNumeric(NexCROPIMAGE, picID);
}

bool NexNumber::getCropImage(uint32_t* picID)
{
  return NexObject::getNumeric(NexCROPIMAGE, picID);
}


bool NexNumber::setFont(uint32_t fontID)
{
  return NexObject::setNumeric(NexFONT, fontID);
}

bool NexNumber::getFont(uint32_t* fontID)
{
  return NexObject::getNumeric(NexFONT, fontID);
}


bool NexNumber::setAlignX(NexTEXTALIGN_t align)
{
  return NexObject::setNumeric(NexALIGNX, (uint32_t)align);
}

bool NexNumber::getAlignX(NexTEXTALIGN_t* align)
{
  return NexObject::getNumeric(NexALIGNX, (uint32_t*)align);
}


bool NexNumber::setAlignY(NexTEXTALIGN_t align)
{
  return NexObject::setNumeric(NexALIGNY, (uint32_t)align);
}

bool NexNumber::getAlignY(NexTEXTALIGN_t* align)
{
  return NexObject::getNumeric(NexALIGNX, (uint32_t*)align);
}


bool NexNumber::setLength(uint32_t len)
{
  return NexObject::setNumeric(NexLENGTH, len);
}

bool NexNumber::getLength(uint32_t* len)
{
  return NexObject::getNumeric(NexLENGTH, len);
}

