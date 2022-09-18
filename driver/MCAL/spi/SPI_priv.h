/********************************************************************************/
/**    File Name: SPI_priv.h                                                         */
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


#ifndef SPI_PRIV_H
#define SPI_PRIV_H

#define SPI_SLAVE_MODE    0
#define SPI_MASTER_MODE   1

#define SPI_CLK_IDLE_LOW    0
#define SPI_CLK_IDLE_HIGH   1


#define SPI_PHASE_SETUP_LEADING      0
#define SPI_PHASE_SETUP_TRILLING     1


#define SPI_DOR_LSB_FIRST   0b0010000
#define SPI_DOR_MSB_FIRST   0b0000000

#define SPI_FREQ_DIV_2      0
#define SPI_FREQ_DIV_4      1
#define SPI_FREQ_DIV_8      2
#define SPI_FREQ_DIV_16     3
#define SPI_FREQ_DIV_32     4
#define SPI_FREQ_DIV_64     5
#define SPI_FREQ_DIV_128    6

#define SPDR    *((volatile uint8 * ) 0x2F)  
#define SPCR    *((volatile uint8 * ) 0x2D)
#define SPSR    *((volatile uint8 * ) 0x2E)

#endif
