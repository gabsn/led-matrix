#include "include/clocks.h"
#include "include/led.h"
#include "include/uart.h"
#include "include/matrix.h"
#include "include/utils.h"

#define size 10

char s[size];

int main() {
    clocks_init();
    uart_init();
    matrix_init();

    activate_row(3); 

    //rgb_color pixel;
    //pixel.b = 0xff;
    //pixel.g = 0xff;
    //pixel.r = 0xff;

    //rgb_color row[8];
    //for (int i=0; i<=8; ++i) 
    //    row[i] = pixel;

    //mat_set_row(1, row);

    return 0;
}
