	.file	"zad06.c"
	.section	.rodata
.LC0:
	.string	"output"
.LC1:
	.string	"Koniec"
	.text
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$420, %edx
	movl	$578, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	open@PLT
	movl	%eax, -12(%rbp)
	movl	$0, -24(%rbp)
	jmp	.L2
.L8:
	movl	$0, -20(%rbp)
	jmp	.L3
.L5:
	call	fork@PLT
	testl	%eax, %eax
	jne	.L4
	movl	-20(%rbp), %eax
	addl	$48, %eax
	movb	%al, -25(%rbp)
	leaq	-25(%rbp), %rcx
	movl	-12(%rbp), %eax
	movl	$1, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	write@PLT
	movl	$0, %edi
	call	exit@PLT
.L4:
	addl	$1, -20(%rbp)
.L3:
	cmpl	$9, -20(%rbp)
	jle	.L5
	movl	$0, -16(%rbp)
	jmp	.L6
.L7:
	movl	$0, %edi
	call	wait@PLT
	addl	$1, -16(%rbp)
.L6:
	cmpl	$9, -16(%rbp)
	jle	.L7
	movb	$10, -25(%rbp)
	leaq	-25(%rbp), %rcx
	movl	-12(%rbp), %eax
	movl	$1, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	write@PLT
	addl	$1, -24(%rbp)
.L2:
	cmpl	$999999, -24(%rbp)
	jle	.L8
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L10
	call	__stack_chk_fail@PLT
.L10:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.ident	"GCC: (GNU) 7.2.0"
	.section	.note.GNU-stack,"",@progbits
