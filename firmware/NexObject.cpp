/**
* @file NexObject.cpp
*
* The implementation of class NexObject. 
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

#include "NexObject.h"
#include "NexDisplay.h"

NexObject::NexObject(NexDisplay& display, NexPage& page, uint8_t cid, const char *name, void *value)
{
  this->__display = &display;
  this->__page = &page;
  this->__pid = page.__pid;
  this->__cid = cid;
  this->__name = name;
  this->__value = value;
}

NexObject::NexObject(uint8_t pid, uint8_t cid, const char *name, void *value)
{
    this->__pid = pid;
    this->__cid = cid;
    this->__name = name;
    this->__value = value;
}

void NexObject::setObjValue(uint8_t type, void *value)
{
    if (__value)
    {
        switch (type)
        {
          case NEX_EVENT_VALUE:
             *((unsigned long *)__value) = (((uint8_t *)value)[0]) | (((unsigned long)((uint8_t *)value)[1]) << 8) | (((unsigned long)((uint8_t *)value)[2]) << 16) | (((unsigned long)((uint8_t *)value)[3]) << 24);
            break;
          case NEX_EVENT_STRING:
            if (value)
              strncpy((char*)__value, (const char*)value, strlen((const char*)value));
            else
              *((char*)__value) = '\0';
            break;
          default:
            //*(__value) = 0;
            break;
        }
    }
}

uint8_t NexObject::getObjPid(void)
{
    return __pid;
}

uint8_t NexObject::getObjCid(void)
{
    return __cid;
}

const char* NexObject::getObjName(void)
{
    return __name;
}

void* NexObject::getObjValue(void)
{
    return __value;
}

bool NexObject::runCommand(const char* cmd)
{
  return __display->runCommand(cmd);
}

bool NexObject::getNumeric(const char* valueType, uint32_t* value)
{
  char attrib[32];
  snprintf(attrib, sizeof(attrib), "%s.%s", __name, valueType);
  return __display->getNumeric(attrib, value);
}

bool NexObject::setNumeric(const char* valueType, uint32_t value)
{
  char attrib[32];
  snprintf(attrib, sizeof(attrib), "%s.%s", __name, valueType);
  return __display->setNumeric(attrib, value);
}

uint16_t NexObject::getString(const char* valueType, char* text, uint16_t len)
{
  char attrib[32];
  snprintf(attrib, sizeof(attrib), "%s.%s", __name, valueType);
  return __display->getString(attrib, text, len);
}

bool NexObject::setString(const char* valueType, const char* text)
{
  char attrib[32];
  snprintf(attrib, sizeof(attrib), "%s.%s", __name, valueType);
  return __display->setString(attrib, text);
}

bool NexObject::operator==(const NexObject& other) const
{
  return (this->__pid == other.__pid && this->__cid == other.__cid);
}

bool NexObject::operator!=(const NexObject& other) const
{
  return (this->__pid != other.__pid || this->__cid != other.__cid);
}
