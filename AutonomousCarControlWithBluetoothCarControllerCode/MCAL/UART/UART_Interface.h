/*
 * UART_Interface.h
 *
 *  Created on: Oct 8, 2024
 *      Author: ahmed
 */

#ifndef MCAL_UART_UART_INTERFAC_H_
#define MCAL_UART_UART_INTERFAC_H_

/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/
typedef enum
{
	UART_NO_ERROR ,
	UART_TIME_OUT_ERROR,
	UART_NULL_ERROR
}UART_ERROR;

/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS Prototypes
*******************************************/
void UART_VoidInit(void);
UART_ERROR UART_VoidSendChar(u8 Copy_U8_Data);
void UART_VoidSendString(u8* PO_U8_Data);

UART_ERROR UART_U8ReceiveChar(u8 *copy_p8_Data);
void UART_VoidReceiveString(u8* PO_U8_Data);

#endif /* MCAL_UART_UART_INTERFACE_H_ */
