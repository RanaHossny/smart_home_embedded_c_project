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
#ifndef TIM1_PRIV_H
#define TIM1_PRIV_H


#define TIM1_NORMAL_MODE     0
#define TIM1_PWM_8_MODE      1//pwm phase correct
#define TIM1_PWM_9_MODE      2
#define TIM1_PWM_10_MODE     3
#define TIM1_CTC_MODE        4
#define TIM1_FPWM_8_MODE     5//fast pwm
#define TIM1_FPWM_9_MODE     6
#define TIM1_FPWM_10_MODE    7
#define TIM1_PWM_PF_ICR_MODE 8
#define TIM1_PWM_PF_OCR_MODE 9
#define TIM1_PWM_P_ICR_MODE  10
#define TIM1_PWM_P_OCR_MODE 11
#define TIM1_CTC_ICR_MODE   12
#define TIM1_FPWM_ICR_MODE  14
#define TIM1_FPWM_OCR_MODE  15

#define TIM1_NO_CLK_SRC                  0
#define TIM1_NO_PRESCALLER               1
#define TIM1_PRESCALLER_8                2
#define TIM1_PRESCALLER_64               3
#define TIM1_PRESCALLER_256              4
#define TIM1_PRESCALLER_1024             5
#define TIM1_EXT_CLK_SRC_FALLING_EDGE    6
#define TIM1_EXT_CLK_SRC_RISING_EDGE     7




#define TCCR1A *((uint8 *)0x4F)// timer counter control register A

#define COM1A1 7 //compare output mode for channel A, OC1A
#define COM1A0 6
#define COM1B1 5//compare output mode for channel B, OC1B
#define COM1B0 4
#define FOC1A 3 //Force Output Compare for Channel A
#define FOC1B 2// Force Output Compare for Channel B
#define WGM11 1
#define WGM10 0


#define TCCR1B *((uint8 *) 0x4E)

#define ICNC1 7 // input capture noise canceler
#define ICES1 6 // input capture edge select
#define WGM13 4 // wave generation mode
#define WGM12 3
#define CS12 2 // clock select for prescaling
#define CS11 1
#define CS10 0

#define TCNT1 *((uint16 *)0x4C) // uint16 to be able to access TCNT1H and TCNT1L at the same time this address is similar to TCNT1L



#define OCR1A *((uint16 *)0x4A)
#define OCR1B *((uint16 *) 0x48)

#define ICR1 *((uint16 *) 0x46)


#define TIMSK *((uint8 *)0x59)  // timer interrupt mask
#define TICIE1 5 //input capture interrupt enable
#define OCIE1A 4 // output compare match interrupt enable
#define OCIE1B 3
#define TOIE1  2  // timer overflow interrupt enable

#define TIFR *((uint8 *) 0x58)//timer interrupt flag
#define ICF1 5 // input capture flag
#define OCF1A 4 // output compare A match flag
#define OCF1B 3
#define TOV1 2






#endif


