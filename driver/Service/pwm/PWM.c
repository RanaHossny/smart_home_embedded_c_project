/********************************************************************************/
/**    File Name: pwm.h                                                         */
/**                                                                             */
/**  Description: Implementation of the PWM contain configuration for the module*/
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
/** saraH     Sara Hossny Hassan          ITI.                                 */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 6/09/2022   0.1       saraH     Initial Creation                        */
/********************************************************************************/
#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO.h"
#include "TIM0.h"
#include "TIM2.h"
#include "pwm.h"
#include "pwm_cfg.h"
#include "pwm_priv.h"
pf pf_delay_intial[NUM_OF_TIMERS]={TIM0_voidInit,TIM2_voidInit};
tpfu32 pfu32_ms_delay[NUM_OF_TIMERS]={TIM0_voidDelayMs,TIM2_voidDelayMs};
uint32 u32_time_on_ms;
uint32 u32_time_off_ms;
tenuErrorStatus Pwm_tenu_Intial (uint8 u8_num_of_pwm_cpy){
	tenuErrorStatus tes_check_error_loc =E_OK;
	if (u8_num_of_pwm_cpy<U8_MAX_NUM_OF_PWM){
		pf_delay_intial[pwm_cfg[u8_num_of_pwm_cpy].u8_timer_num_loc]();
	}
	else{
		tes_check_error_loc =E_NOK_PARAM_OUT_OF_RANGE;
	}
	return tes_check_error_loc;
}
tenuErrorStatus Pwm_tenu_Set_freq_duty (uint8 u8_num_of_pwm_cpy ){
	tenuErrorStatus tes_check_error_loc =E_OK;
	if (u8_num_of_pwm_cpy<U8_MAX_NUM_OF_PWM){
	float32 f32_total_time_loc =1/(pwm_cfg[u8_num_of_pwm_cpy].f32_freq_loc);
	float32 f32_time_on_loc=f32_total_time_loc*pwm_cfg[u8_num_of_pwm_cpy].f32_duty_loc;
	float32 f32_time_off_loc=f32_total_time_loc-f32_time_on_loc;
	u32_time_on_ms=(uint32)(f32_time_on_loc*1000);
	u32_time_off_ms=(uint32)(f32_time_off_loc*1000);
	}
	else{
		tes_check_error_loc =E_NOK_PARAM_OUT_OF_RANGE;
	}
	return tes_check_error_loc;
}
void Pwm_Void_Start(uint8 u8_num_of_pwm_cpy){
	DIO_enuWritePin(pwm_cfg[u8_num_of_pwm_cpy].u8_outpin_num_loc , DIO_u8HIGH);
	pfu32_ms_delay[pwm_cfg[u8_num_of_pwm_cpy].u8_timer_num_loc](u32_time_on_ms);
	DIO_enuWritePin(pwm_cfg[u8_num_of_pwm_cpy].u8_outpin_num_loc , DIO_u8LOW);
	pfu32_ms_delay[pwm_cfg[u8_num_of_pwm_cpy].u8_timer_num_loc](u32_time_off_ms);
}
void Pwm_Void_End(uint8 u8_num_of_pwm_cpy){
	DIO_enuWritePin(pwm_cfg[u8_num_of_pwm_cpy].u8_outpin_num_loc , DIO_u8LOW);
	
}
