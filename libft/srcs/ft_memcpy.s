segment	.text
	global	_ft_memcpy

_ft_memcpy:

	mov		r13,rdi
	mov		rcx,rdx
	mov		rax,rsi
	rep		movsb

done:

	mov		rax,r13
	ret
