	.file	"zad06.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"output"
.LC1:
	.string	"Koniec"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	leaq	.LC0(%rip), %rdi
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movl	$420, %edx
	movl	$578, %esi
	movl	$1000000, %r13d
	subq	$24, %rsp
	.cfi_def_cfa_offset 64
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	leaq	7(%rsp), %r12
	call	open@PLT
	movl	%eax, %ebp
.L2:
	xorl	%ebx, %ebx
	.p2align 4,,10
	.p2align 3
.L4:
	call	fork@PLT
	testl	%eax, %eax
	je	.L12
	addl	$1, %ebx
	cmpl	$10, %ebx
	jne	.L4
	.p2align 4,,10
	.p2align 3
.L5:
	xorl	%edi, %edi
	call	wait@PLT
	subl	$1, %ebx
	jne	.L5
	movl	$1, %edx
	movq	%r12, %rsi
	movl	%ebp, %edi
	movb	$10, 7(%rsp)
	call	write@PLT
	subl	$1, %r13d
	jne	.L2
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	xorl	%eax, %eax
	movq	8(%rsp), %rcx
	xorq	%fs:40, %rcx
	jne	.L13
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L12:
	.cfi_restore_state
	movl	%ebp, %edi
	addl	$48, %ebx
	movl	$1, %edx
	movq	%r12, %rsi
	movb	%bl, 7(%rsp)
	call	write@PLT
	xorl	%edi, %edi
	call	exit@PLT
.L13:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.ident	"GCC: (GNU) 7.2.0"
	.section	.note.GNU-stack,"",@progbits
