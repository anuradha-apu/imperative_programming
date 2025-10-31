/* vers1-64bit - 64-bit int 0x80 version */
void _exit(int status) {
    __asm__ __volatile__ (
        ".intel_syntax noprefix\n\t"
        "mov rax, 1\n\t"                // 32-bit syscall number
        "mov rbx, %0\n\t"               // status (only uses lower 32 bits)
        "int 0x80\n\t"
        ".att_syntax prefix"
        :
        : "r" ((long)status)             // cast to ensure 32-bit value
        : "rax", "rbx"
    );
    
}

void _start() {
    int result = main();
    _exit(result);
}

int main() {
    return 42;
}

//gcc -m64 -nostdlib <filename>
