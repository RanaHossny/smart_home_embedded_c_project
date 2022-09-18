#ifndef TIM2_H
#define TIM2_H

void TIM2_voidInit(void);
void TIM2_voidSetPreloadValue (uint8 u8PreloadValueCpy);
void TIM2_voidSetOutputCompareValue (uint8 u8LoadValueCpy);
void TIM2_voidEnableOVFIntterrupt(void);
void TIM2_voidDisableOVFIntterrupt(void);
void TIM2_voidEnableCTCIntterrupt(void);
void TIM2_voidDisableCTCIntterrupt(void);
void TIM2_voidSetOvfCallback(pf pfOvfCallbackCpy);
void TIM2_voidSetCtcCallback(pf pfCtcCallbackCpy);
void TIM2_voidDelay_ms(uint32 u32DalayTimeCpy);
void TIM2_voidDelay_Init(void);
uint16 TIM2_u16GetCntrValue(void );
void TIM2_voidsetCntrValue(void );
void TIM2_voidSet_TimerCounter(void);
uint32 TIM2_u32get_TimerCounter(void);
uint8 TIM2__u8_get_detect_up(void);
void TIM2_void_set_up(void);
void TIM2_void_reset_up(void);
#endif
