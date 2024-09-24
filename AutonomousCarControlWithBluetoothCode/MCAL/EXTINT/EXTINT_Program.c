/*
 * EXT_Program.c
 *
 *  Created on: Sep 18, 2024
 *      Author: ahmed
 */


#include "STD_TYPES.h"
#include  "BIT_MATH.h"
#include "DIO_Interface.h"

#include "EXTINT_Interface.h"
#include  "EXTINT_Private.h"
#include "EXTINT_Config.h"

static void (*ptr_ArrCallBack[3])(void) = {NULL,NULL,NULL};



#ifdef EXT_Init_NORMAL
void EXTINT_voidInit(u8 copy_u8ExtNum,u8 copy_u8ControlSens)
{

	switch(copy_u8ExtNum)
	{
	case EXT0_ID :

		DIO_voidSetPinDirection(PORTD_ID,PIN2,PIN_INPUT);

		if(copy_u8ControlSens==FALLING_EDGE)
		{

			CLR_BIT(MCUCR_REG,MCUCR_ISC00);
			SET_BIT(MCUCR_REG,MCUCR_ISC01);

		}


		else if(copy_u8ControlSens==RISING_EDGE)
		{
			SET_BIT(MCUCR_REG,MCUCR_ISC00);
			SET_BIT(MCUCR_REG,MCUCR_ISC01);
		}

		SET_BIT(GICR_REG,GICR_INT0);

		break ;


	case EXT1_ID :

		DIO_voidSetPinDirection(PORTD_ID,PIN3,PIN_INPUT);

		if(copy_u8ControlSens==FALLING_EDGE)
		{

			CLR_BIT(MCUCR_REG,MCUCR_ISC10);
			SET_BIT(MCUCR_REG,MCUCR_ISC11);

		}

		else if(copy_u8ControlSens==RISING_EDGE)
		{
			SET_BIT(MCUCR_REG,MCUCR_ISC10);
			SET_BIT(MCUCR_REG,MCUCR_ISC11);
		}
		SET_BIT(GICR_REG,GICR_INT1);

		break ;

	case EXT2_ID :

		DIO_voidSetPinDirection(PORTB_ID,PIN2,PIN_INPUT);

		if(copy_u8ControlSens==FALLING_EDGE)
		{
			CLR_BIT(MCUCSR_REG,MCUCSR_ISC2);
		}

		else if(copy_u8ControlSens==RISING_EDGE)
		{
			SET_BIT(MCUCSR_REG,MCUCSR_ISC2);
		}
		SET_BIT(GICR_REG,GICR_INT2);

		break ;

	}
}

#endif


/******************************************************************************************/
/******************************************************************************************/
#ifdef EXT_Init_DIR

void EXTINT_voidInitDir(void)
{


#if EXT0 == EXTINT_EN

	DIO_voidSetPinDirection(PORTD_ID,PIN2,PIN_INPUT);
	DIO_voidSetPinValue(PORTD_ID,PIN2,PIN_HIGH);

#if EXT0_ControlSens == FALLING_EDGE

	CLR_BIT(MCUCR_REG,MCUCR_ISC00);
	SET_BIT(MCUCR_REG,MCUCR_ISC01);


#elif EXT0_ControlSens == RISING_EDGE

	SET_BIT(MCUCR_REG,MCUCR_ISC00);
	SET_BIT(MCUCR_REG,MCUCR_ISC01);

#endif

	SET_BIT(GICR_REG,GICR_INT0);


#endif


#if EXT1 == EXTINT_EN

	DIO_voidSetPinDirection(PORTD_ID,PIN3,PIN_INPUT);
	DIO_voidSetPinValue(PORTD_ID,PIN3,PIN_HIGH);

#if EXT1_ControlSens == FALLING_EDGE

	CLR_BIT(MCUCR_REG,MCUCR_ISC10);
	SET_BIT(MCUCR_REG,MCUCR_ISC11);


#elif EXT1_ControlSens == RISING_EDGE

	SET_BIT(MCUCR_REG,MCUCR_ISC00);
	SET_BIT(MCUCR_REG,MCUCR_ISC01);

#endif

	SET_BIT(GICR_REG,GICR_INT1);


#endif


#if EXT2 == EXTINT_EN

	DIO_voidSetPinDirection(PORTB_ID,PIN2,PIN_INPUT);
	DIO_voidSetPinValue(PORTB_ID,PIN2,PIN_HIGH);

#if EXT1_ControlSens == FALLING_EDGE

	CLR_BIT(MCUCSR_REG,MCUCSR_ISC2);


#elif EXT1_ControlSens == RISING_EDGE

	SET_BIT(MCUCSR_REG,MCUCSR_ISC2);



#endif

	SET_BIT(GICR_REG,GICR_INT2);


#endif


}



#endif


/**************************************************************************************/
/**************call back function ****************/





void EXTINT_voidSetCallBack (  void (*ptr_ext)(void) ,u8 copy_u8ExtNum )
{

	if(ptr_ext!=NULL)
	{
		switch(copy_u8ExtNum)
		{
		case EXT0_ID:
			ptr_ArrCallBack[ 0 ]= ptr_ext;
			break;
		case EXT1_ID:
			ptr_ArrCallBack[ 1 ]= ptr_ext;
			break;
		case EXT2_ID:
			ptr_ArrCallBack[ 2 ]= ptr_ext;
			break;
		default: break;

		}



	}
}



void __vector_1 () __attribute__ ((signal));
void __vector_1 ()
{

	if(ptr_ArrCallBack[0] !=NULL)
	{
		ptr_ArrCallBack[0]();
	}



}

void __vector_2 () __attribute__ ((signal));
void __vector_2 ()
{
	if(ptr_ArrCallBack[1] !=NULL)
		{
		ptr_ArrCallBack[1]();
		}


}

void __vector_3 () __attribute__ ((signal));
void __vector_3 ()
{
	if(ptr_ArrCallBack[2] !=NULL)
		{
		ptr_ArrCallBack[2]();
		}


}



