// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
// #include <stdio.h>

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum ferris_layers {
  _QWERTY,
  _LOWER,
  _RAISE
};

enum ferris_tap_dances {
  TD_Q_ESC
};

// const uint16_t PROGMEM c_esc[] = {KC_W, KC_E, COMBO_END};
// const uint16_t PROGMEM c_ent[] = {KC_S, KC_D, COMBO_END};
// const uint16_t PROGMEM c_bspc[] = {KC_K, KC_L, COMBO_END};
// const uint16_t PROGMEM c_del[] = {KC_O, KC_P, COMBO_END};
// const uint16_t PROGMEM c_delwrd[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM c_tab[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM c_unds[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM c_mins[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM c_eql[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM c_dquo[] = {KC_I, KC_O, COMBO_END};
// const uint16_t PROGMEM c_mo3[] = {KC_A, KC_S, COMBO_END};
// const uint16_t PROGMEM c_lgui[] = {KC_R, KC_T, COMBO_END};
// const uint16_t PROGMEM c_lgui2[] = {KC_Y, KC_U, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
   //  COMBO(c_esc, KC_ESC), //escape
   //  COMBO(c_ent, KC_ENT), //enter
   //  COMBO(c_bspc, KC_BSPC), // backspace
   //  COMBO(c_del, KC_DEL), //delete
   //  COMBO(c_delwrd, LCTL(KC_BSPC)), //delete word
    COMBO(c_tab, KC_TAB), // tab
    COMBO(c_unds, KC_UNDS), //underscore
    COMBO(c_mins, KC_MINS), //minus
    COMBO(c_eql, KC_EQL), //equal
    COMBO(c_dquo, KC_AT), // this is a double quote ". notice we are using kc_at which is noramlly the at symbol but not on uk for some reason.
   //  COMBO(c_mo3, MO(3)), // layer toggle to layer
   //  COMBO(c_lgui, KC_LGUI), // Os key
   //  COMBO(c_lgui2, KC_LGUI), // Os key
    // COMBO(combo2, LCTL(KC_Z)), // keycodes with modifiers are possible too!
};

/*
base layer, home row mods
layer 1, symbols
layer 2, numbers, and fs
layer 3, arrow keys
layer 4, mouse
*/

#define _______ KC_NO
#define missing KC_NO

#define SNUBS LSFT(KC_NUBS) 

#define GUI_KCA LGUI_T(KC_A)
#define ALT_KCS LALT_T(KC_S)
#define CTL_KCD LCTL_T(KC_D)
#define SFT_KCF LSFT_T(KC_F)

#define GUI_SCN LGUI_T(KC_SCLN)
#define ALT_KCL LALT_T(KC_L)
#define CTL_KCK LCTL_T(KC_K)
#define SFT_KCJ RSFT_T(KC_J)

// #define GUI_NUS LGUI_T(KC_NUHS)
// #define ALT_DLR LALT_T(KC_DLR)
// #define CTL_LPR LCTL_T(KC_LPRN)
// #define SFT_RPR LSFT_T(KC_RPRN)

// #define ALT__AT LALT_T(KC_AT)
// #define CTL_UND LCTL_T(KC_UNDS)
// #define SFT_EQL LSFT_T(KC_EQL)


#define GUI_PLS LGUI_T(KC_PPLS)
#define ALT_NU6 LALT_T(KC_6)
#define CTL_NU5 LCTL_T(KC_5)
#define SFT_NU4 LSFT_T(KC_4)

#define GUI__F8 LGUI_T(KC_F8)
#define ALT__F7 LALT_T(KC_F7)
#define CTL__F6 LCTL_T(KC_F6)
#define SFT__F5 LSFT_T(KC_F5)

#define LT1_BSP LT(1, KC_BSPC)
#define LT1_ENT LT(1, KC_ENT)
#define LT2_ESC LT(2, KC_ESC)
#define LT3_KCE LT(3, KC_E)
#define LT4_KCT LT(4, KC_T)

#define WVD_NXT LGUI(LCTL(KC_RGHT))
#define WVD_PRV LGUI(LCTL(KC_LEFT))

                                  
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
  //,-------------------------------------------.                    ,---------------------------------------------
        KC_Q,    KC_W, LT3_KCE,    KC_R, LT4_KCT,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, 
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
     GUI_KCA, ALT_KCS, CTL_KCD, SFT_KCF,    KC_G,                         KC_H, SFT_KCJ, CTL_KCK, ALT_KCL, GUI_SCN,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
                                         LT1_ENT, LT2_ESC,     KC_SPC,  LT1_BSP
                                      //-----------------'  `------------------
  ),

  [1] = LAYOUT(
  //,-------------------------------------------.                    ,---------------------------------------------
     KC_EXLM, KC_DQUO, KC_LCBR, KC_RCBR, KC_PIPE,                      _______, KC_CIRC, KC_MINS, KC_QUOT, _______,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
     KC_NUHS,  KC_DLR, KC_LPRN, KC_RPRN,   SNUBS,                      _______,  KC_EQL, KC_UNDS,   KC_AT, KC_LGUI,
  //|-------+--------+--------+--------+--------j                    |--------+--------+--------+--------+--------+
     KC_PERC, KC_HASH, KC_LBRC, KC_RBRC, KC_AMPR,                      _______, KC_NUBS, _______, _______, _______,
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
                                         _______, _______,    _______,  _______
                                      //-----------------'  `------------------
  ),

  [2] = LAYOUT(
  //,-------------------------------------------.                    ,---------------------------------------------
      KC_F12,  KC_F11,  KC_F10,   KC_F9, _______,                       KC_EQL,    KC_7,    KC_8,    KC_9, KC_PAST,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
     GUI__F8, ALT__F7, CTL__F6, SFT__F5, WVD_NXT,                       KC_DOT, SFT_NU4, CTL_NU5, ALT_NU6, GUI_PLS,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
       KC_F4,   KC_F3,   KC_F2,   KC_F1, WVD_PRV,                         KC_0,    KC_1,    KC_2,    KC_3, KC_PMNS,
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
                                         _______, _______,    _______,   KC_DEL
                                      //-----------------'  `------------------
  ),

  [3] = LAYOUT(
  //,-------------------------------------------.                    ,---------------------------------------------
     _______, _______, _______, KC_LALT, _______,                      _______, _______,  KC_TAB, _______, _______,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
     _______, _______, _______, _______, _______,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
     _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
                                         _______, _______,    _______, _______
                                      //-----------------'  `------------------
  ),

  [4] = LAYOUT(
  //,-------------------------------------------.                    ,---------------------------------------------
     _______, _______, _______, _______, _______,                      _______, KC_BTN1, KC_BTN3, KC_BTN2, _______,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
     _______, _______, _______, _______, _______,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
     _______, _______, _______, _______, _______,                      _______, KC_WH_D, KC_WH_U, _______, _______,
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
                                         _______, _______,    KC_BTN1, KC_BTN2
                                      //-----------------'  `------------------
  )

//   [3] = LAYOUT(
//   //,-------------------------------------------.                    ,---------------------------------------------
//      _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,
//   //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
//      _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,
//   //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
//      _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,
//   //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
//                                          _______, _______,    _______, _______
//                                       //-----------------'  `------------------
//   )
};

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//   [_QWERTY] = LAYOUT( 
//     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,  KC_I,    KC_O,   KC_P,
//     KC_CTLA, KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,  KC_K,    KC_L,   KC_SCLN,
//     KC_LSHZ, KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,  KC_COMM, KC_DOT, KC_RLSH,
//                                     KC_CLGV, KC_BSM1, KC_SPM2, KC_GUTA
//   ),
//
//   [_LOWER] = LAYOUT( 
//     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
//     QK_GESC, KC_HOME, KC_PGDN, KC_PGUP, KC_END,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT,
//     KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,         KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_ENT,
//                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  
//   ),
//
//   [_RAISE] = LAYOUT( 
//     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
//     KC_TAB,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_PIPE,
//     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_UNDS, KC_PLUS, KC_TRNS, KC_TRNS, QK_BOOT,
//                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
//   )
// };

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};
