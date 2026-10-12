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

#pragma once

#include "color.h"

#ifndef LPD8806_DEFAULT_BRIGHTNESS
#    define LPD8806_DEFAULT_BRIGHTNESS 31
#endif

#define LPD8806_MAX_BRIGHTNESS 31

extern uint8_t lpd8806_led_brightness;

/* User Interface
 *
 * Input:
 */
void lpd8806_set_brightness(uint8_t brightness);
