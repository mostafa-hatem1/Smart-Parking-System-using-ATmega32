/******************************************************************************
 *
 * Module: LED
 *
 * File Name: LED.h
 *
 * Description: Header file for the LED driver
 *
 * Author: Mostafa Hatem
 *
 *******************************************************************************/

#ifndef LED_H_
#define LED_H_

#include "gpio.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define POSITIVE_LOGIC 1
#define NEGATIVE_LOGIC 0

/* Red LED configuration */
#define RED_LED_PORT_ID     PORTC_ID
#define RED_LED_PIN_ID      PIN0_ID
#define RED_LED_LOGIC       POSITIVE_LOGIC

/* Green LED configuration */
#define GREEN_LED_PORT_ID   PORTC_ID
#define GREEN_LED_PIN_ID    PIN1_ID
#define GREEN_LED_LOGIC     POSITIVE_LOGIC

/* Blue LED configuration */
#define BLUE_LED_PORT_ID    PORTC_ID
#define BLUE_LED_PIN_ID     PIN2_ID
#define BLUE_LED_LOGIC      POSITIVE_LOGIC

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

/* Enum for LED identification */
typedef enum {
    RED_LED,
    GREEN_LED,
    BLUE_LED
} LED_ID;

/*******************************************************************************
 *                              Function Prototypes                            *
 *******************************************************************************/

/*
 * Description:
 * Initializes all the LED pins as output.
 */
void LEDS_init(void);

/*
 * Description:
 * Turns ON the specified LED.
 */
void LED_on(LED_ID id);

/*
 * Description:
 * Turns OFF the specified LED.
 */
void LED_off(LED_ID id);

#endif /* LED_H_ */

