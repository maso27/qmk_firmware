/* Copyright 2020 Aldehir Rojas
 * Copyright 2017 Mikkel (Duckle29)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "lpd8806.h"
#include "quantum.h"

#ifndef LPD8806_NOPS
#    if defined(__AVR__)
#        define LPD8806_NOPS 0  // AVR at 16 MHz already spends 62.5 ns per clock, so no extra delay is needed
#    elif defined(PROTOCOL_CHIBIOS)

#        include "hal.h"
#        if defined(STM32F0XX) || defined(STM32F1XX) || defined(STM32F3XX) || defined(STM32F4XX) || defined(STM32L0XX) || defined(GD32VF103)
#            define LPD8806_NOPS (100 / (1000000000L / (CPU_CLOCK / 4)))  // This calculates how many loops of 4 nops to run to delay 100 ns
#        else
#            error("LPD8806_NOPS configuration required")
#            define LPD8806_NOPS 0  // this just pleases the compile so the above error is easier to spot
#        endif
#    endif
#endif

#define io_wait                                 \
    do {                                        \
        for (int i = 0; i < LPD8806_NOPS; i++) { \
            __asm__ volatile("nop\n\t"          \
                             "nop\n\t"          \
                             "nop\n\t"          \
                             "nop\n\t");        \
        }                                       \
    } while (0)

#define LPD8806_SEND_BIT(byte, bit)               \
    do {                                         \
        writePin(RGB_DI_PIN, (byte >> bit) & 1); \
        io_wait;                                 \
        writePinHigh(RGB_CI_PIN);                \
        io_wait;                                 \
        writePinLow(RGB_CI_PIN);                 \
        io_wait;                                 \
    } while (0)
        
uint8_t lpd8806_led_brightness = LPD8806_DEFAULT_BRIGHTNESS;

void static lpd8806_init(void);

void static lpd8806_end_frame(void);

void static lpd8806_send_frame(uint8_t red, uint8_t green, uint8_t blue, uint8_t brightness);
void static lpd8806_send_byte(uint8_t byte);

void lpd8806_setleds(LED_TYPE *start_led, uint16_t num_leds) {
    LED_TYPE *end = start_led + num_leds;
    
    lpd8806_init();
    for (LED_TYPE *led = start_led; led < end; led++) {
        lpd8806_send_frame(led->r, led->g, led->b, lpd8806_led_brightness);
    }
    lpd8806_end_frame();
}

// Overwrite the default rgblight_call_driver to use lpd8806 driver
void rgblight_call_driver(LED_TYPE *start_led, uint8_t num_leds) { lpd8806_setleds(start_led, num_leds); }

void static lpd8806_init(void) {
    setPinOutput(RGB_DI_PIN);
    setPinOutput(RGB_CI_PIN);

    writePinLow(RGB_DI_PIN);
    writePinLow(RGB_CI_PIN);
}

void lpd8806_set_brightness(uint8_t brightness) {
    if (brightness > LPD8806_MAX_BRIGHTNESS) {
        lpd8806_led_brightness = LPD8806_MAX_BRIGHTNESS;
    } else if (brightness < 0) {
        lpd8806_led_brightness = 0;
    } else {
        lpd8806_led_brightness = brightness;
    }
}

void static lpd8806_send_frame(uint8_t red, uint8_t green, uint8_t blue, uint8_t brightness) {
    uint8_t red_send, green_send, blue_send;
    red_send = (red >> 1) | 0x80;
    green_send = (green >> 1) | 0x80;
    blue_send = (blue >> 1) | 0x80;
    // LPD8806 is GRB
    lpd8806_send_byte(blue_send);
    lpd8806_send_byte(red_send);
    lpd8806_send_byte(green_send);
}

void static lpd8806_end_frame() {
    for (uint16_t i = 0; i < 3; i++) {
        lpd8806_send_byte(0);
    }
    lpd8806_init();
}

void static lpd8806_send_byte(uint8_t byte) {
    LPD8806_SEND_BIT(byte, 7);
    LPD8806_SEND_BIT(byte, 6);
    LPD8806_SEND_BIT(byte, 5);
    LPD8806_SEND_BIT(byte, 4);
    LPD8806_SEND_BIT(byte, 3);
    LPD8806_SEND_BIT(byte, 2);
    LPD8806_SEND_BIT(byte, 1);
    LPD8806_SEND_BIT(byte, 0);
}
