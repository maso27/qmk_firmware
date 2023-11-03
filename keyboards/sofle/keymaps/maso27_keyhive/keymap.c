 /* Copyright 2021 Dane Evans
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

// SOFLE RGB SETUP

#include <stdio.h>
#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _DEFAULTS = 0,
    _QWERTY = 0,
    _GAMING = 1,
    _LOWER = 2,
    _RAISE = 3
};

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE,
    KC_LOWER = TT(_LOWER), // MO(_LOWER),
    KC_RAISE = TT(_RAISE), // MO(_RAISE),
    KC_ULOCK = TO(_DEFAULTS), // return to main layer
    KC_PRVWD = LCTL(KC_LEFT),
    KC_NXTWD = LCTL(KC_RIGHT),
    KC_DWORD = LCTL(KC_BSPC),
    KC_CTLALTDEL = LCA(KC_DEL),
    KC_KILL = LALT(KC_F4),
    KC_SH_DEL = LSFT(KC_DEL)
};

#ifdef RGBLIGHT_ENABLE
    #include "rgb_led.c"
#endif

#ifdef OLED_ENABLE
    #include "oled.c"
#endif

#ifdef ENCODER_MAP_ENABLE
    #include "encoder.c"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * MASO QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |ESC/~ |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| Mute  |    | GAMING|------+------+------+------+------+------|
 * | LCTR |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |Ent/Shft |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt |MACRO |LOWER | / Bspc  /       \Space \  |Raise |  -   |  =   |  \   |
 *            |      |      | Play |      |/       /         \      \ |      |      |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  QK_GESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
  KC_TAB,    KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  KC_LSFT,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LCTL,   KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE, TG(_GAMING),KC_N,   KC_M, KC_COMM,  KC_DOT, KC_SLSH,  SC_SENT,
                 KC_LGUI,KC_LALT, DM_PLY1, KC_LOWER, KC_BSPC,   KC_SPC, KC_RAISE, KC_MINS, KC_EQL, KC_BSLS
),


/*
 * GAMING
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | Left | Down | Right|      |      |
 * |------+------+------+------+------+------|LtClick|    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | / Space /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */

[_GAMING] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                          _______,  _______, _______,  _______,  _______,_______,
  _______, _______ , _______ , _______ , _______ , _______,                          _______,  _______,   KC_UP,  _______,  _______,_______,
  _______, _______ , _______ , _______ , _______ , _______,                          _______,  KC_LEFT, KC_DOWN, KC_RIGHT,  _______,_______,
  _______, _______ , _______ , _______ , _______ , _______, KC_MS_BTN1,    _______,  _______,  _______, _______,  _______,  _______,_______,
                         _______, _______, _______, _______, KC_SPC,       _______, _______, _______, _______, _______
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |ALTF4 |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|RGBNext|    |RGBOff |------+------+------+------+------+------|
 * |      |  XX  |  XX  |  XX  |   {  |   }  |-------|    |-------|   [  |   ]  |      |      |   \  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |CtlAlt|      |MACRO |Layers| /Shift- /       \      \  |Layers|  _   |      |      |
 *            |  Del |      | Stop |  OFF |/  Del  /         \      \ |  OFF |      |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  KC_KILL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  KC_GRV,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR,  RGB_MOD,      RGB_TOG, KC_LBRC, KC_RBRC, _______, _______, KC_BSLS, _______,
               KC_CTLALTDEL, _______, DM_RSTP,KC_ULOCK, KC_SH_DEL,     _______,KC_ULOCK, KC_UNDS, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  XX  |  XX  |  XX  |  XX  |  XX  |                    |  XX  |  XX  |  XX  |  XX  |  XX  |  XX  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Ins  | Pscr | Menu |  XX  |  XX  |                    | PgUp | PWrd |  Up  | NWrd | DWord| Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  XX  |  XX  |  XX  |  XX  | Caps |-------.    ,-------| PgDn | Left | Down | Right| BkSpc|  XX  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | RCTR |  XX  |  XX  |  XX  |  (   |  )   |-------|    |-------|  XX  | Home |  XX  | End  |  XX  | Enter|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |MACRO |Layers| /  Del  /       \      \  |Layers|  ~   |      |      |
 *            |      |      |  Rec |  OFF |/       /         \      \ |  OFF |      |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______,  KC_INS, KC_PSCR,  KC_APP, XXXXXXX, XXXXXXX,                        KC_PGUP, KC_PRVWD,  KC_UP, KC_NXTWD,KC_DWORD, KC_DEL,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS,                        KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, XXXXXXX,
  KC_RCTL, XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN,  _______,    _______,  XXXXXXX, KC_HOME, XXXXXXX, KC_END,XXXXXXX, KC_ENT,
                    _______, _______, DM_REC1,KC_ULOCK, KC_DEL,       _______,KC_ULOCK, KC_TILD, _______, _______
)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // handling this once instead of in each keycode uses less program memory.
    if ((keycode >= SAFE_RANGE) && !(record->event.pressed)) {
        return false;
    }

    // this uses less memory than returning in each case.
    return keycode < SAFE_RANGE;
}
