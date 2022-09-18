#ifndef PWM_H
#define PWM_H
#include "pwm_cfg.h"

tenuErrorStatus Pwm_tenu_Intial (uint8 u8_num_of_pwm_cpy);
tenuErrorStatus Pwm_tenu_Set_freq_duty (uint8 u8_num_of_pwm_cpy );
void Pwm_Void_Start(uint8 u8_num_of_pwm_cpy);
void Pwm_Void_End(uint8 u8_num_of_pwm_cpy);
#endif
