#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>

typedef struct {
  unsigned char r;
  unsigned char g;
  unsigned char b;
} rgb_color;

void matrix_init();
void init_bank0();
void desactivate_rows();
void test_pixels();
void set_brightness(uint8_t);
void display_image_optimized(rgb_color *, uint32_t);
void display_image(rgb_color *);

#endif 
