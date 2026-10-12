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
#include "gpio.h"
#include "quantum.h"
#include "rgblight.h"

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

#define LPD8806_SEND_BIT(byte, bit)              \
    do {                                         \
        gpio_write_pin(RGB_DI_PIN, (byte >> bit) & 1); \
        io_wait;                                \
        gpio_write_pin_high(RGB_CI_PIN);        \
        io_wait;                                \
        gpio_write_pin_low(RGB_CI_PIN);         \
        io_wait;                                \
    } while (0)

uint8_t lpd8806_led_brightness = LPD8806_DEFAULT_BRIGHTNESS;

#define LPD8806_LED_COUNT (RGBLIGHT_LED_COUNT / 2)

static rgb_t lpd8806_leds[LPD8806_LED_COUNT];

static void lpd8806_init(void);
static void lpd8806_flush(void);
static void lpd8806_send_frame(uint8_t red, uint8_t green, uint8_t blue);
static void lpd8806_send_byte(uint8_t byte);

static void lpd8806_set_color(int index, uint8_t red, uint8_t green, uint8_t blue) {
    if (index < 0 || index >= LPD8806_LED_COUNT) {
        return;
    }

    lpd8806_leds[index] = (rgb_t){red, green, blue};
}

static void lpd8806_set_color_all(uint8_t red, uint8_t green, uint8_t blue) {
    for (uint8_t i = 0; i < LPD8806_LED_COUNT; i++) {
        lpd8806_set_color(i, red, green, blue);
    }
}

const rgblight_driver_t rgblight_driver = {
    .init          = lpd8806_init,
    .set_color     = lpd8806_set_color,
    .set_color_all = lpd8806_set_color_all,
    .flush         = lpd8806_flush,
};

static void lpd8806_init(void) {
    gpio_set_pin_output(RGB_DI_PIN);
    gpio_set_pin_output(RGB_CI_PIN);

    gpio_write_pin_low(RGB_DI_PIN);
    gpio_write_pin_low(RGB_CI_PIN);
}

static void lpd8806_flush(void) {
    lpd8806_init();
    for (uint8_t i = 0; i < LPD8806_LED_COUNT; i++) {
        rgb_t led = lpd8806_leds[i];
        lpd8806_send_frame(led.r, led.g, led.b);
    }
    lpd8806_send_byte(0);
    lpd8806_send_byte(0);
    lpd8806_send_byte(0);
}

void lpd8806_set_brightness(uint8_t brightness) {
    if (brightness > LPD8806_MAX_BRIGHTNESS) {
        lpd8806_led_brightness = LPD8806_MAX_BRIGHTNESS;
    } else {
        lpd8806_led_brightness = brightness;
    }
}

static void lpd8806_send_frame(uint8_t red, uint8_t green, uint8_t blue) {
    uint8_t red_send, green_send, blue_send;
    red_send = (red >> 1) | 0x80;
    green_send = (green >> 1) | 0x80;
    blue_send = (blue >> 1) | 0x80;
    // LPD8806 is GRB
    lpd8806_send_byte(blue_send);
    lpd8806_send_byte(red_send);
    lpd8806_send_byte(green_send);
}

static void lpd8806_send_byte(uint8_t byte) {
    LPD8806_SEND_BIT(byte, 7);
    LPD8806_SEND_BIT(byte, 6);
    LPD8806_SEND_BIT(byte, 5);
    LPD8806_SEND_BIT(byte, 4);
    LPD8806_SEND_BIT(byte, 3);
    LPD8806_SEND_BIT(byte, 2);
    LPD8806_SEND_BIT(byte, 1);
    LPD8806_SEND_BIT(byte, 0);
}
