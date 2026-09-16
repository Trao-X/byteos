#include <stdint.h>
#include "../include/strcmp.h"
// byteos 1.1.3 armv6-m stm32g0 for byteos development board
// the kernel is named bitnl (credits to .n.o.t.a. for that name)
// last update reprofessionalizing since i decided i was immature 2 days ago
// credits: v3x, osdev (credits for software used outside this file in other files)

volatile uint32_t *rcc_iopenr = (volatile uint32_t *)0x40021034;
volatile uint32_t *rcc_apbenr1 = (volatile uint32_t *)0x4002103C;
volatile uint32_t *gpio_moder = (volatile uint32_t *)0x50000000;
volatile uint32_t *gpio_afrl = (volatile uint32_t *)0x50000020;
volatile uint32_t *usart2_cr1 = (volatile uint32_t *)0x40004400;
volatile uint32_t *usart2_brr = (volatile uint32_t *)0x4000440C;
volatile uint32_t *usart2_isr = (volatile uint32_t *)0x4000441C; // inter status register
volatile uint32_t *usart2_tdr = (volatile uint32_t *)0x40004428; // transmit data register
volatile uint32_t *nvic_iser = (volatile uint32_t *)0xE000E100; // iserrrr for the thing interrupts
// that was a FUCKTON of copy and pasting the hex

// strcmp from embeddedartistry.github.io

void uart_init() {

  *rcc_iopenr |= (1 << 0);   // reset and clock control io enable reg afaik
  *rcc_apbenr1 |= (1 << 17); // rcc adv perihpal bus enable reg

  *gpio_moder &= ~(3 << 4); // gpio mode register, i have fuckall idea what a mode register is
  *gpio_moder |= (2 << 4);

  *gpio_afrl |= (1 << 8); // gpio alternate low register, actually nvm alternate low FUNCTION

  *usart2_brr = 104; // uart with synchronous 2 baud rate register, prob // fixed the uhh brr needed to be smaller cuz less mhz
                     // something that has to do with uartttt
  *usart2_cr1 |= (1 << 5) | (1 << 3) | (1 << 2) | (1 << 0); // gl to you in life if you are reading this, anyways control reg,
              // bro my rename to propfessionalize naming was so fucking shit
  *gpio_moder &= ~(3 << 6); // gpio mode register
  *gpio_moder |= (2 << 6);  // 2x
  *gpio_afrl |= (1 << 12);  // hm
  *nvic_iser |= (1 << 28);
}

void pleaseputacharacter(char okillputacharacter) {
  // *uartbos = okillputacharacter; this is so fucking stupid and i like half understand it maybe idk (this is what i said before switching to the other chip and now i dont understand it at fucking all!)
  while (!(*usart2_isr & (1 << 7))) { // this is probably something idk it sets bit :thumbsup: ok nvm it turns out // ittt reads a bit and isolates bit 7 for testing
  }
  *usart2_tdr = okillputacharacter;
}

void uartcharacterplacement(const char *okillplaceit) {

  while (*okillplaceit != '\0') {
    pleaseputacharacter(*okillplaceit);
    okillplaceit++; // this took me like 10 fucking minutes to figure out + 5 for the braces
  }
}

volatile uint32_t *usart2_rdr = (volatile uint32_t *)0x40004424; // recieve data register

volatile char storag[64];
volatile int writeindia = 0;
volatile int readindia = 0;

char givcharacter() {
  while (readindia == writeindia) {
  }
  char okiassignedit = storag[readindia];
  readindia = (readindia + 1) & 63;
  return okiassignedit;  // tuff
}
char maxinput[1024];
int howmanycharacterscurrently = 0;

void startanewterm() { uartcharacterplacement("\x1b[32mbyteW>\x1b[0m"); } // hacker green prompt

void typepls() {
  while (1) {
    char userinputprobably = givcharacter();
    if (userinputprobably == '\n' || userinputprobably == '\r') {
      maxinput[howmanycharacterscurrently] = '\0';
      howmanycharacterscurrently = 0;
      return;
    }
    else if (userinputprobably == '\b' || userinputprobably == 0x7f) {
      if(howmanycharacterscurrently > 0 ) {
      howmanycharacterscurrently--;
      uartcharacterplacement("\b \b");
      }
    }
    else if (howmanycharacterscurrently < 1023) {
      maxinput[howmanycharacterscurrently] = userinputprobably;
      howmanycharacterscurrently++;
      pleaseputacharacter(userinputprobably);
    } else {
      uartcharacterplacement("stop trying to overflow the kernel, you now may not use the terminal anymore");
    }
  }
}
extern "C" void boskernel() { // copy pasted idk how to call c but yea ig its not copypasted anymore! learned how to do basic c i guess...


  uart_init();
  uartcharacterplacement(
      "welcome to byteos 1.1.3 designed for byte dev board\r\n");
  while (1) {
    startanewterm();
    typepls();
    if(maxinput[0] == '\0') {
      uartcharacterplacement("\r\n");
    }
    else if (strcmp(maxinput, "help") == 0) {
      uartcharacterplacement("\r\nok so the current commands are: help, neofetch, clear\r\n");
    }
    else if (strcmp(maxinput, "neofetch") == 0) {
      uartcharacterplacement("\r\nos: byteos 1.1.3 kernel: bitnl cpu: one of the stm32s probably!\r\n");
    }
    else if (strcmp(maxinput, "clear") ==  0) {
      uartcharacterplacement("\x1b[2J\x1b[H"); // idk why is it in characters but still its kinda cool
    }
    else {
      uartcharacterplacement("\r\nthat command isnt real!\r\n");
    }
  }

  // the while(1) part is entirely copied because i do not understand c // this is not true anymore! hi so im back and 50 lines and 30 more mins! we have
  // added uart input couple of hours for uart input, well not really probably like 30 mins again but like i split it many times
  // i passed river in 0.5x speed, ignore this, 15.09.2026
}
