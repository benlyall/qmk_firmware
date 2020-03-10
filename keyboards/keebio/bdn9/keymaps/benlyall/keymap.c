/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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
#include "benlyall.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAIN] = LAYOUT(
  //┌────────┬────────┬─────────┐
     LDBG,    STRT,    LSRCH,
  //├────────┼────────┼────────┤
     CMDP,    CMDP,    FSCRN,
  //├────────┼────────┼────────┤
     GDEFN,   SREFN,   PDEFN
  //└────────┴────────┴────────┘
  ),
  [_DEBUG] = LAYOUT(
  //┌────────┬────────┬─────────┐
     _______,  STRT,   _______,
  //├────────┼────────┼────────┤
     TGBRK,   STOP,    SHDBG,
  //├────────┼────────┼────────┤
     STIN,    STOVR,   STOUT
  //└────────┴────────┴────────┘
  ),
  [_SEARCH] = LAYOUT(
  //┌────────┬────────┬─────────┐
     _______, _______, LSRCH,
  //├────────┼────────┼────────┤
     FNFL,    FNFL,    _______,
  //├────────┼────────┼────────┤
     RPLC,    RPFL,    _______
  //└────────┴────────┴────────┘
  )
};


void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code16(VSCBCK);
        } else {
            tap_code16(VSCFWD);
        }
    } else {
        switch (get_highest_layer(layer_state)) {
            case _MAIN:
                if (clockwise) {
                    EG_PREV;
                } else {
                    EG_NEXT;
                }
                break;
            case _DEBUG:
                if (clockwise) {
                    EG_PREV;
                } else {
                    EG_NEXT;
                }
                break;
            case _SEARCH:
                if (clockwise) {
                    tap_code16(FD_PREV);
                } else {
                    tap_code16(FD_PREV);
                }
                break;
            default:
                break;
        }
    }
}
