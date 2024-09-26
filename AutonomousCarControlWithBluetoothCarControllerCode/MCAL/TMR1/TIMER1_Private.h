/*
 * TIMER1_Private.h
 *
 *  Created on: September 18, 2024
 *      Author: ahmed
 */

#ifndef TIMER1_TIMER1_PRIVATE_H_
#define TIMER1_TIMER1_PRIVATE_H_

/******************************************
  INCLUDES
*******************************************/


/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/

#define TCCR1A_REG   *((volatile u8 *)0x4F)
#define WGM10         0
#define WGM11         1
#define COM1A0        6
#define COM1A1        7

#define TCCR1B_REG   *((volatile u8 *)0x4E)
#define WGM12         3
#define WGM13         4
#define CS10          0
#define CS11          1
#define CS12          2


#define OCR1A_REG    *((volatile u16 *)0x4A)
#define ICR1_REG     *((volatile u16 *)0x46)


/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS Prototypes
*******************************************/

#endif /* TIMER1_TIMER1_PRIVATE_H_ */
