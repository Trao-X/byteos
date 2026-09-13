    /* bos linker  for bos development board (byteos) */
    /* love v3x 2026 */

ENTRY(plshandletheresetsalrthx) /* pointless ass shit */

MEMORY {
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 128K
    RAM  (rwx)  : ORIGIN = 0x20000000, LENGTH = 36K
}

_endoflestack = ORIGIN(RAM) + LENGTH(RAM);

SECTIONS {
    .vectors : { KEEP(*(.vectors)) } > FLASH
    .text    : { *(.text*) *(.rodata*) } > FLASH
    .data    : { *(.data*) } > RAM
    .bss     : { *(.bss*) *(COMMON) } > RAM
}
