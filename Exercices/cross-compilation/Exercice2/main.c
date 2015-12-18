#include <stdio.h>
#include <stdlib.h>

int f(int n) {
    int a = n;
    printf("addresse stack : %p\n", &a);
    return a;
}

int main() {
    int a; // bss
    printf("addresse bss : %p\n", &a);
    const int b = 1; // rodata
    printf("addresse rodata : %p\n", &b);
    int c = 1; // data
    printf("addresse data : %p\n", &c);
    int * d;
    d = malloc(sizeof(int)); // heap    
    printf("addresse heap : %p\n", &d);
    f(1); // stack

    return 0;
}

