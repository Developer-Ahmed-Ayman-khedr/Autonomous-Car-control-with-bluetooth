/*
 * BIT_MATH.h
 *
 *  Created on: Sep 18, 2024
 *      Author: ahmed
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

/******************************************
  INCLUDES
*******************************************/


/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/

//Control specific bits
#define SET_BIT(VAR,BITNO)  ( (VAR) |=  ( 1 <<(BITNO) ) )
#define CLR_BIT(VAR,BITNO)  ( (VAR) &= ~( 1 <<(BITNO) ) )


#define TOG_BIT(VAR,BITNO)  ( (VAR) ^=  (1 <<(BITNO)  ) )
#define GET_BIT(VAR,BITNO)  ( ( (VAR) >> BITNO) & 0x01  )

#define SET_PORT(VAR,PORT)  ( (VAR) =  (PORT)  )


#define ZERO     (u8)0
#define	ONE      (u8)1
#define	TWO      (u8)2
#define	THREE    (u8)3
#define	FOUR     (u8)4
#define	FIVE     (u8)5
#define	SIX      (u8)6
#define	SEVEN    (u8)7
#define	EIGHT    (u8)8
#define	NINE     (u8)9

/******************************************
  GLOBAL FUNCTIONS Prototypes
*******************************************/

#endif /* LIB_BIT_MATH_H_*/
