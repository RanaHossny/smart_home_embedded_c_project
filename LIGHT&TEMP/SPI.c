#include "STD_Types.h"
#include "BIT_Math.h"

#include "SPI.h"
#include "SPI_cfg.h"
#include "SPI_priv.h"


uint8 SPI_u8RxBuffer ; 
uint8 SPI_u8TxState  ;
void SPI_voidInit(void)
{
	SPCR = (1<<6);
	
	
}

//uint8 SPI_u8DataTransfer_Sync(uint8 u8DataCpy)
//{
//	SPDR  =  u8DataCpy ;
//	while (GET_BIT(SPSR , 7) == 0);
	/* write collision check*/
/*return SPDR ;*/
/*}*/
void SPI_u8DataTransfer_Sync(uint8 u8DataCpy)
{
	SPDR  =  u8DataCpy ;

	while(!(SPSR & (1<<7)));
	//DIO_enuWritePin(DIO_u8PIN_0,DIO_u8HIGH);

}
uint8 SPI_u8DataRecieve_Sync(void)
{
	while (GET_BIT(SPSR , 7) == 0);
	/* write collision check*/
	return SPDR ;
}

void SPI_voidWriteData_Async(uint8 u8DataCpy)
{
		SPDR =  u8DataCpy ;
		SPI_u8TxState = 2;
}

//tenuWriteState SPI_enuWriteStatus_Async(void)
//{
//	tenuWriteState enuReturnStateLoc ;
//	if (SPI_u8TxState == 1)
//	{
//		enuReturnStateLoc = WRITE_DONE ;
//		SPI_u8TxState = 0 ;
//	}
//	else if (SPI_u8TxState == 2 )
//	{
//		enuReturnStateLoc = WRITE_PENDING ;
//	}
//	else if (SPI_u8TxState == 3 )
//	{
//		enuReturnStateLoc = WRITE_NOT_DONE ;
//		SPI_u8TxState = 0 ;
//	}
//	else
//	{
//		enuReturnStateLoc = IDLE ;
//	}
//
//	return enuReturnStateLoc ;
//}

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
