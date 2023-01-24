/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:04:00 by jvictor-          #+#    #+#             */
/*   Updated: 2023/01/24 00:35:09 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_all(char *cmd, t_list **envp, int status, char **cmd_tkn)
{
	if (ft_strncmp(cmd_tkn[0], "export", 6) == 0)
		status = builtin_export(cmd_tkn[1], envp);
	else if (ft_strncmp(cmd_tkn[0], "unset", 5) == 0)
		status = builtin_unset(cmd_tkn[1], envp);
	else if (ft_strncmp(cmd_tkn[0], "env", 3) == 0)
		status = builtin_env(*envp);
	else if (ft_strncmp(cmd_tkn[0], "exit", 4) == 0)
		builtin_exit();
	else if (ft_strncmp(cmd_tkn[0], "pwd", 3) == 0)
		status = builtin_pwd();
	else if (ft_strncmp(cmd_tkn[0], "echo", 4) == 0)
		builtin_echo(cmd_tkn, envp);
	else if (ft_strncmp(cmd_tkn[0], "cd", 2) == 0)
		status = builtin_cd(cmd_tkn[1], envp);
	else
		status = builtin_other(cmd, envp);
	return (status);
}
