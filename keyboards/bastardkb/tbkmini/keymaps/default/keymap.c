/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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


/*
base layer, home row mods
layer 1, symbols
layer 2, numbers, and fs
layer 3, arrow keys
layer 4, mouse
*/

#define _______ KC_NO
#define XXXX KC_NO
#define missing KC_NO

#define SNUBS LSFT(KC_NUBS)

#define GUI_KCA LGUI_T(KC_A)
#define ALT_KCS LALT_T(KC_S)
#define CTL_KCD LCTL_T(KC_D)
#define SFT_KCF LSFT_T(KC_F)
#define GUI_KCG LGUI_T(KC_G)

#define GUI_SCN LGUI_T(KC_SCLN)
#define ALT_KCL LALT_T(KC_L)
#define CTL_KCK LCTL_T(KC_K)
#define SFT_KCJ RSFT_T(KC_J)
#define GUI_KCH LGUI_T(KC_H)

#define GUI_PLS LGUI_T(KC_PPLS)
#define ALT_NU6 LALT_T(KC_6)
#define CTL_NU5 LCTL_T(KC_5)
#define SFT_NU4 LSFT_T(KC_4)
#define GUI_DOT LGUI_T(KC_DOT)

#define GUI__F8 LGUI_T(KC_F8)
#define ALT__F7 LALT_T(KC_F7)
#define CTL__F6 LCTL_T(KC_F6)
#define SFT__F5 LSFT_T(KC_F5)

#define LT1_BSP LT(1, KC_BSPC)
#define LT1_ENT LT(1, KC_ENT)
#define LT2_ESC LT(2, KC_ESC)
#define LT2_SPC LT(2, KC_SPC)
// #define LT3_KCE LT(3, KC_E)
#define LT3_KCR LT(3, KC_R)
#define LT4_KCT LT(4, KC_T)

// mac virtual desktops
#define MVD_NXT LCTL(KC_RGHT)
#define MVD_PRV LCTL(KC_LEFT)

// define the mac version of has which is alt+3... wierdly
#define MAC_HSH LALT(KC_3)

// windows virtual desktops
#define WVD_NXT LGUI(LCTL(KC_RGHT))
#define WVD_PRV LGUI(LCTL(KC_LEFT))
#define WNCLOSE LALT(KC_F4)

enum custom_keycodes {
    CPP_PTR = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case CPP_PTR:
        if (record->event.pressed) {
            // when keycode CPP_PTR is pressed
            SEND_STRING("->");
        } else {
            // when keycode CPP_PTR is released
        }
        break;

    }
    return true;
};

const uint16_t PROGMEM c_bspc[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM c_del[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM c_tab[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM c_unds[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM c_mins[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM c_plus[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM c_mult[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM c_eql[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM c_dquo[] = {KC_I, KC_O, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(c_bspc, KC_BSPC), // backspace
    COMBO(c_del, KC_DEL), //delete
    COMBO(c_tab, KC_TAB), // tab
    COMBO(c_unds, KC_UNDS), //underscore
    COMBO(c_mins, KC_MINS), //minus
    COMBO(c_plus, KC_PPLS), //plus
    COMBO(c_mult, KC_PAST), //mult *
    COMBO(c_eql, KC_EQL), //equal
    COMBO(c_dquo, KC_DQUO), // double quote
};

//TODO : implement some tap dance functions for stuff like the left and right bracket.. trying top take stuff off the pinky!

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_TAB,   KC_Q,    KC_W,    KC_E, LT3_KCR,  LT4_KCT,                         KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LBRC,   KC_A,  ALT_KCS, CTL_KCD, SFT_KCF, GUI_KCG,                      GUI_KCH, SFT_KCJ, CTL_KCK, ALT_KCL, KC_SCLN, KC_RBRC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,   KC_M,  KC_COMM,  KC_DOT, KC_SLSH, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               LT1_ENT,  LT2_ESC, CW_TOGG,    _______,  LT2_SPC, LT1_BSP
                                            //`--------------------------'  `--------------------------'

        ),
    [1] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______, KC_EXLM,   KC_AT, KC_LCBR, KC_RCBR,KC_TILDE,                      CPP_PTR, KC_CIRC, KC_MINS, KC_QUOT, _______,  _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, MAC_HSH,  KC_DLR, KC_LPRN, KC_RPRN, KC_PIPE,                       KC_GRV,  KC_EQL, KC_UNDS, KC_DQUO,  KC_INS, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_PERC, KC_HASH, KC_LBRC, KC_RBRC, KC_AMPR,                      _______, KC_BSLS, KC_HOME,  KC_END, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______, _______, _______,    _______, _______, _______
                                            //`--------------------------'  `--------------------------'

        ),
    [2] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______,  KC_F12,  KC_F11,  KC_F10,   KC_F9, MVD_NXT,                       KC_EQL,    KC_7,    KC_8,    KC_9, KC_PAST, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______,   KC_F8, ALT__F7, CTL__F6, SFT__F5, KC_LGUI,                      GUI_DOT, SFT_NU4, CTL_NU5, ALT_NU6, KC_PPLS, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______,   KC_F4,   KC_F3,   KC_F2,   KC_F1, MVD_PRV,                         KC_0,    KC_1,    KC_2,    KC_3, KC_PMNS, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______, _______, _______,    _______, _______,   KC_DEL
                                            //`--------------------------'  `--------------------------'

        ),
    [3] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______, _______, _______, _______, _______, _______,                      _______, KC_PGDN, KC_PGUP, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______, _______, _______,    _______, _______, _______
                                            //`--------------------------'  `--------------------------'

        ),
    [4] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______, _______, _______, _______, _______, _______,                      _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            QK_BOOT, _______, _______, _______, _______, _______,                      _______, KC_WH_D, KC_WH_U, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______, KC_BTN3, _______,    _______, KC_BTN1,  KC_BTN2
                                            //`--------------------------'  `--------------------------'

        )};
   //  [5] = LAYOUT_split_3x6_3(
   //      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
   //          _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
   //      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   //          _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
   //      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   //          _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
   //      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
   //                                              _______, _______, _______,    _______, _______, _______
   //                                          //`--------------------------'  `--------------------------'

   //      ),
