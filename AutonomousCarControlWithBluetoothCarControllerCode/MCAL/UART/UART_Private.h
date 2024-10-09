/*
 * UART_Private.h
 *
 *  Created on: Oct 8, 2024
 *      Author: ahmed
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_

/******************************************
  INCLUDES
*******************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/
enum STOP_BIT
{
	ONE_STOP_BIT=0b0,
	TWO_STOP_BIT=0b1,
};


/*--------------------------------------------------------------------------------------------*/
typedef struct
{
	u8  UCSRA_MPCM :1 ;
	u8  UCSRA_U2X  :1 ;
	u8  UCSRA_PE   :1 ;
	u8  UCSRA_DOR  :1 ;
	u8  UCSRA_FE   :1 ;
	u8  UCSRA_UDRE :1 ;
	u8  UCSRA_TXC  :1 ;
	u8  UCSRA_RXC  :1 ;

}UCSRA;

/*--------------------------------------------------------------------------------------------*/
typedef struct
{
	u8  UCSRB_TXB8   :1 ;
	u8  UCSRB_RXB8   :1 ;
	u8  UCSRB_UCSZ2  :1 ;
	u8  UCSRB_TXEN   :1 ;
	u8  UCSRB_RXEN   :1 ;
	u8  UCSRB_UDRIE  :1 ;
	u8  UCSRB_TXCIE  :1 ;
	u8  UCSRA_RXCIE  :1 ;

}UCSRB;

/*--------------------------------------------------------------------------------------------*/
typedef union
{
	struct
	{
		u8  UCSRC_UCPOL :1 ;
		u8  UCSRC_UCSZ  :2 ;
		u8  UCSRC_UPM   :2 ;
		u8  UCSRC_UMSEL :1 ;
		u8  UCSRC_URSEL :1 ;

	};
	u8 BYTE ;
}UCSRC_REG_Data;

/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/
#define UART_FINISHED_TRANSMITTING                  1
#define UART_POLLING_TIME                           2000

/*--------------------------------------------------------------------------------------------*/
#define PARITY_DISABLE       0b00
#define PARITY_EVEN          0b10
#define PARITY_ODD           0b11

/*--------------------------------------------------------------------------------------------*/

#define UCSRA_REG  ((volatile UCSRA *) 0x2B)

/*--------------------------------------------------------------------------------------------*/
#define UCSRB_REG  ((volatile UCSRB*) 0x2A)

/*--------------------------------------------------------------------------------------------*/
#define UCSRC_REG  (*((volatile u8 *) 0x40))
/*
#define UCSRC_UPM1_BIT             5
#define UCSRC_UPM0_BIT             4
#define UCSRC_USBS_BIT             3
#define UCSRC_UCSZ1_BIT            2
#define UCSRC_UCSZ0_BIT            1
 */

/*--------------------------------------------------------------------------------------------*/
#define UDR_REG    (*((volatile u8 *) 0x2C))

#define UBRRL_REG  (*((volatile u8 *) 0x29))

/*--------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------*/

/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS Prototypes
*******************************************/


#endif /* MCAL_UART_UART_PRIVATE_H_ */
