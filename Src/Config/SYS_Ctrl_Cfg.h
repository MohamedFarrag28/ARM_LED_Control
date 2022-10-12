/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SYS_CTRL_CFG.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef SYS_CTRL_CFG_H
#define SYS_CTRL_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/*	
	Options:
	MAIN_OSCILLATOR_16_MHZ	
    PRECISION_INTERNAL_OSCILLATOR 
    RECISION_INTERNALL_OSCILLATOR_4 
    LOW_FREQ_INTERNAL_OSCILLATOR 
*/

#define CLOCK_SRC   MAIN_OSCILLATOR_16_MHZ

/*	
    Options:
	CRYSTAL_VALUE_4MHZ_PPLRESERVED 
    CRYSTAL_VALUE_4_096MHZ_PPLRESERVED 
    CRYSTAL_VALUE_4_9152MHZ_PPLRESERVED 
    CRYSTAL_VALUE_5_MHz_USB
    CRYSTAL_VALUE_5_12_MHz
    CRYSTAL_VALUE_6_MHz_USB
    CRYSTAL_VALUE_6_144_MHz
    CRYSTAL_VALUE_7_3728_MHz
    CRYSTAL_VALUE_8_MHz_USB
    CRYSTAL_VALUE_8_192_MHz
    CRYSTAL_VALUE_10_MHz_USB
    CRYSTAL_VALUE_12_MHz_USB
    CRYSTAL_VALUE_12_288_MHz
    CRYSTAL_VALUE_13_56_MHz
    CRYSTAL_VALUE_14_31818_MHz
    CRYSTAL_VALUE_16_MHz_USB
    CRYSTAL_VALUE_16_384_MHz
    CRYSTAL_VALUE_18_MHz_USB
    CRYSTAL_VALUE_20_MHz_USB
    CRYSTAL_VALUE_24_MHz_USB
    CRYSTAL_VALUE_25_MHz_USB
*/

#define CRYSTAL_VALUE   CRYSTAL_VALUE_16_MHz_USB



/*	
	Options:

    ENABLED
    DISABLED
*/

#define PLL_BYPASS  ENABLED

#define  SYSTEM_CLOCK_DIVISOR_STATE ENABLED


#if SYSTEM_CLOCK_DIVISOR_STATE == ENABLED
/*
    SYSCTL_SYSDIV_DIV1_RESERVED  
    SYSCTL_SYSDIV_DIV2_RESERVED 
    SYSCTL_SYSDIV_DIV3_66_67MHZ 
    SYSCTL_SYSDIV_DIV4_50MHZ 
    SYSCTL_SYSDIV_DIV5_40MHZ 
    SYSCTL_SYSDIV_DIV6_33_33MHZ 
    SYSCTL_SYSDIV_DIV7_28_57MHZ 
    SYSCTL_SYSDIV_DIV8_25MHZ 
    SYSCTL_SYSDIV_DIV9_22_22MHZ 
    SYSCTL_SYSDIV_DIV10_20MHZ 
    SYSCTL_SYSDIV_DIV11_18_18MHZ 
    SYSCTL_SYSDIV_DIV12_16_67MHZ 
    SYSCTL_SYSDIV_DIV13_15_38MHZ 
    SYSCTL_SYSDIV_DIV14_14_29MHZ 
    SYSCTL_SYSDIV_DIV15_13_33MHZ 
    SYSCTL_SYSDIV_DIV16_12_5MHZ 
*/

#define SYSTEM_CLOCK_DIVISOR       SYSCTL_SYSDIV_DIV16_12_5MHZ
#endif

/*  
    options :

    DISABLED
    ENABLED
*/
#define PWM_CLOCK_DIVISOR_STATE     DISABLED

#if PWM_CLOCK_DIVISOR_STATE == ENABLED

/*  
    options :
    
    SYSCTL_PWM_DIV_2
    SYSCTL_PWM_DIV_4
    SYSCTL_PWM_DIV_8
    SYSCTL_PWM_DIV_16
    SYSCTL_PWM_DIV_32
    SYSCTL_PWM_DIV_64
*/

#define PWM_CLOCK_DIVISOR   PWM_CLOCK_DIVISOR_64

#endif


/*Configuration of Run Mode Clock Gating  */


#define Watchdog_0_CLK_GATE            ENABLED
#define Watchdog_1_CLK_GATE            ENABLED
#define TMR0_16_32_CLK_GATE            ENABLED
#define TMR1_16_32_CLK_GATE            ENABLED
#define TMR2_16_32_CLK_GATE            ENABLED
#define TMR3_16_32_CLK_GATE            ENABLED
#define TMR4_16_32_CLK_GATE            ENABLED
#define TMR5_16_32_CLK_GATE            ENABLED
#define GPIOA_CLK_GATE                 ENABLED
#define GPIOB_CLK_GATE                 ENABLED
#define GPIOC_CLK_GATE                 ENABLED
#define GPIOD_CLK_GATE                 ENABLED
#define GPIOE_CLK_GATE                 ENABLED
#define GPIOF_CLK_GATE                 ENABLED
#define UDMA_CLK_GATE                  ENABLED
#define HIB_CLK_GATE                   ENABLED
#define UART0_CLK_GATE                 ENABLED
#define UART1_CLK_GATE                 ENABLED
#define UART2_CLK_GATE                 ENABLED
#define UART3_CLK_GATE                 ENABLED
#define UART4_CLK_GATE                 ENABLED
#define UART5_CLK_GATE                 ENABLED
#define UART6_CLK_GATE                 ENABLED
#define UART7_CLK_GATE                 ENABLED
#define SSI0_CLK_GATE                  ENABLED
#define SSI1_CLK_GATE                  ENABLED
#define SSI2_CLK_GATE                  ENABLED
#define SSI3_CLK_GATE                  ENABLED
#define I2C0_CLK_GATE                  ENABLED
#define I2C1_CLK_GATE                  ENABLED
#define I2C2_CLK_GATE                  ENABLED
#define I2C3_CLK_GATE                  ENABLED
#define USB_CLK_GATE                   ENABLED
#define CAN0_CLK_GATE                  ENABLED
#define CAN1_CLK_GATE                  ENABLED
#define ADC0_CLK_GATE                  ENABLED
#define ADC1_CLK_GATE                  ENABLED
#define ACMP_CLK_GATE                  ENABLED
#define PWM0_CLK_GATE                  ENABLED
#define PWM1_CLK_GATE                  ENABLED
#define QEI0_CLK_GATE                  ENABLED
#define QEI1_CLK_GATE                  ENABLED
#define EEPROM_CLK_GATE                ENABLED
#define TMR0_32_64_CLK_GATE            ENABLED
#define TMR1_32_64_CLK_GATE            ENABLED
#define TMR2_32_64_CLK_GATE            ENABLED
#define TMR3_32_64_CLK_GATE            ENABLED
#define TMR4_32_64_CLK_GATE            ENABLED
#define TMR5_32_64_CLK_GATE            ENABLED



#endif  /* INTCTRL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/
