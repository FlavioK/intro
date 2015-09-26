/*
 * LED_application.c
 *
 *  Created on: 26.09.2015
 *      Author: Pascal
 */

#include "LED_application.h"
#include "platform.h"

#include "Wait1.h"
#if LED_EN == 1
	#include "LED.h"
#endif

void LED_app_run(void) {

	PL_Init();

	for(;;){
		#if LED_EN == 1
			#if LED_NBR >= 1
				LED1_Neg();
			#endif
			WAIT1_Waitms(200);

			#if LED_NBR >= 2
				LED2_Neg();
			#endif
			WAIT1_Waitms(200);

			#if LED_NBR >= 3
				LED3_Neg();
			#endif
			WAIT1_Waitms(200);

		#endif
	}

	PL_Deinit();

}

