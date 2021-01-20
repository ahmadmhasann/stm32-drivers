/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Jan 05,   2021                                                    */
/*********************************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB       0 
#define RCC_APB1      1
#define RCC_APB2      2

void RCC_vidInitSysClock   ( void );

void RCC_vidEnableClock    ( u8 Copy_u8BusId, u8 Copy_u8PerId );
void RCC_vidDisableClock   ( u8 Copy_u8BusId, u8 Copy_u8PerId );




#endif
