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


#include "STD_Types.h"
#include "BIT_Math.h"

#include "TIM1.h"
#include "TIM1_cfg.h"
#include "TIM1_priv.h"

pf TIM1_pfCtcACallback ;
pf TIM1_pfCtcBCallback ;
pf TIM1_pfOvfCallback ;
pf TIM1_pfICUCallBack;



void TIM1_voidInit(void)
{
#if   TIM1_MODE == TIM0_NORMAL_MODE
	CLR_BIT(TCCR1A , WGM10);
	CLR_BIT(TCCR1A , WGM11);
	CLR_BIT(TCCR1B , WGM12);
	CLR_BIT(TCCR1B , WGM13);

#elif TIM1_MODE == TIM1_PWM_8_MODE
	SET_BIT(TCCR1A , WGM10);
	CLR_BIT(TCCR1A , WGM11);
	CLR_BIT(TCCR1B , WGM12);
	CLR_BIT(TCCR1B , WGM13);
#elif TIM1_MODE == TIM1_PWM_9_MODE
	CLR_BIT(TCCR1A , WGM10);
	SET_BIT(TCCR1A , WGM11);
	CLR_BIT(TCCR1B , WGM12);
	CLR_BIT(TCCR1B , WGM13);
#elif TIM1_MODE == TIM1_PWM_10_MODE
	SET_BIT(TCCR1A , WGM10);
	SET_BIT(TCCR1A , WGM11);
	CLR_BIT(TCCR1B , WGM12);
	CLR_BIT(TCCR1B , WGM13);
#elif TIM1_MODE == TIM1_CTC_MODE
	CLR_BIT(TCCR1A , WGM10);
	CLR_BIT(TCCR1A , WGM11);
	SET_BIT(TCCR1B , WGM12);
	CLR_BIT(TCCR1B , WGM13);
#elif TIM1_MODE == TIM1_FPWM_8_MODE
	SET_BIT(TCCR1A , WGM10);
	CLR_BIT(TCCR1A , WGM11);
	SET_BIT(TCCR1B , WGM12);
	CLR_BIT(TCCR1B , WGM13);
#elif TIM1_MODE == TIM1_FPWM_9_MODE
	CLR_BIT(TCCR1A , WGM10);
	SET_BIT(TCCR1A , WGM11);
	SET_BIT(TCCR1B , WGM12);
	CLR_BIT(TCCR1B , WGM13);
#elif TIM1_MODE == TIM1_FPWM_10_MODE
	SET_BIT(TCCR1A , WGM10);
	SET_BIT(TCCR1A , WGM11);
	SET_BIT(TCCR1B , WGM12);
	CLR_BIT(TCCR1B , WGM13);
#elif TIM1_MODE == TIM1_PWM_PF_ICR_MODE
	CLR_BIT(TCCR1A , WGM10);
	CLR_BIT(TCCR1A , WGM11);
	CLR_BIT(TCCR1B , WGM12);
	SET_BIT(TCCR1B , WGM13);
#elif TIM1_MODE == PWM_PF_OCR_MODE
	SET_BIT(TCCR1A , WGM10);
	CLR_BIT(TCCR1A , WGM11);
	CLR_BIT(TCCR1B , WGM12);
	SET_BIT(TCCR1B , WGM13);
#elif TIM1_MODE == TIM1_PWM_P_ICR_MODE
	CLR_BIT(TCCR1A , WGM10);
	SET_BIT(TCCR1A , WGM11);
	CLR_BIT(TCCR1B , WGM12);
	SET_BIT(TCCR1B , WGM13);
#elif TIM1_MODE == TIM1_PWM_P_OCR_MODE
	SET_BIT(TCCR1A , WGM10);
	SET_BIT(TCCR1A , WGM11);
	CLR_BIT(TCCR1B , WGM12);
	SET_BIT(TCCR1B , WGM13);
#elif TIM1_MODE == TIM1_CTC_ICR_MODE
	CLR_BIT(TCCR1A , WGM10);
	CLR_BIT(TCCR1A , WGM11);
	SET_BIT(TCCR1B , WGM12);
	SET_BIT(TCCR1B , WGM13);


#elif TIM1_MODE == TIM1_FPWM_ICR_MODE
	CLR_BIT(TCCR1A , WGM10);
	SET_BIT(TCCR1A , WGM11);
	SET_BIT(TCCR1B , WGM12);
	SET_BIT(TCCR1B , WGM13);
	ICR1 = 2499; // setting top to be 2499
	//non inverting mode :
	SET_BIT(TCCR1A,COM1A1); // for OC1A
	SET_BIT(TCCR1A,COM1B1);// for OC2A
#elif TIM1_MODE == TIM1_FPWM_OCR_MODE
	SET_BIT(TCCR1A , WGM10);
	SET_BIT(TCCR1A , WGM11);
	SET_BIT(TCCR1B , WGM12);
	SET_BIT(TCCR1B , WGM13);
#endif

	TCCR1B &= (0xF8);/* clear reg 0b1111 1000 */
	TCCR1B |=((0x07)& TIM1_PRESCALLER) ; /* write in reg to set prescaler*/

	TCNT1 = 0;
	OCR1A = 0;
	OCR1B  = 0;
	/*Disable input capture interrupt*/
	CLR_BIT(TIMSK,TICIE1);

	/*disable output compare match interrupt*/
	CLR_BIT(TIMSK,OCIE1A);
	CLR_BIT(TIMSK,OCIE1B);

	/*disable ovf interupt*/
	CLR_BIT(TIMSK,TOIE1);

//	set Compare output mode
}
void TIM1_voidSetPreloadValue (uint16 u8PreloadValueCpy)
{
	TCNT1 = u8PreloadValueCpy;
}
void TIM1_voidSetOutputCompareAValue (uint16 u8LoadValueCpy)
{
	OCR1A = u8LoadValueCpy;
}

void TIM1_voidSetOutputCompareBValue (uint16 u8LoadValueCpy)
{
	OCR1B = u8LoadValueCpy;
}



void TIM1_voidEnableOVFIntterrupt(void)
{
	SET_BIT(TIMSK , TOIE1) ;
}

void TIM1_voidDisableOVFIntterrupt(void)
{
	CLR_BIT(TIMSK , TOIE1) ;
}
void TIM1_voidEnableCTCAIntterrupt(void)
{
	SET_BIT(TIMSK , OCIE1A) ;
}
void TIM1_voidDisableCTCAIntterrupt(void)
{

	CLR_BIT(TIMSK , OCIE1A) ;
}
void TIM1_voidEnableCTCBIntterrupt(void)
{
	SET_BIT(TIMSK , OCIE1B) ;
}
void TIM1_voidDisableCTCBIntterrupt(void)
{

	CLR_BIT(TIMSK , OCIE1B) ;
}

void TIM1_voidEnableICUIntterrupt(void)
{
	SET_BIT(TIMSK , TICIE1) ;
}
void TIM1_voidDisableICUIntterrupt(void)
{

	CLR_BIT(TIMSK , TICIE1) ;
}




void TIM1_voidSetOvfCallback(pf pfOvfCallbackCpy)
{
	TIM1_pfOvfCallback = pfOvfCallbackCpy ;
}
void TIM1_voidSetCtcACallback(pf pfCtcCallbackCpy)
{
	TIM1_pfCtcACallback = pfCtcCallbackCpy;
}

void TIM1_voidSetCtcBCallback(pf pfCtcCallbackCpy)
{
	TIM1_pfCtcBCallback = pfCtcCallbackCpy;
}


void TIM1_voidSetICUCallback(pf pfCtcCallbackCpy)
{
	TIM1_pfICUCallBack = pfCtcCallbackCpy;
}

uint16 TIM1_u16GetCntrValue(void )
{
	return (uint16)TCNT1;
}
/*OVF ISR*/
void __vector_9 (void) __attribute__((signal ,used));
void __vector_9 (void)
{
	TIM1_pfOvfCallback();
}
/*CTC A ISR*/
void __vector_7(void) __attribute__((signal ,used));
void __vector_7 (void)
{
	TIM1_pfCtcACallback();
}

/*CTC B ISR*/
void __vector_8(void) __attribute__((signal ,used));
void __vector_8 (void)
{
	TIM1_pfCtcBCallback();
}
void __vector_6(void) __attribute__((signal ,used));
void __vector_6 (void)
{
	TIM1_pfICUCallBack();
}



void TIM1_voidPWMAGenerate(float32 f32DutyCycleCpy)
{
//	TCNT1 = 0;
	// if ocr was 0 therefore duty = 0, if OCR was 128 therefore duty cycle is 50%
	OCR1A = ((float32)(f32DutyCycleCpy)/100)* ICR1 ;

	// pwm non inverted mode
	//it means that if ocr =60% MAX then duty cycle = 60%


}
