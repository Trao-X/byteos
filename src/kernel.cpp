#include <stdint.h>
#include "../include/strcmp.h"
#include "../include/bfs.h"
// byteos 1.6 armv6-m stm32g0 for byteos development board
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
volatile uint32_t *aircr = (volatile uint32_t *)0xE000ED0C;
volatile uint32_t *nvic_iser = (volatile uint32_t *)0xE000E100; // iserrrr for the thing interruptsz
// time to start on systrick gd reference
volatile uint32_t *systrick_reload = (volatile uint32_t *)0xE000E014;
volatile uint32_t *systrick_current = (volatile uint32_t *)0xE000E018;
volatile uint32_t *systrick_ctrl = (volatile uint32_t *)0xE000E010;
// that was a FUCKTON of copy and pasting the hex


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
  *systrick_reload = 11999; // i thought this was 24
  *systrick_current = 0;
  *systrick_ctrl |= (1 << 2);
  *systrick_ctrl |= (1 << 0);
  *systrick_ctrl |= (1 << 1); // trick??? is that a gd refernece????
}

volatile uint32_t tiks = 0;

extern "C" void systrickcounter() {
  tiks++;
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

void uint32tonumber(uint32_t number) {
  if(number == 0) {
    uartcharacterplacement("0");
  }
  char table[11];
  int counter = 0;
  while(number != 0) {
  table[counter] = number % 10 + '0';
  counter++;
  number = number / 10; // I FUCKING HATE CPP
  // ill fucking jump off a bridge if it doesnt work next try
  }
  int counterminus1 = counter - 1; // no fucking shit
  while(counterminus1 >= 0) {
  pleaseputacharacter(table[counterminus1]);
  counterminus1 --; // im ENDING IT if this doesnt work
  // IM GONNA SERIOUSLY FUCKING DO IT
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
char maxinput[256];
int howmanycharacterscurrently = 0;

void startanewterm() { uartcharacterplacement("\x1b[32mbyteW>\x1b[0m"); } // hacker green prompt

void copyshit(char* destination, const char* sourc) {
  while ((*destination++ = *sourc++));
}

char uparrowshit[256];
int lecounter = 0;
int FUCKTHISBULLSHIT = 1;
int lengthofuparrowshit = 0;

void typepls() {
  while (1) {
    char userinputprobably = givcharacter();
    if (userinputprobably == '\n' || userinputprobably == '\r') {

      maxinput[howmanycharacterscurrently] = '\0';
      if(FUCKTHISBULLSHIT == 1) {
      copyshit(uparrowshit, maxinput);
      }
      howmanycharacterscurrently = 0;
      lecounter = 0;
      lengthofuparrowshit = 0;
      while(maxinput[lecounter] != '\0') {
        lecounter++;
      }
      return;
    }
    else if (userinputprobably == '\b' || userinputprobably == 0x7f) {
      if(howmanycharacterscurrently > 0 ) {
      howmanycharacterscurrently--;
      uartcharacterplacement("\b \b");
      }
    }
    else if (userinputprobably == '\x1b') {
    char getinputig = givcharacter();
    if (getinputig == '[')    {
    getinputig = givcharacter();
    if (getinputig == 'A') {
    if(FUCKTHISBULLSHIT == 1) {
    uartcharacterplacement(uparrowshit);
    lengthofuparrowshit = 0;
    while(uparrowshit[lengthofuparrowshit] != '\0') {
    lengthofuparrowshit++;
      }
    copyshit(maxinput, uparrowshit);
    howmanycharacterscurrently = lengthofuparrowshit;
    }
    }
    }
    }

    else if (howmanycharacterscurrently < 255) {
      maxinput[howmanycharacterscurrently] = userinputprobably;
      howmanycharacterscurrently++;
      pleaseputacharacter(userinputprobably);
    }
    else {
      uartcharacterplacement("stop trying to overflow the kernel, you now may not use the terminal anymore");
    }
  }
}


int echolaid(const char* lllllline, const char* prefik) {
    while (*prefik != '\0') {
      if (*lllllline != *prefik) {
        return 0;
      }
      lllllline++;
      prefik++;
    }
    return 1;
}
int returnvalue; 
extern "C" void boskernel() { // copy pasted idk how to call c but yea ig its not copypasted anymore! learned how to do basic c i guess...


  uart_init();
  uartcharacterplacement(
      "welcome to byteos 1.6 arm edition\r\n");
  checkif();
  while (1) {
    startanewterm();
    typepls();
    if (strcmp(maxinput, "help") == 0) {
      uartcharacterplacement("\r\nok so the current commands are: help, neofetch, clear, uptime, echo, write, touch, cat, ls, rm, edit, panik, reboot\r\n");
    }
    else if (strcmp(maxinput, "neofetch") == 0) {
      uartcharacterplacement("\r\nos: byteos 1.6 kernel: bitnl cpu: one of the stm32s probably!\r\n");
    }
    else if (strcmp(maxinput, "clear") ==  0) {
      uartcharacterplacement("\x1b[2J\x1b[H"); // idk why is it in characters but still its kinda cool
    }
    else if (strcmp(maxinput, "") ==  0) {
        uartcharacterplacement("\r\n");
    }
    else if(echolaid(maxinput, "touch ") == 1) {
      nameofshit = 6;
      if(maxinput[nameofshit] == '\0') {
        uartcharacterplacement("\r\n");
        uartcharacterplacement("THE FILENAME CANNOT BE FUCKING EMPTY ARE YOU STUPID");
        uartcharacterplacement("\r\n");

      }
      else {
      uartcharacterplacement("\r\n");
      returnvalue = createshit(maxinput + nameofshit);
      uartcharacterplacement("\r\n");
              if(returnvalue == 1) {
      saveshit();
              }
              }
    }

    else if (strcmp(maxinput, "ls") == 0) {
      listshit();
    }
    else if (echolaid(maxinput, "cat ") == 1) {
      nameofshit = 4;
      readshit();
    }
    else if (echolaid(maxinput, "write ") == 1) {
      nameofshit = 6;
      FUCKTHISBULLSHIT = 0;
      returnvalue = writeshit();
      FUCKTHISBULLSHIT = 1;
              if(returnvalue == 1) {
      saveshit();
              }
 // this is fucking evil bro
      }
      else if (strcmp(maxinput, "reboot") == 0) {
        *aircr = (0x5FAu << 16) | (1u << 2);
        uartcharacterplacement("\r\n");
      } 
      else if (echolaid(maxinput, "rm ") == 1) {
        nameofshit = 3;
        returnvalue = removeshit();
        if(returnvalue == 1) {
        saveshit();
        }
        uartcharacterplacement("\r\n");
      }
    else if (strcmp(maxinput, "uptime") == 0) {
      uartcharacterplacement("\nthe uptime iss "); // this better fucking work OR FUCKINE ELSE
      if(tiks <= 60000) {
      uint32tonumber(tiks / 1000);
      uartcharacterplacement("s");
      }
      else if (tiks >= 60000) {
        uint32tonumber((tiks / 1000) / 60);
        uartcharacterplacement("m");
      }

      uartcharacterplacement("\r\n"); // now i have FUCKING LINKER ERRORS IM GONNA HAVE AFUCKING MENTAL BREAKDOWN
 } // IM FUCKING ENDING IT IT DIDNT BOOT
    else if (echolaid(maxinput, "echo ") == 1) {
      uartcharacterplacement("\r\n");
      uartcharacterplacement(maxinput + 5);
      uartcharacterplacement("\r\n"); // i fucking DESPISE semicolons
}
  else if (strcmp(maxinput, "panik") == 0) {
    __asm volatile ("udf #0");
  }
  else if (echolaid(maxinput, "edit ") == 1) {
    nameofshit = 5;
    if(findshit(maxinput + 5) == -1) {
        uartcharacterplacement("\r\n");
        uartcharacterplacement("you didnt make the file bro");
        uartcharacterplacement("\r\n");
      }
      else {
    uartcharacterplacement("\r\n");
    uartcharacterplacement("current file contents: ");
    readshit();
    uartcharacterplacement("\r\n");
    uartcharacterplacement("what do you want in the file?");
    FUCKTHISBULLSHIT = 0;
    returnvalue = writeshit();
    FUCKTHISBULLSHIT = 1;
      if(returnvalue == 1) {
    saveshit();
      }
    
      }
  }
    else {
      uartcharacterplacement("\r\nthat command isnt real!\r\n");
    }
    
  }
}
// FUCK PCPCPPCPCPCPCPCPCPC
// YESSS IT WORKED