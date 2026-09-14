#include <stdint.h>

// byteos 1.0.0 armv6-m stm32g0 for byteos development board & qemu
// credits: v3x, osdev

volatile uint32_t* resetandcockcontrol_ioenablereg = (volatile uint32_t*)0x40021034;
volatile uint32_t* resetandcockcontrol_advancedpenisbusenablereg = (volatile uint32_t*)0x4002103C;
volatile uint32_t* youknowwhatgpiois_modereg = (volatile uint32_t*)0x50000000;
volatile uint32_t* youknowwhatgpiois_altfunreglow = (volatile uint32_t*)0x50000020;
volatile uint32_t* uartbutsynchronous2_ctrlgreg1yolookthatsaysgreg = (volatile uint32_t*)0x40004400;
volatile uint32_t* uartbutsynchronous2_baudratereg = (volatile uint32_t*)0x4000440C;
volatile uint32_t* uartbutsynchronous2_interuptstatusregimisspeledinterrupt = (volatile uint32_t*)0x4000441C;
volatile uint32_t* uartbutsynchronous2_transmitdatareg = (volatile uint32_t*)0x40004428;
// that was a FUCKTON of copy and pasting the binary

void uart_init() {

    *resetandcockcontrol_ioenablereg |= (1 << 0);
    *resetandcockcontrol_advancedpenisbusenablereg |= (1 << 17);

    *youknowwhatgpiois_modereg &= ~(3 << 4);
    *youknowwhatgpiois_modereg |= (2 << 4);

    *youknowwhatgpiois_altfunreglow |= (1 << 8);

    *uartbutsynchronous2_baudratereg = 139;
    *uartbutsynchronous2_ctrlgreg1yolookthatsaysgreg |= (1 << 3) | (1 << 0);
}

// please tell me this is correct or im jumping off a bridge
// it is, not today

void pleaseputacharacter(char okillputacharacter) {
// *uartbos = okillputacharacter; this is so fucking stupid and i like half understand it maybe idk (this is what i said before switching to the other chip and now i dont understand it at fucking all!)
while(!(*uartbutsynchronous2_interuptstatusregimisspeledinterrupt & (1 << 7))) { } // this is probably something idk it sets bit :thumbsup: ok nvm it turns out ittt reads a bit and isolates bit 7 for testing
*uartbutsynchronous2_transmitdatareg = okillputacharacter;
}


void putshitinuart(const char* okillputshitinuart) {

    while (*okillputshitinuart != '\0') {
    pleaseputacharacter(*okillputshitinuart);
    okillputshitinuart++; // this took me like 10 fucking minutes to figure out + 5 for the braces
}
}

volatile uint32_t* uartbutsynchronous2_givemefuckingadataregister = (volatile uint32_t*)0x40004424;

char getmeafuckingcharacter() {
while (!(*uartbutsynchronous2_interuptstatusregimisspeledinterrupt & (1 << 5))) {
    return *uartbutsynchronous2_givemefuckingadataregister; // well no fucking shit
}

// i kinda understand this maybe idk

}

extern "C" void boskernel() {  // copy pasted idk how to call c but yea ig its right maybe idk
uart_init();
putshitinuart("welcome to byteos 1.0.0");
while (1) {
    pleaseputacharacter(getmeafuckingcharacter());
}

// the while(1) part is entirely copied because i do not understand c

// kill yourselfffffffff took me like 30 mins of writing for 24 lines, have to order pcb v1 soon
// hi so im back and 50 lines and 30 more mins!
//fuck c
// we have added uart input


//penis


}
