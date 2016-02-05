/**
* @file NexDualStateButton.cpp
*
* The implementation of class NexDSButton. 
*
* @author  huang xianming (email:<xianming.huang@itead.cc>)
* @date    2015/11/11
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

#include "NexDualStateButton.h"

NexDSButton::NexDSButton(NexDisplay& display, NexPage& page, uint8_t cid, const char *name, void *value)
  :NexTouch(display, page, cid, name, value) { }

NexDSButton::NexDSButton(uint8_t pid, uint8_t cid, const char *name, void *value)
  :NexTouch(pid, cid, name, value) { }


bool NexDSButton::getValue(uint32_t *number)
{
  return NexObject::getNumeric(NexVALUE, number);
}

bool NexDSButton::setValue(uint32_t number)
{
  return NexObject::setNumeric(NexVALUE, number);
}


bool NexDSButton::setBackColor(uint32_t color)
{
  return NexObject::setNumeric(NexBACKCOLOR0, color);
}

bool NexDSButton::getBackColor(uint32_t* color)
{
  return NexObject::getNumeric(NexBACKCOLOR0, color);
}


bool NexDSButton::setActivedBackColor(uint32_t color)
{
  return NexObject::setNumeric(NexBACKCOLOR1, color);
}

bool NexDSButton::getActivedBackColor(uint32_t* color)
{
  return NexObject::getNumeric(NexBACKCOLOR1, color);
}



bool NexDSButton::setPicture(uint32_t picID)
{
  return NexObject::setNumeric(NexPICTURE0, picID);
}

bool NexDSButton::getPicture(uint32_t* picID)
{
  return NexObject::getNumeric(NexPICTURE0, picID);
}


bool NexDSButton::setActivedPicture(uint32_t picID)
{
  return NexObject::setNumeric(NexPICTURE1, picID);
}

bool NexDSButton::getActivedPicture(uint32_t* picID)
{
  return NexObject::getNumeric(NexPICTURE1, picID);
}




bool NexDSButton::setCropImage(uint32_t picID)
{
  return NexObject::setNumeric(NexCROPIMAGE0, picID);
}

bool NexDSButton::getCropImage(uint32_t* picID)
{
  return NexObject::getNumeric(NexCROPIMAGE0, picID);
}


bool NexDSButton::setActivatedCropImage(uint32_t picID)
{
  return NexObject::setNumeric(NexCROPIMAGE1, picID);
}

bool NexDSButton::getActivatedCropImage(uint32_t* picID)
{
  return NexObject::getNumeric(NexCROPIMAGE1, picID);
}
