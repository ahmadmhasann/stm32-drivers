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

void main(void)
{
    RCC_vidInitSysClock();
    GPIO_vidEnableRCC(GPIOA);
    GPIO_vidSetPinDirection(GPIOA, PIN0, OUTPUT_SPEED_2MHZ_PP);
    GPIO_vidSetPinDirection(GPIOA, PIN1, OUTPUT_SPEED_2MHZ_PP);
    GPIO_vidSetPinDirection(GPIOA, PIN2, OUTPUT_SPEED_2MHZ_PP);
    NVIC_vidInit();
    NVIC_vidSetPriority(6, 1, 0);
    NVIC_vidSetPriority(6, 1, 0);
    NVIC_vidEnableInterrupt(6);
    NVIC_vidEnableInterrupt(7);
    NVIC_vidSetPendingFlag(6);

    while (1)
    {
        
    }
    

}


void EXTI0_IRQHandler (void) {
    GPIO_vidSetPinValue(GPIOA, PIN0, HIGH_PIN);
    NVIC_vidSetPendingFlag(7);
    GPIO_vidSetPinValue(GPIOA, PIN1, HIGH_PIN);

}
void EXTI1_IRQHandler (void) {
    GPIO_vidSetPinValue(GPIOA, PIN2, HIGH_PIN);
    
}
void EXTI2_IRQHandler (void) {
    
}


