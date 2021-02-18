/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Feb 18,   2021                                                    */
/*********************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"

void STP_1_vidInit(void)
{    
    GPIO_vidSetPinDirection(STP_SERIAL_DATA_1, OUTPUT_SPEED_2MHZ_PP);
    GPIO_vidSetPinDirection(STP_SHIFT_CLOCK_1, OUTPUT_SPEED_2MHZ_PP);
    GPIO_vidSetPinDirection(STP_STORE_CLOCK_1, OUTPUT_SPEED_2MHZ_PP);
}
void STP_2_vidInit(void)
{    
    GPIO_vidSetPinDirection(STP_SERIAL_DATA_2, OUTPUT_SPEED_2MHZ_PP);
    GPIO_vidSetPinDirection(STP_SHIFT_CLOCK_2, OUTPUT_SPEED_2MHZ_PP);
    GPIO_vidSetPinDirection(STP_STORE_CLOCK_2, OUTPUT_SPEED_2MHZ_PP);
}

void STP_1_vidSendSynchronus (u8 copy_u8DataToSend)
{
    s8 local_s8Counter;
    u8 local_u8Bit;

    /* Send all bits starting from MSB */
    for (local_s8Counter = 7; local_s8Counter >=0; local_s8Counter--) {
        local_u8Bit = GET_BIT(copy_u8DataToSend, local_s8Counter);
        GPIO_vidSetPinValue(STP_SERIAL_DATA_1, local_u8Bit);

        /* Send pulse to Shift Clock */
        GPIO_vidSetPinValue(STP_SHIFT_CLOCK_1, HIGH_PIN);
        STK_vidSetBusyWait(1);
        GPIO_vidSetPinValue(STP_SHIFT_CLOCK_1, LOW_PIN);
        STK_vidSetBusyWait(1);
    }

    /* Send pulse to Store Register */
    GPIO_vidSetPinValue(STP_STORE_CLOCK_1, HIGH_PIN);
    STK_vidSetBusyWait(1);
    GPIO_vidSetPinValue(STP_STORE_CLOCK_1, LOW_PIN);
    STK_vidSetBusyWait(1);
}

void STP_2_vidSendSynchronus (u8 copy_u8DataToSend)
{
    s8 local_s8Counter;
    u8 local_u8Bit;

    /* Send all bits starting from MSB */
    for (local_s8Counter = 7; local_s8Counter >=0; local_s8Counter--) {
        local_u8Bit = GET_BIT(copy_u8DataToSend, local_s8Counter);
        GPIO_vidSetPinValue(STP_SERIAL_DATA_2, local_u8Bit);

        /* Send pulse to Shift Clock */
        GPIO_vidSetPinValue(STP_SHIFT_CLOCK_2, HIGH_PIN);
        STK_vidSetBusyWait(1);
        GPIO_vidSetPinValue(STP_SHIFT_CLOCK_2, LOW_PIN);
        STK_vidSetBusyWait(1);
    }

    /* Send pulse to Store Register */
    GPIO_vidSetPinValue(STP_STORE_CLOCK_2, HIGH_PIN);
    STK_vidSetBusyWait(1);
    GPIO_vidSetPinValue(STP_STORE_CLOCK_2, LOW_PIN);
    STK_vidSetBusyWait(1);
}



