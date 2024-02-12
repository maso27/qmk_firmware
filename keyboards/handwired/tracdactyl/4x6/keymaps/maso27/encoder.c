//Setting up what encoder rotation does. If your encoder can be pressed as a button, that's in your keymap.

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_WH_D, KC_WH_U)  },
    [1] =   { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),  ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [2] =   { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_DOWN, KC_UP)  }
};

// bool encoder_update_user(uint8_t index, bool clockwise) {
//     if (index == 0) {
//         if (clockwise) {
//             if (layer_state_is(LAYER_RAISE)) {
//                 tap_code(KC_RIGHT);
//     #ifdef RGBLIGHT_ENABLE
//             } else if (layer_state_is(LAYER_LOWER)) {
//                 rgblight_increase_val_noeeprom();
//     #endif
//             } else {
//                 tap_code(KC_VOLU);
//             }
//         } else {
//             if (layer_state_is(LAYER_RAISE)) {
//                 tap_code(KC_LEFT);
//     #ifdef RGBLIGHT_ENABLE
//             } else if (layer_state_is(LAYER_LOWER)) {
//                 rgblight_decrease_val_noeeprom();
//     #endif
//             } else {
//                 tap_code(KC_VOLD);
//             }
//         }
//     } else if (index == 1) {
//         if (clockwise) {
//             if (layer_state_is(LAYER_RAISE)) {
//                 tap_code(KC_DOWN);
//     #ifdef RGBLIGHT_ENABLE
// 	    } else if (layer_state_is(LAYER_LOWER)) {
//                 rgblight_decrease_speed_noeeprom();
//     #endif
//             } else {
//                 tap_code(KC_WH_D);
//             }
//         } else {
//             if (layer_state_is(LAYER_RAISE)) {
//                 tap_code(KC_UP);
//     #ifdef RGBLIGHT_ENABLE
//             } else if (layer_state_is(LAYER_LOWER)) {
//                 rgblight_increase_speed_noeeprom();
//     #endif
//             } else {
//                 tap_code(KC_WH_U);
//             }
//         }
//     }
//     return true;
// }
