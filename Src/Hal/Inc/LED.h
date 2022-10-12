#ifndef LED_H
#define LED_H

#include "../Mcal/Inc/DIO.h"

typedef enum{
	 LED_OFF,
    LED_ON
}LED_State;




void Led_State(DIO_Channel_t Channel_id, LED_State Level);







#endif