/*
 * TMR0_Interface.h
 *
 *  Created on: Sep 18, 2024
 *      Author: ahmed
 */

#ifndef MCAL_TMR0_TIMER0_INTERFACE_H_
#define MCAL_TMR0_TIMER0_INTERFACE_H_

/******************************************
  INCLUDES
*******************************************/


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

void TIMER0_VoidInit(void);
void TIMER0_VoidStop(void);
void TIMER0_VoidStart(void);
void TIMER0_VoidSetPreload(u8 copy_u8PRELOAD );
u8 TIMER0_VoidVal(void );


void TIMER0_VoidSetPWMCompareMatch(u8 copy_u8Val );

void TIMER_voidSetCallBack(  void (*ptr_timer)(void) );


void WDT_VoidEnabel(void );
void WDT_VoidDisEnabel(void );
void WDT_VoidSleep(u8 sleep_time );

#endif /* MCAL_TMR0_TIMER0_INTERFACE_H_ */
