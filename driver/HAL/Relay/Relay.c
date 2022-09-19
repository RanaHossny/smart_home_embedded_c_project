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
#include "STD_Types.h"

#include "DIO.h"
#include "RELAY.h"
#include "RELAY_cfg.h"
#include "RELAY_priv.h"


tenuErrorStatus tenu_Relay_enu_on (uint8 u8RelayNumCpy ){
	tenuErrorStatus error = E_OK;
		if(u8RelayNumCpy<RELAY_MAX_NUM){
			DIO_enuWritePin(u8RelayPinMapping.u8RelayNumCpy , DIO_u8HIGH);
		}
		else{
			error=E_NOK_PARAM_OUT_OF_RANGE;
		}		
		
}
tenuErrorStatus tenu_Relay_enu_off (uint8 u8RelayNumCpy ){
	tenuErrorStatus error = E_OK;
		if(u8RelayNumCpy<RELAY_MAX_NUM){
			DIO_enuWritePin(u8RelayPinMapping.u8RelayNumCpy , DIO_u8LOW);
		}
		else{
			error=E_NOK_PARAM_OUT_OF_RANGE;
		}		
		
}

