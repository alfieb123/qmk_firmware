#include QMK_KEYBOARD_H

#define ALT_KCS LALT_T(KC_S)
#define ALTRKCX RALT_T(KC_X)
#define CTL_KCD LCTL_T(KC_D)
#define SFT_KCF LSFT_T(KC_F)
#define GUI_KCG LGUI_T(KC_G)
#define GUI_SCN LGUI_T(KC_SCLN)
#define CTL_KCK LCTL_T(KC_K)
#define SFT_KCJ RSFT_T(KC_J)
#define GUI_KCH LGUI_T(KC_H)
#define ALT_KCL LALT_T(KC_L)
#define ALTRDOT RALT_T(KC_DOT)
#define ALT__F7 LALT_T(KC_F7)
#define CTL__F6 LCTL_T(KC_F6)
#define SFT__F5 LSFT_T(KC_F5)
#define LT1_ENT LT(1, KC_ENT)
#define LT2_ESC LT(2, KC_ESC)
#define LT2_SPC LT(2, KC_SPC)
#define LT3_KCR LT(3, KC_R)
#define LT3_KCM LT(3, KC_M)
#define LT4_KCT LT(4, KC_T)
#define MVD_NXT LCTL(KC_RGHT)
#define MVD_PRV LCTL(KC_LEFT)
#define MAC_HSH LALT(KC_3)
#define CMD_GRV LGUI(KC_GRV)
#define GUI_DOT LGUI_T(KC_DOT)
#define ALT_NU6 LALT_T(KC_6)
#define CTL_NU5 LCTL_T(KC_5)
#define SFT_NU4 LCTL_T(KC_4)
#define GUI__F8 LGUI_T(KC_F8)

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
        case CPP_PTR: if (record->event.pressed) SEND_STRING("->"); return false;
        case RBR_D:   if (record->event.pressed) SEND_STRING("]d"); return false;
        case LBR_D:   if (record->event.pressed) SEND_STRING("[d"); return false;
        case RBR_F:   if (record->event.pressed) SEND_STRING("]f"); return false;
        case LBR_F:   if (record->event.pressed) SEND_STRING("[f"); return false;
        case RBR_T:   if (record->event.pressed) SEND_STRING("]t"); return false;
        case LBR_T:   if (record->event.pressed) SEND_STRING("[t"); return false;
        case RBR_P:   if (record->event.pressed) SEND_STRING("]p"); return false;
        case LBR_P:   if (record->event.pressed) SEND_STRING("[p"); return false;
        case XTHENV:  if (record->event.pressed) SEND_STRING("xv"); return false;
        case LT1_UND:
            if (record->event.pressed) {
                key_timer = timer_read();
                layer_on(1);
            } else {
                if (timer_elapsed(key_timer) < TAPPING_TERM) tap_code16(KC_UNDS);
                layer_off(1);
            }
            return false;
        default:
            return true;
    }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_SPC:
            return true;
        default:
            return false;
    }
}

const uint16_t PROGMEM c_bspc[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM c_tab[]  = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM c_mins[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM c_eql[]  = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM c_dquo[] = {KC_I, KC_O, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(c_bspc, KC_BSPC),
    COMBO(c_tab, KC_TAB),
    COMBO(c_mins, KC_MINS),
    COMBO(c_eql, KC_EQL),
    COMBO(c_dquo, KC_DQUO),
};

// keymaps[] follows (omitted here for brevity)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_TAB,    KC_Q,    KC_W,    KC_E, LT3_KCR,  LT4_KCT,                         KC_Y,   KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______,   KC_A,  ALT_KCS, CTL_KCD, SFT_KCF, GUI_KCG,                      GUI_KCH, SFT_KCJ, CTL_KCK, ALT_KCL, KC_SCLN, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______,   KC_Z,  ALTRKCX,    KC_C,    KC_V,    KC_B,                         KC_N, LT3_KCM,  KC_COMM,ALTRDOT, KC_SLSH, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               LT1_ENT,  LT2_ESC, _______,    _______, LT2_SPC, LT1_UND
                                            //`--------------------------'  `--------------------------'

        ),
    [1] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______, KC_EXLM,   KC_AT, KC_LCBR, KC_RCBR,KC_TILDE,                      CPP_PTR, KC_CIRC, KC_MINS, KC_QUOT, CMD_GRV, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, MAC_HSH,  KC_DLR, KC_LPRN, KC_RPRN, KC_PIPE,                       KC_GRV,  KC_EQL, KC_UNDS, KC_DQUO,  KC_INS, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_PERC, KC_HASH, KC_LBRC, KC_RBRC, KC_AMPR,                      _______, KC_BSLS, KC_HOME,  KC_END, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______, KC_LBRC, _______,    _______, KC_RBRC, CMD_GRV
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
                                                _______, _______, _______,    _______, CW_TOGG,   KC_DEL
                                            //`--------------------------'  `--------------------------'

        ),
    [3] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______, _______,   LBR_T,   LBR_D,   LBR_P,   LBR_F,                      _______, KC_PGDN, KC_PGUP, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______,  XTHENV,   RBR_T,   RBR_D,   RBR_P,   RBR_F,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______,                      _______, _______,  XTHENV, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______, _______, _______,    _______, _______, _______
                                            //`--------------------------'  `--------------------------'

        ),
    [4] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______, _______, _______, _______, _______, _______,                       KC_TAB, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            QK_BOOT, QK_BOOT, _______, _______, _______, _______,                      _______, KC_WH_D, KC_WH_U, _______, _______, _______,
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
