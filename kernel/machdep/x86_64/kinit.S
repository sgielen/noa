	.globl kinit
	.type kinit, @function
kinit:
	pushq	$0x2
	popfq

	movq	$bootstack, %rsp
	xorl	%ebp, %ebp

	call	kstartup

	.bss
	.p2align 2
	.space	0x1000
bootstack:
