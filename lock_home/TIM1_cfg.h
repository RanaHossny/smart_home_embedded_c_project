/**************************************************************************************/
/**    File Name: LCD.h                                                                   */
/**                                                                                       */
/**  Description: Implementation of the TIM1 contain configuration for the module*/
/**---------------------------------------------------------------------------------------*/
/**  CODING LANGUAGE :  C                                                                 */
/**  TARGET          :  Atmega 32                                                 */
/**---------------------------------------------------------------------------------------*/
/**               C O P Y R I G H T                                                       */
/**---------------------------------------------------------------------------------------*/
/** Copyright (c) 2022 by ITI .       All rights reserved.                                */
/**                                                                                       */
/** This software is copyright protected and proprietary                                  */
/** to ITI.                                                                               */
/**---------------------------------------------------------------------------------------*/
/**               A U T H O R   I D E N T I T Y                                           */
/**---------------------------------------------------------------------------------------*/
/** ShortName    Name                      Company                                        */
/** --------     ---------------------     -----------------------------------------------*/
/** ziad     Ziad Fahmy             ITI.                                          */
/**---------------------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                                         */
/**---------------------------------------------------------------------------------------*/
/** Date        Version   Author         Description                                      */
/** ----------  --------  ------      ----------------------------------------------------*/
/** 9/15/2022      0.1 ziad Initial Creation                                 */
/******************************************************************************************/
#ifndef TIM1_CFG_H
#define TIM1_CFG_H


/* modes available :*/
/*
TIM1_NORMAL_MODE
TIM1_PWM_8_MODE      //pwm phase correct
TIM1_PWM_9_MODE
TIM1_PWM_10_MODE
TIM1_CTC_MODE
TIM1_FPWM_8_MODE     //fast pwm
TIM1_FPWM_9_MODE
TIM1_FPWM_10_MODE
TIM1_PWM_PF_ICR_MODE
TIM1_PWM_PF_OCR_MODE
TIM1_PWM_P_ICR_MODE
TIM1_PWM_P_OCR_MODE
TIM1_CTC_ICR_MODE
TIM1_FPWM_ICR_MODE
TIM1_FPWM_OCR_MODE
*/

#define TIM1_MODE        TIM1_FPWM_ICR_MODE
#define TIM1_PRESCALLER  TIM1_PRESCALLER_64

#endif

