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

#ifndef SPI_H_
#define SPI_H_
void spi_void_intial(void);
uint8 SPI_u8DataTransfer_Sync(uint8 u8DataCpy);
void spi_void_read_Syc(uint8 * u8_value_cpy);
uint8 spi_uint8_read_Asyc(void);
void spi_void_write_Syc(uint8 u8_value_cpy);
void spi_void_enable(void);
void spi_void_disable(void );
void spi_void_InterputEnable(void);
void spi_void_InterputDisable(void );
tenuErrorSpiStatus spi_tenuspi_state(void);
#endif
