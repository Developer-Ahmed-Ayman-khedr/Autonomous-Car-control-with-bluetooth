/*
 * main.c
 *
 *  Created on: September 18, 2024
 *      Author: ahmed
 */

/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "DIO_Interface.h"

#include "LCD_Interface.h"

#include "MTR_Interface.h"

#include "SERVO_Interface.h"

#include "ULTRASONIC_Interface.h"

#include "UART_Interface.h"

/*--------------------------------------------------------------------------------------------*/
//LCD Motor custom characters addresses
u8 LCD_MTR_Forward_ADDRESS = (u8)0;

u8 LCD_MTR_Reverce_ADDRESS = (u8)1;

u8 LCD_MTR_Right_ADDRESS = (u8)2;

u8 LCD_MTR_Lift_ADDRESS = (u8)3;
/*--------------------------------------------------------------------------------------------*/

void LCD_MTR_VoidCustomCharacters(){
	//Custom characters
	u8 LCD_MTR_Forward[8] = {
		(u8)0b00100,
		(u8)0b01110,
		(u8)0b11111,
		(u8)0b00100,
		(u8)0b00100,
		(u8)0b00100,
		(u8)0b00100,
		(u8)0b00100
	};

	u8 LCD_MTR_Reverse[8] = {
		(u8)0b00100,
		(u8)0b00100,
		(u8)0b00100,
		(u8)0b00100,
		(u8)0b00100,
		(u8)0b11111,
		(u8)0b01110,
		(u8)0b00100
	};

	u8 LCD_MTR_Right[8] = {
		(u8)0b01000,
		(u8)0b00100,
		(u8)0b00010,
		(u8)0b11111,
		(u8)0b11111,
		(u8)0b00010,
		(u8)0b00100,
		(u8)0b01000
	};

	u8 LCD_MTR_Lift[8] = {
		(u8)0b00010,
		(u8)0b00100,
		(u8)0b01000,
		(u8)0b11111,
		(u8)0b11111,
		(u8)0b01000,
		(u8)0b00100,
		(u8)0b00010
	};

	//Send the custom characters to the CGRAM
	LCD_voidWriteSpecialCharToCGRAM(LCD_MTR_Forward,LCD_MTR_Forward_ADDRESS);

	LCD_voidWriteSpecialCharToCGRAM(LCD_MTR_Reverse,LCD_MTR_Reverce_ADDRESS);

	LCD_voidWriteSpecialCharToCGRAM(LCD_MTR_Right,LCD_MTR_Right_ADDRESS);

	LCD_voidWriteSpecialCharToCGRAM(LCD_MTR_Lift,LCD_MTR_Lift_ADDRESS);

	return;
}

/*--------------------------------------------------------------------------------------------*/
u32 UltrasonicRead = 0;

/*--------------------------------------------------------------------------------------------*/
BOOL Ultrasonic_Servo_BoolCheckRightSide(){
	//Move the SERVO to the right
	Servo_voidSetAngle(90);

	//Start the Ultrasonic read
	ULTRASONIC_VoidStart();

	_delay_ms(500);

	//Write the distance to the UltrasonicRead variable
	UltrasonicRead = ULTRASONIC_VoidVal();

	//check if the distance is greater than 50
	if(ULTRASONIC_VoidVal()>=50){
		//Return TRUE to indicate that the right is empty
		return TRUE;//Right empty
	}
	//Return FALSE to indicate that the right is not empty
	return FALSE;
}

/*--------------------------------------------------------------------------------------------*/
BOOL Ultrasonic_Servo_BoolCheckFrontSide(){
	//Move the SERVO to be forward
	Servo_voidSetAngle(0);

	//Start the Ultrasonic read
	ULTRASONIC_VoidStart();

	_delay_ms(500);

	//Write the distance to the UltrasonicRead variable
	UltrasonicRead = ULTRASONIC_VoidVal();

	//check if the distance is greater than 50
	if(ULTRASONIC_VoidVal()>=50){
		//Return TRUE to indicate that the front is empty
		return TRUE;//Front empty
	}
	//Return FALSE to indicate that the front is not empty
	return FALSE;
}

/*--------------------------------------------------------------------------------------------*/
BOOL Ultrasonic_Servo_BoolCheckLiftSide(){
	//Move the SERVO to the lift
	Servo_voidSetAngle(-90);

	//Start the Ultrasonic read
	ULTRASONIC_VoidStart();

	_delay_ms(500);

	//Write the distance to the UltrasonicRead variable
	UltrasonicRead = ULTRASONIC_VoidVal();

	//check if the distance is greater than 50
	if(ULTRASONIC_VoidVal()>=50){
		//Return true to indicate that the lift is empty
		return TRUE;//Lift empty
	}
	//Return FALSE to indicate that the lift is not empty
	return FALSE;
}

/*--------------------------------------------------------------------------------------------*/

int main(){

	//LCD
	LCD_voidInit();

	LCD_MTR_VoidCustomCharacters();

	//Motor
	u8 MovementState = 0;
	MTR_voidInit();

	//SERVO
	SERVO_voidInit();

	//ULTRASONIC
	ULTRASONIC_voidInit();

	while (1){

		//Clear the display
		LCD_voidClear();

		//Write the distance to the LCD
		LCD_voidWriteNumber(UltrasonicRead);

		switch(MovementState){
		//Forward
		case 0:
			//Check if there is not any obstacles ahead
			if(Ultrasonic_Servo_BoolCheckFrontSide()==TRUE) {
				//Move to the second row in the LCD
				LCD_voidGoToXY(2,0);

				//Send forward custom character to the LCD
				LCD_voidDisplaySpecialChar(LCD_MTR_Forward_ADDRESS);
				//Start the motors
				MTR_voidMovement(MTR_FORWARD, 250);
			}

			//Check if there is not any obstacles ahead
			else if(Ultrasonic_Servo_BoolCheckFrontSide()==FALSE) {
				//Stop the motors
				MTR_voidMovement(MTR_STOP, 0);

				//Send stop to the LCD
				LCD_voidWriteString("Stop.");

				//Do to the second row in the LCD
				LCD_voidGoToXY(2,0);

				MovementState = 1;
			}
			break;
		//Check sides
		case 1:
			if( ( Ultrasonic_Servo_BoolCheckRightSide() && Ultrasonic_Servo_BoolCheckFrontSide() && Ultrasonic_Servo_BoolCheckLiftSide() )==TRUE) {
				//Move to the second row in the LCD
				LCD_voidGoToXY(2,0);

				LCD_voidWriteString("ALL sides are free.");

				MovementState = 0;
			}
			else if(Ultrasonic_Servo_BoolCheckRightSide()==TRUE) {
					MovementState = 2;
			}
			else if(Ultrasonic_Servo_BoolCheckFrontSide()==TRUE) {
					MovementState = 0;
			}
			else if (Ultrasonic_Servo_BoolCheckLiftSide()==TRUE) {
					MovementState = 3;
			}
			else {
				//Stop the motors
				MTR_voidMovement(MTR_REVERSE, 250);

				//Move to the second row in the LCD
				LCD_voidGoToXY(2,0);

				LCD_voidWriteString("No free sides.");


				//Move to the second row in the LCD
				LCD_voidGoToXY(3,0);

				//Send reverse to the LCD
				LCD_voidWriteString("Reversing.");
			}
			break;
		//Movement to the right
		case 2:
			//Check if there is not any obstacles ahead
			if(Ultrasonic_Servo_BoolCheckFrontSide()==TRUE) {
				//Move to the second row in the LCD
				LCD_voidGoToXY(2,0);
				//Send forward custom character to the LCD
				LCD_voidDisplaySpecialChar(LCD_MTR_Right_ADDRESS);
				//Start the motors
				MTR_voidMovement(MTR_RIGHT, 250);
			}
			else {
				MovementState = 1;
			}
			break;
		//Movement to the lift
		case 3:
			//Check if there is not any obstacles ahead
			if(Ultrasonic_Servo_BoolCheckFrontSide()==TRUE) {
				//Move to the second row in the LCD
				LCD_voidGoToXY(2,0);
				//Send forward custom character to the LCD
				LCD_voidDisplaySpecialChar(LCD_MTR_Lift_ADDRESS);
				//Start the motors
				MTR_voidMovement(MTR_LEFT, 250);
			}
			else {
				MovementState = 1;
			}
			break;
		default:
			break;
		}
		_delay_ms(500);
	}

	return 0;
}
