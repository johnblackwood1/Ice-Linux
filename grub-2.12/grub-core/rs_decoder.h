	.file	"reed_solomon.c"
	.text
	.type	pol_evaluate, @function
pol_evaluate:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	movl	%eax, %ebx
	movl	%ecx, %edi
	movl	%edx, %eax
	xorl	%edx, %edx
	xorl	%esi, %esi
.L2:
	testl	%eax, %eax
	js	.L11
	movzbl	(%ebx,%eax), %ecx
	testb	%cl, %cl
	je	.L3
	movzbl	1049088(%ecx), %ecx
	movb	1048576(%edx,%ecx), %cl
	xorl	%ecx, %esi
.L3:
	addl	%edi, %edx
	cmpl	$254, %edx
	jle	.L4
	subl	$255, %edx
.L4:
	decl	%eax
	jmp	.L2
.L11:
	movl	%esi, %eax
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.size	pol_evaluate, .-pol_evaluate
	.type	gf_mul, @function
gf_mul:
	testb	%dl, %dl
	je	.L14
	testb	%al, %al
	je	.L14
	movzbl	%al, %eax
	movzbl	1049088(%eax), %ecx
	movzbl	%dl, %edx
	movzbl	1049088(%edx), %eax
	movb	1048576(%ecx,%eax), %al
	ret
.L14:
	xorl	%eax, %eax
	ret
	.size	gf_mul, .-gf_mul
	.type	gauss_solve.constprop.0, @function
gauss_solve.constprop.0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$60, %esp
	movl	%eax, -40(%ebp)
	movl	%edx, -28(%ebp)
	movl	%ecx, -44(%ebp)
	xorl	%eax, %eax
.L16:
	movl	-40(%ebp), %edi
	cmpl	%edi, %eax
	jge	.L42
	movl	$-1, 1049344(,%eax,4)
	incl	%eax
	jmp	.L16
.L42:
	xorl	%eax, %eax
.L18:
	movl	-28(%ebp), %edx
	cmpl	%edx, %eax
	jge	.L43
	movl	-44(%ebp), %edi
	movb	$0, (%edi,%eax)
	incl	%eax
	jmp	.L18
.L43:
	movl	%edx, %eax
	incl	%eax
	movl	%eax, -36(%ebp)
	xorl	%ecx, %ecx
	xorl	%eax, %eax
	movl	%eax, -32(%ebp)
.L20:
	movl	-32(%ebp), %edi
	cmpl	%edi, -40(%ebp)
	jle	.L44
	xorl	%ebx, %ebx
.L31:
	cmpl	%ebx, -28(%ebp)
	jle	.L21
	cmpb	$0, 1052672(%ebx,%ecx)
	jne	.L23
	incl	%ebx
	jmp	.L31
.L21:
	jne	.L23
.L30:
	incl	-32(%ebp)
	movl	-36(%ebp), %eax
	addl	%eax, %ecx
	jmp	.L20
.L23:
	movl	-32(%ebp), %eax
	movl	%ebx, 1049344(,%eax,4)
	movzbl	1052672(%ebx,%ecx), %eax
	movzbl	1049088(%eax), %edx
	movl	$255, %eax
	subl	%edx, %eax
	xorl	%esi, %esi
	leal	1052672(%ecx), %edi
	movl	%edi, -48(%ebp)
	movzbl	1048576(%eax), %eax
	movl	%eax, -52(%ebp)
.L24:
	cmpl	%esi, -28(%ebp)
	jl	.L45
	movl	%ecx, -56(%ebp)
	movl	-48(%ebp), %eax
	leal	(%eax,%esi), %edi
	movzbl	(%edi), %eax
	movl	-52(%ebp), %edx
	call	gf_mul
	movb	%al, (%edi)
	incl	%esi
	movl	-56(%ebp), %ecx
	jmp	.L24
.L45:
	movl	-32(%ebp), %eax
	incl	%eax
	movl	%eax, -48(%ebp)
	movl	-36(%ebp), %eax
	leal	(%ecx,%eax), %edi
.L26:
	movl	-48(%ebp), %edx
	cmpl	%edx, -40(%ebp)
	je	.L30
	xorl	%esi, %esi
	movzbl	1052672(%ebx,%edi), %eax
	movl	%eax, -52(%ebp)
	leal	1052672(%edi), %eax
	movl	%eax, -56(%ebp)
.L27:
	cmpl	%esi, -28(%ebp)
	jl	.L46
	movzbl	1052672(%esi,%ecx), %eax
	movl	%ecx, -60(%ebp)
	movl	-52(%ebp), %edx
	call	gf_mul
	movl	-56(%ebp), %edx
	xorb	%al, (%edx,%esi)
	incl	%esi
	movl	-60(%ebp), %ecx
	jmp	.L27
.L46:
	incl	-48(%ebp)
	movl	-36(%ebp), %eax
	addl	%eax, %edi
	jmp	.L26
.L44:
	movl	-40(%ebp), %esi
	decl	%esi
	movl	-36(%ebp), %ebx
	imull	%esi, %ebx
	movl	-28(%ebp), %eax
	addl	%eax, %ebx
.L32:
	testl	%esi, %esi
	js	.L47
	movl	1049344(,%esi,4), %edi
	cmpl	$-1, %edi
	je	.L33
	movl	%ebx, %eax
	movl	-28(%ebp), %edx
	subl	%edx, %eax
	movl	%eax, -36(%ebp)
	movb	$0, -32(%ebp)
	xorl	%ecx, %ecx
.L34:
	cmpl	%ecx, -28(%ebp)
	jle	.L48
	movl	-44(%ebp), %eax
	movzbl	(%eax,%ecx), %edx
	movl	-36(%ebp), %eax
	movzbl	1052672(%eax,%ecx), %eax
	movl	%ecx, -40(%ebp)
	call	gf_mul
	xorb	%al, -32(%ebp)
	movl	-40(%ebp), %ecx
	incl	%ecx
	jmp	.L34
.L48:
	movb	-32(%ebp), %al
	xorb	1052672(%ebx), %al
	movl	-44(%ebp), %edx
	movb	%al, (%edx,%edi)
.L33:
	decl	%esi
	movl	-28(%ebp), %eax
	subl	%eax, %ebx
	decl	%ebx
	jmp	.L32
.L47:
	addl	$60, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.size	gauss_solve.constprop.0, .-gauss_solve.constprop.0
	.globl	grub_reed_solomon_recover
	.type	grub_reed_solomon_recover, @function
grub_reed_solomon_recover:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$76, %esp
	movl	%eax, -68(%ebp)
	movl	%edx, -36(%ebp)
	movl	%ecx, -32(%ebp)
	testl	%ecx, %ecx
	je	.L49
	addl	%edx, %eax
	movl	%eax, -40(%ebp)
	leal	-1(%eax,%ecx), %ecx
	movl	%ecx, %eax
.L51:
	movl	-40(%ebp), %edi
	cmpl	%edi, %eax
	jb	.L52
	cmpb	$0, (%eax)
	jne	.L52
	decl	%eax
	jmp	.L51
.L52:
	subl	%eax, %ecx
	movl	$2, %ebx
	movl	-32(%ebp), %eax
	cltd
	idivl	%ebx
	cmpl	%eax, %ecx
	jg	.L49
	movb	$0, 1049088
	movl	$1048576, %edx
	movb	$1, %al
.L57:
	movb	%al, (%edx)
	movb	%al, 255(%edx)
	movzbl	%al, %ecx
	movb	%dl, 1049088(%ecx)
	testb	%al, %al
	jns	.L55
	sall	%eax
	xorl	$29, %eax
	jmp	.L56
.L55:
	sall	%eax
.L56:
	incl	%edx
	cmpl	$1048831, %edx
	jne	.L57
.L58:
	cmpl	$0, -36(%ebp)
	je	.L49
	movl	-36(%ebp), %eax
	movl	-32(%ebp), %edi
	leal	(%eax,%edi), %ecx
	cmpl	$102400, %ecx
	jbe	.L86
	imull	$200, %eax, %eax
	xorl	%edx, %edx
	divl	%ecx
	sall	$9, %eax
	movl	%eax, -44(%ebp)
	imull	$200, %edi, %eax
	xorl	%edx, %edx
	divl	%ecx
	sall	$9, %eax
	movl	%eax, -48(%ebp)
	jmp	.L59
.L86:
	movl	-32(%ebp), %eax
	movl	%eax, -48(%ebp)
	movl	-36(%ebp), %eax
	movl	%eax, -44(%ebp)
.L59:
	movl	$511, -64(%ebp)
	xorl	%edx, %edx
	movl	%edx, -56(%ebp)
.L62:
	movl	-44(%ebp), %eax
	movl	-64(%ebp), %ebx
	addl	%ebx, %eax
	movl	-48(%ebp), %esi
	addl	%ebx, %esi
	cmpl	$511, %esi
	jbe	.L84
	cmpl	$511, %eax
	ja	.L60
.L84:
	incl	-56(%ebp)
	decl	-64(%ebp)
	cmpl	$512, -56(%ebp)
	jne	.L62
	movl	-44(%ebp), %esi
	addl	%esi, -68(%ebp)
	movl	-48(%ebp), %ebx
	addl	%ebx, -40(%ebp)
	subl	%esi, -36(%ebp)
	subl	%ebx, -32(%ebp)
	jmp	.L58
.L60:
	shrl	$9, %eax
	movl	%eax, -52(%ebp)
	movl	-68(%ebp), %eax
	movl	-56(%ebp), %ebx
	addl	%ebx, %eax
	movl	%eax, -60(%ebp)
	movl	%eax, %edx
	xorl	%eax, %eax
.L64:
	movb	(%edx), %cl
	movb	%cl, 1052160(%eax)
	incl	%eax
	addl	$512, %edx
	movl	-52(%ebp), %edi
	cmpl	%edi, %eax
	jl	.L64
	movl	%esi, %eax
	shrl	$9, %eax
	movl	%eax, -28(%ebp)
	movl	-40(%ebp), %eax
	movl	-56(%ebp), %ebx
	leal	(%eax,%ebx), %edx
	xorl	%eax, %eax
.L65:
	movb	(%edx), %cl
	movl	-52(%ebp), %edi
	movb	%cl, 1052160(%edi,%eax)
	incl	%eax
	addl	$512, %edx
	movl	-28(%ebp), %ebx
	cmpl	%ebx, %eax
	jl	.L65
	shrl	$10, %esi
	xorl	%ebx, %ebx
	movl	%edi, %eax
	movl	-28(%ebp), %edi
	addl	%edi, %eax
	movl	%eax, -72(%ebp)
	decl	%eax
	movl	%eax, -76(%ebp)
.L66:
	movl	%ebx, %ecx
	movl	-76(%ebp), %edx
	movl	$1052160, %eax
	call	pol_evaluate
	movb	%al, 1051904(%ebx)
	incl	%ebx
	movl	-28(%ebp), %eax
	cmpl	%eax, %ebx
	jl	.L66
	xorl	%eax, %eax
.L68:
	cmpb	$0, 1051904(%eax)
	jne	.L67
	incl	%eax
	movl	-28(%ebp), %ebx
	cmpl	%ebx, %eax
	jl	.L68
.L67:
	cmpl	%eax, -28(%ebp)
	je	.L69
	leal	1(%esi), %edi
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	jmp	.L70
.L69:
	xorl	%eax, %eax
	jmp	.L71
.L72:
	movb	1051904(%edx,%eax), %bl
	movb	%bl, 1052672(%eax,%ecx)
	incl	%eax
	cmpl	%esi, %eax
	jle	.L72
	incl	%edx
	addl	%edi, %ecx
.L70:
	xorl	%eax, %eax
	cmpl	%esi, %edx
	jl	.L72
.L73:
	cmpl	%eax, %esi
	jle	.L100
	movb	$0, 1050368(%eax)
	incl	%eax
	jmp	.L73
.L100:
	movl	$1050368, %ecx
	movl	%esi, %edx
	movl	%esi, %eax
	call	gauss_solve.constprop.0
	xorl	%ebx, %ebx
	xorl	%edi, %edi
	decl	%esi
.L76:
	movl	$255, %ecx
	subl	%edi, %ecx
	movl	%esi, %edx
	movl	$1050368, %eax
	call	pol_evaluate
	cmpb	1048576(%edi), %al
	jne	.L75
	movl	%ebx, %edx
	movb	%al, 1050624(%ebx)
	incl	%ebx
	movl	-76(%ebp), %eax
	subl	%edi, %eax
	movl	%eax, 1050880(,%edx,4)
.L75:
	incl	%edi
	movl	-72(%ebp), %eax
	cmpl	%eax, %edi
	jl	.L76
	xorl	%eax, %eax
.L77:
	cmpl	%ebx, %eax
	jge	.L101
	movb	$1, 1052672(%eax)
	incl	%eax
	jmp	.L77
.L101:
	movb	1051904, %al
	movb	%al, 1052672(%ebx)
	leal	1(%ebx), %ecx
	leal	(%ebx,%ebx), %eax
	movl	%eax, -76(%ebp)
	movl	%ecx, -80(%ebp)
	xorl	%eax, %eax
	movl	%eax, -72(%ebp)
	movl	$1, %edi
.L79:
	movl	-28(%ebp), %eax
	cmpl	%eax, %edi
	jge	.L102
	xorl	%esi, %esi
.L81:
	cmpl	%ebx, %esi
	jge	.L103
	movl	%ecx, -84(%ebp)
	movl	-72(%ebp), %eax
	movzbl	1052672(%eax,%esi), %edx
	movzbl	1050624(%esi), %eax
	call	gf_mul
	movl	-80(%ebp), %edx
	movb	%al, 1052672(%edx,%esi)
	incl	%esi
	movl	-84(%ebp), %ecx
	jmp	.L81
.L103:
	movb	1051904(%edi), %al
	movl	-76(%ebp), %esi
	movb	%al, 1052673(%esi)
	incl	%edi
	addl	%ecx, -76(%ebp)
	addl	%ecx, -72(%ebp)
	addl	%ecx, -80(%ebp)
	jmp	.L79
.L102:
	movl	$1052416, %ecx
	movl	%ebx, %edx
	call	gauss_solve.constprop.0
	xorl	%eax, %eax
.L82:
	cmpl	%ebx, %eax
	jge	.L69
	movl	1050880(,%eax,4), %edx
	movb	1052416(%eax), %cl
	xorb	%cl, 1052160(%edx)
	incl	%eax
	jmp	.L82
.L71:
	movb	1052160(%eax), %dl
	movl	-60(%ebp), %esi
	movb	%dl, (%esi)
	incl	%eax
	addl	$512, -60(%ebp)
	movl	-52(%ebp), %esi
	cmpl	%esi, %eax
	jl	.L71
	jmp	.L84
.L49:
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.size	grub_reed_solomon_recover, .-grub_reed_solomon_recover
	.section	.note.GNU-stack,"",@progbits
