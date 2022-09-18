/********************************************************************************/
/**    File Name: SPI.h                                                         */
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

#ifndef SPI_H
#define SPI_H
typedef enum {
	WRITE_DONE ,
	WRITE_PENDING,
	WRITE_NOT_DONE , 
    IDLE	
}tenuWriteState;

#define SPI_INT_ENABLE    1
#define SPI_INT_DISABLE   0


void SPI_voidInit(void);

void SPI_u8DataTransfer_Sync(uint8 u8DataCpy);

void SPI_voidWriteData_Async(uint8 u8DataCpy);

tenuWriteState SPI_enuWriteStatus_Async(void);

uint8 SPI_u8ReadData_Async(void);

void SPI_voidSetInterruptState(uint8 u8IntStateCpy);

#endif
