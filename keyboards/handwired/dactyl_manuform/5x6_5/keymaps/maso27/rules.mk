VIA_ENABLE = no
CONSOLE_ENABLE = no         # Console for debug
MOUSEKEY_ENABLE  = no
ENCODER_ENABLE = yes
RGBLIGHT_ENABLE = yes
RGBLIGHT_DRIVER = custom
SRC += lpd8806.c
CAPS_WORD_ENABLE = yes
SRC += features/layer_lock.c

DYNAMIC_MACRO_ENABLE = yes
DYNAMIC_MACRO_NO_NESTING = yes
