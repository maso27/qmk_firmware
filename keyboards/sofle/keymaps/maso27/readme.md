# VIA keymap for Sofle RGB from keyhive

Layout in [Keyboard Layout Editor](http://www.keyboard-layout-editor.com/#/gists/76efb423a46cbbea75465cb468eef7ff) and [adjust layer](http://www.keyboard-layout-editor.com/#/gists/4bcf66f922cfd54da20ba04905d56bd4)

Features:

-   "Gaming" layer changes I,J,K,L to arrows.  Enabled with right encoder press.
-   RGB underglow changes color based on current layer.
-   The OLED on master half shows selected mode and caps lock state. OLED on Slave half shows WPM.
-   Left encoder controls arrow left/right, right controls arrow up/down.  With SHIFT, left controls media prev/next, right controls volume up/down.
-   Via support
-   RGB underglow support

## Flashing

My keyboard has pro micro on left as master, standard arduino on right as slave.

Flash using the correct command below:

```sh
# for pro micro-based builds
avrdude -p atmega32u4 -P usb -c flip1 -U flash:w:<compiledfile.hex>

# for Elite C or dfu bootloader builds
qmk flash
```
