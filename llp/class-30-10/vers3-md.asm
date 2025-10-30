section .data
    number  dd 42       ; Define doubleword (4 bytes)
    result  dd 0

section .text
global _start

_start:
    ; Direct memory - accessing variables by name
    mov eax, [number]   ; EAX = value at 'number' address (42)
    add eax, 10
    mov [result], eax   ; Store result in memory
    
    mov eax, 1
    int 0x80
