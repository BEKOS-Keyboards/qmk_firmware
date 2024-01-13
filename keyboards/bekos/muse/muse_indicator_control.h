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


#define CAPS_LOCK_KEY_LED	61 //Specific LED in Matrix (Row 4, Index 0)
#define CAPS_LOCK_LED 		DRIVER_LED_TOTAL-5

#define NUM_LOCK_KEY_LED 	36 //Specific LED in Matrix (Row 2, Index 17)
#define NUM_LOCK_LED  		DRIVER_LED_TOTAL-4

#define SCROLL_LOCK_KEY_LED 14 //Specific LED in Matrix (Row 1, Index 14)
#define SCROLL_LOCK_LED 	DRIVER_LED_TOTAL-3


#define COMPOSE_LED 		DRIVER_LED_TOTAL-2
#define KANA_LED			DRIVER_LED_TOTAL-1
