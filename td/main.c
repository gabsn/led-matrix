#include "main.h"

int fibo(int n) {
    if (n == 0 || n == 1)
        return n;
    else
        return fibo(n-1) + fibo(n-2);
}
        
int variable_in_bss = 0;

int main() {
    return fibo(8);
}
