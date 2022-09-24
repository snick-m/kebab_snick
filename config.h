/* SPDX-License-Identifier: GPL-2.0-or-later */
#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"
// #include "remove_matrix.h"
#include "add_matrix.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0001
#define MANUFACTURER    Vial
#define PRODUCT         Alice Kebab

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

#define MATRIX_ROW_PINS { F1, F7, B5, B4, D7 }
#define MATRIX_COL_PINS { F0, F6, F5, F4, B6, C6, C7, B0, B1, B2, B3, E6, D2, D3, D5 }

#define DIODE_DIRECTION COL2ROW

// Save Space

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE
#define LAYER_STATE_8BIT


// If encoder present 
#define ENCODERS_PAD_A { D6 }
#define ENCODERS_PAD_B { D4 }
#define ENCODER_RESOLUTION 4
#define ENCODER_DIRECTION_FLIP

// #define BACKLIGHT_PIN B7

#define OLED_BRIGHTNESS 16

// #define LED_FLAG_UNDERGLOW
#define RGB_DISABLE_WHEN_USB_SUSPENDED
// #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #define RGB_MATRIX_KEYPRESSES

#define RGB_DI_PIN B7
#define DRIVER_LED_TOTAL 34
#ifdef RGB_DI_PIN
	// #define RGBLIGHT_ANIMATIONS
	// #define RGBLIGHT_EFFECT_ALTERNATING
    // #define RGBLIGHT_EFFECT_BREATHING
    // #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    // #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
	// #define RGBLIGHT_EFFECT_SNAKE

	// #define RGBLED_NUM 18
	// #define DRIVER_LED_TOTAL 18
	
	// #define RGBLIGHT_LIMIT_VAL 80
	// #define RGBLIGHT_HUE_STEP 512
	// #define RGBLIGHT_SAT_STEP 16
	// #define RGBLIGHT_VAL_STEP 64

	#define RGB_MATRIX_HUE_STEP 2
	#define RGB_MATRIX_SAT_STEP 8
	#define RGB_MATRIX_VAL_STEP 8
#endif

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

#define DISABLE_LEADER

#endif