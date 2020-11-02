#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
	size_t ft_strlen(const char *);
	char *ft_strcpy(char *dest, const char *src);
	int ft_strcmp(const char *s1, const char *s2);
	ssize_t ft_write(int fd, const void *buf, size_t count);

int main()
{
	errno = 0;
	// const char* str1 = "test";
	// char str2[5];
	// printf("%ld\n", ft_strlen("drama  \nqueen"));
	// printf("%s", ft_strcpy(str2, "dp\n"));
	// printf("%d\n", ft_strcmp("sa", "sal"));
	// printf("%d", strcmp("sa", "sal"));
	printf("\n%ld\n", ft_write(-1, "deux", 4));
	// printf("\n%ld\n" ,write(-1, "xd", 1));
	printf("\n%d\n", errno);
}
