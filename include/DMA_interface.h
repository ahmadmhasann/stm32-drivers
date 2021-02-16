/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V02                                                               */
/* Date      : Feb 14,   2021                                                    */
/*********************************************************************************/

#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H



/*  OPTIONS
--> Options for channel:
    DMA_CHANNEL1
    DMA_CHANNEL2
    DMA_CHANNEL3
    DMA_CHANNEL4
    DMA_CHANNEL5
    DMA_CHANNEL6
    DMA_CHANNEL7

--> Options for priority:
    DMA_PRIORITY_LOW
    DMA_PRIORITY_MEDIUM
    DMA_PRIORITY_HIGH
    DMA_PRIORITY_VERY_HIGH

--> Options for mode:
    DMA_MODE_ENABLED
    DMA_MODE_DISABLED

--> Options for data transfer direction:
    DMA_READ_FROM_PERIPHERAL
    DMA_READ_FROM_MEMORY

--> Options for interrupt:
    DMA_TRANSFER_ERROR_INTERRUPT
    DMA_HALF_TRANSFER_INTERRUPT
    DMA_TRANSFER_COMPLETE_INTERRUPT
    DMA_GLOBAL_INTERRUPT (Allowed only to read or clear flag)

--> Options for size:
    DMA_SIZE_8_BITS
    DMA_SIZE_16_BITS
    DMA_SIZE_32_BITS
*/

void DMA_vidEnableClock                 (void);

void DMA_vidEnableChannel               (u8 copy_u8Channel);
void DMA_vidDisableChannel              (u8 copy_u8Channel);

void DMA_vidSetCallback                 (u8 copy_u8Channel , void (*ptr) (void)        );

void DMA_vidSetPriority                 (u8 copy_u8Channel , u8   copy_u8Priority      );
void DMA_vidSetMemoryToMemoryMode       (u8 copy_u8Channel , u8   copy_u8Mode          );
void DMA_vidSetCircularMode             (u8 copy_u8Channel , u8   copy_u8Mode          );
void DMA_vidSetDataTransferDirection    (u8 copy_u8Channel , u8   copy_u8Direction     );
void DMA_vidSetNumberOfData             (u8 copy_u8Channel , u16  copy_u16Number       );

void DMA_vidEnableInterrupt             (u8 copy_u8Channel , u8   copy_u8Interrupt     );
void DMA_vidDisableInterrupt            (u8 copy_u8Channel , u8   copy_u8Interrupt     );
void DMA_vidClearInterruptFlag          (u8 copy_u8Channel , u8   copy_u8Interrupt     );
u8   DMA_u8ReadInterruptFlag            (u8 copy_u8Channel , u8   copy_u8Interrupt     );

void DMA_vidSetSize                     (u8 copy_u8Channel , u8   copy_u8MemorySize     , u8   copy_u8PeripheralSize      );
void DMA_vidSetIncrementMode            (u8 copy_u8Channel , u8   copy_u8MemoryMode     , u8   copy_u8PeripheralMode      );
void DMA_vidSetAddress                  (u8 copy_u8Channel , u32 *copy_u32MemoryAddress , u32 *copy_u32PeripheralAddress  );

/*These values can not be changed*/

#define DMA_CHANNEL1 0
#define DMA_CHANNEL2 1
#define DMA_CHANNEL3 2
#define DMA_CHANNEL4 3
#define DMA_CHANNEL5 4
#define DMA_CHANNEL6 5
#define DMA_CHANNEL7 6

#define DMA_SIZE_8_BITS   0b00
#define DMA_SIZE_16_BITS  0b01
#define DMA_SIZE_32_BITS  0b10

#define DMA_PRIORITY_LOW         0
#define DMA_PRIORITY_MEDIUM      1
#define DMA_PRIORITY_HIGH        2
#define DMA_PRIORITY_VERY_HIGH   3

#define DMA_MODE_DISABLED        0
#define DMA_MODE_ENABLED         1

#define DMA_READ_FROM_PERIPHERAL 0
#define DMA_READ_FROM_MEMORY     1

#define DMA_GLOBAL_INTERRUPT            0
#define DMA_TRANSFER_COMPLETE_INTERRUPT 1
#define DMA_HALF_TRANSFER_INTERRUPT     2
#define DMA_TRANSFER_ERROR_INTERRUPT    3



#endif