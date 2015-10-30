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
#if PL_HAS_BUZZER
#include "Buzzer.h"
#endif
#if PL_HAS_RTOS
#include "RTOS.h"
#endif


void APP_KeyEvntHandler(EVNT_Handle event){
	switch(event){
#if PL_CONFIG_HAS_DEBOUNCE
#if KEY_NBR >= 1
    case EVNT_SW1_PRESSED:
#if !PL_AUTO_CLEAR_EVENT
    	EVNT_ClearEvent(EVNT_SW1_PRESSED);
#endif
#if PL_HAS_BUZZER
		BUZ_Beep(440,1000);
#endif
#if PL_HAS_SNAKE
  EVNT_SetEvent(EVNT_SNAKE_UP);
#endif
      break;
    case EVNT_SW1_LPRESSED:
#if !PL_AUTO_CLEAR_EVENT
    	EVNT_ClearEvent(EVNT_SW1_LPRESSED);
#endif
#if PL_HAS_BUZZER
		BUZ_Beep(600,1000);
#endif
      break;
    case EVNT_SW1_RELEASED:
#if !PL_AUTO_CLEAR_EVENT
    	EVNT_ClearEvent(EVNT_SW1_RELEASED);
#endif
      break;
#endif /*KeyNbr 1*/

#if KEY_NBR >= 2
    case EVNT_SW2_PRESSED:
#if !PL_AUTO_CLEAR_EVENT
    	EVNT_ClearEvent(EVNT_SW2_PRESSED);
#endif
#if PL_HAS_SNAKE
  EVNT_SetEvent(EVNT_SNAKE_RIGHT);
#endif
      break;
    case EVNT_SW2_LPRESSED:
#if !PL_AUTO_CLEAR_EVENT
    	EVNT_ClearEvent(EVNT_SW2_LPRESSED);
#endif
      break;
    case EVNT_SW2_RELEASED:
#if !PL_AUTO_CLEAR_EVENT
    	EVNT_ClearEvent(EVNT_SW2_RELEASED);
#endif
      break;
#endif /*Key NMBR 2*/

  #if KEY_NBR >= 3
   case EVNT_SW3_PRESSED:
#if !PL_AUTO_CLEAR_EVENT
    	EVNT_ClearEvent(EVNT_SW3_PRESSED);
#endif
#if PL_HAS_SNAKE
  EVNT_SetEvent(EVNT_SNAKE_DOWN);
#endif
      break;
   case EVNT_SW3_LPRESSED:
#if !PL_AUTO_CLEAR_EVENT
    	EVNT_ClearEvent(EVNT_SW3_LPRESSED);
#endif
      break;
   case EVNT_SW3_RELEASED:
#if !PL_AUTO_CLEAR_EVENT
    	EVNT_ClearEvent(EVNT_SW3_RELEASED);
#endif
      break;
  #endif/*Key NMBR 3*/

  #if KEY_NBR >= 4
    case EVNT_SW4_PRESSED:
#if !PL_AUTO_CLEAR_EVENT
    	EVNT_ClearEvent(EVNT_SW4_PRESSED);
#endif
#if PL_HAS_SNAKE
  EVNT_SetEvent(EVNT_SNAKE_LEFT);
#endif
      break;
    case EVNT_SW4_LPRESSED:
#if !PL_AUTO_CLEAR_EVENT
    	EVNT_ClearEvent(EVNT_SW4_LPRESSED);
#endif
      break;
    case EVNT_SW4_RELEASED:
#if !PL_AUTO_CLEAR_EVENT
    	EVNT_ClearEvent(EVNT_SW4_RELEASED);
#endif
      break;
  #endif /*Key NMBR 4*/

  #if KEY_NBR >= 5
    case EVNT_SW5_PRESSED:
#if !PL_AUTO_CLEAR_EVENT
    	EVNT_ClearEvent(EVNT_SW5_PRESSED);
#endif
      break;
    case EVNT_SW5_LPRESSED:
#if !PL_AUTO_CLEAR_EVENT
    	EVNT_ClearEvent(EVNT_SW5_LPRESSED);
#endif
      break;
    case EVNT_SW5_RELEASED:
#if !PL_AUTO_CLEAR_EVENT
    	EVNT_ClearEvent(EVNT_SW5_RELEASED);
#endif
      break;
  #endif /*Key NMBR 5*/

  #if KEY_NBR >= 6
    case EVNT_SW6_PRESSED:
#if !PL_AUTO_CLEAR_EVENT
    	EVNT_ClearEvent(EVNT_SW6_PRESSED);
#endif
      break;
    case EVNT_SW6_LPRESSED:
#if !PL_AUTO_CLEAR_EVENT
    	EVNT_ClearEvent(EVNT_SW6_LPRESSED);
#endif
      break;
    case EVNT_SW6_RELEASED:
#if !PL_AUTO_CLEAR_EVENT
    	EVNT_ClearEvent(EVNT_SW6_RELEASED);
#endif
      break;
  #endif /*Key NMBR 6*/

  #if KEY_NBR >= 7
    case EVNT_SW7_PRESSED:
#if !PL_AUTO_CLEAR_EVENT
    	EVNT_ClearEvent(EVNT_SW7_PRESSED);
#endif
#if PL_HAS_SNAKE
  EVNT_SetEvent(EVNT_SNAKE_START_PAUSE);
#endif
     break;

    case EVNT_SW7_LPRESSED:
#if !PL_AUTO_CLEAR_EVENT
    	EVNT_ClearEvent(EVNT_SW7_LPRESSED);
#endif
      break;

    case EVNT_SW7_RELEASED:
#if !PL_AUTO_CLEAR_EVENT
    	EVNT_ClearEvent(EVNT_SW7_RELEASED);
#endif
      break;
  #endif /*Key NMBR 7*/

#else
#if KEY_NBR >= 1
	case KEY1:
#if PL_HAS_SHELL
		CLS1_SendStr("KEY1 is pressed\r\n",CLS1_GetStdio()->stdOut);
#endif /*PL_HAS_SHELL*/
#if PL_HAS_BUZZER
		BUZ_Beep(440,1000);
#endif /*PL_HAS_BUZZER*/
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
#endif /*PL_CONFIG_HAS_KEYS*/
	default:
		break;
	}
}



void APP_event_handler(EVNT_Handle event) {
	switch (event) {
	case EVNT_STARTUP:
#if !PL_AUTO_CLEAR_EVENT
    	EVNT_ClearEvent(EVNT_STARTUP);
#endif
#if PL_HAS_LED
#if LED_NBR>=1
		LED1_Off();
#endif /*LED_NBR >=1*/
#if LED_NBR>=2
		LED2_Off();
#endif /*LED_NBR >=1*/
#if LED_NBR>=3
		LED3_Off();
#endif /*LED_NBR >=1*/
#endif /*PL_HAS_LED*/
		break;

	default:
#if PL_HAS_KEY
      APP_KeyEvntHandler(event);
#endif
	  break;
	}
}

void APP_run(void) {

	PL_Init();
	EVNT_SetEvent(EVNT_STARTUP);
	LED_StartHeartBeat();

	for (;;) {
#if PL_HAS_RTOS
		RTOS_Run();
#endif
#if PL_HAS_EVENTS && !PL_HAS_RTOS
		EVNT_HandleEvent(APP_event_handler);
#endif

#if PL_HAS_KEY
		Key_Scan();
#endif
	}

	PL_Deinit();

}

