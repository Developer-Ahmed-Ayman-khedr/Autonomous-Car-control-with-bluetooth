/*
 * DIO_INT.h
 *
 *  Created on: Sep 18, 2024
 *      Author: ahmed
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

/******************************************
  INCLUDES
*******************************************/

#include"STD_TYPES.h"

#include"BIT_MATH.h"

//Set Cristal Frequency
#define F_CPU 16000000UL
#include<util/delay.h>

/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/

/*
 * Port ID Macros
 */
#define PORTA_ID     (u8)(0x00)
#define PORTB_ID     (u8)(0x01)
#define PORTC_ID     (u8)(0x02)
#define PORTD_ID     (u8)(0x03)

/*
 * Pin ID Macros
 */
#define PIN0         (u8)(0x00)
#define PIN1         (u8)(0x01)
#define PIN2         (u8)(0x02)
#define PIN3         (u8)(0x03)
#define PIN4         (u8)(0x04)
#define PIN5         (u8)(0x05)
#define PIN6         (u8)(0x06)
#define PIN7         (u8)(0x07)

/*
 * Direction Macros
 */
#define PIN_OUTPUT         (u8)(0x01)
#define PIN_INPUT          (u8)(0x00)

#define PIN_HIGH           (u8)(0x01)
#define PIN_LOW            (u8)(0x00)

#define ALL_PORT_OUTPUT    (u8)(0XFF)
#define ALL_PORT_INPUT     (u8)(0x00)

#define ALL_PORT_HIGH      (u8)(0XFF)
#define ALL_PORT_LOW       (u8)(0x00)

/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS Prototypes
*******************************************/

void    DIO_voidSetPortDirection(u8 copy_u8PortID, u8 copy_u8PortDir);
void    DIO_voidSetPortValue(u8 copy_u8PortID, u8 copy_u8PortVal);

void	DIO_voidSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinDir);
void    DIO_voidSetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinValue);


u8 		DIO_u8GetBitValue(u8 copy_u8PortID, u8 copy_PinID);


void 	DIO_voidToggelPin(u8 copy_u8PortID, u8 copy_u8PinID) ;


#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
