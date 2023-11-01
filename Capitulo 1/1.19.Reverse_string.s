	.file	"1.19.Reverse_string.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "ARR:%s - l_new_line: %d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	andl	$-16, %esp
	subl	$1024, %esp
	.cfi_offset 7, -12
	call	___main
	movl	$0, 1020(%esp)
	leal	20(%esp), %edx
	movl	$0, %eax
	movl	$250, %ecx
	movl	%edx, %edi
	rep stosl
	jmp	L2
L3:
	movl	1020(%esp), %eax
	movl	%eax, 8(%esp)
	leal	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	1020(%esp), %eax
	movl	%eax, 4(%esp)
	leal	20(%esp), %eax
	movl	%eax, (%esp)
	call	_reverse_string
L2:
	movl	$1000, 4(%esp)
	leal	20(%esp), %eax
	movl	%eax, (%esp)
	call	_get_char
	movl	%eax, 1020(%esp)
	cmpl	$0, 1020(%esp)
	jg	L3
	movl	$0, %eax
	movl	-4(%ebp), %edi
	leave
	.cfi_restore 5
	.cfi_restore 7
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.globl	_get_char
	.def	_get_char;	.scl	2;	.type	32;	.endef
_get_char:
LFB11:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -24(%ebp)
	movl	$0, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	$0, -28(%ebp)
	jmp	L6
L11:
	cmpl	$32, -12(%ebp)
	jne	L7
	cmpl	$0, -16(%ebp)
	jne	L7
	movl	$1, -16(%ebp)
	movl	-24(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -24(%ebp)
	movl	%eax, %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movb	$95, (%eax)
L7:
	cmpl	$9, -12(%ebp)
	jne	L8
	cmpl	$0, -20(%ebp)
	jne	L8
	movl	$1, -20(%ebp)
	movl	-24(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -24(%ebp)
	movl	%eax, %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movb	$42, (%eax)
L8:
	cmpl	$32, -12(%ebp)
	je	L9
	cmpl	$9, -12(%ebp)
	je	L9
	movl	-24(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -24(%ebp)
	movl	%eax, %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	-12(%ebp), %edx
	movb	%dl, (%eax)
	movl	$0, -16(%ebp)
	movl	$0, -20(%ebp)
L9:
	addl	$1, -28(%ebp)
L6:
	movl	12(%ebp), %eax
	subl	$1, %eax
	cmpl	-28(%ebp), %eax
	jl	L10
	call	_getchar
	movl	%eax, -12(%ebp)
	cmpl	$10, -12(%ebp)
	je	L10
	cmpl	$-1, -12(%ebp)
	jne	L11
L10:
	cmpl	$10, -12(%ebp)
	jne	L12
	movl	-24(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -24(%ebp)
	movl	%eax, %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movb	$10, (%eax)
	movl	-24(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movb	$0, (%eax)
L12:
	movl	-24(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE11:
	.globl	_reverse_string
	.def	_reverse_string;	.scl	2;	.type	32;	.endef
_reverse_string:
LFB12:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -24(%ebp)
	movl	-24(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, -12(%ebp)
	jmp	L15
L17:
	addl	$1, -16(%ebp)
L16:
	movl	-16(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, -20(%ebp)
	cmpl	$95, -20(%ebp)
	je	L17
	cmpl	$42, -20(%ebp)
	je	L17
	jmp	L18
L20:
	movl	-16(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -16(%ebp)
	movl	%eax, %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, -20(%ebp)
L18:
	cmpl	$95, -20(%ebp)
	je	L19
	cmpl	$42, -20(%ebp)
	je	L19
	cmpl	$10, -20(%ebp)
	jne	L20
L19:
	cmpl	$0, -16(%ebp)
	jle	L21
	cmpl	$45, -20(%ebp)
	je	L22
	cmpl	$42, -20(%ebp)
	je	L22
	cmpl	$95, -20(%ebp)
	jne	L21
L22:
	subl	$2, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, -12(%ebp)
	jmp	L23
L27:
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$45, %al
	jne	L24
	movl	$45, (%esp)
	call	_putchar
L24:
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$95, %al
	jne	L25
	movl	$95, (%esp)
	call	_putchar
L25:
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$42, %al
	jne	L26
	movl	$42, (%esp)
	call	_putchar
L26:
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, (%esp)
	call	_putchar
	subl	$1, -12(%ebp)
L23:
	movl	-12(%ebp), %eax
	cmpl	-24(%ebp), %eax
	jge	L27
L21:
	movl	-16(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -24(%ebp)
	cmpl	$95, -20(%ebp)
	je	L28
	cmpl	$42, -20(%ebp)
	jne	L29
L28:
	addl	$1, -16(%ebp)
L29:
	movl	-16(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, -20(%ebp)
	movl	-24(%ebp), %eax
	subl	%eax, 12(%ebp)
L15:
	cmpl	$1, 12(%ebp)
	jg	L16
	movl	$10, (%esp)
	call	_putchar
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE12:
	.globl	_array_cleaner
	.def	_array_cleaner;	.scl	2;	.type	32;	.endef
_array_cleaner:
LFB13:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movb	$0, (%eax)
	nop
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE13:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_getchar;	.scl	2;	.type	32;	.endef
	.def	_putchar;	.scl	2;	.type	32;	.endef
