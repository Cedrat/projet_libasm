	global ft_write
	extern  __errno_location

	ft_write :
		mov 	rax, 1
		syscall
		CMP 	rax, 0
		jl 		return_value
		ret

	return_value:
		neg 	rax
		mov 	rdi, rax
		call 	__errno_location
		;mov [rax],rdi
		;mov rax, -1
		ret