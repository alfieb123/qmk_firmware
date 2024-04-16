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
#define SFT_CWD LSFT_T(CW_TOGG)

// home row mods
#define ALT_KCS LALT_T(KC_S)
#define CTL_KCD LCTL_T(KC_D)
#define SFT_KCF LSFT_T(KC_F)
#define GUI_KCG LGUI_T(KC_G)

#define ALT_KCL LALT_T(KC_L)
#define CTL_KCK LCTL_T(KC_K)
#define SFT_KCJ RSFT_T(KC_J)
#define GUI_KCH LGUI_T(KC_H)

// to switch between windows of the same app in mac, its cmd + `
#define CMD_GRV LGUI(KC_GRV)

#define RALT_EQ RALT_T(KC_EQL)
#define RALT_DQ RALT_T(KC_DQUO)
#define LGUI_DQ LGUI_T(KC_DQUO)
#define LGUI_EQ LGUI_T(KC_EQL)
#define LCTL_MI LCTL_T(KC_MINS)

enum custom_keycodes {
    CPP_PTR = SAFE_RANGE,
    LT1_UND,
    RBR_D,
    LBR_D,
    RBR_F,
    LBR_F,
    RBR_T,
    LBR_T,
    RBR_P,
    LBR_P,
    XTHENV,
};


static uint16_t key_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // ------ THE POINTER ONE ------//
        case CPP_PTR:
            if (record->event.pressed) {
                // when keycode CPP_PTR is pressed
                SEND_STRING("->");
            }
            return false; // Skip all further processing of this key

        // ------ CODE NAVIGATION IN HELIX ------//

        case RBR_D:
            if (record->event.pressed) {
                // when keycode CPP_PTR is pressed
                SEND_STRING("]d");
            }
            return false; // Skip all further processing of this key

        case LBR_D:
            if (record->event.pressed) {
                // when keycode CPP_PTR is pressed
                SEND_STRING("[d");
            }
            return false; // Skip all further processing of this key

        case RBR_F:
            if (record->event.pressed) {
                // when keycode CPP_PTR is pressed
                SEND_STRING("]f");
            }
            return false; // Skip all further processing of this key

        case LBR_F:
            if (record->event.pressed) {
                // when keycode CPP_PTR is pressed
                SEND_STRING("[f");
            }
            return false; // Skip all further processing of this key


        case RBR_T:
            if (record->event.pressed) {
                // when keycode CPP_PTR is pressed
                SEND_STRING("]t");
            }
            return false; // Skip all further processing of this key

        case LBR_T:
            if (record->event.pressed) {
                // when keycode CPP_PTR is pressed
                SEND_STRING("[t");
            }
            return false; // Skip all further processing of this key


        case RBR_P:
            if (record->event.pressed) {
                // when keycode CPP_PTR is pressed
                SEND_STRING("]p");
            }
            return false; // Skip all further processing of this key

        case LBR_P:
            if (record->event.pressed) {
                // when keycode CPP_PTR is pressed
                SEND_STRING("[p");
            }
            return false; // Skip all further processing of this key

        case XTHENV:
            if (record->event.pressed) {
                // when keycode CPP_PTR is pressed
                SEND_STRING("xv");
            }
            return false; // Skip all further processing of this key

        // ------ CODE NAVIGATION IN HELIX ------//

        case LT1_UND:
            if (record->event.pressed) {
                // Key has been pressed, start the timer
                key_timer = timer_read();
                layer_on(1); // Activate layer 1
            } else {
                // Key has been released, check the timer
                if (timer_elapsed(key_timer) < TAPPING_TERM) {
                    // Tapping term defines the time for a tap, if less, it's a tap
                    tap_code16(KC_UNDS); // Send the underscore keycode
                }
                layer_off(1); // Deactivate layer 1 regardless of whether it was a tap or hold
            }
            return false; // Skip all further processing of this key

        default:
            return true; // Process all other keycodes normally
    }
};

// customise caps word
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_SPC: 
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT_split_4x6_5(
   KC_TAB,  KC_EQL, KC_LALT, LCTL_MI, LGUI_EQ, KC_RALT,     KC_RALT, LGUI_DQ, KC_LCTL, KC_LALT,  KC_DEL, KC_BSPC,
  KC_MINS,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_MEH,
  KC_UNDS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, CMD_GRV,
  KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
                             LT1_ENT, LT2_ESC, KC_LSFT,     KC_LSFT, LT2_SPC, LT1_UND,
                                      LT3_LBR, CW_TOGG,     KC_LGUI, LT3_RBR
  ),

[1] = LAYOUT_split_4x6_5(
  _______, _______,  KC_INS,  KC_GRV, KC_HOME,  KC_END,     _______, KC_PGDN, KC_PGUP, _______, _______, _______,
  _______, KC_EXLM,   KC_AT, KC_LCBR, KC_RCBR,KC_TILDE,     CPP_PTR, KC_CIRC, KC_MINS, KC_QUOT, CMD_GRV, _______,
  _______, MAC_HSH,  KC_DLR, KC_LPRN, KC_RPRN, KC_PIPE,      KC_GRV,  KC_EQL, KC_UNDS, KC_DQUO,  KC_INS, _______,
  _______, KC_PERC, KC_HASH, KC_LBRC, KC_RBRC, KC_AMPR,     _______, KC_BSLS, _______, _______, _______, _______,
                             _______, _______, _______,     _______, _______, _______,
                                      _______, _______,     _______, _______
  ),

[2] = LAYOUT_split_4x6_5(
  _______, _______, _______, _______, _______, _______,     _______, KC_PPLS, KC_PMNS, KC_PAST, _______, _______,
  _______,  KC_F12,  KC_F11,  KC_F10,   KC_F9, MVD_NXT,      KC_EQL,    KC_7,    KC_8,    KC_9, KC_PAST, _______,
  _______,   KC_F8,   KC_F7,   KC_F6,   KC_F5, KC_LGUI,      KC_DOT,    KC_4,    KC_5,    KC_6, KC_PPLS, _______,
  _______,   KC_F4,   KC_F3,   KC_F2,   KC_F1, MVD_PRV,        KC_0,    KC_1,    KC_2,    KC_3, KC_PMNS, _______,
                             _______, _______, _______,     _______, KC_LCTL, _______,
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
