/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:41:53 by jvictor-          #+#    #+#             */
/*   Updated: 2022/11/30 23:09:46 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[]) //char *envp[])
{
	if (argc > 1 && argv)
		return (printf("erro ao executar, correto é: ./minishell\n"), 1);
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
