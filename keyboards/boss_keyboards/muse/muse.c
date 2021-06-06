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

#include "muse.h"
#include "muse_rgb_leds.h"
#include "muse_indicator_control.h"

const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
	MUSE_RGB_ROW_1 ,
	MUSE_RGB_ROW_2 ,
	MUSE_RGB_ROW_3 ,
	MUSE_RGB_ROW_4 ,
	MUSE_RGB_ROW_5 ,
	MUSE_RGB_ROW_6 ,
	MUSE_RGB_INDICATOR
};

led_config_t g_led_config = { {
  // Key Matrix to LED Index
  { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, NO_LED },
  { 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40 },
  { 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61 },
  { 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77 },
  { 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94 },
  { 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107 }
 }, {
   { 0, 0 }, { 22, 0 }, { 34, 0 }, { 45, 0 }, { 56, 0 }, {73, 0 }, { 85, 0 }, { 96, 0 }, { 107, 0 }, { 124, 0 }, { 136, 0 }, { 147, 0 }, { 158, 0 }, { 173, 0 }, { 184, 0 }, { 195, 0 }, { 209, 0 }, { 221, 0 }, { 232, 0 },
   { 0, 17 }, { 11, 17 }, { 22, 17 }, { 34, 17 }, { 45, 17 }, { 56, 17 }, { 68, 17 }, { 79, 17 }, { 90, 17 }, { 102, 17 }, { 113, 17 }, { 124, 17 }, { 136, 17 }, { 158, 17 }, { 173, 17 }, { 184, 17 }, { 195, 17 }, { 209, 17 }, { 221, 17 }, { 232, 17 }, { 224, 17 },
   { 8, 29 }, { 17, 29 }, { 28, 29 }, { 39, 29 }, { 51, 29 }, { 62, 29 }, { 73, 29 }, { 85, 29 }, { 96, 29 }, { 107, 29 }, { 119, 29 }, { 130, 29 }, { 141, 29 }, { 161, 29 }, { 173, 29 }, { 184, 29 }, { 195, 29 }, { 209, 29 }, { 221, 29 }, { 232, 29 }, { 244, 34 },
   { 9, 40 }, { 19, 40 }, { 31, 40 }, { 42, 40 }, { 53, 40 }, { 65, 40 }, { 76, 40 }, { 87, 40 }, { 99, 40 }, { 110, 40 }, { 122, 40 }, { 133, 40 }, { 157, 40 }, { 161, 40 }, { 209, 40 }, { 221, 40 }, { 232, 40 },
   { 12, 52 }, { 25, 52 }, { 36, 52 }, { 48, 52 }, { 59, 52 }, { 70, 52 }, { 82, 52 }, { 93, 52 }, { 104, 52 }, { 116, 52 }, { 127, 52 }, { 133, 52 }, { 154, 52 }, { 184, 52 }, { 209, 52 }, { 221, 52 }, { 221, 52 }, { 232, 52 }, { 244, 58 },
   { 7, 64 }, { 21, 64 }, { 35, 64 }, { 78, 64 }, { 120, 64 }, { 134, 64 }, { 148, 64 }, { 163, 64 }, { 173, 64 }, { 184, 64 }, { 195, 64 }, { 221, 64 }, { 232, 64 },
   //{ 173, 40 }, { 178, 40 }, { 184, 40 }, { 190, 40 }, { 195, 40 }
 }, {
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
   5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 4, 4, 4, 4, 4, 4,
   5, 5, 5, 4, 5, 5, 5, 5, 4, 4, 4, 4, 4,
   //8, 8, 8, 8, 8
 }
};



void rgb_matrix_indicators_kb(void) {
	led_t led_state = host_keyboard_led_state();
	if (led_state.caps_lock){
		rgb_matrix_set_color(CAPS_LOCK_LED, RGB_WHITE);
	}
	if (led_state.num_lock){
		rgb_matrix_set_color(NUM_LOCK_LED, RGB_WHITE);
	}
	if (led_state.scroll_lock){
		rgb_matrix_set_color(SCROLL_LOCK_LED, RGB_WHITE);
	}
	if (led_state.compose){
		rgb_matrix_set_color(COMPOSE_LED, RGB_WHITE);
	}
	if (led_state.kana){
		rgb_matrix_set_color(KANA_LED, RGB_WHITE);
	}
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}

bool encoder_update_kb(uint8_t index, bool clockwise) {
    return encoder_update_user(index, clockwise);
}

