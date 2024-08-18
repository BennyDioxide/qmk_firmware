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

extern MidiDevice midi_device;

enum win_keymap_layer {
    LY_QWER = 2,
    LY_CMDH,
    LY_FN,
    LY_SIDE,
    LY_EXT,
    LY_MOUS,
    LY_SYM,
    LY_MIDI,
};

enum keycodes {
    TG_MIDI = SAFE_RANGE,
};

#define KC_EXT (LT(LY_EXT, KC_CAPS))

// clang-format off
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
[LY_QWER] = LAYOUT_ansi_84(
	KC_ESC, 	KC_F1,  	KC_F2,  	KC_F3, 		KC_F4,  	KC_F5,  	KC_F6,  	KC_F7,  	KC_F8,  	KC_F9, 		KC_F10, 	KC_F11, 	KC_F12, 	KC_PSCR,	KC_INS,		KC_DEL,
	KC_GRV, 	KC_1,   	KC_2,   	KC_3,  		KC_4,   	KC_5,   	KC_6,   	KC_7,   	KC_8,   	KC_9,  		KC_0,   	KC_MINS,	KC_EQL, 				KC_BSPC,	KC_PGUP,
	KC_TAB, 	KC_Q,   	KC_W,   	KC_E,  		KC_R,   	KC_T,   	KC_Y,   	KC_U,   	KC_I,   	KC_O,  		KC_P,   	KC_LBRC,	KC_RBRC, 				KC_BSLS,	KC_PGDN,
	KC_EXT, 	KC_A,   	KC_S,   	KC_D,  		KC_F,   	KC_G,   	KC_H,   	KC_J,   	KC_K,   	KC_L,  		KC_SCLN,	KC_QUOT, 	 						KC_ENT,		KC_HOME,
	KC_LSFT,				KC_Z,   	KC_X,   	KC_C,  		KC_V,   	KC_B,   	KC_N,   	KC_M,   	KC_COMM,	KC_DOT,		KC_SLSH,				KC_RSFT,	KC_UP,		KC_END,
	KC_LCTL,	KC_LGUI,	KC_LALT,										KC_SPC, 							MO(LY_SYM), 	MO(LY_FN),   	TG_MIDI,				KC_LEFT,	KC_DOWN,    KC_RGHT),

// layer win Colemak-DH
// Rewrite some function keys to prevent fallbacking to the mac layer
[LY_CMDH] = LAYOUT_ansi_84(
    _______,	KC_F1,  	KC_F2,  	KC_F3, 		KC_F4,  	KC_F5,  	KC_F6,  	KC_F7,  	KC_F8,  	KC_F9, 		KC_F10, 	KC_F11, 	KC_F12, 	KC_PSCR,	KC_INS,		KC_DEL,
    _______,	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 				_______, 	_______,
    _______,	_______, 	_______, 	KC_F,    	KC_P,    	KC_B,    	KC_J,    	KC_L,    	KC_U,    	KC_Y,    	KC_SCLN, 	_______, 	_______, 				_______, 	_______,
    KC_EXT, 	_______, 	KC_R,    	KC_S,    	KC_T,    	_______, 	KC_M,    	KC_N,    	KC_E,    	KC_I,    	KC_O,    	_______, 							_______, 	_______,
    _______,				KC_X,    	KC_C,    	KC_D,    	KC_V,    	KC_Z,    	KC_K,    	KC_H,    	_______, 	_______, 	_______, 				_______, 	_______, 	_______,
    KC_LCTL,	KC_LGUI,	KC_LALT, 										_______, 							MO(LY_SYM),  	MO(LY_FN),   	TG_MIDI, 				_______, 	_______, 	_______),


// layer win Fn
[LY_FN] = LAYOUT_ansi_84(
	_______, 	KC_BRID,   	KC_BRIU,    _______,  	_______,   	_______,   	_______,   	KC_MPRV,   	KC_MPLY,   	KC_MNXT,  	KC_MUTE, 	KC_VOLD, 	KC_VOLU,	_______,	_______,	_______,
	_______, 	LNK_BLE1,  	LNK_BLE2,  	LNK_BLE3,  	LNK_RF,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 				_______,	_______,
	_______, 	DF(LY_QWER),DF(LY_CMDH),_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	DEV_RESET,	SLEEP_MODE, 			BAT_SHOW,	_______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______,   	_______,   	_______,  	_______,	_______, 	 						_______,	_______,
	_______,				_______,   	_______,   	_______,  	_______,   	_______,   	_______,	MO(LY_SIDE), 		RGB_SPD,	RGB_SPI,	_______,				_______,	RGB_VAI,	_______,
	_______,	_______,	_______,										_______, 							_______,	MO(LY_FN),   	_______,				RGB_MOD,	RGB_VAD,    RGB_HUI),

// layer 5
[LY_SIDE] = LAYOUT_ansi_84(
	_______, 	_______,  	_______,  	_______, 	_______,  	_______,  	_______,  	_______,  	_______,  	_______, 	_______, 	_______, 	_______, 	_______,	_______,	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 				_______,	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 				_______,	_______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,	_______, 	 						_______,	_______,
	_______,				_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	SIDE_SPD,	SIDE_SPI,	_______,				_______,	SIDE_VAI,	_______,
	_______,	_______,	_______,										_______, 							_______,	MO(LY_SIDE),   	_______,				SIDE_MOD,	SIDE_VAD,   SIDE_HUI),

// Extend layer
[LY_EXT] = LAYOUT_ansi_84(
	KC_CAPS, 	KC_BRID,   	KC_BRIU,    _______,  	_______,   	_______,   	_______,   	KC_MPRV,	KC_MPLY,	KC_MNXT,	KC_MUTE,	KC_VOLD, 	KC_VOLU,	_______,	_______,	_______,
	_______, 	KC_F1,  	KC_F2,  	KC_F3, 		KC_F4,  	KC_F5,  	KC_F6,  	KC_F7,  	KC_F8,  	KC_F9,  	KC_F10, 	KC_F11, 	KC_F12, 				_______,	_______,
	_______, 	KC_ESC,   	KC_BTN4,	KC_FIND,	KC_BTN5,	_______,	KC_PGUP,	KC_HOME,	KC_UP,  	KC_END, 	KC_CAPS,	_______,	_______, 				_______,	_______,
	MO(LY_EXT),	KC_LALT,   	KC_LGUI,	KC_LSFT,	KC_LCTL,	KC_RALT,	KC_PGDN,	KC_LEFT,	KC_DOWN,	KC_RGHT,	KC_DEL, 	KC_APP, 	 						_______,	_______,
	MO(LY_MOUS),				KC_CUT, 	KC_COPY,	KC_LGUI,	KC_PSTE,	C(KC_Z),	_______,	KC_BSPC,	KC_TAB, 	SIDE_SPI,	_______,				_______,	SIDE_VAI,	_______,
	_______,	_______,	_______,										KC_ENT, 							_______,	_______,	_______,				SIDE_MOD,	SIDE_VAD,   SIDE_HUI),

// Mouse layer
[LY_MOUS] = LAYOUT_ansi_84(
	_______, 	_______,	_______,	_______,	_______,	_______,	_______,	_______,  	_______,	_______,	_______, 	_______, 	_______, 	_______,	_______,	_______,
	_______, 	_______,	_______,	_______,  	_______,  	_______,  	_______,  	_______,  	_______,	_______,	_______, 	_______, 	_______, 				_______,	_______,
	_______, 	_______,	KC_BTN4,	KC_BTN3,	KC_BTN5,	_______,	KC_WH_U,	KC_BTN1,	KC_MS_U,	KC_BTN2,	_______,	_______,	_______, 				_______,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,	KC_WH_D,	KC_MS_L,	KC_MS_D,	KC_MS_R,	KC_DEL, 	KC_APP, 	 						_______,	_______,
	MO(LY_MOUS),				_______, 	_______,	_______,	_______,	C(KC_Z),	_______,	_______,	_______, 	_______,	_______,				_______,	_______,	_______,
	_______,	_______,	_______,										_______, 							_______,	_______,	_______,				_______,	_______,   _______),

// Symbols layer
[LY_SYM] = LAYOUT_ansi_84(
	_______, 	KC_BRID,   	KC_BRIU,    _______,  	_______,   	_______,   	_______,   	KC_MPRV,	KC_MPLY,	KC_MNXT,	KC_MUTE,	KC_VOLD, 	KC_VOLU,	_______,	_______,	_______,
	_______, 	_______,	_______,  	_______,	_______,  	_______,  	_______,  	_______,  	_______,  	_______,  	_______, 	_______, 	_______, 				_______,	_______,
	_______, 	KC_EXLM,   	KC_AT,  	KC_HASH,	KC_DLR, 	KC_PERC,	KC_EQL, 	KC_P7,  	KC_P8,  	KC_P9,  	KC_PLUS,	_______,	_______, 				_______,	_______,
	_______,	KC_UNDS,   	KC_LBRC,	KC_LCBR,	KC_LPRN,	KC_PIPE,	KC_ASTR,	KC_P4,  	KC_P5,  	KC_P6,  	KC_MINUS, 	KC_NUM, 	 						_______,	_______,
	_______,				KC_RBRC, 	KC_RCBR,	KC_RPRN,	KC_TILD,	KC_AMPR,	KC_P0,  	KC_P1,  	KC_P2,  	KC_P3,  	KC_BSLS,				_______,	SIDE_VAI,	_______,
	_______,	_______,	_______,										_______,							MO(7),  	_______,	_______,				SIDE_MOD,	SIDE_VAD,   SIDE_HUI),
// Midi Layer
[LY_MIDI] = LAYOUT_ansi_84(
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	MI_Db3, 	MI_Eb3, 	_______,	MI_Fs3, 	MI_Ab3, 	MI_Bb3, 	_______,	MI_Db4, 	MI_Eb4, 	_______,	_______,				_______,	_______,
	_______,	MI_C3,  	MI_D3,  	MI_E3,  	MI_F3,  	MI_G3,  	MI_A3,  	MI_B3,  	MI_C4,  	MI_D4,  	MI_E4,  	_______,	_______,				_______,	_______,
	_______,	_______,	MI_Db2, 	MI_Eb2, 	_______,	MI_Fs2, 	MI_Ab2, 	MI_Bb2, 	_______,	MI_Db3, 	MI_Eb3, 	_______,							_______,	_______,
	_______,				MI_C2,  	MI_D2,  	MI_E2,  	MI_F2,  	MI_G2,  	MI_A2,  	MI_B2,  	MI_C3,  	MI_D3,  	MI_E3,				_______,	_______,	_______,
	_______,	_______,	_______,										_______,							_______,	_______,	TG_MIDI,				_______,	_______,	_______),

};
// clang-format on

#include "rgb_palette.h"
#define LIGHT_SHOW_CHANNEL 5
#define KEY_COUNT 84

// A map from midi note to velocity, which represents the rgb color
uint8_t midi_rgb[KEY_COUNT] = {0};

void note_rgb(uint8_t chan, uint8_t note, uint8_t vel) {
    if (chan != LIGHT_SHOW_CHANNEL || !layer_state_is(LY_MIDI)) return;
    midi_rgb[note % KEY_COUNT] = vel;
}

void noteon_callback(MidiDevice* device, uint8_t chan, uint8_t note, uint8_t vel) {
    note_rgb(chan, note, vel);
}

void noteoff_callback(MidiDevice* device, uint8_t chan, uint8_t note, uint8_t vel) {
    note_rgb(chan, note, 0);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (layer_state_is(LY_MIDI)) {
        for (uint8_t i = led_min; i < led_max; i++) {
            rgb_color_t color = rgb_palette[midi_rgb[i]];
            rgb_matrix_set_color(i, color.r, color.g, color.b);
        }
    }
    return false;
}

void keyboard_post_init_user(void) {
    //  Set octave to 0
    midi_config.octave = QK_MIDI_OCTAVE_0 - MIDI_OCTAVE_MIN;

    // avoid using 127 since it is used as a special number in some sound sources.
    midi_config.velocity = 117;
    midi_register_noteon_callback(&midi_device, noteon_callback);
    midi_register_noteoff_callback(&midi_device, noteoff_callback);
    midi_register_pitchbend_callback(&midi_device, noteon_callback);
};

// Add the behaviour of  new keycodes
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case TG_MIDI:
            // Our logic will happen on presses, nothing is done on releases
            if (!record->event.pressed) {
                // We've already handled the keycode (doing nothing), let QMK know so no further code is run unnecessarily
                return false;
            }

            layer_invert(LY_MIDI);

            if (layer_state_is(LY_MIDI)) {
                memset(midi_rgb, 0, sizeof(midi_rgb));
                rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            } else {
                rgb_matrix_mode(RGB_MATRIX_DEFAULT_MODE);
            }
            return false;

        // Process other keycodes normally
        default:
            return true;
    }
}
