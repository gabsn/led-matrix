#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>

typedef struct {
  unsigned char r;
  unsigned char g;
  unsigned char b;
} rgb_color;

void matrix_init();
void desactivate_rows();
void activate_row(int);
void desactivate_row(int);
void mat_set_row(int, const rgb_color *);
void init_bank0();
void test_pixels();
void set_brightness(uint8_t);
void display_image(rgb_color *);

#endif 
