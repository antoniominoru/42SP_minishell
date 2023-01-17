/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 01:43:33 by aminoru-          #+#    #+#             */
/*   Updated: 2023/01/17 00:50:22 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_dir(char *cmd, t_list **envp)
{
	char	buffer[2048];
	char	*tmp;

	tmp = getcwd(buffer, 2048);
	change_value_of_env("OLDPWD", tmp, envp);
	if (chdir(cmd) != 0)
		printf("Error\n");
	tmp = getcwd(buffer, 2048);
	change_value_of_env("PWD", tmp, envp);
}

int	builtin_cd(char *cmd, t_list **envp)
{
	char	*tmp;

	if (!ft_strncmp(cmd, "~", 1))
	{
		tmp = take_value_of_env("HOME", envp);
		change_dir(tmp, envp);
	}
	else if (!ft_strncmp(cmd, "-", 1))
	{
		tmp = take_value_of_env("OLDPWD", envp);
		if (tmp == NULL)
			printf("Error\n");
		printf("%s\n", tmp);
		chdir(tmp);
	}
	else
		change_dir(cmd, envp);
	return (1);
}
