/*
Copyright 2019 I/O Keyboards <hello@iokeyboards.eu>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN,
    _MEDIA,
    _DEB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_all(
  KC_F1,   KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_MINS,  KC_EQL,  KC_BSPC, KC_GRV,  KC_MPLY,
  KC_F2,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_LBRC, KC_RBRC,  KC_BSLS,          KC_DEL,
  KC_F3,   KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN, KC_QUOT,  KC_BSLS, KC_ENT,           MO(1),
  KC_F4,   KC_LSFT, KC_GRV, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT, KC_UP,            MO(2),
  KC_LGUI, KC_LCTL, KC_LALT,                                     KC_SPC,                      	    KC_RALT, MO(1),             KC_LEFT, KC_DOWN, KC_RGHT),

[_FN] = LAYOUT_all(
  KC_F5,  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,  MO(3),
  KC_F6,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           XXXXXXX,
  KC_F7,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           XXXXXXX,
  KC_F8,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           XXXXXXX,
  KC_F9, _______, _______,                                     _______,                       	    _______, _______,          _______, _______, _______),

[_MEDIA] = LAYOUT_all(
  KC_WHOM, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  MO(3),
  KC_CALC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           XXXXXXX,
  KC_MAIL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           XXXXXXX,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU,           XXXXXXX,
  _______, _______, _______,                                     KC_MPLY,                      	     _______, _______,          _______, KC_VOLD, _______),

[_DEB] = LAYOUT_all(
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  QK_RBT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX,                            XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX)

};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    }
    return false;
}

layer_state_t  layer_state_set_user(layer_state_t state) {
  switch (state) {
  case _BASE:
    uprintf("layer:base\n");
    break;
  case _FN:
    uprintf("layer:fn\n");
    break;
  case _MEDIA:
    uprintf("layer:media");
    break;
  }
  return state;
}