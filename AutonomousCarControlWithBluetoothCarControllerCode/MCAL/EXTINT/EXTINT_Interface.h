/*
 * EXT_Interface.h
 *
 *  Created on: Sep 18, 2024
 *      Author: ahmed
 */

#ifndef MCAL_EXTINT_EXTINT_INTERFACE_H_
#define MCAL_EXTINT_EXTINT_INTERFACE_H_

/******************************************
  INCLUDES
*******************************************/

#include "STD_TYPES.h"

#include  "BIT_MATH.h"

/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/

#define EXT0_ID (u8)(0)
#define EXT1_ID (u8)(1)
#define EXT2_ID (u8)(2)

#define FALLING_EDGE 0
#define RISING_EDGE  1

/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS Prototypes
*******************************************/

void EXTINT_voidInitDir(void);

//FOR Example:  EXTINT_voidInit(EXT0_ID,FALLING_EDGE)
void EXTINT_voidInit(u8 copy_u8ExtNum,u8 copy_u8ControlSens) ;


void EXTINT_voidSetCallBack(  void (*ptr_ext)(void) ,u8 copy_u8ExtNum );


#endif /* MCAL_EXTINT_EXTINT_INTERFACE_H_ */
