/*
 * SERVO_Program.c
 *
 *  Created on: Oct 3, 2024
 *      Author: ahmed
 */

/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"

#include "TMR1_Interface.h"

#include "SERVO_Config.h"
#include "SERVO_Interface.h"
#include "SERVO_Private.h"


/*--------------------------------------------------------------------------------------------*/
/*   FUNCTIONS BODY   */
/*--------------------------------------------------------------------------------------------*/

void SERVO_voidInit(){
	TIMER1_voidPwm1Init();
	TIMER1_voidPwm1SetTop(4999);
	TIMER1_voidPwm1Start();
}

void Servo_voidSetAngle(s8 copy_s8angle){
	switch(copy_s8angle){
	case 90:
		TIMER1_voidPwm1SetDutyCycle(499);
		break;
	case 0:
		TIMER1_voidPwm1SetDutyCycle(374);
		break;
	case -90:
		TIMER1_voidPwm1SetDutyCycle(249);
		break;
	default:
		break;
	}

}
