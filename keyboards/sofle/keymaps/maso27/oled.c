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

//Sets up what the OLED screens display.

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

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write("QWRTY", false);
            break;
        case _GAMING:
            oled_write("GAMES", false);
            break;
        default:
            oled_write("UNDEF", false);
    }

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
    oled_write("CPSLK", led_usb_state.caps_lock);

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
    return 0;
}


#endif
