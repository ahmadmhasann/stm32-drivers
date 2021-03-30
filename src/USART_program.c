/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Mar 02,   2021                                                    */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

#include "RCC_interface.h"

void USART1_vidInit (void) {

    /* Getting clock frequency of APB2*/
    u32 local_u16Clock = RCC_u32GetClockFrequency(RCC_APB2);

    /* Setting up baud rate */
    u16 local_u16divMantissa =  ((local_u16Clock) / (USART1_BAUDRATE * 16));
    u16 local_u16divFraction =  ((local_u16Clock * 1000 ) / (USART1_BAUDRATE * 16)) - local_u16divMantissa*1000;
    local_u16divFraction = (local_u16divFraction * 16) / 1000;
    USART1 -> BRR = (local_u16divMantissa << 4) | local_u16divFraction;

/* Parity control enable and selection */
#if     (USART1_PARITTY_CONTROL == USART_PARITTY_CONTROL_ENABLED) && (USART1_PARITTY_SELECTION == USART_ODD_PARITY)
    SET_BIT(USART1 -> CR1, 10);
    SET_BIT(USART1 -> CR1, 9 );
#elif   (USART1_PARITTY_CONTROL == USART_PARITTY_CONTROL_ENABLED) && (USART1_PARITTY_SELECTION == USART_EVEN_PARITY)
    SET_BIT(USART1 -> CR1, 10);
    CLR_BIT(USART1 -> CR1, 9 );
#else
    CLR_BIT(USART1 -> CR1, 10);
#endif

/* Stop bits */
#if     USART1_STOP_BITS == USART_1_STOP_BIT
    CLR_BIT(USART1 -> CR2, 12);
    CLR_BIT(USART1 -> CR2, 13);
#elif   USART1_STOP_BITS == USART_0_5_STOP_BIT
    SET_BIT(USART1 -> CR2, 12);
    CLR_BIT(USART1 -> CR2, 13);
#elif   USART1_STOP_BITS == USART_2_STOP_BIT
    CLR_BIT(USART1 -> CR2, 12);
    SET_BIT(USART1 -> CR2, 13);
#elif   USART1_STOP_BITS == USART_1_5_STOP_BIT
    SET_BIT(USART1 -> CR2, 12);
    SET_BIT(USART1 -> CR2, 13);
#endif

/* Clock control */
#if     USART1_CLOCK_CONTROL == USART_1_CLOCK_ENABLED
    SET_BIT(USART1 -> CR2, 11);
#elif   USART1_CLOCK_CONTROL == USART_1_CLOCK_DISABLED
    CLR_BIT(USART1 -> CR2, 11);
#endif

/* Clock polarity */
#if     USART1_CLOCK_POLARITY == USART_CLK_1_WHEN_IDLE
    SET_BIT(USART1 -> CR2, 10);
#elif   USART1_CLOCK_POLARITY == USART_CLK_0_WHEN_IDLE
    CLR_BIT(USART1 -> CR2, 10);
#endif

/* Clock phase */
#if     USART1_CLOCK_PHASE == USART_SECOND_CLOCK_FIRST_CAPTURE
    SET_BIT(USART1 -> CR2, 9);
#elif   USART1_CLOCK_PHASE == USART_FIRST_CLOCK_FIRST_CAPTURE
    CLR_BIT(USART1 -> CR2, 9);
#endif

    SET_BIT(USART1 -> CR1, 2 ); /* RX enable                */
    SET_BIT(USART1 -> CR1, 3 ); /* TX enable                */
    SET_BIT(USART1 -> CR1, 13); /* USART enable             */
    USART1 -> SR = 0;           /* Clear status register    */

}
void USART1_vidTransmit (u8 arr[]) {
    u8 local_u8Counter = 0;
    while (arr[local_u8Counter] != '\0') {
        USART1 -> DR = arr[local_u8Counter];
        while (GET_BIT(USART1 -> SR , 6) == 0); /* Wait till transmission is complete */ 
        local_u8Counter++;
    }
}
u8 USART1_u8Recieve (void) {
    u8 local_u8Result;
    while (GET_BIT(USART1 -> SR , 5) == 0); /* Wait till recieve is complete */
    local_u8Result = (USART1 -> DR) && 0xFF;
    return local_u8Result;

}


void USART1_vidEnableClock(void) {
    RCC_vidEnableClock(RCC_APB2, USART1EN);
}
