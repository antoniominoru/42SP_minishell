/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:41:53 by jvictor-          #+#    #+#             */
/*   Updated: 2022/11/28 22:12:35 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[]) //char *envp[])
{
	if (argc > 1 && argv)
		return (printf("erro ao executar, correto é: ./minishell\n"), 1);
	printf("Funcionou!\n");
 	char *string;
    char ex;

    ex = 'a';
    string = &ex;
 	while(*string != 'q')
 	{
 		string = readline("MiniHELL>>");
         printf("%s\n", string);
 	}
     free(string);
}
