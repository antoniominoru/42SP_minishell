/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:04:00 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/17 01:27:24 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	test_abs_path(char **cmd_tkn)
{
	char	**new_cmd;
	int		last;

	if (ft_strncmp(cmd_tkn[0], "\\", 1) && access(cmd_tkn[0], 0) == 0)
	{
		new_cmd = ft_split(cmd_tkn[0], '/');
		last = count_vector(new_cmd) - 1;
		cmd_tkn[0] = new_cmd[last];
	}
}

void	builtin_all(char *cmd, t_list **envp, char **cmd_tkn)
{
	test_abs_path(cmd_tkn);
	if (ft_strncmp(cmd_tkn[0], "export", ft_strlen(cmd_tkn[0])) == 0)
		builtin_export(cmd_tkn[1], envp, F_BUILTIN);
	else if (ft_strncmp(cmd_tkn[0], "unset", ft_strlen(cmd_tkn[0])) == 0)
		builtin_unset(cmd_tkn[1], envp, F_BUILTIN);
	else if (ft_strncmp(cmd_tkn[0], "env", ft_strlen(cmd_tkn[0])) == 0)
		builtin_env(*envp);
	else if (ft_strncmp(cmd_tkn[0], "exit", ft_strlen(cmd_tkn[0])) == 0)
		builtin_exit(envp, cmd, cmd_tkn);
	else if (ft_strncmp(cmd_tkn[0], "pwd", ft_strlen(cmd_tkn[0])) == 0)
		builtin_pwd();
	else if (ft_strncmp(cmd_tkn[0], "echo", ft_strlen(cmd_tkn[0])) == 0)
		builtin_echo(cmd_tkn);
	else if (ft_strncmp(cmd_tkn[0], "cd", ft_strlen(cmd_tkn[0])) == 0)
		builtin_cd(cmd_tkn[1], envp);
	else
		builtin_other(cmd_tkn, envp);
}
