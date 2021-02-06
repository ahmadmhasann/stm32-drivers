/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V02                                                               */
/* Date      : Feb 05,   2021                                                    */
/*********************************************************************************/

#ifndef EXTI_INTERVACE_H
#define EXTI_INTERVACE_H

void EXTI_vidSetSignalLatch (u8 copy_u8Line, u8 copy_u8SenseMood);
void EXTI_vidEnableLine (u8 copy_u8Line);
void EXTI_vidDisableLine (u8 copy_u8Line);
void EXTI_vidSoftwareTrigger (u8 copy_u8Line);
void EXTI_vidSetCallBack (u8 copy_u8Line, void (*ptr) (void));

enum {
    EXTI_RISING_EDGE  ,
    EXTI_FALLING_EDGE ,
    EXTI_ON_CHANGE
};
#define EXTI_RISING_EDGE    0
#define EXTI_FALLING_EDGE   1
#define EXTI_ON_CHANGE      2

#define EXTI_LINE0     0
#define EXTI_LINE1     1
#define EXTI_LINE2     2
#define EXTI_LINE3     3
#define EXTI_LINE4     4
#define EXTI_LINE5     5
#define EXTI_LINE6     6
#define EXTI_LINE7     7
#define EXTI_LINE8     8
#define EXTI_LINE9     9
#define EXTI_LINE10    10
#define EXTI_LINE11    11
#define EXTI_LINE12    12
#define EXTI_LINE13    13
#define EXTI_LINE14    14
#define EXTI_LINE15    15


#endif