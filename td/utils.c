void wait_for(int t) {
    t *= 24000;
    for (int i=0; i<t; ++t)
        asm volatile ("nop");
}
