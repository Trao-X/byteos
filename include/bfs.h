#pragma once

int findshit(const char* forfindingshit);
void createshit(const char* shitforcreating);
void listshit();
void writeshit();
void checkif();
void saveshit();
void loadshit();
struct filings {
    char namings[32];
    char doomscroll[256];
    int sizeofdoomscroll;
    bool ifusedornotused;
}; 
extern filings shit[15];