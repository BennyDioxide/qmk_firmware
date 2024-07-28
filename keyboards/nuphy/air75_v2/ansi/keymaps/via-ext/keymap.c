/*
Copyright 2023 @ Nuphy <https://nuphy.com/>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define KC_EXT (LT(6, KC_CAPS))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// layer Mac
[0] = LAYOUT_ansi_84(
	KC_ESC, 	KC_BRID,  	KC_BRIU,  	MAC_TASK, 	MAC_SEARCH, MAC_VOICE,  MAC_DND,    KC_MPRV,  	KC_MPLY,  	KC_MNXT, 	KC_MUTE, 	KC_VOLD, 	KC_VOLU, 	MAC_PRTA,	KC_INS,		KC_DEL,
	KC_GRV, 	KC_1,   	KC_2,   	KC_3,  		KC_4,   	KC_5,   	KC_6,   	KC_7,   	KC_8,   	KC_9,  		KC_0,   	KC_MINS,	KC_EQL, 				KC_BSPC,	KC_PGUP,
	KC_TAB, 	KC_Q,   	KC_W,   	KC_E,  		KC_R,   	KC_T,   	KC_Y,   	KC_U,   	KC_I,   	KC_O,  		KC_P,   	KC_LBRC,	KC_RBRC, 				KC_BSLS,	KC_PGDN,
	KC_CAPS,	KC_A,   	KC_S,   	KC_D,  		KC_F,   	KC_G,   	KC_H,   	KC_J,   	KC_K,   	KC_L,  		KC_SCLN,	KC_QUOT, 	 						KC_ENT,		KC_HOME,
	KC_LSFT,				KC_Z,   	KC_X,   	KC_C,  		KC_V,   	KC_B,   	KC_N,   	KC_M,   	KC_COMM,	KC_DOT,		KC_SLSH,				KC_RSFT,	KC_UP,		KC_END,
	KC_LCTL,	KC_LALT,	KC_LGUI,										KC_SPC, 							KC_RGUI,	MO(1),   	KC_RCTL,				KC_LEFT,	KC_DOWN,    KC_RGHT),

// layer Mac Fn
[1] = LAYOUT_ansi_84(
	_______, 	KC_F1,  	KC_F2,  	KC_F3, 		KC_F4,  	KC_F5,  	KC_F6,  	KC_F7,  	KC_F8,  	KC_F9, 		KC_F10, 	KC_F11, 	KC_F12, 	MAC_PRT,	_______,	_______,
	_______, 	LNK_BLE1,  	LNK_BLE2,  	LNK_BLE3,  	LNK_RF,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 				_______,	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	DEV_RESET,	SLEEP_MODE, 			BAT_SHOW,	_______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______,   	_______,   	_______,  	_______,	_______, 	 						_______,	_______,
	_______,				_______,   	_______,   	_______,  	_______,   	_______,   	_______,	MO(5), 		RGB_SPD,	RGB_SPI,	_______,				_______,	RGB_VAI,	_______,
	_______,	_______,	_______,										_______, 							_______,	MO(1),   	_______,				RGB_MOD,	RGB_VAD,    RGB_HUI),

// layer win
[2] = LAYOUT_ansi_84(
	KC_ESC, 	KC_F1,  	KC_F2,  	KC_F3, 		KC_F4,  	KC_F5,  	KC_F6,  	KC_F7,  	KC_F8,  	KC_F9, 		KC_F10, 	KC_F11, 	KC_F12, 	KC_PSCR,	KC_INS,		KC_DEL,
	KC_GRV, 	KC_1,   	KC_2,   	KC_3,  		KC_4,   	KC_5,   	KC_6,   	KC_7,   	KC_8,   	KC_9,  		KC_0,   	KC_MINS,	KC_EQL, 				KC_BSPC,	KC_PGUP,
	KC_TAB, 	KC_Q,   	KC_W,   	KC_E,  		KC_R,   	KC_T,   	KC_Y,   	KC_U,   	KC_I,   	KC_O,  		KC_P,   	KC_LBRC,	KC_RBRC, 				KC_BSLS,	KC_PGDN,
	KC_EXT, 	KC_A,   	KC_S,   	KC_D,  		KC_F,   	KC_G,   	KC_H,   	KC_J,   	KC_K,   	KC_L,  		KC_SCLN,	KC_QUOT, 	 						KC_ENT,		KC_HOME,
	KC_LSFT,				KC_Z,   	KC_X,   	KC_C,  		KC_V,   	KC_B,   	KC_N,   	KC_M,   	KC_COMM,	KC_DOT,		KC_SLSH,				KC_RSFT,	KC_UP,		KC_END,
	KC_LCTL,	KC_LGUI,	KC_LALT,										KC_SPC, 							MO(7),  	MO(4),   	KC_RCTL,				KC_LEFT,	KC_DOWN,    KC_RGHT),

// layer win Colemak-DH
// Rewrite some function keys to prevent fallbacking to the mac layer
[3] = LAYOUT_ansi_84(
    _______,	KC_F1,  	KC_F2,  	KC_F3, 		KC_F4,  	KC_F5,  	KC_F6,  	KC_F7,  	KC_F8,  	KC_F9, 		KC_F10, 	KC_F11, 	KC_F12, 	KC_PSCR,	KC_INS,		KC_DEL,
    _______,	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 				_______, 	_______,
    _______,	_______, 	_______, 	KC_F,    	KC_P,    	KC_B,    	KC_J,    	KC_L,    	KC_U,    	KC_Y,    	KC_SCLN, 	_______, 	_______, 				_______, 	_______,
    KC_EXT, 	_______, 	KC_R,    	KC_S,    	KC_T,    	_______, 	KC_M,    	KC_N,    	KC_E,    	KC_I,    	KC_O,    	_______, 							_______, 	_______,
    _______,				KC_X,    	KC_C,    	KC_D,    	KC_V,    	KC_Z,    	KC_K,    	KC_H,    	_______, 	_______, 	_______, 				_______, 	_______, 	_______,
    KC_LCTL,	KC_LGUI,	KC_LALT, 										_______, 							MO(7),  	MO(4),   	KC_RCTL, 				_______, 	_______, 	_______),


// layer win Fn
[4] = LAYOUT_ansi_84(
	_______, 	KC_BRID,   	KC_BRIU,    _______,  	_______,   	_______,   	_______,   	KC_MPRV,   	KC_MPLY,   	KC_MNXT,  	KC_MUTE, 	KC_VOLD, 	KC_VOLU,	_______,	_______,	_______,
	_______, 	LNK_BLE1,  	LNK_BLE2,  	LNK_BLE3,  	LNK_RF,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 				_______,	_______,
	_______, 	DF(2),   	DF(3),   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	DEV_RESET,	SLEEP_MODE, 			BAT_SHOW,	_______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______,   	_______,   	_______,  	_______,	_______, 	 						_______,	_______,
	_______,				_______,   	_______,   	_______,  	_______,   	_______,   	_______,	MO(5), 		RGB_SPD,	RGB_SPI,	_______,				_______,	RGB_VAI,	_______,
	_______,	_______,	_______,										_______, 							_______,	MO(4),   	_______,				RGB_MOD,	RGB_VAD,    RGB_HUI),

// layer 5
[5] = LAYOUT_ansi_84(
	_______, 	_______,  	_______,  	_______, 	_______,  	_______,  	_______,  	_______,  	_______,  	_______, 	_______, 	_______, 	_______, 	_______,	_______,	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 				_______,	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 				_______,	_______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,	_______, 	 						_______,	_______,
	_______,				_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	SIDE_SPD,	SIDE_SPI,	_______,				_______,	SIDE_VAI,	_______,
	_______,	_______,	_______,										_______, 							_______,	MO(5),   	_______,				SIDE_MOD,	SIDE_VAD,   SIDE_HUI),

// Extend layer
[6] = LAYOUT_ansi_84(
	KC_CAPS, 	KC_BRID,   	KC_BRIU,    _______,  	_______,   	_______,   	_______,   	KC_MPRV,	KC_MPLY,	KC_MNXT,	KC_MUTE,	KC_VOLD, 	KC_VOLU,	_______,	_______,	_______,
	_______, 	KC_F1,  	KC_F2,  	KC_F3, 		KC_F4,  	KC_F5,  	KC_F6,  	KC_F7,  	KC_F8,  	KC_F9,  	KC_F10, 	KC_F11, 	KC_F12, 				_______,	_______,
	_______, 	KC_ESC,   	KC_BTN4,	KC_FIND,	KC_BTN5,	_______,	KC_PGUP,	KC_HOME,	KC_UP,  	KC_END, 	KC_CAPS,	_______,	_______, 				_______,	_______,
	_______,	KC_LALT,   	KC_LGUI,	KC_LSFT,	KC_LCTL,	KC_RALT,	KC_PGDN,	KC_LEFT,	KC_DOWN,	KC_RGHT,	KC_DEL, 	KC_APP, 	 						_______,	_______,
	_______,				KC_CUT, 	KC_COPY,	KC_LGUI,	KC_PSTE,	S(KC_Z),	_______,	KC_BSPC,	KC_TAB, 	SIDE_SPI,	_______,				_______,	SIDE_VAI,	_______,
	_______,	_______,	_______,										KC_ENT, 							_______,	MO(5),   	_______,				SIDE_MOD,	SIDE_VAD,   SIDE_HUI),

// Symbols layer
[7] = LAYOUT_ansi_84(
	_______, 	KC_BRID,   	KC_BRIU,    _______,  	_______,   	_______,   	_______,   	KC_MPRV,	KC_MPLY,	KC_MNXT,	KC_MUTE,	KC_VOLD, 	KC_VOLU,	_______,	_______,	_______,
	_______, 	_______,	_______,  	_______,	_______,  	_______,  	_______,  	_______,  	_______,  	_______,  	_______, 	_______, 	_______, 				_______,	_______,
	_______, 	KC_EXLM,   	KC_AT,  	KC_HASH,	KC_DLR, 	KC_PERC,	KC_EQL, 	KC_P7,  	KC_P8,  	KC_P9,  	KC_PLUS,	_______,	_______, 				_______,	_______,
	_______,	KC_UNDS,   	KC_LBRC,	KC_LCBR,	KC_LPRN,	KC_PIPE,	KC_ASTR,	KC_P4,  	KC_P5,  	KC_P6,  	KC_MINUS, 	KC_APP, 	 						_______,	_______,
	_______,				KC_RBRC, 	KC_RCBR,	KC_RPRN,	KC_TILD,	KC_AMPR,	KC_P0,  	KC_P1,  	KC_P2,  	KC_P3,  	KC_BSLS,				_______,	SIDE_VAI,	_______,
	_______,	_______,	_______,										_______,							MO(7),  	_______,	_______,				SIDE_MOD,	SIDE_VAD,   SIDE_HUI),
};
