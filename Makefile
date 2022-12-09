# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 21:18:27 by aminoru-          #+#    #+#              #
#    Updated: 2022/12/07 02:41:50 by jvictor-         ###   ########.fr        #
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
		./src/exit.c \
		./src/signals.c \
		./src/free_all.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} 
			make -C $(LIBFTPATH)
			${CC} -o ${NAME} ${CFLAG} ${OBJS} ${LIBFT} ${READFLAGS}

.c.o:
			${CC} ${CFLAG} ${INCS} -c $< -o ${<:.c=.o}

clean:
			make clean -C ./lib/libft
			rm -f ${OBJS}

fclean: clean
			make fclean -C ./lib/libft
			rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
