/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Feb 18,   2021                                                    */
/*********************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

#include "GPIO_interface.h"

void SPI1_vidInitMaster(void) {
    /* CPOL =1 / CPHA = 1 / Prescaller = Clk/2 / SPI Enable / MSB First */
    SPI1->CR1 = 0x0347;
}

	
void SPI1_vidSendRecieveSynch (u8 copy_u8SlavePort, u8 copy_u8SlavePin, u16 copy_u16DataToSend, u16 *copy_u16DataToRecieve)
{
    /*Clear slave select pin to start sending*/
    GPIO_vidSetPinValue(copy_u8SlavePort, copy_u8SlavePin, LOW_PIN);

    /*Write data*/
    SPI1 -> DR = copy_u16DataToSend;

    /*Wait for busy flag is cleared when finished*/
    while ((GET_BIT(SPI1->SR, 7)));

    /*Read recieved data*/
    *copy_u16DataToRecieve = SPI1 -> DR;

    /*Set slave select pin to finish sending*/
    GPIO_vidSetPinValue(copy_u8SlavePort, copy_u8SlavePin, HIGH_PIN);
}
void SPI1_vidSendRecieveAsynch (u8 copy_u8SlavePort, u8 copy_u8SlavePin, u16 copy_u16DataToSend, void (*callback) (u16))
{
    /*Clear slave select pin to start sending*/
    GPIO_vidSetPinValue(copy_u8SlavePort, copy_u8SlavePin, LOW_PIN);

    /*Write data*/
    SPI1 -> DR = copy_u16DataToSend;

    /*Set slave select pin to finish sending*/
    GPIO_vidSetPinValue(copy_u8SlavePort, copy_u8SlavePin, HIGH_PIN);
}
