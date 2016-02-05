/**
* @file NexObject.h
*
* The definition of class NexObject. 
*
* @author Wu Pengfei (email:<pengfei.wu@itead.cc>)
* @date 2015/8/13
*
* @copyright 
* Copyright (C) 2014-2015 ITEAD Intelligent Systems Co., Ltd.
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation; either version 2 of
* the License, or (at your option) any later version.
*
* Port for Particle platform (particle.io)
* by BSpranger & ScruffR (Dec. 2015)
*/

#ifndef __NEXOBJECT_H__
#define __NEXOBJECT_H__

#include "Particle.h"
#include "NexCommands.h"

class NexDisplay;  // forward declare required class
class NexPage;     // forward declare required class

 /**
 * @addtogroup CoreAPI 
 * @{ 
 */

   /**
 * String touch event occuring when your finger or pen coming to Nextion touch pannel. 
 */
#define NEX_EVENT_STRING  (0x03)
 
 /**
 * Value touch event occuring when your finger or pen coming to Nextion touch pannel. 
 */
#define NEX_EVENT_VALUE  (0x02)
 
/**
 * Push touch event occuring when your finger or pen coming to Nextion touch pannel. 
 */
#define NEX_EVENT_PUSH  (0x01)

/**
 * Pop touch event occuring when your finger or pen leaving from Nextion touch pannel. 
 */
#define NEX_EVENT_POP   (0x00)  
 
 
/**
 * Root class of all Nextion components. 
 *
 * Provides the essential attributes of a Nextion component and the methods accessing
 * them. At least, Page ID(pid), Component ID(pid) and an unique name are needed for
 * creating a component in Nexiton library. 
 */

class NexObject 
{
protected: /* methods */

public:    /* methods */
    /**
    * Constructor.
    *
    * @param display - ref to owning display hardware
    * @param page    - ref to owning page
    * @param cid     - component id.
    * @param name    - pointer to an unique name in range of all components.
    * @param value   - pointer to the default value of the component.
    */
    NexObject(NexDisplay& display, NexPage& page, uint8_t cid, const char *name, void *value = NULL);

    /**
    * Constructor.
    *
    * @param pid   - page id.
    * @param cid   - component id.
    * @param name  - pointer to an unique name in range of all components.
    * @param value - pointer to the default value of the component.
    */
    NexObject(uint8_t pid, uint8_t cid, const char *name, void *value = NULL);

    /*
     * Get page id.
     *
     * @return the id of page.  
     */
    uint8_t getObjPid(void);    

    /*
     * Get component id.
     *
     * @return the id of component.  
     */
    uint8_t getObjCid(void);

    /*
     * Get component name.
     *
     * @return the name of component. 
     */
    const char *getObjName(void);

    /*
     * Get component value.
     *
     * @return the value of component. 
     */
    void *getObjValue(void);    
    
    /*
     * Set component value.
     *
     * @return none 
     */
    void setObjValue(uint8_t type, void *value);

    bool runCommand(const char* cmd);

    bool getNumeric(const char* valueType, uint32_t* value);
    bool setNumeric(const char* valueType, uint32_t value);

    uint16_t getString(const char* valueType, char* text, uint16_t len);
    bool setString(const char* valueType, const char* text);
    
    bool operator==(const NexObject&) const;
    bool operator!=(const NexObject&) const;

protected: /* data */
    NexDisplay* __display;  /* pointer to the owning display for hardware access   */ 
    NexPage*    __page;     /* pointer to the owning page (NexPages are selfowned) */
    uint8_t __pid = 0;      /* Page ID (will be set even for global compnents)     */
    uint8_t __cid = 0;      /* Component ID                                        */
    const char *__name;     /* An unique name                                      */
    void *__value;

    friend class NexDisplay; // grant access to protected functions / fields for NexDisplay
    friend class NexPage;    // grant access to protected functions / fields for NexPage
};
/**
 * @}
 */

#endif /* #ifndef __NEXOBJECT_H__ */
