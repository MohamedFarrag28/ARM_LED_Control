/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPIO.h
 *       Module:  GPIO
 *
 *  Description:  header file for GPIO PRE    
 *  
 *********************************************************************************************************************/
#ifndef GPIO_H
#define GPIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "../../Common/Mcu_Hw.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef  uint8 DIO_PortLevelType ;

typedef enum{
		DIO_PORTA ,
		DIO_PORTB ,
		DIO_PORTC ,
    DIO_PORTD ,
    DIO_PORTE ,
    DIO_PORTF

}DIO_Port_t;

typedef enum{
	GPIO_PIN_A0=0,	
	GPIO_PIN_A1,	
	GPIO_PIN_A2,	
	GPIO_PIN_A3,	
	GPIO_PIN_A4,	
	GPIO_PIN_A5,	
	GPIO_PIN_A6,	
	GPIO_PIN_A7,	
	GPIO_PIN_B0,	
	GPIO_PIN_B1,
	GPIO_PIN_B2,
	GPIO_PIN_B3,
	GPIO_PIN_B4,
	GPIO_PIN_B5,
	GPIO_PIN_B6,
	GPIO_PIN_B7,
	GPIO_PIN_C0,
	GPIO_PIN_C1,
	GPIO_PIN_C2,
	GPIO_PIN_C3,
	GPIO_PIN_C4,
	GPIO_PIN_C5,
	GPIO_PIN_C6,
	GPIO_PIN_C7,
	GPIO_PIN_D0,
	GPIO_PIN_D1,
	GPIO_PIN_D2,
	GPIO_PIN_D3,
	GPIO_PIN_D4,
	GPIO_PIN_D5,
	GPIO_PIN_D6,
	GPIO_PIN_D7,
	GPIO_PIN_E0,
	GPIO_PIN_E1,
	GPIO_PIN_E2,
	GPIO_PIN_E3,
	GPIO_PIN_E4,
	GPIO_PIN_E5,
	GPIO_PIN_F0 = 40,	
	GPIO_PIN_F1,
	GPIO_PIN_F2,
	GPIO_PIN_F3,
	GPIO_PIN_F4
}DIO_Channel_t;


typedef enum
{
    GPIO_Low =0 ,
    GPIO_High
}DIO_LevelType ;

typedef enum{
	GPIO_Input ,
    GPIO_Output 
    
}DIO_DIR_t;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

DIO_LevelType Dio_ReadChannel(DIO_Channel_t Channel_id);
void Dio_WriteChannel(DIO_Channel_t Channel_id, DIO_LevelType level);
DIO_PortLevelType Dio_ReadPort(DIO_Port_t Port_id);
void Dio_WritePort(DIO_Port_t Port_id, DIO_PortLevelType level);
void Dio_FlipChannel(DIO_Channel_t Channel_id);

/**********************************************************************************************************************
 *  PRIVATE FUNCTION PROTOTYPES
 *********************************************************************************************************************/
volatile GPIO_PRE_REG_t* PGPIO_GetPortPointer(DIO_Port_t Copy_u8PortID) ;

 


#endif  /* IntCrtl_H */

/**********************************************************************************************************************
 *  END OF FILE: GPIO.h
 *********************************************************************************************************************/
