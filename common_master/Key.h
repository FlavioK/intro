/*
 * Key.h
 *
 *  Created on: 10.10.2015
 *      Author: Pascal
 */

#ifndef SOURCES_COMMON_MASTER_KEY_H_
#define SOURCES_COMMON_MASTER_KEY_H_

#include "platform.h"

#if KEY_NBR	>= 1
#include "Key1.h"
#endif

#if KEY_NBR >= 2
#include "Key2.h"
#endif

#if KEY_NBR >= 3
#include "Key3.h"
#endif

#if KEY_NBR >= 4
#include "Key4.h"
#endif

#if KEY_NBR >= 5
#include "Key5.h"
#endif

#if KEY_NBR >= 6
#include "Key6.h"
#endif

#if KEY_NBR >= 7
#include "Key7.h"
#endif


void Key_Init(void);
void Key_Deinit(void);
void Key_Scan(void);

#endif /* SOURCES_COMMON_MASTER_KEY_H_ */
