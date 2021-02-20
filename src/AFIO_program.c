/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Feb 19,   2021                                                    */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"

void AFIO_vidRemap(u8 copy_u8Peripheral, u8 copy_u8Value)
{
    if (copy_u8Peripheral < 25)
    {
        switch (copy_u8Peripheral)
        {
        case AFIO_SWJ_CFG:
            copy_u8Value &= 0b00000111;
            AFIO_MAPR |= (copy_u8Value << AFIO_SWJ_CFG);
            break;
        case AFIO_CAN_REMAP:
        case AFIO_TIM3_REMAP:
        case AFIO_TIM2_REMAP:
        case AFIO_TIM1_REMAP:
        case AFIO_USART3_REMAP:
            copy_u8Value &= 0b00000011;
            AFIO_MAPR |= (copy_u8Value << copy_u8Peripheral);
            break;
        default:
            if (copy_u8Value)
            {
                SET_BIT(AFIO_MAPR, copy_u8Value);
            }
            else
            {
                CLR_BIT(AFIO_MAPR, copy_u8Value);
            }

            break;
        }
    }
    else
    {
        copy_u8Peripheral -= 20;
        if (copy_u8Value)
        {
            SET_BIT(AFIO_MAPR2, copy_u8Value);
        }
        else
        {
            CLR_BIT(AFIO_MAPR2, copy_u8Value);
        }
    }
}

void AFIO_vidSetSourceEXTI(u8 copy_u8Line, u8 copy_u8Port)
{

    switch (copy_u8Line)
    {
    case AFIO_EXTI_LINE0:
        AFIO_EXTICR1 &= 0xFFF0;
        AFIO_EXTICR1 |= (copy_u8Port << 0);
        break;
    case AFIO_EXTI_LINE1:
        AFIO_EXTICR1 &= 0xFF0F;
        AFIO_EXTICR1 |= (copy_u8Port << 4);
        break;
    case AFIO_EXTI_LINE2:
        AFIO_EXTICR1 &= 0xF0FF;
        AFIO_EXTICR1 |= (copy_u8Port << 8);
        break;
    case AFIO_EXTI_LINE3:
        AFIO_EXTICR1 &= 0x0FFF;
        AFIO_EXTICR1 |= (copy_u8Port << 12);
        break;
    case AFIO_EXTI_LINE4:
        AFIO_EXTICR2 &= 0xFFF0;
        AFIO_EXTICR2 |= (copy_u8Port << 0);
        break;
    case AFIO_EXTI_LINE5:
        AFIO_EXTICR2 &= 0xFF0F;
        AFIO_EXTICR2 |= (copy_u8Port << 4);
        break;
    case AFIO_EXTI_LINE6:
        AFIO_EXTICR2 &= 0xF0FF;
        AFIO_EXTICR2 |= (copy_u8Port << 8);
        break;
    case AFIO_EXTI_LINE7:
        AFIO_EXTICR2 &= 0x0FFF;
        AFIO_EXTICR2 |= (copy_u8Port << 12);
        break;
    case AFIO_EXTI_LINE8:
        AFIO_EXTICR3 &= 0xFFF0;
        AFIO_EXTICR3 |= (copy_u8Port << 0);
        break;
    case AFIO_EXTI_LINE9:
        AFIO_EXTICR3 &= 0xFF0F;
        AFIO_EXTICR3 |= (copy_u8Port << 4);
        break;
    case AFIO_EXTI_LINE10:
        AFIO_EXTICR3 &= 0xF0FF;
        AFIO_EXTICR3 |= (copy_u8Port << 8);
        break;
    case AFIO_EXTI_LINE11:
        AFIO_EXTICR3 &= 0x0FFF;
        AFIO_EXTICR3 |= (copy_u8Port << 12);
        break;
    case AFIO_EXTI_LINE12:
        AFIO_EXTICR4 &= 0xFFF0;
        AFIO_EXTICR4 |= (copy_u8Port << 0);
        break;
    case AFIO_EXTI_LINE13:
        AFIO_EXTICR4 &= 0xFF0F;
        AFIO_EXTICR4 |= (copy_u8Port << 4);
        break;
    case AFIO_EXTI_LINE14:
        AFIO_EXTICR4 &= 0xF0FF;
        AFIO_EXTICR4 |= (copy_u8Port << 8);
        break;
    case AFIO_EXTI_LINE15:
        AFIO_EXTICR4 &= 0x0FFF;
        AFIO_EXTICR4 |= (copy_u8Port << 12);
        break;
    default:
        break;
    }
}

void AFIO_vidEnableEventOutput(u8 copy_u8Port, u8 copy_u8Pin)
{
    AFIO_EVCR = 0;
    AFIO_EVCR = (1 << 7) | (copy_u8Port << 4) | (copy_u8Pin);
}