/* Copyright 2017 Wunder
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
#include "xd75.h"

//00 Macro
enum custom_keycodes {
  DOUBLE_ZERO = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case DOUBLE_ZERO:
        SEND_STRING("00");
          return false;
    }
  }
  return true;
};

// Layer shorthand
#define _BASE 0
#define _FN 1

#define KC_ KC_TRNS
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_FN LT(_FN, KC_NO)
#define KC_RST RESET
#define KC_DBUG DEBUG
#define KC_RTOG RGB_TOG
#define KC_RMDN RGB_MOD
#define KC_RMDP RGB_RMOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD
#define KC_P00  DOUBLE_ZERO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = KC_KEYMAP(
  //,----+----+----+----+----+----+----+----+----+----+----+----+----+----+----.
      GRV,  1 ,  2 ,  3 ,  4 ,  5 ,MINS,TILD, EQL,  6 ,  7 ,  8 ,  9 ,  0 , DEL,
  //|----+----+----+----+----+----+----+----+----+----+----+----+----+----+----|
      TAB, Q  , W  , E  , R  , T  ,LBRC,BSLS,RBRC, Y  , U  , I  , O  , P  ,BSPC,
  //|----+----+----+----+----+----+----+----+----+----+----+----+----+----+----|
      ESC, A  , S  , D  , F  , G  ,LCBR,PIPE,RCBR, H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----+----+----+----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,UNDS, UP ,PLUS,  N  , M  ,COMM,DOT,SLSH,PGUP,
  //|----+----+----+----+----+----+----+----+----+----+----+----+----+----+----|
     LCTL,LGUI,LALT, FN ,LSFT, ENT,LEFT,DOWN,RIGHT,SPC,RSFT, FN ,HOME, END,PGDN
  //`----+----+----+----+----+----+----+----+----+----+----+----+----+----+----'
  ),

    [_FN] = KC_KEYMAP(
  //,----+----+----+----+----+----+----+----+----+----+----+----+----+----+----.
      F1 , F2 , F3 , F4 , F5 , F6 ,NLCK,SLSH,ASTR, F7 , F8 , F9 , F10, F11, F12,
  //|----+----+----+----+----+----+----+----+----+----+----+----+----+----+----|
         ,PSCR,SLCK,PAUS,    ,    , P7 , P8 , P9 ,MINS,BSPC,RSAI,RHUI,RVAI,    ,
  //|----+----+----+----+----+----+----+----+----+----+----+----+----+----+----|
         ,MPRV,MPLY,MNXT,MSTP,WREF, P4 , P5 , P6 ,PLUS,    ,RSAD,RHUD,RVAD,    ,
  //|----+----+----+----+----+----+----+----+----+----+----+----+----+----+----|
         ,VOLD,MUTE,VOLD,WBAK,WFWD, P1 , P2 , P3 ,PENT,    ,RTOG,RMDN,RMDP,    ,
  //|----+----+----+----+----+----+----+----+----+----+----+----+----+----+----|
         ,    ,    ,    ,    ,    , P00, P0 ,PDOT,    ,    ,    ,    ,    ,
  //`----+----+----+----+----+----+----+----+----+----+----+----+----+----+----'
  ),
  };

const uint16_t PROGMEM fn_actions[] = {

};
