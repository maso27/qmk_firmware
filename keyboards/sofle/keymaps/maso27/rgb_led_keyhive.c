/* Copyright 2020 Josef Adamcik
 * SPDX-License-Identifier: GPL-2.0-or-later
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

#define OVERRIDE_BRIGHTNESS 100
#define HSV_OVERRIDE_HELP(h, s, v, override) h, s, override
#define SET_UNDERGLOW(hsv) \
    {1, 1, hsv}, {4, 1, hsv}, {10, 1, hsv}, {13, 1, hsv}, {16, 1, hsv}, {25, 1, hsv}, {28, 1, hsv}, {36, 1, hsv}, \
    {37, 1, hsv}, {45, 1, hsv}, {48, 1, hsv}, {57, 1, hsv}, {60, 1, hsv}, {63, 1, hsv}, {69, 1, hsv}, {72, 1, hsv}
#define SET_ARROWS(hsv) \
    {47, 1, HSV_OVERRIDE_HELP(hsv, OVERRIDE_BRIGHTNESS)}, \
    {53, 2, HSV_OVERRIDE_HELP(hsv, OVERRIDE_BRIGHTNESS)}, \
    {59, 1, HSV_OVERRIDE_HELP(hsv, OVERRIDE_BRIGHTNESS)}
#define SET_WASD(hsv) \
    {8, 1,  HSV_OVERRIDE_HELP(hsv, OVERRIDE_BRIGHTNESS)}, \
    {14, 2, HSV_OVERRIDE_HELP(hsv, OVERRIDE_BRIGHTNESS)}, \
    {20, 1, HSV_OVERRIDE_HELP(hsv, OVERRIDE_BRIGHTNESS)}
#define SET_FN_KEYS(hsv) \
    {6, 1, hsv}, {17, 2, hsv}, {29, 2, hsv}, \
    {43, 2, hsv}, {55, 2, hsv}, {67, 2, hsv}, {70, 1, hsv}
#define SET_BRACKETS(hsv) \
    {24, 1, hsv}, {33, 1, hsv}, {40, 1, hsv}, {49, 1, hsv}
#define SET_LOWER(hsv) {34, 1, hsv}
#define SET_RAISE(hsv) {39, 1, hsv}

/* RGB LAYOUT
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
const rgblight_segment_t PROGMEM my_base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_UNDERGLOW(HSV_BLUE),
    SET_LOWER(HSV_PURPLE),
    SET_RAISE(HSV_GREEN)
);

const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_UNDERGLOW(HSV_WHITE),
    SET_WASD(HSV_WHITE),
    SET_ARROWS(HSV_WHITE),
    {38, 1, HSV_WHITE} // space key
);

const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_UNDERGLOW(HSV_PURPLE),
    SET_FN_KEYS(HSV_PURPLE),
    SET_BRACKETS(HSV_PURPLE),
    {11, 1, HSV_PURPLE},
    {3, 1, HSV_GREEN},
    {5, 1, HSV_RED},
    {23, 1, HSV_RED}
);

const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_UNDERGLOW(HSV_GREEN),
    SET_ARROWS(HSV_WHITE),
    {0, 1, HSV_GREEN},
    {7, 1, HSV_GREEN},
    {15, 1, HSV_GREEN},
    {19, 1, HSV_GREEN},
    {23, 1, HSV_BLUE},
    {32, 1, HSV_RED},
    {41, 2, HSV_GREEN},
    {46, 1, HSV_GREEN},
    {49, 1, HSV_GREEN},
    {58, 1, HSV_GREEN},
    {61, 1, HSV_GREEN},
    {66, 1, HSV_RED},
    {68, 1, HSV_RED},
    {70, 1, HSV_RED},
    {73, 1, HSV_GREEN}
);

const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_UNDERGLOW(HSV_WHITE),
    {14, 1, HSV_WHITE}, // mouse left
    {19, 2, HSV_WHITE}, // mouse up/dn
    {26, 1, HSV_WHITE}, // mouse right
    {41, 2, HSV_WHITE}, // whl up/dn
    {47, 1, HSV_WHITE}, // l-click
    {53, 1, HSV_WHITE}, // m-click
    {59, 1, HSV_WHITE}  // r-click
);

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_UNDERGLOW(HSV_RED)
);

const rgblight_segment_t *const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_base_layer,
    my_layer1_layer,
    my_layer2_layer,
    my_layer3_layer,
    my_layer4_layer,
    my_capslock_layer
);

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(5, led_state.caps_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state, _QWERTY));
    rgblight_set_layer_state(1, layer_state_cmp(state, _GAMING));
    rgblight_set_layer_state(2, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(3, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(4, layer_state_cmp(state, _POINTER));
    return state;
}

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
    rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL);
    rgblight_set_speed_noeeprom(30);
}
