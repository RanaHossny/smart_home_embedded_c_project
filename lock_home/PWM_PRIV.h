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
#ifndef PWM_PRIV_H
#define PWM_PRIV_H
#include "pwm_cfg.h"
#define TIMER_0        ((uint8) 0x00  )
#define TIMER_2        ((uint8) 0x01  )
#define NUM_OF_TIMERS ((uint8) 0x02 )
typedef struct {
	uint8 u8_timer_num_loc ;
	uint8 u8_outpin_num_loc ;
	float32 f32_freq_loc ;
	float32 f32_duty_loc ;
	
}st_pwm_cfg ;
extern st_pwm_cfg  pwm_cfg[U8_MAX_NUM_OF_PWM];
#endif
