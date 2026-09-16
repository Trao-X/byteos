#include <stdint.h>

extern uint32_t _data_start, _data_end, _data_flash_start;
extern uint32_t _bss_start, _bss_end;
extern uint32_t _endoflestack; // i agree
extern "C" void boskernel(); // we love the byteos kernel yes we

extern "C" void plshandletheresetsalrthx() { // reset handler probably maybe
    uint32_t* src = &_data_flash_start; // the source is data flash start i suppose?
uint32_t* dst = &_data_start; // start of data yupp
while (dst < &_data_end) {
    *dst = *src; // source is destination
    dst++; // destination + 1
    src++; // source + 1
}

uint32_t* benis = &_bss_start;
while (benis < &_bss_end) {
    *benis = 0;
    benis++;
}
boskernel(); // yup yup
while (1) { }
}




// this is the first part of cpp i meaningfuly struggled on, fun!

__attribute__((section(".vectors"), used))
void* vector_table[] = {

    (void*)&_endoflestack,
    (void*)plshandletheresetsalrthx,
};
