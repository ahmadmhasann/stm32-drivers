/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Feb 18,   2021                                                    */
/*********************************************************************************/


#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

typedef struct {
    volatile u32 CR1     ;
    volatile u32 CR2     ;
    volatile u32 SR      ;
    volatile u32 DR      ;
    volatile u32 CRCPR   ;
    volatile u32 RXCRCR  ;
    volatile u32 TXCRCR  ;
    volatile u32 I2SCFGR ;
    volatile u32 I2SPR   ;
} SPI_registers;

#define SPI1   ((SPI_registers*)(0x40013000))
#define SPI2   ((SPI_registers*)(0x40003800))

#define SPI_MSB_FIRST 0
#define SPI_LSB_FIRST 1


#endif