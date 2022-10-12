/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"




/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    GPIO_Port_A ,
    GPIO_Port_B ,
    GPIO_Port_C ,
    GPIO_Port_D ,
    GPIO_Port_E ,
    UART_0 ,
    UART_1 ,
    SSI0 ,
    I2C_0 ,
    PWM0_Fault ,
    PWM0_Generator_0 ,
    PWM0_Generator_1 ,
    PWM0_Generator_2 ,
    QEI0 ,
    ADC0_Sequence_0 ,
    ADC0_Sequence_1 ,
    ADC0_Sequence_2 ,
    ADC0_Sequence_3 ,
    Watchdog_Timers_0_and_1 ,
    Timer0_A_16_32_bit ,
    Timer0_B_16_32_bit ,
    Timer1_A_16_32_bit ,
    Timer1_B_16_32_bit ,
    Timer2_A_16_32_bit ,
    Timer2_B_16_32_bit ,
    Analog_Comparator_0 ,
    Analog_Comparator_1 ,
    System_Control = 28 ,
    Flash_Memory_and_EEPROM_Control ,
    GPIO_Port_F ,
    UART_2 = 33 ,
    SSI_1 ,
    Timer3_A_16_32_bit ,
    Timer3_B_16_32_bit ,
    I2C_1 ,
    QEI_1 ,
    CAN_0 ,
    CAN_1 ,
    Hibernation_Module =43 ,
    USB ,
    PWM_Generator_3 ,
    UDMA_Software ,
    UDMA_Error ,
    ADC1_Sequence_0 ,
    ADC1_Sequence_1 ,
    ADC1_Sequence_2 ,
    ADC1_Sequence_3 ,
    SSI_2 =57 ,
    SSI_3 ,
    UART_3 ,
    UART_4 ,
    UART_5 ,
    UART_6 ,
    UART_7 ,
    I2C_2 =68 ,
    I2C_3 ,
    Timer4_A_16_32_bit ,
    Timer4_B_16_32_bit ,
    Timer5_A_16_32_bit = 92 ,
    Timer5_B_16_32_bit ,
    Timer0_A_32_64_bit ,
    Timer0_B_32_64_bit ,
    Timer1_A_32_64_bit ,
    Timer1_B_32_64_bit ,
    Timer2_A_32_64_bit ,
    Timer2_B_32_64_bit ,
    Timer3_A_32_64_bit ,
    Timer3_B_32_64_bit ,
    Timer4_A_32_64_bit ,
    Timer4_B_32_64_bit ,
    Timer5_A_32_64_bit ,
    Timer5_B_32_64_bit ,
    System_Exception ,
    PWM1_Generator_0 =134 ,
    PWM1_Generator_1 ,
    PWM1_Generator_2 ,
    PWM1_Generator_3 ,
    PWM1_Fault ,

}IntCtrl_InterruptType;

 typedef enum{
	SCB_EXCEPTION_MEMORY_MANAGE_FAULT ,
	SCB_EXCEPTION_BUS_FAULT,
	SCB_EXCEPTION_USAGE_FAULT,
    SCB_EXCEPTION_SVCALL ,
    SCB_EXCEPTION_DEBUG_MONITOR ,
}SCB_Exception_t;


#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
