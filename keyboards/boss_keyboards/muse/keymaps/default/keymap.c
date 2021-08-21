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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    BKBFN = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
		KC_ESC,       KC_F1, KC_F2, KC_F3, KC_F4,    KC_F5, KC_F6, KC_F7, KC_F8,   KC_F9, KC_F10, KC_F11, KC_F12,   KC_PSCR, KC_SLCK, KC_PAUS,     KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, \
		KC_GRV, KC_1, KC_2,  KC_3,  KC_4,  KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,      KC_BSPC,       KC_INS,  KC_HOME, KC_PGUP,     KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, \
		KC_TAB,   KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,    KC_BSLS,         KC_DEL,  KC_END,  KC_PGDN,     KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, \
		KC_CAPS,    KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,         KC_ENT,                                        KC_KP_4, KC_KP_5, KC_KP_6,       \
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,                                   KC_UP,             KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, \
		KC_LCTL, KC_LGUI,    KC_LALT,                KC_SPC,                   KC_RALT,  BKBFN,   KC_APP,   KC_LCTL,  KC_LEFT, KC_DOWN, KC_RIGHT,  KC_KP_0,       KC_KP_DOT       \
    ),
	[_FN] = LAYOUT(
		KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,                                        KC_TRNS, KC_TRNS, KC_TRNS,       \
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                   KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
		KC_TRNS, KC_TRNS,    KC_TRNS,                KC_TRNS,                   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,       KC_TRNS       \
	)
};


void process_bkb_layerchange(uint8_t layer_num){
	static uint8_t cur_layer = 0;
	if (cur_layer == 0){
		tap_code(TG(layer_num));
	} else {
		tap_code(TG(cur_layer));
		tap_code(TG(layer_num));
	}
	cur_layer = layer_num;
}

bool process_bkb_fn(uint16_t keycode, keyrecord_t *record) {
	bool layerchanged = false;

	switch (keycode) {
		case KC_0:
			if (record->event.pressed){
				process_bkb_layerchange(0); // reset to base layer
				layerchanged = true;
			}
			break;
		case  KC_1:
			if (record->event.pressed){
				process_bkb_layerchange(1); // go to function layer
				layerchanged = true;
			}
			break;
		case KC_2:
			if (record->event.pressed){
				rgb_matrix_set_color_all(RGB_WHITE);
				rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
				layerchanged = true;
		    }
		case KC_PAST:
			eeconfig_init();
			break;
		case KC_P9:
			rgb_matrix_step();
			break;
		case KC_P6:
			rgb_matrix_toggle();
			break;
		case KC_P3:
			rgb_matrix_step_reverse();
			break;

	}
	return layerchanged;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_keyboard=true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	static bool bkb_fn_pressed = false;
	bool layerchanged = false;
	if (bkb_fn_pressed) {
		layerchanged = process_bkb_fn(keycode, record);
	}
	if(!layerchanged){
		switch (keycode) {
			case BKBFN:
				if (record->event.pressed) {
					bkb_fn_pressed = true;
				} else {
					bkb_fn_pressed = false;
				}
				break;
		}
	}
    return true;
}
