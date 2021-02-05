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

#define AFIO_EXTICR1   *((volatile u32*)(0x40010008))

void fun (void) {
    GPIO_vidSetPinValue(GPIOA, PIN1, HIGH_PIN);
    delay(2);
    GPIO_vidSetPinValue(GPIOA, PIN1, LOW_PIN);
    delay(2);
    
}

void main(void)
{
    RCC_vidInitSysClock();

    GPIO_vidEnableRCC(GPIOA);
    GPIO_vidEnableRCC(GPIOB);

    /*AF*/
    RCC_vidEnableClock(RCC_APB2 , 0);

    /*AF select*/
    AFIO_EXTICR1 = 0x00000001;


    GPIO_vidSetPinDirection(GPIOB, PIN0, INPUT_PULLUP_PULLDOWN);
    GPIO_vidSetPinValue(GPIOB, PIN0, HIGH_PIN);
    GPIO_vidSetPinDirection(GPIOA, PIN1, OUTPUT_SPEED_2MHZ_PP);
    GPIO_vidSetPinDirection(GPIOA, PIN2, OUTPUT_SPEED_2MHZ_PP);

    EXTI_vidEnableLine (EXTI_LINE0);
    EXTI_vidSetSignalLatch (EXTI_LINE0, EXTI_RISING_EDGE);
    EXTI_vidSetCallBack(EXTI_LINE0, fun);

    NVIC_vidInit();
    NVIC_vidEnableInterrupt(NVIC_EXTI0);
    

    while (1)
    {
        
    }

    

}




