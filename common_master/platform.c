/*
 * platform.c
 *
 *  Created on: 25.09.2015
 *      Author: Flavio
 */

#include "platform.h"
#include "platform_local.h"
#if PL_HAS_LED
#include "LED.h"
#endif
#if PL_HAS_EVENTS
#include "event_handler.h"
#endif
#if PL_HAS_TIMER
#include "timer.h"
#endif

void PL_Init(void) {
#if PL_HAS_LED
	LED_Init();
#endif
#if PL_HAS_EVENTS
	EVNT_Init();
#endif
#if PL_HAS_TIMER
	TMR_Init();
#endif

}

void PL_Deinit(void) {
#if PL_HAS_LED
	LED_Deinit();
#endif
#if PL_HAS_EVENTS
	EVNT_Deinit();
#endif
#if PL_HAS_TIMER
	TMR_Deinit();
#endif
}
