segment .text
	global _ft_strdup
	extern _ft_strlen
	extern _malloc

_ft_strdup:

	mov		r13,rdi
	call	_ft_strlen
	inc		rax
	mov		r12,rax
	mov		rdi, rax
	call	_malloc
	test	rax,rax
	jz		fail
	mov		r14,rax
	mov		rcx,r12
	mov		rdi,r14
	mov		rsi,r13
	rep		movsb

done:

	mov		rax,r14
	ret

fail:

	mov		rax,0
	jmp		done
