/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:41:53 by jvictor-          #+#    #+#             */
/*   Updated: 2022/11/28 21:10:23 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int	main(int argc, char *argv[], envp)
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