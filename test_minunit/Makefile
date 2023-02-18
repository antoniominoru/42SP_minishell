# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 15:19:37 by aminoru-          #+#    #+#              #
#    Updated: 2023/02/18 02:36:32 by aminoru-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = run_test

LIBFTPATH = ../lib/libft/
LIBFT = ../lib/libft/libft.a
INCS = -I ../include/
SRCS = test.c \
		test_builtin_export.c \
		test_builtin_unset.c  \
		test_builtin_env.c \
		test_builtin_pwd.c \
		test_builtin_echo.c \
		test_builtin_cd.c \
		test_take_value_of_env.c \
		test_change_value_of_env.c \
		test_tokenizer.c \
		test_split_quotes.c \
		../src/builtin_export.c \
		../src/builtin_env.c \
		../src/print_list.c \
		../src/builtin_unset.c \
		../src/builtin_pwd.c \
		../src/builtin_echo.c \
		../src/builtin_cd.c \
		../src/take_value_of_env.c \
		../src/status_error.c \
		../src/change_value_of_env.c \
		../src/tokenizer.c \
		../src/redirect_verify.c \
		../src/here_doc.c \
		../src/split_quotes.c \
		../src/here_doc_complement.c

		

OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
READFLAGS = -lreadline -lncurses

.c.o:
			${CC} ${CFLAGS} ${INCS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			make -C $(LIBFTPATH)
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT} ${READFLAGS}
				
clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all