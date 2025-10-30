;;  immediate addressing
section .text
global _start

_start:
    ; Immediate - using constant values directly
    mov ebx, 100        ; EbX = 100
    add ebx, 15         ; EBX = EBX + 15
    sub ebx, 25         ; EbX = EbX - 25
    
    mov eax, 1
    int 0x80
