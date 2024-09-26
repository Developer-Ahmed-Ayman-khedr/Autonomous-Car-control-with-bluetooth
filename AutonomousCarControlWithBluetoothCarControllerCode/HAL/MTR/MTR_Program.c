/*
 * MTR_Program.c
 *
 *  Created on: Sep 26, 2024
 *      Author: ahmed
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "avr/delay.h"

#include "DIO_Interface.h"

/***********************************************************************************/
#include "TMR2_Interface.h"

#include "GIE_Interface.h"

/***********************************************************************************/
#include "MTR_Config.h"
#include "MTR_Interface.h"

/***********************************************************************************/


void MTR_voidInit(){

	//Control Pin
	DIO_voidSetPinDirection(CONTROL_PORT,CONTROL_PIN,PIN_OUTPUT);

	//Direction Pins
	DIO_voidSetPinDirection(DIRECTION_PORT1,DIRECTION_PIN1,PIN_OUTPUT);

	DIO_voidSetPinDirection(DIRECTION_PORT2,DIRECTION_PIN2,PIN_OUTPUT);

	DIO_voidSetPinDirection(DIRECTION_PORT3,DIRECTION_PIN3,PIN_OUTPUT);

	DIO_voidSetPinDirection(DIRECTION_PORT4,DIRECTION_PIN4,PIN_OUTPUT);

	//Initialize timer2
	TIMER2_VoidInit();

	//Make sure the car does not move when the car is started
	MTR_voidMovement(MTR_STOP,0);

	//Enable Global interrupt enable
	GIE_Enable();

}

void MTR_voidMovement(u8 state, u8 speed){
	switch(state){

	case MTR_STOP:
		//Control Pin
		TIMER2_VoidStop();

		//Direction Pins
		DIO_voidSetPinValue(DIRECTION_PORT1,DIRECTION_PIN1,PIN_LOW);

		DIO_voidSetPinValue(DIRECTION_PORT2,DIRECTION_PIN2,PIN_LOW);

		DIO_voidSetPinValue(DIRECTION_PORT3,DIRECTION_PIN3,PIN_LOW);

		DIO_voidSetPinValue(DIRECTION_PORT4,DIRECTION_PIN4,PIN_LOW);
		break;

	case MTR_FORWARD:
		//Control Pin
		TIMER2_VoidSetPreload(0);
		TIMER2_VoidSetPWMCompareMatch(speed);
		TIMER2_VoidStart();

		//Direction Pins
		DIO_voidSetPinValue(DIRECTION_PORT1,DIRECTION_PIN1,PIN_HIGH);

		DIO_voidSetPinValue(DIRECTION_PORT2,DIRECTION_PIN2,PIN_LOW);

		DIO_voidSetPinValue(DIRECTION_PORT3,DIRECTION_PIN3,PIN_HIGH);

		DIO_voidSetPinValue(DIRECTION_PORT4,DIRECTION_PIN4,PIN_LOW);
		break;

	case MTR_REVERSE:
		//Control Pin
		TIMER2_VoidSetPreload(0);
		TIMER2_VoidSetPWMCompareMatch(speed);
		TIMER2_VoidStart();

		//Direction Pins
		DIO_voidSetPinValue(DIRECTION_PORT1,DIRECTION_PIN1,PIN_LOW);

		DIO_voidSetPinValue(DIRECTION_PORT2,DIRECTION_PIN2,PIN_HIGH);

		DIO_voidSetPinValue(DIRECTION_PORT3,DIRECTION_PIN3,PIN_LOW);

		DIO_voidSetPinValue(DIRECTION_PORT4,DIRECTION_PIN4,PIN_HIGH);
		break;

	case MTR_RIGHT:
		//Control Pin
		TIMER2_VoidSetPreload(0);
		TIMER2_VoidSetPWMCompareMatch(speed);
		TIMER2_VoidStart();

		//Direction Pins
		DIO_voidSetPinValue(DIRECTION_PORT1,DIRECTION_PIN1,PIN_HIGH);

		DIO_voidSetPinValue(DIRECTION_PORT2,DIRECTION_PIN2,PIN_LOW);

		DIO_voidSetPinValue(DIRECTION_PORT3,DIRECTION_PIN3,PIN_LOW);

		DIO_voidSetPinValue(DIRECTION_PORT4,DIRECTION_PIN4,PIN_LOW);
		break;

	case MTR_LEFT:
		//Control Pin
		TIMER2_VoidSetPreload(0);
		TIMER2_VoidSetPWMCompareMatch(speed);
		TIMER2_VoidStart();

		//Direction Pins
		DIO_voidSetPinValue(DIRECTION_PORT1,DIRECTION_PIN1,PIN_LOW);

		DIO_voidSetPinValue(DIRECTION_PORT2,DIRECTION_PIN2,PIN_LOW);

		DIO_voidSetPinValue(DIRECTION_PORT3,DIRECTION_PIN3,PIN_HIGH);

		DIO_voidSetPinValue(DIRECTION_PORT4,DIRECTION_PIN4,PIN_LOW);
		break;

	default:
		break;
	}
}
