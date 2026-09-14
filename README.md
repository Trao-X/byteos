<img width="512" height="512" alt="Logo (4)" src="https://github.com/user-attachments/assets/a8c3e7ef-c88a-4c7a-8d6c-3ff36cd6a040" />


hi im v3x and this is my first non vibecoded os!

the story started when i made the shit vibecodeos byteos and that is bad, i want to get into a good cs college so i restarted work on byteos, this time without vibecoding it.

byteos is a c++ ARMv6-M os started yesterday! it utilizes uart so far, what it does not do is utilize the other shit on the board i made (in the hardware folder)

you need a board with the STM32C031F6P6 mcu to use byteos
compilation instructions

git clone the repo with git clone https://github.com/vthreex/byteos
now you must do `arm-none-eabi-g++ -mcpu=cortex-m0plus -mthumb -ffreestanding -fno-exceptions -fno-rtti -O0 -c src/kernel.cpp -o kernel.o` 
and hten `arm-none-eabi-g++ -mcpu=cortex-m0plus -mthumb -ffreestanding -fno-exceptions -fno-rtti -O0 -c src/startup.cpp -o startup.o`
and finally `arm-none-eabi-g++ -nostdlib -mcpu=cortex-m0plus -mthumb -T linker.ld startup.o kernel.o -o byteos.elf`
actually i lied that wasnt the final line `arm-none-eabi-objcopy -O binary byteos.elf byteos.bin` this is

beautiful copypasted commands!

credits to: wagiminator for his original board that i based my board off because i have no fucking idea how designing pcbs work and the osdev wiki it really helped me and credits to the person who made the linker that i forgot the name of (ok i checked its the osdev one maybe idk)
good luck to anyone trying to flash this!
special fuck you torwards arthurus36 and the kicad team because the software is annoying to use
the pcb took me multiple hours 4-6 to do while the os took me 2-3-ish
love you easyeda team for making your software not cancerous to use unlike fucking kicad


