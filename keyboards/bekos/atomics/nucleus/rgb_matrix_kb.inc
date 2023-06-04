RGB_MATRIX_EFFECT(MUSE_RGB_OFF)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool MUSE_RGB_OFF(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    if (!HAS_FLAGS(g_led_config.flags[i], LED_FLAG_INDICATOR)){
      rgb_matrix_set_color(i, RGB_OFF);
    }
  }
  return led_max < RGB_MATRIX_LED_COUNT;
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
