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
#include "DMA_interface.h"

void getFrame (void) {
    asm("NOP");

}


void main(void)
{
    RCC_vidInitSysClock();
    GPIO_vidEnablePortClock(GPIOA);
    GPIO_vidSetPortDirection(GPIOA, OUTPUT_SPEED_2MHZ_PP);

    





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
        
    }

    

}





    /* DMA Usage
    DMA_vidEnableClock();
    DMA_vidSetPriority(DMA_CHANNEL1, DMA_PRIORITY_MEDIUM);
    DMA_vidSetMemoryToMemoryMode(DMA_CHANNEL1, DMA_MODE_ENABLED);
    DMA_vidSetDataTransferDirection(DMA_CHANNEL1, DMA_READ_FROM_MEMORY);
    DMA_vidSetNumberOfData(DMA_CHANNEL1, 1000);
    DMA_vidSetSize(DMA_CHANNEL1, DMA_SIZE_32_BITS, DMA_SIZE_32_BITS);
    DMA_vidSetIncrementMode(DMA_CHANNEL1, DMA_MODE_ENABLED, DMA_MODE_ENABLED);
    DMA_vidSetAddress(DMA_CHANNEL1, add1, add2);
    DMA_vidEnableInterrupt(DMA_CHANNEL1, DMA_TRANSFER_COMPLETE_INTERRUPT);
    DMA_vidSetCallback(DMA_CHANNEL1, function);
    NVIC_vidEnableInterrupt(NVIC_DMA1_Channel1);
    DMA_vidEnableChannel(DMA_CHANNEL1); */


