/**
* @file NexWaveform.cpp
*
* The implementation of class NexWaveform. 
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

#include "NexWaveform.h"

NexWaveform::NexWaveform(NexDisplay& display, NexPage& page, uint8_t cid, const char *name, void *value)
  :NexTouch(display, page, cid, name, value) { }

NexWaveform::NexWaveform(uint8_t pid, uint8_t cid, const char *name, void *value)
  :NexTouch(pid, cid, name, value) { }

bool NexWaveform::addValue(uint8_t ch, uint8_t number)
{
    char buf[15] = {0};
    
    if (ch > 3)
    {
        return false;
    }
    
    sprintf(buf, NexWAVEADDPOINT, getObjCid(), ch, number);

    return runCommand(buf);
}
 
bool NexWaveform::setBackColor(uint32_t color)
{
  return NexObject::setNumeric(NexBACKCOLOR, color);
}

bool NexWaveform::getBackColor(uint32_t* color)
{
  return NexObject::getNumeric(NexBACKCOLOR, color);
}


bool NexWaveform::setChannelColor(uint8_t channel, uint32_t color)
{
  if (channel > 3) return false;
  char type[8];
  snprintf(type, sizeof(type), "%s%u", NexFORECOLOR, channel);
  return NexObject::setNumeric(type, color);
}

bool NexWaveform::getChannelColor(uint8_t channel, uint32_t* color)
{
  if (channel > 3) return false;
  char type[8];
  snprintf(type, sizeof(type), "%s%u", NexFORECOLOR, channel);
  return NexObject::getNumeric(type, color);
}
bool NexWaveform::setPicture(uint32_t picID)
{
  return NexObject::setNumeric(NexPICTURE, picID);
}

bool NexWaveform::getPicture(uint32_t* picID)
{
  return NexObject::getNumeric(NexPICTURE, picID);
}


bool NexWaveform::setCropImage(uint32_t picID)
{
  return NexObject::setNumeric(NexCROPIMAGE, picID);
}

bool NexWaveform::getCropImage(uint32_t* picID)
{
  return NexObject::getNumeric(NexCROPIMAGE, picID);
}


bool NexWaveform::setGridColor(uint32_t color)
{
  return NexObject::setNumeric(NexGRIDCOLOR, color);
}

bool NexWaveform::getGridColor(uint32_t* color)
{
  return NexObject::getNumeric(NexGRIDCOLOR, color);
}


bool NexWaveform::setGridWidth(uint32_t width)
{
  return NexObject::setNumeric(NexGRIDWIDTH, width);
}

bool NexWaveform::getGridWidth(uint32_t* width)
{
  return NexObject::getNumeric(NexGRIDWIDTH, width);
}
