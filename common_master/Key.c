/*
 * Key.c
 *
 *  Created on: 10.10.2015
 *      Author: Pascal
 */

#include "Key.h"
#include "event_handler.h"

#if PL_CONFIG_HAS_DEBOUNCE
#include "KeyDebounce.h"
#endif

void Key_Init(void){
	/* Nothing to do here */
}

void Key_Deinit(void){
	/* Nothing to do here */
}

void Key_Scan(void){
#if PL_CONFIG_HAS_DEBOUNCE
	  KEYDBNC_Process();
#else
#if PL_HAS_EVENTS

#if KEY_NBR >= 1
	if(Key1_GetVal() == 0){
		EVNT_SetEvent(KEY1);
	}
#endif
#if KEY_NBR >= 2
	if(Key2_GetVal() == 0){
		EVNT_SetEvent(KEY2);
	}
#endif
#if KEY_NBR >= 3
	if(Key3_GetVal() == 0){
		EVNT_SetEvent(KEY3);
	}
#endif
#if KEY_NBR >= 4
	if(Key4_GetVal() == 0){
		EVNT_SetEvent(KEY4);
	}
#endif
#if KEY_NBR >= 5
	if(Key5_GetVal() == 0){
		EVNT_SetEvent(KEY5);
	}
#endif
#if KEY_NBR >= 6
	if(Key6_GetVal() == 0){
		EVNT_SetEvent(KEY6);
	}
#endif
#if KEY_NBR >= 7
	if(Key7_GetVal() == 0){
		EVNT_SetEvent(KEY7);
	}
#endif
#endif /*PL_HAS_EVENTS*/
#endif /*PL_CONFIG_HAS_DEBOUNCE*/
}

