/********************************************************************************/
/**    File Name: TIM2.c                                                         */
/**                                                                             */
/**  Description: Implementation of the TIM2 contain configuration for the module*/
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

#include "STD_Types.h"
#include "BIT_Math.h"
#include "TIM2.h"
#include "TIM2_cfg.h"
#include "TIM2_priv.h"
#include "EXTINT0.h"
void TIM2_Void_dummy(void);
pf TIM2_pfCtcCallback =TIM2_Void_dummy;
pf TIM2_pfOvfCallback =TIM2_Void_dummy ;

uint8 u8_used ,factor;
uint32 counter, delay;
void TIM2_voidInit(void)
{
#if   TIM2_MODE == TIM2_NORMAL_MODE
	CLR_BIT(TCCR2 , 6);
	CLR_BIT(TCCR2 , 3);
#elif TIM2_MODE == TIM2_PWM_PHASE_CORRECT_MODE
	SET_BIT(TCCR2 , 6);
	CLR_BIT(TCCR2 , 3);
#elif TIM2_MODE == TIM2_CTC_MODE
	CLR_BIT(TCCR2 , 6);
	SET_BIT(TCCR2 , 3);
#else
	SET_BIT(TCCR2 , 6);
	SET_BIT(TCCR2 , 3);
#endif

	TCCR2 &= (0xF8);/* clear reg 0b1111 1000 */
	TCCR2 |=((0x07)& TIM2_PRESCALLER) ; /* write in reg */
	TCNT2 = 0;
	OCR2  = 0;
	/* Disable Interrupt  OVF CM */
	CLR_BIT(TIMSK , 5) ;
	CLR_BIT(TIMSK , 6) ;
	/* Clear IF flags OVF CM */
	SET_BIT(TIFR  , 6) ;
	SET_BIT(TIFR  , 7) ;

}
void TIM2_voidSetPreloadValue (uint8 u8PreloadValueCpy)
{
	TCNT2 = u8PreloadValueCpy;
}
void TIM2_voidSetOutputCompareValue (uint8 u8LoadValueCpy)
{
	OCR2 = u8LoadValueCpy;
}
void TIM2_voidEnableOVFIntterrupt(void)
{
	SET_BIT(TIMSK , 6) ;
}
void TIM2_voidDisableOVFIntterrupt(void)
{
	CLR_BIT(TIMSK , 6) ;
}
void TIM2_voidEnableCTCIntterrupt(void)
{
	SET_BIT(TIMSK , 5) ;
}
void TIM2_voidDisableCTCIntterrupt(void)
{

	CLR_BIT(TIMSK , 5) ;
}
void TIM2_voidSetOvfCallback(pf pfOvfCallbackCpy)
{
	TIM2_pfOvfCallback = pfOvfCallbackCpy ;

}
void TIM2_voidSetCtcCallback(pf pfCtcCallbackCpy)
{
	TIM2_pfCtcCallback = pfCtcCallbackCpy;

}
/*OVF ISR*/
void __vector_5 (void) __attribute__((signal ,used));
void __vector_5 (void)
{

	if(u8_used){
		counter++;
	}

	TIM2_pfOvfCallback();

}
/*CM ISR*/
void __vector_4 (void) __attribute__((signal ,used));
void __vector_4 (void)
{
		TIM2_pfCtcCallback();

}
void TIM2_voidDelay_ms(uint32 u32DalayTimeCpy)
{
u8_used=1;
TIM2_voidEnableOVFIntterrupt();
while(counter!=3);
while(TIM2_u16GetCntrValue()!=232);
counter=0;
TIM2_voidDisableOVFIntterrupt();


}
void TIM2_voidDelay_Init(void){
#if   TIM2_MODE == TIM2_NORMAL_MODE
	CLR_BIT(TCCR2 , 6);
	CLR_BIT(TCCR2 , 3);
#elif TIM2_MODE == TIM2_PWM_PHASE_CORRECT_MODE
	SET_BIT(TCCR2 , 6);
	CLR_BIT(TCCR2 , 3);
#elif TIM2_MODE == TIM2_CTC_MODE
	CLR_BIT(TCCR2 , 6);
	SET_BIT(TCCR2 , 3);
#else
	SET_BIT(TCCR2 , 6);
	SET_BIT(TCCR2 , 3);
#endif
	TCCR2 &= (0xF8);/* clear reg 0b1111 1000 */
	TCCR2  |=((0x07)& TIM2_PRESCALLER_8 ) ; /* write in reg */
	TCNT2=0x00;
	OCR2  = 0;

}


uint16 TIM2_u16GetCntrValue(void ){
	return TCNT2 ;
}
void TIM2_voidsetCntrValue(void ){
	 TCNT2=0 ;
}

void TIM2_Void_dummy(void){}
