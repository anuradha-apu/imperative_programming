section .data
    message db "Hello World from NASM!", 0xA, 0 ; The string to print, with a newline and null terminator

section .text
    global _print_hello_nasm ; Make the function visible to the linker

_print_hello_nasm:
    ; Standard Linux x86_64 syscall for write (syscall number 1)
    mov rax, 1                  ; syscall number for write
    mov rdi, 1                  ; file descriptor 1 (stdout)
    mov rsi, message            ; address of the string to write
    mov rdx, 23                 ; length of the string (including newline)
    syscall                     ; execute syscall

    ret                         ; return from the function
