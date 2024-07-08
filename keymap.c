#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};

enum voyager_layers  {
    _COLEMAK,
    _CODE_FUNC,
    _NUMPAD,
    _TXT_NAV,
    _MOUSE,
    _APP,
    _FUNC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_COLEMAK] = LAYOUT_moonlander(
    KC_ESCAPE,          KC_LBRC,            KC_LPRN,            KC_MINUS,               KC_RPRN,            KC_RBRC,    KC_TRANSPARENT,
    KC_TRANSPARENT,     KC_TRANSPARENT,     KC_SLASH,           KC_QUES,                KC_BSLS,            KC_EQUAL,   KC_BSPC,

    KC_GRAVE,           KC_Q,               KC_W,               KC_F,                   KC_P,               KC_G,       KC_TRANSPARENT,
    KC_TRANSPARENT,     KC_J,               KC_L,               KC_U,                   KC_Y,               KC_SCLN,    KC_PIPE,

    KC_PLUS,            KC_A,               KC_R,               LT(_MOUSE, KC_S),       LT(_NUMPAD, KC_T),  KC_D,       KC_TRANSPARENT,
    KC_TRANSPARENT,     KC_H,               LT(_NUMPAD, KC_N),  LT(_CODE_FUNC, KC_E),   LT(_FUNC, KC_I),    KC_O,       KC_QUOTE,

    KC_LEFT_ALT,        KC_Z,               KC_X,               KC_C,                   KC_V,               KC_B,
    KC_K,               KC_M,               KC_COMMA,           KC_DOT,                 KC_SLASH,           KC_PIPE,

    KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,
    KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,

    KC_TRANSPARENT,     LT(_APP, KC_SPACE),         KC_LEFT_SHIFT,
    KC_RIGHT_GUI,       MT(MOD_LCTL, KC_ENTER),     KC_TRANSPARENT
 ),
 [_CODE_FUNC]= LAYOUT_moonlander(
    KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,
    KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,

    KC_TRANSPARENT,     KC_QUES,            KC_ASTR,            KC_HASH,            KC_PERC,            KC_PLUS,            KC_TRANSPARENT,
    KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,

    KC_TRANSPARENT,     KC_AT,              KC_AMPR,            KC_DLR,             KC_TILD,            KC_MINUS,           KC_TRANSPARENT,
    KC_TRANSPARENT,     KC_CIRC,            KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,

    KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_LABK,            KC_RABK,            KC_TRANSPARENT,
    KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,

    KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,
    KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,

    KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,
    KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT
 ),
 [_NUMPAD] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_PLUS,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_MINUS,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           LALT(LGUI(LCTL(LSFT(KC_X)))),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_0, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
 ),
 [_TXT_NAV] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, LGUI(KC_B),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PAGE_UP,     LSFT(KC_TAB),   KC_UP,          KC_TAB,         KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PGDN,        KC_LEFT,        LALT(KC_UP),    KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, LGUI(KC_C),     LGUI(KC_V),     KC_DOWN,        KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
 ),
 [_MOUSE] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_MS_WH_LEFT,  KC_MS_BTN3,     KC_MS_WH_RIGHT, KC_NO,          KC_NO,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_MS_WH_UP,    KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     KC_NO,          KC_NO,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_NO,          KC_NO,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_RIGHT_SHIFT, LGUI(KC_LBRC),  KC_NO,          LGUI(KC_RBRC),  KC_NO,          KC_NO,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                        KC_MS_BTN1,     KC_MS_BTN2,     KC_TRANSPARENT
 ),
 [_APP] = LAYOUT_moonlander(
        KC_TRANSPARENT,     KC_TRANSPARENT,                 LCTL(LSFT(KC_TAB)),             KC_TRANSPARENT,                 LCTL(KC_TAB),                   KC_TRANSPARENT,                 KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,                 LGUI(LSFT(KC_GRAVE)),           LALT(LCTL(KC_F3)),              LGUI(KC_GRAVE),                 KC_TRANSPARENT,                 KC_TRANSPARENT,

        KC_TRANSPARENT,     KC_TRANSPARENT,                 LALT(LGUI(LCTL(LSFT(KC_W)))),   LALT(LGUI(LCTL(LSFT(KC_F)))),   LALT(LGUI(LCTL(LSFT(KC_P)))),   LALT(LGUI(LCTL(LSFT(KC_G)))),   KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_AUDIO_VOL_UP,                LALT(LCTL(KC_LEFT)),            LALT(LCTL(KC_ENTER)),           LALT(LCTL(KC_RIGHT)),           KC_TRANSPARENT,                 KC_TRANSPARENT,

        KC_TRANSPARENT,     KC_TRANSPARENT,                 LALT(LGUI(LCTL(LSFT(KC_L)))),   LALT(LGUI(LCTL(LSFT(KC_M)))),   LALT(LGUI(LCTL(LSFT(KC_S)))),   LALT(LGUI(LCTL(LSFT(KC_T)))),   LALT(LGUI(LCTL(LSFT(KC_D)))),
        KC_TRANSPARENT,     KC_AUDIO_VOL_DOWN,              LALT(LCTL(KC_E)),               LALT(LCTL(KC_C)),               LALT(LCTL(KC_T)),               LALT(LGUI(LCTL(LSFT(KC_O)))),   KC_TRANSPARENT,

        KC_TRANSPARENT,     KC_TRANSPARENT,                 KC_TRANSPARENT,                 LALT(LGUI(LCTL(LSFT(KC_C)))),   LGUI(LCTL(LSFT(KC_4))),         LGUI(LCTL(LSFT(KC_3))),
        LALT(LGUI(LCTL(LSFT(KC_K)))),   LALT(LCTL(KC_D)),   LALT(LCTL(KC_F)),               LALT(LCTL(KC_G)),               KC_TRANSPARENT,                 KC_TRANSPARENT,

        KC_TRANSPARENT,     KC_TRANSPARENT,                 KC_TRANSPARENT,                 KC_TRANSPARENT,                 KC_TRANSPARENT,                 KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,                 KC_TRANSPARENT,                 KC_TRANSPARENT,                 KC_TRANSPARENT,                 KC_TRANSPARENT,

        KC_TRANSPARENT,     KC_TRANSPARENT,                 KC_TRANSPARENT,
        KC_PAUSE,           KC_MEDIA_PLAY_PAUSE,            KC_TRANSPARENT
 ),
 [_FUNC] = LAYOUT_moonlander(
        KC_TRANSPARENT,     KC_TRANSPARENT,     KC_F10,         KC_F11,         KC_F12,         KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

        KC_TRANSPARENT,     KC_TRANSPARENT,     KC_F7,          KC_F8,          KC_F9,          KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

        KC_TRANSPARENT,     KC_TRANSPARENT,     KC_F4,          KC_F5,          KC_F6,          KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

        KC_TRANSPARENT,     KC_TRANSPARENT,     KC_F1,          KC_F2,          KC_F3,          KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

        KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

        KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,
        KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT
 ),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {74,255,206}, {74,255,206}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 2:
      set_layer_color(2);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
  }
  return true;
}



