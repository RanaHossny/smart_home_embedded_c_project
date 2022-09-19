/*
 * main.c
 *
 *  Created on: Sep 16, 2022
 *      Author: Ziad
 */


#include "STD_Types.h"
#include "BIT_Math.h"
#include <avr/delay.h>

//MCAL
#include "DIO.h"
#include "ADC.h"
#include "spi.h"


//HAL
#include "LED.h"
#include "LCD.h"
#include "Relay.h"
#include "servo.h"
uint16 u16data;
void display_String(char *s, uint8 u8CmdCpy);


int main(void)
{
	float32 u32data;
	uint8 u8CntrLoc1;
	DIO_voidInit();
	DIO_enuPullWrite(DIO_u8PIN_0,DIO_u8ACTIVATE);
	SPI_voidInit();
	ADC_voidInit();
	ADC_voidEnable();
	TIM1_voidInit();
	LCD_voidInit();

	uint16 u16ReadedValLoc=15;
	uint16 u16ReadedValLocprev=15;

	float32 f32VoltLoc;
	uint8 u8CntrLoc = 0;
	uint8 u8ReceivedDataLoc = 0;

	while(!u8ReceivedDataLoc)
	{
		u8ReceivedDataLoc = SPI_u8DataRecieve_Sync();

	}
	uint8 s3[] = "TEMP: ";

	display_String(s3,0x80);
	//keep blocking untill the door is opened

	uint8 s[] = " Value: ";
	uint8 s1[] = "Volt: ";

	display_String(s1,0xc0);


	while(1)
	{
		//switch to LDR
		ADC_voidPinSwitch(0);
		_delay_ms(100);
		u16ReadedValLocprev = u16ReadedValLoc;
		//read from ADC
		u16ReadedValLoc=ADC_u16ReadSync();
		f32VoltLoc = ADC_f32NumtoVolt(u16ReadedValLoc);
		if(u16ReadedValLoc <= 94)
		{
			LED_enuWriteValue(LED_u8NUM_0,LED_u8ON);
			LED_enuWriteValue(LED_u8NUM_1,LED_u8ON);
			LED_enuWriteValue(LED_u8NUM_2,LED_u8ON);
		}
		else if (u16ReadedValLoc <=512)
		{
			LED_enuWriteValue(LED_u8NUM_0,LED_u8OFF);
			LED_enuWriteValue(LED_u8NUM_1,LED_u8ON);
			LED_enuWriteValue(LED_u8NUM_2,LED_u8ON);
		}
		else if(u16ReadedValLoc <= 931)
		{
			LED_enuWriteValue(LED_u8NUM_0,LED_u8OFF);
			LED_enuWriteValue(LED_u8NUM_1,LED_u8OFF);
			LED_enuWriteValue(LED_u8NUM_2,LED_u8ON);
		}
		else
		{
			LED_enuWriteValue(LED_u8NUM_0,LED_u8OFF);
			LED_enuWriteValue(LED_u8NUM_1,LED_u8OFF);
			LED_enuWriteValue(LED_u8NUM_2,LED_u8OFF);
		}

		LCD_enuWriteCmd(LCD_u8NUM_0,0xC0+6);
		LCD_enuWritenumber(LCD_u8NUM_0,f32VoltLoc);
		if(u16ReadedValLocprev != u16ReadedValLoc)
		{
			display_String(s1,0xc0);
		}
		//switch to the LM35
		ADC_voidPinSwitch(1);

		u16data = ADC_u16ReadSync();
		u32data = ADC_f32NumtoVolt(u16data);
		LCD_enuWriteCmd(LCD_u8NUM_0,0x80+6);
		LCD_enuWritenumber(LCD_u8NUM_0,(uint8)(u32data * 100));
		if((uint8)(u32data * 100) > 28)
		{
			//open air conditioner
			tenu_Relay_enu_on(RELAY_u8NUM_0);
			//close window because we opened air conditioner
			SERVO_voidMove(SERVO_u8NUM_0,SERVO_MOVE_TO_180);
		}
		else
		{
			// close air conditioner
			tenu_Relay_enu_off(RELAY_u8NUM_0);
			//open window
			SERVO_voidMove(SERVO_u8NUM_0,SERVO_MOVE_TO_0);
		}

	}
}
void display_String(char *s, uint8 u8CmdCpy)
{
	uint8 u8CntrLoc = 0;
	LCD_enuWriteCmd(LCD_u8NUM_0,u8CmdCpy);
	while(s[u8CntrLoc] != '\0')
	{
		LCD_enuWriteChar(LCD_u8NUM_0,s[u8CntrLoc]);
		u8CntrLoc++;
	}
}
