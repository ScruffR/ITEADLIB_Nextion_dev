/**
* @file NexDisplay.h
*
* The implementation of class NexDisplay.
*
* @author  Andreas Rothenwänder (aka ScruffR http://community.particle.io)
* @date    2015/12/01
* @copyright
* Copyright (C) 2015-2016 Andreas Rothenwänder
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation; either version 2 of
* the License, or (at your option) any later version.
*/

#ifndef __NEXDISPLAY_H__
#define __NEXDISPLAY_H__

#include "Nextion.h"

#include <map>

class NexObject;  // forward declare required class

/**
* Main class of the Nextion display.
*
* Provides the essential attributes of a Nextion component and the methods accessing
* them. At least, Page ID(pid), Component ID(pid) and an unique name are needed for
* creating a component in Nexiton library.
*/
class NexDisplay
{
public: /* methods */
  /**
  * Constructor.
  *
  * @param width    - display width in pixels
  * @param height   - display height in pixels
  * @param serial   - reference to the serial com port to use
  * @param baudrate - baud rate for communication between MCU and display
  */
  NexDisplay(USARTSerial& serial = Serial1, uint32_t baudrate = 9600);
  NexDisplay(uint16_t width, uint16_t height, USARTSerial& serial = Serial1, uint32_t baudrate = 9600);
  
  ~NexDisplay();


  /**
  * Initializes the serial communication and resets display
  *
  * @param baudrate - if 0, the value of __baud is kept otherwise set
  */
  bool init(uint32_t baudrate = 0);

  /**
  * Send a printf formatted command to the display
  *
  * @param cmdPattern - printf format string for command
  * @param ...        - printf value list
  */
  int  sendCommand(const char *cmdPattern, ...);

  /*
  * Send a batch of commands (skript) each terminated by NexCMDTERM
  * If noRR is set TRUE
  *   For the batch the command execution result response gets
  *   temporarily deactivated.
  *   After completion it will be reactivated and set to the
  *   previously saved state (__bkCmd).
  *
  * @param cmd  - the skript (each command must be terminated individually)
  * @param noRR - indicate if result response should be deactivated (default false)
  */
  void sendSkript(const char* cmd, bool noRR);

  bool      sendCurrentPageId(uint8_t* pageId);
  bool      setBrightness(uint8_t dimValue, bool setDefault = false);
  bool      setBaudrate(uint32_t baudrate, bool setDefault = false);
  void      sendRefreshAll(void);

  bool      runCommand(const char *cmdPattern);
  bool      getNumeric(const char* varName, uint32_t* value);
  bool      setNumeric(const char* varName, uint32_t value);
  int       getInt(const char* varName);
  uint16_t  getString(const char* varName, char* text, uint16_t len);
  bool      setString(const char* varName, const char* text);

  NexObject& add(NexObject& newComponent, bool withEvents = false, bool global = false);
  NexObject& add(NexPage& page, uint8_t compID, const char* name, void *value = NULL, bool withEvents = false, bool global = false);
  NexObject& add(uint8_t pageID, uint8_t compID, const char* name, void *value = NULL, bool withEvents = false, bool global = false);
  NexObject& operator[](const uint16_t key);
  NexObject& operator[](float pid_point_cid);  // cid hast do be 001..255

  /**
  * Listen touch event and calling callbacks attached before.
  *
  * Supports push and pop at present.
  *
  * @param nex_listen_list - index to Nextion Components list.
  * @return none.
  *
  * @warning This function must be called repeatedly to response touch events
  *  from Nextion touch panel. Actually, you should place it in your loop function.
  */
  void nexLoop();

  // -------------------------- graphics primitives ---------------------------
  void clearScreen(uint32_t color = 0xFFFFFF);
  void plot(uint32_t x, uint32_t y, uint32_t color = 0);
  void drawLine(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t color = 0);
  void drawRect(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t color = 0);
  void fillRect(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t color = 0);
  void drawRectAbs(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t color = 0);
  void fillRectAbs(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t color = 0);
  void drawCircle(uint32_t x, uint32_t y, uint32_t r, uint32_t color = 0);
  void drawPic(uint32_t x, uint32_t y, uint32_t picID = 0);
  void cropPic(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t picID = 0);
  void drawText(uint32_t x, uint32_t y, uint32_t w, uint32_t h, NexTEXTALIGN_t centerX, NexTEXTALIGN_t centerY,
  uint32_t fontID, uint32_t fontColor, uint32_t backColor, NexBACKGROUND_t backStyle,
  const char* text);
  void drawTextAbs(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, NexTEXTALIGN_t centerX, NexTEXTALIGN_t centerY,
  uint32_t fontID, uint32_t fontColor, uint32_t backColor, NexBACKGROUND_t backStyle,
  const char* text);
  uint16_t color565(uint16_t R, uint16_t G, uint16_t B);

  void enqueueEvent(void(*eventCallback)(void));

protected: /* methods */

private:   /* methods */
  
  bool     recvRetNumber(uint32_t *number, uint32_t timeout = 100);
  uint16_t recvRetString(char *buffer, uint16_t len, uint32_t timeout = 100);
  bool     recvRetCommandFinished(uint32_t timeout = 100);
  void     checkEvent(uint8_t pid, uint8_t cid, int32_t event, void *value);

protected: /* data */
  std::map<uint16_t, NexObject>  __components; /* map to hold all components for standard access */
                                               // not yet implementd
  //std::map<uint16_t, NexTouch> __controls;   /* map to hold subset to watch for touch events   */

  USARTSerial* __serial;              /* serial port for communicatino MCU <-> display  */
                                      // list of up to ten pending events to be serviced each iteration of nexLoop
                                      
private: /* data */                   
  uint32_t __baud = 9600;             /* baudrate     */
  uint16_t __width  = 0;              /* pixel width  */
  uint16_t __height = 0;              /* pixel height */
  uint8_t  __bkCmd = 1;               /* command execution response behaviour */
                                      // 0 .. no response
                                      // 1 .. onSuccess (default
                                      // 2 .. noFail
                                      // 3 .. always
                                      // a queue of up to ten pending events to be serviced each iteration of nexLoop
  void(*__eventQueue[10])(void) = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
  uint8_t __queuedEvents        = 0;// cound of currently pending events


  friend class NexPage;    // grant access to protected functions / fields for NexPage
};
/**
* @}
*/
#endif
