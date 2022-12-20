# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 15:19:37 by aminoru-          #+#    #+#              #
#    Updated: 2022/12/20 23:47:00 by aminoru-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = run_test

LIBFTPATH = ../lib/libft/
LIBFT = ../lib/libft/libft.a
SRCS = test.c \
		test_builtin_export.c \
		test_builtin_unset.c  \
		../src/builtin_export.c \
		../src/builtin_env.c \
		../src/print_list.c \
		../src/builtin_unset.c \
		../src/builtin_exit.c \
		../src/builtin_pwd.c

OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Werror -Wextra

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			make -C $(LIBFTPATH)
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}
				
clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all