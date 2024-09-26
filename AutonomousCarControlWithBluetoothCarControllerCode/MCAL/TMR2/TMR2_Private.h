/*
 * TMR0_Private.h
 *
 *  Created on: Sep 18, 2024
 *      Author: ahmed
 */

#ifndef MCAL_TMR0_TMR0_PRIVATE_H_
#define MCAL_TMR0_TMR0_PRIVATE_H_

/******************************************
  INCLUDES
*******************************************/


/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/

#define NORMAL2_MOOD  1
#define CTC2_MOOD     2
#define PWM2_MOOD     3


/************************************************************************************/

#define  ISR2_EN       1
#define  ISR2_DIS_EN   2


/************************************************************************************/

#define  OC2_ON       1
#define  OC2_OFF      2

/************************************************************************************/

/*
 * OC2_PWM_STAT
 * */
#define  CLEAR2_ON_COMPARE_MATCH_SET_ON_TOP   0b10
#define  SET_ON2_COMPARE_MATCH_CLR_ON_TOP     0b11


/************************************************************************************/


enum OC2_CTC_STAT
{
	OC2_DISCONNECTED        = 0b00   ,
	OC2_TOGGEL              = 0b01   ,
	CLEAR2_ON_COMPARE_MATCH  = 0b10   ,
	SET_ON2_COMPARE_MATCH    = 0b11
};

/************************************************************************************/



/************************************************************************************/

enum  PRESCALER2
{
	No2_FREQ        =  0b000 ,
	No2_PRESCALER   =  0b001 ,
	PRESCALER2_8    =  0b010 ,
	PRESCALER2_64   =  0b011 ,
	PRESCALER2_256  =  0b100 ,
	PRESCALER2_1024 =  0b101
};


/************************************************************************************/

/*
 * Timer/Counter 2 Control Register
 */

typedef struct
{
	u8 TCCR2_CS0     :3 ;
	u8 TCCR2_WGM01   :1 ;
	u8 TCCR2_COM     :2 ;
	u8 TCCR2_WGM00   :1 ;
	u8 TCCR2_FOC0    :1 ;
}TCCR2;

#define TCCR2_REG  ((volatile TCCR2*) 0x45)


/*
 * Timer/Counter 2 Register
 */
#define TCNT2_REG  (*( (volatile u8 *) 0x44))
/************************************************************************************/

/*
 * Timer/Counter 2 Output Compare Register
 */
#define OCR2_REG   (*( (volatile u8 *) 0x43))
/************************************************************************************/

/*
 * Timer/Counter 02Interrupt Mask Register
 */
//#define TIMSK_REG  (*( (volatile u8 *) 0x59))
///* Bits from 7 : 2 are not used in this module */
//#define TIMSK_OCIE0  (0x01)
//#define TIMSK_TOIE0  (0x00)
typedef struct
{
	u8               :6 ;
	u8 TIMSK_TOIE2    :1 ;
	u8 TIMSK_OCIE2    :1 ;

} TIMSK2;

#define TIMSK2_REG  ((volatile TIMSK2*) 0x59)

/************************************************************************************/

/*
 * Timer/Counter 2 Interrupt Flag Register
 */
#define TIFR2   (*( (volatile u8 *) 0x58))
/* Bits from 7 : 2 are not used in this module */
#define TIFR_OCF2   (0x07)
#define TIFR_TOV2   (0x06)

/************************************************************************************/


/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS Prototypes
*******************************************/


#endif /* MCAL_TMR0_TMR0_PRIVATE_H_ */
