global ft_strcpy

									; rsi = src rdi = dest
	ft_strcpy:
		XOR rax, rax ; similar to mov rax, 0 but really more fast. (basic operation of processor)
	loop:

		mov 	bl, byte [rsi + rax]
		mov		byte [rdi + rax] , bl
		cmp 	bl, byte 0
		je		end
		inc 	rax
		jmp 	loop

	end:
		mov rax, rdi
		ret
