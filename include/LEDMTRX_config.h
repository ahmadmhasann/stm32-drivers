/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Feb 09,   2021                                                    */
/*********************************************************************************/

#ifndef LEDMTRX_CONFIG_H
#define LEDMTRX_CONFIG_H

#define LEDMTRX_SPEED_MS        300
/*
--> Options:
    LEDMTRX_LEFT_TO_RIGHT
    LEDMTRX_RIGHT_TO_LEFT
*/
#define LEDMTRX_DISPLAY_ORDER   LEDMTRX_LEFT_TO_RIGHT
/*
--> Options:
    LEDMTRX_CONTROLLED_BY_PINS
    LEDMTRX_CONTROLLED_BY_STP_CONVERTER
--> In case of using STP_CONVERTER you should define its pins in STP_config.h file
        STP1 is connected to row pins
        STP2 is connected to column pins
*/
#define LEDMTRX_CONTROL         LEDMTRX_CONTROLLED_BY_PINS
/*
--> Define row and columns pin only if LEDMTRX_CONTROLLED_BY_PINS
*/
#if LEDMTRX_CONTROL ==          LEDMTRX_CONTROLLED_BY_PINS

#define LEDMTRX_ROW_0           GPIOA,PIN0
#define LEDMTRX_ROW_1           GPIOA,PIN1
#define LEDMTRX_ROW_2           GPIOA,PIN2
#define LEDMTRX_ROW_3           GPIOA,PIN3
#define LEDMTRX_ROW_4           GPIOA,PIN4
#define LEDMTRX_ROW_5           GPIOA,PIN5
#define LEDMTRX_ROW_6           GPIOA,PIN6
#define LEDMTRX_ROW_7           GPIOA,PIN7

#define LEDMTRX_COL_0           GPIOB,PIN0
#define LEDMTRX_COL_1           GPIOB,PIN1
#define LEDMTRX_COL_2           GPIOB,PIN5
#define LEDMTRX_COL_3           GPIOB,PIN6
#define LEDMTRX_COL_4           GPIOB,PIN7
#define LEDMTRX_COL_5           GPIOB,PIN8
#define LEDMTRX_COL_6           GPIOB,PIN9
#define LEDMTRX_COL_7           GPIOB,PIN10

#endif

#endif