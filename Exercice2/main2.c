#include <stdio.h>
#include <stdlib.h>

void g(int n) {
    int a = n;
    printf("seconde variable : %p\n", &a);
}

void f(int n) {
    int a = n;
    printf("première variable : %p\n", &a);
    g(a);
}

int main() {
    f(1);

    return 0;
}
