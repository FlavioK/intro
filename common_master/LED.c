/*
 * LED.c
 *
 *  Created on: 26.09.2015
 *      Author: Pascal
 */
#include "LED.h"
#if PL_HAS_TRIGGER
#include "Trigger.h"
#endif

#if PL_HAS_TRIGGER
static void LED_HeartBeat(void *p){
	(void)p;
#if LED_NBR >=2
	LED2_Neg();
#endif
	TRG_SetTrigger(TRG_HEARTBEAT,200/TRG_TICKS_MS,LED_HeartBeat,NULL);
}
#endif

void LED_Init(void){
	#if  LED_NBR >= 1
		LED1_Init();
	#endif

	#if  LED_NBR >= 2
		LED2_Init();
	#endif

	#if  LED_NBR >= 3
		LED3_Init();
	#endif
#if PL_HAS_TRIGGER
			LED_HeartBeat(NULL);
#endif

}

void LED_Deinit(void){
	#if  LED_NBR >= 1
		LED1_Deinit();
	#endif

	#if  LED_NBR >= 2
		LED2_Deinit();
	#endif

	#if  LED_NBR >= 3
		LED3_Deinit();
	#endif
}
