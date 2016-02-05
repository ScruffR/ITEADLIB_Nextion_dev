/**
* @file NexTouch.h
*
* The definition of class NexTouch. 
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

#ifndef __NEXTOUCH_H__
#define __NEXTOUCH_H__

#if defined(SPARK)
#include "Particle.h"
#else
#include "Arduino.h"
#endif

#include "NexConfig.h"
#include "NexObject.h"

/**
 * @addtogroup TouchEvent 
 * @{ 
 */

/**
 * Type of callback funciton when an touch event occurs. 
 * 
 * @return none. 
 */
typedef void (*NexTouchEventCb)();

/**
 * Father class of the components with touch events.  
 *
 * Derives from NexObject and provides methods allowing user to attach
 * (or detach) a callback function called when push(or pop) touch event occurs.
 */
class NexTouch: public NexObject 
{
public: /* static methods */    
    //static void iterate(NexTouch **list, uint8_t pid, uint8_t cid, int32_t event, void *value = NULL);

public: /* methods */
    /**
    * @copydoc NexObject::NexObject(NexDisplay& display, NexPage& page, uint8_t cid, const char *name, void *value);
    */
    NexTouch(NexDisplay& display, NexPage& page, uint8_t cid, const char *name, void *value = NULL);
    /**
    * @copydoc NexObject::NexObject(uint8_t pid, uint8_t cid, const char *name, void *value);
    */
    NexTouch(uint8_t pid, uint8_t cid, const char *name, void *value = NULL);

    /**
     * Attach an callback function of push touch event. 
     *
     * @param callback - function called with data when a push touch event occurs. 
     * @return none. 
     *
     * @note If calling this method multiple times, the last call is valid. 
     */
    void attachPush(NexTouchEventCb callback);

    /**
     * Detach an callback function. 
     * 
     * @return none. 
     */
    void detachPush(void);

    /**
     * Attach an callback function of pop touch event. 
     *
     * @param callback - function called with data when a pop touch event occurs. 
     * @return none. 
     *
     * @note If calling this method multiple times, the last call is valid. 
     */
    void attachPop(NexTouchEventCb callback);

    /**
     * Detach an callback function. 
     * 
     * @return none. 
     */
    void detachPop(void);
    
    
     /**
     * Attach an callback function of value touch event. 
     *
     * @param callback - function called with data when a value touch event occurs. 
     * @return none. 
     *
     * @note If calling this method multiple times, the last call is valid. 
     */
    void attachValue(NexTouchEventCb callback);

    /**
     * Detach an callback function. 
     * 
     * @return none. 
     */
    void detachValue(void);
    
private: /* methods */ 
    void push(void);
    void pop(void);
    void value(void);

private: /* data */ 
    NexTouchEventCb __cb_push;
    NexTouchEventCb __cb_pop;
    NexTouchEventCb __cb_value;

    friend class NexDisplay; // grant access to private date for NexDisplay
};

/**
 * @}
 */

#endif /* #ifndef __NEXTOUCH_H__ */
