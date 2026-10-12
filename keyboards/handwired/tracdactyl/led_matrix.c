/*
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Publicw License as published by
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

#include "quantum.h"

// clang-format off
#ifdef RGB_MATRIX_ENABLE
/**
 * \brief LEDs index.
 *
 * .-----------------------------------------.                                  .-----------------------------------------.
 * |  20  |  16  |  12  |  8   |  4   |  0   |                                  |  50  |  46  |  42  |  38  |  34  |  30  |
 * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
 * |  21  |  17  |  13  |  9   |  5   |  1   |                                  |  51  |  47  |  43  |  39  |  35  |  31  |
 * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
 * |  22  |  18  |  14  |  10  |  6   |  2   |                                  |  52  |  48  |  44  |  40  |  36  |  32  |
 * |------+------+------+------+------|------|                                  |------+------+------+------+------+------|
 * |  23  |  19  |  15  |  11  |  7   |  3   |                                  |  53  |  49  |  45  |  41  |  37  |  33  |
 * '-------------+------+------+-------------/                                  \--------------------+--------------------'
 *               |  24  |  25  |    /       /---------------.                    \   56  \    |  57  |  58  |
 *               |      |      |   /       /       /       /      .---------------\       \   |      |      |
 *               '-------------'  '-------/   26  /  27   /        \   54  \  55   \-------'  '-------------'
 *                                       /---------------/          \       \       \
 *                                      /   28  /  29   /            '---------------'
 *                                     /       /       /
 *                                    '---------------'
 *
 * Note: the LED config simulates 58 LEDs instead of the actual 56 to prevent
 * confusion when testing LEDs during assembly when handedness is not set
 * correctly.  Those fake LEDs are bound to the physical bottom-left corner.d
 */
led_config_t g_led_config = { {
    /* Key Matrix to LED index. */
    // Left split.
    {      20,     16,     12,      8,      4,      0 }, // Num row
    {      21,     17,     13,      9,      5,      1 }, // Top row
    {      22,     18,     14,     10,      6,      2 }, // Middle row
    {      23,     19,     15,     11,      7,      3 }, // Bottom row
    {  NO_LED, NO_LED,     24,     25, NO_LED, NO_LED }, // Last 2
    {  NO_LED, NO_LED,     29,     27,     28,     26 }, // Thumb cluster

    // Right split.
    {      30,     34,     38,     42,     46,     50 }, // Num row
    {      31,     35,     39,     43,     47,     51 }, // Top row
    {      32,     36,     40,     44,     48,     52 }, // Middle row
    {      33,     37,     41,     45,     49,     53 }, // Bottom row
    {  NO_LED, NO_LED,     58,     57, NO_LED, NO_LED }, // Last 2
    {  NO_LED, NO_LED, NO_LED,     56,     55,     54 }  // Thumb cluster
}, {
    /* LED index to physical position. */
    // Left split.
    /* index=0  */ {  80,   0 }, {  80,  12 }, {  80,  24 }, {  80,  36 }, // col 6 (right most, left half)
    /* index=4  */ {  64,   0 }, {  64,  12 }, {  64,  24 }, {  64,  36 }, // col 5
    /* index=8  */ {  48,   0 }, {  48,  12 }, {  48,  24 }, {  48,  36 },
    /* index=12 */ {  32,   0 }, {  32,  12 }, {  32,  24 }, {  32,  36 },
    /* index=16 */ {  16,   0 }, {  16,  12 }, {  16,  24 }, {  16,  36 },
    /* index=20 */ {   0,   0 }, {   0,  12 }, {   0,  24 }, {   0,  36 }, // col 1 (left most)
    /* index=24 */ {  32,  48 }, {  48,  48 }, {  80,  48 }, {  96,  48 }, // Thumb row 1
    /* index=28 */ {  80,  60 }, {  96,  60 },                             // Thumb row 2
    // Right split.
    /* index=30 */ { 224,   0 }, { 224,  12 }, { 224,  24 }, { 224,  36 }, // col 12 (right most)
    /* index=34 */ { 208,   0 }, { 208,  12 }, { 208,  24 }, { 208,  36 }, // col 11
    /* index=38 */ { 192,   0 }, { 192,  12 }, { 192,  24 }, { 192,  36 },
    /* index=42 */ { 176,   0 }, { 176,  12 }, { 176,  24 }, { 176,  36 },
    /* index=46 */ { 160,   0 }, { 160,  12 }, { 160,  24 }, { 160,  36 },
    /* index=50 */ { 144,   0 }, { 144,  12 }, { 144,  24 }, { 144,  36 }, // col 7 (left most, right half)
    /* index=54 */ { 112,  60 }, { 128,  60 }, { 144,  60 }, // Lower thumb row
    /* index=57 */ { 160,  48 }, { 176,  48 }
}, {
    /* LED index to flag. */
    // Left split.
    /* index=0  */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, // col 1
    /* index=4  */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, // col 2
    /* index=8  */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=12 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=16 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=20 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=24 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_INDICATOR, LED_FLAG_INDICATOR, // Thumb cluster top
    /* index=28 */ LED_FLAG_INDICATOR, LED_FLAG_INDICATOR,                    // Thumb cluster bottom
    // /* index=24 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, // Thumb cluster top
    // /* index=28 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,                    // Thumb cluster bottom
    // Right split.
    /* index=30 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, // col 12
    /* index=34 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, // col 11
    /* index=38 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=42 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=46 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=50 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    /* index=54 */ LED_FLAG_INDICATOR, LED_FLAG_INDICATOR, LED_FLAG_INDICATOR, // Thumb cluster
    /* index=57 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT                    // Final bottom 2 keys
    // /* index=54 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, // Thumb cluster
    // /* index=57 */ LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT                    // Final bottom 2 keys
} };
#endif
// clang-format on
