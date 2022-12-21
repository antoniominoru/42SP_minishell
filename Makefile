# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 21:18:27 by aminoru-          #+#    #+#              #
#    Updated: 2022/12/21 00:50:50 by aminoru-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFTPATH = ./lib/libft/
LIBFT = ./lib/libft/libft.a
CC = gcc
READFLAGS = -lreadline -lncurses
CFLAG = -Wall -Werror -Wextra -g3
INCS = -I ./include/
SRCS = 	./src/minishell.c \
		./src/env_to_lst.c \
		./src/print_list.c \
		./src/builtin_all.c \
		./src/signals.c \
		./src/ft_add_history.c \
		./src/free_all.c \
		./src/builtin_env.c \
		./src/builtin_export.c  \
		./src/builtin_unset.c  \
		./src/builtin_exit.c \
		./src/builtin_pwd.c \
		./src/builtin_cd.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} 
			make -C $(LIBFTPATH)
			${CC} -o ${NAME} ${CFLAG} ${OBJS} ${LIBFT} ${READFLAGS}

.c.o:
			${CC} ${CFLAG} ${INCS} -c $< -o ${<:.c=.o}

clean:
			make clean -C ./lib/libft
			make clean -C ./test_minunit
			rm -f ${OBJS}

fclean: clean
			make fclean -C ./lib/libft
			make fclean -C ./test_minunit
			rm -f ${NAME}

test:
			make
			make -C ./test_minunit
			clear
			./test_minunit/run_test
			norminette -R CheckForbiddenSourceHeader ./src/ ./include/ ./lib/

test2:
			make
			make -C ./test_minunit
			clear
			./test_minunit/run_test

re: fclean all

.PHONY: all clean fclean re
