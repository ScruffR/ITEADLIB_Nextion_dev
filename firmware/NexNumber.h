/**
* @file NexNumber.h
*
* The definition of class NexNumber. 
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
* by ScruffR (Dec. 2015)
*/
 
#ifndef __NEXNUMBER_H__
#define __NEXNUMBER_H__

#include "NexTouch.h"

/**
 * @addtogroup Component 
 * @{ 
 */

/**
 * NexNumber component.
 */
class NexNumber: public NexTouch
{
public: /* methods */
    /**
    * @copydoc NexObject::NexObject(NexDisplay& display, NexPage& page, uint8_t cid, const char *name, void *value);
    */
    NexNumber(NexDisplay& display, NexPage& page, uint8_t cid, const char *name, void *value = NULL);
    /**
     * @copydoc NexObject::NexObject(uint8_t pid, uint8_t cid, const char *name, void *value);
     */
    NexNumber(uint8_t pid, uint8_t cid, const char *name, void *value = NULL);
    
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

    bool setForeColor(uint32_t color);
    bool getForeColor(uint32_t* color);

    bool setPicture(uint32_t picID);
    bool getPicture(uint32_t* picID);

    bool setCropImage(uint32_t picID);
    bool getCropImage(uint32_t* picID);

    bool setFont(uint32_t fontID);
    bool getFont(uint32_t* fontID);

    bool setAlignX(NexTEXTALIGN_t align);
    bool getAlignX(NexTEXTALIGN_t *align);

    bool setAlignY(NexTEXTALIGN_t align);
    bool getAlignY(NexTEXTALIGN_t* align);

    bool setLength(uint32_t len);
    bool getLength(uint32_t* len);

};

/**
 * @}
 */

#endif /* #ifndef __NEXNUMBER_H__ */
