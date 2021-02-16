/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V02                                                               */
/* Date      : Feb 14,   2021                                                    */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"

#include "RCC_interface.h"

static void(*DMA_callback[7])(void);

void DMA_vidEnableClock(void)
{
    RCC_vidEnableClock(RCC_AHB, DMA1EN);
}

void DMA_vidSetMemoryToMemoryMode(u8 copy_u8Channel, u8 copy_u8Mode)
{
    switch (copy_u8Mode)
    {
    case DMA_MODE_ENABLED:
        SET_BIT((DMA -> channel[copy_u8Channel].CCR), 14);
        break;
    case DMA_MODE_DISABLED:
        CLR_BIT((DMA -> channel[copy_u8Channel].CCR), 14);
        break;
    default:
        /*Return Error*/
        break;
    }
}

void DMA_vidSetPriority(u8 copy_u8Channel, u8 copy_u8Priority) {
    switch (copy_u8Priority)
    {
    case DMA_PRIORITY_LOW:
        CLR_BIT((DMA -> channel[copy_u8Channel].CCR), 12);
        CLR_BIT((DMA -> channel[copy_u8Channel].CCR), 13);
        break;
    case DMA_PRIORITY_MEDIUM:
        SET_BIT((DMA -> channel[copy_u8Channel].CCR), 12);
        CLR_BIT((DMA -> channel[copy_u8Channel].CCR), 13);
        break;
    case DMA_PRIORITY_HIGH:
        CLR_BIT((DMA -> channel[copy_u8Channel].CCR), 12);
        SET_BIT((DMA -> channel[copy_u8Channel].CCR), 13);
        break;
    case DMA_PRIORITY_VERY_HIGH:
        SET_BIT((DMA -> channel[copy_u8Channel].CCR), 12);
        SET_BIT((DMA -> channel[copy_u8Channel].CCR), 13);
        break;
    default:
        /*Return Error*/
        break;
    }
}

void DMA_vidSetSize(u8 copy_u8Channel, u8 copy_u8MemorySize, u8 copy_u8PeripheralSize)
{
    switch (copy_u8MemorySize)
    {
    case DMA_SIZE_8_BITS:
        CLR_BIT((DMA -> channel[copy_u8Channel].CCR), 10);
        CLR_BIT((DMA -> channel[copy_u8Channel].CCR), 11);
        break;
    case DMA_SIZE_16_BITS:
        SET_BIT((DMA -> channel[copy_u8Channel].CCR), 10);
        CLR_BIT((DMA -> channel[copy_u8Channel].CCR), 11);
        break;
    case DMA_SIZE_32_BITS:
        CLR_BIT((DMA -> channel[copy_u8Channel].CCR), 10);
        SET_BIT((DMA -> channel[copy_u8Channel].CCR), 11);
        break;
    default:
        /*Return Error*/
        break;
    }
    switch (copy_u8PeripheralSize)
    {
    case DMA_SIZE_8_BITS:
        CLR_BIT((DMA -> channel[copy_u8Channel].CCR), 8);
        CLR_BIT((DMA -> channel[copy_u8Channel].CCR), 9);
        break;
    case DMA_SIZE_16_BITS:
        SET_BIT((DMA -> channel[copy_u8Channel].CCR), 8);
        CLR_BIT((DMA -> channel[copy_u8Channel].CCR), 9);
        break;
    case DMA_SIZE_32_BITS:
        CLR_BIT((DMA -> channel[copy_u8Channel].CCR), 8);
        SET_BIT((DMA -> channel[copy_u8Channel].CCR), 9);
        break;
    default:
        /*Return Error*/
        break;
    }
}
void DMA_vidSetIncrementMode(u8 copy_u8Channel, u8 copy_u8MemoryMode, u8 copy_u8PeripheralMode) 
{
    switch (copy_u8MemoryMode)
    {
    case DMA_MODE_ENABLED:
        SET_BIT((DMA -> channel[copy_u8Channel].CCR), 7);
        break;
    case DMA_MODE_DISABLED:
        CLR_BIT((DMA -> channel[copy_u8Channel].CCR), 7);
        break;
    default:
        /*Return Error*/
        break;
    }
    switch (copy_u8PeripheralMode)
    {
    case DMA_MODE_ENABLED:
        SET_BIT((DMA -> channel[copy_u8Channel].CCR), 6);
        break;
    case DMA_MODE_DISABLED:
        CLR_BIT((DMA -> channel[copy_u8Channel].CCR), 6);
        break;
    default:
        /*Return Error*/
        break;
    }
}

void DMA_vidSetCircularMode(u8 copy_u8Channel, u8 copy_u8Mode) 
{
    switch (copy_u8Mode)
    {
    case DMA_MODE_ENABLED:
        SET_BIT((DMA -> channel[copy_u8Channel].CCR), 5);
        break;
    case DMA_MODE_DISABLED:
        CLR_BIT((DMA -> channel[copy_u8Channel].CCR), 5);
        break;
    default:
        /*Return Error*/
        break;
    }

}

void DMA_vidSetDataTransferDirection(u8 copy_u8Channel, u8 copy_u8Direction)
{
    switch (copy_u8Direction)
    {
    case DMA_READ_FROM_MEMORY:
        SET_BIT((DMA -> channel[copy_u8Channel].CCR), 4);
        break;
    case DMA_READ_FROM_PERIPHERAL:
        CLR_BIT((DMA -> channel[copy_u8Channel].CCR), 4);
        break;
    default:
        /*Return Error*/
        break;
    }

}
void DMA_vidEnableInterrupt(u8 copy_u8Channel, u8 copy_u8Interrupt)
{
    switch (copy_u8Interrupt)
    {
    case DMA_TRANSFER_ERROR_INTERRUPT:
        SET_BIT((DMA -> channel[copy_u8Channel].CCR), 3);
        break;
    case DMA_HALF_TRANSFER_INTERRUPT:
        SET_BIT((DMA -> channel[copy_u8Channel].CCR), 2);
        break;
    case DMA_TRANSFER_COMPLETE_INTERRUPT:
        SET_BIT((DMA -> channel[copy_u8Channel].CCR), 1);
        break;
    default:
        break;
    }

}
void DMA_vidDisableInterrupt(u8 copy_u8Channel, u8 copy_u8Interrupt)
{
    switch (copy_u8Interrupt)
    {
    case DMA_TRANSFER_ERROR_INTERRUPT:
        CLR_BIT((DMA -> channel[copy_u8Channel].CCR), 3);
        break;
    case DMA_HALF_TRANSFER_INTERRUPT:
        CLR_BIT((DMA -> channel[copy_u8Channel].CCR), 2);
        break;
    case DMA_TRANSFER_COMPLETE_INTERRUPT:
        CLR_BIT((DMA -> channel[copy_u8Channel].CCR), 1);
        break;
    default:
        break;
    }

}

void DMA_vidEnableChannel(u8 copy_u8Channel)
{
    SET_BIT((DMA -> channel[copy_u8Channel].CCR), 0);
}

void DMA_vidDisableChannel(u8 copy_u8Channel)
{
    CLR_BIT((DMA -> channel[copy_u8Channel].CCR), 0);
}

u8 DMA_u8ReadInterruptFlag(u8 copy_u8Channel, u8 copy_u8Interrupt)
{
    u8 local_u8Result;
    u8 local_u8PinNumber = copy_u8Interrupt + 4*copy_u8Channel;
    local_u8Result = GET_BIT( (DMA -> ISR), local_u8PinNumber);
    return local_u8Result;
}

void DMA_vidClearInterruptFlag(u8 copy_u8Channel, u8 copy_u8Interrupt)
{
    u8 local_u8PinNumber = copy_u8Interrupt + 4*copy_u8Channel;
    DMA -> IFCR = 1 << local_u8PinNumber;
}

void DMA_vidSetNumberOfData(u8 copy_u8Channel, u16 copy_u16Number) 
{
    DMA -> channel[copy_u8Channel].CNDTR = copy_u16Number;
}

void DMA_vidSetAddress(u8 copy_u8Channel, u32 *copy_u32MemoryAddress, u32 *copy_u32PeripheralAddress) 
{
    DMA -> channel[copy_u8Channel].CMAR = copy_u32MemoryAddress;
    DMA -> channel[copy_u8Channel].CPAR = copy_u32PeripheralAddress;
}

void DMA_vidSetCallback(u8 copy_u8Channel, void (*ptr)(void))
{
    DMA_callback[copy_u8Channel] = ptr;
}


/* IRQHandler Handlers */
void DMA1_Channel1_IRQHandler(void) {
    DMA_callback[0]();
    DMA -> IFCR = 0x0000000F; /* clear interrupt flags */
}
void DMA1_Channel2_IRQHandler(void) {
    DMA_callback[1]();
    DMA -> IFCR = 0x000000F0; /* clear interrupt flags */
}
void DMA1_Channel3_IRQHandler(void) {
    DMA_callback[2]();
    DMA -> IFCR = 0x00000F00; /* clear interrupt flags */
}
void DMA1_Channel4_IRQHandler(void) {
    DMA_callback[3]();
    DMA -> IFCR = 0x0000F000; /* clear interrupt flags */
}
void DMA1_Channel5_IRQHandler(void) {
    DMA_callback[4]();
    DMA -> IFCR = 0x000F0000; /* clear interrupt flags */
}
void DMA1_Channel6_IRQHandler(void) {
    DMA_callback[5]();
    DMA -> IFCR = 0x00F00000; /* clear interrupt flags */
}
void DMA1_Channel7_IRQHandler(void) {
    DMA_callback[6]();
    DMA -> IFCR = 0x0F000000; /* clear interrupt flags */
}
