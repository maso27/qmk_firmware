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

//Setting up what encoder rotation does. If your encoder can be pressed as a button, that function can be set in Via.
/*
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(MS_WHLD, MS_WHLU)  },
    [1] =   { ENCODER_CCW_CW(MS_LEFT, MS_RGHT),  ENCODER_CCW_CW(MS_DOWN, MS_UP)    },
    [2] =   { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),  ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [3] =   { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_DOWN, KC_UP)    },
    [4] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(MS_WHLD, MS_WHLU)  }
};
#endif
*/
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            if (layer_state_is(_LOWER)) {
                rgblight_increase_val_noeeprom();
            } else if (layer_state_is(_RAISE)) {
                tap_code(KC_RGHT);
            } else if (layer_state_is(_GAMING)) {
                tap_code(MS_RGHT);
            } else {
                tap_code(KC_VOLU);
            }
        } else {
            if (layer_state_is(_LOWER)) {
                rgblight_decrease_val_noeeprom();
            } else if (layer_state_is(_RAISE)) {
                tap_code(KC_LEFT);
            } else if (layer_state_is(_GAMING)) {
                tap_code(MS_LEFT);
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
                tap_code(MS_UP);
            } else {
                tap_code(MS_WHLD); // scroll wheel down
            }
        } else {
            if( layer_state_is(_LOWER)) {
                rgblight_decrease_speed_noeeprom();
            } else if (layer_state_is(_RAISE)) {
                tap_code(KC_DOWN);
            } else if (layer_state_is(_GAMING)) {
                tap_code(MS_DOWN);
            } else {
                tap_code(MS_WHLU); // scroll wheel up
            }
        }
    }
    return false;
}

#endif