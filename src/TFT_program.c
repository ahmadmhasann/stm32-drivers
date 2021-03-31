/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Mar 30,   2021                                                    */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"

#include "GPIO_interface.h"
#include "STK_interface.h"
#include "SPI_interface.h"
#include "delay.h"

void TFT_vidInit(void) {

    /* Initialize pins */
    GPIO_vidSetPinDirection(TFT_A0_PIN, OUTPUT_SPEED_2MHZ_PP);
    GPIO_vidSetPinDirection(TFT_RESET_PIN, OUTPUT_SPEED_2MHZ_PP);
    GPIO_vidSetPinDirection(TFT_CS_PIN, OUTPUT_SPEED_2MHZ_PP);
    /* Send pulse to RESET pin */
    GPIO_vidSetPinValue(TFT_RESET_PIN, HIGH_PIN);
    delayMS(1);
    GPIO_vidSetPinValue(TFT_RESET_PIN, LOW_PIN);
    delayMS(1);
    GPIO_vidSetPinValue(TFT_RESET_PIN, HIGH_PIN);
    delayMS(1);
    GPIO_vidSetPinValue(TFT_RESET_PIN, LOW_PIN);
    delayMS(1);
    GPIO_vidSetPinValue(TFT_RESET_PIN, HIGH_PIN);
    delayMS(150);
    /* SLEEPOUT command */
    voidWriteCommand(0x11);
    delayMS(150);
    /* Color mode */
    voidWriteCommand(0x3A);
    voidWriteData(0x05);
    /* TFT on */
    voidWriteCommand(0x29);




}


void TFT_vidFisplayImage(const u16* copyImage) {

    u16 counter=0;
    /* Set X address */
    voidWriteCommand(0x2A);
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(127);

    /* Set X address */
    voidWriteCommand(0x2B);
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(159);

    /* Write to RAM */
    voidWriteCommand(0x2C);

    for (counter = 0; counter< 20480; counter++) {
        voidWriteData(copyImage[counter] >> 8);
        voidWriteData(copyImage[counter] & 0x00FF);
    }
    

}


static void voidWriteCommand(u8 copy_u8Command) {
    u8 local_u8Temp;
    GPIO_vidSetPinValue(TFT_A0_PIN, LOW_PIN);
    SPI1_vidSendRecieveSynch8Bit(TFT_CS_PIN, copy_u8Command, &local_u8Temp);
}
static void voidWriteData(u8 copy_u8Data) {
    u8 local_u8Temp;
    GPIO_vidSetPinValue(TFT_A0_PIN, HIGH_PIN);
    SPI1_vidSendRecieveSynch8Bit(TFT_CS_PIN, copy_u8Data, &local_u8Temp);
}