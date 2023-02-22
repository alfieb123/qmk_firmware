
        #include QMK_KEYBOARD_H
        #include "print.h"

        enum key_layers {
_BASE,
_1,
_2,
_3,
_4,
};

        #define TRNS KC_TRANSPARENT
        #define __ KC_NO
        #define C_ESC LCTL_T(KC_ESC)
        #define DWORD LCTL(KC_BSPC)
        #define SNUBS LSFT(KC_NUBS)
        #define ENT_1 LT(1, KC_ENT)
        #define SLN_3 LT(3, KC_SCLN)
        #define WVD_U LGUI(LCTL(KC_RGHT)) //windows virtual desktop up
        #define WVD_D LGUI(LCTL(KC_LEFT)) // windows virtual desktop down

        const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = 
{
    [_BASE] = LAYOUT(
        KC_TAB,  __,      KC_MINS, KC_UNDS, KC_AT,                              CW_TOGG, __,      __,      DWORD,   KC_BSPC,
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    SLN_3,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
        __,      __,      KC_EQL,  ENT_1,   KC_LSFT,                            KC_SPC,  MO(2),   KC_LSFT, KC_LCTL, KC_LALT,
                                            C_ESC,                              KC_LGUI                                    
    ),
    [_1] = LAYOUT(
        QK_BOOT, __,      __,      __,      __,                                 __,      __,      __,      __,      __,
        KC_F12,  KC_F11,  KC_F10,  KC_F9,   __,                                 __,      __,      __,      __,      __,
        KC_F8,   KC_F7,   KC_F6,   KC_F5,   WVD_U,                              __,      __,      __,      __,      __,
        KC_F4,   KC_F3,   KC_F2,   KC_F1,   WVD_D,                              __,      __,      __,      __,      __,
        __,      __,      __,      TRNS,    TRNS,                               TRNS,    TRNS,    __,      __,      __,
                                            TRNS,                               TRNS                                    
    ),
    [_2] = LAYOUT(
        KC_DQUO, KC_QUOT, KC_MINS, KC_UNDS, KC_CIRC,                            QK_BOOT, __,      __,      __,      KC_DEL,
        KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                            __,      KC_7,    KC_8,    KC_9,    KC_PAST,
        KC_NUHS, KC_DLR,  KC_LPRN, KC_RPRN, SNUBS,                              __,      KC_4,    KC_5,    KC_6,    KC_PPLS,
        KC_PERC, KC_HASH, KC_LBRC, KC_RBRC, KC_AMPR,                            __,      KC_1,    KC_2,    KC_3,    KC_PMNS,
        __,      __,      __,      TRNS,    TRNS,                               TRNS,    TRNS,    KC_0,    KC_DOT,  __,
                                            TRNS,                               TRNS                                    
    ),
    [_3] = LAYOUT(
        __,      __,      __,      __,      __,                                 __,      __,      __,      __,      __,
        KC_LEFT, KC_RGHT, KC_UP,   KC_DOWN, KC_TAB,                             KC_LALT, KC_BTN1, KC_BTN3, KC_BTN2, __,
        __,      KC_BTN1, KC_BTN3, KC_BTN2, KC_EQL,                             KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, __,
        KC_WH_L, KC_WH_R, KC_WH_U, KC_WH_D, __,                                 __,      __,      __,      __,      __,
        __,      __,      __,      TRNS,    TRNS,                               TRNS,    TRNS,    __,      __,      __,
                                            TRNS,                               TRNS                                    
    ),
    [_4] = LAYOUT(
        __,      __,      __,      __,      __,                                 __,      __,      __,      __,      __,
        __,      __,      __,      __,      __,                                 __,      __,      __,      __,      __,
        __,      __,      __,      __,      __,                                 __,      __,      __,      __,      __,
        __,      __,      __,      __,      __,                                 __,      __,      __,      __,      __,
        __,      __,      __,      __,      __,                                 __,      __,      __,      __,      __,
                                            __,                                 __                                    
    )
};

        