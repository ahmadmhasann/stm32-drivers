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
#include "OS_interface.h"

#define OS_TEST_PIN_1 GPIOA,PIN0
#define OS_TEST_PIN_2 GPIOA,PIN1
#define OS_TEST_PIN_3 GPIOA,PIN2

void getFrame (void) {
    asm("NOP");

}

void task1 (void) {
    GPIO_u8TogglePinValue(OS_TEST_PIN_1);
}
void task2 (void) {
    GPIO_u8TogglePinValue(OS_TEST_PIN_2);
}
void task3 (void) {
    GPIO_u8TogglePinValue(OS_TEST_PIN_3);
}

void main(void)
{
    RCC_vidInitSysClock();
    GPIO_vidEnablePortClock(GPIOA);
    OS_vidInit();
    GPIO_vidSetPinDirection(OS_TEST_PIN_1, OUTPUT_SPEED_2MHZ_PP);
    GPIO_vidSetPinDirection(OS_TEST_PIN_2, OUTPUT_SPEED_2MHZ_PP);
    GPIO_vidSetPinDirection(OS_TEST_PIN_3, OUTPUT_SPEED_2MHZ_PP);
    OS_u8CreateTask(1000, 1000, task1);
    OS_u8CreateTask(2000, 1000, task2);
    OS_u8CreateTask(3000, 1000, task3);
    OS_vidStart();

    /*GPIO_vidSetPinDirection(GPIOA, PIN0, INPUT_FLOATING);
    GPIO_vidSetPinDirection(GPIOA, PIN1, OUTPUT_SPEED_2MHZ_PP);
    GPIO_vidSetPinDirection(GPIOA, PIN2, OUTPUT_SPEED_2MHZ_PP);
    GPIO_vidSetPinDirection(GPIOA, PIN3, OUTPUT_SPEED_2MHZ_PP);

    EXTI_vidSetCallBack(EXTI_LINE0, getFrame);
    EXTI_vidEnableLine(EXTI_LINE0);
    EXTI_vidSetSignalLatch(EXTI_LINE0, EXTI_FALLING_EDGE);

    NVIC_vidInit();
    NVIC_vidEnableInterrupt(NVIC_EXTI0);

    STK_vidInit();*/




    while (1)
    {
        OS_vidDispatchTasks();
    }

    

}




