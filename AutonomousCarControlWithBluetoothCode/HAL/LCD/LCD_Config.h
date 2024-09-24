/*
 * LCD_Config.h
 *
 *  Created on: Sep 18, 2024
 *      Author: ahmed
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

/******************************************
  INCLUDES
*******************************************/


/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/

//#define LCD_MODE  FOUR_BIT

/*
 * choose control pins
 */
#define RS_PIN   PIN0
#define RS_PORT  PORTC_ID


#define EN_PIN   PIN1
#define EN_PORT  PORTC_ID


/*
 * data pins
 */
#define D7_PIN    PIN5
#define D7_PORT   PORTC_ID

#define D6_PIN    PIN4
#define D6_PORT   PORTC_ID

#define D5_PIN    PIN3
#define D5_PORT   PORTC_ID

#define D4_PIN    PIN2
#define D4_PORT   PORTC_ID

/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS Prototypes
*******************************************/


#endif /* HAL_LCD_LCD_CONFIG_H_ */
