// Time specified in ms 
void wait_for(int t) {
    t *= 10000;
    for (int i=0; i<t; ++i)
        __asm__ volatile ("nop");
}

// Time specified in micro seconds 
void wait_for_m(int t) {
    t *= 10;
    for (int i=0; i<t; ++i)
        __asm__ volatile ("nop");
}
