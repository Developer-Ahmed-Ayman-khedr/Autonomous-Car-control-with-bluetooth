/*
 * TMR2_Interface.h
 *
 *  Created on: Sep 26, 2024
 *      Author: ahmed
 */

#ifndef MCAL_TMR2_TIMER2_INTERFACE_H_
#define MCAL_TMR2_TIMER2_INTERFACE_H_

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

void TIMER2_VoidInit(void);
void TIMER2_VoidStop(void);
void TIMER2_VoidStart(void);
void TIMER2_VoidSetPreload(u8 copy_u8PRELOAD );
u8 TIMER2_VoidVal(void );


void TIMER2_VoidSetPWMCompareMatch(u8 copy_u8Val );

void TIMER2_voidSetCallBack(  void (*ptr_timer)(void) );


#endif /* MCAL_TMR0_TIMER0_INTERFACE_H_ */
