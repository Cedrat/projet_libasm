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
	char bigstr[] = "ceci est une chaine, longue surement pas assez, viens et augmente la si tu veux mais je voulais pas pourrir mon main :(du coup, je vais copier coller plusieurs fois)ceci est une chaine, longue surement pas assez, viens et augmente la si tu veux mais je voulais pas pourrir mon main :(du coup, je vais copier coller plusieurs fois)ceci est une chaine, longue surement pas assez, viens et augmente la si tu veux mais je voulais pas pourrir mon main :(du coup, je vais copier coller plusieurs fois)ceci est une chaine, longue surement pas assez, viens et augmente la si tu veux mais je voulais pas pourrir mon main :(du coup, je vais copier coller plusieurs fois)ceci est une chaine, longue surement pas assez, viens et augmente la si tu veux mais je voulais pas pourrir mon main :(du coup, je vais copier coller plusieurs fois)ceci est une chaine, longue surement pas assez, viens et augmente la si tu veux mais je voulais pas pourrir mon main :(du coup, je vais copier coller plusieurs fois)ineed9cac";
	puts("_____________ft_strlen.s_____________\n\n");
	puts("_____________with_length = 0_____________");
	printf("libc = %ld\n", strlen(""));
	printf("libasm.a = %ld\n", ft_strlen(""));
	puts("\n_____________with_length = 1_____________");
	printf("libc = %ld\n", strlen("1"));
	printf("libasm.a = %ld\n", ft_strlen("1"));
	puts("\n_____________with_length = a lot_____________");
	printf("libc = %ld\n", strlen(bigstr));
	printf("libasm.a = %ld\n", ft_strlen(bigstr));


	puts("\n\n_____________ft_strcpy.s_____________\n\n");
	puts("_____________with_empty_string_____________");
	char dest_str[] = "";
	char dest_str1[] = "";
	printf("libc = %s\n", strcpy(dest_str, ""));
	printf("libasm.a = %s\n", ft_strcpy(dest_str, ""));
	puts("\n_____________with_a_long_string_____________");
	char dest_str2[10000];
	char dest_str3[10000];
	printf("libc = %s\n", strcpy(dest_str, bigstr));
	printf("\nlibasm.a = %s\n", ft_strcpy(dest_str, bigstr));

	puts("\n\n_____________ft_strcmp.s_____________\n\n");
	puts("_____________with_two_empty_string_____________");
	printf("libc = %d\n", strcmp("", ""));
	printf("libasm.a = %d\n", ft_strcmp	("", ""));
	puts("\n_____________with_one_empty_string_____________");
	printf("libc = %d\n", strcmp("yo", ""));
	printf("libasm.a = %d\n", ft_strcmp	("yo", ""));
	puts("\n_____________with_one_empty_string_but_not_the_same_____________");
	printf("libc = %d\n", strcmp("", "yo"));
	printf("libasm.a = %d\n", ft_strcmp	("", "yo"));
	puts("\n_____________many_test_____________");
	printf("libc = %d\n", strcmp("deflag", "yo"));
	printf("libasm.a = %d\n", ft_strcmp	("deflag", "yo"));
	printf("libc = %d\n", strcmp("yo", "deflag"));
	printf("libasm.a = %d\n", ft_strcmp	("yo", "deflag"));

	errno = 0;
	puts("\n\n_____________ft_write.s_____________\n\n");
	puts("_____________in_stdin_____________");
	printf(" = libc = %ld\n", write(1, "yo", 2));
	printf(" = libasm.a = %ld\n", ft_write(1, "yo", 2));
	printf(" = libc = %ld\n", write(1, "yo", 1));
	printf(" = libasm.a = %ld\n", ft_write(1, "yo", 1));
	printf(" = libc = %ld\n", write(1, "yo", 0));
	printf(" = libasm.a = %ld\n", ft_write(1, "yo", 0));
	puts("\n_____________in_test_____________");
	int fd = open("test", O_WRONLY|O_CREAT, 0644);
	int fd1 = open("test1", O_WRONLY|O_CREAT, 0644);
	printf("libc = %ld\n", write(fd, "yo", 2));
	printf("errno = %d\n", errno);
	printf("libasm.a = %ld\n", ft_write(fd1, "yo", 2));
	printf("errno = %d\n", errno);
	puts("\n_____________bad_fd_____________");
	printf("libc = %ld\n", write(-1, "yo", 2));
	printf("errno = %d\n", errno);
	printf("libasm.a = %ld\n", ft_write(-1, "yo", 2));
	printf("errno = %d\n", errno);
	close(fd);
	close(fd1);
	puts("\n_____________no_authorization_____________");
	fd = open("no_authorization", O_WRONLY|O_CREAT, 0644);
	printf("libc = %ld\n", write(-1, "yo", 2));
	printf("errno = %d\n", errno);
	printf("libasm.a = %ld\n", ft_write(-1, "yo", 2));
	printf("errno = %d\n", errno);
	close(fd);

	puts("\n ^  ^  ^   ^      ___I_      ^  ^   ^  ^  ^   ^  ^\\\n/|\\/|\\/|\\ /|\\    /\\-_--\\    /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\\\\n/|\\/|\\/|\\ /|\\   /  \\_-__\\   /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\\n/|\\/|\\/|\\ /|\\   |[]| [] |   /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\");
	puts("\n_____________ft_read.s_____________\n\n");
	puts("_____________in_stdin_____________");
	char buff[50];
	char buff1[50];
	int ret;
	printf(" = libasm.a = %d\n", ret = ft_read(1, buff1, 50));
	buff1[ret] = '\0';
	puts(buff1);
	printf(" = libc = %d\n", ret = read(1, buff, 50));
	buff[ret] = '\0';
	puts(buff);
	puts("\n_____________in_test_____________");
	char buff2[50];
	char buff3[50];
	errno = 0;
	fd = open("test", O_RDONLY, 0644);
	fd1 = open("test1", O_RDONLY, 0644);
	printf(" = libasm.a = %d\n", ret = ft_read(fd, buff2, 50));
	printf("errno = %d\n", errno);
	buff2[ret] = '\0';
	puts(buff2);
	printf(" = libc = %d\n", ret = read(fd1, buff3, 50));
	printf("errno = %d\n", errno);
	buff3[ret] = '\0';
	puts(buff3);
	close(fd);
	close(fd1);
	puts("\n_____________bad_fd_____________");
	printf("libc = %ld\n", read(-1, buff, 2));
	printf("errno = %d\n", errno);
	printf("libasm.a = %ld\n", ft_read(-1, buff, 2));
	printf("errno = %d\n", errno);
	puts("\n_____________no_authorization_____________");
	fd = open("no_authorization", O_RDONLY, 0644);
	printf("libc = %ld\n", read(fd, buff, 2));
	printf("errno = %d\n", errno);
	printf("libasm.a = %ld\n", ft_read(fd, buff, 2));
	printf("errno = %d\n", errno);
	close(fd);

	puts("\n\n_____________ft_strdup.s_____________\n\n");
	puts("_____________with_empty_string_____________");
	char *dest_dup;
	char *dest_dup1;
	printf("libc = %s\n", strdup(""));
	printf("libasm.a = %s\n", ft_strdup(""));
	puts("\n_____________with_a_long_string_____________");
	char *dest_dup2;
	char *dest_dup3;
	printf("libc = %s\n", strdup(bigstr));
	printf("\nlibasm.a = %s\n", ft_strdup(bigstr));
}
