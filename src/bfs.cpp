// byte File System 4.0 (informally byteFS/BFS) designed for byteOS
// credits: v3x, osdev (credits for software used outside this file in other files)

#include <stdint.h>
#include "../include/strcmp.h"
#include "../include/kernel.h"
#include "../include/bfs.h"
    int nameofshit; 
    int forwritingshit;
    int forremovingshit;
    int forlistingshit;


filings shit[15];

void copyshit2(char* destination, const char* sourc) {
  while ((*destination++ = *sourc++));
}

volatile uint32_t *bfsflashings = (volatile uint32_t *)0x08006000;
volatile uint32_t *flashkeyr = (volatile uint32_t *)0x40022008;
volatile uint32_t *flashsr = (volatile uint32_t *)0x40022010;
volatile uint32_t *flashcr = (volatile uint32_t *)0x40022014;


void flashingsunlockings() {
*flashkeyr = 0x45670123;
*flashkeyr = 0xCDEF89AB;
if ((*flashcr & (1u << 31)) == 0) { // this is some fucking bullshit
    while((*flashsr & (1u << 16)) == 65536) {
   }
    *flashcr &= ~(0x3FFu << 3);
   *flashcr |= (1u << 1); 
    *flashcr |= (12u << 3); 
    *flashcr |= (1u << 16); 
    while((*flashsr & (1u << 16)) == 65536) {
    }
    *flashcr &= ~(1u << 1); 
        while((*flashsr & (1u << 16)) == 65536) {
   }
    *flashcr &= ~(0x3FFu << 3);
   *flashcr |= (1u << 1); 
    *flashcr |= (13u << 3); 
    *flashcr |= (1u << 16); 
    while((*flashsr & (1u << 16)) == 65536) {
    }
    *flashcr &= ~(1u << 1); 
        while((*flashsr & (1u << 16)) == 65536) {
   }
    *flashcr &= ~(0x3FFu << 3);
   *flashcr |= (1u << 1); 
    *flashcr |= (14u << 3); 
    *flashcr |= (1u << 16); 
    while((*flashsr & (1u << 16)) == 65536) {
    }
    *flashcr &= ~(1u << 1); 
        while((*flashsr & (1u << 16)) == 65536) {
        }
    *flashcr &= ~(0x3FFu << 3);
   *flashcr |= (1u << 1); 
    *flashcr |= (15u << 3); 
    *flashcr |= (1u << 16); 
    while((*flashsr & (1u << 16)) == 65536) {
    }
    *flashcr &= ~(1u << 1); 
}
}

void saveshit() {
    flashingsunlockings();
    *flashcr |= (1u << 0);
    uint32_t *tastyshit = (uint32_t *)shit;
    int rottenshit = 0;
    bfsflashings[0] = 0x42465331;
    bfsflashings[1] = 4;
    while((*flashsr & (1u << 16)) == 65536) {
        }
    while (rottenshit < (sizeof(shit) / sizeof(uint32_t))) {
    bfsflashings[rottenshit + 2] = tastyshit[rottenshit];
    bfsflashings[rottenshit + 3] = tastyshit[rottenshit + 1];
    while ((*flashsr & (1u << 16)) != 0) {
    }
    rottenshit += 2;
}
*flashcr &= ~(1u << 0);
}


void loadshit() {
    uint32_t *tastyshit2  = (uint32_t *)shit;
    int simonsscatfetish = 0;
    while (simonsscatfetish < (sizeof(shit) / sizeof(uint32_t))) {
        tastyshit2[simonsscatfetish] = bfsflashings[simonsscatfetish + 2];
        simonsscatfetish++;
    }

}


int createshit(const char* shitforcreating) {
    if(findshit(shitforcreating) == -1) {
if(shit[0].ifusedornotused == false) {
    copyshit2(shit[0].namings, shitforcreating);
    shit[0].sizeofdoomscroll = 0;
    shit[0].ifusedornotused = true;
}
    else if(shit[1].ifusedornotused == false) {
    copyshit2(shit[1].namings, shitforcreating);
    shit[1].sizeofdoomscroll = 0;
    shit[1].ifusedornotused = true;
    }
    else if(shit[2].ifusedornotused == false) {
    copyshit2(shit[2].namings, shitforcreating);
    shit[2].sizeofdoomscroll = 0;
    shit[2].ifusedornotused = true;
        }
            else if(shit[3].ifusedornotused == false) {
    copyshit2(shit[3].namings, shitforcreating);
    shit[3].sizeofdoomscroll = 0;
                shit[3].ifusedornotused = true;
            }
                else if(shit[4].ifusedornotused == false) {
    copyshit2(shit[4].namings, shitforcreating);
    shit[4].sizeofdoomscroll = 0;
    shit[4].ifusedornotused = true;
                }
                    else if(shit[5].ifusedornotused == false) {
    copyshit2(shit[5].namings, shitforcreating);
    shit[5].sizeofdoomscroll = 0;
    shit[5].ifusedornotused = true;
                    }
                        else if(shit[6].ifusedornotused == false) {
    copyshit2(shit[6].namings, shitforcreating);
    shit[6].sizeofdoomscroll = 0;
    shit[6].ifusedornotused = true;
                        }
                            else if(shit[7].ifusedornotused == false) {
    copyshit2(shit[7].namings, shitforcreating);
    shit[7].sizeofdoomscroll = 0;
    shit[7].ifusedornotused = true;
                            }
                                else if(shit[8].ifusedornotused == false) {
    copyshit2(shit[8].namings, shitforcreating);
    shit[8].sizeofdoomscroll = 0;
    shit[8].ifusedornotused = true;
                                }
                                    else if(shit[9].ifusedornotused == false) {
    copyshit2(shit[9].namings, shitforcreating);
    shit[9].sizeofdoomscroll = 0;
    shit[9].ifusedornotused = true;
                                    }
                                        else if(shit[10].ifusedornotused == false) {
    copyshit2(shit[10].namings, shitforcreating);
    shit[10].sizeofdoomscroll = 0;
    shit[10].ifusedornotused = true;
                                        }
                                            else if(shit[11].ifusedornotused == false) {
    copyshit2(shit[11].namings, shitforcreating);
    shit[11].sizeofdoomscroll = 0;
    shit[11].ifusedornotused = true;
                                            }
                                                else if(shit[12].ifusedornotused == false) {
    copyshit2(shit[12].namings, shitforcreating);
    shit[12].sizeofdoomscroll = 0;
    shit[12].ifusedornotused = true;
                                                }
                                                    else if(shit[13].ifusedornotused == false) {
    copyshit2(shit[13].namings, shitforcreating);
    shit[13].sizeofdoomscroll = 0;
    shit[13].ifusedornotused = true;
                                                    }
                                                        else if(shit[14].ifusedornotused == false) {
    copyshit2(shit[14].namings, shitforcreating);
    shit[14].sizeofdoomscroll = 0;
    shit[14].ifusedornotused = true;

                                                    }
                                                
                                                            else {
        uartcharacterplacement("\r\n");
        uartcharacterplacement("Filesystem full!");
        uartcharacterplacement("\r\n");
        return 0;
    }
    return 1;
}


                                                     // fuck for loops
                                                    else {
                                                        uartcharacterplacement("\r\n");
                                                        uartcharacterplacement("file already exists");
                                                        uartcharacterplacement("\r\n");
                                                                return 0;
                                                    }
                                                }


    int findshit(const char* forfindingshit) {
        int forfindingshit2;
        for(forfindingshit2 = 0; forfindingshit2 < 15; forfindingshit2++) {
            if(shit[forfindingshit2].ifusedornotused == true) {
                if(strcmp(forfindingshit, shit[forfindingshit2].namings) == 0) {
                    return forfindingshit2; // writing an fs is fucking stupid
                }
                
            }

        }
        return -1;
    }
    

    void listshit(int modesssst) {
        if(modesssst == 0) {
        uartcharacterplacement("\r\n");
        for(forlistingshit = 0; forlistingshit < 15; forlistingshit++) {
            if(shit[forlistingshit].ifusedornotused == true) {
                uartcharacterplacement(shit[forlistingshit].namings);
                uartcharacterplacement("\r\n");
            }

        }
        


    }
        else if(modesssst == 1) {
                    uartcharacterplacement("\r\n");
        for(forlistingshit = 0; forlistingshit < 15; forlistingshit++) {
            if(shit[forlistingshit].ifusedornotused == true) {
                uartcharacterplacement(shit[forlistingshit].namings);
                uartcharacterplacement(",");
                uartcharacterplacement(" ");
                uint32tonumber(shit[forlistingshit].sizeofdoomscroll);
                uartcharacterplacement(" bytes");
                uartcharacterplacement("\r\n");
        }

        }
    }
}

    void checkif() {
        if(bfsflashings[0] == 0x42465331) {
            if(bfsflashings[1] == 4) {
            loadshit();
            }
            else {
            uartcharacterplacement("Incompatible filesystem version! Writing ByteFS 4.0");
            uartcharacterplacement("\r\n");
            saveshit();  
            }
        }
        else {
            uartcharacterplacement("Invalid filesystem, writing ByteFS 4.0...");
            uartcharacterplacement("\r\n");
            saveshit();
        }
    }

    int writeshit() {
      forwritingshit = findshit(comans + nameofshit); 
      if(forwritingshit == -1) {
        uartcharacterplacement("\r\n");
        uartcharacterplacement("Invalid file!");
        uartcharacterplacement("\r\n");
        return 0;
      }
      else {
        uartcharacterplacement("\r\n");
        uartcharacterplacement("Edit: ");
        typepls();
        shit[forwritingshit].sizeofdoomscroll = lecounter;
        uartcharacterplacement("\r\n");
        copyshit2(shit[forwritingshit].doomscroll, comans);
        return 1;
    }
    }

    int readshit() {
        int forreadingshit;
        forreadingshit = findshit(comans + nameofshit);
        if(forreadingshit == -1) {
          uartcharacterplacement("\r\n");
          uartcharacterplacement("Invalid file!");
          uartcharacterplacement("\r\n");
          return 0;
        }
        else {
          uartcharacterplacement("\r\n");
          uartcharacterplacement(shit[forreadingshit].doomscroll);
          uartcharacterplacement("\r\n");
          return 1;
        }
    }

    int removeshit() {
        forremovingshit = findshit(comans + nameofshit);
      if(forremovingshit == -1) {
        uartcharacterplacement("\r\n");
        uartcharacterplacement("Invalid file!");
        uartcharacterplacement("\r\n");
        return 0;
      }
      else {
    shit[forremovingshit].ifusedornotused = false;
    shit[forremovingshit].sizeofdoomscroll = 0;
    shit[forremovingshit].doomscroll[0] = '\0';
        return 1;
      }

    }