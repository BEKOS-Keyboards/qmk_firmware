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
#ifdef VIA_ENABLE
    BKB_FN         = QK_KB_0,
    BKB_RGB_OFF    = QK_KB_1,
    BKB_RGB_HUE    = QK_KB_2,
    BKB_RGB_SAT    = QK_KB_3,
    BKB_RGB_VAL    = QK_KB_4,
    BKB_RGB_SPD    = QK_KB_5,
    BKB_IND_TOG    = QK_KB_6,
    BKB_USER_TOG   = QK_KB_7,
    BKB_LAYER_BASE = SAFE_RANGE,
#else
    BKB_FN = SAFE_RANGE,
    BKB_RGB_OFF,
    BKB_RGB_HUE,
    BKB_RGB_SAT,
    BKB_RGB_VAL,
    BKB_RGB_SPD,
    BKB_IND_TOG,
    BKB_USER_TOG,
    BKB_LAYER_BASE,

#endif
    BKB_LAYER_FN,
#ifdef MEME_ENABLE
    TAUNT_TEXT_EN,
    WIDE_TEXT_EN,
#endif
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
  		KC_ESC,       KC_F1, KC_F2, KC_F3, KC_F4,    KC_F5, KC_F6, KC_F7, KC_F8,   KC_F9, KC_F10, KC_F11, KC_F12,      KC_PSCR, KC_SCRL, KC_PAUS,   KC_MUTE, \
  		KC_GRV, KC_1, KC_2,  KC_3,  KC_4,  KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,      KC_BSPC,          KC_INS,  KC_HOME, KC_PGUP,            \
  		KC_TAB,   KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,    KC_BSLS,            KC_DEL,  KC_END,  KC_PGDN,            \
  		KC_CAPS,    KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,         KC_ENT,                                                  \
  		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,                                    KC_UP,                      \
  		KC_LCTL, KC_LGUI,    KC_LALT,                KC_SPC,                   KC_RALT,  BKB_FN,  KC_APP, KC_RCTL,     KC_LEFT, KC_DOWN, KC_RIGHT,           \
        KC_NUM, KC_PSLS, KC_PAST, KC_PMNS, \
        KC_P7, KC_P8, KC_P9, KC_PPLS,      \
        KC_P4, KC_P5, KC_P6,               \
        KC_P1, KC_P2, KC_P3, KC_PENT,      \
        KC_P0, KC_PDOT \
    ),
	[_FN] = LAYOUT(
  		KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, \
  		KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,              \
  		KC_TRNS,  RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,              \
  		KC_TRNS,    RGB_RMOD, BKB_RGB_OFF, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,                                                  \
		BKB_RGB_SPD, BKB_IND_TOG, BKB_USER_TOG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                KC_TRNS,                  \
		BKB_RGB_HUE, BKB_RGB_SAT, BKB_RGB_VAL,                KC_TRNS,                   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS,              \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS,          \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS \
	),
	[_FN2] = LAYOUT(
		KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, \
		KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,              \
		KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,              \
		KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,                                                     \
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                          KC_TRNS,                       \
		KC_TRNS, KC_TRNS,    KC_TRNS,                KC_TRNS,                   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS,              \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS,          \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS \
	),
	[_FN3] = LAYOUT(
		KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, \
		KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,              \
		KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,              \
		KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,                                                     \
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                          KC_TRNS,                       \
		KC_TRNS, KC_TRNS,    KC_TRNS,                KC_TRNS,                   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS,              \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS,          \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS \
	),
	[_FN4] = LAYOUT(
		KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, \
		KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,              \
		KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,              \
		KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,                                                     \
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                          KC_TRNS,                       \
		KC_TRNS, KC_TRNS,    KC_TRNS,                KC_TRNS,                   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS,              \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS,          \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS \
	),
	[_FN5] = LAYOUT(
		KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, \
		KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,              \
		KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,              \
		KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,                                                     \
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                          KC_TRNS,                       \
		KC_TRNS, KC_TRNS,    KC_TRNS,                KC_TRNS,                   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS,              \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS,          \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS \
	),
	[_FN6] = LAYOUT(
		KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, \
		KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,              \
		KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,              \
		KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,                                                     \
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                          KC_TRNS,                       \
		KC_TRNS, KC_TRNS,    KC_TRNS,                KC_TRNS,                   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS,              \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS,          \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS \
	),
	[_FN7] = LAYOUT(
		KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, \
		KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,              \
		KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,              \
		KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,                                                     \
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                          KC_TRNS,                       \
		KC_TRNS, KC_TRNS,    KC_TRNS,                KC_TRNS,                   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS,              \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS,          \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS \
	)
    // clang-format on
};

enum combo_events {
    EN_BASE,
    EN_FN,
#ifdef MEME_ENABLE
    EN_TAUNT,
    EN_WIDE,
#endif
    COMBO_LENGTH
};

uint16_t      COMBO_LEN       = COMBO_LENGTH;
encoder_rgb_t encoder_control = {0, 0, 0, 0};

const uint16_t PROGMEM reset_layer_to_base[] = {BKB_FN, KC_0, COMBO_END};
const uint16_t PROGMEM enable_layer_fn[]     = {BKB_FN, KC_1, COMBO_END};
#ifdef MEME_ENABLE
const uint16_t PROGMEM enable_taunt[] = {BKB_FN, KC_KP_1, COMBO_END};
const uint16_t PROGMEM enable_wide[]  = {BKB_FN, KC_KP_2, COMBO_END};
#endif
combo_t key_combos[] = {
    [EN_BASE] = COMBO(reset_layer_to_base, BKB_LAYER_BASE),
    [EN_FN]   = COMBO(enable_layer_fn, BKB_LAYER_FN),
#ifdef MEME_ENABLE
    [EN_TAUNT] = COMBO(enable_taunt, TAUNT_TEXT_EN),
    [EN_WIDE]  = COMBO(enable_wide, WIDE_TEXT_EN),
#endif
};

#ifdef MEME_ENABLE
typedef struct taunt_config {
    bool enabled;
} taunt_config_t;

typedef struct wide_config {
    bool enabled;
    bool first;
} wide_config_t;

typedef struct meme_config {
    taunt_config_t taunt;
    wide_config_t  wide;
} meme_config_t;
#endif

void process_bkb_layerchange(uint8_t layer_num) {
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
#ifdef MEME_ENABLE
        case EN_WIDE:
        case EN_TAUNT:
            return 1000;
#endif
        case EN_BASE:
        case EN_FN:
            return 3000;
    }
    return COMBO_TERM;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef MEME_ENABLE
    static meme_config_t meme_config = {.taunt = {.enabled = false}, .wide = {.enabled = false, .first = false}};

    if (meme_config.wide.enabled) {
        if (record->event.pressed) {
            switch (keycode) {
                case KC_A ... KC_0:
                case KC_MINUS ... KC_SLASH:
                case KC_SPC:
                    if (meme_config.wide.first) {
                        meme_config.wide.first = false;
                    } else {
                        send_char(' ');
                    }
                    break;
                case KC_ENT:
                    meme_config.wide.first = true;
                    break;
                case KC_BSPC:
                    send_char('\b'); // backspace
                    break;
            }
        }
    }

    if (meme_config.taunt.enabled) {
        if (record->event.pressed) {
            if (keycode != KC_SPC) {
                register_code(KC_CAPS);
                unregister_code(KC_CAPS);
            }
        }
    }
#endif

    switch (keycode) {
        case BKB_LAYER_BASE:
            if (record->event.pressed) {
                process_bkb_layerchange(_BASE);
            }
            return false;
        case BKB_LAYER_FN:
            if (record->event.pressed) {
                process_bkb_layerchange(_FN);
            }
            return false;
        case BKB_RGB_OFF:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_CUSTOM_MUSE_RGB_OFF);
            }
            return false;
        case BKB_IND_TOG:
            if (record->event.pressed) {
                toggle_lock_key_underglow();
            }
            return false;
        case BKB_USER_TOG:
            if (record->event.pressed) {
                toggle_user_color_for_indicators();
            }
            return false;
        case BKB_RGB_HUE:
            encoder_control.hue = record->event.pressed;
            return false;
        case BKB_RGB_SAT:
            encoder_control.sat = record->event.pressed;
            return false;
        case BKB_RGB_VAL:
            encoder_control.val = record->event.pressed;
            return false;
        case BKB_RGB_SPD:
            encoder_control.speed = record->event.pressed;
            return false;
#ifdef MEME_ENABLE
        case WIDE_TEXT_EN:
            if (record->event.pressed) {
                meme_config.wide.enabled = !meme_config.wide.enabled;
                meme_config.wide.first   = true;
            }
            return false;
        case TAUNT_TEXT_EN:
            if (record->event.pressed) {
                meme_config.taunt.enabled = !meme_config.taunt.enabled;
                if (meme_config.taunt.enabled) {
                    register_code(KC_CAPS);
                    unregister_code(KC_CAPS);
                }
            }
            return false;
#endif
        default:
            break;
    }

    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            if (encoder_control.hue || encoder_control.sat || encoder_control.val || encoder_control.speed) {
                HSV     hsv   = rgb_matrix_get_hsv();
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
            if (encoder_control.hue || encoder_control.sat || encoder_control.val || encoder_control.speed) {
                HSV     hsv   = rgb_matrix_get_hsv();
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
