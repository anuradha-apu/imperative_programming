	.file	"connect.c"
	.text
	.globl	gggg
	.bss
	.align 4
	.type	gggg, @object
	.size	gggg, 4
gggg:
	.zero	4
	.globl	ffff
	.align 4
	.type	ffff, @object
	.size	ffff, 4
ffff:
	.zero	4
	.text
	.globl	foo
	.type	foo, @function
foo:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	movl	8(%ebp), %edx
	subl	12(%ebp), %edx
	movl	%edx, gggg@GOTOFF(%eax)
	movl	16(%ebp), %edx
	subl	20(%ebp), %edx
	movl	%edx, ffff@GOTOFF(%eax)
	nop
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	foo, .-foo
	.section	.text.__x86.get_pc_thunk.ax,"axG",@progbits,__x86.get_pc_thunk.ax,comdat
	.globl	__x86.get_pc_thunk.ax
	.hidden	__x86.get_pc_thunk.ax
	.type	__x86.get_pc_thunk.ax, @function
__x86.get_pc_thunk.ax:
.LFB1:
	.cfi_startproc
	movl	(%esp), %eax
	ret
	.cfi_endproc
.LFE1:
	.ident	"GCC: (Ubuntu 14.2.0-19ubuntu2) 14.2.0"
	.section	.note.GNU-stack,"",@progbits
