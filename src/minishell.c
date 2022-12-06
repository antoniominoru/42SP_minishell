/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:41:53 by jvictor-          #+#    #+#             */
/*   Updated: 2022/12/06 00:58:25 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*cmd;
	t_list	*lst_env;
	int		status;

	cmd = NULL;
	lst_env = NULL;
	status = 1;
	if (argc > 1 && argv && envp)
		return (printf("erro ao executar, correto é: ./minishell\n"), 1);
	lst_env = env_to_lst(envp);
	if (lst_env == NULL)
		printf("erro");
	while (status)
	{
		cmd = readline("MiniHELL>>");
		ft_add_history(cmd);
		status = builtin_all(cmd, lst_env);
	}
	free(cmd);
}
