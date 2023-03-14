/* Copyright 2022 Nathan Olivares
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

#include "keymap_steno.h"
#include QMK_KEYBOARD_H

enum layers{
	STENO,
	QWERTY,
	GAMING,
	NKRO,
	MODS,
	SYMBOL
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[STENO] = LAYOUT(
		KC_ESC,			KC_F1,		KC_F2,		KC_F11,		KC_F12,		KC_LALT,			STN_N6,		KC_LEFT,	KC_DOWN,	KC_UP,		KC_RIGHT,	STN_FN,				
		TO(QWERTY),		STN_S1,		STN_TL,		STN_PL,		STN_HL,		STN_ST1,			STN_ST3,	STN_FR,		STN_PR,		STN_LR,		STN_TR,		STN_DR,
		MO(SYMBOL),		STN_S2,		STN_KL,		STN_WL,		STN_RL,		STN_ST2,			STN_ST4,	STN_RR,		STN_BR,		STN_GR,		STN_SR,		STN_ZR,
												MO(MODS),	STN_A,		STN_O,				STN_E,		STN_U,		STN_NC
	),

	[QWERTY] = LAYOUT(
		KC_ESC,			KC_Q,		KC_W,		KC_E,		KC_R,	 	KC_T,				KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,			KC_BSPC,
		TO(STENO),		KC_A,		KC_S,		KC_D,		KC_F,	 	KC_G,				KC_H,		KC_J,		KC_K,		KC_L,		KC_SCLN,		KC_QUOT,
		MO(SYMBOL),		KC_Z,		KC_X,		KC_C,		KC_V,	 	KC_B,				KC_N,		KC_M,		KC_COMM,	KC_DOT, 	KC_SLASH,		KC_RSHIFT,
												KC_LCTL,	KC_LSHIFT,	KC_LALT,			KC_ENTER,	KC_SPACE,	KC_LWIN
	),

	[GAMING] = LAYOUT(
		KC_ESC,			KC_Q,		KC_W,		KC_E,		KC_R,	 	KC_T,				KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,			KC_BSPC,
		TO(STENO),		KC_A,		KC_S,		KC_D,		KC_F,	 	KC_G,				KC_H,		KC_J,		KC_K,		KC_L,		KC_SCLN,		KC_QUOT,
		KC_LSHIFT,		KC_Z,		KC_X,		KC_C,		KC_V,	 	KC_B,				KC_N,		KC_M,		KC_COMM,	KC_DOT, 	KC_SLASH,		KC_RSHIFT,
												KC_SPACE,	KC_LCTL,	MO(MODS),			KC_ENTER,	KC_SPACE,	KC_LWIN
	),

/*	[GAMING] = LAYOUT(
		KC_ESC,			KC_LALT,	KC_Q,		KC_W,		KC_E,		KC_R,				KC_T,		KC_Y,		KC_U,		KC_I,		KC_O,			KC_P,
		TO(STENO),		KC_LCTL,	KC_A,		KC_S,		KC_D,		KC_F,				KC_G,		KC_H,		KC_J,		KC_K,		KC_L,			KC_QUOT,
		MO(SYMBOL),		KC_LSHIFT,	KC_X,		KC_C,		KC_V,		KC_B,				KC_N,		KC_M,		KC_COMM,	KC_DOT,		KC_SLASH,		KC_RSHIFT,
												KC_Z,		KC_SPACE,	KC_LCTL,			KC_LALT,	KC_SPACE,	KC_ESC
	),
*/
	[NKRO] = LAYOUT(
		KC_GRAVE,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,				KC_6,		KC_7,		KC_8,		KC_9,		KC_0,			KC_MINS,
		TO(STENO),		KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,				KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,			KC_LBRC,
		MO(SYMBOL),		KC_A,		KC_S,		KC_D,		KC_F,		KC_G,				KC_H,		KC_J,		KC_K,		KC_L,		KC_SCLN,		KC_QUOT,
												KC_X,		KC_C,		KC_V,				KC_N,		KC_M,		KC_M
	),

	[MODS] = LAYOUT(
		KC_TAB,			KC_1,		KC_2,		KC_3,		KC_4,		KC_5,				KC_6,		KC_7,		KC_8,		KC_9,		KC_0,			KC_NO,
		TO(GAMING),		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,				KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,			KC_NO,		
		TO(NKRO),		KC_LCTL,	KC_LSHIFT,	KC_LALT,	KC_LWIN,	KC_NO,				KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,			KC_NO,	
												KC_NO,		KC_DEL,		KC_BSPC,			KC_NO,		KC_NO,		KC_NO
	),

	[SYMBOL] = LAYOUT(
		KC_TAB,			KC_1,		KC_2,		KC_3,		KC_4,		KC_5,				KC_6,		KC_7,		KC_8,		KC_9,		KC_0,			KC_DEL,
		_______,		KC_EXLM,	KC_AT,		KC_LT,		KC_GT,		KC_BSLASH,			KC_DQT,		KC_PLUS,	KC_MINS,	KC_SLASH,	KC_ASTR,		KC_TAB,	
		_______,		KC_PERC,	KC_CIRC,	KC_LBRC,	KC_RBRC,	KC_GRAVE,			KC_MINS,	KC_AMPR,	KC_EQUAL,	KC_COMM,	KC_DOT,			KC_RSHIFT,
												KC_LCTL,	KC_LSHIFT,	KC_LALT,			KC_ENTER,	KC_SPACE,	KC_ESC
	)
};

void matrix_init_user(void) {
	steno_set_mode(STENO_MODE_GEMINI);
};

void LED(int redState, int greenState) {
	if (redState == 0) {
		palClearPad(GPIOA, 0);
	}
	else {
		palSetPad(GPIOA, 0);
	}

	if (greenState == 0) {
		palClearPad(GPIOA, 1);
	}
	else {
		palSetPad(GPIOA, 1);
	}
};

layer_state_t layer_state_set_user(layer_state_t state) {
	// Or uint8_t layer = get_highest_layer(state);
	switch (get_highest_layer(state)) {

	case (STENO):
		LED(0, 1);
		break;

	case (QWERTY):
		combo_enable();
		LED(1, 0);
		break;

	case (GAMING): 
		combo_disable();
		LED(0, 0);
		break;

	case (NKRO):
		combo_disable();
		LED(1, 1);
		break; 

	default:
		break;

	}

return state;
}
