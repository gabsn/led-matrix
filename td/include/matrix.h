#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>

typedef struct {
  unsigned char r;
  unsigned char g;
  unsigned char b;
} rgb_color;

void matrix_init();
void pulse_SCK();
void pulse_LAT();
void desactivate_rows();
void activate_row(int);
void send_byte(uint8_t, int);
void mat_set_row(int, const rgb_color *);
void init_bank0();

#endif 
