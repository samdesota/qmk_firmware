#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _DVORAK,
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Qwerty
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |  Esc |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Tab |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | Shft |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  | Ctrl |
 * `-----------------------------------------'           `-----------------------------------------'
 *        ,------.         ,--------------------.    ,--------------------.          ,------.
 *        | MUTE |         | LOWER| Enter|  Del |    |BckSpc| Space| RAISE|          | MUTE |
 *        `------'         `--------------------'    `--------------------.          `------'
 *                         ,--------------------.    ,--------------------.
 *                         |Mouse3|Mouse1|Mouse2|    | Vol- | Mute | Vol+ |    // 3 way thumb switch
 *                         `--------------------'    `--------------------.
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_QWERTY] = LAYOUT_ximi(
  KC_ESC,       KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,            KC_BSLS,
  KC_TAB,       LCTL_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LSFT_T(KC_F), KC_G,         KC_H,    RSFT_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT,
  KC_LSFT,      KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_ENT,
                KC_MUTE,                    LOWER,        C(S(A(KC_LGUI))),       KC_MS_BTN1,       KC_BSPC, KC_SPC,       RAISE,                      KC_MUTE,
                                            KC_MS_BTN3,   KC_MS_BTN1,   KC_MS_BTN2,   KC_VOLD, KC_MUTE,      KC_VOLU
),

/* DVORAK
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |  Esc |   Q  |   W  |   F  |   P  |   B  |           |   J  |   L  |   U  |   Y  |   ;  |   \  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Tab |   A  |   R  |   S  |   T  |   G  |           |   M  |   N  |   E  |   I  |   O  |   '  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | Shft |   Z  |   X  |   C  |   D  |   V  |           |   K  |   H  |   ,  |   .  |   /  | Ctrl |
 * `--------------------+--------------------'           `-----------------------------------------'
 *        ,------.         ,--------------------.    ,--------------------.          ,------.
 *        | MUTE |         | LOWER| Enter|   '  |    |BckSpc| Space| RAISE|          | MUTE |
 *        `------'         `--------------------'    `--------------------.          `------'
 *                         ,--------------------.    ,--------------------.
 *                         | Undo | Redo2| Redo |    | Vol- | Mute | Vol+ |    // 3 way thumb switch
 *                         `--------------------'    `--------------------.
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_DVORAK] = LAYOUT_ximi(
  KC_ESC,       KC_SCLN,         KC_COMM,         KC_DOT,         KC_P,         KC_Y,         KC_F,    KC_G,         KC_C,         KC_R,      KC_L,   KC_SLSH,
  LT(_LOWER, KC_TAB),       LCTL_T(KC_A), LGUI_T(KC_O), LALT_T(KC_E), LSFT_T(KC_U), MT(MOD_HYPR, KC_I),         MT(MOD_HYPR, KC_D),    RSFT_T(KC_H), RALT_T(KC_T), RGUI_T(KC_N), RCTL_T(KC_S), LT(_LOWER, KC_MINS),
  KC_LSFT,      KC_QUOT,         KC_Q,         KC_J,         KC_K,         KC_X,         KC_B,    KC_M,         KC_W,      KC_V,       KC_Z,      KC_ENT,
                KC_MUTE,                    LOWER,        C(S(A(KC_LGUI))),       KC_MS_BTN1,      KC_BSPC, KC_SPC,       RAISE,                      KC_MUTE,
                                            C(KC_Z),      C(S(KC_Z)),   C(KC_Y),      KC_VOLD, KC_MUTE,      KC_VOLU
),

/* Colemak
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |  Esc |   Q  |   W  |   F  |   P  |   B  |           |   J  |   L  |   U  |   Y  |   ;  |   \  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Tab |   A  |   R  |   S  |   T  |   G  |           |   M  |   N  |   E  |   I  |   O  |   '  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | Shft |   Z  |   X  |   C  |   D  |   V  |           |   K  |   H  |   ,  |   .  |   /  | Ctrl |
 * `--------------------+--------------------'           `-----------------------------------------'
 *        ,------.         ,--------------------.    ,--------------------.          ,------.
 *        | MUTE |         | LOWER| Enter|   '  |    |BckSpc| Space| RAISE|          | MUTE |
 *        `------'         `--------------------'    `--------------------.          `------'
 *                         ,--------------------.    ,--------------------.
 *                         | Undo | Redo2| Redo |    | Vol- | Mute | Vol+ |    // 3 way thumb switch
 *                         `--------------------'    `--------------------.
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_COLEMAK] = LAYOUT_ximi(
  KC_ESC,       KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,         KC_J,    KC_L,         KC_U,         KC_Y,         KC_SCLN,      KC_BSLS,
  KC_TAB,       LCTL_T(KC_A), LGUI_T(KC_R), LALT_T(KC_S), LSFT_T(KC_T), MT(MOD_HYPR, KC_G),         MT(MOD_HYPR, KC_M),    RSFT_T(KC_N), RALT_T(KC_E), RGUI_T(KC_I), RCTL_T(KC_O), KC_QUOT,
  KC_LSFT,      KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,         KC_K,    KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,      KC_ENT,
                KC_MUTE,                    LOWER,        C(S(A(KC_LGUI))),       KC_MS_BTN1,      KC_BSPC, KC_SPC,       RAISE,                      KC_MUTE,
                                            C(KC_Z),      C(S(KC_Z)),   C(KC_Y),      KC_VOLD, KC_MUTE,      KC_VOLU
),

/* Raise
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * | ____ |      |      |  up  |      |      |           |      |   5  |   6  |  7   |  8   |   9  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | ____ |   (  | lft  |  dn  | rht  |  )   |           |   0  |   1  |   2  |  3   |  4   | ____ |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | ____ |   [  |   {  |  }   |   ]  |      |           |      |      |      |      |      | ____ |
 * `-----------------------------------------'           `-----------------------------------------'
 *        ,------.         ,--------------------.    ,--------------------.          ,------.
 *        | MUTE |         | LOWER|      |      |    |      |      | RAISE|          | MUTE |
 *        `------'         `--------------------'    `--------------------.          `------'
 *                         ,--------------------.    ,--------------------.
 *                         | Undo | Redo2| Redo |    | Vol- | Mute | Vol+ |    // 3 way thumb switch
 *                         `--------------------'    `--------------------.
 */
[_RAISE] = LAYOUT_ximi(
  _______, _______, _______, KC_UP  , _______, _______,   /**/  _______, KC_5   , KC_6   , KC_7   , KC_8   , KC_9   ,
  _______, KC_LPRN, KC_LEFT, KC_DOWN, KC_RGHT, KC_RPRN,   /**/  KC_0   , KC_1   , KC_2   , KC_3   , KC_4   , _______,
  _______, KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, _______,   /**/  _______, _______, _______, _______, _______, _______,

                _______,          _______, _______, _______,                _______, _______, _______,          _______,
                                  _______, _______, _______,                _______, _______, _______
),

/* Lower
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * | ____ |      |      |      |  p+  |      |           |      |  g`  |  c^  |  r%  |      | ____ |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | ____ |  a@  |  o|  |  e=  |      |      |           |      |  h#  |  t~  |  n!  |  s$  | ____ |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | ____ |      |      |      |      |  x*  |           |  b\  |  m&  |      |      |      | ____ |
 * `-----------------------------------------'           `-----------------------------------------'
 *        ,------.         ,--------------------.    ,--------------------.          ,------.
 *        | MUTE |         | LOWER|      |      |    |  Del |      | RAISE|          | MUTE |
 *        `------'         `--------------------'    `--------------------.          `------'
 *                         ,--------------------.    ,--------------------.
 *                         | Undo | Redo2| Redo |    | Vol- | Mute | Vol+ |    // 3 way thumb switch
 *                         `--------------------'    `--------------------.
 */
[_LOWER] = LAYOUT_ximi(
  _______,      _______, _______, _______, KC_PLUS, _______,      _______, KC_GRV , KC_CIRC, KC_PERC, _______, DT_UP,
  _______,      KC_AT  , KC_PIPE, KC_EQL , _______, _______,      _______, KC_HASH, KC_TILD, KC_EXLM, KC_DLR , DT_DOWN,
  QK_BOOT,      KC_CAPS, _______, _______, _______, KC_ASTR,      KC_BSLS, KC_AMPR, _______, _______, _______, DT_PRNT,

                _______,          _______, _______, _______,      KC_DEL,  _______, _______,          _______,
                                  _______, _______, _______,      _______, _______, _______
),

/* Adjust (Lower + Raise)
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * | ____ | RGB_T| RGB_R| RGB_F|      |QWERTY|           |   F1 |  F2  |  F3  |  F4  |  F5  | ____ |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | ____ | SPD_I| HUE_I| SAT_I| VAL_I|COLEMK|           |   F6 |  F7  |  F8  |  F9  |  F10 | ____ |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | ____ | SPD_D| HUE_D| SAT_D| VAL_D|      |           |  F11 |  F12 |      |Reset | Btldr| ____ |
 * `-----------------------------------------'           `-----------------------------------------'
 *        ,------.         ,--------------------.    ,--------------------.          ,------.
 *        | MUTE |         | LOWER|      |      |    |      |      | RAISE|          | MUTE |
 *        `------'         `--------------------'    `--------------------.          `------'
 *                         ,--------------------.    ,--------------------.
 *                         | Undo | Redo2| Redo |    | Vol- | Mute | Vol+ |    // 3 way thumb switch
 *                         `--------------------'    `--------------------.
 */
[_ADJUST] =  LAYOUT_ximi(
  _______,      EE_CLR, FP_POINT_DPI_DN, RGB_MOD, _______, TO(_QWERTY),       KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   _______,
  _______,      RGB_SPI, RGB_HUI,  RGB_SAI, RGB_VAI, TO(_COLEMAK),      KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  _______,
  _______,      RGB_SPD, RGB_HUD,  RGB_SAD, RGB_VAD, TO(_DVORAK),           KC_F11,  KC_F12,  _______, QK_RBT,   QK_BOOT, _______,
                _______,           _______, _______, _______,           _______, _______, _______,          _______,
                                   _______, _______, _______,           _______, _______, _______
)
};
/*
static bool scrolling_mode = false;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (scrolling_mode) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

layer_state_t layer_state_set_pointing(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _RAISE:
        case _LOWER:
            scrolling_mode = true;
            pointing_device_set_cpi(200);
            break;
        default:
            if (scrolling_mode) {
                scrolling_mode = false;
                pointing_device_set_cpi(2000);
            }
            break;
    }
    return state;
}
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;
        default:
            break;
    }

    return true;
}
