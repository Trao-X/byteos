#include <stdint.h>
#include <stddef.h> // im only including this because the creator of the strcmp is a fuckign chud who uses null instead of nullptr
// byteos 1.1.1 armv6-m stm32g0 for byteos development board
// last update made it so no memory overflow when maxinput passed
// credits: v3x, osdev, embeddedartistry.github.io


volatile uint32_t* resetandcockcontrol_ioenablereg = (volatile uint32_t*)0x40021034;
volatile uint32_t* resetandcockcontrol_advancedpenisbusenablereg = (volatile uint32_t*)0x4002103C;
volatile uint32_t* youknowwhatgpiois_modereg = (volatile uint32_t*)0x50000000;
volatile uint32_t* youknowwhatgpiois_altfunreglow = (volatile uint32_t*)0x50000020;
volatile uint32_t* uartbutsynchronous2_ctrlgreg1yolookthatsaysgreg = (volatile uint32_t*)0x40004400;
volatile uint32_t* uartbutsynchronous2_baudratereg = (volatile uint32_t*)0x4000440C;
volatile uint32_t* uartbutsynchronous2_interuptstatusregimisspeledinterrupt = (volatile uint32_t*)0x4000441C;
volatile uint32_t* uartbutsynchronous2_transmitdatareg = (volatile uint32_t*)0x40004428;
// that was a FUCKTON of copy and pasting the hex

// strcmp from embeddedartistry.github.io

 int strcmp(const char* s1, const char* s2)
 {
     int r = -1;

     if(s1 == s2)
     {
         // short circuit - same string
         return 0;
     }

     // I don't want to panic with a NULL ptr - we'll fall through and fail w/ -1
     if(s1 != NULL && s2 != NULL)
     {
         // iterate through strings until they don't match or s1 ends (null-term)
         for(; *s1 == *s2; ++s1, ++s2)
         {
             if(*s1 == 0)
             {
                 r = 0;
                 break;
             }
         }

         // handle case where we didn't break early - set return code.
         if(r != 0)
         {
             r = *(const char*)s1 - *(const char*)s2;
         }
     }

     return r;
 }


void uart_init() {

    *resetandcockcontrol_ioenablereg |= (1 << 0);
    *resetandcockcontrol_advancedpenisbusenablereg |= (1 << 17);

    *youknowwhatgpiois_modereg &= ~(3 << 4);
    *youknowwhatgpiois_modereg |= (2 << 4);

    *youknowwhatgpiois_altfunreglow |= (1 << 8);

    *uartbutsynchronous2_baudratereg = 139;
    *uartbutsynchronous2_ctrlgreg1yolookthatsaysgreg |= (1 << 3) | (1 << 2) | (1 << 0);
    *youknowwhatgpiois_modereg &= ~(3 << 6);
    *youknowwhatgpiois_modereg |= (2 << 6);
    *youknowwhatgpiois_altfunreglow |= (1 << 12); // uart init or smht idfk
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
while (!(*uartbutsynchronous2_interuptstatusregimisspeledinterrupt & (1 << 5))) {}
return *uartbutsynchronous2_givemefuckingadataregister; // well no fucking shit

// i kinda understand this maybe idk

}

char maxinput[1024];
int howmanycharacterscurrently = 0;


void startanewterm() {
putshitinuart("byteW>");
}



void typepls() {
    while (1) {
    char wtfdidutype = getmeafuckingcharacter();
    if (wtfdidutype == '\n' || wtfdidutype == '\r') {
    maxinput[howmanycharacterscurrently] = '\0';
    howmanycharacterscurrently = 0;
    return;
}
if (howmanycharacterscurrently < 1023) {
maxinput[howmanycharacterscurrently] = wtfdidutype;
howmanycharacterscurrently++;
pleaseputacharacter(wtfdidutype);
}
else {
    putshitinuart("stop trying to overflow the kernel you fucking chud");
}
}
}
extern "C" void boskernel() {  // copy pasted idk how to call c but yea ig its right maybe idk // its not copypasted anymore! i learned how to do basic c i guess...
uart_init();
putshitinuart("welcome to byteos 1.1.1 designed for byte dev board");
while (1) {
    startanewterm();
    typepls();
    if (strcmp(maxinput, "help") == 0) {
        putshitinuart("\r\ngo fuck yourself im not helping you you fucking chud\r\n");
    }
}

// the while(1) part is entirely copied because i do not understand c
// kill yourselfffffffff took me like 30 mins of writing for 24 lines, have to order pcb v1 soon
// hi so im back and 50 lines and 30 more mins!
// fuck c cpp better
// we have added uart input
// couple of hours for uart input, well not really probably like 30 mins again but like i split it many times
// penis
// i passed river in 0.5x speed, ignore this, 15.09.2026


}
