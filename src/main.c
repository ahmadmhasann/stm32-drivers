/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Jan 04,   2021                                                    */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "delay.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"
#include "LEDMTRX_interface.h"



void main(void)
{
    RCC_vidInitSysClock();
    STK_vidInit();
    LEDMTRX_vidInit();

    GPIO_vidEnablePortClock(GPIOA);
    GPIO_vidEnablePortClock(GPIOB);
    u8 frame[8] = {0, 124, 18, 18, 18, 18, 124, 0};

    LEDMTRX_vidDisplayFrame(frame);

    

    while (1)
    {
        
    }

    

}




