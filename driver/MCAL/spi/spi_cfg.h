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


#ifndef SPI_CFG_H_
#define SPI_CFG_H_


/*  LSB_FIRST      MSB_FIRST */
#define DATA_ORDER   LSB_FIRST
/*  MASTER      SLAVE       */
#define SPI_STATE    MASTER
/* LEADING_RISING  LEADING_FAILING */
#define SPI_CLK_POLARITY  LEADING_FAILING
/* LEADING_SAMPLE   LEADING_SETUP */
#define SPI_CLK_PHASE  LEADING_SETUP
#if SPI_STATE==MASTER
/* FREQ_DIV_2   FREQ_DIV_4  FREQ_DIV_8  FREQ_DIV_16  FREQ_DIV_32  FREQ_DIV_64  FREQ_DIV_128*/
#define SCK_FREQUENCY  FREQ_DIV_16
#endif
#endif
