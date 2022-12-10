/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:04:00 by jvictor-          #+#    #+#             */
/*   Updated: 2022/12/10 03:54:00 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_all(char *cmd, t_list **envp, int status)
{
	if (ft_strncmp(cmd, "export", 6) == 0)
		status = builtin_export((cmd + 7), *envp);
	if (ft_strncmp(cmd, "unset", 5) == 0)
		status = builtin_unset((cmd + 6), envp);
	if (ft_strncmp(cmd, "env", 3) == 0)
		status = builtin_env(*envp);
	if (ft_strncmp(cmd, "exit", 4) == 0)
		status = builtin_exit(cmd);
	if (ft_strncmp(cmd, "pwd", 3) == 0)
		status = builtin_pwd();
	return (status);
}
