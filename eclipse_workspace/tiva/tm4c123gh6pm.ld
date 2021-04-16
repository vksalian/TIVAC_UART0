ENTRY(Reset_Handler)

MEMORY
{
    FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 256K
    SRAM(rwx)  : ORIGIN = 0x20000000, LENGTH = 32K
}

SECTIONS
{
    /* .text section for executable file */
    .text :
    {
        /* Note: The order must be .isr_vector, .text, .rodata */
        *(.isr_vector)  /* Merge all the .isr_vector sections of all input object (*.o) files */
        *(.text)        /* Merge all the .text sections of all input object (*.o) files */
        *(.text.*)      /* Merge all the .text.<func_name> sections of all input object (*.o) files */
        *(.rodata)      /* Merge all the .rodata sections of all input object (*.o) files */
        *(.rodata.*)    /* Merge all the .rodata.* sections of all input object (*.o) files */

        . = ALIGN(4);   /* Align the end address to 4-byte boundary or word boundary.
                           If not aligned, sometimes the size calculation goes wrong */
        _e_text = .;    /* . = location counter and _e_text is a linker symbol and has end address of .text (; is must for this) */

    } > FLASH

    /* .data section for executable file */
    .data :
    {
        _s_data = .;    /* . = location counter and _s_data is a linker symbol and has start address of .data (; is must for this) 
                           Location counter always tracks vma */

        *(.data)        /* Merge all the .data sections of all input object (*.o) files */
        *(.data.*)      /* Merge all the .data.* sections of all input object (*.o) files */

        . = ALIGN(4);   /* Align the end address to 4-byte boundary or word boundary.
                           If not aligned, sometimes the size calculation goes wrong */

        _e_data = .;    /* . = location counter and _e_data is a linker symbol and has end address of .data (; is must for this) 
                           Location counter always tracks vma */
    } > SRAM AT> FLASH

    /* .bss section for executable file */
    .bss :
    {
        _s_bss = .;     /* . = location counter and _s_bss is a linker symbol and has start address of .bss (; is must for this) 
                           Location counter always tracks vma */

        *(.bss)         /* Merge all the .bss sections of all input object (*.o) files */
        *(.bss.*)       /* Merge all the .bss.* sections of all input object (*.o) files */
        *(COMMON*)      /* Merge all the .COMMON sections of all input object (*.o) files 
                           Note: In some cases, the uninitialized variables that are supposed 
                           to get listed under .bss will be listed under COMMON section. So
                           we have to include COMMON sections here in .bss section */

        . = ALIGN(4);   /* Align the end address to 4-byte boundary or word boundary.
                           If not aligned, sometimes the size calculation goes wrong */

        _e_bss = .;     /* . = location counter and _e_bss is a linker symbol and has end address of .bss (; is must for this) 
                           Location counter always tracks vma */
    } > SRAM
}