/*
 * acceleration.c
 *
 *  Created on: 02.02.2016
 *      Author: flavio
 */

#include "platform.h"
#if PL_HAS_ACCEL
#include "acceleration.h"
#include "MMA1.h"


void ACCEL_getXYZmg(int16_t* X,int16_t* Y, int16_t* Z){
	  int16_t xmg, ymg, zmg;

	  xmg = MMA1_GetXmg();
	  ymg = MMA1_GetYmg();
	  zmg = MMA1_GetZmg();
	  *X = xmg;
	  *Y = ymg;
	  *Z = zmg;
}

uint8_t ACCEL_Enable(void){
	return MMA1_Enable();
}

uint8_t ACCEL_isEnabled(bool *isEnabled){
	return MMA1_isEnabled(isEnabled);

}


void ACCEL_Init(void){
	/*Needs Interupts. Are not enabled if RTOS is not running yet.*/
	/*MMA1_Init() in beginning of RTOS-task.*/
MMA1_Init();
MMA1_Enable();
MMA1_SetFastMode(FALSE);

}

void ACCEL_Deinit(void){
MMA1_Deinit();
}

#endif

