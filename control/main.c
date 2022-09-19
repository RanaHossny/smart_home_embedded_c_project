/*
 * main.c
 *
 *  Created on: Aug 23, 2022
 *      Author: Rana Hossny
 */

#include <avr/io.h>
#include <avr/delay.h>
#include"STD_Types.h"
#include"BIT_Math.h"
#include"DIO.h"
#include "spi.h"
#include"GIE.h"
#include "EXTINT0.h"
#include "TIM0.h"
#include "LCD.h"
#include "ultrasonic.h"
#include "uart.h"



void main(void){
	uint16 read=0;
	GIE_voidDisable();
	EXTINT0_voidDisable();
	DIO_voidInit();
	SPI_voidInit();
	LCD_voidInit();
	EXTINT0_voidInit();
	ultrasonic_void_intial();
	uart_void_intial();
	TIM0_voidInit();
	GIE_voidEnable();

	while(1){
		ultrasonic_void_Start();
		_delay_ms(100);
		LCD_enuWritenumber(LCD_u8NUM_0 ,ultrasonic_f32_get_distance());
		_delay_ms(1000);
		LCD_enuWriteCmd (LCD_u8NUM_0 , LCD_u8CLEAR);
		_delay_ms(1000) ;
		if(ultrasonic_f32_get_distance()<200){
		uart_void_write ('1');
		_delay_ms(1000) ;
		while(read !='1'){
			uart_void_read (&read);

		}
		DIO_enuWritePin(DIO_u8PIN_28,DIO_u8HIGH);
		SPI_u8DataTransfer_Sync('a');
		}
	}
}

