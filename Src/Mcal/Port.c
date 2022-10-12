/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
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
#include "Inc/Port.h"

volatile GPIO_PRE_REG_t* PPORT_GetPortPointer(GPIO_Port_t Copy_u8PortID) 
{
    switch (Copy_u8PortID)
    {
        case GPIO_PORTA:
        return GPIO_PORTA_REG ;
        

        case GPIO_PORTB :
        return GPIO_PORTB_REG ;

        

        case GPIO_PORTC :
        return GPIO_PORTC_REG ;

        case GPIO_PORTD:
        return GPIO_PORTD_REG ;

        case GPIO_PORTE :
        return GPIO_PORTE_REG ;

        case GPIO_PORTF :
        return GPIO_PORTF_REG ;

        default :
        return 0 ;
    }
}



extern const uint32 NUM_ACT_PINS ;
extern GPIO_Conf_t Conf_Pins[] ; 



void Port_Init(void)
{
    volatile GPIO_PRE_REG_t* Port =0 ;
    uint8 counter=0 ;
    /*
    DIO:
     - GPIO_UNLOCK (0) 
     - Commit (1)
     - Choose dio in AFSEL (0)
     - Enable Digital function
     - Disable Analog function
     - Choose direction
     - Choose initial state
     - Choose output current
     - PullUp_PullDown

    Analog:
     - Choose dio in AFSEL (0)
     - Disable Digital function
     - Enable Analog function

    Alt function:
     - Choose alt in AFSEL (1)
     - Disable Digital function
     - Disable Analog function
     - Choose function

    Exti :
     - Choose dio in AFSEL (0)
     - Disable Digital function
     - Disable Analog function
     - Choose interrupt sense
     - Choose both edges or not
     - Choose fall or low / rise or high
    */

    for(counter=0 ; counter <NUM_ACT_PINS ; counter++)
    {

        Port =PPORT_GetPortPointer(Conf_Pins[counter].PORT_NO) ;
        switch(Conf_Pins[counter].PIN_FUNCTION)
        {
            case DIO :
                Port->GPIOLOCK = 0x4C4F434B ;
                SET_BIT(Port->GPIOCR,Conf_Pins[counter].PIN_NO) ;
                CLR_BIT(Port->GPIOAFSEL,Conf_Pins[counter].PIN_NO);
                SET_BIT(Port->GPIODEN,Conf_Pins[counter].PIN_NO) ;
                CLR_BIT(Port->GPIOAMSEL,Conf_Pins[counter].PIN_NO);
                if (Conf_Pins[counter].PIN_DIR == GPIO_OUTPUT)
                {
                    SET_BIT(Port->GPIODIR,Conf_Pins[counter].PIN_NO) ;
                    CLR_BIT(Port->GPIODR_2_4_8R[0], Conf_Pins[counter].PIN_NO) ;
                    SET_BIT(Port->GPIODR_2_4_8R[Conf_Pins[counter].PIN_OUTPUT_CURRENT], Conf_Pins[counter].PIN_NO);
                }
                else if (Conf_Pins[counter].PIN_DIR == GPIO_INPUT)
                {
                    CLR_BIT(Port->GPIODIR,Conf_Pins[counter].PIN_NO) ;
                    SET_BIT(Port->GPIO_ODR_PUR_PDR[Conf_Pins[counter].PIN_INTERNAL_ATTACH], Conf_Pins[counter].PIN_NO);

                }

            break ;


            case Alt_Function :
                SET_BIT(Port->GPIOAFSEL,Conf_Pins[counter].PIN_NO);
                CLR_BIT(Port->GPIODEN,Conf_Pins[counter].PIN_NO) ;
                CLR_BIT(Port->GPIOAMSEL,Conf_Pins[counter].PIN_NO);
                Port->GPIOPCTL |=(Conf_Pins[counter].ALT_FUNC_T<<(4* Conf_Pins[counter].PIN_NO)) ;
            break ;


            case Analog_Function :
                SET_BIT(Port->GPIOAFSEL,Conf_Pins[counter].PIN_NO);
                CLR_BIT(Port->GPIODEN,Conf_Pins[counter].PIN_NO) ;
                SET_BIT(Port->GPIOAMSEL,Conf_Pins[counter].PIN_NO);
            break ;


            case Ext_Interrupt :
                Port->GPIOIS |= Conf_Pins[counter].PIN_INT_SENSE<<Conf_Pins[counter].PIN_NO ;
                Port->GPIOIBE |= Conf_Pins[counter].PIN_INT_BOTH_EDGES<<Conf_Pins[counter].PIN_NO  ;
                Port->GPIOIEV |= Conf_Pins[counter].PIN_INT_EVENT_TYPE<<Conf_Pins[counter].PIN_NO ;
            break ;

            default :
			break ;
        }
        
    }
    




	

}

/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/
