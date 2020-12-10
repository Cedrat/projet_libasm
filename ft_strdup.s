global ft_strdup
extern ft_strlen
extern ft_strcpy;   rdi  ft_strcpy(rdi, rsi) rdi = malloc pointer rsi = original string
extern 	malloc
extern  __errno_location

	ft_strdup:
		push rbp			;we need to save YOU
		mov rbp, rdi		;save char* to copy
		call ft_strlen		;rdi take len
		inc rax;
		mov rdi, rax
		inc rdi
		call malloc	wrt ..plt		;malloc use len and return rdi
		CMP 	rax, 0
		jl 		err_value            ; if negative, is a error_code
		mov [rax],rdi
		mov rdi, rax
		mov rsi, rbp
		pop rbp
		call ft_strcpy
		mov rax, rdi
		ret

	err_value:
		xor rax, rax
		ret
