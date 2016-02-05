/**
* @file NexText.cpp
*
* The implementation of class NexText. 
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

#include "NexText.h"

NexText::NexText(NexDisplay& display, NexPage& page, uint8_t cid, const char *name, void *value)
  :NexTouch(display, page, cid, name, value) { }

NexText::NexText(uint8_t pid, uint8_t cid, const char *name, void *value)
  :NexTouch(pid, cid, name, value) { }

uint16_t NexText::getText(char *buffer, uint16_t len)
{
  return NexObject::getString(NexTEXT, buffer, len);
}

bool NexText::setText(const char *buffer)
{
  return NexObject::setString(NexTEXT, buffer);
}


bool NexText::setBackColor(uint32_t color)
{
  return NexObject::setNumeric(NexBACKCOLOR, color);
}

bool NexText::getBackColor(uint32_t* color)
{
  return NexObject::getNumeric(NexBACKCOLOR, color);
}


bool NexText::setForeColor(uint32_t number)
{
  return NexObject::setNumeric(NexFORECOLOR, number);
}

bool NexText::getForeColor(uint32_t* color)
{
  return NexObject::getNumeric(NexFORECOLOR, color);
}


bool NexText::setPicture(uint32_t picID)
{
  return NexObject::setNumeric(NexPICTURE, picID);
}

bool NexText::getPicture(uint32_t* picID)
{
  return NexObject::getNumeric(NexPICTURE, picID);
}


bool NexText::setCropImage(uint32_t picID)
{
  return NexObject::setNumeric(NexCROPIMAGE, picID);
}

bool NexText::getCropImage(uint32_t* picID)
{
  return NexObject::getNumeric(NexCROPIMAGE, picID);
}


bool NexText::setFont(uint32_t fontID)
{
  return NexObject::setNumeric(NexFONT, fontID);
}

bool NexText::getFont(uint32_t* fontID)
{
  return NexObject::getNumeric(NexFONT, fontID);
}


bool NexText::setAlignX(NexTEXTALIGN_t align)
{
  return NexObject::setNumeric(NexALIGNX, (uint32_t)align);
}

bool NexText::getAlignX(NexTEXTALIGN_t* align)
{
  return NexObject::getNumeric(NexALIGNX, (uint32_t*)align);
}


bool NexText::setAlignY(NexTEXTALIGN_t align)
{
  return NexObject::setNumeric(NexALIGNY, (uint32_t)align);
}

bool NexText::getAlignY(NexTEXTALIGN_t* align)
{
  return NexObject::getNumeric(NexALIGNX, (uint32_t*)align);
}
