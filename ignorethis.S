    // bos entry code for bos development board (byteos)
    // credits: osdev team (https://wiki.osdev.org/QEMU_AArch64_Virt_Bare_Bones) because i am NOT writing asm
    // DEPRECATED CODE THAT I LEFT IN BY ACCIEDENT 


.global _start
_start:
    ldr x30, =stack_top
    mov sp, x30
    bl  boskernel
    b   .
