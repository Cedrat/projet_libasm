global ft_strdup
extern ft_strlen
extern ft_strcpy;   rdi  ft_strcpy(rdi, rsi) rdi = malloc pointer rsi = original string
extern 	malloc
extern  __errno_location

	ft_strdup:
		push rbp			;we need to save YOU
		mov rbp, rdi		;save char* to copy
		call ft_strlen		;rdi take len
		mov rdi, rax
		inc rdi
		call malloc			;malloc use len and return rdi
		mov rdi, rax
		mov rsi, rbp
		call ft_strcpy
		pop rbp
		ret
