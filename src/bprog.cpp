// byte Programming Interpreter 2.0 (informally bProg) designed for byteOS
// credits: v3x, osdev (credits for software used outside this file in other files)

#include "../include/kernel.h"
#include "../include/strcmp.h"
#include "../include/bfs.h"

void bprogprint(const char* filenam) {
    int indexofshit = findshit(filenam);
int leng = 0;
while (filenam[leng] != '\0') {
leng++;
      }
if(leng > 3) {
}
     else {
                uartcharacterplacement("\r\n");
                uartcharacterplacement("File is not a bProg program or doesn't exist!");
                uartcharacterplacement("\r\n");
                return;
                
            }

        if (filenam[leng - 3] == '.') {
        }
     else {
                uartcharacterplacement("\r\n");
                uartcharacterplacement("File is not a bProg program or doesn't exist!");
                uartcharacterplacement("\r\n");
                return;
                
            }
        if (filenam[leng - 2] == 'b') {
        }
                    else {
                uartcharacterplacement("\r\n");
                uartcharacterplacement("File is not a bProg program or doesn't exist!");
                uartcharacterplacement("\r\n");
                return;
                    }

        if (filenam[leng - 1] == 'p') {
        }
                else {
                uartcharacterplacement("\r\n");
                uartcharacterplacement("File is not a bProg program or doesn't exist!");
                uartcharacterplacement("\r\n");
                return; // yanderedev reference
            }
        
     if(indexofshit == -1) {
    uartcharacterplacement("\r\n");
    uartcharacterplacement("Invalid file!");
    uartcharacterplacement("\r\n");
    }           
         
if(indexofshit != -1) {
    int semishit2 = 0;
    char *hi = shit[indexofshit].doomscroll; while (*hi != '\0') {
                int semishit = 0;
            while(hi[semishit] != '\0') {
            semishit++;;
        if(semishit[hi] == ';') {    
            semishit[hi] = '\0'; // what the FUCK does run normal bprog instructions afterwards mean
            semishit2 = 1;
            break;
    }

}



    if (echolaid(hi, "output(uart) ") == 1) {
    uartcharacterplacement("\r\n");
    uartcharacterplacement(hi + 13);
    uartcharacterplacement("\r\n");
    }
    else if (echolaid(hi, "output(uart, loop) ") == 1) {
        while(strcmp(maxinput, "exit") != 0) {
            uartcharacterplacement("\r\n");
            uartcharacterplacement(hi + 19);
            uartcharacterplacement("\r\n");
            typepls();
        }
    }
    else if (echolaid(hi, "execute(commands) ") == 1) {
        
        comans = (hi + 18);
        uartcharacterplacement("\r\n");
        termcommandsssss();
        uartcharacterplacement("\r\n");
        }
    else {
        uartcharacterplacement("Not implemented!");
    }
        if(semishit2 == 0) {
            break;
        }
        if(semishit2 == 1) {
            semishit[hi] = ';';
            hi = hi + semishit + 1;
            semishit2 = 0;
            }

}
        }
    }
        

