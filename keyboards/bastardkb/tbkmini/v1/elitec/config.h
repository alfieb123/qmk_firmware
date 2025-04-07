/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#pragma once

/* Key matrix configuration. */
#define MATRIX_ROW_PINS \
    { B5, F7, F6, B6 }
#define MATRIX_COL_PINS \
    { B4, E6, C6, B1, B3, B2 }

/* Handedness. */
#define MASTER_RIGHT

/* serial.c configuration (for split keyboard). */
#define SOFT_SERIAL_PIN D0

/* RGB settings. */
#define RGB_DI_PIN D2

#define COMBO_COUNT 5
#define COMBO_TERM 30

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// Tap-Hold and Mod-Tap timing tweaks to mimic ZMK
#define TAPPING_TERM 220              // Matches ZMK tapping-term-ms
#define QUICK_TAP_TERM 165            // Matches ZMK quick_tap_ms
#define IGNORE_MOD_TAP_INTERRUPT      // Prevents accidental hold when typing fast
#define HOLD_ON_OTHER_KEY_PRESS       // Only trigger hold if another key is pressed
//#define PERMISSIVE_HOLD             // Optional: enables early hold, try it disabled first

// Optional: if you want more fine-tuned control per key
//#define TAPPING_TERM_PER_KEY


