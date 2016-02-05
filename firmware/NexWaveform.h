/**
* @file NexWaveform.h
*
* The definition of class NexWaveform. 
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

#ifndef __NEXWAVEFORM_H__
#define __NEXWAVEFORM_H__

#include "NexTouch.h"

/**
 * @addtogroup Component 
 * @{ 
 */

/**
 * NexWaveform component.
 */
class NexWaveform: public NexTouch
{
public: /* methods */
    /**
    * @copydoc NexObject::NexObject(NexDisplay& display, NexPage& page, uint8_t cid, const char *name, void *value);
    */
    NexWaveform(NexDisplay& display, NexPage& page, uint8_t cid, const char *name, void *value = NULL);

    /**
     * @copydoc NexObject::NexObject(uint8_t pid, uint8_t cid, const char *name, void *value);
     */
    NexWaveform(uint8_t pid, uint8_t cid, const char *name, void *value = NULL);
    
    /**
     * Add value to show. 
     *
     * @param ch - channel of waveform(0-3). 
     * @param number - the value of waveform.  
     *
     * @retval true - success. 
     * @retval false - failed. 
     */
    bool addValue(uint8_t ch, uint8_t number);

    bool setBackColor(uint32_t color);
    bool getBackColor(uint32_t* color);

    bool setChannelColor(uint8_t channel, uint32_t color);
    bool getChannelColor(uint8_t channel, uint32_t* color);

    bool setPicture(uint32_t picID);
    bool getPicture(uint32_t* picID);

    bool setCropImage(uint32_t picID);
    bool getCropImage(uint32_t* picID);

    bool setGridColor(uint32_t color);
    bool getGridColor(uint32_t* color);

    bool setGridWidth(uint32_t width);
    bool getGridWidth(uint32_t* width);

};

/**
 * @}
 */

#endif /* #ifndef __NEXWAVEFORM_H__ */
