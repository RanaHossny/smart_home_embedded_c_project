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
#ifndef TIM1_H
#define TIM1_H



void TIM1_voidInit(void);

void TIM1_voidSetPreloadValue(uint16 u8PreloadValueCpy);

void TIM1_voidSetOutputCompareAValue(uint16 u8LoadValueCpy);

void TIM1_voidSetOutputCompareBValue(uint16 u8LoadValueCpy);

void TIM1_voidEnableOVFIntterrupt(void);

void TIM1_voidDisableOVFIntterrupt(void);

void TIM1_voidEnableCTCAIntterrupt(void);

void TIM1_voidEnableCTCBIntterrupt(void);

void TIM1_voidDisableCTCAIntterrupt(void);

void TIM1_voidDisableCTCBIntterrupt(void);

void TIM1_voidSetOvfCallback(pf pfOvfCallbackCpy);

void TIM1_voidSetCtcACallback(pf pfCtcCallbackCpy);

void TIM1_voidSetICUCallback(pf pfCtcCallbackCpy);


void TIM1_voidSetCtcBCallback(pf pfCtcCallbackCpy);

void TIM1_voidDelayMs(uint16 u16DalayTimeCpy);

uint16 TIM1_u16GetCntrValue(void);

void TIM1_voidEnableICUIntterrupt(void);

void TIM1_voidDisableICUIntterrupt(void);

void TIM1_voidPWMAGenerate(float32 f32DutyCycleCpy);

#endif


