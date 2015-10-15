/*
 * LED_heartbeat_application.c
 *
 *  Created on: 10.10.2015
 *      Author: Pascal
 */
#include "application.h"
#include "platform.h"
#include "WAIT1.h"

#if PL_HAS_LED
#include "LED.h"
#endif
#if PL_HAS_EVENTS
#include "event_handler.h"
#endif
#if PL_HAS_KEY
#include "Key.h"
#endif
#if PL_HAS_SHELL
#include "CLS1.h"
#endif

void APP_event_handler(EVNT_Handle event) {
	switch (event) {
#if PL_HAS_LED
#if LED_NBR>=1
	case EVNT_STARTUP:
		LED1_On();
		break;
#endif /*LED_NBR >=1*/
#if LED_NBR>=2
	case EVNT_LEDHEARTBEAT:
		LED2_Neg();
		break;
#endif /*LED_NBR >=2*/
#endif /*PL_HAS_LED*/

#if PL_HAS_KEY
#if KEY_NBR >= 1
	case KEY1:
#if PL_HAS_SHELL
		CLS1_SendStr("KEY1 is pressed\r\n",CLS1_GetStdio()->stdOut);
#endif /*PL_HAS_SHELL*/
		break;
#endif /*KEY_NBR >=1*/
#if KEY_NBR >= 2
	case KEY2:
#if PL_HAS_SHELL
		CLS1_SendStr("KEY2 is pressed\r\n",CLS1_GetStdio()->stdOut);
#endif /*PL_HAS_SHELL*/
		break;
#endif /*KEY_NBR >=2*/
#if KEY_NBR >= 3
	case KEY3:
#if PL_HAS_SHELL
		CLS1_SendStr("KEY3 is pressed\r\n",CLS1_GetStdio()->stdOut);
#endif /*PL_HAS_SHELL*/
		break;
#endif /*KEY_NBR >=3*/
#if KEY_NBR >= 4
	case KEY4:
#if PL_HAS_SHELL
		CLS1_SendStr("KEY4 is pressed\r\n",CLS1_GetStdio()->stdOut);
#endif /*PL_HAS_SHELL*/
		break;
#endif /*KEY_NBR >=4*/
#if KEY_NBR >= 5
	case KEY5:
#if PL_HAS_SHELL
		CLS1_SendStr("KEY5 is pressed\r\n",CLS1_GetStdio()->stdOut);
#endif /*PL_HAS_SHELL*/
		break;
#endif /*KEY_NBR >=5*/
#if KEY_NBR >= 6
	case KEY6:
#if PL_HAS_SHELL
		CLS1_SendStr("KEY6 is pressed\r\n",CLS1_GetStdio()->stdOut);
#endif /*PL_HAS_SHELL*/
		break;
#endif /*KEY_NBR >=6*/
#if KEY_NBR >= 7
	case KEY7:
#if PL_HAS_SHELL
		CLS1_SendStr("KEY7 is pressed\r\n",CLS1_GetStdio()->stdOut);
#endif /*PL_HAS_SHELL*/
		break;
#endif /*KEY_NBR >=7*/
#endif /*PL_HAS_KEY*/
	default:
		break;
	}
}

void APP_run(void) {

	PL_Init();
	EVNT_SetEvent(EVNT_STARTUP);

	for (;;) {
#if PL_HAS_EVENTS
		EVNT_HandleEvent(APP_event_handler);
#endif

#if PL_HAS_KEY
		Key_Scan();
#endif
	}

	PL_Deinit();

}

