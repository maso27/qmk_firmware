
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
  // SOFLE RGB
#include <stdio.h>

#include QMK_KEYBOARD_H
#include "features/layer_lock.h"

#define INDICATOR_BRIGHTNESS 30
#define KEY_BRIGHTNESS 40

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

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
    KC_LOWER = MO(_LOWER), // LT(_LOWER,KC_LPRN), // lower layer when held, parentheses when tapped
    KC_RAISE = MO(_RAISE), // LT(_RAISE,KC_RPRN),
    KC_PRVWD = LCTL(KC_LEFT),
    KC_NXTWD = LCTL(KC_RIGHT),
    KC_DWORD = LCTL(KC_BSPC),
    KC_CTLALTDEL = LCA(KC_DEL),
    KC_KILL = LALT(KC_F4),
    KC_SH_DEL = LSFT(KC_DEL),
    LLOCK = SAFE_RANGE  // layer lock key
};

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
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|RGBNext|    |RGBOff |------+------+------+------+------+------|
 * |      |  XX  |  XX  |  XX  |   {  |   }  |-------|    |-------|   [  |   ]  |      |      |   \  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |CtlAlt|      |      |      | /Shift- /       \      \  | Layer|  _   |      |      |
 *            |  Del |      |      |      |/  Del  /         \      \ | Lock |      |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  KC_KILL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR,  RGB_MOD,      RGB_TOG, KC_LBRC, KC_RBRC, _______, _______, KC_BSLS, _______,
               KC_CTLALTDEL, _______, _______, _______, KC_SH_DEL,     _______,   LLOCK, KC_UNDS, _______, _______
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
 *            |      |      |MACRO | Layer| /  Del  /       \      \  |      |  ~   |      |      |
 *            |      |      |  Rec | Lock |/       /         \      \ |      |      |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______,  KC_INS, KC_PSCR,  KC_APP, XXXXXXX, XXXXXXX,                        KC_PGUP, KC_PRVWD,  KC_UP, KC_NXTWD,KC_DWORD, KC_DEL,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS,                        KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, XXXXXXX,
  KC_RCTL, XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN,  _______,    _______,  XXXXXXX, KC_HOME, XXXXXXX, KC_END,XXXXXXX, KC_ENT,
                      _______, _______, DM_REC1,  LLOCK,  KC_DEL,      _______, _______, KC_TILD, _______, _______
)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // handling this once instead of in each keycode uses less program memory.
    if ((keycode >= SAFE_RANGE) && !(record->event.pressed)) {
        return false;
    }
    
    // layer lock code
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }

    // this uses less memory than returning in each case.
    return keycode < SAFE_RANGE;
}

#ifdef RGBLIGHT_ENABLE
    /*  RGB LAYER STUFF  */
    /*
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  11  |  12  |  21  |  22  |  31  |  32  |                    |  68  |  67  |  58  |  57  |  48  |  47  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  10  |  13  |  20  |  23  |  30  |  33  |                    |  69  |  66  |  59  |  56  |  49  |  46  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |   9  |  14  |  19  |  24  |  29  |  34  |-------.    ,-------|  70  |  65  |  60  |  55  |  50  |  45  |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |   8  |  15  |  18  |  25  |  28  |  35  |-------|    |-------|  71  |  64  |  61  |  54  |  51  |  44  |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            |   7  |  16  |  17  |  26  | /  27   /       \  63  \  |  62  |  53  |  52  |  43  |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `---------------------------'-------'           '------''---------------------------'
     *       INDICATOR = 0                                                  INDICATOR = 36
     *       UNDERGLOW = 1-6                                                UNDERGLOW = 37-42
     */

// Light combinations
#define SET_ALLKEYS(hsv) \
    {0, 36, hsv}, \
    {36+0, 36, hsv}
#define SET_INDICATORS(hsv) \
    {0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {36+0, 1, hsv}
#define SET_UNDERGLOW(hsv) \
    {1, 6, hsv}, \
    {36+1, 6,hsv}
#define SET_NUMPAD(hsv)     \
    {36+13, 3, hsv},\
    {36+18, 3, hsv},\
    {36+23, 3, hsv}
#define SET_NUMROW(hsv) \
    {11, 2, hsv}, \
    {21, 2, hsv}, \
    {31, 2, hsv}, \
    {36+ 11, 2, hsv}, \
    {36+ 21, 2, hsv}, \
    {36+ 31, 2, hsv}
#define SET_FNROW(hsv) \
    {11, 2, hsv}, \
    {21, 2, hsv}, \
    {31, 2, hsv}, \
    {46, 3, hsv}, \
    {57, 2, hsv}, \
    {67, 2, hsv}
#define SET_ARROWS(hsv) \
    {55,1,hsv}, \
    {59,2,hsv}, \
    {65,1,hsv}
#define SET_WASD(hsv) \
    {14, 1, hsv}, \
    {19, 2, hsv}, \
    {24, 1, hsv}
#define SET_INNER_COL(hsv)	\
    {32, 4, hsv}, \
    {36+ 32, 4, hsv}
#define SET_OUTER_COL(hsv) \
    {8, 4, hsv}, \
    {36+ 8, 4, hsv}
#define SET_THUMB_CLUSTER(hsv) 	\
    {26, 2, hsv}, \
    {36+ 26, 2, hsv}
#define SET_LAYER_ID(hsv) 	\
    {0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {36+0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {1, 6, hsv}, \
    {36+1, 6, hsv}
#define SET_BRACES(hsv)         \
    {28, 1, hsv}, \
    {35, 1, hsv}
#define SET_BRACKETS(hsv)       \
    {64, 1, hsv}, \
    {71, 1, hsv}

char layer_state_str[72];
// Now define the array of layers. Later layers take precedence

const rgblight_segment_t PROGMEM my_base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_BLUE),
  {26,1,HSV_PURPLE},
  {62,1,HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_WHITE),
  SET_ARROWS(HSV_WHITE),
  SET_WASD(HSV_WHITE),
  {27,1,HSV_WHITE} // space key
);
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_PURPLE),
  SET_FNROW(HSV_PURPLE),
  SET_BRACKETS(HSV_PURPLE),
  SET_BRACES(HSV_PURPLE),
  {7,1,HSV_PURPLE}, // ctl-alt-del on windows key
//  {8,1,HSV_GREEN},  // R-ctrl on ctrl key
  {11,1,HSV_RED},    // alt-F4 on Esc key
  {53,1,HSV_PURPLE}  // _ on - key
);
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_GREEN),
  SET_ARROWS(HSV_WHITE),
  SET_BRACES(HSV_GREEN), // really parentheses
  {8,1,HSV_GREEN}, // R-ctrl on ctrl key
  {13,1,HSV_GREEN},
  {17,1,HSV_RED},   // macro_rec
  {20,1,HSV_GREEN},
  {23,1,HSV_GREEN},
  {34,1,HSV_RED},   // capslock
  {44,1,HSV_GREEN}, // enter (no shift)
  {46,1,HSV_RED}, // delete
  {49,2,HSV_RED},   // delete word and backspace
  {53,2,HSV_GREEN}, // ~ and end
//  {54,1,HSV_GREEN}, // end
  {56,1,HSV_GREEN}, // next_word
  {69,2,HSV_GREEN}, // pgup-pgdn
  {66,1,HSV_GREEN}, // prev_word
  {64,1,HSV_GREEN}  // home
);
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_RED)
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_base_layer,
    my_layer1_layer,    // Overrides base layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer,    // Overrides other layers
    my_capslock_layer   // Overrides all other layers
);

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(4, led_state.caps_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(0, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_QWERTY));
    rgblight_set_layer_state(1, layer_state_cmp(state, _GAMING));
    rgblight_set_layer_state(2, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(3, layer_state_cmp(state, _RAISE));
    return state;
}

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
    // Set to rainbow mood
	rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD);
    rgblight_set_speed_noeeprom(30); // 0 to 255
}
#endif

#ifdef OLED_ENABLE

/* 32 * 53 logo */
static void render_logo(void) {
    static const char PROGMEM maso_logo[] = {
    0xe0, 0xf8, 0x7c, 0x1e, 0x1f, 0x0f, 0x0f, 0x0f, 0x0f, 0x1e, 0x3e, 0xfc, 0xf8, 0x80, 0x80, 0x80, 
    0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x21, 0x7f, 0x3e, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0xbe, 0xff, 0xff, 0x87, 0x03, 0x01, 
    0x31, 0x38, 0x38, 0x38, 0x11, 0x01, 0x83, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x1c, 0xfc, 0xf8, 0xf8, 0xbc, 0x3c, 0x1e, 0xfe, 0xfe, 0xff, 0x0f, 0x0f, 0x7f, 0xff, 0xc7, 0x87, 
    0x8e, 0x0e, 0x80, 0xc0, 0xf0, 0xf1, 0xc1, 0x83, 0x07, 0xff, 0xfe, 0xc0, 0x00, 0x00, 0x00, 0x00, 
    0x03, 0x07, 0x03, 0x03, 0x03, 0x07, 0x0f, 0x0f, 0x1f, 0x1f, 0x3c, 0xfe, 0xff, 0xff, 0xff, 0xff, 
    0x9f, 0x0f, 0x07, 0x03, 0x01, 0x31, 0x00, 0x18, 0x3c, 0x3f, 0x7f, 0xff, 0xf0, 0x00, 0x00, 0x00, 
    0xee, 0xfe, 0x7c, 0x7c, 0xfc, 0xfe, 0xde, 0xce, 0x8e, 0x8f, 0x8f, 0x1f, 0x0f, 0x00, 0x03, 0xff, 
    0xff, 0xff, 0xc7, 0x87, 0x03, 0x02, 0x02, 0x22, 0xe0, 0xe0, 0x62, 0x7f, 0xff, 0xfe, 0x80, 0x00, 
    0xdc, 0xfc, 0xf8, 0xf8, 0xf8, 0xfc, 0x9d, 0x9f, 0x9f, 0x8f, 0x8f, 0xc7, 0xc7, 0x00, 0x00, 0x00, 
    0x1f, 0x3f, 0x38, 0x30, 0x38, 0x38, 0x38, 0x18, 0x18, 0x18, 0x1c, 0x1c, 0x0c, 0x0f, 0x0f, 0x00, 
    0x01, 0x03, 0x01, 0x00, 0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x07, 0x0f, 0x0f, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};

    oled_write_raw_P(maso_logo, sizeof(maso_logo));
}

/* 32 * 14 os logos */
static const char PROGMEM windows_logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbc, 0xbc, 0xbe, 0xbe, 0x00,
    0xbe, 0xbe, 0xbf, 0xbf, 0xbf, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x0f, 0x0f, 0x00,
    0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/* static const char PROGMEM mac_logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf8, 0xf8,
    0xf0, 0xf6, 0xfb, 0xfb, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x1f, 0x1f,
    0x0f, 0x0f, 0x1f, 0x1f, 0x0f, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
}; */

static void print_logo_narrow(void) {
    render_logo();
    
    #ifdef WPM_ENABLE
    /* wpm counter */
    uint8_t n = get_current_wpm();
    char wpm_str[4];
    oled_set_cursor(0,14);
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + n % 10;
    wpm_str[1] = '0' + ( n /= 10) % 10;
    wpm_str[0] = '0' + n / 10;
    oled_write(wpm_str, false);

    oled_set_cursor(0,15);
    oled_write(" wpm", false);
    #endif
}

static void print_status_narrow(void) {
    /* Print current mode */
    oled_set_cursor(0,0);
//    if (keymap_config.swap_lctl_lgui) {
//        oled_write_raw_P(mac_logo, sizeof(mac_logo));
//    } else {
        oled_write_raw_P(windows_logo, sizeof(windows_logo));
//    }

    oled_set_cursor(0,3);

//     switch (get_highest_layer(default_layer_state)) {
//         case _QWERTY:
            oled_write("QWRTY", false);
//             break;
//         case _GAMING:
//             oled_write("GAMES", false);
//             break;
//         default:
//             oled_write("UNDEF", false);
//     }

    oled_set_cursor(0,5);

    /* Print current layer */
    oled_write("LAYER", false);

    oled_set_cursor(0,6);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write("Base ", false);
            break;
        case _GAMING:
            oled_write("Games", false);
            break;
        case _RAISE:
            oled_write("Raise", false);
            break;
        case _LOWER:
            oled_write("Lower", false);
            break;
        default:
            oled_write("Undef", false);
    }

    /* caps lock */
    oled_set_cursor(0,8);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write("CAPS  LOCK", led_usb_state.caps_lock);
    oled_set_cursor(0,11);
    oled_write("CAPS  WORD", is_caps_word_on());
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        print_logo_narrow();
    }
    return false;
}

#endif

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            if (layer_state_is(_LOWER)) {
                rgblight_increase_val_noeeprom();
            } else if (layer_state_is(_RAISE)) {
                tap_code(KC_RIGHT);
	    } else if (layer_state_is(_GAMING)) {
		tap_code(KC_MS_RIGHT);
            } else {
                tap_code(KC_VOLU);
            }
        } else {
            if (layer_state_is(_LOWER)) {
                rgblight_decrease_val_noeeprom();
            } else if (layer_state_is(_RAISE)) {
                tap_code(KC_LEFT);
	    } else if (layer_state_is(_GAMING)) {
		tap_code(KC_MS_LEFT);
            } else {
                tap_code(KC_VOLD);
            }
        }
    } else if (index == 1) {
        if (clockwise) {
            if (layer_state_is(_LOWER)) {
                rgblight_increase_speed_noeeprom();
            } else if (layer_state_is(_RAISE)) {
                tap_code(KC_UP);
	    } else if (layer_state_is(_GAMING)) {
		tap_code(KC_MS_UP);
            } else {
                tap_code(KC_WH_U); // scroll wheel up
            }
        } else {
            if( layer_state_is(_LOWER)) {
                rgblight_decrease_speed_noeeprom();
            } else if (layer_state_is(_RAISE)) {
                tap_code(KC_DOWN);
	    } else if (layer_state_is(_GAMING)) {
		tap_code(KC_MS_DOWN);
            } else {
                tap_code(KC_WH_D); // scroll wheel down
            }
        }
    }
    return true;
}

#endif
