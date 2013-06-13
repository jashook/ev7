; boot.asm

   mov   ax, 0x07c0
   mov   ds, ax

   mov   si, msg

ch_loop: lodsb

   or    al, al   ; zero = end of string

   jz hang

   mov   ah, 0x0E

   int   0x10

   jmp   ch_loop

hang:

   jmp hang

msg   db 'Hello World, OS :)', 13, 10, 0

   times 512-($-$$) db 0

   db 0x55

   db 0xAA