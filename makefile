

# for github actions and easier building i suppose
CXX = arm-none-eabi-g++
OBJCOPY = arm-none-eabi-objcopy
FLAGS = -mcpu=cortex-m0plus -mthumb -ffreestanding -fno-exceptions -fno-rtti -O0

all: byteos.bin

kernel.o: src/kernel.cpp
	$(CXX) $(FLAGS) -c src/kernel.cpp -o kernel.o

startup.o: src/startup.cpp
	$(CXX) $(FLAGS) -c src/startup.cpp -o startup.o

byteos.elf: startup.o kernel.o linker.ld
	$(CXX) -nostdlib -mcpu=cortex-m0plus -mthumb -T linker.ld startup.o kernel.o -o byteos.elf

byteos.bin: byteos.elf
	$(OBJCOPY) -O binary byteos.elf byteos.bin

clean:
	rm -f *.o *.elf *.bin
