/*
 * STD_TYPES.h
 *
 *  Created on: Sep 18, 2024
 *      Author: ahmed
 */

#ifndef LIB_STD_TYPES_H_
#define LIB_STD_TYPES_H_

/**************
  INCLUDES
***************/


/**************
  Global Data TYPES AND STRUCTURES
***************/
/*
 * unSigned Data Types
 */
typedef unsigned char           u8;
typedef unsigned short int      u16;
typedef unsigned long int       u32;
typedef unsigned long long int  u64;

/*
 * signed Data Types
 */
typedef signed char             s8;
typedef signed short int        s16;
typedef signed long int         s32;
typedef signed long long int    s64;

/*
 * Floating point Types
 */
typedef float                   f32;
typedef double                  f64;

/*
 * Address NULL
 */

/*Boolians*/
typedef enum {FALSE,TRUE} BOOL;

/**************
  GLOBAL CONSTANT MACROS
***************/

#ifndef NULL
#define NULL ((void *) 0)
#endif

/**************
  GLOBAL FUNCTIONS MACROS
***************/


/**************
  GLOBAL FUNCTIONS Prototypes
***************/

#endif /* LIB_STD_TYPES_H_ */
