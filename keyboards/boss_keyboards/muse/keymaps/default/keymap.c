/* Copyright 2021 BOSS-Keyboards
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN,
    _FN2,
    _FN3
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    BKB_FN = SAFE_RANGE,
	BKB_RGB_OFF
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
  		KC_ESC,       KC_F1, KC_F2, KC_F3, KC_F4,    KC_F5, KC_F6, KC_F7, KC_F8,   KC_F9, KC_F10, KC_F11, KC_F12,      KC_PSCR, KC_SLCK, KC_PAUS,      KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, \
  		KC_GRV, KC_1, KC_2,  KC_3,  KC_4,  KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,      KC_BSPC,          KC_INS,  KC_HOME, KC_PGUP,      KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, \
  		KC_TAB,   KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,    KC_BSLS,            KC_DEL,  KC_END,  KC_PGDN,      KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, \
  		KC_CAPS,    KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,         KC_ENT,                                            KC_KP_4, KC_KP_5, KC_KP_6,          \
  		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,                                    KC_UP,                KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, \
  		KC_LCTL, KC_LGUI,    KC_LALT,                KC_SPC,                   KC_RALT,  BKB_FN,  KC_MENU, KC_RCTL,    KC_LEFT, KC_DOWN, KC_RIGHT,     KC_KP_0,          KC_KP_DOT         \
    ),
	[_FN] = LAYOUT(
  		KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  		KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  		KC_TRNS,  RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  		KC_TRNS,    RGB_RMOD, BKB_RGB_OFF, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,                                           KC_TRNS, KC_TRNS, KC_TRNS,          \
  		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                          KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  		KC_TRNS, KC_TRNS,    KC_TRNS,                KC_TRNS,                   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,          KC_TRNS           \
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
	)
};


static uint8_t cur_layer = _BASE;
void process_bkb_layerchange(uint8_t layer_num){
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

bool process_bkb_fn(uint16_t keycode, keyrecord_t *record) {
	bool layerchanged = false;
	dprintf("Processing layer change...\n");
	switch (keycode) {
		case KC_0:
			if (record->event.pressed){
				process_bkb_layerchange(_BASE); // reset to base layer
				layerchanged = true;
			}
			break;
		case  KC_1:
			if (record->event.pressed){
				process_bkb_layerchange(_FN); // go to function layer
				layerchanged = true;
			}
			break;
	}
	return layerchanged;
}

static bool bkb_fn_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	bool layerchanged = false;
	if (bkb_fn_pressed) {
		layerchanged = process_bkb_fn(keycode, record);
	}
	if(!layerchanged){
		switch (keycode) {
			case BKB_FN:
				if (record->event.pressed) {
					bkb_fn_pressed = true;
				} else {
					bkb_fn_pressed = false;
				}
				break;
			case BKB_RGB_OFF:
				if (record->event.pressed) {
					rgb_matrix_sethsv(HSV_OFF);
					rgb_matrix_mode(RGB_MATRIX_NONE);
				}
				break;
		}
	}
	dprintf("BK_FN Pressed: %s, Layer Changed: %s\n", bkb_fn_pressed ? "true":"false", layerchanged ? "true":"false");
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
        	tap_code_delay(KC_VOLU, 10);
        } else {
        	tap_code_delay(KC_VOLD, 10);
        }
    }
    return true;
}
