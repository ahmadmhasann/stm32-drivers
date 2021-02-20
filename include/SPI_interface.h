/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Feb 18,   2021                                                    */
/*********************************************************************************/


#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void SPI1_vidEnableClock                    ( void );
void SPI1_vidInitMaster                     ( void );
void SPI1_vidInitSlave                      ( void );
void SPI1_vidSendRecieveSynch16Bit          ( u8 copy_u8SlavePort   , u8 copy_u8SlavePin, u16 copy_u16DataToSend, u16 *copy_u16DataToRecieve );
void SPI1_vidSendRecieveSynch8Bit           ( u8 copy_u8SlavePort   , u8 copy_u8SlavePin, u8  copy_u8DataToSend , u8  *copy_u8DataToRecieve  );
void SPI1_vidSetBaudRatePrescaler           ( u8  copy_u8Prescaler );
u8   SPI1_u8GetBaudRatePrescalerFromMaxFreq ( u32 copy_u32MaxFreq  );

void SPI2_vidEnableClock                    ( void );
void SPI2_vidInitMaster                     ( void );
void SPI2_vidInitSlave                      ( void );
void SPI2_vidSendRecieveSynch16Bit          ( u8 copy_u8SlavePort   , u8 copy_u8SlavePin, u16 copy_u16DataToSend, u16 *copy_u16DataToRecieve );
void SPI2_vidSendRecieveSynch8Bit           ( u8 copy_u8SlavePort   , u8 copy_u8SlavePin, u8  copy_u8DataToSend , u8  *copy_u8DataToRecieve  );
void SPI2_vidSetBaudRatePrescaler           ( u8  copy_u8Prescaler );
u8   SPI2_u8GetBaudRatePrescalerFromMaxFreq ( u32 copy_u32MaxFreq  );


/*
--> Options for copy_u8Prescaler:
        SPI_BAUDRATE_PRESCALER_2
        SPI_BAUDRATE_PRESCALER_4
        SPI_BAUDRATE_PRESCALER_8
        SPI_BAUDRATE_PRESCALER_16
        SPI_BAUDRATE_PRESCALER_32
        SPI_BAUDRATE_PRESCALER_64
        SPI_BAUDRATE_PRESCALER_128
        SPI_BAUDRATE_PRESCALER_256
*/

#define SPI_BAUDRATE_PRESCALER_2    0
#define SPI_BAUDRATE_PRESCALER_4    1
#define SPI_BAUDRATE_PRESCALER_8    2
#define SPI_BAUDRATE_PRESCALER_16   3
#define SPI_BAUDRATE_PRESCALER_32   4
#define SPI_BAUDRATE_PRESCALER_64   5
#define SPI_BAUDRATE_PRESCALER_128  6
#define SPI_BAUDRATE_PRESCALER_256  7

#endif