/*
 * platform.c
 *
 *  Created on: 25.09.2015
 *      Author: Flavio
 */

#include "platform.h"
#include "platform_local.h"
#if PL_HAS_LED
#include "LED.h"
#endif
#if PL_HAS_KEY
#include "Key.h"
#endif
#if PL_HAS_EVENTS
#include "event_handler.h"
#endif
#if PL_HAS_TIMER
#include "timer.h"
#endif
#if PL_HAS_TRIGGER
#include "Trigger.h"
#endif
#if PL_HAS_BUZZER
#include "Buzzer.h"
#endif
#if PL_CONFIG_HAS_DEBOUNCE
#include "Debounce.h"
#include "KeyDebounce.h"
#endif
#if PL_HAS_RTOS
#include "RTOS.h"
#endif
#if PL_HAS_SNAKE
  #include "Snake.h"
#endif
#if PL_HAS_SHELL
#include "Shell.h"
#endif
#if PL_HAS_MENU
#include "Menu.h"
#endif
#if PL_HAS_SHELLQUEUE
#include "ShellQueue.h"
#endif


void PL_Init(void) {
#if PL_HAS_LED
	LED_Init();
#endif
#if PL_HAS_KEY
	Key_Init();
#endif
#if PL_HAS_EVENTS
	EVNT_Init();
#endif
#if PL_HAS_TIMER
	TMR_Init();
#endif
#if PL_HAS_TRIGGER
	TRG_Init();
#endif
#if PL_HAS_BUZZER
	BUZ_Init();
#endif
#if PL_CONFIG_HAS_DEBOUNCE
	DBNC_Init();
	KEYDBNC_Init();
#endif
#if PL_HAS_SNAKE
	SNAKE_Init();
#endif
#if PL_HAS_SHELL
	SHELL_Init();
#endif
#if PL_HAS_SHELLQUEUE
	SQUEUE_Init();
#endif
#if PL_HAS_RTOS
	RTOS_Init();
#endif
#if PL_HAS_MENU
	MENU_Init();
#endif
}

void PL_Deinit(void) {
#if PL_HAS_LED
	LED_Deinit();
#endif
#if PL_HAS_KEY
	Key_Deinit();
#endif
#if PL_HAS_EVENTS
	EVNT_Deinit();
#endif
#if PL_HAS_TIMER
	TMR_Deinit();
#endif
#if PL_HAS_TRIGGER
	TRG_Deinit();
#endif
#if PL_HAS_BUZZER
	BUZ_Deinit();
#endif
#if PL_CONFIG_HAS_DEBOUNCE
	DBNC_Deinit();
	KEYDBNC_Deinit();
#endif
#if PL_HAS_SNAKE
	SNAKE_Deinit();
#endif
#if PL_HAS_SHELL
	SHELL_Deinit();
#endif
#if PL_HAS_SHELLQUEUE
	SQUEUE_Deinit();
#endif
#if PL_HAS_RTOS
	RTOS_Deinit();
#endif
#if PL_HAS_MENU
	MENU_Deinit();
#endif
}
