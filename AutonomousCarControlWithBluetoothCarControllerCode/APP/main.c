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
//UART Read
#define UART_MTR_CONTINUE (u8)1

/*--------------------------------------------------------------------------------------------*/
//SystemMode
#define AUTONOMOUSMODE 	(u8)1

#define BLUETOOTHMODE 	(u8)2

/*--------------------------------------------------------------------------------------------*/
//AutonomousMode
void AutonomousMode_voidMain(){
	static u8 AutonomousModeMovementState = 0;

	switch(AutonomousModeMovementState){
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

				AutonomousModeMovementState = 1;
			}
			break;
		//Check sides
		case 1:
			if( ( Ultrasonic_Servo_BoolCheckRightSide() && Ultrasonic_Servo_BoolCheckFrontSide() && Ultrasonic_Servo_BoolCheckLiftSide() )==TRUE) {
				//Move to the second row in the LCD
				LCD_voidGoToXY(2,0);

				LCD_voidWriteString("ALL sides are free.");

				AutonomousModeMovementState = 0;
			}
			else if(Ultrasonic_Servo_BoolCheckRightSide()==TRUE) {
				AutonomousModeMovementState = 2;
			}
			else if(Ultrasonic_Servo_BoolCheckFrontSide()==TRUE) {
				AutonomousModeMovementState = 0;
			}
			else if (Ultrasonic_Servo_BoolCheckLiftSide()==TRUE) {
				AutonomousModeMovementState = 3;
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
				AutonomousModeMovementState = 1;
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
				AutonomousModeMovementState = 1;
			}
			break;
		default:
			LCD_voidWriteString("Error.");
			break;
		}
}
/*--------------------------------------------------------------------------------------------*/
//BluetoothMode
void BluetoothMode_voidMain(){
	static u8 BluetoothModeMovementState = 0;

	switch(BluetoothModeMovementState){
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

				//Go to the second row in the LCD
				LCD_voidGoToXY(2,0);

				BluetoothModeMovementState = 1;
			}
			break;
		//Check sides
		case 1:
			if( ( Ultrasonic_Servo_BoolCheckRightSide() && Ultrasonic_Servo_BoolCheckFrontSide() && Ultrasonic_Servo_BoolCheckLiftSide() )==TRUE) {
				//Move to the second row in the LCD
				LCD_voidGoToXY(2,0);

				LCD_voidWriteString("ALL sides are free.");

				//Send the options to the user using UART
				UART_VoidSendString("\r\nALL sides are free.\r\n");
				UART_VoidSendString("1.Forward 2.Right 3.Lift\r\n");

				//Read the UART
				if (UART_VoidReceiveString(&BluetoothModeMovementState)!=UART_TIME_OUT_ERROR) {
					UART_VoidSendChar(BluetoothModeMovementState);
					BluetoothModeMovementState-=1;
				}
			}
			else if(Ultrasonic_Servo_BoolCheckRightSide()==TRUE) {
				//Move to the second row in the LCD
				LCD_voidGoToXY(2,0);

				LCD_voidWriteString("Right side is empty.");

				//Send the options to the user using UART
				UART_VoidSendString("\r\nRight side is empty.\r\n");
				UART_VoidSendString("1.Continue\r\n");

				//Read the UART
				if (UART_VoidReceiveString(&BluetoothModeMovementState)!=UART_TIME_OUT_ERROR) {
					UART_VoidSendChar(BluetoothModeMovementState);
					if(BluetoothModeMovementState==UART_MTR_CONTINUE) {
						BluetoothModeMovementState = 2;
					}
				}
			}
			else if(Ultrasonic_Servo_BoolCheckFrontSide()==TRUE) {
				//Move to the second row in the LCD
				LCD_voidGoToXY(2,0);

				LCD_voidWriteString("Front side is empty.");

				//Send the options to the user using UART
				UART_VoidSendString("\r\nFront side is empty.\r\n");
				UART_VoidSendString("1.Continue\r\n");

				//Read the UART
				if (UART_VoidReceiveString(&BluetoothModeMovementState)!=UART_TIME_OUT_ERROR) {
					UART_VoidSendChar(BluetoothModeMovementState);
					if(BluetoothModeMovementState==UART_MTR_CONTINUE) {
						BluetoothModeMovementState = 0;
					}
				}

			}
			else if (Ultrasonic_Servo_BoolCheckLiftSide()==TRUE) {
				//Move to the second row in the LCD
				LCD_voidGoToXY(2,0);

				LCD_voidWriteString("Lift side is empty.");

				//Send the options to the user using UART
				UART_VoidSendString("\r\nLift side is empty.\r\n");
				UART_VoidSendString("1.Continue\r\n");

				//Read the UART
				if (UART_VoidReceiveString(&BluetoothModeMovementState)!=UART_TIME_OUT_ERROR) {
					UART_VoidSendChar(BluetoothModeMovementState);
					if(BluetoothModeMovementState==UART_MTR_CONTINUE) {
						BluetoothModeMovementState = 3;
					}
				}

			}
			else {
				//Move to the second row in the LCD
				LCD_voidGoToXY(2,0);

				LCD_voidWriteString("ALL sides are not free.");

				//Send the options to the user using UART
				UART_VoidSendString("\r\nALL sides are not free.\r\n");
				UART_VoidSendString("1.Reverse\r\n");

				//Read the UART
				if (UART_VoidReceiveString(&BluetoothModeMovementState)!=UART_TIME_OUT_ERROR) {
					UART_VoidSendChar(BluetoothModeMovementState);
					if (BluetoothModeMovementState==UART_MTR_CONTINUE) {
						//Stop the motors
						MTR_voidMovement(MTR_REVERSE, 250);

						//Move to the second row in the LCD
						LCD_voidGoToXY(3,0);

						//Send reverse to the LCD
						LCD_voidWriteString("Reversing.");
					}
				}
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
				BluetoothModeMovementState = 1;
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
				BluetoothModeMovementState = 1;
			}
			break;
		default:
			LCD_voidWriteString("Error.");
			break;
		}
}
/*--------------------------------------------------------------------------------------------*/

int main(){

	//System
	u8 SystemMode = 0;

	//UART
	UART_VoidInit();

	//LCD
	LCD_voidInit();

	LCD_MTR_VoidCustomCharacters();

	//Motor
	MTR_voidInit();

	//SERVO
	SERVO_voidInit();

	//ULTRASONIC
	ULTRASONIC_voidInit();

	while (1){

		//Send the options to the user using UART
		UART_VoidSendString("\r\nHello\r\n");
		UART_VoidSendString("1.Autonomous 2.Bluetooth Control\r\n");

		//Read the UART
		if (UART_VoidReceiveString(&SystemMode)!=UART_TIME_OUT_ERROR) {

			UART_VoidSendChar(SystemMode);

			//Check if the mode is equal to AutonomousMode or BluetoothMode
			if (SystemMode==AUTONOMOUSMODE){
				AutonomousMode_voidMain();
			}
			else if(SystemMode==BLUETOOTHMODE){
				BluetoothMode_voidMain();
			}
		}

		//Clear the display
		LCD_voidClear();

		//Write the distance to the LCD
		LCD_voidWriteNumber(UltrasonicRead);


		_delay_ms(500);
	}

	return 0;
}
