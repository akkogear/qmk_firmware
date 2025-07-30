SRC += rgb_light_mode.c
RGB_MATRIX_CUSTOM_USER = yes
RGBLIGHT_DRIVER = custom

include keyboards/akko/mineral_01/rgb_record/rgb_record.mk
include keyboards/akko/mineral_01/wls/wls.mk
include keyboards/linker/wireless/wireless.mk

