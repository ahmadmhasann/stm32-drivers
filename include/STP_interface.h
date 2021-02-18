/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Feb 18,   2021                                                    */
/*********************************************************************************/


#ifndef STP_INTERFACE_H
#define STP_INTERFACE_H


void STP_1_vidInit            ( void );
void STP_2_vidInit            ( void );
void STP_1_vidSendSynchronus  ( u8 copy_u8DataToSend );
void STP_2_vidSendSynchronus  ( u8 copy_u8DataToSend );


#endif