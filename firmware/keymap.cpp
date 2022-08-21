/*
Copyright 2018-2021 <Pierre Constantineau>
Copyright (C) 2020 Jocelyn Turcotte <turcotte.j@gmail.com>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include "keymap.h"

std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    KEYMAP2ARRAY(KEYMAP(
         KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
         KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
         KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
              KC_NO,  KC_NO,  KC_NO, KC_NO,
        // left thumb
                              KC_NO, KC_NO,
                                       KC_NO,
                     KC_NO,  KC_NO,  KC_NO,
        // right hand
         KC_NO, KC_NO,  KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_NO,
         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_NO,
         KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_NO, KC_NO,
         KC_NO,    KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,
              KC_NO, KC_NO, KC_NO, KC_NO,
        // right thumb
        KC_NO, KC_NO,
        KC_NO,
        KC_NO,  KC_NO,  KC_NO 
    ));

void setupKeymapQwerty() {
    uint32_t qwerty[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
         KC_ESC,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
         KC_EQL,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
         KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
         KC_LCTRL,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
         KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
              KC_GRV,  KC_INS,  KC_LEFT, KC_RGHT,
        // left thumb
                              KC_LGUI, KC_LALT,
                                       KC_HOME,
                     KC_BSPC,  KC_DEL,  KC_END,
        // right hand
         KC_F9, KC_F10,  KC_F11,  KC_F12, KC_PSCR, KC_SLCK, KC_PAUS, KC_NO, KMDVORAK,
         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
              KC_UP, KC_DOWN, KC_LBRC, KC_RBRC,
        // right thumb
        KC_RCTRL, KC_RGUI,
        KC_PGUP,
        KC_PGDN,  KC_ENT,  KC_SPC 
    );
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_L0, Method::PRESS, qwerty[row][col]);
        }
    }
    //matrix[0][2].addActivation(_L0, Method::DT_TAP, KC_ESC); 
    if (keyboard_config.BLEProfile == 1) {
        // This is overiding printscreen
        // see keyboard_config.h to xref--start with the lower matrix for the indices, then go to the upper macro for the logical layout
        matrix[14][5].addActivation(_L0, Method::MT_TAP, BLEPROFILE_2); 
    } else {
        matrix[14][5].addActivation(_L0, Method::MT_TAP, BLEPROFILE_1); 
    }
}

void setupKeymapDvorak() {
    // Although David observed the DT_TAP to be more reliable for sending the escape onboard, it still doesn't feel glitch-free as karabiner
    uint32_t dvorak[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
         KC_ESC,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
         KC_EQUAL,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
         KC_TAB, KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,
         KC_CAPSLOCK,     KC_A,    KC_O,    KC_E,    KC_U,    KC_I,
         KC_LSHIFT, KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,
             KC_GRV,  KC_LALT,  KC_LEFT, KC_RIGHT,
        // left thumb
                              KC_LGUI, KC_LALT,
                                       KC_HOME,
                     KC_BSPC, KC_DELETE, KC_END,
        // right hand
         KC_F9, KC_F10,  KC_F11,  KC_F12,  KC_PSCREEN, KC_SCROLLLOCK,  KC_PAUSE,  KC_NO, KMQWERTY,
         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSLASH,
         KC_F,    KC_G,    KC_C,    KC_R,    KC_L,  KC_SLSH,
         KC_D,    KC_H,    KC_T,    KC_N,    KC_S, KC_MINS,
         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, KC_RSHIFT,
             KC_UP, KC_DOWN, KC_LBRC, KC_RBRC,
        // right thumb
        KC_RCTRL, KC_RGUI,
        KC_PGUP,
        KC_PGDN,  KC_ENTER,  KC_SPC 
    );
    //matrix[0][2].addActivation(_L0, Method::DT_TAP, KC_ESC); 
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_L0, Method::PRESS, dvorak[row][col]);

        }
    }
    if (keyboard_config.BLEProfile == 1) {
        // This is overiding printscreen
        // see keyboard_config.h to xref--start with the lower matrix for the indices, then go to the upper macro for the logical layout
        matrix[14][5].addActivation(_L0, Method::MT_TAP, BLEPROFILE_2); 
    } else {
        matrix[14][5].addActivation(_L0, Method::MT_TAP, BLEPROFILE_1); 
    }
};

void setupKeymap() {
#ifdef IS_DAVID
    setupKeymapDvorak();
#else
    setupKeymapQwerty();
#endif
}


void process_user_macros(uint16_t macroid)
{
    switch ((macroid))
    { 
        case KMQWERTY:
            setupKeymapQwerty();
            break;
        case KMDVORAK:
            setupKeymapDvorak();
            break;
    }
}
