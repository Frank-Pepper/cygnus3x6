// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define MOUSE TG(_MOUSE)
#define NAV TG(_NAV)

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
const uint16_t PROGMEM toggle_nav_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM toggle_mouse_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[] = {
    COMBO(cut, KC_CUT),
    COMBO(copy, KC_COPY),
    COMBO(paste, KC_PASTE),
    COMBO(toggle_nav_combo, NAV),
    COMBO(toggle_mouse_combo, MOUSE), // keycodes with modifiers are possible too!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Alt│
      *               └───┤Bsp├───┐   ┌───┤Ent├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [_BASE] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        SC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, SC_RSPC,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|  
                                            KC_BSPC, KC_LGUI,   MO(1),     KC_SPC,  KC_ENT,  KC_RALT
                                        //`--------------------------'  `--------------------------'

    ),
    [_NUMS] = LAYOUT_split_3x6_3( \
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_VOLU,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_VOLD,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, KC_TILD, KC_GRV,  KC_LBRC, KC_LCBR,                      KC_RCBR, KC_RBRC, KC_COMM, KC_DOT,  KC_SLSH, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_LGUI, KC_COLON
                                        //`--------------------------'  `--------------------------'
    ),
    [_NAV] = LAYOUT_split_3x6_3( \
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, KC_VOLU,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      XXXXXXX, KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, KC_VOLD,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      XXXXXXX, KC_COPY, KC_PASTE, KC_CUT, KC_UNDO, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LGUI,  KC_TAB,     NAV,    MS_BTN1, MS_BTN2, MS_BTN3
                                        //`--------------------------'  `--------------------------'
    ),
      [_MOUSE] = LAYOUT_split_3x6_3( \
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, MS_BTN1, MS_WHLU, MS_BTN2, XXXXXXX, KC_VOLU,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      XXXXXXX, MS_LEFT, MS_UP,   MS_DOWN, MS_RGHT, KC_VOLD,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, MS_WHLL, MS_WHLD, MS_WHLR, KC_SLSH, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_TRNS,  KC_TAB,   MOUSE,    MS_BTN1, MS_BTN2, MS_BTN3
                                        //`--------------------------'  `--------------------------'
    ),
};
