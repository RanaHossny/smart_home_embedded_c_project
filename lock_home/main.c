#include "STD_Types.h"
#include "BIT_MATH.h"
#include"DIO.h"
#include"GIE.h"
#include"TIM1.h"
#include"EXTINT2.h"
#include"uart.h"

#include"Master_TWI.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "LOCK.h"

void main (void){
	GIE_voidDisable();

		DIO_voidInit();
		LCD_voidInit();
		TIM1_voidInit();
		 uart_void_intial();
		KEYPAD_voidInit();
		GIE_voidEnable();
	while(1){
		start_void();
	}






}
