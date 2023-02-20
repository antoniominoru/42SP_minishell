/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_other.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:17:36 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/20 03:44:02 by jvictor-         ###   ########.fr       */
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

int	builtin_other_int(char **cmd, t_list **envp, pid_t pid_dad)
{
	char	**cmd_args;
	char	*comand;
	char	**path_env;
	char	*temp_path;
	char	*tmp;

	path_env = NULL;
	temp_path = ft_strdup(take_value_of_env("PATH", envp));
	path_env = ft_split(temp_path, ':');
	cmd_args = cmd;
	tmp = ft_strdup(cmd_args[0]);
	comand = get_cmd(tmp, path_env);
	if (!comand)
	{
		kill(pid_dad, SIGUSR1);
		exit(127);
	}
	execve(comand, cmd_args, path_env);
	free_tkn(cmd_args);
	free_tkn(path_env);
	free(comand);
	free(tmp);
	free(temp_path);
	return (1);
}

void	builtin_other(char **cmd, t_list **envp)
{
	int		pid;
	int		status;
	pid_t	pid_dad;

	g_current_status = NO_ERROR;
	pid_dad = getpid();
	define_signals_fork();
	pid = fork();
	if (pid == 0)
		builtin_other_int(cmd, envp, pid_dad);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		status = WEXITSTATUS(status);
		status_error(NULL, status);
	}
}
