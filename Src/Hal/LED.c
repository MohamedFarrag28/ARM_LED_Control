#include "../Common/Std_Types.h"
#include "../Common/Platform_Types.h"
#include "../Common/Bit_Math.h"
#include "../Mcal/Inc/DIO.h"
#include "Inc/LED.h"


void Led_State(DIO_Channel_t Channel_id,  LED_State Level)
{

    Dio_WriteChannel( Channel_id,  Level);



}
