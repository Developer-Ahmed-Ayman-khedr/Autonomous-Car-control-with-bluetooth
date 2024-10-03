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

int main(){

	//LCD
	LCD_voidInit();

	LCD_MTR_VoidCustomCharacters();

	//Motor

	MTR_voidInit();

	//ULTRASONIC
	u32 UltrasonicRead = 0;

	ULTRASONIC_voidInit();

	while (1){
		//Start the Ultrasonic read
		ULTRASONIC_VoidStart();

		UltrasonicRead = 0;

		//Read the distance
		UltrasonicRead = ULTRASONIC_VoidVal();

		//check if the distance is not 0
		if(UltrasonicRead!=0){
			//Clear the display
			LCD_voidClear();

			//Write the distance to the LCD
			LCD_voidWriteNumber(UltrasonicRead);

			//Do to the second row in the LCD
			LCD_voidGoToXY(2,0);

			//check if the distance is greater than 50
			if(UltrasonicRead>=50){
				//Send forward custom character to the LCD
				LCD_voidDisplaySpecialChar(LCD_MTR_Forward_ADDRESS);
				//Start the motors
				MTR_voidMovement(MTR_FORWARD, 250);
			}
			//check if the distance is less than 50 stop the motors
			else if(UltrasonicRead<50){

				//Stop the motors
				MTR_voidMovement(MTR_STOP, 0);

				//Send stop to the LCD
				LCD_voidWriteString("Stop.");

				//Move the SERVO to the right and lift until the distance is greater than 50

			}

		}
		_delay_ms(100);
	}

	return 0;
}
