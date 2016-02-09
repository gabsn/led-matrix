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
void mat_set_row(int, const rgb_color *);
void set_brightness(uint8_t);

#endif 
