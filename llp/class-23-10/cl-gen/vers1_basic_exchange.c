/* Version 1: Basic Register Exchange
 * This example demonstrates:
 * - Basic inline assembly syntax
 * - Intel syntax usage
 * - Register operands with "+r" constraint
 * - The XCHG instruction
 * 
 * Compilation: gcc -o version1 version1_basic_exchange.c
 * Status: WORKS ✓
 */

#include <stdio.h>

int main() {
    int var1 = 10;
    int var2 = 20;
    
    printf("Before exchange:\n");
    printf("var1 = %d\n", var1);
    printf("var2 = %d\n", var2);
    
    // Inline assembly block
    __asm__ __volatile__ (
        ".intel_syntax noprefix\n\t"    // Switch to Intel syntax
        "mov eax, %0\n\t"                // Load var1 into EAX
        "mov ebx, %1\n\t"                // Load var2 into EBX
        "xchg eax, ebx\n\t"              // Exchange EAX and EBX
        "mov %0, eax\n\t"                // Store EAX back to var1
        "mov %1, ebx\n\t"                // Store EBX back to var2
        ".att_syntax prefix\n\t"         // Switch back to AT&T syntax
        : "+r" (var1), "+r" (var2)       // Output operands (read-write)
        :                                 // No input-only operands
        : "eax", "ebx"                   // Clobbered registers
    );
    
    printf("\nAfter exchange:\n");
    printf("var1 = %d\n", var1);
    printf("var2 = %d\n", var2);
    
    return 0;
}

/*
 * LEARNING POINTS:
 * 
 * 1. Operand Binding:
 *    : "+r" (var1), "+r" (var2)
 *      ^^^^         ^^^^
 *      %0           %1
 * 
 * 2. Constraint "+r":
 *    + = read-write (both input and output)
 *    r = use any general-purpose register
 * 
 * 3. Clobber List:
 *    Lists registers modified by assembly code
 *    Prevents compiler from using them incorrectly
 * 
 * Expected Output:
 * Before exchange:
 * var1 = 10
 * var2 = 20
 * 
 * After exchange:
 * var1 = 20
 * var2 = 10
 */
