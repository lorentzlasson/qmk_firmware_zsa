// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Layers
enum layers {
    _QWERTY = 0,
    _SYM,
    _SYS,
    _F,
    _GAME,
    _GAME_SYM
};

// all modifiers should be modtap!
#define KC_MYENT  MT(MOD_LALT, KC_ENT)
#define KC_MYSYM  LT(_SYM, KC_TAB)
#define KC_MYSPC  MT(MOD_LCTL, KC_SPC)
#define KC_MYBSPC MT(MOD_LCTL, KC_BSPC)
#define KC_MYALT  MT(MOD_LALT, KC_TAB)
#define KC_MYCAPS LT(_F, KC_CAPS)
#define KC_TMUX   LCTL(KC_SPC)
#define KC_MYTAB  LT(_SYS, KC_TAB)
#define KC_GAME   TG(_GAME)
#define KC_GSYM   MO(_GAME_SYM)

// Fillers to make layering more clear
#define ___x___ KC_NO

#define KC_AU ALGR(KC_W) // å
#define KC_AE ALGR(KC_Q) // ä
#define KC_OE ALGR(KC_P) // ö

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_TMUX, KC_LGUI, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_LGUI, KC_TMUX,
        KC_MYTAB, KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,            KC_Y,  KC_U,  KC_I,      KC_O,    KC_P,      KC_AU,
        KC_MYCAPS,KC_A,  KC_S,  KC_D,  KC_F,  KC_G,            KC_H,  KC_J,  KC_K,      KC_L,    KC_OE,     KC_AE,
        KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,            KC_N,  KC_M,  KC_COMMA,  KC_DOT,  KC_SLASH,  KC_RSFT,
                                    KC_MYSYM,KC_MYBSPC,      KC_MYSPC, KC_MYENT
    ),

    [_SYM] = LAYOUT(
        ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,
        KC_GRAVE, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_AMPR,            KC_ASTR, KC_7, KC_8, KC_9, KC_PLUS, KC_EQL,
        KC_TILD,  KC_CIRC, KC_DLR,  KC_LPRN, KC_RPRN, KC_QUOT,            KC_SCLN, KC_4, KC_5, KC_6, KC_MINS, KC_UNDS,
        KC_PIPE,  KC_HASH, KC_PERC, KC_LBRC, KC_RBRC, KC_DQUO,            KC_COLN, KC_1, KC_2, KC_3, KC_BSLS, KC_DELETE,
                                            ___x___, ___x___,        ___x___, KC_0

    ),

    [_SYS] = LAYOUT(
        ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,
        ___x___,    ___x___,    KC_MUTE,    KC_VOLD,    KC_VOLU,    ___x___,                   KC_CALC,    ___x___,    ___x___,    ___x___,    KC_MCTL,   KC_KB_POWER,
        ___x___,    ___x___,    KC_MPLY,    KC_MPRV,    KC_MNXT,    ___x___,                   KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    ___x___,   KC_SLEP,
        ___x___,    ___x___,    ___x___,    ___x___,    ___x___,    ___x___,                   ___x___,    ___x___,    ___x___,    ___x___,    ___x___,   KC_PSCR,
                                                     _______, _______,    _______, _______
    ),

    [_F] = LAYOUT(
        ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,
        ___x___,    ___x___,    ___x___,    ___x___,    ___x___,    ___x___,                   ___x___,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   ___x___,
        ___x___,    ___x___,    ___x___,    ___x___,    ___x___,    ___x___,                   ___x___,    KC_F4,    KC_F5,    KC_F6,    KC_F11,   ___x___,
        ___x___,    ___x___,    ___x___,    ___x___,    ___x___,    ___x___,                   ___x___,    KC_F1,    KC_F2,    KC_F3,    KC_F12,   ___x___,
                                                     _______, _______,    _______, _______
    )
};

const uint16_t PROGMEM bootload_combo[] = {KC_Y, KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM lalt_combo[] = {KC_A, KC_W, KC_D, COMBO_END};
combo_t key_combos[] = {
    COMBO(bootload_combo, QK_BOOT),
    COMBO(lalt_combo, KC_LALT),
};
