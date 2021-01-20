/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Jan 19,   2021                                                    */
/*********************************************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


#define GPIOA_BASE_ADDRESS        0x40010800            /* Boundary address of GPIO port A */
#define GPIOB_BASE_ADDRESS        0x40010C00            /* Boundary address of GPIO port B */
#define GPIOC_BASE_ADDRESS        0x40011000            /* Boundary address of GPIO port C */


/* PORTA Registers */
#define GPIOA_CRL                 *((u32*)(GPIOA_BASE_ADDRESS + 0x00))
#define GPIOA_CRH                 *((u32*)(GPIOA_BASE_ADDRESS + 0x04))
#define GPIOA_IDR                  *( (volatile u32*) (GPIOA_BASE_ADDRESS + 0x08))
#define GPIOA_ODR                 *((u32*)(GPIOA_BASE_ADDRESS + 0x0c))
#define GPIOA_BSR                 *((u32*)(GPIOA_BASE_ADDRESS + 0x10))
#define GPIOA_BRR                 *((u32*)(GPIOA_BASE_ADDRESS + 0x14))
#define GPIOA_LCK                 *((u32*)(GPIOA_BASE_ADDRESS + 0x18))

/* PORTB Registers */
#define GPIOB_CRL                 *((u32*)(GPIOB_BASE_ADDRESS + 0x00))
#define GPIOB_CRH                 *((u32*)(GPIOB_BASE_ADDRESS + 0x04))
#define GPIOB_IDR                 *((u32*)(GPIOB_BASE_ADDRESS + 0x08))
#define GPIOB_ODR                 *((u32*)(GPIOB_BASE_ADDRESS + 0x0c))
#define GPIOB_BSR                 *((u32*)(GPIOB_BASE_ADDRESS + 0x10))
#define GPIOB_BRR                 *((u32*)(GPIOB_BASE_ADDRESS + 0x14))
#define GPIOB_LCK                 *((u32*)(GPIOB_BASE_ADDRESS + 0x18))

/* PORTC Registers */
#define GPIOC_CRL                 *((u32*)(GPIOC_BASE_ADDRESS + 0x00))
#define GPIOC_CRH                 *((u32*)(GPIOC_BASE_ADDRESS + 0x04))
#define GPIOC_IDR                 *((u32*)(GPIOC_BASE_ADDRESS + 0x08))
#define GPIOC_ODR                 *((u32*)(GPIOC_BASE_ADDRESS + 0x0c))
#define GPIOC_BSR                 *((u32*)(GPIOC_BASE_ADDRESS + 0x10))
#define GPIOC_BRR                 *((u32*)(GPIOC_BASE_ADDRESS + 0x14))
#define GPIOC_LCK                 *((u32*)(GPIOC_BASE_ADDRESS + 0x18))


#endif