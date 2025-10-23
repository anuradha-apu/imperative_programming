/* Version 6: BROKEN - Operand Numbering Error
 * This example demonstrates a COMMON ERROR:
 * - Incorrect operand numbering
 * - Off-by-one errors with empty output sections
 * 
 * Compilation: gcc -o version6 version6_operand_numbering_error.c
 * Status: FAILS ✗
 * 
 * ERROR MESSAGE YOU'LL SEE:
 * error: invalid 'asm': operand number out of range
 * 
 * PURPOSE: Learn the operand numbering rules
 */

#include <stdio.h>

int main() {
    int source = 42;
    int destination = 0;
    int *p_src = &source;
    int *p_dst = &destination;
    
    printf("Before: source = %d, destination = %d\n", source, destination);
    
    // THIS WILL NOT COMPILE!
    __asm__ __volatile__ (
        ".intel_syntax noprefix\n\t"
        "mov eax, [%1]\n\t"      // ERROR: %1 doesn't exist!
        "mov [%2], eax\n\t"      // ERROR: %2 doesn't exist!
        ".att_syntax prefix\n\t"
        :                        // Empty output section
        : "r" (p_src), "r" (p_dst)  // These are %0 and %1, NOT %1 and %2!
        : "eax", "memory"
    );
    
    printf("After: source = %d, destination = %d\n", source, destination);
    
    return 0;
}

/*
 * WHY THIS FAILS:
 * 
 * OPERAND NUMBERING RULE:
 * - Output operands are numbered FIRST: %0, %1, %2, ...
 * - Input operands CONTINUE the numbering
 * 
 * In this code:
 *     :                        ← No outputs (empty)
 *     : "r" (p_src), "r" (p_dst)  ← First input is %0, second is %1
 * 
 * MISTAKE:
 * The code uses %1 and %2, expecting them to be p_src and p_dst
 * But since there are NO outputs, inputs start at %0!
 * 
 * CORRECT NUMBERING:
 *     %0 = p_src (first input)
 *     %1 = p_dst (second input)
 *     %2 = doesn't exist!
 * 
 * WHAT HAPPENS:
 * Compiler sees %2 but only has operands %0 and %1
 * Result: "operand number out of range"
 * 
 * THE FIX:
 * Change %1 to %0 and %2 to %1:
 * 
 * __asm__ __volatile__ (
 *     ".intel_syntax noprefix\n\t"
 *     "mov eax, [%0]\n\t"      // %0 = first input
 *     "mov [%1], eax\n\t"      // %1 = second input
 *     ".att_syntax prefix\n\t"
 *     :                        // Empty
 *     : "r" (p_src), "r" (p_dst)
 *     : "eax", "memory"
 * );
 * 
 * GENERAL RULE:
 * 
 * With outputs:
 *     : "=r" (out1), "=r" (out2)  ← %0, %1
 *     : "r" (in1), "r" (in2)       ← %2, %3
 * 
 * Without outputs:
 *     :                            ← Empty
 *     : "r" (in1), "r" (in2)       ← %0, %1
 * 
 * DEBUGGING TIP:
 * Count your operands carefully:
 * 1. Count all outputs (even if empty = 0)
 * 2. Inputs continue from that number
 * 3. Use a comment to mark each operand
 * 
 * Example:
 *     : "=r" (out1)        // %0
 *     : "r" (in1),         // %1
 *       "r" (in2)          // %2
 * 
 * TRY COMPILING THIS:
 * You SHOULD see an error. Try to fix it before looking at version4!
 */
