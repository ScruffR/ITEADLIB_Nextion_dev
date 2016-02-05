/**
* @file NexButton.cpp
*
* The implementation of class NexButton. 
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

#include "NexButton.h"

NexButton::NexButton(NexDisplay& display, NexPage& page, uint8_t cid, const char *name, void *value)
  :NexTouch(display, page, cid, name, value) { }

NexButton::NexButton(uint8_t pid, uint8_t cid, const char *name, void *value)
  :NexTouch(pid, cid, name, value) { }

uint16_t NexButton::getText(char *buffer, uint16_t len)
{
  return NexObject::getString(NexTEXT, buffer, len);
}

bool NexButton::setText(const char *buffer)
{
  return NexObject::setString(NexTEXT, buffer);
}


bool NexButton::setBackColor(uint32_t color)
{
  return NexObject::setNumeric(NexBACKCOLOR, color);
}

bool NexButton::getBackColor(uint32_t* color)
{
  return NexObject::getNumeric(NexBACKCOLOR, color);
}


bool NexButton::setActivedBackColor(uint32_t color)
{
  return NexObject::setNumeric(NexBACKCOLORACT, color);
}

bool NexButton::getActivedBackColor(uint32_t* color)
{
  return NexObject::getNumeric(NexBACKCOLORACT, color);
}


bool NexButton::setForeColor(uint32_t color)
{
  return NexObject::setNumeric(NexFORECOLOR, color);
}

bool NexButton::getForeColor(uint32_t* color)
{
  return NexObject::getNumeric(NexFORECOLOR, color);
}


bool NexButton::setActivedForeColor(uint32_t color)
{
  return NexObject::setNumeric(NexFORECOLORACT, color);
}

bool NexButton::getActivedForeColor(uint32_t* color)
{
  return NexObject::getNumeric(NexFORECOLORACT, color);
}


bool NexButton::setPicture(uint32_t picID)
{
  return NexObject::setNumeric(NexPICTURE, picID);
}

bool NexButton::getPicture(uint32_t* picID)
{
  return NexObject::getNumeric(NexPICTURE, picID);
}


bool NexButton::setActivedPicture(uint32_t picID)
{
  return NexObject::setNumeric(NexPICTUREACT, picID);
}

bool NexButton::getActivedPicture(uint32_t* picID)
{
  return NexObject::getNumeric(NexPICTUREACT, picID);
}


bool NexButton::setCropImage(uint32_t picID)
{
  return NexObject::setNumeric(NexCROPIMAGE, picID);
}

bool NexButton::getCropImage(uint32_t* picID)
{
  return NexObject::getNumeric(NexCROPIMAGE, picID);
}


bool NexButton::setActivatedCropImage(uint32_t picID)
{
  return NexObject::setNumeric(NexCROPIMAGEACT, picID);
}

bool NexButton::getActivatedCropImage(uint32_t* picID)
{
  return NexObject::getNumeric(NexCROPIMAGEACT, picID);
}


bool NexButton::setFont(uint32_t fontID)
{
  return NexObject::setNumeric(NexFONT, fontID);
}

bool NexButton::getFont(uint32_t* fontID)
{
  return NexObject::getNumeric(NexFONT, fontID);
}


bool NexButton::setAlignX(NexTEXTALIGN_t align)
{
  return NexObject::setNumeric(NexALIGNX, (uint32_t)align);
}

bool NexButton::getAlignX(NexTEXTALIGN_t* align)
{
  return NexObject::getNumeric(NexALIGNX, (uint32_t*)align);
}


bool NexButton::setAlignY(NexTEXTALIGN_t align)
{
  return NexObject::setNumeric(NexALIGNY, (uint32_t)align);
}

bool NexButton::getAlignY(NexTEXTALIGN_t* align)
{
  return NexObject::getNumeric(NexALIGNX, (uint32_t*)align);
}

