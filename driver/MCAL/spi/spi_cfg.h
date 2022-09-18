
/********************************************************************************/
/**    File Name: spi_cfg.h                                                         */
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


#ifndef SPI_CFG_H
#define SPI_CFG_H


#define SPI_MODE             SPI_MASTER_MODE
#define SPI_CLK_IDLE_STATE   SPI_CLK_IDLE_HIGH
#define SPI_PHASE_MODE       SPI_PHASE_SETUP_LEADING
#define SPI_DOR_STATE        SPI_DOR_LSB_FIRST

#if  SPI_MODE == SPI_MASTER_MODE	
#define SPI_GEN_CLK     SPI_FREQ_DIV_16
#endif 
#endif
