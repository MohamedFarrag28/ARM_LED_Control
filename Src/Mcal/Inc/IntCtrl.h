/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCrtl.h
 *       Module:  IntCrtl
 *
 *  Description:  header file for IntCrtl Module    
 *  
 *********************************************************************************************************************/
#ifndef IntCrtl_H
#define IntCrtl_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Platform_Types.h"
#include "IntCtrl_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define VECTKEY         0x05FA0000



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum{
	PRI_CONFIG_8_GROUP_1_SUB = 4,
	PRI_CONFIG_4_GROUP_2_SUB,
	PRI_CONFIG_2_GROUP_4_SUB,
	PRI_CONFIG_1_GROUP_8_SUB,
}PRI_CONFIG_t;


typedef enum{
	GROUP_1,
	GROUP_2,
	GROUP_3,
	GROUP_4,
	GROUP_5,
	GROUP_6,
	GROUP_7,
	GROUP_8
}GroupPriority_t;

typedef enum{
	SUB_1,
	SUB_2,
	SUB_3,
	SUB_4,
	SUB_5,
	SUB_6,
	SUB_7,
	SUB_8,
}SubPriority_t;


typedef struct{
	
IntCtrl_InterruptType               Interrupt_Number;
GroupPriority_t			            Group_Priority;
SubPriority_t				        SubGroup_Priority;
	
}Interrupt_Cfg_t;


typedef struct{
	     
SCB_Exception_t                     Interrupt_Number;
boolean                             State ;      
GroupPriority_t			            Group_Priority;
SubPriority_t				        SubGroup_Priority;
	
}sys_Interrupt_Cfg_t;




 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
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
void IntCrtl_Init(void);
 
#endif  /* IntCrtl_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.h
 *********************************************************************************************************************/
