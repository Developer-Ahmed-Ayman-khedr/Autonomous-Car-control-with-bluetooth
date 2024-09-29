/*
 * main.c
 *
 *  Created on: September 18, 2024
 *      Author: ahmed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "DIO_Interface.h"

#include "LCD_Interface.h"

#include "MTR_Interface.h"

#include "ULTRASONIC_Interface.h"

int main(){

	//LCD
	LCD_voidInit();

	//Custom character

	u8 LCD_MTR_Forward_ADDRESS = (u8)0;

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

	u8 LCD_MTR_Reverce_ADDRESS = (u8)1;
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

	u8 LCD_MTR_Right_ADDRESS = (u8)2;
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

	u8 LCD_MTR_Lift_ADDRESS = (u8)3;
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

	//Motor
	MTR_voidInit();

	//ULTRASONIC
	ULTRASONIC_voidInit();

	u32 UltrasonicRead = 0;

	while (1){
		ULTRASONIC_VoidStart();

		MTR_voidMovement(MTR_FORWARD,50);

		UltrasonicRead = 0;

		UltrasonicRead = ULTRASONIC_VoidVal();

		if(UltrasonicRead!=0){
			LCD_voidWriteNumber(UltrasonicRead);
		}
	}

	return 0;
}
