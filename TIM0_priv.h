
/**  File Name: TIM0_priv.h **/
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

#ifndef TIM0_PRIV_H
#define TIM0_PRIV_H

#define  TIM0_NORMAL_MODE                0 
#define  TIM0_PWM_PHASE_CORRECT_MODE     1
#define  TIM0_CTC_MODE                   2
#define  TIM0_FAST_PWM_MODE              3

#define TIM0_NO_CLK_SRC                  0
#define TIM0_NO_PRESCALLER               1
#define TIM0_PRESCALLER_8                2
#define TIM0_PRESCALLER_64               3
#define TIM0_PRESCALLER_256              4
#define TIM0_PRESCALLER_1024             5
#define TIM0_EXT_CLK_SRC_FALLING_EDGE    6
#define TIM0_EXT_CLK_SRC_RISING_EDGE     7

#define TCNT0     *((volatile uint8 *) 0x52 )
#define OCR0      *((volatile uint8 *) 0x5C )
#define TCCR0     *((volatile uint8 *) 0x53 )
#define TIMSK     *((volatile uint8 *) 0x59 )
#define TIFR      *((volatile uint8 *) 0x58 )

#endif 
