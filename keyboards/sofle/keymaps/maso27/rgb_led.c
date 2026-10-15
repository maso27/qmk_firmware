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

//Configuring RGB LED layout

#define INDICATOR_BRIGHTNESS 30
#define KEY_BRIGHTNESS 40

#define OVERRIDE_BRIGHTNESS 100
#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s, Override
#define SOFLE_RGBLIGHT_HALF_COUNT (RGBLIGHT_LED_COUNT / 2)
#define SOFLE_RGBLIGHT_RIGHT_LED(index) ((index) + SOFLE_RGBLIGHT_HALF_COUNT - 36)

// Light combinations
#define SET_ALLKEYS(hsv) \
    {0, SOFLE_RGBLIGHT_HALF_COUNT, hsv}, \
    {SOFLE_RGBLIGHT_HALF_COUNT, SOFLE_RGBLIGHT_HALF_COUNT, hsv}
#define SET_INDICATORS(hsv) \
    {0,     1,  HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {SOFLE_RGBLIGHT_HALF_COUNT, 1, hsv}
#define SET_UNDERGLOW(hsv) \
    {1,     6,  hsv}, \
    {SOFLE_RGBLIGHT_HALF_COUNT + 1, 6, hsv}
#define SET_NUMPAD(hsv)     \
    {SOFLE_RGBLIGHT_HALF_COUNT + 13, 3, hsv}, \
    {SOFLE_RGBLIGHT_HALF_COUNT + 18, 3, hsv}, \
    {SOFLE_RGBLIGHT_HALF_COUNT + 23, 3, hsv}
#define SET_NUMROW(hsv) \
    {11,    2,  hsv}, \
    {21,    2,  hsv}, \
    {31,    2,  hsv}, \
    {SOFLE_RGBLIGHT_HALF_COUNT + 11, 2, hsv}, \
    {SOFLE_RGBLIGHT_HALF_COUNT + 21, 2, hsv}, \
    {SOFLE_RGBLIGHT_HALF_COUNT + 31, 2, hsv}
#define SET_FNROW(hsv) \
    {11,    2,  hsv}, \
    {21,    2,  hsv}, \
    {31,    2,  hsv}, \
    {SOFLE_RGBLIGHT_RIGHT_LED(46), 3, hsv}, \
    {SOFLE_RGBLIGHT_RIGHT_LED(57), 2, hsv}, \
    {SOFLE_RGBLIGHT_RIGHT_LED(67), 2, hsv}
#define SET_ARROWS(hsv) \
    {SOFLE_RGBLIGHT_RIGHT_LED(55), 1, hsv}, \
    {SOFLE_RGBLIGHT_RIGHT_LED(59), 2, hsv}, \
    {SOFLE_RGBLIGHT_RIGHT_LED(65), 1, hsv}
#define SET_WASD(hsv) \
    {14,    1,  hsv}, \
    {19,    2,  hsv}, \
    {24,    1,  hsv}
#define SET_INNER_COL(hsv)	\
    {32,    4,  hsv}, \
    {SOFLE_RGBLIGHT_HALF_COUNT + 32, 4, hsv}
#define SET_OUTER_COL(hsv) \
    {8,     4,  hsv}, \
    {SOFLE_RGBLIGHT_HALF_COUNT + 8, 4, hsv}
#define SET_THUMB_CLUSTER(hsv) 	\
    {26,    2,  hsv}, \
    {SOFLE_RGBLIGHT_HALF_COUNT + 26, 2, hsv}
#define SET_LAYER_ID(hsv) 	\
    {0,     1,  HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {SOFLE_RGBLIGHT_HALF_COUNT, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {1,     6,  hsv}, \
    {SOFLE_RGBLIGHT_HALF_COUNT + 1, 6, hsv}
#define SET_BRACES(hsv)         \
    {28,    1,  hsv}, \
    {SOFLE_RGBLIGHT_RIGHT_LED(35), 1, hsv}
#define SET_BRACKETS(hsv)       \
    {SOFLE_RGBLIGHT_RIGHT_LED(64), 1, hsv}, \
    {SOFLE_RGBLIGHT_RIGHT_LED(71), 1, hsv}

char layer_state_str[RGBLIGHT_LED_COUNT];

/*  RGB LAYOUT
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
     *       INDICATOR = 0                                      INDICATOR = SOFLE_RGBLIGHT_HALF_COUNT
     *       UNDERGLOW = 1-6                                    UNDERGLOW = SOFLE_RGBLIGHT_HALF_COUNT+1..6
     */

const rgblight_segment_t PROGMEM my_base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_BLUE),
  {26,1,HSV_PURPLE},
  {SOFLE_RGBLIGHT_RIGHT_LED(62),1,HSV_GREEN}
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
  {7, 1,HSV_PURPLE}, // ctl-alt-del on windows key
//  {8, 1,HSV_GREEN},  // R-ctrl on ctrl key
  {10,1,HSV_GREEN},  // real greaves key
  {11,1,HSV_RED},    // alt-F4 on Esc key
  {17,1,HSV_RED},   // macro_stop
  {SOFLE_RGBLIGHT_RIGHT_LED(53),1,HSV_PURPLE}  // _ on - key
);
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_GREEN),
  SET_ARROWS(HSV_WHITE),
  SET_BRACES(HSV_GREEN), // really parentheses
  {8, 1,HSV_GREEN}, // R-ctrl on ctrl key
  {13,1,HSV_GREEN},
  {17,1,HSV_BLUE},   // macro_rec
  {20,1,HSV_GREEN},
  {23,1,HSV_GREEN},
  {34,1,HSV_RED},   // capslock
  {SOFLE_RGBLIGHT_RIGHT_LED(44),1,HSV_GREEN}, // enter (no shift)
  {SOFLE_RGBLIGHT_RIGHT_LED(46),1,HSV_RED}, // delete
  {SOFLE_RGBLIGHT_RIGHT_LED(49),2,HSV_RED}, // delete word and backspace
  {SOFLE_RGBLIGHT_RIGHT_LED(53),2,HSV_GREEN}, // ~ and end
//  {SOFLE_RGBLIGHT_RIGHT_LED(54),1,HSV_GREEN}, // end
  {SOFLE_RGBLIGHT_RIGHT_LED(56),1,HSV_GREEN}, // next_word
  {SOFLE_RGBLIGHT_RIGHT_LED(69),2,HSV_GREEN}, // pgup-pgdn
  {SOFLE_RGBLIGHT_RIGHT_LED(66),1,HSV_GREEN}, // prev_word
  {SOFLE_RGBLIGHT_RIGHT_LED(64),1,HSV_GREEN}  // home
);
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_WHITE),
  {SOFLE_RGBLIGHT_RIGHT_LED(55),2,HSV_WHITE}, // r-click
  {SOFLE_RGBLIGHT_RIGHT_LED(60),2,HSV_WHITE}, // m-click
  {SOFLE_RGBLIGHT_RIGHT_LED(65),2,HSV_WHITE}, // l-click
  {SOFLE_RGBLIGHT_RIGHT_LED(69),2,HSV_WHITE}, // whl-up
  {SOFLE_RGBLIGHT_RIGHT_LED(70),2,HSV_WHITE} // whl-dn
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
    my_layer4_layer,    // Overrides other layers
    my_capslock_layer   // Overrides all other layers
);

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(5, led_state.caps_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_QWERTY));
    rgblight_set_layer_state(1, layer_state_cmp(state, _GAMING));
    rgblight_set_layer_state(2, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(3, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(4, layer_state_cmp(state, _POINTER));
    return state;
}

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
    // Set to rainbow mood
    rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD);
    rgblight_set_speed_noeeprom(30); // 0 to 255
}
