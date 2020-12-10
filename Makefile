# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/05 18:19:38 by lnoaille          #+#    #+#              #
#    Updated: 2020/12/10 20:09:00 by lnoaille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCS = ft_read.s ft_strcmp.s ft_strcpy.s ft_write.s ft_strdup.s ft_strlen.s

CFLAGS = -f elf64

OBJS = ${SRCS:.s=.o}

RM = rm -f

LIB = ar rc


%.o : %.s
	nasm -f elf64 -o $@ $<

all : 		${NAME}

${NAME}:	${OBJS}
			${LIB} ${NAME} ${OBJS}
			ranlib ${NAME}

main:		${NAME}
			gcc main.c -L -lasm ${NAME} && ./a.out

clean :
			${RM} ${OBJS} ${BONUS}

fclean :	clean
			${RM} ${NAME}

re :		fclean all
