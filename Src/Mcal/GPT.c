/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  GPT.c
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
#include "Inc/GPT.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
	
volatile GPT_REG_t* Local_GPT_arr[12] = {GPT_16_32_TIM0_REG,GPT_16_32_TIM1_REG,GPT_16_32_TIM2_REG,GPT_16_32_TIM3_REG
                                ,GPT_16_32_TIM4_REG,GPT_16_32_TIM5_REG,GPT_32_64_TIM0_REG ,GPT_32_64_TIM1_REG
                                ,GPT_32_64_TIM2_REG,GPT_32_64_TIM3_REG,GPT_32_64_TIM4_REG,GPT_32_64_TIM5_REG };


static void (*GPT_ISR[12])(void) = {NULL_PTR}; /*For channel A */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
void TIMER0A_Handler(void)
{
    if(GPT_ISR[0]!= NULL_PTR)
    {
        GPT_ISR[0]() ;
    }
}


void TIMER1A_Handler(void)
{
    if(GPT_ISR[1]!= NULL_PTR)
    {
        GPT_ISR[1]() ;
    }
}


void TIMER2A_Handler(void)
{
    if(GPT_ISR[2]!= NULL_PTR)
    {
        GPT_ISR[2]() ;
    }
}


void TIMER3A_Handler(void)
{
    if(GPT_ISR[3]!= NULL_PTR)
    {
        GPT_ISR[3]() ;
    }
}


void TIMER4A_Handler(void)
{
    if(GPT_ISR[4]!= NULL_PTR)
    {
        GPT_ISR[4]() ;
    }
}


void TIMER5A_Handler(void)
{
    if(GPT_ISR[5]!= NULL_PTR)
    {
        GPT_ISR[5]() ;
    }
}



void WTIMER0A_Handler(void)
{
    if(GPT_ISR[6]!= NULL_PTR)
    {
        GPT_ISR[6]() ;
    }
}


void WTIMER1A_Handler(void)
{
    if(GPT_ISR[7]!= NULL_PTR)
    {
        GPT_ISR[7]() ;
    }
}


void WTIMER2A_Handler(void)
{
    if(GPT_ISR[8]!= NULL_PTR)
    {
        GPT_ISR[8]() ;
    }
}


void WTIMER3A_Handler(void)
{
    if(GPT_ISR[9]!= NULL_PTR)
    {
        GPT_ISR[9]() ;
    }
}


void WTIMER4A_Handler(void)
{
    if(GPT_ISR[10]!= NULL_PTR)
    {
        GPT_ISR[10]() ;
    }
}


void WTIMER5A_Handler(void)
{
    if(GPT_ISR[11]!= NULL_PTR)
    {
        GPT_ISR[11]() ;
    }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/



void GPT_Init(const GPT_Config_t* copy_Config_Ptr) 
{
    /* channel disable */
    Local_GPT_arr[copy_Config_Ptr->Channel_id]->GPTMCTL &= ~(0x1) ;
    /* set timer config /bits num */
    Local_GPT_arr[copy_Config_Ptr->Channel_id]->GPTMCFG &= ~(0x7) ;  /* clear first */
    Local_GPT_arr[copy_Config_Ptr->Channel_id]->GPTMCFG = copy_Config_Ptr->Bits_Num ;

    /* set channel mode /Periodic-OneShot */
    Local_GPT_arr[copy_Config_Ptr->Channel_id]->GPTMTAMR &= (0x3) ;  /* clear first */
    Local_GPT_arr[copy_Config_Ptr->Channel_id]->GPTMTAMR |= copy_Config_Ptr->Channel_Mode ;

    /* set call back function */
    GPT_ISR[copy_Config_Ptr->Channel_id] = copy_Config_Ptr->Call_Back ;
    

}

void GPT_DisableNotification(GPT_Channel_t copy_Channel)
{

    CLR_BIT(Local_GPT_arr[copy_Channel]->GPTMIMR,0) ;
}

void GPT_EnableNotification(GPT_Channel_t copy_Channel)
{   
    if (GPT_ISR[copy_Channel] != NULL_PTR )
        SET_BIT(Local_GPT_arr[copy_Channel]->GPTMIMR,0) ;
}

void GPT_StartTimer(GPT_Channel_t copy_Channel,GPT_Value_t copy_Value)
{
    /* load the starting count value */
    Local_GPT_arr[copy_Channel]->GPTMTAILR = copy_Value ;

    /* Enable channel*/

    SET_BIT(Local_GPT_arr[copy_Channel]->GPTMCTL,0);
}

void GPT_StopTimer(GPT_Channel_t copy_Channel)
{
    CLR_BIT(Local_GPT_arr[copy_Channel]->GPTMCTL,0);
} 


GPT_Value_t GPT_GetTimeElapsed(GPT_Channel_t copy_Channel)
{
    GPT_Value_t local_val = (Local_GPT_arr[copy_Channel]->GPTMTAILR) - (Local_GPT_arr[copy_Channel]->GPTMTAV);

    return local_val ;
}


GPT_Value_t GPT_GetTimeRemaining(GPT_Channel_t copy_Channel)
{

    return (Local_GPT_arr[copy_Channel]->GPTMTAV);
}


/**********************************************************************************************************************
 *  END OF FILE: GPT.c
 *********************************************************************************************************************/
