/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 01:43:33 by aminoru-          #+#    #+#             */
/*   Updated: 2023/01/11 00:37:08 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_cd(char *cmd, t_list **envp)
{
	char	buffer[2048];
	char	*tmp;

	if (take_value_of_env("HOME", envp) == NULL)
		return (0);
	if (ft_strnstr(cmd, "~",1))
	{
		tmp = getcwd(buffer, 2048);
		change_value_of_env("OLDPWD", tmp, envp);
		if (chdir(take_value_of_env("HOME", envp)) != 0)
			return(0);
		tmp = getcwd(buffer, 2048);
		change_value_of_env("PWD", tmp, envp);
	}
	return (1);
}
