/*
 * TMR2_Config.h
 *
 *  Created on: Sep 26, 2024
 *      Author: ahmed
 */

#ifndef MCAL_TMR2_TMR2_CONFIG_H_
#define MCAL_TMR2_TMR2_CONFIG_H_

/******************************************
  INCLUDES
*******************************************/


/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/

/***************************************************************************************/
#define  PRELOAD2   0

/***************************************************************************************/

/*
 * NORMAL2_MOOD
 * CTC2_MOOD
 * PWM2_MOOD
 * */
#define MOOD2  PWM2_MOOD
/***************************************************************************************/

/*
 * ISR2_EN
 * ISR2_DIS_EN
 */


#if (MOOD2==CTC2_MOOD) ||(MOOD2==NORMAL2_MOOD)
#define  ISR2  ISR_EN
#endif


/***************************************************************************************/

/*
 * CLEAR_ON_COMPARE_MATCH
 * SET_ON_COMPARE_MATCH
 * OC0_TOGGEL
 * OC0_DISCONNECTED
 */

#if  MOOD2 == CTC2_MOOD
#define CTC2_COMPARE_MATCH     OC2_TOGGEL
#define  CTC2_MOOD_VAL         249
#endif

/***************************************************************************************/

/*
 * CLEAR2_ON_COMPARE_MATCH_SET_ON_TOP
 * SET2_ON_COMPARE_MATCH_CLR_ON_TOP
 * OC2_DISCONNECTED
 */
#if     MOOD2 == PWM2_MOOD
#define PWM2_COMPARE_MATCH       CLEAR2_ON_COMPARE_MATCH_SET_ON_TOP
#endif

/***************************************************************************************/
/*
 * No2_PRESCALER
 * PRESCALER2_8
 * PRESCALER2_64
 * PRESCALER2_128
 * PRESCALER2_256
 * PRESCALER2_1024
 * */

#define PRESCALER2   PRESCALER2_1024

/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS Prototypes
*******************************************/

#endif /* MCAL_TMR2_TMR2_CONFIG_H_ */
