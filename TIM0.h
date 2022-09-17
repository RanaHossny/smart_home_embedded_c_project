#ifndef TIM0_H
#define TIM0_H

void TIM0_voidInit(void);
void TIM0_voidSetPreloadValue (uint8 u8PreloadValueCpy);
void TIM0_voidSetOutputCompareValue (uint8 u8LoadValueCpy);
void TIM0_voidEnableOVFIntterrupt(void);
void TIM0_voidDisableOVFIntterrupt(void);
void TIM0_voidEnableCTCIntterrupt(void);
void TIM0_voidDisableCTCIntterrupt(void);
void TIM0_voidSetOvfCallback(pf pfOvfCallbackCpy);
void TIM0_voidSetCtcCallback(pf pfCtcCallbackCpy);
void TIM0_voidDelay_ms(uint32 u32DalayTimeCpy);
void TIM0_voidDelay_Init(void);
void TIM0_voidDelay_us(uint32 u32DalayTimeCpy);
uint16 TIM0_u16GetCntrValue(void );
void TIM0_voidSet_TimerCounter(void);
uint32 TIM0_u32get_TimerCounter(void);
uint8 TIM0__u8_get_detect_up(void);
void TIM0_void_set_up(void);
void TIM0_void_reset_up(void);
#endif
