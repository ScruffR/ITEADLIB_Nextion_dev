/**
* @file NexSlider.h
*
* The definition of class NexSlider. 
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

#ifndef __NEXSLIDER_H__
#define __NEXSLIDER_H__

#include "NexTouch.h"

/**
 * @addtogroup Component 
 * @{ 
 */

/**
 * NexSlider component. 
 */
class NexSlider: public NexTouch
{
public: /* methods */
    /**
    * @copydoc NexObject::NexObject(NexDisplay& display, NexPage& page, uint8_t cid, const char *name, void *value);
    */
    NexSlider(NexDisplay& display, NexPage& page, uint8_t cid, const char *name, void *value = NULL);

    /**
    * @copydoc NexObject::NexObject(uint8_t pid, uint8_t cid, const char *name, void *value);
    */
    NexSlider(uint8_t pid, uint8_t cid, const char *name, void *value = NULL);

    /**
     * Get the value of slider. 
     * 
     * @param number - an output parameter to save the value of slider.  
     * 
     * @retval true - success. 
     * @retval false - failed. 
     */
    bool getValue(uint32_t *number);
    
    /**
     * Set the value of slider.
     *
     * @param number - the value of slider.  
     *
     * @retval true - success. 
     * @retval false - failed. 
     */
    bool setValue(uint32_t number);
    
    bool setMaxVal(uint32_t number);
    bool getMaxVal(uint32_t* number);

    bool setMinVal(uint32_t number);
    bool getMinVal(uint32_t* number);

    bool setBackColor(uint32_t color);
    bool getBackColor(uint32_t* color);

    bool setForeColor(uint32_t color);
    bool getForeColor(uint32_t* color);

    bool setPicture(uint32_t picID);
    bool getPicture(uint32_t* picID);

    bool setThumbPicture(uint32_t picID);
    bool getThumbPicture(uint32_t* picID);

    bool setCropImage(uint32_t picID);
    bool getCropImage(uint32_t* picID);

    bool setThumbWidth(uint32_t width);
    bool getThumbWidth(uint32_t* width);

    bool setThumbHeight(uint32_t height);
    bool getThumbHeight(uint32_t* height);

};
/**
 * @}
 */


#endif /* #ifndef __NEXSLIDER_H__ */
