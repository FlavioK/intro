/*
 * Key.c
 *
 *  Created on: 10.10.2015
 *      Author: Pascal
 */

#include "Key.h"
#include "event_handler.h"

void Key_Init(void){
	/* Nothing to do here */
}

void Key_Deinit(void){
	/* Nothing to do here */
}

void Key_Scan(void){
#if PL_HAS_EVENTS

#if KEY_NBR >= 1
	if(Key1_GetVal() == 1){
		EVNT_SetEvent(KEY1);
	}
#endif
#if KEY_NBR >= 2
	if(Key1_GetVal() == 1){
		EVNT_SetEvent(KEY2);
	}
#endif
#if KEY_NBR >= 3
	if(Key1_GetVal() == 1){
		EVNT_SetEvent(KEY3);
	}
#endif
#if KEY_NBR >= 4
	if(Key1_GetVal() == 1){
		EVNT_SetEvent(KEY4);
	}
#endif
#if KEY_NBR >= 5
	if(Key1_GetVal() == 1){
		EVNT_SetEvent(KEY5);
	}
#endif
#if KEY_NBR >= 6
	if(Key1_GetVal() == 1){
		EVNT_SetEvent(KEY6);
	}
#endif
#if KEY_NBR >= 7
	if(Key1_GetVal() == 1){
		EVNT_SetEvent(KEY7);
	}
#endif
#endif
}

