/* Copyright 2021-2024 BEKOS Keyboards
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
#include QMK_KEYBOARD_H
#include "print.h"

#if defined(__GNUC__)
#    define PACKED __attribute__((__packed__))
#else
#    define PACKED
#endif

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN,
    _FN2,
    _FN3,
	_FN4,
	_FN5,
	_FN6,
	_FN7,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    BKB_FN = NEW_SAFE_RANGE,
	BKB_RGB_OFF,
	BKB_RGB_HUE,
	BKB_RGB_SAT,
	BKB_RGB_VAL,
	BKB_RGB_SPD,
	BKB_LAYER_BASE,
	BKB_LAYER_FN
};

// Configure RGB Control via Encoder
typedef struct PACKED {
	uint8_t hue : 2;
	uint8_t sat : 2;
	uint8_t val : 2;
	uint8_t speed : 2;
} encoder_rgb_t;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base */
	// clang-format off
    [_BASE] = LAYOUT(
  		KC_ESC,       KC_F1, KC_F2, KC_F3, KC_F4,    KC_F5, KC_F6, KC_F7, KC_F8,   KC_F9, KC_F10, KC_F11, KC_F12,      KC_PSCR, KC_SCRL, KC_PAUS,      KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, \
  		KC_GRV, KC_1, KC_2,  KC_3,  KC_4,  KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,      KC_BSPC,          KC_INS,  KC_HOME, KC_PGUP,      KC_NUM , KC_PSLS, KC_PAST, KC_PMNS, \
  		KC_TAB,   KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,    KC_BSLS,            KC_DEL,  KC_END,  KC_PGDN,      KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, \
  		KC_CAPS,    KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,         KC_ENT,                                            KC_KP_4, KC_KP_5, KC_KP_6,          \
  		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,                                    KC_UP,                KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, \
  		KC_LCTL, KC_LGUI,    KC_LALT,                KC_SPC,                   KC_RALT,  BKB_FN,  KC_APP, KC_RCTL,     KC_LEFT, KC_DOWN, KC_RIGHT,     KC_KP_0,          KC_KP_DOT         \
    ),
	[_FN] = LAYOUT(
  		KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  		KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  		KC_TRNS,  RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  		KC_TRNS,    RGB_RMOD, BKB_RGB_OFF, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS,          \
		BKB_RGB_SPD, BKB_IND_TOG, BKB_USER_TOG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		BKB_RGB_HUE, BKB_RGB_SAT, BKB_RGB_VAL,                KC_TRNS,                   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,          KC_TRNS           \
	),
	[_FN2] = LAYOUT(
		KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,                                            KC_TRNS, KC_TRNS, KC_TRNS,          \
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                          KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS, KC_TRNS,    KC_TRNS,                KC_TRNS,                   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,          KC_TRNS           \
	),
	[_FN3] = LAYOUT(
		KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,                                            KC_TRNS, KC_TRNS, KC_TRNS,          \
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                          KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS, KC_TRNS,    KC_TRNS,                KC_TRNS,                   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,          KC_TRNS           \
	),
	[_FN4] = LAYOUT(
		KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,                                            KC_TRNS, KC_TRNS, KC_TRNS,          \
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                          KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS, KC_TRNS,    KC_TRNS,                KC_TRNS,                   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,          KC_TRNS           \
	),
	[_FN5] = LAYOUT(
		KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,                                            KC_TRNS, KC_TRNS, KC_TRNS,          \
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                          KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS, KC_TRNS,    KC_TRNS,                KC_TRNS,                   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,          KC_TRNS           \
	),
	[_FN6] = LAYOUT(
		KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,                                            KC_TRNS, KC_TRNS, KC_TRNS,          \
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                          KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS, KC_TRNS,    KC_TRNS,                KC_TRNS,                   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,          KC_TRNS           \
	),
	[_FN7] = LAYOUT(
		KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,                                            KC_TRNS, KC_TRNS, KC_TRNS,          \
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                          KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS, KC_TRNS,    KC_TRNS,                KC_TRNS,                   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,          KC_TRNS           \
	)
	// clang-format on
};

enum combo_events {
  EN_BASE,
  EN_FN,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;
encoder_rgb_t encoder_control = {0,0,0,0};

const uint16_t PROGMEM reset_layer_to_base[] = {BKB_FN, KC_0, COMBO_END};
const uint16_t PROGMEM enable_layer_fn[] = {BKB_FN, KC_1, COMBO_END};
combo_t key_combos[] = {
  [EN_BASE] = COMBO(reset_layer_to_base, BKB_LAYER_BASE),
  [EN_FN] = COMBO(enable_layer_fn, BKB_LAYER_FN),
};


void process_bkb_layerchange(uint8_t layer_num){
	static uint8_t cur_layer = _BASE;
	if (cur_layer == _BASE) {
		dprintf("Layer Num: %u\n", layer_num);
		layer_on(layer_num);
	} else if (layer_num == _BASE && cur_layer != _BASE) {
		dprintf("Cur Layer Num: %u\n", cur_layer);
		layer_off(cur_layer);
	} else {
		dprintf("Current Layer: %u, Layer Num: %u\n", cur_layer, layer_num);
		layer_off(cur_layer);
		layer_on(layer_num);
	}
	cur_layer = layer_num;
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
	switch (index) {
		case EN_BASE:
		case EN_FN:
			return 3000;
	}
	return COMBO_TERM;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	case BKB_LAYER_BASE:
		if (record->event.pressed) {
			process_bkb_layerchange(_BASE);
		}
		break;
	case BKB_LAYER_FN:
		if (record->event.pressed) {
			process_bkb_layerchange(_FN);
		}
		break;
	case BKB_RGB_OFF:
		if (record->event.pressed) {
			rgb_matrix_mode(RGB_MATRIX_CUSTOM_MUSE_RGB_OFF);
		}
		break;
	case BKB_RGB_HUE:
		encoder_control.hue = record->event.pressed;
		break;
	case BKB_RGB_SAT:
		encoder_control.sat = record->event.pressed;
		break;
	case BKB_RGB_VAL:
		encoder_control.val = record->event.pressed;
		break;
	case BKB_RGB_SPD:
		encoder_control.speed = record->event.pressed;
		break;
	}


	return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
        	if (encoder_control.hue ||
        		encoder_control.sat ||
				encoder_control.val ||
				encoder_control.speed) {
        		HSV hsv = rgb_matrix_get_hsv();
        		uint8_t speed = rgb_matrix_get_speed();
        		if (encoder_control.hue) {
        			hsv.h++;
        		}
        		if (encoder_control.sat) {
        			hsv.s++;
        		}
        		if (encoder_control.val) {
        			hsv.v++;
        		}
        		if (encoder_control.speed) {
        			speed++;
        		}
        		rgb_matrix_sethsv(hsv.h, hsv.s, hsv.v);
        		rgb_matrix_set_speed(speed);
        	} else {
        		tap_code_delay(KC_VOLU, 10);
        	}
        } else {
        	if (encoder_control.hue ||
				encoder_control.sat ||
				encoder_control.val ||
				encoder_control.speed) {
        		HSV hsv = rgb_matrix_get_hsv();
				uint8_t speed = rgb_matrix_get_speed();
				if (encoder_control.hue) {
					hsv.h--;
				}
				if (encoder_control.sat) {
					hsv.s--;
				}
				if (encoder_control.val) {
					hsv.v--;
				}
				if (encoder_control.speed) {
					speed--;
				}
				rgb_matrix_sethsv(hsv.h, hsv.s, hsv.v);
				rgb_matrix_set_speed(speed);
        	} else {
        		tap_code_delay(KC_VOLD, 10);
        	}
        }
    }
    return true;
}
