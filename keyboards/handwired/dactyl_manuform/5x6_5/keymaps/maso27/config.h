// Copyright 2021 Christian Eiden, cykedev
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#define TAPPING_TOGGLE 2
#define HOLD_ON_OTHER_KEY_PRESS // for layer toggle -- keypress faster

#define MASTER_LEFT
//#define EE_HANDS
// #define SPLIT_USB_DETECT

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

#ifdef ENCODER_ENABLE
    #define ENCODERS_PAD_A          {F5}
    #define ENCODERS_PAD_B          {F4}
    #define ENCODERS_PAD_A_RIGHT    {F4}
    #define ENCODERS_PAD_B_RIGHT    {F5}
#endif

// More lighting options in quantum/rgblight/rgblight.h
#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_MOOD+2

    // Disabling some of these is a good way to save flash space.
    // #define RGBLIGHT_EFFECT_ALTERNATING     // 108
    // #define RGBLIGHT_EFFECT_RGB_TEST        // 158
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD    // 160
    // #define RGBLIGHT_EFFECT_STATIC_GRADIENT // 168
    // #define RGBLIGHT_EFFECT_RAINBOW_SWIRL   // 192
    // #define RGBLIGHT_EFFECT_BREATHING       // 348
    // #define RGBLIGHT_EFFECT_KNIGHT          // 336
    // #define RGBLIGHT_EFFECT_SNAKE           // 406
    // #define RGBLIGHT_EFFECT_CHRISTMAS       // 508
    // #define RGBLIGHT_EFFECT_TWINKLE         // 1156

    #define RGBLIGHT_LAYERS
    #define RGBLIGHT_SLEEP
    #define RGBLIGHT_MAX_LAYERS 5
    
    #undef RGBLED_NUM
    #define RGBLED_NUM 36
    #define RGBLED_SPLIT {18,18}
    
    /* lpd8806 RGB LED */
    #define RGB_DI_PIN D3
    #define RGB_CI_PIN D2
    
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif


#define FORCE_NKRO

// Disabled to save space
#define NO_ACTION_ONESHOT  // 332
#define NO_ACTION_MACRO    // 0
#define NO_ACTION_FUNCTION // 0
#define DISABLE_LEADER     // 0
