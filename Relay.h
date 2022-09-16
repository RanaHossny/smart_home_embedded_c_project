/********************************************************************************/
/**    File Name: RELAY.h                                                         */
/**                                                                             */
/**  Description: Implementation of the RELAY contain configuration for the module*/
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
/** SaraH     Sara Hossny         ITI.                                       */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 22/08/2022   0.1      SaraH     Initial Creation                             */
 
/********************************************************************************/
#ifndef RELAY_H
#define RELAY_H
#define  RELAY_PRESSED    ((uint8) 1)
#define  RELAY_NOT_PRESSED    ((uint8) 0)
#include "RELAY_cfg.h"
tenuErrorStatus tenu_Relay_enu_on (uint8 u8RelayNumCpy );
tenuErrorStatus tenu_Relay_enu_off (uint8 u8RelayNumCpy );
#endif























