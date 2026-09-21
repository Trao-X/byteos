#pragma once

int findshit(const char* forfindingshit);
int createshit(const char* shitforcreating);
void listshit();
int writeshit();
void checkif();
void saveshit();
void loadshit();
int readshit();
int removeshit();
struct filings {
    char namings[256];
    char doomscroll[256];
    int sizeofdoomscroll;
    bool ifusedornotused;
}; 
extern filings shit[15];
extern int nameofshit;
extern int forwritingshit;
extern int forremovingshit;