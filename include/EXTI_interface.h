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
enum {
    EXTI_LINE0  ,
    EXTI_LINE1  ,
    EXTI_LINE2  ,
    EXTI_LINE3  ,
    EXTI_LINE4  ,
    EXTI_LINE5  ,
    EXTI_LINE6  ,
    EXTI_LINE7  ,
    EXTI_LINE8  ,
    EXTI_LINE9  ,
    EXTI_LINE10 ,
    EXTI_LINE11 ,
    EXTI_LINE12 ,
    EXTI_LINE13 ,
    EXTI_LINE14 ,
    EXTI_LINE15
};


#endif