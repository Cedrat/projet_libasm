
	global ft_strcmp

	ft_strcmp:
		xor rax, rax

	loop:
		mov bl , [rdi]
		mov r9b , [rsi]
		cmp bl, byte 0
		je check
		cmp r9b, bl
		jne check
		inc rsi
		inc rdi
		jmp loop

	check:
		movzx rdx, bl
		movzx rbx, r9b
		cmp rbx, rdx
		jl incre
		cmp rbx, rdx
		jg decre
		cmp rbx, rdx
		je end

	incre:
		inc rax
		jmp end

	decre:
		dec rax

	end:
		ret
