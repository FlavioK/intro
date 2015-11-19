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
#include "event_handler.h"
#if PL_HAS_TRIGGER
#include "Trigger.h"
#endif
#if PL_HAS_MOTOR_TACHO
#include "Tacho.h"
#endif

void TMR_OnInterrupt(void) {
#if PL_HAS_TRIGGER
		TRG_IncTick();
#endif
#if PL_HAS_MOTOR_TACHO
		TACHO_Sample();
#endif
}

void TMR_Init(void) {
	/* nothing needed right now */
}

void TMR_Deinit(void) {
	/* nothing needed right now */
}

#endif /*PL_HAS_TIMER*/
