/********************************************/
/* Description : Standard lib for new types */
/* Author      : Ahmed abo elnour           */
/* Date        : 14/8/2022                  */
/* Version     : 0.1V                       */
/********************************************/
 /* Gaurd */
#ifndef  STD_TYPES_H 
#define  STD_TYPES_H

typedef     unsigned       char   uint8    ;
typedef     unsigned short int    uint16   ;
typedef     unsigned long  int    uint32   ;
typedef     signed         char   sint8    ;
typedef     signed   short int    sint16   ;
typedef     signed   long  int    sint32   ;
typedef                    float  float32  ;
typedef                    double float64  ;
typedef              long  double float128 ;


typedef enum {
	E_OK ,
	E_NOK,
	E_NOK_PARAM_OUT_OF_RANGE,
	E_NOK_PARAM_NULL_POINTER ,
	E_NOK_CONFIG_PARM_ERROR
}tenuErrorStatus;
typedef enum {
	E_OK_WRITE_DONE,
	E_NOK_BUS_CONTENTION,
	E_NOK_COLLISION
}tenuErrorSpiStatus;

#define NULL_PTR   ((void * )0)
typedef void (*tpfu32) (uint32) ;
typedef void (*pf) (void) ;
typedef void (*tvpf) (pf) ;
typedef uint16 (*tu16pf) (void) ;
typedef void (*tpfu8) (uint8) ;
typedef void (*tpfF32)(float32);

#endif 



