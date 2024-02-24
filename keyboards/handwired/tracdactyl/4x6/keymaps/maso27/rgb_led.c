
void set_key_leds(uint8_t key_array[], size_t arr_size, HSV solidHSV) {
    RGB solidRGB = hsv_to_rgb(solidHSV);

    for (uint8_t i = 0; i < arr_size; i++) {
        rgb_matrix_set_color(key_array[i], solidRGB.r, solidRGB.g, solidRGB.b);
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    static uint8_t indicator_leds[] = {26, 27, 28, 29, 54, 55, 56};
    static uint8_t mouse_leds[]     = {15, 19, 37, 40, 41, 44, 48};
    static uint8_t arrow_leds[]     = {40, 43, 44, 48};
    static uint8_t extra_dir_leds[] = {41, 49, 51, 52};
    static uint8_t caps_lock_led[]  = {2};
    static uint8_t bracket_leds[]   = {3, 7, 49, 53};

    if (layer_state_is(LAYER_POINTER)) {
        set_key_leds(indicator_leds, ARRAY_SIZE(indicator_leds), (HSV){HSV_WHITE});
        set_key_leds(mouse_leds,     ARRAY_SIZE(mouse_leds),     (HSV){HSV_WHITE});
    } else if (host_keyboard_led_state().caps_lock) {
        set_key_leds(indicator_leds, ARRAY_SIZE(indicator_leds), (HSV){HSV_RED});
    } else if (layer_state_is(LAYER_LOWER)) {
        set_key_leds(indicator_leds, ARRAY_SIZE(indicator_leds), (HSV){HSV_PURPLE});
        set_key_leds(bracket_leds,   ARRAY_SIZE(bracket_leds),   (HSV){HSV_PURPLE});
    } else if (layer_state_is(LAYER_RAISE)) {
        set_key_leds(indicator_leds, ARRAY_SIZE(indicator_leds), (HSV){HSV_GREEN});
        set_key_leds(arrow_leds,     ARRAY_SIZE(arrow_leds),     (HSV){HSV_RED});
        set_key_leds(extra_dir_leds, ARRAY_SIZE(extra_dir_leds), (HSV){HSV_GREEN});
        set_key_leds(caps_lock_led,  ARRAY_SIZE(caps_lock_led),  (HSV){HSV_RED});

    }

    return false;
}
