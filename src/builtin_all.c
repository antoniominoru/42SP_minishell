/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:04:00 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/19 17:05:01 by jvictor-         ###   ########.fr       */
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

static	int	len_builtin(int len, int len_builtin)
{
	if (len == len_builtin)
		return (len);
	else if (len < len_builtin)
		return (len_builtin);
	else
		return (len);
}

void	builtin_all(char *cmd, t_list **envp, char **cmd_tkn)
{
	int	len;

	len = ft_strlen(cmd_tkn[0]);
	test_abs_path(cmd_tkn);
	if (!ft_strncmp(cmd_tkn[0], "export", len_builtin(len, 6)))
		builtin_export(cmd_tkn[1], envp, F_BUILTIN);
	else if (!ft_strncmp(cmd_tkn[0], "unset", len_builtin(len, 5)))
		builtin_unset(cmd_tkn[1], envp, F_BUILTIN);
	else if (!ft_strncmp(cmd_tkn[0], "env", len_builtin(len, 3)))
		builtin_env(*envp);
	else if (!ft_strncmp(cmd_tkn[0], "exit", len_builtin(len, 4)))
		builtin_exit(envp, cmd, cmd_tkn);
	else if (!ft_strncmp(cmd_tkn[0], "pwd", len_builtin(len, 3)))
		builtin_pwd();
	else if (!ft_strncmp(cmd_tkn[0], "echo", len_builtin(len, 4)))
		builtin_echo(cmd_tkn);
	else if (!ft_strncmp(cmd_tkn[0], "cd", len_builtin(len, 2)))
		builtin_cd(cmd_tkn[1], envp);
	else
		builtin_other(cmd_tkn, envp);
}
