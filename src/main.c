#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"

#define PORTA_CRL *((u32*)0x40010800)
#define PORTA_ODR *((u32*)0x4001080C)
void main (void) {
    RCC_voidInitSysClock();
    RCC_voidEnableClock(RCC_APB2, 2);
    PORTA_CRL = 0x00000002;
    PORTA_ODR = 0x00000001;





    while (1)
    {
        
    }
    
}