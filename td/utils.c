
// Time specified in ms 
void wait_for(int t) {
    t *= 4800;
    for (int i=0; i<t; ++i)
        __asm__ volatile ("nop");
}

// Time specified in micro seconds 
void wait_for_m(int t) {
    t *= 5;
    for (int i=0; i<t; ++i)
        __asm__ volatile ("nop");
}
