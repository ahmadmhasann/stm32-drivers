/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Jan 20,   2021                                                    */
/*********************************************************************************/

#include "STD_TYPES.h"

#include "delay.h"

void delay(u8 counter)
{
    for (u16 i = 0; i < 1000*counter; i++)
    {
        for (u16 i = 0; i < 500; i++)
        {
            asm("NOP");
        }
    }
}