/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SYS_Ctrl_types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef SYS_CTRL_TYPES_H
#define SYS_CTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define    MOSC_MAIN_OSCILLATOR_16_MHZ						0
#define    PIOSC_PRECISION_INTERNAL_OSCILLATOR		        1
#define    PIOSC_4_PRECISION_INTERNALL_OSCILLATOR           2
#define    LIFOSC_LOW_FREQ_INTERNAL_OSCILLATOR		        3

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define     DISABLED		    0
#define     ENABLED			    1

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{

    MAIN_OSCILLATOR_16_MHZ	,
    PRECISION_INTERNAL_OSCILLATOR ,
    RECISION_INTERNALL_OSCILLATOR_4 ,
    LOW_FREQ_INTERNAL_OSCILLATOR ,

}Clock_Source_t;


typedef enum{
    CRYSTAL_VALUE_4MHZ_PPLRESERVED = 6 ,
    CRYSTAL_VALUE_4_096MHZ_PPLRESERVED ,
    CRYSTAL_VALUE_4_9152MHZ_PPLRESERVED ,
    CRYSTAL_VALUE_5_MHz_USB,
    CRYSTAL_VALUE_5_12_MHz,
    CRYSTAL_VALUE_6_MHz_USB,
    CRYSTAL_VALUE_6_144_MHz,
    CRYSTAL_VALUE_7_3728_MHz,
    CRYSTAL_VALUE_8_MHz_USB,
    CRYSTAL_VALUE_8_192_MHz,
    CRYSTAL_VALUE_10_MHz_USB,
    CRYSTAL_VALUE_12_MHz_USB,
    CRYSTAL_VALUE_12_288_MHz,
    CRYSTAL_VALUE_13_56_MHz,
    CRYSTAL_VALUE_14_31818_MHz,
    CRYSTAL_VALUE_16_MHz_USB,
    CRYSTAL_VALUE_16_384_MHz,
    CRYSTAL_VALUE_18_MHz_USB,
    CRYSTAL_VALUE_20_MHz_USB,
    CRYSTAL_VALUE_24_MHz_USB,
    CRYSTAL_VALUE_25_MHz_USB

}CRYSTAL_VALUE_t;


typedef enum{
    SYSCTL_SYSDIV_DIV1_RESERVED  ,
    SYSCTL_SYSDIV_DIV2_RESERVED ,
    SYSCTL_SYSDIV_DIV3_66_67MHZ ,
    SYSCTL_SYSDIV_DIV4_50MHZ ,
    SYSCTL_SYSDIV_DIV5_40MHZ ,
    SYSCTL_SYSDIV_DIV6_33_33MHZ ,
    SYSCTL_SYSDIV_DIV7_28_57MHZ ,
    SYSCTL_SYSDIV_DIV8_25MHZ ,
    SYSCTL_SYSDIV_DIV9_22_22MHZ ,
    SYSCTL_SYSDIV_DIV10_20MHZ , 
    SYSCTL_SYSDIV_DIV11_18_18MHZ ,
    SYSCTL_SYSDIV_DIV12_16_67MHZ ,
    SYSCTL_SYSDIV_DIV13_15_38MHZ ,
    SYSCTL_SYSDIV_DIV14_14_29MHZ ,
    SYSCTL_SYSDIV_DIV15_13_33MHZ ,
    SYSCTL_SYSDIV_DIV16_12_5MHZ ,

}SYSTEM_CLOCK_DIVISOR_t;


typedef enum{

    SYSCTL_PWM_DIV_2,
    SYSCTL_PWM_DIV_4,
    SYSCTL_PWM_DIV_8,
    SYSCTL_PWM_DIV_16,
    SYSCTL_PWM_DIV_32,
    SYSCTL_PWM_DIV_64,

}PWM_UNIT_CLOCK_DIVISOR_t;

 
#endif  /* SYS_Ctrl_types_H */

/**********************************************************************************************************************
 *  END OF FILE: SYS_Ctrl_types.h
 *********************************************************************************************************************/
