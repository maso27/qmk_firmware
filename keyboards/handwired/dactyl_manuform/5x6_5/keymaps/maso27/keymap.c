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

#include QMK_KEYBOARD_H


enum layer_names {
  _DEFAULTS = 0,
  _QWERTY = 0,
  _GAMING = 1,
  _LOWER = 2,
  _RAISE = 3
};

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE,  // can always be here (4 bytes)
    KC_PRVWD = LCTL(KC_LEFT),
    KC_NXTWD = LCTL(KC_RIGHT),
    KC_DLINE = LCTL(KC_BSPC),
    KC_CTLALTDEL = LCTL(LALT(KC_DEL)),
    KC_SH_DEL = LSFT(KC_DEL),
    KC_KILL = LALT(KC_F4)
};

/*
#define XXX KC_NO

#define LAYOUT_5x6_5( \
    L00, L01, L02, L03, L04, L05,                          R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,                          R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,                          R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35,                          R30, R31, R32, R33, R34, R35, \
              L42, L43,      L44, L55, L53,      R52, R50, R41,      R42, R43, \
                                  L54, L52,      R53, R51 \
) { \
    { L00, L01, L02, L03, L04, L05 }, \
    { L10, L11, L12, L13, L14, L15 }, \
    { L20, L21, L22, L23, L24, L25 }, \
    { L30, L31, L32, L33, L34, L35 }, \
    { XXX, XXX, L42, L43, L44, XXX }, \
    { XXX, XXX, L52, L53, L54, L55 }, \
\
    { R00, R01, R02, R03, R04, R05 }, \
    { R10, R11, R12, R13, R14, R15 }, \
    { R20, R21, R22, R23, R24, R25 }, \
    { R30, R31, R32, R33, R34, R35 }, \
    { XXX, R41, R42, R43, XXX, XXX }, \
    { R50, R51, R52, R53, XXX, XXX } \
}
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_5x6_5(
  /* QWERTY
   * .-----------------------------------------.                                  .-----------------------------------------.
   * | Esc  |   1  |   2  |   3  |   4  |   5  |                                  |   6  |   7  |   8  |   9  |   0  |  -   |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |                                  |   Y  |   U  |   I  |   O  |   P  | Bspc |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |LShift|   A  |   S  |   D  |   F  |   G  |                                  |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | LCtrl|   Z  |   X  |   C  |   V  |   B  |                                  |   N  |   M  |   ,  |   .  |   /  | Enter|
   * '-----------------------------------------/                                  \-----------------------------------------'
   *               | LGUI | LAlt |    / Mute  /---------------.    .---------------\ GAMING\    |   =  |   \  |
   *               |      |      |   /       / LOWER / Bspc  /      \ Space \ RAISE \       \   |      |      |
   *               '-------------'  '-------/       /       /        \       \       \-------'  '-------------'
   *                                       /---------------/          \---------------\
   *                                      / Rctrl / Home  /            \  End  \   `   \
   *                                     /       /       /              \       \       \
   *                                    '---------------'                '---------------'
   */
   KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
   KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
   KC_DEL , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                                     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
   KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                                     KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,  KC_ENT,
                     KC_LGUI, KC_LALT,       KC_MUTE,MO(_LOWER),KC_BSPC,    KC_SPC ,MO(_RAISE),TG(_GAMING),    KC_EQL, KC_BSLS,
                                                      KC_RCTRL, KC_HOME ,   KC_END , KC_GRV
   ),
  [_GAMING] = LAYOUT_5x6_5(
  /* GAMING
   * .-----------------------------------------.                                  .-----------------------------------------.
   * |      |      |      |      |      |      |                                  |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |      |      |      |      |      |                                  |      |      |  Up  |      |      |      |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |      |      |      |      |      |                                  |      | Left | Down | Right|      |      |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |      |      |      |      |      |                                  |      |      |      |      |      |      |
   * '-----------------------------------------/                                  \-----------------------------------------'
   *               |      |      |    /       /---------------.    .---------------\       \    |      |      |
   *               |      |      |   /       /       / Space /      \       \       \       \   |      |      |
   *               '-------------'  '-------/       /       /        \       \       \-------'  '-------------'
   *                                       /---------------/          \---------------\
   *                                      /       /       /            \       \       \
   *                                     /       /       /              \       \       \
   *                                    '---------------'                '---------------'
   */
   _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______,                                     _______, _______,   KC_UP, _______, _______, _______,
   _______, _______, _______, _______, _______, _______,                                     _______, KC_LEFT, KC_DOWN,KC_RIGHT, _______, _______,
   _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
                     _______, _______,          _______, _______,  KC_SPC,   _______, _______, _______,          _______, _______,
                                                         _______, _______,   _______, _______
   ),
  [_LOWER] = LAYOUT_5x6_5(
  /* LOWER
   * .-----------------------------------------.                                  .-----------------------------------------.
   * | AltF4|  F1  |  F2  |  F3  |  F4  |  F5  |                                  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |   1  |   2  |   3  |   4  |   5  |                                  |   6  |   7  |   8  |   9  |   0  |  F12 |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |   !  |   @  |   #  |   $  |   %  |                                  |   ^  |   &  |   *  |   (  |   )  |   |  |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |   =  |   -  |   +  |   {  |   }  |                                  |   [  |   ]  |   ;  |   :  |   \  |      |
   * '-----------------------------------------/                                  \-----------------------------------------'
   *               |CtlAlt|      |    /       /---------------.    .---------------\       \    |      |      |
   *               |  Del |      |   / RGBNxt/       /Shift- /      \       \       \RGBOff \   |      |      |
   *               '-------------'  '-------/       /  Del  /        \       \       \-------'  '-------------'
   *                                       /---------------/          \---------------\
   *                                      /       /       /            \       \       \
   *                                     /       /       /              \       \       \
   *                                    '---------------'                '---------------'
   */
   KC_KILL, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                                     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
   _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
   _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
   _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR,                                     KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                KC_CTLALTDEL, _______,          RGB_MOD, _______, KC_SH_DEL, _______, _______, RGB_TOG,          _______, _______,
                                                         _______, _______,   _______, _______
   ),
  [_RAISE] = LAYOUT_5x6_5(
  /* RAISE
   * .-----------------------------------------.                                  .-----------------------------------------.
   * |      |  XX  |  XX  |  XX  |  XX  |  XX  |                                  |  XX  |  XX  |  XX  |  XX  |  XX  | BkSpc|
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      | Ins  | Pscr | Menu |  XX  |  XX  |                                  | PgUp | PWrd |  Up  | NWrd | Dline|  Del |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |  XX  |  XX  |  XX  |  XX  | Caps |                                  | PgDn | Left | Down | Right|  XX  |  XX  |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |  XX  |  XX  |  XX  |  XX  |  XX  |                                  |  XX  | Home |  XX  | End  |  XX  |      |
   * '-----------------------------------------/                                  \-----------------------------------------'
   *               |      |      |    /       /---------------.    .---------------\       \    |      |      |
   *               |      |      |   /       /       /  Del  /      \       \       \       \   |      |      |
   *               '-------------'  '-------/       /       /        \       \       \-------'  '-------------'
   *                                       /---------------/          \---------------\
   *                                      /       /       /            \       \       \
   *                                     /       /       /              \       \       \
   *                                    '---------------'                '---------------'
   */
   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
   _______,  KC_INS, KC_PSCR,  KC_APP, XXXXXXX, XXXXXXX,                                     KC_PGUP, KC_PRVWD,  KC_UP, KC_NXTWD,KC_DLINE, KC_DEL,
   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, KC_HOME, XXXXXXX, KC_END,  XXXXXXX, _______,
                     _______, _______,          _______, _______,  KC_DEL,   _______, _______, _______,          XXXXXXX, XXXXXXX,
                                                         _______, _______,   _______, _______
   )
};

// Custom keycode handling.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // handling this once instead of in each keycode uses less program memory.
     if ((keycode >= SAFE_RANGE) && !(record->event.pressed)) {
         return false;
     }

    switch (keycode) {
/*         case CYCLE:
            set_single_persistent_default_layer((1+get_highest_layer(default_layer_state)) % BASE_LAYERS);
            break; */
    }

    // this uses less memory than returning in each case.
    return keycode < SAFE_RANGE;
};

#ifdef RGBLIGHT_ENABLE
// This is just copy-pasted.  Not complete.
#define INDICATOR_BRIGHTNESS 30
#define KEY_BRIGHTNESS 40

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

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

  /* RGB LAYER STUFF
   * .-----------------------------------------.                                  .-----------------------------------------.
   * |      |      |      |      |      |      |                                  |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |      |      |      |      |      |                                  |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |      |      |      |      |      |                                  |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |      |      |      |      |      |                                  |      |      |      |      |      |      |
   * '-----------------------------------------/                                  \-----------------------------------------'
   *               |      |      |    /       /---------------.    .---------------\       \    |      |      |
   *               |      |      |   /       /       /       /      \       \       \       \   |      |      |
   *               '-------------'  '-------/       /       /        \       \       \-------'  '-------------'
   *                                       /---------------/          \---------------\
   *                                      /       /       /            \       \       \
   *                                     /       /       /              \       \       \
   *                                    '---------------'                '---------------'
   */    
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
  {7,1,HSV_PURPLE} // ctl-alt-del on windows key
);
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_GREEN),
  SET_ARROWS(HSV_RED),
  {13,1,HSV_GREEN},
  {20,1,HSV_GREEN},
  {23,1,HSV_GREEN},
  {34,1,HSV_RED},   // capslock
  {46,2,HSV_GREEN}, // bkspc-del
  {49,1,HSV_RED},   // delete word
  {54,1,HSV_GREEN}, // end
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

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            if(layer_state_is(_RAISE)) {
                tap_code(KC_VOLU);
    #ifdef RGBLIGHT_ENABLE
            } else if(layer_state_is(_LOWER)) {
                rgblight_increase_val_noeeprom();
    #endif
            } else {
                tap_code(KC_RIGHT);
            }
        } else {
            if(layer_state_is(_RAISE)) {
                tap_code(KC_VOLD);
    #ifdef RGBLIGHT_ENABLE
            } else if(layer_state_is(_LOWER)) {
                rgblight_decrease_val_noeeprom();
    #endif
            } else {
                tap_code(KC_LEFT);
            }
        }
    } else if (index == 1) {
        if (clockwise) {
    #ifdef RGBLIGHT_ENABLE
            if(layer_state_is(_LOWER)) {
                rgblight_increase_speed_noeeprom();
            } else {
    #endif
                tap_code(KC_UP); // (KC_DOWN);
    #ifdef RGBLIGHT_ENABLE
            }
    #endif
        } else {
    #ifdef RGBLIGHT_ENABLE
            if(layer_state_is(_LOWER)) {
                rgblight_decrease_speed_noeeprom();
            } else {
    #endif
                tap_code(KC_DOWN); // (KC_UP);
    #ifdef RGBLIGHT_ENABLE
            }
    #endif
        }
    }
    return true;
}
#endif
