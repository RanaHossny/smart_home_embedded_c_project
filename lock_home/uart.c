#include "STD_Types.h"
#include "BIT_Math.h"
#include "uart.h"

void uart_void_intial(){
	UCSRC=(Synchronous_Operation)|(uart_cfg.u8_Parity_Mode)|(uart_cfg.u8_Stop_Bit_Mode)|(uart_cfg.u8_Char_Size)|(uart_cfg.u8_Clock_Polarity);
	if(uart_cfg.u8_Char_Size==Char_9Bit){
		SET_BIT(UCSRB , 2);
	}
	SET_BIT(UCSRB , 4);/*enable receive */
	SET_BIT(UCSRB , 3);/*enable transmission */
}
void uart_void_read (uint16* u16_value_cpy){
	/*SET_BIT(UCSRB , 7); enable  RX Complete Interrupt*/
	while (!(GET_BIT(UCSRA , 7)));
	*u16_value_cpy= UDR;
	if ((uart_cfg.u8_Char_Size)==Char_9Bit){
	*u16_value_cpy|= ((UCSRB>>1)&0x01)<<8;
	}
}
void uart_void_write (uint16 u16_value_cpy){
	/*SET_BIT(UCSRB , 5); enable Data Register Empty Interrupt*/
	while ((UCSRA&0x20)!=0x20);
	UDR= (u16_value_cpy)&0xff ;
	if (uart_cfg.u8_Char_Size==Char_9Bit){
	UCSRB&=0xFE;
	UCSRB|=((u16_value_cpy>>8)&0x01);
	}
	
	
}
