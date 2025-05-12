/******************************************************************************
 *
 * Module: Ultrasonic Sensor
 *
 * File Name: ultrasonic.h
 *
 * Description: Header file for the Ultrasonic Sensor driver
 *
 * Author: Mostafa Hatem
 *
 *******************************************************************************/

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"
#include "gpio.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define ULTRASONIC_TRIG_PORT_ID PORTD_ID
#define ULTRASONIC_TRIG_PIN_ID  PIN7_ID

/*******************************************************************************
 *                              Function Prototypes                            *
 *******************************************************************************/

/*
 * Description:
 * Function to initialize the Ultrasonic sensor driver.
 * - Initializes the ICU to detect edges on the Echo pin.
 * - Configures the trigger pin as output.
 */
void Ultrasonic_init(void);

/*
 * Description:
 * Function to send a 10µs trigger pulse to the Ultrasonic sensor.
 */
void Ultrasonic_Trigger(void);

/*
 * Description:
 * Function to trigger the sensor and wait for the Echo response.
 * - Waits for the Echo signal to complete.
 * - Returns the measured distance in centimeters.
 */
uint16 Ultrasonic_readDistance(void);

/*
 * Description:
 * ICU callback function used to handle edge detection.
 * - On rising edge: resets timer and sets to detect falling edge.
 * - On falling edge: captures timer value and signals measurement done.
 */
void Ultrasonic_edgeProcessing(void);

#endif /* ULTRASONIC_H_ */


