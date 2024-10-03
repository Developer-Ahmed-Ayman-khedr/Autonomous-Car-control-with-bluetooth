/*
 * TMR1_int.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef TMR1_TMR1_INT_H_
#define TMR1_TMR1_INT_H_

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

void TIMER1_voidPwm1Init(void);

void TIMER1_voidPwm1SetTop(u32 copy_u32top);

void TIMER1_voidPwm1SetDutyCycle(u32 copy_u32duty);

void TIMER1_voidPwm1Start(void);

void TIMER1_voidPwm1Stop(void);

#endif /* TMR1_TMR1_INT_H_ */
