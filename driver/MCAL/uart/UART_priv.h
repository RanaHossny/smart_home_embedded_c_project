/********************************************************************************/
/**    File Name: uart.h                                                         */
/**                                                                             */
/**  Description: Implementation of the PWM contain configuration for the module*/
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
/** saraH     Sara Hossny Hassan          ITI.                                 */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 6/09/2022   0.1       saraH     Initial Creation                        */
/********************************************************************************/
#ifndef UART_PRIV_H
#define UART_PRIV_H

#define Synchronous_Operation    ((uint8)  0x40  )
#define Disabled_parity          ((uint8)  0x00  )
#define Even_Parity              ((uint8)  0x20  )
#define Odd_Parity               ((uint8)  0x30  )
#define One_Stop_Bit             ((uint8)  0x00  )
#define Two_Stop_Bit             ((uint8)  0x08  )
#define Char_5Bit                ((uint8)  0x00  )
#define Char_6Bit                ((uint8)  0x02  )
#define Char_7Bit                ((uint8)  0x04  )
#define Char_8Bit                ((uint8)  0x06  )
#define Char_9Bit                ((uint8)  0x16  )/* remeber to take first 4 bits in UCSRC and the the least is  UCSZ2 bit in UCSRB */
#define Transmit_Rising_Edge     ((uint8)  0x00  )
#define Transmit_falling_Edge    ((uint8)  0x01  )
#define UCSRC                   *((volatile uint8 *)  0x40  )
#define UCSRB                   *((volatile uint8 *)  0x2A  )
#define UCSRA                   *((volatile uint8 *)  0x2B  )
#define UDR                     *((volatile uint8 *)  0x2C  )



typedef struct {
	uint8 u8_Parity_Mode;
	uint8 u8_Stop_Bit_Mode;
	uint8 u8_Char_Size;
	uint8 u8_Clock_Polarity;
}ts_uart_cfg ;

extern ts_uart_cfg uart_cfg;
#endif
