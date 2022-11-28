/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:41:53 by jvictor-          #+#    #+#             */
/*   Updated: 2022/11/28 23:25:37 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	char *string;
    char ex;

    ex = 'a';
    string = &ex;
	while(*string != 'b')
	{
		string = readline(">>>>>>>>>");
        printf("%s\n", string);
	}
    free(string);
}
//gcc -o minishell minishell.c -lreadline -lncurses
//TEste