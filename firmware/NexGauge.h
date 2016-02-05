/**
* @file NexGauge.h
*
* The definition of class NexGauge. 
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
 
#ifndef __NEXGAUGE_H__
#define __NEXGAUGE_H__

#include "NexTouch.h"

/**
 * @addtogroup Component 
 * @{ 
 */

/**
 * NexGauge component.
 */
class NexGauge: public NexTouch
{
public: /* methods */
    /**
    * @copydoc NexObject::NexObject(NexDisplay& display, NexPage& page, uint8_t cid, const char *name, void *value);
    */
    NexGauge(NexDisplay& display, NexPage& page, uint8_t cid, const char *name, void *value = NULL);

    /**
    * @copydoc NexObject::NexObject(uint8_t pid, uint8_t cid, const char *name, void *value);
    */
    NexGauge(uint8_t pid, uint8_t cid, const char *name, void *value = NULL);
    /**
     * Get the value of gauge.
     * 
     * @param number - an output parameter to save gauge's value.
     * 
     * @retval true - success. 
     * @retval false - failed. 
     */
    bool getValue(uint32_t *number);
    
    /**
     * Set the value of gauge. 
     *
     * @param number - the value of gauge.  
     *
     * @retval true - success. 
     * @retval false - failed. 
     */
    bool setValue(uint32_t number);


    bool setBackColor(uint32_t color);
    bool getBackColor(uint32_t* color);

    bool setForeColor(uint32_t color);
    bool getForeColor(uint32_t* color);

    bool setCropImage(uint32_t picID);
    bool getCropImage(uint32_t* picID);

    bool setWidth(uint32_t width);
    bool getWidth(uint32_t* width);

};

/**
 * @}
 */

#endif /* #ifndef __NEXGAUGE_H__ */
