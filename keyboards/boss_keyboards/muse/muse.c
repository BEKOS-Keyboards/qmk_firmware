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
#ifdef RGB_MATRIX_ENABLE
#include "is31fl3733.h"
#define ISSI_COMMANDREGISTER_WRITELOCK 0xFE
#define ISSI_COMMANDREGISTER 0xFD
#define ISSI_PAGE_FUNCTION 0x03    	 // PG3
#define ISSI_REG_SWPULLUP 0x0F       // PG3
#define ISSI_REG_CSPULLUP 0x10       // PG3
#endif




const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
	MUSE_RGB_ROW_1 ,
	MUSE_RGB_ROW_2 ,
	MUSE_RGB_ROW_3 ,
	MUSE_RGB_ROW_4 ,
	MUSE_RGB_ROW_5 ,
	MUSE_RGB_ROW_6 ,
	MUSE_RGB_INDICATOR
};

static bool diff_layer = false;



led_config_t g_led_config = { {
  // Key Matrix to LED Index
    {      0, NO_LED,      1,  2,      3,      4, NO_LED,      5,      6,      7,  8,  9,     10,     11,     12,     13,     14,     15,  16,     17,  18, NO_LED },
    {     19,     20,     21, 22,     23,     24,     25,     26,     27,     28, 29, 30,     31, NO_LED,     32,     33,     34,     35,  36,     37,  38,     39 },
    {     40, NO_LED,     41, 42,     43,     44,     45,     46,     47,     48, 49, 50,     51,     52,     53,     54,     55,     56,  57,     58,  59,     60 },
    {     61, NO_LED,     62, 63,     64,     65,     66,     67,     68,     69, 70, 71,     72,     73, NO_LED, NO_LED, NO_LED, NO_LED,  74,     75,  76, NO_LED },
    { NO_LED,     77,     78, 79,     80,     81,     82,     83,     84,     85, 86, 87, NO_LED,     88, NO_LED, NO_LED,     89, NO_LED,  90,     91,  92,     93 },
    {     94,     95, NO_LED, 96, NO_LED, NO_LED,     97, NO_LED, NO_LED, NO_LED, 98, 99, NO_LED,    100,    101,    102,    103,    104, 105, NO_LED, 106, NO_LED }
 }, {
    {  0,  0}, { 20,  0}, { 30,  0}, { 40,  0}, { 50,   0}, { 66,  0}, { 76,  0}, { 86,  0}, { 96,  0}, {112,  0}, {122,  0}, {132,  0}, {142,  0}, {155,  0}, {165,  0}, {175,  0}, {188,  0}, {198,  0}, {208,  0},
    {  0, 16}, { 11, 16}, { 20, 16}, { 30, 16}, { 40,  16}, { 50, 16}, { 61, 16}, { 71, 16}, { 81, 16}, { 91, 16}, {101, 16}, {112, 16}, {122, 16}, {142, 16}, {155, 16}, {165, 16}, {175, 16}, {188, 16}, {198, 16}, {208, 16}, {218, 16},
    {  7, 26}, { 15, 26}, { 25, 26}, { 35, 26}, { 45,  26}, { 56, 26}, { 66, 26}, { 76, 26}, { 86, 26}, { 96, 26}, {106, 26}, {117, 26}, {127, 26}, {145, 26}, {155, 26}, {165, 26}, {175, 26}, {188, 26}, {198, 26}, {208, 26}, {218, 32},
    {  9, 37}, { 17, 37}, { 28, 37}, { 38, 37}, { 48,  37}, { 58, 37}, { 68, 37}, { 78, 37}, { 89, 37}, { 99, 37}, {109, 37}, {119, 37}, {141, 37}, {188, 37}, {198, 37}, {208, 37},
    { 11, 48}, { 22, 48}, { 33, 48}, { 43, 48}, { 53,  48}, { 63, 48}, { 73, 48}, { 84, 48}, { 94, 48}, {104, 48}, {114, 48}, {138, 48}, {165, 48}, {188, 48}, {198, 48}, {208, 48}, {218, 53},
    {  6, 58}, { 19, 58}, { 31, 58}, { 70, 58}, {108,  58}, {120, 58}, {133, 58}, {146, 58}, {155, 58}, {165, 58}, {175, 58}, {198, 58}, {208, 58},
	{155, 37}, {160, 37}, {165, 37}, {170, 37}, {175,  37}
 }, {
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
   5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 4, 4, 4, 4, 4,
   5, 5, 5, 4, 5, 5, 5, 5, 4, 4, 4, 4, 4,
   8, 8, 8, 8, 8
 }
};


layer_state_t layer_state_set_kb(layer_state_t state) {
	switch (get_highest_layer(state)) {
		case 1:
			diff_layer = true;
			break;
		default:
			diff_layer = false;
	}
	return state;
}

#ifdef RGB_MATRIX_ENABLE
void enable_deghost_on_rgb_matrix_driver(uint8_t addr) {
	// Unlock command register
	IS31FL3733_write_register(addr, ISSI_COMMANDREGISTER_WRITELOCK, 0xC5);

	//Select PG3
	IS31FL3733_write_register(addr, ISSI_COMMANDREGISTER, ISSI_PAGE_FUNCTION);
	// Set SWx Pull-up
	IS31FL3733_write_register(addr, ISSI_REG_SWPULLUP, 0x07);
	// Set CSx Pull-down
	IS31FL3733_write_register(addr, ISSI_REG_CSPULLUP, 0x07);
	// Wait 10ms to ensure the device has been configured.
	wait_ms(10);
}
#endif

void keyboard_post_init_kb(void) {
#ifdef CONSOLE_ENABLE
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=false;
  debug_keyboard=true;
  //debug_mouse=true;
#endif
#ifdef RGB_MATRIX_ENABLE
    // This is a hack to enable de-ghosting resistors on the keyboard
	enable_deghost_on_rgb_matrix_driver(DRIVER_ADDR_1);
	enable_deghost_on_rgb_matrix_driver(DRIVER_ADDR_2);
#endif
	keyboard_post_init_user();
}

RGB dim_indicators(HSV hsv) {
	hsv.v = hsv.v - MUSE_INDICATORS_DIM_VAL;
	return hsv_to_rgb(hsv);
}

void rgb_matrix_indicators_kb(void) {
	led_t led_state = host_keyboard_led_state();
	HSV indicator_hsv = {HSV_WHITE};
	if (led_state.caps_lock){
		RGB indicator_color = dim_indicators(indicator_hsv);
		rgb_matrix_set_color(CAPS_LOCK_LED, indicator_color.r, indicator_color.g, indicator_color.b);
#if defined(MUSE_KEY_INDICATORS)
		rgb_matrix_set_color(CAPS_LOCK_KEY_LED, RGB_WHITE);
#endif
	} else {
		rgb_matrix_set_color(CAPS_LOCK_LED, RGB_OFF);
	}
	if (led_state.num_lock){
		RGB indicator_color = dim_indicators(indicator_hsv);
		rgb_matrix_set_color(NUM_LOCK_LED, indicator_color.r, indicator_color.g, indicator_color.b);
#if defined(MUSE_KEY_INDICATORS)
		rgb_matrix_set_color(NUM_LOCK_KEY_LED, RGB_WHITE);
#endif
	} else {
		rgb_matrix_set_color(NUM_LOCK_LED, RGB_OFF);
	}
	if (led_state.scroll_lock){
		RGB indicator_color = dim_indicators(indicator_hsv);
		rgb_matrix_set_color(SCROLL_LOCK_LED, indicator_color.r, indicator_color.g, indicator_color.b);
#if defined(MUSE_KEY_INDICATORS)
		rgb_matrix_set_color(SCROLL_LOCK_KEY_LED, RGB_WHITE);
#endif
	} else {
		rgb_matrix_set_color(SCROLL_LOCK_LED, RGB_OFF);
	}
	rgb_matrix_set_color(COMPOSE_LED, RGB_OFF);
	if (diff_layer) {
		rgb_matrix_set_color(KANA_LED, RGB_RED);
	} else {
		rgb_matrix_set_color(KANA_LED, RGB_OFF);
	}
}
