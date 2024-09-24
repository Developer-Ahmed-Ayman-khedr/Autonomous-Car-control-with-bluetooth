/*
 * EXTINT_Config.h
 *
 *  Created on: Sep 18, 2024
 *      Author: ahmed
 */

#ifndef MCAL_EXTINT_EXTINT_CONFIG_H_
#define MCAL_EXTINT_EXTINT_CONFIG_H_

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
EXT_Init_DIR
EXT_Init_NORMAL
*/
#define EXT_Init_NORMAL

/*********************************************************/


/*---------------------------------------------------------*/

#ifdef EXT_Init_DIR

/*---------------------------------------------------------*/

/*
 * EXTINT_EN
 * EXTINT_DIS_EN
 */
#define EXT0  EXTINT_DIS_EN
#define EXT1  EXTINT_EN
#define EXT2  EXTINT_DIS_EN

/*********************************************************/

/*
 * RISING_EDGE
 * FALLING_EDGE
 */
#if EXT0 ==EXTINT_EN
#define EXT0_ControlSens  FALLING_EDGE
#endif

#if EXT1 == EXTINT_EN
#define EXT1_ControlSens  FALLING_EDGE
#endif



#if EXT2 == EXTINT_EN
#define EXT1_ControlSens  FALLING_EDGE
#endif
/*********************************************************/


#endif

/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS Prototypes
*******************************************/


#endif /* MCAL_EXTINT_EXTINT_CONFIG_H_ */
