/*
 * event_handler.h
 *
 *  Created on: 08.10.2015
 *      Author: Pascal
 */

#ifndef SOURCES_COMMON_MASTER_EVENT_HANDLER_H_
#define SOURCES_COMMON_MASTER_EVENT_HANDLER_H_

#include "platform.h"

#if PL_HAS_EVENTS

typedef enum{
	EVNT_STARTUP,
#if PL_CONFIG_HAS_DEBOUNCE
#if KEY_NBR >= 1
  EVNT_SW1_PRESSED,
  EVNT_SW1_LPRESSED,
  EVNT_SW1_RELEASED,
#endif
#if KEY_NBR >= 2
  EVNT_SW2_PRESSED,
  EVNT_SW2_LPRESSED,
  EVNT_SW2_RELEASED,
#endif
#if KEY_NBR >= 3
  EVNT_SW3_PRESSED,
  EVNT_SW3_LPRESSED,
  EVNT_SW3_RELEASED,
#endif
#if KEY_NBR >= 4
  EVNT_SW4_PRESSED,
  EVNT_SW4_LPRESSED,
  EVNT_SW4_RELEASED,
#endif
#if KEY_NBR >= 5
  EVNT_SW5_PRESSED,
  EVNT_SW5_LPRESSED,
  EVNT_SW5_RELEASED,
#endif
#if KEY_NBR >= 6
  EVNT_SW6_PRESSED,
  EVNT_SW6_LPRESSED,
  EVNT_SW6_RELEASED,
#endif
#if KEY_NBR >= 7
  EVNT_SW7_PRESSED,
  EVNT_SW7_LPRESSED,
  EVNT_SW7_RELEASED,
#endif
#else /*PL_CONFIG_HAS DEBOUNCE == 0*/
#if PL_HAS_KEY
#if KEY_NBR >= 1
	KEY1,
#endif
#if KEY_NBR >= 2
	KEY2,
#endif
#if KEY_NBR >= 3
	KEY3,
#endif
#if KEY_NBR >= 4
	KEY4,
#endif
#if KEY_NBR >= 5
	KEY5,
#endif
#if KEY_NBR >= 6
	KEY6,
#endif
#if KEY_NBR >= 7
	KEY7,
#endif
#endif /*PL_HAS_KEYS*/
#endif /*PL_CONFIG_HAS_DEBOUNCE*/
	EVNT_SIZE,
} EVNT_Handle;

void EVNT_SetEvent(EVNT_Handle event);
void EVNT_ClearEvent(EVNT_Handle evnt);
bool EVNT_EventIsSet(EVNT_Handle event);
bool EVNT_EventIsSetAutoClear(EVNT_Handle evnt);
void EVNT_HandleEvent(void (*callback)(EVNT_Handle));
void EVNT_Init(void);
void EVNT_Deinit(void);

#endif /*PL_CONFIG_HAS_EVENTS */

#endif /* SOURCES_COMMON_MASTER_EVENT_HANDLER_H_ */
