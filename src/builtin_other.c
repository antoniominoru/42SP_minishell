/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_other.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:17:36 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/11 00:50:30 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_cmd(char *cmd, char **paths)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

int	builtin_other_int(char **cmd, t_list **envp)
{
	char	**cmd_args;
	char	*comand;
	char	**path_env;

	path_env = NULL;
	path_env = ft_split(ft_strdup(take_value_of_env("PATH", envp)), ':');
	cmd_args = cmd;
	comand = get_cmd(cmd_args[0], path_env);
	if (!comand)
	{
		status_error("First command not found", 127);
		exit(127);
	}
	//resolver erro de quando o comando n é encontrado (processo filho n altera o do processo pai)
	execve(comand, cmd_args, path_env);
	free_tkn(cmd_args);
	free_tkn(path_env);
	free(comand);
	return (1);
}

void	builtin_other(char **cmd, t_list **envp)
{
	int		pid;

	g_current_status = NO_ERROR;
	define_signals_fork();
	pid = fork();
	if (pid == 0)
		builtin_other_int(cmd, envp);
	waitpid(pid, NULL, 0);
}
