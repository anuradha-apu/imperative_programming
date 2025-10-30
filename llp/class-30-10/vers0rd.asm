section .text
global _start

_start:
    ; Register direct - operating directly on registers
    mov rax, 10         ; RAX = 10
    mov rbx, 20         ; RBX = 20
    add rbx, rax        ; RAX = EAX + EBX (30)


			; Exit
	
    mov rax, 1
    int 0x80
