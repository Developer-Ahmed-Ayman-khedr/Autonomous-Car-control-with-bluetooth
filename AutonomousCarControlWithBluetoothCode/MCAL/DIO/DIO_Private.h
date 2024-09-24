/*
 * DIO_Private.h
 *
 *  Created on: Sep 18, 2024
 *      Author: ahmed
 */

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_

/******************************************
  INCLUDES
*******************************************/

#include"STD_TYPES.h"

/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/

/*************** Group A Registers *************/

#define PORTA_REG	*((volatile u8*)0x3B)
#define DDRA_REG	*((volatile u8*)0x3A)
#define PINA_REG	*((volatile u8*)0x39)


/*************** Group B Registers *************/
#define PORTB_REG  *((volatile u8*)0x38)
#define DDRB_REG   *((volatile u8*)0x37)
#define PINB_REG   *((volatile u8*)0x36)


/*************** Group C Registers *************/
#define PORTC_REG  *((volatile u8*)0x35)
#define DDRC_REG   *((volatile u8*)0x34)
#define PINC_REG   *((volatile u8*)0x33)


/*************** Group D Registers ************/
#define PORTD_REG  *((volatile u8*)0x32)
#define DDRD_REG   *((volatile u8*)0x31)
#define PIND_REG   *((volatile u8*)0x30)


/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS Prototypes
*******************************************/

#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
