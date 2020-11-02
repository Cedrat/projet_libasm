#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

	size_t ft_strlen(const char *);
	char *ft_strcpy(char *dest, const char *src);
	int ft_strcmp(const char *s1, const char *s2);
	ssize_t ft_write(int fd, const void *buf, size_t count);
	ssize_t ft_read(int fd, void *buf, size_t count);
	char* ft_strdup(const char *s);

int main()
{
	errno = 0;
	int fd = 0;
	fd = open("ft_read.s", O_RDONLY) ;
	// const char* str1 = "test";
	int size = 256;
	char str2[300];
	char* str3;
	char  str4[] = "deflagration";
	// printf("%ld\n", ft_strlen("drama  \nqueen"));
	// printf("%s", ft_strcpy(str2, "dp\n"));
	// printf("%d\n", ft_strcmp("sa", "sal"));
	// printf("%d", strcmp("sa", "sal"));
	// printf("\n%ld\n", ft_write(1, "hola", 4));
	// printf("\n%d\n", errno);
	// errno = 0;
	// printf("\n%ld\n" ,write(1, "hola", 4));
	// printf("\n%d\n", errno);
	// printf("\n%ld\n", ft_read(fd, str2, 256));
	// str2[size] ='\0';
	// printf("%s", str2);
	// printf("\n%d\n", errno);
	str3 = ft_strdup(str4);
	printf("%s\n", str4);
	printf("%s", str3);


}
