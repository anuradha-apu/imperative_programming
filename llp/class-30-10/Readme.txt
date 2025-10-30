                               __________

                                 README (Generated)


Table of Contents
_________________

1. Addressing modes to try
2. gdb with nasm summary
.. 1. command-line
.. 2. Interacting with gdb
.. 3. Useful GDB Configuration
.. 4. Advanced setups





1 Addressing modes to try
=========================

  - Register Direct: `mov eax, ebx`
  - Immediate: `mov eax, 100`
  - Direct Memory: `mov eax, [variable]`
  - Register Indirect: `mov eax, [esi]`
  - Base + Displacement: `mov eax, [ebx + 8]`
  - Indexed: `mov eax, [array + esi*4]`
  - Base + Index: `mov eax, [ebx + esi*4]`


2 gdb with nasm summary
=======================

2.1 command-line
~~~~~~~~~~~~~~~~

  nasm -f elf64 -g -F dwarf program.asm ld -o program program.o


2.2 Interacting with gdb
~~~~~~~~~~~~~~~~~~~~~~~~

  (gdb) break _start # Set breakpoint at start (gdb) run # Start program
  (gdb) quit # Exit gdb

  (gdb) info registers # Show ALL registers (gdb) print $rax # Show RAX
  value (gdb) print $ebx # Show EBX value (gdb) print $rsp # Show stack
  pointer

  (gdb) stepi # Step one instruction (gdb) nexti # Step over function
  calls (gdb) continue # Continue execution

  (gdb) x/10x $rsp # Examine 10 words at stack pointer (gdb) x/s 0x4000
  # Examine as string at address


2.3 Useful GDB Configuration
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  Create .gdbinit file for better assembly debugging with following
  lines:

  set disassembly-flavor intel layout regs

  Or you could set this interactively in a session as: (gdb) set
  disassembly-flavor intel (gdb) layout regs # Show registers window
  (gdb) layout asm # Show assembly code window


2.4 Advanced setups
~~~~~~~~~~~~~~~~~~~

  (gdb) watch $rax (gdb) watch *0x600000

  (gdb) display $rax (gdb) display $rbx

  (gdb) disassemble _start

  (gdb) x/8xb &number # 8 bytes in hex (gdb) x/4xw &number # 4 words in
  hex (gdb) x/d &number # As decimal

  (gdb) tui enable (gdb) layout split # Code and registers

  x/10x $rsp - Examine 10 hexadecimal words at stack x/4xw &variable -
  Examine 4 words at variable address x/s 0x4000 - Examine memory as
  null-terminated string x/d &number - Examine memory as decimal value

  few more:

  x/4dw &data # 4 integers as decimal x/10db $rsp # 10 bytes as decimal
  from stack

  x/8db - 8 bytes as decimal x/4dh - 4 halfwords (2-byte) as decimal
  x/2dw - 2 words (4-byte) as decimal x/1dg - 1 giant word (8-byte) as
  decimal
