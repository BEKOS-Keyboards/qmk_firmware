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

#pragma once

#include "quantum.h"
#include "color.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#if defined(__GNUC__)
#    define PACKED __attribute__((__packed__))
#else
#    define PACKED
#endif

typedef union {
	uint32_t raw;
	struct PACKED {
		bool underkey_lock_rgb_enable :1;
		bool user_color_for_lock_ind: 1;
	};
} keyboard_config_t;

typedef enum {
	IND_OFF,
	IND_WHITE,
	IND_USER
} muse_layer_color_e;

typedef struct muse_layer {
	muse_layer_color_e right;
	muse_layer_color_e left;
} muse_layer_t;

enum keyboard_keycodes {
    BKB_IND_TOG = SAFE_RANGE,
	BKB_USER_TOG,
    NEW_SAFE_RANGE  // Important!
};

#define XXXX KC_NO

#define LAYOUT( \
    k000,       k002, k003, k004, k005,    k007, k008, k009, k00a,   k00b, k00c, k00d, k00e,  k00f, k010, k011,  k013, k014, k015, k016, \
    k200, k201, k202, k203, k204, k205, k206, k207, k208, k209, k20a, k20b, k20c,      k20e,  k20f, k210, k211,  k213, k214, k215, k216, \
	k300,   k302, k303, k304, k305, k306, k307, k308, k309, k30a, k30b, k30c, k30d,    k30e,  k30f, k310, k311,  k313, k314, k315, k316, \
	k400,    k402, k403, k404, k405, k406, k407, k408, k409, k40a, k40b, k40c,         k40d,                     k413, k414, k415,       \
	k501,    k502, k503, k504, k505, k506, k507, k508, k509, k50a, k50b,               k50d,        k510,        k513, k514, k515, k516, \
	k600, k601,    k603,                k606,                   k60a,  k60b,   k60d,   k60e,  k60f, k610, k611,  k613,       k615       \
) { \
    { k000, XXXX, k002, k003, k004, k005, XXXX, k007, k008, k009, k00a, k00b, k00c, k00d, k00e, k00f, k010, k011, k013, k014, k015, k016 }, \
	{ k200, k201, k202, k203, k204, k205, k206, k207, k208, k209, k20a, k20b, k20c, XXXX, k20e, k20f, k210, k211, k213, k214, k215, k216 }, \
	{ k300, XXXX, k302, k303, k304, k305, k306, k307, k308, k309, k30a, k30b, k30c, k30d, k30e, k30f, k310, k311, k313, k314, k315, k316 }, \
    { k400, XXXX, k402, k403, k404, k405, k406, k407, k408, k409, k40a, k40b, k40c, k40d, XXXX, XXXX, XXXX, XXXX, k413, k414, k415, XXXX }, \
	{ XXXX, k501, k502, k503, k504, k505, k506, k507, k508, k509, k50a, k50b, XXXX, k50d, XXXX, XXXX, k510, XXXX, k513, k514, k515, k516 }, \
	{ k600, k601, XXXX, k603, XXXX, XXXX, k606, XXXX, XXXX, XXXX, k60a, k60b, XXXX, k60d, k60e, k60f, k610, k611, k613, XXXX, k615, XXXX }  \
}
