/*
 * LED.c
 *
 *  Created on: 26.09.2015
 *      Author: Pascal
 */
#include "LED.h"

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
