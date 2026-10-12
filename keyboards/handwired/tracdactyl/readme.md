# Tracdactyl

An ergonomic keyboard with integrated trackball.

Engineered to be a full mouse replacement solution with high-quality, custom-developed components.

Keyboard case generated from [Wylderbuilds Github](https://github.com/bullwinkle3000/dactyl-keyboard)
-   Left hand: dactyl_mini
-   Right hand: minithicc3

Keyboard code leveraged from [Bastard Keyboards' Charybdis](https://github.com/qmk/qmk_firmware/tree/master/keyboards/bastardkb/charybdis)

For notes on how to operate the trackball's Pointer Layer, see [this guide](https://www.youtube.com/watch?v=XjFAvW-78bE)

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information.

Brand new to QMK? Start with the [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

Check out the [keyboard build guides](https://wylderbuilds.com/building-it) for notes on how to build the keyboard

## Building the firmware

The template is:

```shell
qmk compile -kb handwired/tracdactyl -km maso27
```

See below for populated commands per layout

The `default` keymap is inspired from the original [Dactyl Manuform](../../handwired/dactyl_manuform) layout.

Check out the `via` layout if you're looking for VIA support.

## Customizing the firmware

### Dynamic DPI scaling

The pointer's DPI can be changed at runtime.

By default, the DPI is set to `800`. The Tracdactyl supports up to 16 different DPI values. By default, it cycles between `400` and `3400`, with a step of `200` (_ie._ `400`, `600`, `800`, …, `3400`).

Calling `tracdactyl_cycle_pointer_default_dpi(bool forward)` will cycle forward or backward the possible values.

Use `tracdactyl_cycle_pointer_default_dpi_noeeprom(bool forward)` to change the DPI value without persisting the change to EEPROM (_ie._ resetting the board will revert to the last saved value).

`tracdactyl_get_pointer_default_dpi()` returns the current DPI value.

This behavior can be further customized with the following defines:

```c
#define TRACDACTYL_MINIMUM_DEFAULT_DPI 400
#define TRACDACTYL_DEFAULT_DPI_CONFIG_STEP 200
```

### Trackball acceleration

The speed of motion can be used to determine distance traveled.
To enable this, use the following define:

```c
#define TB_ACCELERATION
```
### Drag-scroll

Drag-scroll enables scrolling with the trackball. When drag-scroll is enabled, the trackball's `x` and `y` movements are converted into `h` (horizontal) and `v` (vertical) movement, effectively sending scroll instructions to the host system.

Call `tracdactyl_set_pointer_dragscroll_enabled(bool enable)` to enable/disable drag-scroll.

`tracdactyl_get_pointer_dragscroll_enabled()` returns whether drag-scroll mode is currently enabled.

To invert the horizontal scrolling direction, define `TRACDACTYL_DRAGSCROLL_REVERSE_X`:

```c
#define TRACDACTYL_DRAGSCROLL_REVERSE_X
```

To invert the vertical scrolling direction (_ie._ mimic macOS "natural" scroll direction), define `TRACDACTYL_DRAGSCROLL_REVERSE_Y`:

```c
#define TRACDACTYL_DRAGSCROLL_REVERSE_Y
```

This only affects the vertical scroll direction.

### Sniping mode

Sniping mode slows down the pointer for more precise gestures. It is useful when combined with a higher default DPI.

Call `tracdactyl_set_pointer_sniping_enabled(bool enable)` to enable/disable sniping mode.

`tracdactyl_get_pointer_sniping_enabled()` returns whether sniping mode is currently enabled.

Like the default pointer's DPI, the sniper mode DPI can be changed at runtime.

By default, sniping mode lowers the DPI to `200`. This can be changed at runtime: the Tracdactyl supports up to 4 different DPI values for sniping mode. By default, it cycles between `200`, `300`, `400` and `500`.

Calling `tracdactyl_cycle_pointer_sniping_dpi(bool forward)` will cycle forward or backward the possible values.

Use `tracdactyl_cycle_pointer_sniping_dpi_noeeprom(bool forward)` to change the sniping mode DPI value without persisting the change to EEPROM (_ie._ resetting the board will revert to the last saved value).

`tracdactyl_get_pointer_sniping_dpi()` returns the current sniping mode DPI value.

This behavior can be further customized with the following defines:

```c
#define TRACDACTYL_MINIMUM_SNIPING_DPI 200
#define TRACDACTYL_SNIPING_DPI_CONFIG_STEP 100
```

### Custom keycodes

The Tracdactyl firmware defines a number of keycodes to leverage its features, namely:

```
#ifndef NO_TRACDACTYL_KEYCODES
enum tracdactyl_keycodes {
  POINTER_DEFAULT_DPI_FORWARD = QK_KB_0,
  POINTER_DEFAULT_DPI_REVERSE,
  POINTER_SNIPING_DPI_FORWARD,
  POINTER_SNIPING_DPI_REVERSE,
  SNIPING_MODE,
  SNIPING_MODE_TOGGLE,
  DRAGSCROLL_MODE,
  DRAGSCROLL_MODE_TOGGLE,
};

#define DPI_MOD POINTER_DEFAULT_DPI_FORWARD
#define DPI_RMOD POINTER_DEFAULT_DPI_REVERSE
#define S_D_MOD POINTER_SNIPING_DPI_FORWARD
#define S_D_RMOD POINTER_SNIPING_DPI_REVERSE
#define SNIPING SNIPING_MODE
#define SNP_TOG SNIPING_MODE_TOGGLE
#define DRGSCRL DRAGSCROLL_MODE
#define DRG_TOG DRAGSCROLL_MODE_TOGGLE
#endif // !NO_TRACDACTYL_KEYCODES
```

To disable the custom keycodes, and reduce binary size, simply add a definition in `config.h`:

```c
#define NO_TRACDACTYL_KEYCODES
```

### Configuration Syncing

If you want/need to enable syncing of the tracdactyl config, such as to read the sniping or drag scroll modes on the other half (such as for displaying the status via rgb matrix, or added on screens, or what not), you can enabled this. To do so, add this to your `config.h`:

```c
#define TRACDACTYL_CONFIG_SYNC
```

Note that you will need to reflash both sides when enabling this.

### Enable Large Mouse Reports

By default, the X and Y motion for the pointing device/mouse reports is -127 to 127. You can definitely hit the limit for that with the sensors. You can enable support for -32767 to 32767 by adding this to your `config.h`:

```c
#define MOUSE_EXTENDED_REPORT
```

Note that you will need to reflash both sides when enabling this.
