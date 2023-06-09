// Copyright 2021 Christoph Rehmann (crehmann)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german_ch.h"
#include "features/haptic_utils.h"

#ifdef PS2_MOUSE_ENABLE
    #include "ps2_mouse.h"
#endif

enum layers {
    _BASE = 0,
    _NAVR,
    _SYMB,
    _NUMR,
    _FUNL,
    _MOAJ
};


// Aliases for readability
#define BASE     DF(_BASE)
#define NAVR     MO(_NAVR)
#define SYMB     MO(_SYMB)
#define NUMR     MO(_NUMR)
#define FUNL     MO(_FUNL)
#define MOAD     MO(_MOAJ)

// Left-hand home row mods
#define RALT_X  RALT_T(KC_X)
#define GUI_A   LGUI_T(KC_A)
#define ALT_S   LALT_T(KC_S)
#define CTL_D   LCTL_T(KC_D)
#define SFT_F   LSFT_T(KC_F)

// Right-hand home row mods
#define SFT_J   RSFT_T(KC_J)
#define CTL_K   RCTL_T(KC_K)
#define ALT_L   LALT_T(KC_L)
#define GUI_SCL RGUI_T(KC_SCLN)
#define RALT_DT RALT_T(KC_DOT)

// Left-hand outer column
#define CTL_ESC  MT(MOD_LCTL, KC_ESC)

// Thumbcluster
#define UC_TL1 CTL_ESC
#define UC_TL2 LT(NAVR, KC_SPC)
#define UC_TL3 LT(NUMR, KC_TAB)

#define UC_TR3 LT(FUNL, KC_BSPC)
#define UC_TR2 LT(SYMB, KC_ENT)
#define UC_TR1 KC_DEL

// Shortcuts
#define UC_COPY LCTL(KC_C)
#define UC_PSTE LCTL(KC_V)
#define UC_CUT  LCTL(KC_X)
#define UC_MUTE SGUI(KC_M)
#define UC_OSFT OSM(MOD_LSFT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// /*
//  * Base Layer
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |   Q  |   W  |   E  |   R  |   T  |                                               |   Z  |   U  |   I  |   O  |   P  |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *          ,------+------+------+------+------+------|                                               |------+------+------+------+------+------.
//  *          | OSM  |   A  |   S  |   D  |   F  |   G  |                                               |   H  |   J  |   K  |   L  |  ; : | Bksp |
//  *          | Shift|  GUI | LALT | LCTL | LSFT |      |                                               |      | LSFT | LCTL | LALT |  GUI |      |
//  *          |------+------+------+------+------+------|                                               |------+------+------+------+------+------|
//  *          |  ESC |   Y  |   X  |   C  |   F  |   B  |                                               |   N  |   M  |  , < |  . > |  / ? | Mute |
//  *          |  CTL |      | RALT |      |      |      |                                               |      |      |      | RALT |      |  Mic |
//  *          `----------------------------------+------+-------------.                   ,-------------+------+----------------------------------'
//  *                                             |  ESC | Space| TAB  |                   |  Bksp| Enter|  Del |
//  *                                             |  CTL | NAVR | NUMR |                   |  FUNL| SYML |      |
//  *                                             `--------------------'                   `--------------------'
//  */
    [_BASE] = LAYOUT(
               KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                        CH_Z   , KC_U   , KC_I   , KC_O   , KC_P   ,
      UC_OSFT, GUI_A  , ALT_S  , CTL_D  , SFT_F  , KC_G   ,                                        KC_H   , SFT_J  , CTL_K  , ALT_L  , GUI_SCL, KC_BSPC,
      CTL_ESC, CH_Y   , RALT_X , KC_C   , KC_V   , KC_B   ,                                        KC_N   , KC_M   , KC_COMM, RALT_DT, KC_SLSH, UC_MUTE,
                                                   UC_TL1 , UC_TL2 , UC_TL3 ,    UC_TR3 , UC_TR2 , UC_TR1
    ),

// /*
//  * Symbol Layer
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |   `  |   @  |   {  |   }  |   $  |                                               |   ¨  |   ü  |   /  |   \  |   ^  |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *          ,------+------+------+------+------+------|                                               |------+------+------+------+------+------.
//  *          |      |   ä  |   &  |   (  |   )  |   |  |                                               |   '  |   "  |   ?  |   !  |   +  |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |------+------+------+------+------+------|                                               |------+------+------+------+------+------|
//  *          |      |   %  |   #  |   [  |   ]  |   ~  |                                               |   €  |   =  |   *  |   <  |   >  |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          `----------------------------------+------+-------------.                   ,-------------+------+----------------------------------'
//  *                                             |      |      | TAB  |                   |      |      |      |
//  *                                             |      |      |      |                   |      |      |      |
//  *                                             `--------------------'                   `--------------------'
//  */
    [_SYMB] = LAYOUT(
               CH_GRV , CH_AT  , CH_LCBR, CH_RCBR, CH_DLR ,                                       CH_DIAE, CH_UDIA, CH_SLSH, CH_BSLS, KC_CIRC,
      _______, CH_ADIA, CH_AMPR, CH_LPRN, CH_RPRN, CH_PIPE,                                       CH_QUOT, CH_DQUO, CH_QUES, CH_EXLM, CH_PLUS, _______,
      _______, CH_PERC, CH_HASH, CH_LBRC, CH_RBRC, CH_TILD,                                       CH_EURO, CH_EQL , CH_ASTR, CH_LABK, CH_RABK, _______,
                                                   _______, _______, KC_TAB,    _______, _______ , _______ 
    ),

// /*
//  * Navigation Layer (Right)
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |      |      |      |      |      |                                               |Insert| Cut  | PgUp | PgDn |      |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *          ,------+------+------+------+------+------|                                               |------+------+------+------+------+------.
//  *          |      |      |      |      |      |      |                                               | Copy |   ←  |   ↑  |   ↓  |   →  |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |------+------+------+------+------+------|                                               |------+------+------+------+------+------|
//  *          |      |      |      |      |      |      |                                               | Paste| Home | WH_U | WH_D | End  |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          `----------------------------------+------+-------------.                   ,-------------+------+----------------------------------'
//  *                                             |      |      |      |                   | Bksp |      |  Del |
//  *                                             |      |      |      |                   |      |      |      |
//  *                                             `--------------------'                   `--------------------'
//  */
    [_NAVR] = LAYOUT(
               _______, _______, _______, _______, _______,                                        KC_INS , UC_CUT , KC_PGUP, KC_PGDN, _______,
      _______, _______, _______, _______, _______, _______,                                        UC_COPY, KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT, _______,
      _______, _______, _______, _______, _______, _______,                                        UC_PSTE, KC_HOME, KC_WH_U, KC_WH_D, KC_END , _______,
                                                   _______, _______, _______,    KC_BSPC, _______, _______
    ),
// --------------------------------------------------------------------------------------------------------------------------------------------------------

// /*
//  * Number Layer (Right)
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |      |      |      |      |      |                                               |   /  |   7  |   8  |   9  |  -   |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *          ,------+------+------+------+------+------|                                               |------+------+------+------+------+------.
//  *          |      |      |      |      |      |      |                                               |   *  |   4  |   5  |  6   |  +   |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |------+------+------+------+------+------|                                               |------+------+------+------+------+------|
//  *          |      |      |      |      |      |      |                                               |   0  |   1  |   2  |  3   |  .   |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          `----------------------------------+------+-------------.                   ,-------------+------+----------------------------------'
//  *                                             |      |      |      |                   | Bksp | Enter|      |
//  *                                             |      |      |      |                   |      |      |      |
//  *                                             `--------------------'                   `--------------------'
//  */
    [_NUMR] = LAYOUT(
               _______, _______, _______, _______, _______,                                        KC_SLSH, KC_7   , KC_8   , KC_9   , KC_MINS,
      _______, _______, _______, _______, _______, _______,                                        KC_ASTR, KC_4   , KC_5   , KC_6   , KC_PLUS, _______,
      _______, _______, _______, _______, _______, _______,                                        KC_0   , KC_1   , KC_2   , KC_3   , KC_DOT , _______,
                                                   _______, _______, _______,    KC_BSPC, KC_ENT , _______ 
    ),

// /*
//  * Function Layer (Left)
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |  F12 |  F7  |  F8  |  F9  | Pause|                                               |      |      |      |      |      |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *          ,------+------+------+------+------+------|                                               |------+------+------+------+------+------.
//  *          |      |  F11 |  F4  |  F5  |  F6  | PrScr|                                               |      |      |      |      |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |------+------+------+------+------+------|                                               |------+------+------+------+------+------|
//  *          |      |  F10 |  F1  |  F2  |  F3  | CapsL|                                               |      |      |      |      |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          `----------------------------------+------+-------------.                   ,-------------+------+----------------------------------'
//  *                                             |      | Space|  TAB |                   |      |      |      |
//  *                                             |      |      |      |                   |      |      |      |
//  *                                             `--------------------'                   `--------------------'
//  */
    [_FUNL] = LAYOUT(
               KC_F12 , KC_F7  , KC_F8  , KC_F9  , KC_PAUS,                                        _______, _______, _______, _______, _______,
      _______, KC_F11 , KC_F4  , KC_F5  , KC_F6  , KC_PSCR,                                        _______, _______, _______, _______, _______, _______,
      _______, KC_F10 , KC_F1  , KC_F2  , KC_F3  , KC_CAPS,                                        _______, _______, _______, _______, _______, _______,
                                                   _______, KC_SPC , KC_TAB  ,    _______, _______, _______
    ),
  
// /*
//  * Mouse & Adjustment Layer
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *          ,------+------+------+------+------+------|                                               |------+------+------+------+------+------.
//  *          |      |      | BTN3 | BTN2 | BTN1 |      |                                               |      |      |      |      |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |------+------+------+------+------+------|                                               |------+------+------+------+------+------|
//  *          |      |      |  Cut | Copy | Paste|      |                                               | Play |M Prev| VolDn| VolUp|M Next|      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          `----------------------------------+------+-------------.                   ,-------------+------+----------------------------------'
//  *                                             |      |      |      |                   |      |      |      |
//  *                                             |      |      |      |                   |      |      |      |
//  *                                             `--------------------'                   `--------------------'
//  */
    [_MOAJ] = LAYOUT(
               _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______,
      _______, _______, KC_BTN3, KC_BTN2, KC_BTN1, _______,                                        _______, _______, _______, _______, _______, _______,
      _______, _______, UC_CUT , UC_COPY, UC_PSTE, _______,                                        KC_MPLY, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
                                                   _______, _______, _______,    _______, _______, _______
    ),

// -------------------------------------------------------- TEMPLATE -------------------------------------------------------------------------------------
// /*
//  * Layer
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *          ,------+------+------+------+------+------|                                               |------+------+------+------+------+------.
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |------+------+------+------+------+------|                                               |------+------+------+------+------+------|
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          `----------------------------------+------+-------------.                   ,-------------+------+----------------------------------'
//  *                                             |      |      |      |                   |      |      |      |
//  *                                             |      |      |      |                   |      |      |      |
//  *                                             `--------------------'                   `--------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//                _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,
//                                                    _______, _______, _______,    _______, _______, _______
//     ),
// --------------------------------------------------------------------------------------------------------------------------------------------------------
};

layer_state_t layer_state_set_user(layer_state_t state) {
    process_layer_pulse(state);
    return update_tri_layer_state(state, _NAVR, _SYMB, _MOAJ);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_A:
            return TAPPING_TERM + 150;
        case ALT_S:
            return TAPPING_TERM + 50;
        case ALT_L:
            return TAPPING_TERM + 50;
        case GUI_SCL:
            return TAPPING_TERM + 150;
        default:
            return TAPPING_TERM;
    }
}
