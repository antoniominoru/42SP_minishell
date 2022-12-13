# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 15:19:37 by aminoru-          #+#    #+#              #
#    Updated: 2022/12/14 00:12:50 by aminoru-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = run_test

LIBFTPATH = ../lib/libft/
LIBFT = ../lib/libft/libft.a
SRCS = test.c \
		../src/builtin_export.c \
		../src/builtin_unset.c \
		../src/builtin_exit.c 

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