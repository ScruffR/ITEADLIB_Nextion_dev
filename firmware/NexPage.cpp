/**
* @file NexPage.cpp
*
* The implementation of class NexPage. 
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

#include "NexPage.h"
#include "NexDisplay.h"

NexPage::NexPage(NexDisplay& display, uint8_t pid, const char *name, void *value)
  :NexTouch(display, *this, 0, name, value) 
{
  this->__pid = pid;
}

NexPage::NexPage(uint8_t pid, uint8_t cid, const char *name, void *value)
  :NexTouch(pid, cid, name, value) { }

NexPage::NexPage(uint8_t pid, const char *name, void *value)
  : NexTouch(pid, 0, name, value) { }

bool NexPage::show(void)
{
  char cmd[32];
  //sprintf(cmd, NexPAGENAME, __name);
  sprintf(cmd, NexPAGEID, __pid);
  return runCommand(cmd);
}

NexObject& NexPage::add(NexObject* newComponent, bool withEvents, bool global)
{
  // ToDo: add to private components map
  // ToDo: treatment for global components on owning page (???)
  if (newComponent->__pid != __pid)
    return *this;  // component not part of this page return page
  return __display->add(*newComponent, withEvents, global);
}

NexObject& NexPage::add(uint8_t compID, const char* name, void* value, bool withEvents, bool global)
{
  // ToDo: add to private components map
  // ToDo: treatment for global components on owning page (???)
  return __display->add(*this, compID, name, value, withEvents, global);
}
