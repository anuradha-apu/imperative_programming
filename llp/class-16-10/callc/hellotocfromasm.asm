
	extern test
	extern exit

section .text

global main
main:
	
	mov rsi,1
	mov rdi,2
	call test

	mov rdi, rax
	mov rax, 60
	syscall
	

	
