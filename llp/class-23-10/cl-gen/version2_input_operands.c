/* Version 2: Input-Only Operands
 * This example demonstrates:
 * - Separate input and output operands
 * - "=r" write-only constraint
 * - "r" read-only constraint
 * - Integer multiplication (IMUL)
 * 
 * Compilation: gcc -o version2 version2_input_operands.c
 * Status: WORKS ✓
 */

#include <stdio.h>

int main() {
    int num1 = 5;
    int num2 = 7;
    int result = 0;
    
    printf("Input values:\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);
    
    // Inline assembly: result = num1 * num2
    __asm__ __volatile__ (
        ".intel_syntax noprefix\n\t"
        "mov eax, %1\n\t"        // Load num1 (input) into EAX
        "imul eax, %2\n\t"       // Multiply EAX by num2 (input)
        "mov %0, eax\n\t"        // Store result into output variable
        ".att_syntax prefix\n\t"
        : "=r" (result)          // OUTPUT: write-only (%0)
        : "r" (num1), "r" (num2) // INPUTS: read-only (%1, %2)
        : "eax"                  // Clobbered register
    );
    
    printf("\nAfter multiplication:\n");
    printf("result = %d\n", result);
    
    return 0;
}

/*
 * LEARNING POINTS:
 * 
 * 1. Operand Numbering:
 *    : "=r" (result)          ← %0 (outputs numbered first)
 *    : "r" (num1), "r" (num2) ← %1, %2 (inputs continue numbering)
 * 
 * 2. Constraint Types:
 *    "=r" - Write-only output (result is only written, never read)
 *    "r"  - Read-only input (num1, num2 are only read, never modified)
 *    "+r" - Read-write (from previous example)
 * 
 * 3. Why Separate Input/Output?
 *    - num1 and num2 are NEVER modified by assembly
 *    - result is ONLY written to (not read first)
 *    - Compiler can optimize better knowing this
 * 
 * Expected Output:
 * Input values:
 * num1 = 5
 * num2 = 7
 * 
 * After multiplication:
 * result = 35
 */
