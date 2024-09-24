/*
 * EXTINT_Private.h
 *
 *  Created on: Sep 18, 2024
 *      Author: ahmed
 */

#ifndef MCAL_EXTINT_EXTINT_PRIVATE_H_
#define MCAL_EXTINT_EXTINT_PRIVATE_H_

/******************************************
  INCLUDES
*******************************************/


/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/

/****************************************************
 ***************************************************/
#define EXTINT_DIS_EN   0
#define EXTINT_EN       1

/****************************************************
 ***************************************************/

#define MCUCR_REG  *((volatile u8 *)0x55)
#define MCUCR_ISC00 0
#define MCUCR_ISC01 1
#define MCUCR_ISC10 2
#define MCUCR_ISC11 3

/****************************************************
 ***************************************************/

#define MCUCSR_REG *((volatile u8 *)0x54)
#define MCUCSR_ISC2 6

/****************************************************
 ***************************************************/

#define GICR_REG   *((volatile u8 *)0x5B)
#define GICR_INT1 7
#define GICR_INT0 6
#define GICR_INT2 5

/****************************************************
 ***************************************************/
#define GIFR_REG   *((volatile u8 *)0x5A)
#define GIFR_INTF1 7
#define GIFR_INTF0 6
#define GIFR_INTF2 5

/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS Prototypes
*******************************************/

#endif /* MCAL_EXTINT_EXTINT_PRIVATE_H_ */
