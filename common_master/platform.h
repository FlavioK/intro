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
#define PL_HAS_BUZZER (1 && PL_LOCAL_HAS_BUZZER)
#define PL_HAS_TRIGGER (1 && PL_LOCAL_HAS_TRIGGER)

void PL_Init(void);
void PL_Deinit(void);

#endif /* SOURCES_COMMON_MASTER_PLATFORM_H_ */
