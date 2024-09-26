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

	LCD_voidInit();

	MTR_voidInit();

	while (1){


		LCD_voidWriteString("F ");

		_delay_ms(100);

		MTR_voidMovement(MTR_LEFT,200);

	}

	return 0;
}
