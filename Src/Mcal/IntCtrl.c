/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../Common/Std_Types.h"
#include "../Common/Platform_Types.h"
#include "Inc/IntCtrl.h"
#include "../Common/Bit_Math.h"
#include "../Common/Mcu_Hw.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern const uint32 NUM_ACT_GROUPS;
extern PRI_CONFIG_t IntCtrl_GroupingConfig  ;
extern Interrupt_Cfg_t Interrupt_Groups[] ;
extern sys_Interrupt_Cfg_t SCB_Exeptions_Groups[] ;

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void)
{
    uint8 Local_u32Counter =0 ,Local_u8Interrupt_Number,Local_u8Group , Local_u8SubGroup ,Local_u8PriorityField ,Local_u8State  ; 

	/****** Configure Grouping\SubGrouping System in APINT register in SCB ******/

    /*	Read Least 3 bits of APINT Register	*/
	uint32 Local_u32RegValue = (SCB_REG->APINT) & 7;
	/*	Add Write Key and Priority Cofiguration */
	Local_u32RegValue |= VECTKEY | (IntCtrl_GroupingConfig<<8);
	/*	Write New Value to AIRCR Register*/
	SCB_REG->APINT = Local_u32RegValue;

    /****** Assign Group\Subgroup priority in  SCB_SYSPRIx & Enable\Disable based on user configurations in SCB_Sys ******/  
	for (Local_u32Counter=0 ; Local_u32Counter <5 ; Local_u32Counter++)
    {
        Local_u8Interrupt_Number = SCB_Exeptions_Groups[Local_u32Counter].Interrupt_Number ;
        Local_u8State = SCB_Exeptions_Groups[Local_u32Counter].State;
        Local_u8Group = SCB_Exeptions_Groups[Local_u32Counter].Group_Priority ;
        Local_u8SubGroup = SCB_Exeptions_Groups[Local_u32Counter].SubGroup_Priority ;

        if ( Local_u8Interrupt_Number <= SCB_EXCEPTION_USAGE_FAULT)
        {
            switch (Local_u8State)
            {
                case TRUE : //enable & set group/sub
                Local_u8PriorityField = (Local_u8Group<<(IntCtrl_GroupingConfig-4) | Local_u8SubGroup)& 0x7 ;
                /*	Clear Priority Field according to Exception value and Set it the new Value	*/
                SCB_REG->SYSPRI1 &= ~(0x7<<(Local_u8Interrupt_Number*8+5)) ;

                SCB_REG->SYSPRI1 |= (Local_u8PriorityField<<(Local_u8Interrupt_Number*8+5)) ;
                
                SET_BIT(SCB_REG->SYSHNDCTRL,Local_u8Interrupt_Number+16) ;
                break ;

                case FALSE://disable 
                
                CLR_BIT(SCB_REG->SYSHNDCTRL,Local_u8Interrupt_Number+16) ;
                break ;

                default :
                break;
            }
        }


        else 
        {
            if (Local_u8State)   // setting prio group/subgroup
            {
                Local_u8PriorityField = (Local_u8Group<<(IntCtrl_GroupingConfig-4) | Local_u8SubGroup)& 0x7 ;

                if (Local_u8Interrupt_Number==SCB_EXCEPTION_SVCALL)
                {
                    /*	Clear Priority Field according to Exception value and Set it the new Value	*/
                    SCB_REG->SYSPRI2 &= ~(0x7<<29) ;

                    SCB_REG->SYSPRI2 |= (Local_u8PriorityField<<29) ;
                }

                else if(Local_u8Interrupt_Number == SCB_EXCEPTION_DEBUG_MONITOR) 
                {

                    /*	Clear Priority Field according to Exception value and Set it the new Value	*/
                    SCB_REG->SYSPRI1 &= ~(0x7<<5) ;

                    SCB_REG->SYSPRI1 |= (Local_u8PriorityField<<5) ;
                }


            }
        }




    }



    /******  Assign Group\Subgroup priority in NVIC_PRIx Nvic & Enable\Disable based on user configurations in NVIC_ENx  ******/
    for(Local_u32Counter=0 ; Local_u32Counter< NUM_ACT_GROUPS ; Local_u32Counter++ )
    {
        Local_u8Interrupt_Number = Interrupt_Groups[Local_u32Counter].Interrupt_Number ;
        Local_u8Group = Interrupt_Groups[Local_u32Counter].Group_Priority ;
        Local_u8SubGroup = Interrupt_Groups[Local_u32Counter].SubGroup_Priority ;
        

        /*Priority*/
        Local_u8PriorityField = (Local_u8Group<<(IntCtrl_GroupingConfig-4) | Local_u8SubGroup)& 0x7 ;

        NVIC_REG_PRI->N[Local_u8Interrupt_Number/4] &= ~(0x7<<((Local_u8Interrupt_Number%4)*8+5)) ;
        NVIC_REG_PRI->N[Local_u8Interrupt_Number/4] |= (Local_u8PriorityField<<(((Local_u8Interrupt_Number%4)*8)+5));


        /* Enable */
        
        NVIC_REG_EN->N[Local_u8Interrupt_Number/32] |= 1<<((Local_u8Interrupt_Number%32)) ;
    }
    
	

}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
