<img width="300" alt="Logo (4)" src="https://github.com/user-attachments/assets/a8c3e7ef-c88a-4c7a-8d6c-3ff36cd6a040" />

# byteos revived
> byteos is an OS written in C++ for ARMv6-M!

## Support

A board with the `STM32C031F6P6 MCU` is required or `Renode` can be used instead.

## Building

Install the following packages :-
* arm-none-eabi-gcc
* arm-none-eabi-binutils
* make

And then run the following :-
```BASH
make all
```
> The above produces byteos.bin which is the built binary

## Features
Currently byteos only has a single command and that is `help`

## Credits
* **wagiminator/Stefan Wagner** - for his original board that I based my board off of.
* **zalanwastaken** - for writing the readme

## Licenses used: 
* MIT (byteos, embedded artistry's strcmp)
* CC-BY-SA 3.0 (wagiminators/Stefan Wagner's board)

**WARNING**: The board is in development and the firmware has not been tested on **real hardware**, only in Renode.
