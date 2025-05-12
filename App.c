
/******************************************************************************
 *
 * Module: Main Application
 *
 * File Name: App.c
 *
 * Description: Main driver for controlling the car parking sensor system
 *              using Ultrasonic sensor, LEDs, and Buzzer.
 *
 * Author: Mostafa Hatem
 *
 *******************************************************************************/

#include "Ultrasonic.h"
#include "LED.h"
#include "buzzer.h"
#include "Interrupts.h"
#include "lcd.h"
#include <util/delay.h>

/*******************************************************************************
 *                              Helper Functions                               *
 *******************************************************************************/

/*
 * Description:
 * Turns ON all three LEDs (Red, Blue, Green).
 */
void turnOnAllLEDs(void)
{
    LED_on(RED_LED);
    LED_on(BLUE_LED);
    LED_on(GREEN_LED);
}

/*
 * Description:
 * Turns OFF all three LEDs (Red, Blue, Green).
 */
void turnOffAllLEDs(void)
{
    LED_off(RED_LED);
    LED_off(BLUE_LED);
    LED_off(GREEN_LED);
}

/*******************************************************************************
 *                           Main Function Definition                           *
 *******************************************************************************/

int main(void)
{
    uint16 distance;

    /* --- Initialization of peripherals and components --- */
    Interrupts_enableGlobalInterrupts();
    LCD_init();
    LEDS_init();
    Ultrasonic_init();
    Buzzer_init();

    LCD_displayString("Distance =    cm");

    while (1)
    {
        /* --- Read distance from the Ultrasonic sensor --- */
        distance = Ultrasonic_readDistance();

        /* --- Update the distance display on the LCD --- */
        LCD_moveCursor(0, 11);
        LCD_intgerToString(distance);

        /* --- Handle different distance ranges and perform corresponding actions --- */
        if (distance <= 5)
        {
            LCD_moveCursor(1, 6);
            LCD_displayString("STOP");
            _delay_ms(300);

            turnOnAllLEDs();
            Buzzer_on();
            _delay_ms(300);
            turnOffAllLEDs();
            Buzzer_off();
        }
        else if (distance >= 6 && distance <= 10)
        {
            /* --- Clear extra digit if distance is not 10 --- */
            if (distance != 10)
            {
                LCD_moveCursor(0, 12);
                LCD_displayCharacter(' ');
            }

            LCD_moveCursor(1, 6);
            LCD_displayString("    "); /* Clear "STOP" */

            turnOnAllLEDs();
            Buzzer_off();
        }
        else if (distance >= 11 && distance <= 15)
        {
            LED_on(RED_LED);
            LED_on(GREEN_LED);
            LED_off(BLUE_LED);
            Buzzer_off();
        }
        else if (distance >= 16 && distance <= 20)
        {
            LED_on(RED_LED);
            LED_off(GREEN_LED);
            LED_off(BLUE_LED);
            Buzzer_off();
        }
        else if (distance > 20 && distance <= 99)
        {
            /* --- Clean up previous digits displayed on the LCD --- */
            LCD_moveCursor(0, 13);
            LCD_displayCharacter(' ');

            turnOffAllLEDs();
            Buzzer_off();
        }
    }
}






