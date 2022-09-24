/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H

#include "kebab_snick.h"
#include <stdio.h>

char* dat_h = "0";

enum my_keycodes {
  RGB_TOP_TOGGLE = USER00,
  TOGGLE_WPM = USER01,
  TOGGLE_SPEEDMETER = USER02
};

bool top_rgb_enabled = false;
bool show_wpm = false;
bool speedmeter_enabled = true;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT(
		KC_6, KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_HOME, 
		KC_Y, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_END, 
		KC_AUDIO_MUTE, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_DEL, 
		KC_GRV, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, 
		TG(2), KC_LCTL, KC_LALT, KC_SPC, LT(1, KC_SPC), KC_SPC, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

	[1] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
  
  [2] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, TOGGLE_WPM, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, TOGGLE_SPEEDMETER, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    RGB_TOP_TOGGLE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

};

led_config_t g_led_config = { { // Use the g_led_config code I provided in dm here
  {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, },
  {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, },
  {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, },
  {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, },
  {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, }
},
{
  {0, 32},
  {0, 36}, 
  {0, 40}, 
  {0, 44}, 
  {0, 48}, 
  {0, 52}, 
  {0, 56}, 
  {0, 60}, {20, 64}, {40, 64}, {60, 64}, {80, 64}, {100, 64}, {120, 64}, {140, 64}, {160, 64}, {180, 64}, {200, 64},
                                                                                                                    {220, 64},
                                                                                                                    {220, 32},
                                                                                                                    {220, 0},
                                                                                                          {200, 0},
                                                                                                {180, 0},
                                                                                    {160, 0},
                                                                          {140, 0},
                                                              {120, 0}, 
                                                    {100, 0}, 
                                          {80, 0},
                                {60, 0}, 
                      {40, 0}, 
            {20, 0},
  {0, 0},
  {0, 32},
  {0, 64}
}, 
{
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                2,
                                2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2,
  2,
  2
}};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode)
  {
  case RGB_TOP_TOGGLE:
    if (record->event.pressed) {
      for (int i = 0; i < 8; i++) {
        if (top_rgb_enabled) {
          rgb_matrix_set_color(i, 0, 0, 0);
        }
        g_led_config.flags[i] = top_rgb_enabled ? LED_FLAG_NONE : LED_FLAG_UNDERGLOW;
      }
      top_rgb_enabled ^= 1;
    }
    return true;
  
  case TOGGLE_WPM:
    if (record->event.pressed) {
      show_wpm ^= 1;
      oled_set_cursor(0, 0);
      oled_write_P(PSTR("         "), false); // clear the line
    }
    return true;
  
  case TOGGLE_SPEEDMETER:
    if (record->event.pressed) {
      speedmeter_enabled ^= 1;
      for (int i = 0; i < 8; i++) {
        rgb_matrix_set_color(i, 0, 0, 0);
      }
    }
    return true;

  default:
    return true;
  }
	// return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) { // Manual Encoder Handling
  if ((get_mods() & (MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT))) == (MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT))) {
    if (clockwise) {
      rgb_matrix_increase_speed();
    } else {
      rgb_matrix_decrease_speed();
    }

    return false;
  } else if (get_mods() & MOD_MASK_SHIFT) {
    if (clockwise) {
      rgblight_increase_val();
    } else {
      rgblight_decrease_val();
    }

    return false;
  } else if (get_mods() & MOD_MASK_ALT) {
    if (clockwise) {
      rgb_matrix_increase_sat();
    } else {
      rgb_matrix_decrease_sat();
    }

    return false;
  } else if (get_mods() & MOD_MASK_CTRL) {
    if (clockwise) {
      rgb_matrix_increase_hue();
    } else {
      rgb_matrix_decrease_hue();
    }

    return false;
  } else {
    if (layer_state_is(2)) {
      if (clockwise) {
        rgb_matrix_step();
      } else {
        rgb_matrix_step_reverse();
      }
    } else {
      if (clockwise) {
        tap_code(KC_VOLU);
      } else {
        tap_code(KC_VOLD);
      }
    }

    return false;
  }

  return true;
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][1][2] = {
    [0] =   {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] =  { ENCODER_CCW_CW(RGB_HUD, RGB_HUI)},
    [2] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
};
#endif


uint8_t get_hue_for(int i) {
  if (i <= 2) {
    return 85;
  } else if (i <= 5) {
    return 40;
  } else {
    return 0;
  }
}

void speedmeter_task(void) {
  uint8_t leds = (uint8_t)(8.0/120 * get_current_wpm());
  
  for (int i = 0; i < 8; i++) {
    HSV hsv;

    if (i < leds) {
      hsv.h = get_hue_for(i);
      hsv.s = 255;
      hsv.v = 55;
    } else {
      hsv.h = 0;
      hsv.s = 0;
      hsv.v = 0;
    }

    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(7 - i, rgb.r, rgb.g, rgb.b);
  }
}

void housekeeping_task_user(void) {
  if (!top_rgb_enabled && speedmeter_enabled) {
    speedmeter_task();
  }
}

#ifdef OLED_ENABLE

#include "frames.h"

#define TAP_FRAMES 2 // total number of tapping animation frames
#define IDLE_FRAMES 3
#define READY_SPEED 30 // above this speed, switch from waiting to ready
#define TAP_SPEED 45 // above this speed, switch from ready to animation

#define ANIM_FRAME_DURATION 200 // how long each animation frame lasts in ms
#define ANIM_SIZE 512 // number of pixels in 128x32 display

// TODO: Add a fallback so that when there's no stream, stored animation plays

// uint32_t anim_timer = 0;
// uint8_t curr_anim_frame = 0;
// uint8_t  current_idle_frame = 0;

// void render_bongo_cat(void) {
//   if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
//     anim_timer = timer_read32();
	
//     if (get_current_wpm() <= TAP_SPEED) {
// 	  current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
// 	  oled_write_raw_P(Idle_Frames[abs((IDLE_FRAMES - 1) - current_idle_frame)], ANIM_SIZE);
      
//     } else {
//       curr_anim_frame = (curr_anim_frame + 1) % TAP_FRAMES;
//       if (get_mods() & MOD_MASK_SHIFT) {
//         oled_write_raw_P(Shift_Frames[curr_anim_frame], ANIM_SIZE);
//       } else {
//         oled_write_raw_P(Run_Frames[curr_anim_frame], ANIM_SIZE);
//       }
//     }
//     //  else if (get_current_wpm() > READY_SPEED && get_current_wpm() < TAP_SPEED){
// 		// oled_write_raw_P(ready_frame, ANIM_SIZE);
//     // }
//   }
// }

void render_frame(void) { // Render Streamed Frame
  oled_set_cursor(0, 0);
  oled_write_raw(oled_frame, 512);
  oled_frame_rcv = 0;
}

bool oled_task_user(void) {
  static char bufa[2] = {0};

  if (oled_frame_rcv >= 512) {
    render_frame();
  }

	// render_bongo_cat();

  // for (int i = 1; i < 17; i++) { // Clear QMK Logo on Bongo
  //   oled_write_pixel(128-i, 14, 0);
  // }
  // for (int i = 1; i < 17; i++) { // Clear QMK Logo on Bongo
  //   oled_write_pixel(128-i, 15, 0);
  // }
  
  oled_set_cursor(oled_max_chars() - 2, 0);
    oled_write_P(PSTR("L"), false);
    oled_write(get_numeric_str(bufa, sizeof(bufa), layer_state_is(0) * 1 + layer_state_is(1) * 2 + layer_state_is(2) * 3, ' '), false);
	
  // oled_set_cursor(oled_max_chars() - 3, 1);
  //   oled_write(dat_h, false);
  if (show_wpm) {
    oled_set_cursor(0, 0);
      oled_write_P(PSTR("WPM "), false);
      oled_write(get_u8_str(get_current_wpm(), '0'), false);
  }

	oled_set_cursor(0, 3);
    oled_write_P(PSTR("SNICK"), false);
  
  //	oled_write(get_u8_str(oled_max_chars(), ' '), false); // Wipe QMK LOGO part
  // oled_set_cursor(oled_max_chars() - 4, 2); // Wipe QMK LOGO part
  //   oled_write_P(PSTR("    "), false);

  oled_set_cursor(oled_max_chars() - 1, 3);
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("C") : PSTR(" "), false);
	return false;
}
#endif