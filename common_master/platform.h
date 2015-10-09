/*
 * platform.h
 *
 *  Created on: 25.09.2015
 *      Author: Flavio
 */

#ifndef SOURCES_COMMON_MASTER_PLATFORM_H_
#define SOURCES_COMMON_MASTER_PLATFORM_H_

#include "platform_local.h"

#define PL_HAS_EVENTS (1 && PL_LOCAL_HAS_EVENTS)
#define PL_HAS_TIMER (1 && PL_LOCAL_HAS_TIMER)

void PL_Init(void);
void PL_Deinit(void);

#endif /* SOURCES_COMMON_MASTER_PLATFORM_H_ */
