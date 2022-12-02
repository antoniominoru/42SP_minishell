/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:41:53 by jvictor-          #+#    #+#             */
/*   Updated: 2022/12/01 20:52:48 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*cmd;

	cmd = NULL;
	if (argc > 1 && argv && envp)
		return (printf("erro ao executar, correto é: ./minishell\n"), 1);
	env_to_lst(envp);
	while (1)
	{
		cmd = readline("MiniHELL>>");
		ft_add_history(cmd);
	}
	free(cmd);
}
