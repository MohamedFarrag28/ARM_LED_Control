/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SYS_Ctrl.c
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
#include "../Config/SYS_Ctrl_Cfg.h"
#include "Inc/SYS_Ctrl.h"
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void SYS_Ctrl(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
//SYSCTRL_REG_RCC
void Sys_Ctrl_Init(void)
{

    #if CLOCK_SRC == MAIN_OSCILLATOR_16_MHZ
    /*enable Main Oscillator  */
    CLR_BIT(SYSCTRL_REG_RCC,0) ;
    /* select Oscillator Source */
    CLR_BIT(SYSCTRL_REG_RCC,4) ;
    CLR_BIT(SYSCTRL_REG_RCC,5) ;

    /*select crystal value  */

    // clear it first then write
    SYSCTRL_REG_RCC &= ~(0x1F<<6) ;
    SYSCTRL_REG_RCC |= (CRYSTAL_VALUE<<6);

    #elif CLOCK_SRC == PRECISION_INTERNAL_OSCILLATOR
    SYSCTRL_REG_RCC &= ~(3<<4) ;
    SYSCTRL_REG_RCC |= (1<<4) ;

    #elif CLOCK_SRC == RECISION_INTERNALL_OSCILLATOR_4
    SYSCTRL_REG_RCC &= ~(3<<4) ;
    SYSCTRL_REG_RCC |= (2<<4) ;
    #elif CLOCK_SRC == LOW_FREQ_INTERNAL_OSCILLATOR
    SYSCTRL_REG_RCC &= ~(3<<4) ;
    SYSCTRL_REG_RCC |= (3<<4) ;

    #endif

    /* check ppl */

    #if PLL_BYPASS == ENABLED 
    CLR_BIT(SYSCTRL_REG_RCC,13) ;
    CLR_BIT(SYSCTRL_REG_RCC,11) ;

    #elif PLL_BYPASS == DISABLED
    SET_BIT(SYSCTRL_REG_RCC,13) ;
    SET_BIT(SYSCTRL_REG_RCC,11) ;
    #endif

    /* check sysdiv */ 

    #if SYSTEM_CLOCK_DIVISOR_STATE == ENABLED
    SET_BIT(SYSCTRL_REG_RCC,22) ;
    // clear divisor  first then write on it 
    SYSCTRL_REG_RCC &= ~(0xF<<23) ;
    SYSCTRL_REG_RCC |= ~(SYSTEM_CLOCK_DIVISOR<<23) ;

    #endif 

    #if PWM_CLOCK_DIVISOR_STATE == ENABLED
    SET_BIT(SYSCTRL_REG_RCC,20) ;
    // clear divisor  first then write on it 
    SYSCTRL_REG_RCC &= ~(7<<17) ;
    SYSCTRL_REG_RCC |= ~(PWM_CLOCK_DIVISOR<<17) ;
    #endif


    SYSCTRL_REG->RCGCWD     |= (Watchdog_0_CLK_GATE<<0)|(Watchdog_1_CLK_GATE<<1) ;
    SYSCTRL_REG->RCGCTIMER  |= (TMR0_16_32_CLK_GATE<<0) | (TMR1_16_32_CLK_GATE<<1) |(TMR2_16_32_CLK_GATE<<2)|(TMR3_16_32_CLK_GATE<<3)
                                |(TMR4_16_32_CLK_GATE<<4) |(TMR5_16_32_CLK_GATE<<5) ;
    SYSCTRL_REG->RCGCGPIO   |= (GPIOA_CLK_GATE<<0) | (GPIOB_CLK_GATE<<1) |(GPIOC_CLK_GATE<<2)|(GPIOD_CLK_GATE<<3)|(GPIOE_CLK_GATE<<4)
                                |(GPIOF_CLK_GATE<<5)  ;
    SYSCTRL_REG->RCGCDMA    |= (UDMA_CLK_GATE<<0) ; 
    SYSCTRL_REG->RCGCHIB    |= (HIB_CLK_GATE<<0);
    SYSCTRL_REG->RCGCUART   |= (UART0_CLK_GATE<<0) | (UART1_CLK_GATE<<1)|(UART2_CLK_GATE<<2)|(UART3_CLK_GATE<<3)|(UART4_CLK_GATE<<4)
                                |(UART5_CLK_GATE<<5)|(UART6_CLK_GATE<<6)|(UART7_CLK_GATE<<7) ;
    SYSCTRL_REG->RCGCSSI    |= (SSI0_CLK_GATE<<0) | (SSI1_CLK_GATE<<1) | (SSI2_CLK_GATE<<2) | (SSI3_CLK_GATE<<3) ;
    SYSCTRL_REG->RCGCI2C    |= (I2C0_CLK_GATE<<0) | (I2C1_CLK_GATE<<1) | (I2C2_CLK_GATE<<2) | (I2C3_CLK_GATE<<3) ;
    SYSCTRL_REG->RCGCUSB    |= (USB_CLK_GATE<<0);
    SYSCTRL_REG->RCGCCAN    |= (CAN0_CLK_GATE<<0) | (CAN1_CLK_GATE<<1) ;
    SYSCTRL_REG->RCGCADC    |= (ADC0_CLK_GATE<<0) | (ADC1_CLK_GATE<<1) ;
    SYSCTRL_REG->RCGCACMP   |= (ACMP_CLK_GATE<<0) ;
    SYSCTRL_REG->RCGCPWM    |= (PWM0_CLK_GATE<<0) | (PWM0_CLK_GATE<<1) ;
    SYSCTRL_REG->RCGCQEI    |= (QEI0_CLK_GATE<<0) | (QEI1_CLK_GATE<<1) ;
    SYSCTRL_REG->RCGCEEPROM |= (EEPROM_CLK_GATE<<0) ;
    SYSCTRL_REG->RCGCWTIMER |= (TMR0_32_64_CLK_GATE<<0) | (TMR1_32_64_CLK_GATE<<1) | (TMR2_32_64_CLK_GATE<<2) | (TMR3_32_64_CLK_GATE<<3)
                                |(TMR4_32_64_CLK_GATE<<4) | (TMR5_32_64_CLK_GATE<<5) ;

}


/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
