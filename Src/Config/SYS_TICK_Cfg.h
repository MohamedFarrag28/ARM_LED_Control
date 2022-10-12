/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SYS_TICK_CFG.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef SYS_TICK_CFG_H
#define SYS_TICK_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*
    Options :
    ENABLE
    DISABLE

*/

#define SYSTICK_STATE         ENABLE



/*
    Options :
    ENABLE
    DISABLE

*/
#define SYSTICK_INTERRUPT       ENABLE



/*	
    Options:
	SYSTICK_CLK_PIOSC_DIV_4
    SYSTICK_CLK_SYSCLK
*/
#define SYSTICK_CLK_SRC         SYSTICK_CLK_PIOSC_DIV_4

#if SYSTICK_CLK_SRC == SYSTICK_CLK_SYSCLK

/*
put your system clock after gates here
as :
#define CLK_SYSCLK_FREQ         160000000
*/         

#ifndef	CLK_SYSCLK_FREQ
#warning you didnt entered the frequency of the system ---> you_are_using SYSTICK_CLK_PIOSC_DIV_4
#define CLK_SYSCLK_FREQ  16000000

#endif

#endif




#endif  /* SYS_TICK_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: SYS_TICK_Cfg.h
 *********************************************************************************************************************/
