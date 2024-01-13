# MCU name
MCU = STM32L433

# Bootloader selection
BOOTLOADER = stm32-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes     # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes            # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
BLUETOOTH_ENABLE = no       # Enable Bluetooth
AUDIO_ENABLE = no           # Audio output
TERMINAL_ENABLE = no		# Enable Terminal

# RGB Options
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = is31fl3733
RGB_MATRIX_CUSTOM_KB = yes

# Combo Enable (For layer switching)
COMBO_ENABLE = yes

# Music Encoder
ENCODER_ENABLE = yes

# EEPROM
EEPROM_DRIVER = i2c

# VIA Support
VIA_ENABLE = yes

# SERIAL DRIVER
#SERIAL_DRIVER = off

# Minimization
#LTO_ENABLE = yes
