/**
 * \file
 * \brief This is a configuration file for the RNet stack
 * \author (c) 2013 Erich Styger, http://mcuoneclipse.com/
 * \note MIT License (http://opensource.org/licenses/mit-license.html)
 *
 * Here the stack can be configured using macros.
 */

#ifndef __RNET_APP_CONFIG__
#define __RNET_APP_CONFIG__

/*! type ID's for application messages */
typedef enum {
  RAPP_MSG_TYPE_STDIN = 0x40,
  RAPP_MSG_TYPE_STDOUT = 0x41,
  RAPP_MSG_TYPE_STDERR = 0x42,
  RAPP_MSG_TYPE_ACCEL = 0x43,
  RAPP_MSG_TYPE_DATA = 0x44,
  RAPP_MSG_TYPE_JOYSTICK_XY = 0x45,
  RAPP_MSG_TYPE_JOYSTICK_BTN = 0x94, /* Joystick button message (data is one byte: 'A', 'B', ... 'F' and 'K') */
} RAPP_MSG_Type;

#endif /* __RNET_APP_CONFIG__ */
