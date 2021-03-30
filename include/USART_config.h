/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Mar 02,   2021                                                    */
/*********************************************************************************/

#ifndef USART_CONFIG_H
#define USART_CONFIG_H

#define USART1_BAUDRATE             9600
#define USART1_PARITTY_CONTROL      USART_PARITTY_CONTROL_ENABLED
#define USART1_PARITTY_SELECTION    USART_EVEN_PARITY
#define USART1_CLOCK_POLARITY       USART_CLK_1_WHEN_IDLE
#define USART1_CLOCK_PHASE          USART_SECOND_CLOCK_FIRST_CAPTURE
#define USART1_STOP_BITS            USART_1_STOP_BIT
#define USART1_CLOCK_CONTROL        USART_1_CLOCK_ENABLED
/* Options:
    USART_FIRST_CLOCK_FIRST_CAPTURE
    USART_SECOND_CLOCK_FIRST_CAPTURE
*/



#endif
