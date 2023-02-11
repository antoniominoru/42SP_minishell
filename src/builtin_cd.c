/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 01:43:33 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/11 20:11:14 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_dir(char *cmd, t_list **envp)
{
	char	buffer[2048];
	char	*tmp;

	tmp = getcwd(buffer, 2048);
	change_value_of_env("OLDPWD", tmp, envp, F_INTERN);
	if (chdir(cmd) != 0)
		status_error("Error CD", ERROR_ONE);
	tmp = getcwd(buffer, 2048);
	change_value_of_env("PWD", tmp, envp, F_INTERN);
}

void	builtin_cd(char *cmd, t_list **envp)
{
	char	*tmp;

	g_current_status = NO_ERROR;
	if (!ft_strncmp(cmd, "~", 1))
	{
		tmp = take_value_of_env("HOME", envp);
		change_dir(tmp, envp);
	}
	else if (!ft_strncmp(cmd, "-", 1))
	{
		tmp = take_value_of_env("OLDPWD", envp);
		if (tmp == NULL)
			status_error("Error CD OLDPWD", ERROR_ONE);
		printf("%s\n", tmp);
		chdir(tmp);
	}
	else
		change_dir(cmd, envp);
}
