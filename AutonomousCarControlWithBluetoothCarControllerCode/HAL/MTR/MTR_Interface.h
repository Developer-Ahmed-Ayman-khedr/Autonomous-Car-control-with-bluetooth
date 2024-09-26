/*
 * MTR_Interface.h
 *
 *  Created on: Sep 26, 2024
 *      Author: ahmed
 */

#ifndef HAL_MTR_MTR_INTERFACE_H_
#define HAL_MTR_MTR_INTERFACE_H_

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
/*
 *Motor movement
 */
#define MTR_STOP	((u8)0)

#define MTR_FORWARD	((u8)1)

#define MTR_REVERSE	((u8)2)

#define MTR_RIGHT	((u8)3)

#define MTR_LEFT	((u8)4)


/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS Prototypes
*******************************************/

void MTR_voidInit();

void MTR_voidMovement(u8 copy_u8state, u8 copy_u8speed);

#endif /* HAL_MTR_MTR_INTERFACE_H_ */
