/********************************************************************************/
/**    File Name: PWM.c                                                         */
/**                                                                             */
/**  Description: Implementation of the pwm contain configuration for the module*/
/**-----------------------------------------------------------------------------*/
/**  CODING LANGUAGE :  C                                                       */
/**  TARGET          :  Atmega 32                                               */
/**-----------------------------------------------------------------------------*/
/**               C O P Y R I G H T                                             */
/**-----------------------------------------------------------------------------*/
/** Copyright (c) 2022 by ITI .       All rights reserved.                      */
/**                                                                             */
/** This software is copyright protected and proprietary                        */
/** to ITI.                                                                     */
/**-----------------------------------------------------------------------------*/
/**               A U T H O R   I D E N T I T Y                                 */
/**-----------------------------------------------------------------------------*/
/** ShortName    Name                      Company                              */
/** --------     ---------------------     -------------------------------------*/
/** Rana    Rana Hossny         ITI.                                       */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 22/08/2022   0.1      Rana     Initial Creation                             */
 
/********************************************************************************/
#include <avr/delay.h>
#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO.h"
#include "TIM0.h"
#include "PWM.h"
#include "PWM _CFG.h"
#include "PWM_PRIV.h"

float32 f32time_on_ms ,f32time_off_ms ,f32total_time_ms;
uint32  u32time_on_ms ,u32time_off_ms ;
void pwm_init_void()
{
	f32total_time_ms= (1/FREQUENCY_HZ)*1000;
	f32time_on_ms=f32total_time_ms *(DUTY_CYCLE);
	u32time_on_ms= ((uint32)f32time_on_ms);
	f32time_off_ms= f32total_time_ms-f32time_on_ms;
	u32time_off_ms=((uint32)f32time_off_ms);

	
	
 }
void pwm_start_void(){

}


void pwm_stop_void(){
	DIO_enuWritePin(OUTPUT_PIN , DIO_u8LOW);
	
}
