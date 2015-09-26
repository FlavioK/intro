/*
 * platform.c
 *
 *  Created on: 25.09.2015
 *      Author: Flavio
 */

#include "platform.h"
#include "platform_local.h"
#if LED_EN == 1
	#include "LED.h"
#endif

void PL_Init(void){
	#if LED_EN == 1
		LED_Init();
	#endif
}

void PL_Deinit(void){
	#if LED_EN == 1
		LED_Deinit();
	#endif
}
