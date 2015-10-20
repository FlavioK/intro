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
#if PL_HAS_LED && (LED_NBR >= 1)
	EVNT_STARTUP,
#endif

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
#endif

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
