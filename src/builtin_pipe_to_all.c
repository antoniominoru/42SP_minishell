/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pipe_to_all.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:10:20 by aminoru-          #+#    #+#             */
/*   Updated: 2023/01/18 02:00:08 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_pipe(char *cmd, t_list **envp, int status)
{
	// int		fd[2];
	// pid_t	pid1;
	// pid_t	pid2;
	char	**cmd_tkn_pipe;
	char	**cmd_tkn_1 = NULL;
	// char	**cmd_tkn_2 = NULL;
	
	cmd_tkn_pipe = ft_split(cmd, '|');
	cmd_tkn_1 = tokenizer(cmd_tkn_pipe[0], cmd_tkn_1);
	// cmd_tkn_2 = tokenizer(cmd_tkn_pipe[1], cmd_tkn_2);
	printf("%s\n",cmd_tkn_pipe[0]);
	printf("%s\n",cmd_tkn_pipe[1]);
	printf("%s\n",cmd_tkn_1[0]);
	printf("%s\n",cmd_tkn_1[1]);
	if (envp == NULL || status == 0)
		return (0);
	
	// if (pipe(fd) == -1)
	// 	printf("pipex error");
	// pid1 = fork();
	// if (pid1 < 0)
	// 	printf("Fork error");
	// if (pid1 == 0)
	// {
	// 	dup2(fd[1], 1);
	// 	dup2(fd[0], 0);
	// 	status = builtin_all(cmd, envp, status, cmd_tkn_1);
	// }
	// pid2 = fork();
	// if (pid2 < 0)
	// 	printf("Fork error");
	// if (pid2 == 0)
	// {
	// 	dup2(fd[1], 1);
	// 	dup2(fd[0], 0);
	// 	status = builtin_all(cmd, envp, status, cmd_tkn_2);
	// }
	// close(fd[0]);
	// close(fd[1]);
	
	// waitpid(pid1, NULL, 0);
	// waitpid(pid2, NULL, 0);
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
		builtin_pipe(cmd, envp, status);
	}
	else
	{
		cmd_tkn = tokenizer(cmd, cmd_tkn);
		builtin_all(cmd, envp, status, cmd_tkn);	
	}
	return (status);
}
