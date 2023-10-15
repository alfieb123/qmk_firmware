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
#define LT3_LBR LT(3, KC_LBRC)
#define LT3_RBR LT(3, KC_RBRC)
#define LT4_HME LT(3, KC_HOME)
#define LT4_END LT(3, KC_END)
// mac virtual desktops
#define MVD_NXT LCTL(KC_RGHT)
#define MVD_PRV LCTL(KC_LEFT)
// define the mac version of has which is alt+3... wierdly
#define MAC_HSH LALT(KC_3)
#define DEL_WRD LALT(KC_BSPC)
#define SFT_CWD LSFT(QK_CAPS_WORD_TOGGLE)

// home row mods
#define ALT_KCS LALT_T(KC_S)
#define CTL_KCD LCTL_T(KC_D)
#define SFT_KCF LSFT_T(KC_F)
#define GUI_KCG LGUI_T(KC_G)

#define ALT_KCL LALT_T(KC_L)
#define CTL_KCK LCTL_T(KC_K)
#define SFT_KCJ RSFT_T(KC_J)
#define GUI_KCH LGUI_T(KC_H)

enum custom_keycodes {
    // QMKBEST = SAFE_RANGE,
    CPP_PTR = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    // case QMKBEST:
    //     if (record->event.pressed) {
    //         // when keycode QMKBEST is pressed
    //         SEND_STRING("QMK is the best thing ever!");
    //     } else {
    //         // when keycode QMKBEST is released
    //     }
    //     break;

    case CPP_PTR:
        if (record->event.pressed) {
            // when keycode QMKURL is pressed
            SEND_STRING("->");
        } else {
            // when keycode QMKURL is released
        }
        break;

    }
    return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT_split_4x6_5(
   KC_TAB,KC_TILDE, MAC_HSH,  KC_EQL, KC_UNDS, KC_MINS,     KC_QUOT, KC_DQUO, CPP_PTR, DEL_WRD,  KC_DEL, KC_BSPC,
  _______,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, _______,
  _______,    KC_A, ALT_KCS, CTL_KCD, SFT_KCF, GUI_KCG,     GUI_KCH, SFT_KCJ, CTL_KCK, ALT_KCL, KC_SCLN, _______,
  _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, _______,
                             LT1_ENT, LT2_ESC, SFT_CWD,     KC_LSFT, LT2_SPC, LT1_BSP,
                                      LT3_LBR, LT4_HME,     LT4_END, LT3_RBR
  ),

[1] = LAYOUT_split_4x6_5(
  _______, _______,  KC_INS,  KC_GRV, KC_HOME,  KC_END,     _______, KC_PGDN, KC_PGUP, _______, _______, _______,
  _______, KC_EXLM,   KC_AT, KC_LCBR, KC_RCBR,KC_TILDE,     _______, KC_CIRC, KC_MINS, KC_QUOT, _______, _______,
  _______, MAC_HSH,  KC_DLR, KC_LPRN, KC_RPRN, KC_PIPE,     _______,  KC_EQL, KC_UNDS, KC_DQUO, _______, _______,
  _______, KC_PERC, KC_HASH, KC_LBRC, KC_RBRC, KC_AMPR,     _______, KC_BSLS, _______, _______, _______, _______,
                             _______, _______, _______,     _______, _______, _______,
                                      _______, _______,     _______, _______
  ),

[2] = LAYOUT_split_4x6_5(
  _______, _______, _______, _______, _______, _______,     _______, KC_PPLS, KC_PMNS, KC_PAST, _______, _______,
  _______,  KC_F12,  KC_F11,  KC_F10,   KC_F9, MVD_NXT,      KC_EQL,    KC_7,    KC_8,    KC_9, KC_PAST, _______,
  _______,   KC_F8,   KC_F7,   KC_F6,   KC_F5, KC_LGUI,      KC_DOT,    KC_4,    KC_5,    KC_6, KC_PPLS, _______,
  _______,   KC_F4,   KC_F3,   KC_F2,   KC_F1, MVD_PRV,        KC_0,    KC_1,    KC_2,    KC_3, KC_PMNS, _______,
                             _______, _______, _______,     _______, _______, _______,
                                      _______, _______,     _______, _______
  ),

[3] = LAYOUT_split_4x6_5(
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,     KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, _______, _______,
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
                             _______, _______, _______,     _______, _______, _______,
                                      _______, _______,     _______, _______
  ),

[4] = LAYOUT_split_4x6_5(
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
  _______, _______, _______, _______, _______, _______,     _______, KC_WH_D, KC_WH_U, _______, _______, _______,
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
