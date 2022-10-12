/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SYS_TICK.c
 *        \brief  
 *
 *      \details  
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "../Common/Std_Types.h"
#include "../Common/Compiler.h"
#include "../Common/Platform_Types.h"
#include "../Common/Bit_Math.h"
#include "../Common/Mcu_Hw.h"
#include "../Config/SYS_TICK_Cfg.h"
#include "Inc/SYS_TICK.h"
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
static void (*SYS_TICK_ISR)(void) = NULL_PTR;


/******************************************************************************
* \Syntax          : void SYS_Ctrl(void)                                      
* \Description     : initialize SYSTICK Module by parsing the Configuration 
*                    into SYSTICK registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
//SYSCTRL_REG_RCC
void Sys_Tick_Init(float32 Copy_f32time_in_second)
{
	# if SYSTICK_CLK_SRC == SYSTICK_CLK_PIOSC_DIV_4
    uint32 Local_u32Val = ((Copy_f32time_in_second*16000000)-1) ;

	#elif SYSTICK_CLK_SRC == SYSTICK_CLK_SYSCLK
	uint32 Local_u32Val = ((Copy_f32time_in_second*CLK_SYSCLK_FREQ)-1) ;


	#endif

		SYSTICK_REG->STRELOAD |= (Local_u32Val&0x00FFFFFF) ;
	
    SYSTICK_REG->STCTRL = SYSTICK_CLK_SRC<<2 |SYSTICK_STATE<<0 |SYSTICK_INTERRUPT<<1 ;
		
    
}


void Sys_Tick_SetCallBack(void(* Call_Back)(void)) 
{
	
	SYS_TICK_ISR =  Call_Back ;
	
}

void SysTick_Handler(void)
{
	if (SYS_TICK_ISR != 0 )
	{
		SYS_TICK_ISR() ;
	}

}

void Sys_Tick_DisableNotification(void)
{
	CLR_BIT(SYSTICK_REG->STCTRL,1);
}

void Sys_Tick_EnableNotification(void)
{
	SET_BIT(SYSTICK_REG->STCTRL,1);
}


void Sys_Tick_SetReloadValue(uint32 copy_Value)
{
	SYSTICK_REG->STRELOAD &= ~(0x00FFFFFF) ;
	SYSTICK_REG->STRELOAD |= (copy_Value&0x00FFFFFF) ;
}






/**********************************************************************************************************************
 *  END OF FILE: SYS_TICK.c
 *********************************************************************************************************************/
