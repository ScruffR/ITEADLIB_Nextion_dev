/**
* @file NexDualStateButton.h
*
* The definition of class NexDSButton. 
*
* @author  huang xianming (email:<xianming.huang@itead.cc>)
* @date    2015/11/11
*   
*
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

#ifndef __NEXDSBUTTON_H__
#define __NEXDSBUTTON_H__

#include "NexTouch.h"

/**
 * @addtogroup Component 
 * @{ 
 */

/**
 * NexDSButton component. 
 *
 * Commonly, you want to do something after push and pop it. It is recommanded that only
 * call @ref NexTouch::attachPop to satisfy your purpose. 
 * 
 * @warning Please do not call @ref NexTouch::attachPush on this component, even though you can. 
 */
class NexDSButton: public NexTouch
{
public: /* methods */
    /**
    * @copydoc NexObject::NexObject(NexDisplay& display, NexPage& page, uint8_t cid, const char *name, void *value);
    */
    NexDSButton(NexDisplay& display, NexPage& page, uint8_t cid, const char *name, void *value = NULL);

    /**
     * @copydoc NexObject::NexObject(uint8_t pid, uint8_t cid, const char *name, void *value);
     */
    NexDSButton(uint8_t pid, uint8_t cid, const char *name, void *value = NULL);
    
    /**
     * Get number attribute of component.
     *
     * @param buffer - buffer storing text returned. 
     * @param len - length of buffer. 
     * @return The real length of text returned. 
     */
    bool getValue(uint32_t *number);
    
    /**
     * Set number attribute of component.
     *
     * @param buffer - number buffer. 
     * @return true if success, false for failure. 
     */
    bool setValue(uint32_t number);

    bool setBackColor(uint32_t color);
    bool getBackColor(uint32_t* color);

    bool setActivedBackColor(uint32_t color);
    bool getActivedBackColor(uint32_t* color);

    bool setPicture(uint32_t picID);
    bool getPicture(uint32_t* picID);

    bool setActivedPicture(uint32_t picID);
    bool getActivedPicture(uint32_t* picID);

    bool setCropImage(uint32_t picID);
    bool getCropImage(uint32_t* picID);

    bool setActivatedCropImage(uint32_t picID);
    bool getActivatedCropImage(uint32_t* picID);

};
/**
 * @}
 */

#endif /* #ifndef __NEXDSBUTTON_H__ */