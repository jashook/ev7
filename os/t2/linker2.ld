ENTRY (_start)

SECTIONS{
    . = 0xC0100400;  /* 3G + 1M + skip 1024 bytes ELF header */

    ev7_start = .;

    .text : {
        *bootstrap_a.o(.text*)
        *(.multiboot)
        *(.text*)
        *(.gnu.linkonce.t*)
    }

    .rodata ALIGN(4096) : {

        /* . = ALIGN(8); */
        ctor_start = .;
        *(.ctor*)
        ctor_end = .;

        dtor_start = .;
        *(.dtor*)
        dtor_end = .;

        *(.rodata*)
        *(.gnu.linkonce.r*)
    }

    .data ALIGN(4096) : {
        *(.data*)
        *(.gnu.linkonce.d*)
    }
    
    .symtab ALIGN(4096) : {
        *(.symtab*)
        *(.strtab*)
        *(.shstrtab*)
    }
    
    .bss ALIGN(4096) : {
        sbss = .;
        *(COMMON*)
        *(.bss*)
        *(.gnu.linkonce.b*)
        ebss = .;
    }

    . = ALIGN(4096);
    _kernel_end = .;
    end = .;

    /DISCARD/ : {
        *(.comment)
        *(.eh_frame) /* You should discard this unless you're implementing runtime support for C++ exceptions. */
    }

}
