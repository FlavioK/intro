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
#if PL_HAS_TRIGGER
#include "Trigger.h"
#endif

void TMR_OnInterrupt(void) {
#if PL_HAS_TRIGGER
		TRG_IncTick();
#endif
}

void TMR_Init(void) {
	TI1_Enable();
}

void TMR_Deinit(void) {
	TI1_Disable();
}

#endif /*PL_HAS_TIMER*/
