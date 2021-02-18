/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Feb 18,   2021                                                    */
/*********************************************************************************/


#ifndef STP_CONFIG_H
#define STP_CONFIG_H

/* write pins in pairs (port, pin) */

#define STP_SERIAL_DATA_1     GPIOA, PIN0
#define STP_SHIFT_CLOCK_1     GPIOA, PIN2
#define STP_STORE_CLOCK_1     GPIOA, PIN1

#define STP_SERIAL_DATA_2     GPIOA, PIN0
#define STP_SHIFT_CLOCK_2     GPIOA, PIN2
#define STP_STORE_CLOCK_2     GPIOA, PIN1

#endif