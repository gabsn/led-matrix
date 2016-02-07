#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

int main() {
    double sbr, new_rate, err(0.05);
    int reg = 33;
    const double baudrate = 38400;
    const double srcclock = 24000000;

    while (reg > 4 && err > 0.02) {
        sbr = floor(srcclock/(baudrate*reg));    
        cout << "sbr : " << sbr;
        new_rate = srcclock/(sbr*reg);
        cout << "new_rate : " << new_rate << endl;
        err = abs(baudrate - new_rate)/baudrate;
        cout << "err : " << err << endl;
        reg--;
    }

    cout << reg << endl;

    return 0;
}
    
        

