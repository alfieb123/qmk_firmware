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
// const uint16_t PROGMEM c_bspc[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM c_bspc[] = {KC_O, KC_P, COMBO_END};
// const uint16_t PROGMEM c_del[] = {KC_COMM, KC_DOT, COMBO_END};
// const uint16_t PROGMEM c_delwrd[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM c_tab[] = {KC_Q, KC_W, COMBO_END};
// const uint16_t PROGMEM c_unds[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM c_mins[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM c_eql[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM c_dquo[] = {KC_I, KC_O, COMBO_END};
// const uint16_t PROGMEM c_mo3[] = {KC_A, KC_S, COMBO_END};
// const uint16_t PROGMEM c_lgui[] = {KC_R, KC_T, COMBO_END};
// const uint16_t PROGMEM c_lgui2[] = {KC_Y, KC_U, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
   //  COMBO(c_esc, KC_ESC), //escape
   //  COMBO(c_ent, KC_ENT), //enter
    COMBO(c_bspc, KC_BSPC), // backspace
    // COMBO(c_del, KC_DEL), //delete
   //  COMBO(c_delwrd, LCTL(KC_BSPC)), //delete word
    COMBO(c_tab, KC_TAB), // tab
    // COMBO(c_unds, KC_UNDS), //underscore
    COMBO(c_mins, KC_MINS), //minus
    COMBO(c_eql, KC_EQL), //equal 
    //COMBO(c_dquo, KC_AT), // this is a double quote ". notice we are using kc_at which is noramlly the at symbol but not on uk for some reason. ONLY windows and linux!
    COMBO(c_dquo, KC_DQUO),
   //  COMBO(c_mo3, MO(3)), // layer toggle to layer
   //  COMBO(c_lgui, KC_LGUI), // Os key
   //  COMBO(c_lgui2, KC_LGUI), // Os key
    // COMBO(combo2, LCTL(KC_Z)), // keycodes with modifiers are possible too!
};


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
#define ALTRKCX RALT_T(KC_X)
#define CTL_KCD LCTL_T(KC_D)
#define SFT_KCF LSFT_T(KC_F)
#define GUI_KCG LGUI_T(KC_G)

#define GUI_SCN LGUI_T(KC_SCLN)
#define ALT_KCL LALT_T(KC_L)
#define ALTRDOT RALT_T(KC_DOT)
#define CTL_KCK LCTL_T(KC_K)
#define SFT_KCJ RSFT_T(KC_J)
#define GUI_KCH LGUI_T(KC_H)

#define ALT__AT LALT_T(KC_AT)


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
#define LT3_KCR LT(3, KC_R)
#define LT3_KCM LT(3, KC_M)
#define LT4_KCT LT(4, KC_T)

// mac virtual desktops

#define MVD_NXT LCTL(KC_RGHT)
#define MVD_PRV LCTL(KC_LEFT)

// define the mac version of has which is alt+3... wierdly
#define MAC_HSH LALT(KC_3)

// to switch between windows of the same app in mac, its cmd + `
#define CMD_GRV LGUI(KC_GRV)

// windows virtual desktops
#define WVD_NXT LGUI(LCTL(KC_RGHT))
#define WVD_PRV LGUI(LCTL(KC_LEFT))
// #define WNCLOSE LALT(KC_F4)

// lgui lalt lsft, this has been put here specificlly for the the windows store app
// 'Virtual Desktrop Indictor', that has number based switching desktops with win alt shift num,
// and switching windows to numbered virtual desktop with win alt shift Fnum (so, F2 instead of 2)
//#define GAS LGUI(LALT(KC_LSFT))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
  //,-------------------------------------------.                    ,---------------------------------------------
        KC_Q,    KC_W,    KC_E, LT3_KCR, LT4_KCT,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
        KC_A, ALT_KCS, CTL_KCD, SFT_KCF, GUI_KCG,                      GUI_KCH, SFT_KCJ, CTL_KCK, ALT_KCL, KC_SCLN,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
        KC_Z, ALTRKCX,    KC_C,    KC_V,    KC_B,                         KC_N, LT3_KCM, KC_COMM, ALTRDOT, KC_SLSH,
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
                                         LT1_ENT, LT2_ESC,    LT2_SPC,  LT1_UND
                                      //-----------------'  `------------------
  ),

// mac: ______
  [1] = LAYOUT(
  //,-------------------------------------------.                    ,---------------------------------------------
     KC_EXLM,   KC_AT, KC_LCBR, KC_RCBR,KC_TILDE,                      CPP_PTR, KC_CIRC, KC_MINS, KC_QUOT, CMD_GRV,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
     MAC_HSH,  KC_DLR, KC_LPRN, KC_RPRN, KC_PIPE,                      KC_LGUI,  KC_EQL, KC_UNDS, KC_DQUO, KC_INS,
  //|-------+--------+--------+--------+--------j                    |--------+--------+--------+--------+--------+
     KC_PERC, KC_HASH, KC_LBRC, KC_RBRC, KC_AMPR,                       KC_GRV, KC_BSLS, KC_HOME,  KC_END, _______,
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
                                         _______, KC_LBRC,    KC_RBRC,  CMD_GRV
                                      //-----------------'  `------------------
  ),

  [2] = LAYOUT(
  //,-------------------------------------------.                    ,---------------------------------------------
      KC_F12,  KC_F11,  KC_F10,   KC_F9, MVD_NXT,                       KC_EQL,    KC_7,    KC_8,    KC_9, KC_PAST,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
       KC_F8, ALT__F7, CTL__F6, SFT__F5, KC_LGUI,                      GUI_DOT, SFT_NU4, CTL_NU5, ALT_NU6, KC_PPLS,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
       KC_F4,   KC_F3,   KC_F2,   KC_F1, MVD_PRV,                         KC_0,    KC_1,    KC_2,    KC_3, KC_PMNS,
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
                                         _______, _______,    CW_TOGG,   KC_DEL
                                      //-----------------'  `------------------
  ),

  [3] = LAYOUT(
  //,-------------------------------------------.                    ,---------------------------------------------
     _______,   LBR_T,   LBR_D,   LBR_P,   LBR_F,                      _______, KC_PGDN, KC_PGUP, _______, _______,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
     _______,   RBR_T,   RBR_D,   RBR_P,   RBR_F,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
     _______,  XTHENV, _______, _______, _______,                      _______, _______,  XTHENV, _______, _______,
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
                                           KC_UP, KC_DOWN,    _______, _______
                                      //-----------------'  `------------------
  ),

  [4] = LAYOUT(
  //,-------------------------------------------.                    ,---------------------------------------------
     _______, _______, _______, _______, _______,                       KC_TAB, KC_BTN1, KC_BTN3, KC_BTN2, _______,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
     _______, _______, _______, _______, _______,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
     QK_BOOT, _______, _______, _______, _______,                      _______, KC_WH_D, KC_WH_U, _______, _______,
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
                                         _______, KC_BTN3,    KC_BTN1, KC_BTN2
                                      //-----------------'  `------------------
  ),

// // linux and pc:
//   [1] = LAYOUT(
//   //,-------------------------------------------.                    ,---------------------------------------------
//      KC_EXLM, KC_DQUO, KC_LCBR, KC_RCBR, KC_PIPE,                      _______, KC_CIRC, KC_MINS, KC_QUOT, _______,
   
//   //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
//      KC_NUHS,  KC_DLR, KC_LPRN, KC_RPRN,   SNUBS,                      _______,  KC_EQL, KC_UNDS,   KC_AT, KC_LGUI,
//   //|-------+--------+--------+--------+--------j                    |--------+--------+--------+--------+--------+
//      KC_PERC, KC_HASH, KC_LBRC, KC_RBRC, KC_AMPR,                      _______, KC_NUBS, _______, _______, _______,
//   //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
//                                          WNCLOSE, _______,    _______,  _______
//                                       //-----------------'  `------------------
//   ),


  //  // caps layout
  // [5] = LAYOUT(
  // //,-------------------------------------------.                    ,---------------------------------------------
  //       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
  // //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
  //       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
  // //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+
  //       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  // //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+
  //                                         KC_ENT,  KC_ESC,     KC_SPC,  KC_BSPC
  //                                     //-----------------'  `------------------
  // )

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
//                                  _N,   KC_CLGV, KC_BSM1, KC_SPM2, KC_GUTA
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
//     KC_TRNS_N,, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_UNDS, KC_PLUS, KC_TRNS, KC_TRNS, QK_BOOT,
//                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
//   )
// };

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};
