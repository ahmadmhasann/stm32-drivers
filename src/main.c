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
    RCC_vidInitSysClock();
    GPIO_vidEnableRCC(GPIOA);
    GPIO_vidSetPinDirection(GPIOA, PIN0, OUTPUT_SPEED_10MHZ_PP);
    GPIO_vidSetPinValue(GPIOA, PIN0, HIGH_PIN);
    delay(2);
    GPIO_vidSetPinValue(GPIOA, PIN0, LOW_PIN);
    delay(2);
    GPIO_vidSetPinValue(GPIOA, PIN0, HIGH_PIN);
    delay(2);
    GPIO_vidLockPin(GPIOA, PIN0);
    GPIO_vidSetPinDirection(GPIOA, PIN0, OUTPUT_SPEED_10MHZ_OD);
    GPIO_vidSetPinValue(GPIOA, PIN0, HIGH_PIN);
    delay(2);
    GPIO_vidSetPinValue(GPIOA, PIN0, LOW_PIN);
    delay(2);
    GPIO_vidSetPinValue(GPIOA, PIN0, HIGH_PIN);
    delay(2);


    /*GPIO_vidSetPortDirection(GPIOA, OUTPUT_SPEED_10MHZ_PP);
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
    }*/
}


