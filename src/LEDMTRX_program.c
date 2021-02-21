#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"
#include "STP_interface.h"

#include "LEDMTRX_interface.h"
#include "LEDMTRX_private.h"
#include "LEDMTRX_config.h"

/* Global variables */
u8 	global_u8CurrentIndex 	= 0;
u8 	global_u8Start 			= 0;
u8 	global_u8End 			= 0;
u32 global_u32Counter 		= 0;
u8 *global_u8Frame			   ;

void LEDMTRX_vidInit(void)
{	
#if LEDMTRX_CONTROL == LEDMTRX_CONTROLLED_BY_PINS
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

#elif LEDMTRX_CONTROL == LEDMTRX_CONTROLLED_BY_STP_CONVERTER
	/* Init Serial to Parallel Converters */
	STP_1_vidInit();
	STP_2_vidInit();

#endif
}

void LEDMTRX_vidDisplayFrame(u8 *copy_u8Frame, u8 copy_u8Length)
{
	
	global_u8Frame = copy_u8Frame;	/* Save the desired Frame	*/
	global_u8CurrentIndex = 0;		/* Reset the frame Start 	*/
	global_u32Counter = 0;			/* Reset the counter 		*/

#if LEDMTRX_DISPLAY_ORDER == LEDMTRX_LEFT_TO_RIGHT
	global_u8Start = 0;
	global_u8End = copy_u8Length;

#elif LEDMTRX_DISPLAY_ORDER == LEDMTRX_RIGHT_TO_LEFT
	global_u8End = copy_u8Length;
	global_u8Start = global_u8End - 8;

#endif
	
	activateColumn (global_u8CurrentIndex);					/* Dislay the tirst column 	*/
	setRowsValue   (copy_u8Frame[global_u8CurrentIndex]);	/* Display The rows value 	*/
	STK_vidSetIntervalPeriodic(2000,displayNextColumn);		/* Start timer 				*/
}

static void displayNextColumn (void)
{
	global_u8CurrentIndex++;
	global_u32Counter++;

	if (global_u8CurrentIndex == 8)
	{
		global_u8CurrentIndex = 0;
	}

	if (global_u32Counter == LEDMTRX_SPEED_MS/2) {

		global_u32Counter = 0;

#if LEDMTRX_DISPLAY_ORDER == LEDMTRX_LEFT_TO_RIGHT

		if (global_u8End - global_u8Start == 8) {
			global_u8Start = 0;
		}
		else {
			global_u8Start++;
		}

#elif LEDMTRX_DISPLAY_ORDER == LEDMTRX_RIGHT_TO_LEFT
		if (global_u8Start == 0) {
			global_u8Start = global_u8End - 8;
		}
		else {
			global_u8Start--;
		}

#endif

	}
	
	
	/* Dislay The first Column */
	activateColumn(global_u8CurrentIndex);
	setRowsValue  (global_u8Frame[global_u8CurrentIndex + global_u8Start]);
}

static void setRowsValue (u8 copy_u8Value)
{
#if LEDMTRX_CONTROL == LEDMTRX_CONTROLLED_BY_PINS
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
#elif LEDMTRX_CONTROL == LEDMTRX_CONTROLLED_BY_STP_CONVERTER
	STP_1_vidSendSynchronus(copy_u8Value);
#endif
}

static void activateColumn (u8 copy_u8Col)
{
#if LEDMTRX_CONTROL == LEDMTRX_CONTROLLED_BY_PINS
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
#elif LEDMTRX_CONTROL == LEDMTRX_CONTROLLED_BY_STP_CONVERTER
	STP_2_vidSendSynchronus(1<<copy_u8Col);
#endif

}