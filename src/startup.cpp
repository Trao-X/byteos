#include <stdint.h>

extern uint32_t _endoflestack; // i agree
extern "C" void boskernel(); // we love the byteos kernel yes we

extern "C" void plshandletheresetsalrthx() { // reset handler probably maybe
boskernel(); // yup yup
while (1) { }
}

__attribute__((section(".vectors"), used))
void* vector_table[] = {

    (void*)&_endoflestack,
    (void*)plshandletheresetsalrthx,
};
