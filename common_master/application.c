/*
 * LED_heartbeat_application.c
 *
 *  Created on: 10.10.2015
 *      Author: Pascal
 */
#include "application.h"
#include "platform.h"
#include "WAIT1.h"

#if PL_HAS_LED
#include "LED.h"
#endif
#if PL_HAS_EVENTS
#include "event_handler.h"
#endif
#if PL_HAS_KEY
#include "Key.h"
#endif

void APP_event_handler(EVNT_Handle event) {
	switch (event) {
	case EVNT_STARTUP:
#if LED_NBR>=1
		LED1_Off();
#endif
		break;

	case EVNT_LEDHEARTBEAT:
#if LED_NBR>=2
		//LED2_Neg();
#endif
		break;
#if PL_HAS_KEY
#if KEY_NBR >= 1
	case KEY1:
		LED2_Neg();
		break;
#endif
#endif
	default:
		break;
	}
}

void APP_run(void) {

	PL_Init();
	EVNT_SetEvent(EVNT_STARTUP);

	for (;;) {
#if PL_HAS_EVENTS
		EVNT_HandleEvent(APP_event_handler);
#endif

#if PL_HAS_KEY
		Key_Scan();
#endif
	}

	PL_Deinit();

}

