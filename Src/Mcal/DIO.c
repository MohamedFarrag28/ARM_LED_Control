/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
 *        \brief  
 *
 *      \details  
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../Common/Std_Types.h"
#include "../Common/Platform_Types.h"
#include "../Common/Bit_Math.h"
#include "../Common/Mcu_Hw.h"
#include "Inc/DIO.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
volatile GPIO_PRE_REG_t* PGPIO_GetPortPointer(DIO_Port_t Copy_u8PortID) 
{
    switch (Copy_u8PortID)
    {
        case DIO_PORTA:
        return GPIO_PORTA_REG ;
        

        case DIO_PORTB :
        return GPIO_PORTB_REG ;

        

        case DIO_PORTC :
        return GPIO_PORTC_REG ;

        case DIO_PORTD:
        return GPIO_PORTD_REG ;

        case DIO_PORTE :
        return GPIO_PORTE_REG ;

        case DIO_PORTF :
        return GPIO_PORTF_REG ;

        default :
        return 0 ;
    }
}




DIO_LevelType Dio_ReadChannel(DIO_Channel_t Channel_id)
{
    volatile GPIO_PRE_REG_t* Port = PGPIO_GetPortPointer((uint8)(Channel_id/8));
    return 	GET_BIT( (uint32)(Port->GPIODATA[255]),(uint8)(Channel_id%8));

}

void Dio_WriteChannel(DIO_Channel_t Channel_id, DIO_LevelType level)
{
		
    volatile GPIO_PRE_REG_t* Port = PGPIO_GetPortPointer((uint8)(Channel_id/8));
    switch(level)
    {
        case GPIO_Low :
        CLR_BIT((Port->GPIODATA[255]),(uint8)(Channel_id%8)) ;
        break ;

        case GPIO_High :
        SET_BIT((Port->GPIODATA[255]),Channel_id%8) ;
        break ;
    }
}

DIO_PortLevelType Dio_ReadPort(DIO_Port_t Port_id)
{
    volatile GPIO_PRE_REG_t* Port = PGPIO_GetPortPointer(Port_id);
    return Port-> GPIODATA[255] ;
}

void Dio_WritePort(DIO_Port_t Port_id, DIO_PortLevelType level)
{
    volatile GPIO_PRE_REG_t* Port = PGPIO_GetPortPointer(Port_id);
    Port->GPIODATA[255] = level ;
}

void Dio_FlipChannel(DIO_Channel_t Channel_id)
{
    volatile GPIO_PRE_REG_t* Port = PGPIO_GetPortPointer(Channel_id/8);
    TOG_BIT(Port->GPIODATA[255],(uint8)(Channel_id%8));

}



/**********************************************************************************************************************
 *  END OF FILE: DIO.c
 *********************************************************************************************************************/
