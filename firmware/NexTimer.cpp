/**
* @file NexTimer.cpp
*
* The implementation of class NexTimer. 
*
* @author  huang xianming (email:<xianming.huang@itead.cc>)
* @date    2015/8/26
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

#include "NexTimer.h"

NexTimer::NexTimer(NexDisplay& display, NexPage& page, uint8_t cid, const char *name, void *value)
  :NexTouch(display, page, cid, name, value) { }

NexTimer::NexTimer(uint8_t pid, uint8_t cid, const char *name, void *value)
  :NexTouch(pid, cid, name, value) { }

void NexTimer::attachTimer(NexTouchEventCb timer)
{
    NexTouch::attachPop(timer);
}

void NexTimer::detachTimer(void)
{
    NexTouch::detachPop();
}

bool NexTimer::getCycle(uint32_t *number)
{
  return NexObject::getNumeric("tim", number);
}

bool NexTimer::setCycle(uint32_t number)
{
  if (number < 50) number = 50;
  return NexObject::setNumeric("tim", number);
}

bool NexTimer::enable(void)
{
  return NexObject::setNumeric("en", 1);
}

bool NexTimer::disable(void)
{
  return NexObject::setNumeric("en", 0);
}

bool NexTimer::getState(bool* state)
{
  return NexObject::getNumeric(NexENABLED, (uint32_t*)state);
}

bool NexTimer::isEnabled()
{
  bool state;
  if (getState(&state))
    return state;
  
  return false;
}
