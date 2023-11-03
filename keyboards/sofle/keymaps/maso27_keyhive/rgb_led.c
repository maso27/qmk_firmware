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
#define SET_UNDERGLOW(hsv) \
    {1,  1, hsv}, {4,  1, hsv}, {10, 1, hsv}, {13, 1, hsv}, {16, 1, hsv}, {25, 1, hsv}, {28, 1, hsv}, {36, 1, hsv}, \
    {37, 1, hsv}, {45, 1, hsv}, {48, 1, hsv}, {57, 1, hsv}, {60, 1, hsv}, {63, 1, hsv}, {69, 1, hsv}, {72, 1, hsv}
#define SET_LOWER(hsv) \
    {34, 1, hsv}
#define SET_RAISE(hsv) \
    {39, 1, hsv}
#define SET_ARROWS(hsv) \
    {47, 1, HSV_OVERRIDE_HELP(hsv, OVERRIDE_BRIGHTNESS)}, \
    {53, 2, HSV_OVERRIDE_HELP(hsv, OVERRIDE_BRIGHTNESS)}, \
    {59, 1, HSV_OVERRIDE_HELP(hsv, OVERRIDE_BRIGHTNESS)}
#define SET_WASD(hsv) \
    {8,  1, HSV_OVERRIDE_HELP(hsv, OVERRIDE_BRIGHTNESS)}, \
    {14, 2, HSV_OVERRIDE_HELP(hsv, OVERRIDE_BRIGHTNESS)}, \
    {20, 1, HSV_OVERRIDE_HELP(hsv, OVERRIDE_BRIGHTNESS)}
#define SET_FN_KEYS(hsv) \
    {6,  1, hsv}, {17, 2, hsv}, {29, 2, hsv}, \
    {43, 2, hsv}, {55, 2, hsv}, {67, 2, hsv}, {70, 1, hsv}
#define SET_BRACKETS(hsv) \
    {24, 1, hsv}, {33, 1, hsv}, \
    {40, 1, hsv}, {49, 1, hsv}

/*  RGB LAYER STUFF  */
/*
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |  5   |  6   |  17  |  18  |  29  |  30  |                    |  43  |  44  |  55  |  56  |  67  |  68  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |  3   |  7   |  15  |  19  |  27  |  31  |                    |  42  |  46  |  54  |  58  |  66  |  70  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |  2   |  8   |  14  |  20  |  26  |  32  |-------.    ,-------|  41  |  47  |  53  |  59  |  65  |  71  |
    * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
    * |  0   |  9   |  12  |  21  |  24  |  33  |-------|    |-------|  40  |  49  |  52  |  61  |  64  |  73  |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *            |  11  |  22  |  23  |  34  | /  35   /       \  38  \  |  39  |  50  |  51  |  62  |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `---------------------------'-------'           '------''---------------------------'
    *       UNDERGLOW = 1,4,10,13,16,25,28,36                             UNDERGLOW = 37,45,48,57,60,63,69,72
    */
// Light underglow blue when in standard mode
const rgblight_segment_t PROGMEM my_base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_UNDERGLOW(HSV_BLUE),
    SET_LOWER(HSV_PURPLE),
    SET_RAISE(HSV_GREEN)
);

// Light underglow and gaming-specific keys in white when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_UNDERGLOW(HSV_WHITE),
    SET_WASD(HSV_WHITE),
    SET_ARROWS(HSV_WHITE)
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_UNDERGLOW(HSV_PURPLE),
    SET_FN_KEYS(HSV_PURPLE),
    SET_BRACKETS(HSV_PURPLE),
    // {0,  1, HSV_GREEN},  // Rctrl on Control key
    {3,  1, HSV_GREEN},  // Greaves `/~
    {5,  1, HSV_RED},    // Alt-F4 Kill
    {11, 1, HSV_PURPLE}, // Ctrl-Alt-Del on windows key
    {23, 1, HSV_RED},    // macro_stop
    {50, 1, HSV_PURPLE}  // _ on - key
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_UNDERGLOW(HSV_GREEN),
    SET_ARROWS(HSV_WHITE),
    {0,  1, HSV_GREEN},  // Rctrl on Control key
    {7,  1, HSV_GREEN},  // insert
    {15, 1, HSV_GREEN},  // printscreen
    {19, 1, HSV_GREEN},  // menu
    {23, 1, HSV_BLUE},   // macro_record
    {32, 1, HSV_RED},    // caps lock
    {41, 2, HSV_GREEN},  // pgup / pgdown
    {46, 1, HSV_GREEN},  // prev word
    {49, 1, HSV_GREEN},  // home
    {58, 1, HSV_GREEN},  // next word
    {61, 1, HSV_GREEN},  // end
    {66, 1, HSV_RED},    // delete word
    {68, 1, HSV_RED},    // backspace
    {70, 1, HSV_RED},    // delete
    {73, 1, HSV_GREEN}   // enter (no shift)

);
// Light underglow red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_UNDERGLOW(HSV_RED)
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
    rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL);
    rgblight_set_speed_noeeprom(30); // 0 to 255
}

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
