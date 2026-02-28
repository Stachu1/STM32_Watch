ENTRY(ResetHandler)

MEMORY
{
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 32K
    RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 8K
}

_Min_Heap_Size = 0x0000;
_Min_Stack_Size = 0x1000;

SECTIONS
{
    .isr_vector :
    {
        . = ALIGN(8);
        KEEP(*(.isr_vector))
        . = ALIGN(8);
    } >FLASH

    .text :
    {
        . = ALIGN(8);
        _text_start = .;
        *(.text)
        *(.text*)
        *(.glue_7)
        *(.glue_7t)
        *(.eh_frame)

        KEEP(*(.init))
        KEEP(*(.fini))

        . = ALIGN(8);
        _text_end = .;
    } >FLASH

    .rodata :
    {
        . = ALIGN(8);

        *(.rodata)
        *(.rodata*)

        . = ALIGN(8);
    } >FLASH

    .ARM.extab :
    {
        . = ALIGN(8);
        *(.ARM.extab* .gnu.linkonce.armextab.*)
        . = ALIGN(8);
    } >FLASH

    .ARM :
    {
        . = ALIGN(8);
        __exidx_start = .;
        *(.ARM.exidx*)
        __exidx_end = .;
    } >FLASH

    _data_rom = LOADADDR(.data);

    .data :
    {
        . = ALIGN(8);
        _data_ram = .;
        *(.data)
        *(.data*)

        . = ALIGN(8);
        _data_ram_end = .;
    } >RAM AT> FLASH

    .bss (NOLOAD) :
    {
        . = ALIGN(8);
        _sbss = .;

        *(.bss)
        *(.bss*)
        *(COMMON)

        . = ALIGN(8);
        _ebss = .;
    } >RAM

    ._user_heap_stack (NOLOAD) :
    {
        . = ALIGN(8);
        PROVIDE( end = . );
        PROVIDE( _end = . );
        _heap_start = .;
        . = . + _Min_Heap_Size;
        . = ALIGN(8);
        _heap_end = .;
        _stack_start = .;
        . = . + _Min_Stack_Size;
        . = ALIGN(8);
        _stack_end = .;
        _stack_top = .;
    } >RAM

    /DISCARD/ :
    {
        /*libc.a ( * )*/
        /*libm.a ( * )*/
        /*libgcc.a ( * )*/
    }
}