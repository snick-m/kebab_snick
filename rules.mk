# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
# change yes to no to disable
#
BOOTMAGIC_ENABLE = no     # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no       # Mouse keys
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration

EXTRAKEY_ENABLE = yes       # Audio control and System control

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no           
BACKLIGHT_ENABLE = no
AUDIO_ENABLE = no
ENCODER_ENABLE = yes
QMK_SETTINGS = no         
OLED_ENABLE = yes
OLED_DRIVER = SSD1306
UNICODE_ENABLE = no
WPM_ENABLE = yes
COMBO_ENABLE = no
LTO_ENABLE = yes
SWAP_HANDS_ENABLE= no
EXTRAFLAGS  += -flto
TAP_DANCE_ENABLE = no
KEY_OVERRIDE_ENABLE = no

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812

RAW_HID = yes

# RGBLIGHT_ENABLE = yes
# RGBLIGHT_DRIVER = WS2812

# ENCODER_MAP_ENABLE = yes

# Save Space

SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no 
MAGIC_ENABLE = no
MUSIC_ENABLE = no
AVR_USE_MINIMAL_PRINTF = yes
