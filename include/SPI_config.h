/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Feb 18,   2021                                                    */
/*********************************************************************************/


#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/* Options:
    SPI_PINS_A4_A5_A6_A7
    SPI_PINS_A15_B3_B4_B5
*/

#define SPI1_PINS    SPI_PINS_A4_A5_A6_A7

/* Options:
    SPI_MSB_FIRST
    SPI_LSB_FIRST
*/
#define SPI1_DATA_ORDER     SPI_MSB_FIRST
#define SPI2_DATA_ORDER     SPI_LSB_FIRST

/* Options:
    SPI_FIRST_CLOCK_FIRST_CAPTURE
    SPI_SECOND_CLOCK_FIRST_CAPTURE
*/
#define SPI1_CLK_PHASE      SPI_SECOND_CLOCK_FIRST_CAPTURE
#define SPI2_CLK_PHASE      SPI_SECOND_CLOCK_FIRST_CAPTURE

/* Options:
    SPI_FIRST_CLOCK_FIRST_CAPTURE
    SPI_SECOND_CLOCK_FIRST_CAPTURE
*/
#define SPI1_CLK_POLARITY      SPI_CK_1_WHEN_IDLE
#define SPI2_CLK_POLARITY      SPI_CK_1_WHEN_IDLE

/* Options:
    SPI_FIRST_CLOCK_FIRST_CAPTURE
    SPI_SECOND_CLOCK_FIRST_CAPTURE
*/

/* Options:
    SPI_BAUDRATE_PRESCALER_2
    SPI_BAUDRATE_PRESCALER_4
    SPI_BAUDRATE_PRESCALER_8
    SPI_BAUDRATE_PRESCALER_16
    SPI_BAUDRATE_PRESCALER_32
    SPI_BAUDRATE_PRESCALER_64
    SPI_BAUDRATE_PRESCALER_128
    SPI_BAUDRATE_PRESCALER_256
*/
#define SPI1_BAUDRATE_PRESCALER      SPI_BAUDRATE_PRESCALER_2
#define SPI2_BAUDRATE_PRESCALER      SPI_BAUDRATE_PRESCALER_2

#endif