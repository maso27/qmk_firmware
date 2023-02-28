# Compiling

Make example for this keyboard (after setting up your build environment):

    make handwired/dactyl_manuform/5x6_5:maso27

## Flashing

Flash using the correct command below in linux (or use QMK Toolbox in Windows). These commands can be mixed if, for example, you have an Elite C on the left and a pro micro on the right.

Press reset button on the keyboard before running the command.

Elite C:
avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 -U flash:w:handwired_dactyl_manuform_5x6_5_maso27.hex

Micro Pro:
avrdude -p atmega32u4 -P usb -c flip1 -U flash:w:handwired_dactyl_manuform_5x6_5_maso27.hex

Disconnect the first half, connect the second one and repeat the process.

