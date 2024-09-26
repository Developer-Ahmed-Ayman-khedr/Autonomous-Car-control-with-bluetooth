/*
 * MTR_Config.h
 *
 *  Created on: Sep 26, 2024
 *      Author: ahmed
 */

#ifndef HAL_MTR_MTR_CONFIG_H_
#define HAL_MTR_MTR_CONFIG_H_

/******************************************
  INCLUDES
*******************************************/


/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/
/*
 * choose control pin
 */
#define CONTROL_PIN   PIN7
#define CONTROL_PORT  PORTD_ID

/*
 * direction pins
 */
#define DIRECTION_PIN1    PIN4
#define DIRECTION_PORT1   PORTA_ID

#define DIRECTION_PIN2    PIN5
#define DIRECTION_PORT2   PORTA_ID

#define DIRECTION_PIN3    PIN6
#define DIRECTION_PORT3   PORTA_ID

#define DIRECTION_PIN4    PIN7
#define DIRECTION_PORT4   PORTA_ID

/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS Prototypes
*******************************************/


#endif /* HAL_MTR_MTR_CONFIG_H_ */
