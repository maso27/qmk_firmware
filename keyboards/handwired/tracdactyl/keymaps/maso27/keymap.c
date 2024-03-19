/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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
#include QMK_KEYBOARD_H

#ifdef TRACDACTYL_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // TRACDACTYL_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum tracdactyl_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER = 1,
    LAYER_RAISE = 2,
    LAYER_POINTER = 3
};

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE,  // can always be here (4 bytes)
    KC_LOWER = TT(LAYER_LOWER), // MO(_LOWER),
    KC_RAISE = TT(LAYER_RAISE), // MO(_RAISE),
    KC_ULOCK = TO(LAYER_BASE), // return to main layer
    KC_PRVWD = LCTL(KC_LEFT),
    KC_NXTWD = LCTL(KC_RIGHT),
    KC_DWORD = LCTL(KC_BSPC),
    KC_CTLALTDEL = LCTL(LALT(KC_DEL)),
    KC_KILL  = LALT(KC_F4),
    KC_SH_DEL = LSFT(KC_DEL),
    KC_MOUSE = TT(LAYER_POINTER),
    PT_Z     = LT(LAYER_POINTER, KC_Z),
    PT_SLSH  = LT(LAYER_POINTER, KC_SLSH),
    PT_SCLN  = LT(LAYER_POINTER, KC_SCLN)
};

#ifdef TRACDACTYL_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef TRACDACTYL_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define TRACDACTYL_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // TRACDACTYL_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef TRACDACTYL_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define TRACDACTYL_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // TRACDACTYL_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // TRACDACTYL_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL  KC_NO
#    define DPI_MOD  KC_NO
#    define DPI_RMOD KC_NO
#    define S_D_MOD  KC_NO
#    define S_D_RMOD KC_NO
#    define SNIPING  KC_NO
#endif // !POINTING_DEVICE_ENABLE

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮                     ╭──────────────────────────────────────────────────────╮
        QK_GESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  // ├──────────────────────────────────────────────────────┤                     ├──────────────────────────────────────────────────────┤
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  // ├──────────────────────────────────────────────────────┤                     ├──────────────────────────────────────────────────────┤
       KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L, PT_SCLN, KC_QUOT,
  // ├──────────────────────────────────────────────────────┤                     ├──────────────────────────────────────────────────────┤
       KC_LCTL,    PT_Z,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_N,    KC_M, KC_COMM,  KC_DOT, PT_SLSH, SC_SENT,
  // ╰──────────────────────────────────────────────────────┤                     ├──────────────────────────────────────────────────────╯
                         KC_LGUI, KC_LALT, KC_MUTE, KC_LOWER, KC_BSPC,   KC_SPC, KC_RAISE,  KC_MINS,    KC_EQL, KC_BSLS,
                                                    DM_PLY1, KC_MOUSE,                                        KC_MS_BTN1
  //                                      ╰───────────────────────────╯ ╰───────────────────────────╯
  ),

  [LAYER_LOWER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮                     ╭──────────────────────────────────────────────────────╮
       KC_KILL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤                     ├──────────────────────────────────────────────────────┤
       RGB_MOD,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,     KC_0,   KC_F12,
  // ├──────────────────────────────────────────────────────┤                     ├──────────────────────────────────────────────────────┤
       RGB_TOG, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_PIPE,
  // ├──────────────────────────────────────────────────────┤                     ├──────────────────────────────────────────────────────┤
      RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR,                       KC_LBRC, KC_RBRC, _______, _______, KC_BSLS,  _______,
  // ╰──────────────────────────────────────────────────────┤                     ├──────────────────────────────────────────────────────╯
                    KC_CTLALTDEL, _______, RGB_MOD, KC_ULOCK, KC_SH_DEL,  _______, KC_ULOCK, KC_UNDS,  _______, _______,
                                                     DM_RSTP, KC_ULOCK,                                        _______
  //                                      ╰───────────────────────────╯ ╰───────────────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮                     ╭──────────────────────────────────────────────────────╮
       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤                     ├──────────────────────────────────────────────────────┤
       _______,  KC_INS, KC_PSCR,  KC_APP, XXXXXXX, XXXXXXX,                        KC_PGUP, KC_PRVWD,  KC_UP, KC_NXTWD,KC_DWORD, KC_DEL,
  // ├──────────────────────────────────────────────────────┤                     ├──────────────────────────────────────────────────────┤
       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS,                        KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤                     ├──────────────────────────────────────────────────────┤
       KC_RCTL, XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN,                        XXXXXXX, KC_HOME, XXXXXXX, KC_END,  XXXXXXX, KC_ENT,
  // ╰──────────────────────────────────────────────────────┤                     ├──────────────────────────────────────────────────────╯
                         _______, _______, _______, KC_ULOCK, KC_DEL,     _______, KC_ULOCK, KC_TILD, XXXXXXX, XXXXXXX,
                                                    DM_REC1, KC_ULOCK,                                       XXXXXXX
  //                                      ╰───────────────────────────╯ ╰───────────────────────────╯
  ),

  [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮                     ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤                     ├──────────────────────────────────────────────────────┤
       _______, RGB_MOD, RGB_VAI, RGB_SPI, S_D_MOD, DPI_MOD,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤                     ├──────────────────────────────────────────────────────┤
      _______, RGB_RMOD, RGB_VAD, RGB_SPD, S_D_RMOD, DPI_RMOD,                      XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, _______, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤                     ├──────────────────────────────────────────────────────┤
       _______, _______, DRGSCRL, SNIPING, EE_CLR,  QK_BOOT,                        QK_BOOT, EE_CLR,  SNIPING, DRGSCRL, _______, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤                     ├──────────────────────────────────────────────────────╯
                         _______, _______, RGB_TOG, KC_ULOCK, KC_DEL,     KC_BTN1, KC_ULOCK, KC_BTN2, XXXXXXX, XXXXXXX,
                                                    XXXXXXX, KC_ULOCK,                                        KC_BTN3
  //                                      ╰───────────────────────────╯ ╰───────────────────────────╯
  ),
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef TRACDACTYL_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > TRACDACTYL_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > TRACDACTYL_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= TRACDACTYL_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // TRACDACTYL_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef TRACDACTYL_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    tracdactyl_set_pointer_sniping_enabled(layer_state_cmp(state, TRACDACTYL_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // TRACDACTYL_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);

#include "rgb_led.c"

#endif

#ifdef ENCODER_ENABLE
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
        [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_WH_U, KC_WH_D)  },
        [1] =   { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),  ENCODER_CCW_CW(RGB_SPI, RGB_SPD)  },
        [2] =   { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_UP, KC_DOWN)  },
        [3] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_WH_U, KC_WH_D)  }
    };
#endif
