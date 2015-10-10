/**
 * \file
 * \brief Timer driver
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This module implements the driver for all our timers.
  */

#include "Platform.h"
#if PL_HAS_TIMER
#include "Timer.h"
#include "TI1.h"
#include "event_handler.h"

void TMR_OnInterrupt(void) {
#define BLINK_PERIOD_MS 1000
	static int counter = 0;

	counter++;
	if(counter == BLINK_PERIOD_MS/TMR_TICK_MS){
		counter = 0;
		EVNT_SetEvent(EVNT_LEDHEARTBEAT);
	}
}

void TMR_Init(void) {
	TI1_Enable();
}

void TMR_Deinit(void) {
	TI1_Disable();
}

#endif /*PL_HAS_TIMER*/
