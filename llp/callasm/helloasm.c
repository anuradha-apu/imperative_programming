#include <stdio.h>

// Declare the external assembly function
extern void _print_hello_nasm();

int main() {
    printf("Calling NASM function...\n");
    _print_hello_nasm(); // Call the assembly function
    printf("NASM function returned.\n");
    return 0;
}
