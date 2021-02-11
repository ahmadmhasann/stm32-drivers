#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMTRX_interface.h"
#include "LEDMTRX_private.h"
#include "LEDMTRX_config.h"

u8 LEDMTRX_u8CurrentIndex = 0;
u8 *LEDMTRX_u8Frame;

void LEDMTRX_vidInit(void)
{
	/*Set Direction of all rows pins*/
	GPIO_vidSetPinDirection(LEDMTRX_ROW_0, OUTPUT_SPEED_2MHZ_PP);
	GPIO_vidSetPinDirection(LEDMTRX_ROW_1, OUTPUT_SPEED_2MHZ_PP);
	GPIO_vidSetPinDirection(LEDMTRX_ROW_2, OUTPUT_SPEED_2MHZ_PP);
	GPIO_vidSetPinDirection(LEDMTRX_ROW_3, OUTPUT_SPEED_2MHZ_PP);
	GPIO_vidSetPinDirection(LEDMTRX_ROW_4, OUTPUT_SPEED_2MHZ_PP);
	GPIO_vidSetPinDirection(LEDMTRX_ROW_5, OUTPUT_SPEED_2MHZ_PP);
	GPIO_vidSetPinDirection(LEDMTRX_ROW_6, OUTPUT_SPEED_2MHZ_PP);
	GPIO_vidSetPinDirection(LEDMTRX_ROW_7, OUTPUT_SPEED_2MHZ_PP);

	/*Set Direction of all columns pins*/
	GPIO_vidSetPinDirection(LEDMTRX_COL_0, OUTPUT_SPEED_2MHZ_PP);
	GPIO_vidSetPinDirection(LEDMTRX_COL_1, OUTPUT_SPEED_2MHZ_PP);
	GPIO_vidSetPinDirection(LEDMTRX_COL_2, OUTPUT_SPEED_2MHZ_PP);
	GPIO_vidSetPinDirection(LEDMTRX_COL_3, OUTPUT_SPEED_2MHZ_PP);
	GPIO_vidSetPinDirection(LEDMTRX_COL_4, OUTPUT_SPEED_2MHZ_PP);
	GPIO_vidSetPinDirection(LEDMTRX_COL_5, OUTPUT_SPEED_2MHZ_PP);
	GPIO_vidSetPinDirection(LEDMTRX_COL_6, OUTPUT_SPEED_2MHZ_PP);
	GPIO_vidSetPinDirection(LEDMTRX_COL_7, OUTPUT_SPEED_2MHZ_PP);
}

void LEDMTRX_vidDisplayFrame(u8 *copy_u8Frame)
{
	/* Save the desired Frame */
	LEDMTRX_u8Frame = copy_u8Frame;
	
	/* Reset the frame Start */
	LEDMTRX_u8CurrentIndex = 0;
	
	/* Dislay The first Column */
	activateColumn (LEDMTRX_u8CurrentIndex);
	setRowsValue   (copy_u8Frame[LEDMTRX_u8CurrentIndex]);
	
	/* Start timer */
	STK_vidSetIntervalPeriodic(2000,displayNextColumn);
}

static void displayNextColumn (void)
{
	LEDMTRX_u8CurrentIndex++;
	if (LEDMTRX_u8CurrentIndex == 8)
	{
		LEDMTRX_u8CurrentIndex = 0;
	}
	
	/* Dislay The first Column */
	activateColumn(LEDMTRX_u8CurrentIndex);
	setRowsValue  (LEDMTRX_u8Frame[LEDMTRX_u8CurrentIndex]);
}

static void setRowsValue (u8 copy_u8Value)
{
	u8 local_u8Index;
	u8 local_u8Bit[8];

	for ( local_u8Index = 0; local_u8Index < 8; local_u8Index++ ) {
		local_u8Bit[local_u8Index] = GET_BIT( copy_u8Value, local_u8Index);
	}

	GPIO_vidSetPinValue(LEDMTRX_ROW_0, local_u8Bit[0]);
	GPIO_vidSetPinValue(LEDMTRX_ROW_1, local_u8Bit[1]);
	GPIO_vidSetPinValue(LEDMTRX_ROW_2, local_u8Bit[2]);
	GPIO_vidSetPinValue(LEDMTRX_ROW_3, local_u8Bit[3]);
	GPIO_vidSetPinValue(LEDMTRX_ROW_4, local_u8Bit[4]);
	GPIO_vidSetPinValue(LEDMTRX_ROW_5, local_u8Bit[5]);
	GPIO_vidSetPinValue(LEDMTRX_ROW_6, local_u8Bit[6]);
	GPIO_vidSetPinValue(LEDMTRX_ROW_7, local_u8Bit[7]);
}

static void activateColumn (u8 copy_u8Col)
{
	/* Disable All */
	GPIO_vidSetPinValue(LEDMTRX_COL_0, HIGH_PIN);
	GPIO_vidSetPinValue(LEDMTRX_COL_1, HIGH_PIN);
	GPIO_vidSetPinValue(LEDMTRX_COL_2, HIGH_PIN);
	GPIO_vidSetPinValue(LEDMTRX_COL_3, HIGH_PIN);
	GPIO_vidSetPinValue(LEDMTRX_COL_4, HIGH_PIN);
	GPIO_vidSetPinValue(LEDMTRX_COL_5, HIGH_PIN);
	GPIO_vidSetPinValue(LEDMTRX_COL_6, HIGH_PIN);
	GPIO_vidSetPinValue(LEDMTRX_COL_7, HIGH_PIN);
	
	/* Enable the desired pin only */
	switch (copy_u8Col)
	{
		case 0: GPIO_vidSetPinValue(LEDMTRX_COL_0, LOW_PIN); break;
		case 1: GPIO_vidSetPinValue(LEDMTRX_COL_1, LOW_PIN); break;
		case 2: GPIO_vidSetPinValue(LEDMTRX_COL_2, LOW_PIN); break;
		case 3: GPIO_vidSetPinValue(LEDMTRX_COL_3, LOW_PIN); break;
		case 4: GPIO_vidSetPinValue(LEDMTRX_COL_4, LOW_PIN); break;
		case 5: GPIO_vidSetPinValue(LEDMTRX_COL_5, LOW_PIN); break;
		case 6: GPIO_vidSetPinValue(LEDMTRX_COL_6, LOW_PIN); break;
		case 7: GPIO_vidSetPinValue(LEDMTRX_COL_7, LOW_PIN); break;
	}
}