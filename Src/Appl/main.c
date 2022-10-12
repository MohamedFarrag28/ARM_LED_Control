
#include "../Common/Std_Types.h"
#include "../Common/Platform_Types.h"
#include "../Common/Bit_Math.h"
#include "../MCAL/Inc/IntCtrl.h"
#include "../MCAL/Inc/SYS_Ctrl.h"
#include "../Mcal/Inc/Port.h"
#include "../Mcal/Inc/DIO.h"
#include "../Common/Bit_Math.h"
#include "../MCAL/Inc/SYS_TICK.h"
#include "../Hal/Inc/LED.h"

uint8 on_time   ;  //in  sec
uint8 off_time  	;


uint8 state = 0,counter=0 ;
uint8 on_counter ;     // ontime / systick 
uint8 off_counter ;
uint8 Switch_counter =0 ;

void LED(void);

int main()
{
	uint8 i =0  ;
	IntCrtl_Init();
	Sys_Ctrl_Init();
	Port_Init();
	
	Sys_Tick_Init(1) ;
	Sys_Tick_DisableNotification();
	Sys_Tick_SetCallBack(LED) ;
  
	
	while(1)
	{
		
		if(Dio_ReadChannel(GPIO_PIN_F4 )==0)  // switch 1 pressed 
		{			
			while(Dio_ReadChannel(GPIO_PIN_F4 ) == 0) ; // stuck until release "rising edge"
			
			if(Switch_counter == 0)
					Sys_Tick_DisableNotification();
			else if (Switch_counter == 2)
			{
				
				on_counter = on_time/1 ;
				off_counter = off_time/1 ;
				Switch_counter = 0 ;
				counter = 0 ;
				state = 0 ;
				Sys_Tick_EnableNotification();
				continue ;
			}
			
			i = 0 ;

			while(Dio_ReadChannel(GPIO_PIN_F4 )== 1)  // stuck till next press 
			{
				if(Dio_ReadChannel(GPIO_PIN_F0) == 0)
				{
					while(Dio_ReadChannel(GPIO_PIN_F0)==0 ) ;
					i++ ;
				}
					
			}
			
			if(Switch_counter == 0)
			{
				on_time = i ;
				Switch_counter++ ;
			}
			else if(Switch_counter==1)
			{
				off_time = i ;
				Switch_counter++ ;
			}

			
		}

	}
	return 0 ;
}




void LED(void)
{
	counter++ ;
	if (state)
	{
		if (counter == on_counter)
		{
			Led_State( GPIO_PIN_F3,  LED_OFF);
			counter = 0 ;
			state ^=1 ;
		}

	}
	else 
	{
		if(counter == off_counter)
		{
			Led_State( GPIO_PIN_F3,  LED_ON);
			counter = 0 ;
			state ^=1 ;
		}
	}
	

}
/*0x40025000	*/

/*400253FC*/
/*0x40000000, 0x400FFFFF llst*/

