/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V02                                                               */
/* Date      : Feb 05,   2021                                                    */
/*********************************************************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define EXTI_IMR      *((volatile u32*)(0x40010400))
#define EXTI_EMR      *((volatile u32*)(0x40010404))
#define EXTI_RTSR     *((volatile u32*)(0x40010408))
#define EXTI_FTSR     *((volatile u32*)(0x4001040C))
#define EXTI_SWIER    *((volatile u32*)(0x40010410))
#define EXTI_PR       *((volatile u32*)(0x40010414))



#endif