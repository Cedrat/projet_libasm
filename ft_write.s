	global ft_write
	extern  __errno_location ;return a int* who is a pointer to the adress of __errno_location
							 ;need to puts the err_value at the adress of pointer

	ft_write :
		mov 	rax, 1				; 1 is syscall write
		syscall
		CMP 	rax, 0
		jl 		err_value            ; if negative, is a error_code
		ret

	err_value:
		neg 	rax
		mov 	rdi, rax
		call 	__errno_location wrt ..plt
		mov [rax],rdi
		mov rax, -1
		ret
