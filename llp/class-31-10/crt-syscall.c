/* vers1-64bit - 64-bit int 0x80 version */


void _exit(int status) {
    __asm__ __volatile__ (
        ".intel_syntax noprefix\n\t"
        "mov eax, 60\n\t"               // 64-bit exit syscall number
        "mov edi, %0\n\t"               // status parameter (edi instead of ebx)
        "syscall\n\t"                   // syscall instead of int 0x80
        ".att_syntax prefix"
        :
        : "r" (status)
        : "rax", "rdi"                  // Update clobbered registers
    );

}

void _start() {
    int result = main();
    _exit(result);
}

int main() {
    return 42;
}

/*gcc -m64 -nostdlib <filename>

Note the changes:
int 0x80 → syscall
mov eax, 1 → mov eax, 60 (64-bit exit syscall number)
mov ebx, %0 → mov edi, %0 (64-bit parameter register)
"eax", "ebx" → "rax", "rdi" (updated clobber list)


Cleaner version is to keep it 64 bit clean:
void _exit(int status) {
    __asm__ __volatile__ (
        ".intel_syntax noprefix\n\t"
        "mov rax, 60\n\t"               // Use rax for 64-bit
        "mov rdi, %0\n\t"               // Use rdi for 64-bit  
        "syscall\n\t"
        ".att_syntax prefix"
        :
        : "r" (status)
        : "rax", "rdi"
    );
}
*/
