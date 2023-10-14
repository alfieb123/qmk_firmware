/* 
 * Copyright 2021 Ian Sterling <xyverz on Github.com>
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

#include QMK_KEYBOARD_H

#define _______ KC_NO
#define LT1_BSP LT(1, KC_BSPC)
#define LT1_ENT LT(1, KC_ENT)
#define LT2_ESC LT(2, KC_ESC)
#define LT2_SPC LT(2, KC_SPC)
// mac virtual desktops
#define MVD_NXT LCTL(KC_RGHT)
#define MVD_PRV LCTL(KC_LEFT)
// define the mac version of has which is alt+3... wierdly
#define MAC_HSH LALT(KC_3)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT_split_4x6_5(
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
  _______,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, _______,
  _______,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, _______,
  _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, _______,
                             LT1_ENT, LT2_ESC, _______,     _______, LT2_SPC, LT1_BSP,
                                      _______, _______,     _______, _______
  ),

[1] = LAYOUT_split_4x6_5(
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
  _______, KC_EXLM,   KC_AT, KC_LCBR, KC_RCBR,KC_TILDE,     _______, KC_CIRC, KC_MINS, KC_QUOT, _______, _______,
  _______, MAC_HSH,  KC_DLR, KC_LPRN, KC_RPRN, KC_PIPE,     KC_LGUI,  KC_EQL, KC_UNDS, KC_DQUO, KC_LGUI, _______,
  _______, KC_PERC, KC_HASH, KC_LBRC, KC_RBRC, KC_AMPR,     _______, KC_BSLS, _______, _______, _______, _______,
                             _______, _______, _______,     _______, _______, _______,
                                      _______, _______,     _______, _______
  ),

[2] = LAYOUT_split_4x6_5(
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
  _______,  KC_F12,  KC_F11,  KC_F10,   KC_F9, MVD_NXT,      KC_EQL,    KC_7,    KC_8,    KC_9, KC_PAST, _______,
  _______,   KC_F8,   KC_F7,   KC_F6,   KC_F5, KC_LGUI,     GUI_DOT,    KC_4,    KC_5,    KC_6, KC_PPLS, _______,
  _______,   KC_F4,   KC_F3,   KC_F2,   KC_F1, MVD_PRV,        KC_0,    KC_1,    KC_2,    KC_3, KC_PMNS, _______,
                             _______, _______, _______,     _______, _______, _______,
                                      _______, _______,     _______, _______
  ),

// [0] = LAYOUT_split_4x6_5(
//   _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
//                              _______, _______, _______,     _______, _______, _______,
//                                       _______, _______,     _______, _______
//   ),

};
