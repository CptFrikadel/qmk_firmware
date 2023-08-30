#include QMK_KEYBOARD_H
#include "features/layer_lock.h"

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3

enum custom_keycodes {
    LLOCK = SAFE_RANGE,
};

void keyboard_pre_init_user(void){

    // Turn of LED after initialize
    setPinOutput(24);
    writePinHigh(24);
}


bool process_record_user(uint16_t keycode, keyrecord_t* record){

    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }

    return true;
}


 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_LAYER0] = LAYOUT(
         KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,                  KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
         KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                  KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS,
         KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G,                  KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
         KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LBRC,    KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RCTL,
                        KC_LCTL, KC_LGUI, MO(1), KC_ENT,    KC_SPC, MO(2), KC_BSPC, KC_RALT),

[_LAYER1] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, KC_DEL,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                          KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
        _______, _______, _______, _______, _______, _______, _______,      _______, KC_NO, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                                   _______, _______, _______, _______,      _______, MO(3), _______, _______),


[_LAYER2] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        KC_CAPS, KC_F1,   KC_F3,   KC_F4,   KC_PGUP, KC_HOME,                        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   LLOCK,
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_PGDN, KC_END, _______,       _______, KC_PLUS, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
                                   _______, _______, MO(3),  _______,       _______, _______, _______, _______),


[_LAYER3] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                          KC_NO,   KC_NO,   RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,          KC_NO,   LLOCK,   KC_NO,   RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,
                                   _______, _______, _______, _______,      _______, _______, _______, _______)

};
