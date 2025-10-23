/* Version 3: BROKEN - Intel Syntax + Memory Operands
 * This example demonstrates a COMMON ERROR:
 * - Trying to use "m" constraint with Intel syntax
 * - This will NOT compile
 * 
 * Compilation: gcc -o version3 version3_broken_memory.c
 * Status: FAILS ✗
 * 
 * ERROR MESSAGE YOU'LL SEE:
 * Error: junk `(%rbp)' after expression
 * 
 * PURPOSE: Learn why Intel syntax + "m" constraint doesn't work
 */

#include <stdio.h>

int main() {
    int source = 42;
    int destination = 0;
    
    printf("Before: source = %d, destination = %d\n", source, destination);
    
    // THIS WILL NOT COMPILE!
    __asm__ __volatile__ (
        ".intel_syntax noprefix\n\t"
        "mov eax, %1\n\t"        // ERROR: "m" constraint with Intel syntax
        "mov %0, eax\n\t"        // ERROR: Same problem
        ".att_syntax prefix\n\t"
        : "=m" (destination)     // "m" = memory operand
        : "m" (source)           // "m" = memory operand
        : "eax"
    );
    
    printf("After: source = %d, destination = %d\n", source, destination);
    
    return 0;
}

/*
 * WHY THIS FAILS:
 * 
 * 1. GCC expands "m" constraint to AT&T syntax: -8(%rbp)
 * 2. Your instruction becomes: mov eax, -8(%rbp)
 * 3. Intel syntax parser doesn't understand AT&T (%rbp) notation
 * 4. Result: Syntax error!
 * 
 * WHAT HAPPENS BEHIND THE SCENES:
 * 
 * You write:
 *     "mov eax, %1" with : "m" (source)
 * 
 * GCC expands to:
 *     mov eax, -8(%rbp)     ← AT&T memory reference
 * 
 * Intel parser sees:
 *     -8(%rbp) ← What is this? ERROR!
 * 
 * THE FUNDAMENTAL ISSUE:
 * - GCC's inline assembly was designed for AT&T syntax
 * - Memory operands ("m") generate AT&T-style references
 * - Intel syntax directives can't parse AT&T memory syntax
 * 
 * SOLUTIONS:
 * See version4 (pointers) or version5 (AT&T syntax)
 * 
 * TRY COMPILING THIS:
 * You SHOULD see an error. This is intentional!
 * Understanding why it fails is crucial for mastering inline assembly.
 */
