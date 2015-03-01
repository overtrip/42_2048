segment	.text
	global	_ft_memalloc
	extern	_ft_memset
	extern	_malloc

_ft_memalloc:

	cmp		rdi,0
	je		fail
	mov		r13,rdi
	call	_malloc
	test	rax,rax
	jz		fail
	mov		rdi,rax
	mov		rsi,0
	mov		rdx,r13
	call	_ft_memset
	ret

fail:
	mov		rax,0
	ret
