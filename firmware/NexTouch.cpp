/**
* @file NexTouch.cpp
*
* The implementation of class NexTouch.
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

#include "NexTouch.h"
#include "NexDisplay.h"

NexTouch::NexTouch(NexDisplay& display, NexPage& page, uint8_t cid, const char *name, void *value)
  :NexObject(display, page, cid, name, value)
{
  this->__cb_push = NULL;
  this->__cb_pop = NULL;
  this->__cb_value = NULL;
}


NexTouch::NexTouch(uint8_t pid, uint8_t cid, const char *name, void *value)
  :NexObject(pid, cid, name, value)
{
  this->__cb_push = NULL;
  this->__cb_pop = NULL;
  this->__cb_value = NULL;
}

void NexTouch::attachPush(NexTouchEventCb callback)
{
  this->__cb_push = callback;
}

void NexTouch::detachPush(void)
{
  this->__cb_push = NULL;
}

void NexTouch::attachPop(NexTouchEventCb callback)
{
  this->__cb_pop = callback;
}

void NexTouch::detachPop(void)
{
  this->__cb_pop = NULL;
}

void NexTouch::attachValue(NexTouchEventCb callback)
{
  this->__cb_value = callback;
}

void NexTouch::detachValue(void)
{
  this->__cb_value = NULL;
}

void NexTouch::push(void)
{
  if (__cb_push)
    __display->enqueueEvent(__cb_push);
}

void NexTouch::pop(void)
{
  if (__cb_pop)
    __display->enqueueEvent(__cb_pop);
}

void NexTouch::value(void)
{
  if (__cb_value)
    __display->enqueueEvent(__cb_value);
}
