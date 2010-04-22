	.globl kinit
	.type kinit, @function
kinit:
	pushq	$0x2
	popfq

	movq	%rsp, %rbp
	movl	4(%rbp), %edi
	movl	8(%rbp), %esi

	movq	$bootstack, %rsp
	xorl	%ebp, %ebp

	call	kstartup

	.bss
	.p2align 2
	.space	0x1000
bootstack:
