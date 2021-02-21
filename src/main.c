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
#include "STP_interface.h"
#include "SPI_interface.h"
void getFrame (void) {
    asm("NOP");

}

u8 arr[] = {0, 126, 64, 64, 64, 0, 124, 18, 18, 18, 124, 0, 126, 10, 10, 14, 0, 126, 64, 64, 64, 0, 124, 18, 18, 18, 124, 0, 126, 66, 66, 66, 0, 126, 82, 82, 82, 0, 0, 0};
void main(void)
{
    RCC_vidInitSysClock();
    STK_vidInit();
    GPIO_vidEnablePortClock(GPIOA);
    GPIO_vidEnablePortClock(GPIOB);
    
    LEDMTRX_vidInit();
    
    LEDMTRX_vidDisplayFrame(arr, 40);


    

    





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


