/******************************************************************************
 *
 * Module: Interrupts
 *
 * File Name: Interrupts.h
 *
 * Description: Header file for enabling and disabling global interrupts
 *
 * Author: Mostafa Hatem
 *
 *******************************************************************************/

#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include <avr/io.h>

/*******************************************************************************
 *                              Function Prototypes                            *
 *******************************************************************************/

/*
 * Description:
 * Enables global interrupts by setting the I-bit in the Status Register (SREG).
 */
static inline void Interrupts_enableGlobalInterrupts(void)
{
    SREG |= (1 << 7);
}

/*
 * Description:
 * Disables global interrupts by clearing the I-bit in the Status Register (SREG).
 */
static inline void Interrupts_disableGlobalInterrupts(void)
{
    SREG &= ~(1 << 7);
}

#endif /* INTERRUPTS_H_ */
