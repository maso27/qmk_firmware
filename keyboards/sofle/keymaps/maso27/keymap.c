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

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY = 0,
    _GAMING = 1,
    _LOWER = 2,
    _RAISE = 3
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_GAMING,
    KC_LOWER,
    KC_RAISE,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
    KC_BSPC_DEL
};

bool shift_held = false;

#include "oled.c"
#include "encoder.c"


//Default keymap. This can be changed in Via. Use oled.c and encoder.c to change beavior that Via cannot change.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * MASO QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| Mute  |    | GAMING|------+------+------+------+------+------|
 * | LCTR |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |Enter |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | RCTR |LOWER | / Space /       \Space \  |Raise |  `   |  =   |  \   |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC, // KC_BSPC_DEL,
  KC_LSFT,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LCTRL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     TG(_GAMING),KC_N, KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
                 KC_LGUI,KC_LALT, KC_RCTRL, MO(_LOWER), KC_SPC,      KC_SPC, MO(_RAISE), KC_GRV, KC_EQL, KC_BSLS
),

/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 *

[0] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 KC_LGUI,KC_LALT,KC_LCTRL, MO(2), KC_ENT,            KC_SPC,  MO(3), KC_RCTRL, KC_RALT, KC_RGUI
),*/
/*
 * GAMING
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | Left | Down | Right|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */

[_GAMING] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                          _______,  _______, _______,  _______,  _______,_______,
  _______, _______ , _______ , _______ , _______ , _______,                          _______,  _______,   KC_UP,  _______,  _______,_______,
  _______, _______ , _______ , _______ , _______ , _______,                          _______,  KC_LEFT, KC_DOWN, KC_RIGHT,  _______,_______,
  _______, _______ , _______ , _______ , _______ , _______,  _______,      _______,  _______,  _______, _______,  _______,  _______,_______,
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR,  _______,      _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                    _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  XX  |  XX  | XX   | XX   |  XX  |                    | XX   |  XX  | XX   | XX   | XX   | BkSpc|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Ins  | Pscr | Menu | XX   |  XX  |                    | PgUp | PWrd |  Up  | NWrd | DLine| Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | LAlt | LCtl |LShift| XX   | Caps |-------.    ,-------| PgDn | Left | Down | Right| XX   | XX   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | Undo |  Cut | Copy | Paste| XX   |-------|    |-------| XX   | Home | XX   | End  | XX   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
  _______,  KC_INS, KC_PSCR,  KC_APP, XXXXXXX, XXXXXXX,                        KC_PGUP, KC_PRVWD,  KC_UP, KC_NXTWD,KC_DLINE, KC_DEL,
  _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS,                        KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
  _______, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE, XXXXXXX,  _______,      _______,  XXXXXXX, KC_HOME,XXXXXXX, KC_END,XXXXXXX, _______,
                      _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______
)
};

/* Smart Backspace Delete */
static uint16_t held_shift = 0;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;

        /* Smart Backspace Delete (also controls volume knob)*/
        case KC_RSFT:
        case KC_LSFT:
            shift_held = record->event.pressed;
            held_shift = keycode;
            break;
        /*case KC_BSPC_DEL:
            if (record->event.pressed) {
                if (shift_held) {
                    unregister_code(held_shift);
                    register_code(KC_DEL);
                } else {
                    register_code(KC_BSPC);
                }
            } else {
                unregister_code(KC_DEL);
                unregister_code(KC_BSPC);
                if (shift_held) {
                    register_code(held_shift);
                }
            }
            return false;*/
    }
    return true;
}

#ifdef RGBLIGHT_ENABLE
    /*  RGB LAYER STUFF  */
    /*
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  33  |  32  |  24  |  23  |  14  |  13  |                    |  50  |  51  |  60  |  61  |  69  |  70  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  34  |  31  |  25  |  22  |  15  |  12  |                    |  49  |  52  |  59  |  62  |  68  |  71  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  35  |  30  |  26  |  21  |  16  |  11  |-------.    ,-------|  48  |  53  |  58  |  63  |  67  |  72  |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |  36  |  29  |  27  |  20  |  17  |  10  |-------|    |-------|  47  |  54  |  57  |  64  |  66  |  73  |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            |  28  |  19  |  18  |   9  | /   8   /       \  45  \  |  46  |  55  |  56  |  65  |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `---------------------------'-------'           '------''---------------------------'
     *       UNDERGLOW = 0-7                                                UNDERGLOW = 37-44
     */
    // Light underglow blue when in standard mode
    const rgblight_segment_t PROGMEM my_base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 8, HSV_BLUE},      // Light 8 LEDs, starting with LED 0 (UNDERGLOW)
        {9, 1, HSV_PURPLE},
        {46, 1, HSV_GREEN},
        {37, 8, HSV_BLUE}      // (UNDERGLOW)
    );

    // Light underglow and gaming-specific keys in white when keyboard layer 1 is active
    const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 8, HSV_WHITE},      // Light 8 LEDs, starting with LED 0 (UNDERGLOW)
        {21, 1, HSV_WHITE},
        {25, 2, HSV_WHITE},
        {30, 1, HSV_WHITE},
        {37, 8, HSV_WHITE},      // (UNDERGLOW)
        {53, 1, HSV_WHITE},
        {58, 2, HSV_WHITE},
        {63, 1, HSV_WHITE}
    );
    // Light LEDs 11 & 12 in purple when keyboard layer 2 is active
    const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 8, HSV_PURPLE},      // Light 8 LEDs, starting with LED 0 (UNDERGLOW)
        {37, 8, HSV_PURPLE}      // (UNDERGLOW)
    );
    // Light LEDs 13 & 14 in green when keyboard layer 3 is active
    const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 8, HSV_GREEN},      // Light 8 LEDs, starting with LED 0 (UNDERGLOW)
        {11, 1, HSV_RED},
        {17, 1, HSV_GREEN},
        {20, 3, HSV_GREEN},
        {25, 3, HSV_GREEN},
        {29, 3, HSV_GREEN},
        {37, 8, HSV_GREEN},     // (UNDERGLOW)
        {48, 2, HSV_GREEN},
        {52, 1, HSV_GREEN},
        {53, 1, HSV_RED},
        {54, 1, HSV_GREEN},
        {58, 2, HSV_RED},
        {62, 1, HSV_GREEN},
        {63, 1, HSV_RED},
        {64, 1, HSV_GREEN},
        {68, 1, HSV_RED},
        {70, 2, HSV_GREEN}
       
    );
    // Light underglow red when caps lock is active. Hard to ignore!
    const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 8, HSV_RED},      // Light 8 LEDs, starting with LED 0 (UNDERGLOW)
        {37, 8, HSV_RED}      // (UNDERGLOW)
    );

    // Now define the array of layers. Later layers take precedence
    const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
        my_base_layer,
        my_layer1_layer,    // Overrides base layer
        my_layer2_layer,    // Overrides other layers
        my_layer3_layer,    // Overrides other layers
        my_capslock_layer   // Overrides all other layers
    );

    void keyboard_post_init_user(void) {
        // Enable the LED layers
        rgblight_layers = my_rgb_layers;
    }

    bool led_update_user(led_t led_state) {
        rgblight_set_layer_state(4, led_state.caps_lock);
        return true;
    }

    layer_state_t default_layer_state_set_user(layer_state_t state) {
        rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
        return state;
    }

    layer_state_t layer_state_set_user(layer_state_t state) {
        rgblight_set_layer_state(1, layer_state_cmp(state, _GAMING));
        rgblight_set_layer_state(2, layer_state_cmp(state, _LOWER));
        rgblight_set_layer_state(3, layer_state_cmp(state, _RAISE));
        return state;
    }
#endif
