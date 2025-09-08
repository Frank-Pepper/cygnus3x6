// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define MOUSE TG(_MOUSE)
#define NAV TG(_NAV)

#define ALTBSPC LALT_T(KC_BSPC)
#define LENTR LT(_NUMS, KC_ENT)
#define RALENTR RALT_T(KC_ENT)

#define KC_COPY C(KC_C)
#define KC_PASTE C(KC_V)
#define KC_UNDO C(KC_Z)
#define KC_CUT C(KC_X)

enum custom_layers {
    _BASE,
    _NUMS,
    _NAV,
    _MOUSE,
    _FUNC,
};

const uint16_t PROGMEM cut[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM copy[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM paste[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM toggle_nav_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM toggle_mouse_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[] = {
    COMBO(cut, KC_CUT),
    COMBO(copy, KC_COPY),
    COMBO(paste, KC_PASTE),
    COMBO(kl_combo, KC_ESC),
    COMBO(toggle_nav_combo, NAV),
    COMBO(toggle_mouse_combo, MOUSE), // keycodes with modifiers are possible too!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        SC_LSPO,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, SC_RSPC,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|  
                                            ALTBSPC, KC_LGUI,   LENTR,     KC_SPC, RALENTR,  KC_RALT
                                        //`--------------------------'  `--------------------------'

    ),
    [_NUMS] = LAYOUT_split_3x6_3( \
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_GRV, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_VOLU,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_VOLD,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, KC_TILD, KC_MINS, KC_UNDS, KC_LBRC, KC_LCBR,                      KC_RCBR, KC_RBRC, KC_PLUS, KC_EQL,  KC_PIPE, KC_BSLS,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_LGUI,  KC_DOT
                                        //`--------------------------'  `--------------------------'
    ),
    [_NAV] = LAYOUT_split_3x6_3( \
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, KC_VOLU,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, KC_VOLD,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      XXXXXXX, KC_COPY, KC_PASTE, KC_CUT, KC_UNDO, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LGUI,  KC_TAB,     NAV,    MS_BTN1, MS_BTN3, MS_BTN2
                                        //`--------------------------'  `--------------------------'
    ),
      [_MOUSE] = LAYOUT_split_3x6_3( \
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, CG_LSWP, CG_LNRM, QK_BOOT,                      XXXXXXX, MS_BTN1, MS_WHLU, MS_BTN2, XXXXXXX, KC_VOLU,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      MS_WHLL, MS_LEFT, MS_UP,   MS_DOWN, MS_RGHT, KC_VOLD,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, MS_BTN4, MS_WHLD, MS_BTN5, MS_WHLR, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_TRNS,  KC_TAB,   MOUSE,    MS_BTN1, MS_BTN3, MS_BTN2
                                        //`--------------------------'  `--------------------------'
    ),
};
