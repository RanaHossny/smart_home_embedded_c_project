/********************************************************************************/
/**    File Name:  ULTRASONIC.c                                                        */
/**                                                                             */
/**  Description: Implementation of the TIM0 contain configuration for the module*/
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
/** SaraH    Sara Hossny         ITI.                                       */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 22/08/2022   0.1      SaraH     Initial Creation                             */

/********************************************************************************/


#include <avr/delay.h>
#include "STD_Types.h"
#include "DIO.h"
#include "TIM0.h"
#include "EXTINT0.h"
#include "ultrasonic.h"
#include "ultrasonic_cfg.h"
#include "LCD.h"

uint8  up=0,start;
uint8  timerCounter;
float32  result=0;
uint32 Start=0;
uint8 start_flag=0;
void ultrasonic_void_callBack(void);
void ultrasonic_void_intial(void){
	EXTINT0_voidSetCallBack(ultrasonic_void_callBack);
}
void ultrasonic_void_Start(void){
	 EXTINT0_voidEnable();
	DIO_enuWritePin(ULTRASONI_TRIGGER_PIN , DIO_u8LOW);
		 _delay_us(1);
	 DIO_enuWritePin(ULTRASONI_TRIGGER_PIN  , DIO_u8HIGH);
	 start_flag =1;
	 _delay_us(10);
	 DIO_enuWritePin(ULTRASONI_TRIGGER_PIN , DIO_u8LOW);
	 _delay_us(1);
	EXTINT0_voidSetCallBack(ultrasonic_void_callBack);
}
void ultrasonic_void_callBack(void)
{
        if (start_flag) { //accept interrupts only when sonar was started
                if (TIM0__u8_get_detect_up() == 0) { // voltage rise, start time measurement
                	TIM0_voidsetCntrValue();
                    TIM0_voidSet_TimerCounter();
                	    TIM0_void_set_up() ;
                        result=0;
                        TIM0_voidEnableOVFIntterrupt();
                } else {
                        // voltage drop, stop time measurement
                	 result =(TIM0_u16GetCntrValue()+(TIM0_u32get_TimerCounter()*256))*0.00216;
                        TIM0_void_reset_up();
                        start_flag=0;
                        TIM0_voidDisableOVFIntterrupt();
                        EXTINT0_voidDisable();
                }
        }
}

float32 ultrasonic_f32_get_distance(void){
	return result;
}
void ultrasonic_f32_setter_distance(void){
	 result=-1;
}



