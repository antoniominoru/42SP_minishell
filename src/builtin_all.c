/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:04:00 by jvictor-          #+#    #+#             */
/*   Updated: 2023/01/31 23:25:59 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_all(char *cmd, t_list **envp, char **cmd_tkn)
{
	if (ft_strncmp(cmd_tkn[0], "export", 6) == 0)
		builtin_export(cmd_tkn[1], envp);
	else if (ft_strncmp(cmd_tkn[0], "unset", 5) == 0)
		builtin_unset(cmd_tkn[1], envp);
	else if (ft_strncmp(cmd_tkn[0], "env", 3) == 0)
		builtin_env(*envp);
	else if (ft_strncmp(cmd_tkn[0], "exit", 4) == 0)
		builtin_exit(envp, cmd, cmd_tkn);
	else if (ft_strncmp(cmd_tkn[0], "pwd", 3) == 0)
		builtin_pwd();
	else if (ft_strncmp(cmd_tkn[0], "echo", 4) == 0)
		builtin_echo(cmd_tkn);
	else if (ft_strncmp(cmd_tkn[0], "cd", 2) == 0)
		builtin_cd(cmd_tkn[1], envp);
	else
		builtin_other(cmd, envp);
}
