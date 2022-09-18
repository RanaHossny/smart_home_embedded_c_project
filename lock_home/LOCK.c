#include<avr/delay.h>
#include "STD_Types.h"
#include "BIT_MATH.h"
#include"DIO.h"
#include "GIE.h"
#include"EXTINT2.h"
#include "TIM2.h"
#include "LCD.h"
#include"servo.h"
#include "KEYPAD.h"
#include "EEPROM.h"
#include"Master_TWI.h"
#include "uart.h"
#include "LOCK.h"
#include "LOCK_confg.h"
#include "LOCK_priv.h"

void Start_servo (void);
void Door_void(void);
void get_password(void);
void password_check(uint8* pass_rom , uint8* entered_password,uint8* result);
uint16 read_distance_ok=0 ,open_door=0;
uint8 password_rom[SIZE_PASSWORD];

void Door_void(void){
EXTINT2_voidSetCallBack(Start_servo);
uint8 size=0,result=0;
sint8  i=0;

uint8 entered_pass[SIZE_PASSWORD];
uint8 welcome_string[8]=" Welcome";
uint8 password_string[15]=" Enter password";
uint8 password_wrong[15]=" password wrong";
uint8 door_open[16]=" Door is opening";
DIO_enuWritePin(DIO_u8PIN_10,DIO_u8LOW );
LCD_enuWriteData(LCD_u8NUM_0,welcome_string, 8);
_delay_ms(500);
LCD_enuWriteCmd(LCD_u8NUM_0,LCD_u8CLEAR);
LCD_enuWriteData(LCD_u8NUM_0,password_string,15);
LCD_enuWriteCmd(LCD_u8NUM_0, 0xC0);
while(i<SIZE_PASSWORD){
KEYPAD_enuGetPressedKey(KEYPAD_u8NUM_0,entered_pass+i ,&size );
if(size!=0){

	LCD_enuWriteChar (LCD_u8NUM_0  ,'*');
 i++;
	}
}
_delay_ms(500);

 password_check(password_rom , entered_pass,& result);


if(result==0){
	LCD_enuWriteCmd(LCD_u8NUM_0,LCD_u8CLEAR);
	LCD_enuWriteData(LCD_u8NUM_0,password_wrong, 15);
	_delay_ms(500);
	LCD_enuWriteCmd(LCD_u8NUM_0,LCD_u8CLEAR);
	Door_void();

}
else{
	open_door=1;
	LCD_enuWriteCmd(LCD_u8NUM_0,LCD_u8CLEAR);
	LCD_enuWriteData(LCD_u8NUM_0,door_open, 16);
	_delay_ms(500);
	Start_servo();
	_delay_ms(500);
	uart_void_write ('1');
}

}


void get_password(void){

uint8 i;
GIE_voidDisable();
TWI_init_master();

for(i=0;i<SIZE_PASSWORD;i++){
	EEPROM_Write(0xA6,i,passward[i]);
	_delay_ms(100);
	password_rom[i]=EEPROM_Read(0xA6,i);
	_delay_ms(100);
	 }
GIE_voidEnable();
}
void password_check(uint8* pass_rom , uint8* entered_password,uint8* result){
	uint8 i;
	for(i=0;i<SIZE_PASSWORD;i++){
		if(pass_rom[i]!=entered_password[i]){
			*result=0;
			break;
		}

			*result=1;
	}

}
 void Start_servo (void){

	SERVO_voidMove(SERVO_u8NUM_0,SERVO_MOVE_TO_0);
			_delay_ms(1000);
			SERVO_voidMove(SERVO_u8NUM_0,SERVO_MOVE_TO_90);
			_delay_ms(1000);
			SERVO_voidMove(SERVO_u8NUM_0,SERVO_MOVE_TO_180);
			_delay_ms(1000);
}
void start_void(void){
	get_password();
	while(read_distance_ok !='1'){
		uart_void_read (&read_distance_ok);
	}
	 Door_void();
}

