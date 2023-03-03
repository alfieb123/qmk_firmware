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

const uint16_t PROGMEM c_esc[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM c_ent[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM c_bspc[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM c_del[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM c_delwrd[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM c_tab[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM c_unds[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM c_mins[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM c_eql[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM c_dquo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM c_mo3[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM c_lgui[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM c_lgui2[] = {KC_Y, KC_U, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(c_esc, KC_ESC), //escape
    COMBO(c_ent, KC_ENT), //enter
    COMBO(c_bspc, KC_BSPC), // backspace
    COMBO(c_del, KC_DEL), //delete
    COMBO(c_delwrd, LCTL(KC_BSPC)), //delete word
    COMBO(c_tab, KC_TAB), // tab
    COMBO(c_unds, KC_UNDS), //underscore
    COMBO(c_mins, KC_MINS), //minus
    COMBO(c_eql, KC_EQL), //equal
    COMBO(c_dquo, KC_AT), // this is a double quote ". notice we are using kc_at which is noramlly the at symbol but not on uk for some reason.
    COMBO(c_mo3, MO(3)), // layer toggle to layer
    COMBO(c_lgui, KC_LGUI), // Os key
    COMBO(c_lgui2, KC_LGUI), // Os key
    // COMBO(combo2, LCTL(KC_Z)), // keycodes with modifiers are possible too!
};

#define _______ KC_NO
#define missing KC_NO
#define SNUBS LSFT(KC_NUBS) 
#define LALTCOM LALT_T(KC_COMM) 
#define LCTLDOT LCTL_T(KC_DOT) 
#define LSFTSLH LSFT_T(KC_SLSH) 
#define LCTLESC LCTL_T(KC_ESC) 
#define DELWRD LCTL(KC_BSPC)
#define LT1TAB LT(1, KC_TAB)
#define LT2BSPC LT(2, KC_BSPC)
#define LT2SCLN LT(2, KC_SCLN)
#define LT3ENT LT(3, KC_ENT)

#define WVD_U LGUI(LCTL(KC_RGHT)) //windows virtual desktop up
#define WVD_D LGUI(LCTL(KC_LEFT)) // windows virtual desktop down
                                  
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
  //,-------------------------------------------.                    ,---------------------------------------------
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, 
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, LT2SCLN,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, LALTCOM, LCTLDOT, LSFTSLH,
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
                                         KC_LCTL, KC_LSFT,     KC_SPC,  MO(1) 
                                      //-----------------'  `------------------
  ),

  [1] = LAYOUT(
  //,-------------------------------------------.                    ,---------------------------------------------
     KC_EXLM, KC_DQUO, KC_LCBR, KC_RCBR, KC_PIPE,                      XXXXXXX,    KC_7,    KC_8,    KC_9, KC_PAST,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
     KC_NUHS,  KC_DLR, KC_LPRN, KC_RPRN,   SNUBS,                       KC_DOT,    KC_4,    KC_5,    KC_6, KC_PPLS,
  //|-------+--------+--------+--------+--------j                    |--------+--------+--------+--------+--------+
     KC_PERC, KC_HASH, KC_LBRC, KC_RBRC, KC_AMPR,                         KC_0,    KC_1,    KC_2,    KC_3, KC_PMNS,
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
                                          KC_TAB, XXXXXXX,    XXXXXXX, XXXXXXX
                                      //-----------------'  `------------------
  ),

  [2] = LAYOUT(
  //,-------------------------------------------.                    ,---------------------------------------------
     XXXXXXX, KC_QUOT, KC_MINS, KC_CIRC, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
     XXXXXXX,   KC_AT, KC_UNDS,  KC_EQL, XXXXXXX,                      XXXXXXX, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
                                         XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
                                      //-----------------'  `------------------
  ),

  [3] = LAYOUT(
  //,-------------------------------------------.                    ,---------------------------------------------
      KC_F12,  KC_F11,  KC_F10,   KC_F9, XXXXXXX,                      XXXXXXX, KC_WH_D, KC_WH_U, XXXXXXX,   MO(4),
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
       KC_F8,   KC_F7,   KC_F6,   KC_F5,   WVD_U,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
       KC_F4,   KC_F3,   KC_F2,   KC_F1,   WVD_D,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
                                         XXXXXXX, XXXXXXX,    KC_BTN1, KC_BTN2
                                      //-----------------'  `------------------
  ),
  [4] = LAYOUT(
  //,-------------------------------------------.                    ,---------------------------------------------
     QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
                                         XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
                                      //-----------------'  `------------------
  )
//   [3] = LAYOUT(
//   //,-------------------------------------------.                    ,---------------------------------------------
//      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
//      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
//      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
//                                          XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
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
