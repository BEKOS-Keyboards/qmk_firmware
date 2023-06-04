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
        bool underkey_lock_ind_enable : 1;
        bool user_color_for_lock_ind : 1;
    };
} keyboard_config_t;

typedef enum { IND_OFF, IND_INV, IND_USER } muse_layer_color_e;

typedef struct muse_layer {
    muse_layer_color_e right;
    muse_layer_color_e left;
} muse_layer_t;

void toggle_lock_key_underglow(void);
void toggle_user_color_for_indicators(void);

// clang-format off
#define XXXX KC_NO

#define LAYOUT( \
    k101,       k103, k104, k105, k106,    k107, k108, k109, k10a,   k10b, k10c, k10d, k10e,  k10f, k110, k111,  k112, \
    k201, k202, k203, k204, k205, k206, k207, k208, k209, k20a, k20b, k20c, k20d,      k20f,  k210, k211, k212, \
	k301,   k303, k304, k305, k306, k307, k308, k309, k30a, k30b, k30c, k30d, k30e,    k30f,  k310, k311, k312, \
	k401,    k403, k404, k405, k406, k407, k408, k409, k40a, k40b, k40c, k40d,         k40e,                    \
	k502,    k503, k504, k505, k506, k507, k508, k509, k50a, k50b, k50c,               k50e,        k511,       \
	k601, k602,    k604,                k607,                   k60b,  k60c,   k60e,   k60f,  k610, k611, k612, \
    k801, k802, k803, k804, \
    k901, k902, k903, k904, \
    ka01, ka02, ka03, \
    kb01, kb02, kb03, kb04, \
    kc01,       kc03 \
) { \
    { k101, XXXX, k103, k104, k105, k106, k107, k108, k109, k10a, k10b, k10c, k10d, k10e, k10f, k110, k111, k112 }, \
	{ k201, k202, k203, k204, k205, k206, k207, k208, k209, k20a, k20b, k20c, k20d, XXXX, k20f, k210, k211, k212 }, \
	{ k301, XXXX, k303, k304, k305, k306, k307, k308, k309, k30a, k30b, k30c, k30d, k30e, k30f, k310, k311, k312 }, \
    { k401, XXXX, k403, k404, k405, k406, k407, k408, k409, k40a, k40b, k40c, k40d, k40e, XXXX, XXXX, XXXX, XXXX }, \
	{ XXXX, k502, k503, k504, k505, k506, k507, k508, k509, k50a, k50b, k50c, XXXX, k50e, XXXX, XXXX, k511, XXXX }, \
	{ k601, k602, XXXX, k604, XXXX, XXXX, k607, XXXX, XXXX, XXXX, k60b, k60c, XXXX, k60e, k60f, k610, k611, k612 }, \
    { XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX }, \
    { k801, k802, k803, k804, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX }, \
    { k901, k902, k903, k904, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX }, \
    { ka01, ka02, ka03, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX }, \
    { kb01, kb02, kb03, kb04, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX }, \
    { kc01, XXXX, kc03, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX }  \
}
