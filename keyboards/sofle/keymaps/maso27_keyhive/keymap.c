 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE,  // can always be here (4 bytes)
    KC_PRVWD = LCTL(KC_LEFT),
    KC_NXTWD = LCTL(KC_RIGHT),
    KC_DWORD = LCTL(KC_BSPC),
    KC_CTLALTDEL = LCTL(LALT(KC_DEL)),
    KC_KILL = LALT(KC_F4),
    KC_SH_DEL = LSFT(KC_DEL)
};

enum custom_layers {
    _DEFAULTS = 0,
    _QWERTY = 0,
    _GAMING = 1,
    _LOWER = 2,
    _RAISE = 3
};

#include "oled.c"
#include "encoder.c"
#include "rgb_led.c"

// Extra keys are added for rotary encoder support in VIA
#define LAYOUT_via( \
    LA1, LA2, LA3, LA4, LA5, LA6,           RA6, RA5, RA4, RA3, RA2, RA1, \
    LB1, LB2, LB3, LB4, LB5, LB6, LB7, RB7, RB6, RB5, RB4, RB3, RB2, RB1, \
    LC1, LC2, LC3, LC4, LC5, LC6, LE1, RE6, RC6, RC5, RC4, RC3, RC2, RC1, \
    LD1, LD2, LD3, LD4, LD5, LD6, LD7, RD7, RD6, RD5, RD4, RD3, RD2, RD1, \
              LE2, LE3, LE4, LE5, LE6, RE5, RE4, RE3, RE2, RE1 \
    ) \
    { \
        { LA1, LA2, LA3, LA4, LA5, LA6, KC_NO }, \
        { LB1, LB2, LB3, LB4, LB5, LB6, LB7   }, \
        { LC1, LC2, LC3, LC4, LC5, LC6, KC_NO }, \
        { LD1, LD2, LD3, LD4, LD5, LD6, LD7   }, \
        { LE1, LE2, LE3, LE4, LE5, LE6, KC_NO }, \
        { RA1, RA2, RA3, RA4, RA5, RA6, KC_NO }, \
        { RB1, RB2, RB3, RB4, RB5, RB6, RB7   }, \
        { RC1, RC2, RC3, RC4, RC5, RC6, KC_NO }, \
        { RD1, RD2, RD3, RD4, RD5, RD6, RD7   }, \
        { RE1, RE2, RE3, RE4, RE5, RE6, KC_NO } \
    }

//Default keymap. This can be changed in Via. Use oled.c to change beavior that Via cannot change.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                     ,-----------------------------------------.
 * | ESC/~|   1  |   2  |   3  |   4  |   5  |-------.  E  ,-------|   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------| Vol+  |< N >| SCRL+ |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |-------.  C  ,-------|   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------| Mute  |< O >|GAMING |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.  D  ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| Vol-  |< E >| SCRL- |------+------+------+------+------+------|
 * | LCTR |   Z  |   X  |   C  |   V  |   B  |-------|  R  |-------|   N  |   M  |   ,  |   .  |   /  |Ent/Shft |
 * `-----------------------------------------/       /      \      \-----------------------------------------'
 *            | LGUI | LAlt |MACRO |LOWER | / Bspc  /        \Space \  |RAISE |  -   |  =   |  \   |
 *            |      |      | Play |      |/       /          \      \ |      |      |      |      |
 *            `-----------------------------------'            '------''---------------------------'
 */

[_QWERTY] = LAYOUT_via(
  QK_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                         KC_6    , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
  KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_VOLU,       KC_WH_U, KC_Y    , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
  KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_MUTE,   TG(_GAMING), KC_H    , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
  KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_VOLD,       KC_WH_D, KC_N    , KC_M   , KC_COMM, KC_DOT , KC_SLSH, SC_SENT,
                  KC_LGUI,KC_LALT,DM_PLY1,TT(_LOWER), KC_BSPC ,         KC_SPC  ,TT(_RAISE), KC_MINS, KC_EQL, KC_BSLS
),

/*
 * GAMING
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|MouseRt|    |MouseUp|------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |  Up  |      |      |      |
 * |------+------+------+------+------+------|LtClick|    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | Left | Down | Right|      |      |
 * |------+------+------+------+------+------|MouseLt|    |MouseDn|------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | / Space /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */

[_GAMING] = LAYOUT_via(
  _______, _______ , _______ , _______ , _______ , _______,                          _______,  _______, _______,  _______,  _______,_______,
  _______, _______ , _______ , _______ , _______ , _______,  KC_MS_R,      KC_MS_U,  _______,  _______,   KC_UP,  _______,  _______,_______,
  _______, _______ , _______ , _______ , _______ , _______, KC_MS_BTN1,    _______,  _______,  KC_LEFT, KC_DOWN, KC_RIGHT,  _______,_______,
  _______, _______ , _______ , _______ , _______ , _______,  KC_MS_L,      KC_MS_D,  _______,  _______, _______,  _______,  _______,_______,
                         _______, _______, _______, _______, KC_SPC,       _______, _______, _______, _______, _______
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |ALTF4 |  F1  |  F2  |  F3  |  F4  |  F5  |-------.  E  ,-------|  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------| RGBUp |< N >|RGBSpd+|------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |-------.  C  ,-------|   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|RGBNext|< O >|  RGB  |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |-------.  D  ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------| RGBDn |< E >|RGBSpd-|------+------+------+------+------+------|
 * |      |  XX  |  XX  |  XX  |   {  |   }  |-------|  R  |-------|   [  |   ]  |      |      |   \  |      |
 * `-----------------------------------------/       /      \      \-----------------------------------------'
 *            |CtlAlt|      |      |      | /Shift- /        \      \  |      |  _   |      |      |
 *            |  Del |      |      |      |/  Del  /          \      \ |      |      |      |      |
 *            `-----------------------------------'            '------''---------------------------'
 */
[_LOWER] = LAYOUT_via(
  KC_KILL, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                         KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
  _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , RGB_VAI,       RGB_SPI, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_F12 ,
  _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, RGB_MOD,       RGB_TOG, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______, KC_EQL , KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, RGB_VAD,       RGB_SPD, KC_LBRC, KC_RBRC, _______, _______, KC_BSLS, _______,
             KC_CTLALTDEL, _______, _______, _______, KC_SH_DEL,      _______, _______, KC_UNDS, _______, _______
),
/* RAISE
 * ,----------------------------------------.                      ,-----------------------------------------.
 * |      |  XX  |  XX  |  XX  |  XX  |  XX  |-------.  E  ,-------|  XX  |  XX  |  XX  |  XX  |  XX  |  XX  |
 * |------+------+------+------+------+------| Right |< N >|  Up   |------+------+------+------+------+------|
 * |      | Ins  | Pscr | Menu |  XX  |  XX  |-------.  C  ,-------| PgUp | PWrd |  Up  | NWrd | DWord| Del  |
 * |------+------+------+------+------+------|       |< O >|       |------+------+------+------+------+------|
 * |      |  XX  |  XX  |  XX  |  XX  | Caps |-------.  D  ,-------| PgDn | Left | Down | Right| Bspc |  XX  |
 * |------+------+------+------+------+------| Left  |< E >| Down  |------+------+------+------+------+------|
 * | RCTR |  XX  |  XX  |  XX  |  (   |  )   |-------|  R  |-------|  XX  | Home |  XX  |  End |  XX  | Enter|
 * `-----------------------------------------/      /       \      \-----------------------------------------'
 *            |      |      |MACRO |      | / Del  /         \      \  |      |   ~  |      |      |
 *            |      |      |  Rec |      |/      /           \      \ |      |      |      |      |
 *            `----------------------------------'             '------''---------------------------'
 */
[_RAISE] = LAYOUT_via(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, KC_INS , KC_PSCR, KC_APP , XXXXXXX , XXXXXXX, KC_RIGHT,     KC_UP,  KC_PGUP,KC_PRVWD, KC_UP  ,KC_NXTWD,KC_DWORD, KC_DEL,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX , KC_CAPS, _______,    _______,  KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, XXXXXXX,
  KC_RCTL, XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN , KC_RPRN, KC_LEFT,    KC_DOWN,  XXXXXXX, KC_HOME, XXXXXXX,  KC_END, XXXXXXX, KC_ENT,
                   _______, _______, DM_REC1, _______, KC_DEL,        _______, _______, KC_TILD, _______, _______
)
};

// Custom keycode handling.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // handling this once instead of in each keycode uses less program memory.
    if ((keycode >= SAFE_RANGE) && !(record->event.pressed)) {
        return false;
    }

    // this uses less memory than returning in each case.
    return keycode < SAFE_RANGE;
};
