/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:23:46 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/18 20:28:11 by aminoru-         ###   ########.fr       */
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
	if (lst_env == NULL)
		status_error("Error", ERROR_ONE);
	set_path(&lst_env);
	if (argc > 1 && argv && envp)
		return (status_error("too many arguments. correct is: ./minishell",
				ERROR), ERROR_ONE);
	minishell(cmd, lst_env, &path);
	free_part(&lst_env, &cmd, &path);
}
