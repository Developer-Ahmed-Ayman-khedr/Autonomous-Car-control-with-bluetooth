/*
 * LCD_Interface.h
 *
 *  Created on: Sep 18, 2024
 *      Author: ahmed
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

/******************************************
  INCLUDES
*******************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/

#define SHIFT_DISPLAY_RIGHT                  	(u8)0b00011100

#define SHIFT_DISPLAY_LIFT                  	(u8)0b00011000

/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS Prototypes
*******************************************/

static void LCD_voidWriteBitsToSend(u8 copy_u8Byte);

void LCD_voidInit(void);

void LCD_voidWriteData(u8 copy_u8data);

void LCD_voidWriteCommand(u8 copy_u8Command);



void LCD_voidWriteString(u8 * copy_str);

void LCD_voidGoToXY(u8 copy_u8Row,u8 copy_u8Col);

void LCD_voidClear(void);

void LCD_voidShift(u8 copy_u8direction);

void LCD_voidWriteNumber( u32 Copy_u8num );


void LCD_voidWriteSpecialCharToCGRAM(u8 * copy_u8data , u8 copy_u8ByteNum );

void LCD_voidDisplaySpecialChar(u8 copy_u8ByteNum ) ;

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
