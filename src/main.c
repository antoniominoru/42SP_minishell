/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:23:46 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/06 00:51:01 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_current_status;

int	main(int argc, char *argv[], char *envp[])
{
	char	*cmd;
	t_list	*lst_env;
	char	*path;

	cmd = NULL;
	path = NULL;
	status_error(NULL, NO_ERROR);
	lst_env = env_to_lst(envp);
	if (argc > 1 && argv && envp)
		return (status_error("too many arguments. correct is: ./minishell",
				ERROR), 1);
	if (lst_env == NULL)
		printf("erro");
	define_signals();
	minishell(cmd, lst_env, &path);
	free_part(&lst_env, &cmd, &path);
}
