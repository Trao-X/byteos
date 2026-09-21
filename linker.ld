/* bos linker  for bos development board (byteos) */
    /* love v3x 2026 */

ENTRY(plshandletheresetsalrthx) /* pointless ass shit */

MEMORY {
    FLASH : ORIGIN = 0x08000000, LENGTH = 24K
    RAM  (rwx)  : ORIGIN = 0x20000000, LENGTH = 12K /* fixed ram/flash size cuz was outdated iggg */
    BFSFLASHINGS : ORIGIN = 0x08006000, LENGTH = 8k
}

_endoflestack = ORIGIN(RAM) + LENGTH(RAM);

SECTIONS {
    .vectors : { KEEP(*(.vectors)) } > FLASH
    .text    : { *(.text*) *(.rodata*) } > FLASH
.data :
{
    _data_start = .;
    *(.data*)
    _data_end = .;
} > RAM AT > FLASH

_data_flash_start = LOADADDR(.data);

.bss :
{
    _bss_start = .;
    *(.bss*) *(COMMON)
    _bss_end = .;
} > RAM
} /* copypasted bss and data ferom some website cuz couldnt bother to learn how to write a fucking linker */
