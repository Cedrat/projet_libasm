	global ft_read
	extern  __errno_location

	ft_read :
		mov 	rax, 0				; 0 is syscall read
		syscall
		CMP 	rax, 0
		jl 		err_value            ; if negative, is a error_code
		ret

	err_value:
		neg 	rax
		mov 	rdi, rax
		call 	__errno_location
		mov [rax],rdi
		mov rax, -1
		ret
