/*
 * event_handler.c
 *
 *  Created on: 08.10.2015
 *      Author: Pascal
 */

#include "platform.h"

#if PL_HAS_EVENTS
#include "CS1.h"

#include "event_handler.h"
typedef uint8_t EVNT_MemUnit;
#define EVNT_MEM_UNIT_NOF_BITS (sizeof(EVNT_MemUnit)*8) /* number of bits in memory unit */

static EVNT_MemUnit EVNT_Events[((EVNT_SIZE - 1) / EVNT_MEM_UNIT_NOF_BITS) + 1]; /* event-flag array */

#define SET_EVENT(event) \
  EVNT_Events[(event)/EVNT_MEM_UNIT_NOF_BITS] |= (1<<(EVNT_MEM_UNIT_NOF_BITS-1))>>((uint8_t)((event)%EVNT_MEM_UNIT_NOF_BITS)) /*!< Set the event */
#define CLR_EVENT(event) \
  EVNT_Events[(event)/EVNT_MEM_UNIT_NOF_BITS] &= ~((1<<(EVNT_MEM_UNIT_NOF_BITS-1))>>((uint8_t)((event)%EVNT_MEM_UNIT_NOF_BITS))) /*!< Clear the event */
#define GET_EVENT(event) \
  (bool)(EVNT_Events[(event)/EVNT_MEM_UNIT_NOF_BITS]&((1<<(EVNT_MEM_UNIT_NOF_BITS-1))>>((uint8_t)((event)%EVNT_MEM_UNIT_NOF_BITS)))) /*!< Return TRUE if event is set */

void EVNT_SetEvent(EVNT_Handle event) {
	CS1_CriticalVariable();
	CS1_EnterCritical();

	SET_EVENT(event);

	CS1_ExitCritical();
}

void EVNT_ClearEvent(EVNT_Handle event) {
	CS1_CriticalVariable();
	CS1_EnterCritical();

	CLR_EVENT(event);

	CS1_ExitCritical();
}

bool EVNT_EventIsSet(EVNT_Handle event) {
	return GET_EVENT(event);
}

bool EVNT_EventIsSetAutoClear(EVNT_Handle event) {
	bool res;

	res = GET_EVENT(event);
	if (res) {
		CS1_CriticalVariable();
		CS1_EnterCritical();

		CLR_EVENT(event); /* automatically clear event */

		CS1_ExitCritical();
	}
	return res;
}

void EVNT_HandleEvent(void (*callback)(EVNT_Handle)) {
	/* Handle the one with the highest priority. Zero is the event with the highest priority. */
	EVNT_Handle event;
	for (event = (EVNT_Handle) 0; event < EVNT_SIZE; event++) { /* does a test on every event */
		if (GET_EVENT(event)) { /* event present? */
			CS1_CriticalVariable();
			CS1_EnterCritical();

			CLR_EVENT(event); /* clear event */

			CS1_ExitCritical();
			break; /* get out of loop */
		}
	}
	if (event != EVNT_SIZE) {
		callback(event);
		/* Note: if the callback sets the event, we will get out of the loop.
		 * We will catch it by the next iteration.
		 */
	}
}

void EVNT_Init(void) {
	uint8_t i;

	i = 0;
	do {
		EVNT_Events[i] = 0; /* initialize data structure */
		i++;
	} while (i < sizeof(EVNT_Events) / sizeof(EVNT_Events[0]));
}

void EVNT_Deinit(void) {
	/* nothing needed */
}

#endif /* PL_HAS_EVENTS */

