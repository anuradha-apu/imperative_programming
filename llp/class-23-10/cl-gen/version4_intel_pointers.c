/* Version 4: Intel Syntax with Pointers (SOLUTION)
 * This example demonstrates:
 * - How to use Intel syntax for memory operations
 * - Using pointers with "r" constraint instead of "m"
 * - Multiple memory access patterns
 * 
 * Compilation: gcc -o version4 version4_intel_pointers.c
 * Status: WORKS ✓
 * 
 * This is the CORRECT way to use Intel syntax with memory!
 */

#include <stdio.h>

int main() {
    // Example 1: Memory Access via Pointers
    int source = 42;
    int destination = 0;
    int *p_src = &source;      // Key: Use pointers!
    int *p_dst = &destination;
    
    printf("=== Example 1: Memory Access via Pointers ===\n");
    printf("Before: source = %d, destination = %d\n", source, destination);
    
    __asm__ __volatile__ (
        ".intel_syntax noprefix\n\t"
        "mov eax, [%0]\n\t"      // Read from address in register
        "mov [%1], eax\n\t"      // Write to address in register
        ".att_syntax prefix\n\t"
        :                        // No output operands
        : "r" (p_src), "r" (p_dst)  // Pointers as register operands
        : "eax", "memory"
    );
    
    printf("After:  source = %d, destination = %d\n\n", source, destination);
    
    
    // Example 2: Increment via pointer
    int counter = 10;
    int *p_counter = &counter;
    
    printf("=== Example 2: Direct Memory Increment ===\n");
    printf("Before: counter = %d\n", counter);
    
    __asm__ __volatile__ (
        ".intel_syntax noprefix\n\t"
        "mov rax, %0\n\t"        // Get pointer into register
        "add DWORD PTR [rax], 5\n\t"  // Add 5 to memory location
        ".att_syntax prefix\n\t"
        :
        : "r" (p_counter)
        : "rax", "memory"
    );
    
    printf("After:  counter = %d\n\n", counter);
    
    
    // Example 3: Array element swap
    int array[3] = {100, 200, 300};
    int *p_array = array;
    
    printf("=== Example 3: Array Element Swap ===\n");
    printf("Before: array[0] = %d, array[1] = %d\n", array[0], array[1]);
    
    __asm__ __volatile__ (
        ".intel_syntax noprefix\n\t"
        "mov rdi, %0\n\t"        // Load array address into rdi
        "mov eax, [rdi]\n\t"     // Load array[0]
        "mov ebx, [rdi+4]\n\t"   // Load array[1] (4 bytes offset)
        "mov [rdi], ebx\n\t"     // Store to array[0]
        "mov [rdi+4], eax\n\t"   // Store to array[1]
        ".att_syntax prefix\n\t"
        :
        : "r" (p_array)
        : "rax", "rbx", "rdi", "memory"
    );
    
    printf("After:  array[0] = %d, array[1] = %d\n", array[0], array[1]);
    
    return 0;
}

/*
 * WHY THIS WORKS:
 * 
 * Instead of using "m" constraint:
 *     : "m" (variable)  ← Generates AT&T memory reference
 * 
 * We use "r" with pointers:
 *     int *ptr = &variable;
 *     : "r" (ptr)       ← Pointer VALUE in register
 * 
 * BEHIND THE SCENES:
 * 
 * You write:
 *     int *p = &source;
 *     "mov eax, [%0]" with : "r" (p)
 * 
 * Compiler assigns register (e.g., rsi) to hold pointer:
 *     %0 expands to: rsi
 * 
 * Result:
 *     mov eax, [rsi]    ← Valid Intel syntax!
 * 
 * THE KEY DIFFERENCE:
 * 
 * "m" constraint:
 *     %0 → -8(%rbp)     ← AT&T memory reference (breaks Intel)
 * 
 * "r" constraint with pointer:
 *     %0 → rsi          ← Register name (works with Intel!)
 * 
 * MEMORY CLOBBER:
 * Always include "memory" when modifying memory contents
 * This tells compiler memory has changed
 * 
 * Expected Output:
 * === Example 1: Memory Access via Pointers ===
 * Before: source = 42, destination = 0
 * After:  source = 42, destination = 42
 * 
 * === Example 2: Direct Memory Increment ===
 * Before: counter = 10
 * After:  counter = 15
 * 
 * === Example 3: Array Element Swap ===
 * Before: array[0] = 100, array[1] = 200
 * After:  array[0] = 200, array[1] = 100
 */
