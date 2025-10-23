/* Version 5: AT&T Syntax with Memory Operands (ALTERNATIVE SOLUTION)
 * This example demonstrates:
 * - Using AT&T syntax for direct memory operations
 * - "m" constraint works naturally with AT&T
 * - AT&T syntax rules and conventions
 * 
 * Compilation: gcc -o version5 version5_att_memory.c
 * Status: WORKS ✓
 * 
 * Use this approach when you need direct memory operands!
 */

#include <stdio.h>

int main() {
    // Example 1: Memory to Memory copy
    int source = 42;
    int destination = 0;
    
    printf("=== Example 1: Memory-to-Memory Copy ===\n");
    printf("Before: source = %d, destination = %d\n", source, destination);
    
    __asm__ __volatile__ (
        "movl %1, %%eax\n\t"     // AT&T: source first, dest second
        "movl %%eax, %0\n\t"     // Store to destination
        : "=m" (destination)     // Output: memory
        : "m" (source)           // Input: memory
        : "eax"
    );
    
    printf("After:  source = %d, destination = %d\n\n", source, destination);
    
    
    // Example 2: Arithmetic on memory operand
    int data = 15;
    int output = 0;
    
    printf("=== Example 2: Add and Store ===\n");
    printf("Before: data = %d\n", data);
    
    __asm__ __volatile__ (
        "movl %1, %%eax\n\t"     // Load from memory
        "addl $20, %%eax\n\t"    // Add immediate value (note $ prefix)
        "movl %%eax, %0\n\t"     // Store to memory
        : "=m" (output)
        : "m" (data)
        : "eax"
    );
    
    printf("After:  output = %d\n\n", output);
    
    
    // Example 3: Multiple operations
    int value1 = 99;
    int value2 = 0;
    
    printf("=== Example 3: Memory Operations ===\n");
    printf("Before: value1 = %d, value2 = %d\n", value1, value2);
    
    __asm__ __volatile__ (
        "movl %1, %%eax\n\t"
        "movl %%eax, %0\n\t"
        : "=m" (value2)
        : "m" (value1)
        : "eax"
    );
    
    printf("After:  value1 = %d, value2 = %d\n\n", value1, value2);
    
    
    // Example 4: Using multiple registers
    int num1 = 10;
    int num2 = 20;
    int sum = 0;
    
    printf("=== Example 4: Addition ===\n");
    printf("Before: num1 = %d, num2 = %d\n", num1, num2);
    
    __asm__ __volatile__ (
        "movl %1, %%eax\n\t"     // Load num1
        "movl %2, %%ebx\n\t"     // Load num2
        "addl %%ebx, %%eax\n\t"  // Add ebx to eax
        "movl %%eax, %0\n\t"     // Store result
        : "=m" (sum)
        : "m" (num1), "m" (num2)
        : "eax", "ebx"
    );
    
    printf("After:  sum = %d\n", sum);
    
    return 0;
}

/*
 * AT&T SYNTAX RULES:
 * 
 * 1. Direction: SOURCE, DESTINATION (opposite of Intel!)
 *    movl %eax, %ebx    → Move EAX to EBX
 *    Intel: mov ebx, eax
 * 
 * 2. Register Prefix: %% in inline assembly (% in pure assembly)
 *    %%eax, %%ebx, %%ecx
 * 
 * 3. Immediate Prefix: $ for constants
 *    addl $5, %%eax     → Add 5 to EAX
 * 
 * 4. Size Suffixes:
 *    movb - byte (8-bit)
 *    movw - word (16-bit)
 *    movl - long (32-bit)
 *    movq - quad (64-bit)
 * 
 * 5. Memory Addressing:
 *    offset(%base)           → [base + offset]
 *    offset(%base, %index)   → [base + index + offset]
 *    offset(%base, %index, scale) → [base + index*scale + offset]
 * 
 * WHY "m" WORKS WITH AT&T:
 * 
 * When you write:
 *     "movl %0, %%eax" with : "m" (variable)
 * 
 * GCC expands to:
 *     movl -8(%rbp), %eax   ← Valid AT&T syntax!
 * 
 * AT&T syntax naturally understands AT&T memory references
 * No conflict, no errors!
 * 
 * COMPARISON WITH INTEL:
 * 
 * Intel Syntax:
 *     mov eax, [rsi]
 *     add eax, 5
 *     mov [rdi], eax
 * 
 * AT&T Syntax:
 *     movl (%rsi), %eax
 *     addl $5, %eax
 *     movl %eax, (%rdi)
 * 
 * WHEN TO USE AT&T:
 * - Need direct memory operands ("m" constraint)
 * - Working with existing AT&T assembly code
 * - Default GCC inline assembly style
 * 
 * Expected Output:
 * === Example 1: Memory-to-Memory Copy ===
 * Before: source = 42, destination = 0
 * After:  source = 42, destination = 42
 * 
 * === Example 2: Add and Store ===
 * Before: data = 15
 * After:  output = 35
 * 
 * === Example 3: Memory Operations ===
 * Before: value1 = 99, value2 = 0
 * After:  value1 = 99, value2 = 99
 * 
 * === Example 4: Addition ===
 * Before: num1 = 10, num2 = 20
 * After:  sum = 30
 */
