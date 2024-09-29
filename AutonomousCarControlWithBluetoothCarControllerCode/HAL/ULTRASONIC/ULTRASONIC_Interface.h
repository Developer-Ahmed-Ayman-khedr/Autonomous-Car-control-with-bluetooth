/*
 * ULTRASONIC_Interface.h
 *
 *  Created on: Sep 26, 2024
 *      Author: ahmed
 */

#ifndef HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_
#define HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_

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

void ULTRASONIC_voidInit();

void ULTRASONIC_VoidStart();

u32 ULTRASONIC_VoidVal();

#endif /* HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_ */
