;;;  Build with nasm -f elf64 -F dwarf itoa.asm -o itoa.o
;;; ld itoa.o -o itoa
section .data
    number dq 12345       ; Your number
    buffer times 16 db 0

section .text
global _start

_start:
    mov rax, [number]     ; Load the number
    call int_to_string     ; Returns string in RSI, length in RBX
    
    ; Syscall to print the number
    mov rax, 1            ; sys_write
    mov rdi, 1            ; stdout  
    ; RSI already contains the string pointer from int_to_string
    ; RBX already contains the length from int_to_string
    mov rdx, rbx          ; length
    syscall
    
    ; Exit
    mov rax, 60           ; sys_exit
    mov rdi, 0
    syscall

int_to_string:
    mov rdi, buffer + 15  ; Point to end of buffer
    mov byte [rdi], 0     ; Null terminator (optional)
    mov rbx, 0            ; Counter for length
    
.convert_loop:
    xor rdx, rdx          ; Clear RDX for division
    mov rcx, 10           ; Divisor (moved inside to preserve across calls)
    div rcx               ; RAX = quotient, RDX = remainder
    add dl, '0'           ; Convert digit to ASCII
    dec rdi               ; Move buffer pointer backwards
    mov [rdi], dl         ; Store digit
    inc rbx               ; Increment length counter
    
    test rax, rax         ; Check if quotient is zero
    jnz .convert_loop     ; If not, continue
    
    mov rsi, rdi          ; Return pointer to start of string in RSI
    ret
