/**
* @file NexPage.h
*
* The definition of class NexPage. 
*
* @author Wu Pengfei (email:<pengfei.wu@itead.cc>)
* @date 2015/8/13
*
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

#ifndef __NEXPAGE_H__
#define __NEXPAGE_H__

#include "NexTouch.h"
#include <map>

/**
 * @addtogroup Component 
 * @{ 
 */

/**
 * A special component , which can contain other components such as NexButton, 
 * NexText and NexWaveform, etc. 
 */
class NexPage: public NexTouch
{
protected: /* methods */
    /*
    * @copydoc NexObject::NexObject(uint8_t pid, uint8_t cid, const char *name, void *value);
    *          cid has to be 0 for pages
    */
    NexPage(uint8_t pid, uint8_t cid, const char *name, void *value = NULL);

public: /* methods */
    /**
    * @copydoc NexObject::NexObject(uint8_t pid, const char *name, void *value);
    */
    NexPage(NexDisplay& display, uint8_t pid, const char *name, void *value = NULL);

    /**
    * @copydoc NexObject::NexObject(uint8_t pid, const char *name, void *value);
    */
    NexPage(uint8_t pid, const char *name, void *value = NULL);

    /**
     * Show itself. 
     * 
     * @return true if success, false for faileure.
     */
    bool show(void);
    NexObject& add(NexObject* newComponent, bool withEvents = false, bool global = false);
    NexObject& add(uint8_t compID, const char* name, void* value = NULL, bool withEvents = false, bool global = false);

protected: /* fields */
  // not yet implemented
  //std::map<uint16_t, NexObject> __components; /* map to hold components on page for access via the page object */
  //                                            // will be filled and used by the owning NexDisplay object
};
/**
 * @}
 */

#endif /* #ifndef __NEXPAGE_H__ */
