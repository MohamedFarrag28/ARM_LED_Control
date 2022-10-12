/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port.h
 *       Module:  Port
 *
 *  Description:      
 *  
 *********************************************************************************************************************/
#ifndef PORT_H
#define PORT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

typedef enum{
		GPIO_PORTA ,
		GPIO_PORTB ,
		GPIO_PORTC ,
    GPIO_PORTD ,
    GPIO_PORTE ,
    GPIO_PORTF

}GPIO_Port_t;




typedef enum{
	GPIO_PIN_0,
	GPIO_PIN_1,
	GPIO_PIN_2,
	GPIO_PIN_3,
	GPIO_PIN_4,
	GPIO_PIN_5,
	GPIO_PIN_6,
	GPIO_PIN_7
}GPIO_Channel_t;


typedef enum{
    DIO,
    Alt_Function,
    Analog_Function,
    Ext_Interrupt
}PINMODE_t;

typedef enum{

    GPIO_2mA_Drive_Select,
    GPIO_4mA_Drive_Select,
    GPIO_8mA_Drive_Select

}PIN_CURRENT_t;


typedef enum{

    OPEN_DRAIN,
    PULL_UP,
    PULL_DOWN
 
}INTERNAL_PIN_t;

typedef enum
{
    GPIO_INPUT ,
    GPIO_OUTPUT

}GPIO_DIR_t;


typedef enum
{
    EDGE_SENSITIVE ,
    LEVEL_SENSITIVE 

}GPIO_INT_SENSE_t;


typedef enum
{
    INT_BOTH_EDGES_DISABLE ,
    INT_BOTH_EDGES_ENABLE  
}INT_BOTH_EDGES_t;

typedef enum
{
    INT_FALLING_EDGE_LOW_LEVEL ,
    INT_RISING_EDGE_HIGH_LEVEL
}INT_EVENT_t;

typedef struct{
    GPIO_Port_t		 					PORT_NO;
    GPIO_Channel_t 					PIN_NO;
    PINMODE_t   						PIN_FUNCTION ;
    uint8       						ALT_FUNC_T ;
    GPIO_DIR_t 							PIN_DIR;
    INTERNAL_PIN_t 					PIN_INTERNAL_ATTACH;
    PIN_CURRENT_t 					PIN_OUTPUT_CURRENT;
    GPIO_INT_SENSE_t 				PIN_INT_SENSE;
    INT_BOTH_EDGES_t 				PIN_INT_BOTH_EDGES;
    INT_EVENT_t 						PIN_INT_EVENT_TYPE;
}GPIO_Conf_t;
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 


void Port_Init(void);
 
#endif  /* PORT_H */

/**********************************************************************************************************************
 *  END OF FILE: PORT.h
 *********************************************************************************************************************/
