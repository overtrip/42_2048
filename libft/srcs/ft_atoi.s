segment	.text

	global	_ft_atoi

_ft_atoi:

	mov		r12,0
	mov		r13,1

f_loop:

	cmp		byte [rdi],' '
	jne		space
	inc		rdi
	jmp		f_loop

space:

	cmp		byte [rdi],9
	jl		sign
	cmp		byte [rdi],13
	jg		sign
	inc		rdi
	jmp		f_loop

sign:

	cmp		byte [rdi],'-'
	jne		signg
	mov		r13,-1
	inc		rdi

signg:

	cmp		byte [rdi],'+'
	jne		done
	inc		rdi

loop:

	cmp		byte [rdi],0h
	je		done
	cmp		byte [rdi],'0'
	jl		done
	cmp		byte [rdi],'9'
	jg		done
	mov		rax,r12
	mov		rcx,10
	mul		rcx
	mov		r12, rax
	xor		rax, rax
	mov		al, [rdi]
	add		r12, rax
	sub		r12,'0'
	inc		rdi
	jmp		loop

done:

	mov		rax,r12
	mov		rcx,r13
	mul		rcx
	ret
