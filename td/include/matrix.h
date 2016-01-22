#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>

typedef struct {
  unsigned char r;
  unsigned char g;
  unsigned char b;
} rgb_color;

void pulse_SCK();
void pulse_LAT();
void desactivate_rows();
void activate_row(int);
void send_byte(uint8_t, int);
void init_bank0();

#endif 
