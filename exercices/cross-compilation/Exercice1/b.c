#include <stdint.h> 
#include <stdio.h> 

int32_t x = 34; 
int8_t a;
int16_t b;
int32_t y; 
int64_t c;
struct t1 {
    int8_t a;
    int8_t b;
    int8_t c;
};
struct t2 {
    int a;
    int b;
};
struct t3 {
    int a;
    int b;
    int c;
};
struct t4 {
    int a;
    int b;
    int c;
    int d;
};
struct t5 {
    int a;
    int b;
    int c;
    int d;
    int e;
};
struct t6 {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
};
struct t7 {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
};

struct t1 s1;
struct t2 s2;
struct t3 s3;
struct t4 s4;
struct t5 s5;
struct t6 s6;
struct t7 s7;

const char mesg[] = "Hello World!\n"; 

int main() { 
    static uint8_t z; 
    uint16_t t;
    y = 12; 
    z = z + 1; 
    t = y+z; 
    printf(mesg); 
    printf("x = %d, y = %d, z = %d, t = %d\n", x, y, z, t); 
    return 0; 
}
