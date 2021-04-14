#include QMK_KEYBOARD_H
#include "print.h"

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3

#define RGB_SUSTAIN 0.7
#define RGB_PROPAGATE 0.1
#define RGB_HIT 0xff

//static uint16_t last_rgb;
//static uint8_t rgb_state[RGBLED_NUM];

enum my_keycodes {
    RGB_M_RCT
};

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
    LAYER3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_LAYER0] = LAYOUT(KC_ESC, KC_EQL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_DEL, KC_PGUP, KC_GRV, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_HOME, KC_PGDN, KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_LSFT, KC_LBRC, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RBRC, RSFT_T(KC_END), KC_LCTL, KC_LGUI, KC_LALT, MO(2), MO(1), KC_NO, KC_SPC, KC_SPC, KC_NO, KC_BSPC, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),

    [_LAYER1] = LAYOUT(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_VOLU, KC_UNDS, KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_PLUS, KC_TRNS, KC_F1, KC_F4, KC_LCBR, KC_LPRN, KC_F5, KC_UNDS, KC_RPRN, KC_RCBR, KC_F6, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(3), KC_TRNS, KC_VOLD, KC_VOLU, KC_MPLY, KC_MUTE),

    [_LAYER2] = LAYOUT(RESET, KC_TILD, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_VOLD, EEP_RST, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_SPI, RGB_VAI, KC_6, KC_7, KC_8, KC_9, KC_0, KC_LCBR, KC_RCBR, KC_PLUS, KC_TRNS, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_SPD, RGB_VAD, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, KC_TRNS, BL_TOGG, BL_STEP, BL_BRTG, BL_INC, BL_DEC, KC_F11, RGB_M_G, RGB_M_T, RGB_M_RCT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(3), KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_MUTE),

    [_LAYER3] = LAYOUT(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, AU_ON, AU_OFF, AG_NORM, AG_SWAP, TO(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

    };

    const rgblight_segment_t PROGMEM _LAYER1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 2, HSV_RED}
);

const rgblight_segment_t PROGMEM _LAYER2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 2, HSV_BLUE}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(_LAYER1_layer, _LAYER2_layer);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

    //debugs
    //debug_enable = true;
    //debug_keyboard = true;
    //debug_matrix = true;
}


layer_state_t layer_state_set_user(layer_state_t state) {
     rgblight_set_layer_state(0, layer_state_cmp(state, _LAYER1));
     rgblight_set_layer_state(1, layer_state_cmp(state, _LAYER2));
     return state;
}
/*
void matrix_init_user(void) {
    last_rgb = timer_read();
    rgblight_setrgb(0,0,0);

    for (int i = 0; i < RGBLED_NUM; i++) {
        rgb_state[i] = 0;
    }

}*/

void matrix_scan_user(void) {
    #ifdef RGBLIGHT_ENABLE
    /*

    if (timer_elapsed(last_rgb) > 20) {
        last_rgb = timer_read();

        uint8_t next_rgb_state[RGBLED_NUM];
        for (int i = 0; i < RGBLED_NUM; i++) {
            // retain some
            next_rgb_state[i] = rgb_state[i] * RGB_SUSTAIN;

            //accept some from neighbours

            //lower neighbour, excl lower bound of each hand
            if (i != 0 && i != RGBLED_NUM / 2){
            next_rgb_state[i] += rgb_state[i-1] * RGB_PROPAGATE;
            }

            if (i != RGBLED_NUM / 2 - 1 && i != RGBLED_NUM -1){
            next_rgb_state[i] += rgb_state[i+1] * RGB_PROPAGATE;
            }
        }

        // assign new state
        for (int i = 0; i < RGBLED_NUM; i++){
            rgb_state[i] = next_rgb_state[i];
            led[i].r = rgb_state[i];
        }
        rgblight_set();
    }
    */
    #endif //RGBLIGHT_ENBLE

 }

 bool process_record_user(uint16_t keycode, keyrecord_t *record){

    switch (keycode){
        case (RGB_M_RCT):
            if (record->event.pressed){
                rgblight_mode((uint8_t)RGB_MODE_REACT);
                return false;
            }
        default:
            return true;
    }


 #ifdef RGBLIGHT_ENABLE 
    //bump the level of the led that corresponds to this key

   //keypos_t key = record->event.key;

   //rh
  // if (key.row >= 5) {
 //      rgb_state[ (6-key.col)] = RGB_HIT;
 //  } else {
   //lh
  //     rgb_state[key.col] = RGB_HIT;
  //}
    

#endif
return true;
}
