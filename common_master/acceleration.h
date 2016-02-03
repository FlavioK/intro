/*
 * acceleration.h
 *
 *  Created on: 02.02.2016
 *      Author: flavio
 */

#ifndef SOURCES_COMMON_MASTER_ACCELERATION_H_
#define SOURCES_COMMON_MASTER_ACCELERATION_H_

#include "platform.h"
#if PL_HAS_ACCEL

void ACCEL_getXYZmg(int16_t* X,int16_t* Y, int16_t* Z);


uint8_t ACCEL_Enable(void);

uint8_t ACCEL_isEnabled(bool *isEnabled);


void ACCEL_Init(void);

void ACCEL_Deinit(void);

#endif

#endif /* SOURCES_COMMON_MASTER_ACCELERATION_H_ */
