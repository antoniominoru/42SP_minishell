/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pipe_to_all.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:10:20 by aminoru-          #+#    #+#             */
/*   Updated: 2023/01/20 02:33:42 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// usar recursividade
int	builtin_pipe(char *cmd, t_list **envp, int status)
{
	if (cmd == NULL && envp == NULL)
		return (0);
	return (status);
}

int	ft_ispipe(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '|')
			return (1);
		i++;
	}
	return (0);
}

int	builtin_pipe_to_all(char *cmd, t_list **envp, int status)
{
	char	**cmd_tkn;

	cmd_tkn = NULL;
	if (ft_ispipe(cmd))
	{
		status = builtin_pipe(cmd, envp, status);
	}
	else
	{
		cmd_tkn = tokenizer(cmd, cmd_tkn);
		status = builtin_all(cmd, envp, status, cmd_tkn);	
	}
	return (status);
}
