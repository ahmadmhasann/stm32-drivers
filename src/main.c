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


void main(void)
{
    RCC_voidInitSysClock();
    GPIO_vidEnableRCC(GPIOA);
    GPIO_vidSetPortDirection(GPIOA, OUTPUT_SPEED_10MHZ_PP);
    GPIO_vidSetPortValue(GPIOA, HIGH_PORT);
    while (1)
    {
        delay(1);
        if (GPIO_u16GetPortValue(GPIOA) == 0xffff)
        {
            GPIO_vidSetPortValue(GPIOA, LOW_PORT);
        }
        else if (GPIO_u16GetPortValue(GPIOA) == 0)
        {
            GPIO_vidSetPortValue(GPIOA, HIGH_PORT);
        }
    }
}


