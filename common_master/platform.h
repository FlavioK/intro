/*
 * platform.h
 *
 *  Created on: 25.09.2015
 *      Author: Flavio
 */

#ifndef SOURCES_COMMON_MASTER_PLATFORM_H_
#define SOURCES_COMMON_MASTER_PLATFORM_H_

#include "platform_local.h"
#include "PE_Types.h"

#define PL_HAS_EVENTS (1 && PL_LOCAL_HAS_EVENTS)
#define PL_HAS_TIMER (1 && PL_LOCAL_HAS_TIMER)
#define PL_HAS_LED (1 && PL_LOCAL_HAS_LED)
#define PL_HAS_KEY (1 && PL_LOCAL_HAS_KEY)
#define PL_HAS_SHELL (1 && PL_LOCAL_HAS_SHELL)
#define PL_HAS_BLUETOOTH (1 && PL_LOCAL_HAS_BLUETOOTH)
#define PL_HAS_BUZZER (1 && PL_LOCAL_HAS_BUZZER)
#define PL_HAS_TRIGGER (1 && PL_LOCAL_HAS_TRIGGER)
#define PL_CONFIG_HAS_DEBOUNCE (1 && PL_LOCAL_HAS_DEBOUNCE)
#define PL_HAS_RTOS (1 && PL_LOCAL_HAS_RTOS)
#define PL_HAS_SNAKE (1 && PL_LOCAL_HAS_SNAKE)
#define PL_AUTO_CLEAR_EVENT (1 && PL_LOCAL_AUTO_CLEAR_EVENT)
#define PL_HAS_USB_CDC (1 && PL_LOCAL_HAS_USB_CDC)

void PL_Init(void);
void PL_Deinit(void);

#endif /* SOURCES_COMMON_MASTER_PLATFORM_H_ */
