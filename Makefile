# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 21:18:27 by aminoru-          #+#    #+#              #
#    Updated: 2022/11/30 21:23:30 by jvictor-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFTPATH = ./lib/libft/
LIBFT = ./lib/libft/libft.a
CC = gcc
READFLAGS = -lreadline -lncurses
CFLAG = -Wall -Werror -Wextra
INCS = -I ./include/
SRCS = 	./src/minishell.c \
		./src/history.c

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
