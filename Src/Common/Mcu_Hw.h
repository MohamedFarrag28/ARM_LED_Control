/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Private.h
 *       Module:  -
 *
 *  Description:  header file for Registers definition 
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_PRIVATE_H
#define INTCTRL_PRIVATE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Platform_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/* SYSTICK Register type */
typedef struct
{
    uint32 STCTRL ;
    uint32 STRELOAD ;
    uint32 STCURRENT ;
}SYSTICK_REG_t;

 /*	NVIC Registers types	*/
typedef struct
{
    uint32 N[5] ;
}NVIC_REG_t;

typedef struct
{
    uint32 N[35] ;
}NVIC_REG_PRI_t;


 /*	SCB Register types	*/
typedef struct
{
    uint32 CPUID ;
    uint32 INTCTRL ;
    uint32 VTABLE ; 
    uint32 APINT ;
    uint32 SYSCTRL ;
    uint32 CFGCTRL ;
    uint32 SYSPRI1 ;
    uint32 SYSPRI2 ;
    uint32 SYSPRI3 ;
    uint32 SYSHNDCTRL ;
    uint32 FAULTSTAT ;
    uint32 HFAULTSTAT ;
    uint32 RESERVED ;
    uint32 MMADDR ;
    uint32 FAULTADDR ;

}SCB_REG_t ;


typedef struct
{
    uint32 RCGCWD ;
    uint32 RCGCTIMER ;
    uint32 RCGCGPIO;
    uint32 RCGCDMA;
    uint32 RES1 ;
    uint32 RCGCHIB;
    uint32 RCGCUART;
    uint32 RCGCSSI ;
    uint32 RCGCI2C ;
    uint32 RES2 ;
    uint32 RCGCUSB;
    uint32 RES3[2] ;
    uint32 RCGCCAN ;
    uint32 RCGCADC ;
    uint32 RCGCACMP ;
    uint32 RCGCPWM ;
    uint32 RCGCQEI;
    uint32 RES4[4] ;
    uint32 RCGCEEPROM ;
    uint32 RCGCWTIMER ;


}SYS_CTRL_REG_t ;

/* GPIO Registers type */


typedef struct{

    uint32 GPIODATA[256];
    uint32 GPIODIR;
    uint32 GPIOIS;
    uint32 GPIOIBE;
    uint32 GPIOIEV;
    uint32 GPIOIM;
    uint32 GPIORIS;
    uint32 GPIOMIS;
    uint32 GPIOICR;
    uint32 GPIOAFSEL;
    uint32 Reserved[55];
    uint32 GPIODR_2_4_8R[3];
    uint32 GPIO_ODR_PUR_PDR[3] ;
    uint32 GPIOSLR ;
    uint32 GPIODEN;
    uint32 GPIOLOCK;
    uint32 GPIOCR;
    uint32 GPIOAMSEL;
    uint32 GPIOPCTL;
    uint32 GPIOADCCTL;
    uint32 GPIODMACTL;

}GPIO_PRE_REG_t;



/* GPT Registers type */


typedef struct
{

    uint32 GPTMCFG;
    uint32 GPTMTAMR;
    uint32 GPTMTBMR;
    uint32 GPTMCTL;
    uint32 GPTMSYNC;
    uint32 RES_1;
    uint32 GPTMIMR;
    uint32 GPTMRIS;
    uint32 GPTMMIS;
    uint32 GPTMICR;
    uint32 GPTMTAILR;
    uint32 GPTMTBILR;
    uint32 GPTMTAMATCHR;
    uint32 GPTMTBMATCHR;
    uint32 GPTMTAPR;
    uint32 GPTMTBPR;
    uint32 GPTMTAPMR;
    uint32 GPTMTBPMR;
    uint32 GPTMTAR;
    uint32 GPTMTBR;
    uint32 GPTMTAV;
    uint32 GPTMTBV;
    uint32 GPTMRTCPD;
    uint32 GPTMTAPS;
    uint32 GPTMTBPS;
    uint32 GPTMTAPV;
    uint32 GPTMTBPV;

}GPT_REG_t;


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/



/* BASE_ADDRESS	*/

#define CORTEXM4_PERI_BASE_ADDRESS              0xE000E000
#define SYSTEM_CONTROL_BASE_ADDRESS             0x400FE000

#define GPIO_PORTA_BASE_ADDRESS_APB             0x40004000
#define GPIO_PORTB_BASE_ADDRESS_APB             0x40005000
#define GPIO_PORTC_BASE_ADDRESS_APB             0x40006000
#define GPIO_PORTD_BASE_ADDRESS_APB             0x40007000
#define GPIO_PORTE_BASE_ADDRESS_APB             0x40024000
#define GPIO_PORTF_BASE_ADDRESS_APB             0x40025000

#define GPIO_PORTA_BASE_ADDRESS_AHB             0x40058000
#define GPIO_PORTB_BASE_ADDRESS_AHB             0x40059000
#define GPIO_PORTC_BASE_ADDRESS_AHB             0x4005A000
#define GPIO_PORTD_BASE_ADDRESS_AHB             0x4005B000
#define GPIO_PORTE_BASE_ADDRESS_AHB             0x4005C000
#define GPIO_PORTF_BASE_ADDRESS_AHB             0x4005D000



#define GPT_16_32_TIM_0_BASE_ADDRESS           0x40030000
#define GPT_16_32_TIM_1_BASE_ADDRESS           0x40031000
#define GPT_16_32_TIM_2_BASE_ADDRESS           0x40032000
#define GPT_16_32_TIM_3_BASE_ADDRESS           0x40033000
#define GPT_16_32_TIM_4_BASE_ADDRESS           0x40034000
#define GPT_16_32_TIM_5_BASE_ADDRESS           0x40035000

#define GPT_32_64_WIDE_TIM_0_BASE_ADDRESS      0x40036000
#define GPT_32_64_WIDE_TIM_1_BASE_ADDRESS      0x40037000
#define GPT_32_64_WIDE_TIM_2_BASE_ADDRESS      0x4004C000
#define GPT_32_64_WIDE_TIM_3_BASE_ADDRESS      0x4004D000
#define GPT_32_64_WIDE_TIM_4_BASE_ADDRESS      0x4004E000
#define GPT_32_64_WIDE_TIM_5_BASE_ADDRESS      0x4004F000


/*SYSTICK REGISTERs */
#define SYSTICK_REG                     ((volatile SYSTICK_REG_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x010))


/*	NVIC Registers	*/
#define NVIC_REG_EN                     ((volatile NVIC_REG_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define NVIC_REG_DIS                    ((volatile NVIC_REG_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x180))               
#define NVIC_REG_PEND                   ((volatile NVIC_REG_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x200))               
#define NVIC_REG_UNPEND                 ((volatile NVIC_REG_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x280))               
#define NVIC_REG_ACTIVE                 ((volatile NVIC_REG_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x300))               
#define NVIC_REG_PRI                    ((volatile NVIC_REG_PRI_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x400))               
#define NVIC_REG_SWTRIG                 ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xF00))               

/* SCB REGISTERS     */
#define SCB_REG_ACTLR                   ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x008))               
#define SCB_REG                         ((volatile SCB_REG_t*)(CORTEXM4_PERI_BASE_ADDRESS+0xD00))



/* SYSCTRL REGISTERS */

#define SYSCTRL_REG_RCC                 *((volatile uint32*)(SYSTEM_CONTROL_BASE_ADDRESS+0x060)) 
#define SYSCTRL_REG                      ((volatile SYS_CTRL_REG_t*)(SYSTEM_CONTROL_BASE_ADDRESS+0x600))

/* GPIO REGISTERs    */

#define GPIO_PORTA_REG                  ((volatile GPIO_PRE_REG_t*)(GPIO_PORTA_BASE_ADDRESS_APB))
#define GPIO_PORTB_REG                  ((volatile GPIO_PRE_REG_t*)(GPIO_PORTB_BASE_ADDRESS_APB))
#define GPIO_PORTC_REG                  ((volatile GPIO_PRE_REG_t*)(GPIO_PORTC_BASE_ADDRESS_APB))
#define GPIO_PORTD_REG                  ((volatile GPIO_PRE_REG_t*)(GPIO_PORTD_BASE_ADDRESS_APB))
#define GPIO_PORTE_REG                  ((volatile GPIO_PRE_REG_t*)(GPIO_PORTE_BASE_ADDRESS_APB))
#define GPIO_PORTF_REG                  ((volatile GPIO_PRE_REG_t*)(GPIO_PORTF_BASE_ADDRESS_APB))

/* GPT REGISTERs    */

#define GPT_16_32_TIM0_REG                  ((volatile GPT_REG_t*)(GPT_16_32_TIM_0_BASE_ADDRESS))
#define GPT_16_32_TIM1_REG                  ((volatile GPT_REG_t*)(GPT_16_32_TIM_1_BASE_ADDRESS))
#define GPT_16_32_TIM2_REG                  ((volatile GPT_REG_t*)(GPT_16_32_TIM_2_BASE_ADDRESS))
#define GPT_16_32_TIM3_REG                  ((volatile GPT_REG_t*)(GPT_16_32_TIM_3_BASE_ADDRESS))
#define GPT_16_32_TIM4_REG                  ((volatile GPT_REG_t*)(GPT_16_32_TIM_4_BASE_ADDRESS))
#define GPT_16_32_TIM5_REG                  ((volatile GPT_REG_t*)(GPT_16_32_TIM_5_BASE_ADDRESS))



#define GPT_32_64_TIM0_REG                  ((volatile GPT_REG_t*)(GPT_32_64_WIDE_TIM_0_BASE_ADDRESS))
#define GPT_32_64_TIM1_REG                  ((volatile GPT_REG_t*)(GPT_32_64_WIDE_TIM_1_BASE_ADDRESS))
#define GPT_32_64_TIM2_REG                  ((volatile GPT_REG_t*)(GPT_32_64_WIDE_TIM_2_BASE_ADDRESS))
#define GPT_32_64_TIM3_REG                  ((volatile GPT_REG_t*)(GPT_32_64_WIDE_TIM_3_BASE_ADDRESS))
#define GPT_32_64_TIM4_REG                  ((volatile GPT_REG_t*)(GPT_32_64_WIDE_TIM_4_BASE_ADDRESS))
#define GPT_32_64_TIM5_REG                  ((volatile GPT_REG_t*)(GPT_32_64_WIDE_TIM_5_BASE_ADDRESS))



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* INTCTRL_PRIVATE_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Private.h
 *********************************************************************************************************************/
