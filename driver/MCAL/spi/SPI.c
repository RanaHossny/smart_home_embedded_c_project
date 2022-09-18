/********************************************************************************/
/**    File Name: SPI.c                                                         */
/**  Description: Implementation of the TIM0 contain configuration for the module*/
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

#include "DIO.h"
#include "SPI.h"
#include "SPI_cfg.h"
#include "SPI_priv.h"


uint8 SPI_u8RxBuffer ; 
uint8 SPI_u8TxState  ;
void SPI_voidInit(void)
{
	/*Enable SPI */
	SPCR = (1<<6)|(1<<4)|(1<<0);

}


void SPI_u8DataTransfer_Sync(uint8 u8DataCpy)
{
	SPDR  =  u8DataCpy ;

	while(!(SPSR & (1<<7)));
	//DIO_enuWritePin(DIO_u8PIN_0,DIO_u8HIGH);

}

void SPI_voidWriteData_Async(uint8 u8DataCpy)
{
	SPDR =  u8DataCpy ;
	SPI_u8TxState = 2;
}

tenuWriteState SPI_enuWriteStatus_Async(void)
{
	tenuWriteState enuReturnStateLoc ;
	if (SPI_u8TxState == 1)
	{
		enuReturnStateLoc = WRITE_DONE ;
		SPI_u8TxState = 0 ;
	}
	else if (SPI_u8TxState == 2 )
	{
		enuReturnStateLoc = WRITE_PENDING ;
	}
	else if (SPI_u8TxState == 3 )
	{
		enuReturnStateLoc = WRITE_NOT_DONE ;
		SPI_u8TxState = 0 ;
	}
	else
	{
		enuReturnStateLoc = IDLE ;
	}

	return enuReturnStateLoc ;
}

uint8 SPI_u8ReadData_Async(void)
{
	return SPI_u8RxBuffer ;
}

void SPI_voidSetInterruptState(uint8 u8IntStateCpy)
{
	if (u8IntStateCpy == SPI_INT_ENABLE )
	{
		SET_BIT (SPCR , 7 ) ;
	}
	else
	{
		CLR_BIT (SPCR , 7 ) ;
	}
}

void __vector_12 (void) __attribute__ ((signal , used)) ;
void __vector_12 (void)
{   
	if ( GET_BIT(SPSR , 6))
	{
		SPI_u8TxState  = 3 ;
	}
	else 
	{
		SPI_u8TxState  = 1 ;
	}
	SPI_u8RxBuffer = SPDR ;
}
