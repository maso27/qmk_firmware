// Copyright 2020 Maso27
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _GAMING,
    _LOWER,
    _RAISE,
    _POINTER,
};

enum custom_keycodes {
    KC_LOWER = TT(_LOWER),
    KC_RAISE = TT(_RAISE),
    KC_MOUSE = TT(_POINTER),
    KC_ULOCK = TO(_BASE),
    KC_PRVWD = LCTL(KC_LEFT),
    KC_NXTWD = LCTL(KC_RIGHT),
    KC_DWORD = LCTL(KC_BSPC),
    KC_KILL = LALT(KC_F4),
    KC_CTLALTDEL = LCTL(LALT(KC_DEL)),
    KC_SH_DEL = LSFT(KC_DEL),
    PT_SCLN  = LT(_POINTER, KC_SCLN)
};

#ifdef RGBLIGHT_ENABLE
const rgblight_segment_t PROGMEM base_layer[] = RGBLIGHT_LAYER_SEGMENTS({5, 3, HSV_PURPLE}, {23, 3, HSV_PURPLE});
const rgblight_segment_t PROGMEM gaming_layer[] = RGBLIGHT_LAYER_SEGMENTS({5, 3, HSV_RED}, {23, 3, HSV_RED});
const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS({5, 3, HSV_BLUE}, {23, 3, HSV_BLUE});
const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS({5, 3, HSV_GREEN}, {23, 3, HSV_GREEN});
const rgblight_segment_t PROGMEM pointer_layer[] = RGBLIGHT_LAYER_SEGMENTS({5, 3, HSV_WHITE}, {23, 3, HSV_WHITE});
const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 18, HSV_RED}, {18, 18, HSV_RED});

const rgblight_segment_t *const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(base_layer, gaming_layer, lower_layer, raise_layer, pointer_layer, capslock_layer);
/* RGB LAYOUT
* .-----------------------------------------.                                  .-----------------------------------------.
* |      14     |      13     |      0      |                                  |      18     |      31     |      32     |
* |------+------+-------------+------+------|                                  |------+------+------+------+------+------|
* |      15     |      12     |      1      |                                  |      19     |      30     |      33     |
* |------+------+------11-----+------+------|                                  |------+------+------29-----+------+------|
* |      16     |      |      |      2      |                                  |      20     |      |      |      34     |
* |------+------+------10-----+------|------|                                  |------+------+------28-----+------+------|
* |      17     |      |      |      3      |                                  |      21     |      |      |      35     |
* '--------------------9-------------|------/                                  \--------------------27-------------------'
*               |      |      |    /  4    /---------------.    .---------------\    22 \    |      |      |
*               |      8      |   /    5  /       /       /      \       \       \  23   \   |      26     |
*               '-------------'  '-------/  6    /       /        \       \   24  \-------'  '-------------'
*                                       /---------------/          \---------------\
*                                      /       /       /            \       \       \
*                                     /       /  7    /              \    25 \       \
*                                    '---------------'                '---------------'
*/    
void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
    rgblight_set_layer_state(1, layer_state_cmp(state, _GAMING));
    rgblight_set_layer_state(2, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(3, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(4, layer_state_cmp(state, _POINTER));
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(5, led_state.caps_lock);
    return true;
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_5x6_5(
    // ╭──────────────────────────────────────────────────────╮                         ╭──────────────────────────────────────────────────────╮
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    // ├──────────────────────────────────────────────────────┤                         ├──────────────────────────────────────────────────────┤
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    // ├──────────────────────────────────────────────────────┤                         ├──────────────────────────────────────────────────────┤
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                KC_H,    KC_J,    KC_K,    KC_L,    PT_SCLN, KC_QUOT,
    // ├──────────────────────────────────────────────────────┤                         ├──────────────────────────────────────────────────────┤
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_SENT,
    // ╰──────────────────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────────────────╯
                    KC_LGUI, KC_LALT,           KC_MUTE, KC_LOWER, KC_BSPC,  KC_SPC, KC_RAISE, TG(_GAMING),       KC_EQL, KC_BSLS,
    //            ╰──────────────────╯         ╰──────────────────────────┤ ├──────────────────────────────╯    ╰──────────────────╯
                                                         DM_PLY1, KC_MOUSE,  MS_BTN1, MS_BTN3
    //                                                  ╰─────────────────╯ ╰────────────────╯  
    ),
    [_GAMING] = LAYOUT_5x6_5(
    // ╭──────────────────────────────────────────────────────╮                         ╭──────────────────────────────────────────────────────╮
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    // ├──────────────────────────────────────────────────────┤                         ├──────────────────────────────────────────────────────┤
        _______, _______, _______, _______, _______, _______,                            _______, _______, KC_UP,   _______, _______, _______,
    // ├──────────────────────────────────────────────────────┤                         ├──────────────────────────────────────────────────────┤
        _______, _______, _______, _______, _______, _______,                            _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    // ├──────────────────────────────────────────────────────┤                         ├──────────────────────────────────────────────────────┤
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    // ╰──────────────────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────────────────╯
                    _______, _______,            _______, _______, KC_SPC,     _______, _______, _______,         _______, _______,
    //            ╰──────────────────╯         ╰──────────────────────────┤ ├──────────────────────────────╯    ╰──────────────────╯
                                                         _______, _______,   _______, _______
    //                                                  ╰─────────────────╯ ╰────────────────╯  
    ),
    [_LOWER] = LAYOUT_5x6_5(
    // ╭──────────────────────────────────────────────────────╮                         ╭──────────────────────────────────────────────────────╮
        KC_KILL, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    // ├──────────────────────────────────────────────────────┤                         ├──────────────────────────────────────────────────────┤
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
    // ├──────────────────────────────────────────────────────┤                         ├──────────────────────────────────────────────────────┤
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    // ├──────────────────────────────────────────────────────┤                         ├──────────────────────────────────────────────────────┤
        _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR,                            KC_LBRC, KC_RBRC, _______, _______, KC_BSLS,  _______,
    // ╰──────────────────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────────────────╯
                KC_CTLALTDEL, _______,        RM_NEXT, KC_ULOCK, KC_SH_DEL,    _______, KC_ULOCK, KC_UNDS,        _______, _______,
    //            ╰──────────────────╯         ╰──────────────────────────┤ ├──────────────────────────────╯    ╰──────────────────╯
                                                         DM_RSTP, KC_ULOCK,  _______, _______
    //                                                  ╰─────────────────╯ ╰────────────────╯  
    ),
    [_RAISE] = LAYOUT_5x6_5(
    // ╭──────────────────────────────────────────────────────╮                         ╭──────────────────────────────────────────────────────╮
        KC_GRV,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // ├──────────────────────────────────────────────────────┤                         ├──────────────────────────────────────────────────────┤
        _______, KC_INS,  KC_PSCR, KC_APP,  XXXXXXX, XXXXXXX,                            KC_PGUP, KC_PRVWD, KC_UP, KC_NXTWD, KC_DWORD, KC_DEL,
    // ├──────────────────────────────────────────────────────┤                         ├──────────────────────────────────────────────────────┤
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS,                            KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, XXXXXXX,
    // ├──────────────────────────────────────────────────────┤                         ├──────────────────────────────────────────────────────┤
        KC_RCTL, XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN,                            XXXXXXX, KC_HOME, XXXXXXX, KC_END,  XXXXXXX, KC_ENT,
    // ╰──────────────────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────────────────╯
                    _______, _______,            _______, KC_ULOCK, KC_DEL,   _______, KC_ULOCK, KC_GRV,          _______, _______,
    //            ╰──────────────────╯         ╰──────────────────────────┤ ├──────────────────────────────╯    ╰──────────────────╯
                                                         DM_REC1, KC_ULOCK,  _______, _______
    //                                                  ╰─────────────────╯ ╰────────────────╯  
    ),
    [_POINTER] = LAYOUT_5x6_5(
    // ╭──────────────────────────────────────────────────────╮                         ╭──────────────────────────────────────────────────────╮
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // ├──────────────────────────────────────────────────────┤                         ├──────────────────────────────────────────────────────┤
        _______, XXXXXXX, XXXXXXX,  MS_UP,  XXXXXXX, XXXXXXX,                            MS_WHLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // ├──────────────────────────────────────────────────────┤                         ├──────────────────────────────────────────────────────┤
        _______, XXXXXXX, MS_LEFT, MS_DOWN, MS_RGHT, XXXXXXX,                            MS_WHLD, MS_BTN1, MS_BTN2, MS_BTN3, _______, XXXXXXX,
    // ├──────────────────────────────────────────────────────┤                         ├──────────────────────────────────────────────────────┤
        _______, XXXXXXX, XXXXXXX, XXXXXXX,  EE_CLR, QK_BOOT,                            QK_BOOT, EE_CLR,  XXXXXXX, XXXXXXX, _______, XXXXXXX,
    // ╰──────────────────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────────────────╯
                    _______, _______,           _______, KC_ULOCK, _______,    _______, KC_ULOCK, _______,        _______, _______,
    //            ╰──────────────────╯         ╰──────────────────────────┤ ├──────────────────────────────╯    ╰──────────────────╯
                                                         _______, KC_ULOCK,  _______, _______
    //                                                  ╰─────────────────╯ ╰────────────────╯  
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (layer_state_is(_RAISE)) {
            tap_code(clockwise ? KC_RGHT : KC_LEFT);
        } else if (layer_state_is(_LOWER)) {
            tap_code(clockwise ? UG_VALU : UG_VALD);
        } else if (layer_state_is(_GAMING)) {
            tap_code(clockwise ? MS_RGHT : MS_LEFT);
        } else {
            tap_code(clockwise ? KC_VOLU : KC_VOLD);
        }
    } else if (index == 1) {
        if (layer_state_is(_RAISE)) {
            tap_code(clockwise ? KC_UP : KC_DOWN);
        } else if (layer_state_is(_LOWER)) {
            tap_code(clockwise ? UG_SPDU : UG_SPDD);
        } else if (layer_state_is(_GAMING)) {
            tap_code(clockwise ? MS_UP : MS_DOWN);
        } else {
            tap_code(clockwise ? MS_WHLD : MS_WHLU);
        }
    }
    return true;
}
