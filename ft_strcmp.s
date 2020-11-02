
	global ft_strcmp

	ft_strcmp:
		xor rax, rax

	loop:
		mov bl , byte [rdi]
		mov bh , byte [rsi]
		cmp [rsi], byte 0
		je check
		cmp [rdi], byte 0
		je check
		cmp bh, bl
		jne check
		inc rsi
		inc rdi
		jmp loop

	check:
		cmp bh, bl
		jl incre
		cmp bh, bl
		jg decre
		cmp bh, bl
		je end

	incre:
		inc rax
		jmp end

	decre:
		dec rax

	end:
		ret
