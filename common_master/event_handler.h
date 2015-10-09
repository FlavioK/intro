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
	EVNT_NR1,
	EVNT_NR2,
	EVNT_SIZE,
} EVNT_Handle;

void EVNT_SetEvent(EVNT_Handle event);
void EVNT_ClearEvent(EVNT_Handle evnt);
void EVNT_EventIsSet(EVNT_Handle event);
void EVNT_EventIsSetAutoClear(EVNT_Handle evnt);
void EVNT_HandleEvent(void (*callback)(EVNT_Handle));
void EVNT_Init(void);
void EVNT_Deinit(void);

#endif /*PL_CONFIG_HAS_EVENTS */

#endif /* SOURCES_COMMON_MASTER_EVENT_HANDLER_H_ */
