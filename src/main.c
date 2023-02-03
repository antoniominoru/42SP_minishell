/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:23:46 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/03 22:12:49 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*cmd;
	t_list	*lst_env;
	char	*path;

	cmd = NULL;
	path = NULL;
	lst_env = env_to_lst(envp);
	if (argc > 1 && argv && envp)
		return (printf("erro ao executar, correto é: ./minishell\n"), 1);
	if (lst_env == NULL)
		printf("erro");
	define_signals();
	minishell(cmd, lst_env, &path);
	free_part(&lst_env, &cmd, &path);
}
