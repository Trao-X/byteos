// byte file system
// designed for byteOS arm edition
// ver 1.0.0

#include <stdint.h>
#include "../include/strcmp.h"
#include "../include/kernel.h"
#include "../include/bfs.h"

    char namings[32];
    char doomscroll[256];
    int sizeofdoomscroll;
    bool ifusedornotused;

filings shit[15];

void copyshit2(char* destination, const char* sourc) {
  while ((*destination++ = *sourc++));
}



void createshit(const char* shitforcreating) {
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
                                                    } // fuck for loops

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

    void listshit() {
        int forlistingshit;
        uartcharacterplacement("\r\n");
        for(forlistingshit = 0; forlistingshit < 15; forlistingshit++) {
            if(shit[forlistingshit].ifusedornotused == true) {
                uartcharacterplacement("\r\n");
                uartcharacterplacement(shit[forlistingshit].namings);
                uartcharacterplacement("\r\n");
            }

        }
        

    }
