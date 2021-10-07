# VIA keymap for Sofle RGB from keyhive

Features:

-   "Gaming" layer changes I,J,K,L to arrows.  Enabled with right encoder press.
-   RGB underglow changes color based on current layer.
-   The OLED on master half shows selected mode and caps lock state. OLED on Slave half shows WPM.
-   Left encoder controls arrow left/right, right controls arrow up/down.  With SHIFT, left controls media prev/next, right controls volume up/down.
-   Via support
-   RGB underglow support

## Flashing

My keyboard has pro micro on the left, Elite C arduino on the right.
I use the EE_HANDS method of left/right delineation so I program the eeprom of each board with a left or right definition file.
These files (eeprom-lefthand.eep and eeprom-righthand.eep) are found in qmk_firmware/quantum/split_common.

Flash (in Linux) using the correct commands below:

```sh
# for pro micro-based builds
avrdude -p atmega32u4 -P usb -c flip1 -U eeprom:w:eeprom-lefthand.eep
avrdude -p atmega32u4 -P usb -c flip1 -U flash:w:<compiledfile.hex>

# for Elite C or dfu bootloader builds
avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 -U eeprom:w:eeprom-righthand.eep
avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 -U flash:w:<compiledfile.hex>
```
