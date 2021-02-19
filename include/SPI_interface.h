/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Feb 18,   2021                                                    */
/*********************************************************************************/


#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void SPI1_vidInitMaster(void);
void SPI1_vidSendRecieveSynch (u8 copy_u8SlavePort, u8 copy_u8SlavePin, u16 copy_u16DataToSend, u16 *copy_u16DataToRecieve);
void SPI1_vidSendRecieveAsynch (u8 copy_u8SlavePort, u8 copy_u8SlavePin, u16 copy_u16DataToSend, void (*callback) (u16));

#endif