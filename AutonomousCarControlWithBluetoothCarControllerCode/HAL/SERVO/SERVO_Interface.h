/*
 * SERVO_Interface.h
 *
 *  Created on: Oct 3, 2024
 *      Author: ahmed
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

/******************************************
  INCLUDES
*******************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS Prototypes
*******************************************/
void SERVO_voidInit();

void Servo_voidSetAngle(s8 copy_s8angle);

#endif /* MCAL_UART_UART_INTERFACE_H_ */
