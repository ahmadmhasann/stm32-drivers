/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Feb 09,   2021                                                    */
/*********************************************************************************/


#ifndef LEDMTRX_PRIVATE_H
#define LEDMTRX_PRIVATE_H

static void displayNextColumn   (void);
static void setRowsValue        (u8 copy_u8Value);
static void activateColumn      (u8 copy_u8Col  );

#define LEDMTRX_CONTROLLED_BY_PINS              0
#define LEDMTRX_CONTROLLED_BY_STP_CONVERTER     1
#define LEDMTRX_LEFT_TO_RIGHT                   0
#define LEDMTRX_RIGHT_TO_LEFT                   1

#endif