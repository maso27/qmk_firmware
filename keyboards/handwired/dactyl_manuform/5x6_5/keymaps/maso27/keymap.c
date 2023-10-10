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
    KC_LOWER = TT(_LOWER), // MO(_LOWER),
    KC_RAISE = TT(_RAISE), // MO(_RAISE),
    KC_ULOCK = TO(_DEFAULTS), // return to main layer
    KC_PRVWD = LCTL(KC_LEFT),
    KC_NXTWD = LCTL(KC_RIGHT),
    KC_DWORD = LCTL(KC_BSPC),
    KC_CTLALTDEL = LCTL(LALT(KC_DEL)),
    KC_KILL = LALT(KC_F4),
    KC_SH_DEL = LSFT(KC_DEL)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_5x6_5(
  /* QWERTY
   * .-----------------------------------------.                                  .-----------------------------------------.
   * |Esc/~ |   1  |   2  |   3  |   4  |   5  |                                  |   6  |   7  |   8  |   9  |   0  |  -   |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |                                  |   Y  |   U  |   I  |   O  |   P  | Bspc |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |LShift|   A  |   S  |   D  |   F  |   G  |                                  |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | LCtrl|   Z  |   X  |   C  |   V  |   B  |                                  |   N  |   M  |   ,  |   .  |   /  |Ent/Shft|
   * '-----------------------------------------/                                  \-----------------------------------------'
   *               | LGUI | LAlt |    / Mute  /---------------.    .---------------\ GAMING\    |   =  |   \  |
   *               |      |      |   /       / LOWER / Bspc  /      \ Space \ RAISE \       \   |      |      |
   *               '-------------'  '-------/       /       /        \       \       \-------'  '-------------'
   *                                       /---------------/          \---------------\
   *                                      / MACRO /  {/[  /            \  ]\}  \   -   \
   *                                     /   Play/       /              \       \       \
   *                                    '---------------'                '---------------'
   */
   QK_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
   KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
   KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                                     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
   KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                                     KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,  SC_SENT,
                     KC_LGUI, KC_LALT,       KC_MUTE, KC_LOWER, KC_BSPC,   KC_SPC, KC_RAISE,TG(_GAMING),    KC_EQL, KC_BSLS,
                                                      DM_PLY1, KC_LBRC,     KC_RBRC, KC_MINS
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
   *               |      |      |    / Left- /---------------.    .---------------\       \    |      |      |
   *               |      |      |   /  Click/       / Space /      \       \       \       \   |      |      |
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
                     _______, _______,       KC_MS_BTN1, _______,  KC_SPC, _______, _______, _______,          _______, _______,
                                                         _______, _______, _______, _______
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
   * |      |  XX  |  XX  |  XX  |   {  |   }  |                                  |   [  |   ]  |      |      |   \  |      |
   * '-----------------------------------------/                                  \-----------------------------------------'
   *               |CtlAlt|      |    /       /---------------.    .---------------\       \    |      |      |
   *               |  Del |      |   / RGBNxt/Layers /Shift- /      \       \ Layers\RGBOff \   |      |      |
   *               '-------------'  '-------/   OFF /  Del  /        \       \  OFF  \-------'  '-------------'
   *                                       /---------------/          \---------------\
   *                                      / MACRO /       /            \       \   _   \
   *                                     /  Stop /       /              \       \       \
   *                                    '---------------'                '---------------'
   */
   KC_KILL, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                                       KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
   _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
   _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
   _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR,                                       KC_LBRC, KC_RBRC, _______, _______, KC_BSLS, _______,
                KC_CTLALTDEL, _______,        RGB_MOD, KC_ULOCK, KC_SH_DEL, _______,KC_ULOCK, RGB_TOG,           _______, _______,
                                                        DM_RSTP, _______,     _______,   KC_UNDS
   ),
  [_RAISE] = LAYOUT_5x6_5(
  /* RAISE
   * .-----------------------------------------.                                  .-----------------------------------------.
   * |      |  XX  |  XX  |  XX  |  XX  |  XX  |                                  |  XX  |  XX  |  XX  |  XX  |  XX  |  XX  |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      | Ins  | Pscr | Menu |  XX  |  XX  |                                  | PgUp | PWrd |  Up  | NWrd | Dline|  Del |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |  XX  |  XX  |  XX  |  XX  | Caps |                                  | PgDn | Left | Down | Right| BkSpc|  XX  |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | RCTR |  XX  |  XX  |  XX  |  (   |  )   |                                  |  XX  | Home |  XX  | End  |  XX  | Enter|
   * '-----------------------------------------/                                  \-----------------------------------------'
   *               |      |      |    /       /---------------.    .---------------\       \    |      |      |
   *               |      |      |   /       /Layers /  Del  /      \       \ Layers\       \   |      |      |
   *               '-------------'  '-------/   OFF /       /        \       \  OFF  \-------'  '-------------'
   *                                       /---------------/          \---------------\
   *                                      / MACRO /       /            \       \   ~   \
   *                                     /   Rec /       /              \       \       \
   *                                    '---------------'                '---------------'
   */
   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   _______,  KC_INS, KC_PSCR,  KC_APP, XXXXXXX, XXXXXXX,                                     KC_PGUP, KC_PRVWD,  KC_UP, KC_NXTWD,KC_DWORD, KC_DEL,
   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, XXXXXXX,
   KC_RCTL, XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN,                                     XXXXXXX, KC_HOME, XXXXXXX, KC_END,  XXXXXXX, KC_ENT,
                     _______, _______,          _______, KC_ULOCK, KC_DEL, _______, KC_ULOCK, _______,          XXXXXXX, XXXXXXX,
                                                        DM_REC1, _______,   _______, KC_TILD
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

#ifdef RGBLIGHT_ENABLE
    // This is copy-pasted. May need more attention
    #define INDICATOR_BRIGHTNESS 30
    #define KEY_BRIGHTNESS 40

    #define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
    #define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

    // Light combinations
    #define SET_ALLKEYS(hsv) \
        {0, 18, hsv}, \
        {18+0, 18, hsv}
    #define SET_NUMROW(hsv) \
        {0, 1, hsv}, \
        {13, 2, hsv}, \
        {18+ 0, 1, hsv}, \
        {18+ 13, 2, hsv}
    #define SET_ARROWS(hsv) \
        {20,1,hsv}, \
        {29,2,hsv}
    #define SET_WASD(hsv) \
        {11, 2, hsv}, \
        {16, 1, hsv}
    #define SET_BKSPC(hsv) \
        {32, 2, hsv}
    #define SET_THUMB_CLUSTER(hsv) 	\
        {5, 3, hsv}, \
        {18+5, 3, hsv}
    
/*    
        {5, 3, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
        {18+5, 3, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}
*/
      /* RGB LAYER STUFF
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
       
    #define SET_UNDERGLOW(hsv) \
        {0, 8, hsv}, \
        {8+0, 8,hsv}
    char layer_state_str[36];
    // Now define the array of layers. Later layers take precedence

    const rgblight_segment_t PROGMEM my_base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
      // SET_ALLKEYS(HSV_BLUE)
      SET_THUMB_CLUSTER(HSV_BLUE)
    );
    const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
      // SET_ALLKEYS(HSV_WHITE)
      SET_THUMB_CLUSTER(HSV_WHITE)
    );
    const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
      // SET_ALLKEYS(HSV_PURPLE)
      SET_THUMB_CLUSTER(HSV_PURPLE)
    );
    const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
      // SET_ALLKEYS(HSV_GREEN)
      // SET_ARROWS(HSV_WHITE),
      // SET_BKSPC(HSV_RED),
      SET_THUMB_CLUSTER(HSV_GREEN)
    );
    const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
      SET_ALLKEYS(HSV_RED)
//      SET_THUMB_CLUSTER(HSV_RED)
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
        rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING); // (RGBLIGHT_MODE_RAINBOW_MOOD);
	rgblight_sethsv_noeeprom(HSV_CYAN);
        rgblight_set_speed_noeeprom(10); // 0 to 255
    }
#endif // RGBLIGHT_ENABLE

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            if (layer_state_is(_RAISE)) {
                tap_code(KC_RIGHT);
	    } else if (layer_state_is(_GAMING)) {
                tap_code(KC_MS_RIGHT);
    #ifdef RGBLIGHT_ENABLE
            } else if (layer_state_is(_LOWER)) {
                rgblight_increase_val_noeeprom();
    #endif
            } else {
                tap_code(KC_VOLU);
            }
        } else {
            if (layer_state_is(_RAISE)) {
                tap_code(KC_LEFT);
	    } else if (layer_state_is(_GAMING)) {
		tap_code(KC_MS_LEFT);
    #ifdef RGBLIGHT_ENABLE
            } else if (layer_state_is(_LOWER)) {
                rgblight_decrease_val_noeeprom();
    #endif
            } else {
                tap_code(KC_VOLD);
            }
        }
    } else if (index == 1) {
        if (clockwise) {
            if (layer_state_is(_RAISE)) {
                tap_code(KC_DOWN);
            } else if (layer_state_is(_GAMING)) {
		tap_code(KC_MS_DOWN);
    #ifdef RGBLIGHT_ENABLE
	    } else if (layer_state_is(_LOWER)) {
                rgblight_decrease_speed_noeeprom();
    #endif
            } else {
                tap_code(KC_WH_D);
            }
        } else {
            if (layer_state_is(_RAISE)) {
                tap_code(KC_UP);
            } else if (layer_state_is(_GAMING)) {
		tap_code(KC_MS_UP);
    #ifdef RGBLIGHT_ENABLE
            } else if (layer_state_is(_LOWER)) {
                rgblight_increase_speed_noeeprom();
    #endif
            } else {
                tap_code(KC_WH_U);
            }
        }
    }
    return true;
}
#endif // ENCODER_ENABLE
