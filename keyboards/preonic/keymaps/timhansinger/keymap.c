/* Copyright 2015-2021 Jack Humbert
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

#include "color.h"
#include "keycode.h"
#include "keycode_legacy.h"
//#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _GAME,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NAV,
  _NAV2,
  _NUM,
  _UMLAUTQ,
  _UMLAUTD
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  GAME,
  DVORAK,
  LOWER,
  RAISE,
  BACKLIT,
  LOW_TAB,
  LOW_SPC,
  MY_UE, // ü
  MY_OE, // ö
  MY_AE, // ä
  MY_SS, // ß
  MYDOLTL, // $ ~
  MYSHBT, // | `
  MYEXCPT, // ! %
  MYBSHSH, // \ #
  MYATCIR // @ ^
};

// Define combos (Super Duper)
#define COMBO_ONLY_FROM_LAYER _QWERTY

enum myCombos {
  SD_LAYER,
  KL_LAYER,
  OE_LAYER,
  TN_LAYER,
  XC_LAYER,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

// Combos for QWERTY
const uint16_t PROGMEM sd_combo[] = {KC_S, LALT_T(KC_D), COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_L, RALT_T(KC_K), COMBO_END};
const uint16_t PROGMEM xc_combo[] = {LT(0, KC_X), LT(0, KC_C), COMBO_END};
// Combos for DVORAK
const uint16_t PROGMEM oe_combo[] = {KC_O, LALT_T(KC_E), COMBO_END};
const uint16_t PROGMEM tn_combo[] = {KC_N, RALT_T(KC_T), COMBO_END};

combo_t key_combos[] = {
  [SD_LAYER] = COMBO(sd_combo, MO(_NAV)),
  [KL_LAYER] = COMBO(kl_combo, LM(_NAV2, MOD_LGUI)),
  [XC_LAYER] = COMBO(xc_combo, MO(_NUM)),
  [OE_LAYER] = COMBO(oe_combo, MO(_NAV)),
  [TN_LAYER] = COMBO(tn_combo, LM(_NAV2, MOD_LGUI)),
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */



//const key_override_t shift_space_override = ko_make_basic(MOD_MASK_SHIFT, KC_SPC, KC_BSPC);

// This globally defines all key overrides to be used
//const key_override_t **key_overrides = (const key_override_t *[]){
//    //&shift_space_override,
//    NULL // Null terminate the array of overrides!
//};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Define key presses
#define HYP_TAB ALL_T(KC_TAB)
//#define HYP_BSLS ALL_T(KC_BSLS)
#define HYP_ENT ALL_T(KC_ENT)
#define CTL_ESC LCTL_T(KC_ESC)
//#define CTL_QUOT LCTL_T(KC_QUOT)
#define CTL_MINS LCTL_T(KC_MINS)
//#define SFT_BSPC LSFT_T(KC_BSPC)
//#define SFT_DEL RSFT_T(KC_DEL)
#define LGUI_F LGUI_T(KC_F)
#define LGUI_U LGUI_T(KC_U)
#define LALT_D LALT_T(KC_D)
#define LALT_E LALT_T(KC_E)
#define RGUI_J RGUI_T(KC_J)
#define RGUI_H RGUI_T(KC_H)
#define RALT_K RALT_T(KC_K)
#define RALTT RALT_T(KC_T)
//#define ALT_ENT LALT_T(KC_ENT)

//#define NAV_D LT(_NAV, KC_D) // D when tapped, NAV_Layer when held
//#define NAV_S LT(_NAV, KC_S) // S when tapped, NAV_Layer when held
//#define NAV_SPC LT(_NAV, KC_SPC) // Space when tapped, NAV_Layer when held
#define OSM_SFT OSM(MOD_LSFT)
//#define GUI_SPC LT(0, KC_SPC)
#define GUI_Z LT(0, KC_Z)
#define GUI_X LT(0, KC_X)
#define GUI_C LT(0, KC_C)
#define GUI_V LT(0, KC_V)
//#define GUI_Q LT(0, KC_Q)
//#define GUI_W LT(0, KC_W)
//#define GUIT LT(0, KC_T)

//#define G_LEFT LT(0, KC_LEFT)
//#define G_RGHT LT(0, KC_RGHT)
//#define G_UP LT(0, KC_UP)
//#define G_DOWN LT(0, KC_DOWN)

#define PRE_TAB G(S(KC_LBRC))
#define NEX_TAB G(S(KC_RBRC))
#define PRE_WRD A(KC_LEFT)
#define NEX_WRD A(KC_RIGHT)

//#define F_LM LM(_TIMMOD, MOD_LGUI)
//#define LGUI_BS LGUI_T(KC_BSLS)

#define UMLAUTQ MO(_UMLAUTQ)
#define UMLAUTD MO(_UMLAUTD)
#define G_SPC G(KC_SPC)

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  HYP_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT, //MYBSHSH,
  CTL_ESC, KC_A,    KC_S,    LALT_D,  LGUI_F,  KC_G,    KC_H,    RGUI_J,  RALT_K,  KC_L,    KC_SCLN, CTL_MINS,
  KC_BSPC, GUI_Z,   GUI_X,   GUI_C,   GUI_V,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, HYP_ENT,
  UMLAUTQ, KC_LCTL, MYDOLTL, MYBSHSH, G_SPC,   LOW_SPC, OSM_SFT, RAISE,   KC_SLSH, MYATCIR, KC_UP,   UMLAUTQ
),

[_GAME] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_NAV] = LAYOUT_preonic_grid(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, PRE_WRD, PRE_TAB, NEX_TAB, NEX_WRD, XXXXXXX,
  _______, KC_LALT, _______, _______, KC_LGUI, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC, KC_DEL,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB,  KC_LSFT, KC_LSFT, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[_NAV2] = LAYOUT_preonic_grid(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, KC_W,    KC_Q,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, KC_LSFT, KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, KC_H,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[_UMLAUTQ] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, MY_UE,   _______, MY_OE,   _______, _______,
  _______, MY_AE,   MY_SS,   _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_UMLAUTD] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, MY_AE,   MY_OE,   _______, MY_UE,   _______, _______, _______, _______, _______, MY_SS,   _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Dvorak - Real Programmers Dvorak (use with Keymap from ThePrimeagen)
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_preonic_grid(
  KC_DLR,  KC_PLUS, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR, KC_EQL,  KC_RPRN, KC_RCBR, KC_RBRC, KC_ASTR, KC_EXLM,
  HYP_TAB, KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    GUI_C,   KC_R,    KC_L,    MYBSHSH,
  CTL_ESC, KC_A,    KC_O,    LALT_E,  LGUI_U,  KC_I,    KC_D,    RGUI_H,  RALTT,   KC_N,    KC_S,    CTL_MINS,
  KC_BSPC, KC_QUOT, KC_Q,    KC_J,    KC_K,    GUI_X,   KC_B,    KC_M,    KC_W,    GUI_V,   GUI_Z,   HYP_ENT,
  UMLAUTD, KC_LCTL, MYDOLTL, MYBSHSH, G_SPC,  LOW_SPC,  OSM_SFT, RAISE,   KC_SLSH, MYATCIR, KC_UP,   UMLAUTD
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PERC,
  KC_PIPE, KC_PLUS, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR, KC_EQL,  KC_RPRN, KC_RCBR, KC_RBRC, KC_ASTR, KC_EXLM,
  KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
  KC_DEL,  _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / | Pg Up| Pg Dn|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
[_RAISE] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),
 */
// THIS WILL BE THE YABAI WINDOW MANAGEMENT LAYER
[_RAISE] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
[_NUM] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, KC_NUM,  _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PAST, _______,
  _______, _______, _______, _______, _______, _______, KC_PMNS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______,
  _______, _______, _______, _______, _______, _______, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PEQL, _______,
  XXXXXXX, _______, _______, _______, _______, _______, _______, KC_P0,   KC_COMM, KC_PDOT, XXXXXXX, XXXXXXX
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  GAME,    DVORAK,  _______, _______,
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, BACKLIT
)


};

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // custom timer
  //static uint16_t low_bspc_timer;
  static uint16_t low_tab_timer;
  static uint16_t low_spc_timer;
  //static bool button_pressed;
  static uint16_t kc;
  mod_state = get_mods();

  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case GAME:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_GAME);
          }
          return false;
          break;
        case DVORAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_DVORAK);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;

        case LT(0, KC_SPC):
          if (record->tap.count && record->event.pressed) {
            if ((get_mods() & MOD_BIT(KC_LGUI)) == MOD_BIT(KC_LGUI)) {
              tap_code16(KC_LSFT); // Send LSHFT if LGUI is pressed (for App Switcher)
            } else {
              tap_code16(KC_SPC); // Send Space otherwise
            }
          } else if (record->event.pressed) {
            tap_code16(G(KC_SPC)); // Intercept hold function to send Cmd-SPC
          }
          return false;
        case LT(0, KC_Q):
          if (!record->tap.count && record->event.pressed) {
            tap_code16(G(KC_Q)); // Intercept hold function to send Cmd-Q
            return false;
          }
          return true;
        case LT(0, KC_W):
          if (!record->tap.count && record->event.pressed) {
            tap_code16(G(KC_W)); // Intercept hold function to send Cmd-W
            return false;
          }
          return true;
        case LT(0, KC_Z):
          if (!record->tap.count && record->event.pressed) {
            tap_code16(G(KC_Z));
            return false;
          }
          return true;
        case LT(0, KC_X):
          if (!record->tap.count && record->event.pressed) {
            tap_code16(G(KC_X));
            return false;
          }
          return true;
        case LT(0, KC_C):
          if (!record->tap.count && record->event.pressed) {
            tap_code16(G(KC_C));
            return false;
          }
          return true;
        case LT(0, KC_V):
          if (!record->tap.count && record->event.pressed) {
            tap_code16(G(KC_V));
            return false;
          }
          return true;
        case LT(0, KC_T):
          if (!record->tap.count && record->event.pressed) {
            tap_code16(G(KC_T));
            return false;
          }
          return true;

        case LT(0, KC_LEFT):
          if (!record->tap.count && record->event.pressed) {
            tap_code16(G(KC_LEFT));
            return false;
          }
          return true;
        case LT(0, KC_RIGHT):
          if (!record->tap.count && record->event.pressed) {
            tap_code16(G(KC_RIGHT));
            return false;
          }
          return true;
        case LT(0, KC_UP):
          if (!record->tap.count && record->event.pressed) {
            tap_code16(G(KC_UP));
            return false;
          }
          return true;
        case LT(0, KC_DOWN):
          if (!record->tap.count && record->event.pressed) {
            tap_code16(G(KC_DOWN));
            return false;
          }
          return true;

        //case LOW_BSPC:
        //  if (record->event.pressed) {
        //    low_bspc_timer = timer_read();
        //    layer_on(_LOWER);
        //    update_tri_layer(_LOWER, _RAISE, _ADJUST);
        //  } else {
        //    layer_off(_LOWER);
        //    update_tri_layer(_LOWER, _RAISE, _ADJUST);
        //    if (timer_elapsed(low_bspc_timer) < TAPPING_TERM) {
        //      register_code(KC_BSPC);
        //      unregister_code(KC_BSPC);
        //    }
        //  }
        //  return false;
        //  break;

        case LOW_SPC:
          if (record->event.pressed) {
            low_spc_timer = timer_read();
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
            if (timer_elapsed(low_spc_timer) < TAPPING_TERM) {
              register_code(KC_SPC);
              unregister_code(KC_SPC);
            }
          }
          return false;
          break;
        case LOW_TAB:
          if (record->event.pressed) {
            low_tab_timer = timer_read();
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
            if (timer_elapsed(low_tab_timer) < TAPPING_TERM) {
              register_code(KC_TAB);
              unregister_code(KC_TAB);
            }
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef RGBLIGHT_ENABLE
              if (rgblight_is_enabled()) {
                rgblight_toggle();
              } else {
                rgblight_enable(); // Enables RGB, without saving settings
                //rgblight_sethsv_noeeprom(HSV_PURPLE);
                rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
                rgblight_setrgb(RGB_PURPLE);
                //rgblight_sethsv(HSV_GREEN);
                //rgblight_setrgb_at(RGB_GOLD, 3);
              }
            #endif
            #ifdef __AVR__
              writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
              writePinHigh(E6);
            #endif
          }
          return false;
          break;
        //case MY_DUMMY:
        //  if (record->event.pressed) {
        //  } else {
        //  }
        //  return false;
        //  break;
        case MY_AE:
          //static uint8_t kc;
          if (record->event.pressed) {
            // get_oneshot_mods only works since I only use SHIFT as OSM
            if (mod_state & MOD_MASK_SHIFT || (get_oneshot_mods() && !has_oneshot_mods_timed_out())) {
              del_mods(MOD_MASK_SHIFT);
              clear_oneshot_mods();
              //kc = KC_DOWN;
              register_code(KC_RALT);
              register_code(KC_U);
              unregister_code(KC_U);
              unregister_code(KC_RALT);
              register_code(KC_LSFT);
              register_code(KC_A);
              unregister_code(KC_A);
              unregister_code(KC_LSFT);
              set_mods(mod_state);
            } else {
              //kc = KC_UP;
              register_code(KC_RALT);
              register_code(KC_U);
              unregister_code(KC_U);
              unregister_code(KC_RALT);
              register_code(KC_A);
              unregister_code(KC_A);
            }
            //register_code(kc);
          } else {
            //unregister_code(kc);
          }
          return false;
          break;
        case MY_UE:
          //static uint8_t kc;
          if (record->event.pressed) {
            // get_oneshot_mods only works since I only use SHIFT as OSM
            if (mod_state & MOD_MASK_SHIFT || (get_oneshot_mods() && !has_oneshot_mods_timed_out())) {
              del_mods(MOD_MASK_SHIFT);
              clear_oneshot_mods();
              //kc = KC_DOWN;
              register_code(KC_RALT);
              register_code(KC_U);
              unregister_code(KC_U);
              unregister_code(KC_RALT);
              register_code(KC_LSFT);
              register_code(KC_U);
              unregister_code(KC_U);
              unregister_code(KC_LSFT);
              set_mods(mod_state);
            } else {
              //kc = KC_UP;
              register_code(KC_RALT);
              register_code(KC_U);
              unregister_code(KC_U);
              unregister_code(KC_RALT);
              register_code(KC_U);
              unregister_code(KC_U);
            }
            //register_code(kc);
          } else {
            //unregister_code(kc);
          }
          return false;
          break;
        case MY_OE:
          //static uint8_t kc;
          if (record->event.pressed) {
            // get_oneshot_mods only works since I only use SHIFT as OSM
            if (mod_state & MOD_MASK_SHIFT || (get_oneshot_mods() && !has_oneshot_mods_timed_out())) {
              del_mods(MOD_MASK_SHIFT);
              clear_oneshot_mods();
              //kc = KC_DOWN;
              register_code(KC_RALT);
              register_code(KC_U);
              unregister_code(KC_U);
              unregister_code(KC_RALT);
              register_code(KC_LSFT);
              register_code(KC_O);
              unregister_code(KC_O);
              unregister_code(KC_LSFT);
              set_mods(mod_state);
            } else {
              //kc = KC_UP;
              register_code(KC_RALT);
              register_code(KC_U);
              unregister_code(KC_U);
              unregister_code(KC_RALT);
              register_code(KC_O);
              unregister_code(KC_O);
            }
            //register_code(kc);
          } else {
            //unregister_code(kc);
          }
          return false;
          break;

        case MY_SS:
          //static uint8_t kc;
          if (record->event.pressed) {
            // get_oneshot_mods only works since I only use SHIFT as OSM
            if (mod_state & MOD_MASK_SHIFT || (get_oneshot_mods() && !has_oneshot_mods_timed_out())) {
              del_mods(MOD_MASK_SHIFT);
              clear_oneshot_mods();
              //kc = KC_DOWN;
              register_code(KC_LSFT);
              register_code(KC_S);
              unregister_code(KC_S);
              register_code(KC_S);
              unregister_code(KC_S);
              unregister_code(KC_LSFT);
              set_mods(mod_state);
            } else {
              //kc = KC_UP;
              register_code(KC_RALT);
              register_code(KC_S);
              unregister_code(KC_S);
              unregister_code(KC_RALT);
            }
            //register_code(kc);
          } else {
            //unregister_code(kc);
          }
          return false;
          break;

        case MYDOLTL:
          if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT || (get_oneshot_mods() && !has_oneshot_mods_timed_out())) {
              kc = KC_TILD;
              register_code(kc);
              unregister_code(kc);
            } else {
              kc = KC_DLR;
              register_code(KC_LSFT);
              register_code(kc);
              unregister_code(kc);
              unregister_code(KC_LSFT);
            }
          } else {
          }
          return false;
          break;
        case MYSHBT:
          if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT || (get_oneshot_mods() && !has_oneshot_mods_timed_out())) {
              kc = KC_GRAVE;
              del_mods(MOD_MASK_SHIFT);
              clear_oneshot_mods();
              register_code(kc);
              unregister_code(kc);
              set_mods(mod_state);
            } else {
              kc = KC_PIPE;
              register_code(KC_LSFT);
              register_code(kc);
              unregister_code(kc);
              unregister_code(KC_LSFT);
            }
          } else {
          }
          return false;
          break;
        case MYEXCPT:
          if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT || (get_oneshot_mods() && !has_oneshot_mods_timed_out())) {
              kc = KC_PERC;
              //del_mods(MOD_MASK_SHIFT);
              //clear_oneshot_mods();
              register_code(kc);
              unregister_code(kc);
              //set_mods(mod_state);
            } else {
              kc = KC_EXLM;
              register_code(KC_LSFT);
              register_code(kc);
              unregister_code(kc);
              unregister_code(KC_LSFT);
            }
          } else {
          }
          return false;
          break;
        case MYBSHSH:
          if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT || (get_oneshot_mods() && !has_oneshot_mods_timed_out())) {
              kc = KC_HASH;
              //del_mods(MOD_MASK_SHIFT);
              //clear_oneshot_mods();
              register_code(kc);
              unregister_code(kc);
              //set_mods(mod_state);
            } else {
              kc = KC_BSLASH;
              register_code(kc);
              unregister_code(kc);
            }
          } else {
          }
          return false;
          break;
        case MYATCIR:
          if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT || (get_oneshot_mods() && !has_oneshot_mods_timed_out())) {
              kc = KC_CIRC;
              //del_mods(MOD_MASK_SHIFT);
              //clear_oneshot_mods();
              register_code(kc);
              unregister_code(kc);
              //set_mods(mod_state);
            } else {
              kc = KC_AT;
              register_code(KC_LSFT);
              register_code(kc);
              unregister_code(kc);
              unregister_code(KC_LSFT);
            }
          } else {
          }
          return false;
          break;

        //case gg_G:
        //  if (record->event.pressed) {
        //    if (keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT)) {
        //        register_mods(mod_config(MOD_LGUI));
        //        tap_code(KC_DOWN);
        //        unregister_mods(mod_config(MOD_LGUI));
        //    }
        //  }
        //  return false;
        //  break;
      }
    return true;
};

// COMBO Key Events
/*
void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case SD_LAYER2:
      if (pressed) {
        layer_invert(_NAV);
      }
      break;
  }
}
*/

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable(); // Enables RGB, without saving settings
  rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
  rgblight_setrgb(RGB_PURPLE);
}
#endif

