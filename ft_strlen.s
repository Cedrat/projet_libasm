
	global ft_strlen

ft_strlen:
	mov rax, 0 ; rax is the returned value (integer) -> set rax to 0

loop:
	CMP [rdi], byte 0 ; compare the byte with 0, if byte == 0, jump to the end
	JE end

	INC rdi
	INC rax
	JMP loop ; again and again
end:
	ret ; return rax
