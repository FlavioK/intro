/*
 * LED.h
 *
 *  Created on: 26.09.2015
 *      Author: Pascal
 */

#ifndef SOURCES_COMMON_MASTER_LED_H_
#define SOURCES_COMMON_MASTER_LED_H_

#include "Platform.h"
#if LED_NBR >= 1
#include "LED1.h"
#endif

#if LED_NBR >= 2
#include "LED2.h"
#endif

#if LED_NBR >=3
#include "LED3.h"
#endif

void LED_Init(void);
void LED_Deinit(void);
void LED_StartHeartBeat(void);
#endif /* SOURCES_COMMON_MASTER_LED_H_ */
