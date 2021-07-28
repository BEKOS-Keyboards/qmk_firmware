RGB_MATRIX_EFFECT(row_one_only)


#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
static bool row_one_only(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < 16; i++) {
    rgb_matrix_set_color(i, 0xff, 0xff, 0xff);
  }
  for (uint8_t i = 16; i < 19; i++) {
      rgb_matrix_set_color(i, 74, 65, 42);
    }
  return led_max < DRIVER_LED_TOTAL;
}
#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
