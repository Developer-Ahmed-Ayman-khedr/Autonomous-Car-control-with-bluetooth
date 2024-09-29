/*
 * ULTRASONIC_Program.c
 *
 *  Created on: Sep 26, 2024
 *      Author: ahmed
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "avr/delay.h"
#include "DIO_Interface.h"

#include "TMR0_Interface.h"
#include "EXTINT_Interface.h"

#include "ULTRASONIC_Config.h"
#include "ULTRASONIC_Interface.h"
#include "ULTRASONIC_Private.h"

/***********************************************************************************/
//UltraSonic using Timer0 and INT0
f32 Ttick = 0.004, TONTime=0; //ms
u32 dis = 0;
u32 OvCounter=0, TimeOn=0;
u8 edge = 0;

void Timer0OvFunc(){
	OvCounter++;
}

void UltrasonicFunc(){
	//rising
	if (edge==RISING_EDGE){

		TIMER0_VoidSetPreload(0);

		TIMER0_VoidStart();

		OvCounter = 0;

		EXTINT_voidInit(EXT0_ID,FALLING_EDGE);

		edge = FALLING_EDGE;

	}
	//falling
	else if (edge==FALLING_EDGE){
		TIMER0_VoidStop();

		TimeOn = TIMER0_VoidVal();

		TONTime = Ttick*(TimeOn+(256*OvCounter));
		dis = 17 * TONTime;

		EXTINT_voidInit(EXT0_ID,RISING_EDGE);

		edge = RISING_EDGE;
	}
}

void ULTRASONIC_voidInit(){
	//TR
	DIO_voidSetPinDirection(TRIGGER_PORT,TRIGGER_PIN,PIN_OUTPUT);

	//ECHO
	DIO_voidSetPinDirection(ECHO_PORT,ECHO_PIN,PIN_INPUT);

	//Timer0
	TIMER0_VoidInit();

	TIMER0_voidSetCallBack(Timer0OvFunc);

	//External Interrupt
	EXTINT_voidInit(EXT0_ID,RISING_EDGE);

	EXTINT_voidSetCallBack(UltrasonicFunc,EXT0_ID);
}

void ULTRASONIC_VoidStart(){
	DIO_voidSetPinValue(TRIGGER_PORT,TRIGGER_PIN,PIN_HIGH);

	_delay_us(11);

	DIO_voidSetPinValue(TRIGGER_PORT,TRIGGER_PIN,PIN_LOW);
}

u32 ULTRASONIC_VoidVal(){

	return dis;
}
