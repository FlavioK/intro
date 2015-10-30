/*
 * RTOS.c
 *
 *  Created on: 28.10.2015
 *      Author: Flavio
 */
#include "platform.h"
#if PL_HAS_RTOS
#include "RTOS.h"
#include "FRTOS1.h"
#include "event_handler.h"
#include "Key.h"
#include "Application.h"

static void AppTask(void* param) {
	EVNT_SetEvent(EVNT_STARTUP); /* set startup event */
	for (;;) {
#if PL_HAS_EVENTS
#if !PL_AUTO_CLEAR_EVENT
		EVNT_HandleEvent(APP_event_handler,FALSE);
#else
		EVNT_HandleEvent(APP_event_handler,TRUE);
#endif
#endif
#if PL_HAS_KEY && KEY_NBR>0 && !PL_CONFIG_HAS_KBI
		Key_Scan(); /* scan keys */
#endif
		FRTOS1_vTaskDelay(10/portTICK_RATE_MS);
	}
}

void RTOS_Run(void) {
	FRTOS1_vTaskStartScheduler(); /* does usually not return! */
}

void RTOS_Init(void) {
	if (FRTOS1_xTaskCreate(AppTask, (signed portCHAR *)"App",
			configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL) != pdPASS) {
		for (;;) {
		} /* error */
	}
}

void RTOS_Deinit(void) {
	/*Nothing to do here*/

}
#endif
