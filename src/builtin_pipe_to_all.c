/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pipe_to_all.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:10:20 by aminoru-          #+#    #+#             */
/*   Updated: 2023/01/24 02:43:28 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static void	old_in(int	*fd)
{
	*fd = 0;
}

static void	save_fd(int *fd)
{
	fd[0] = dup(STDIN_FILENO);
	fd[1] = dup(STDOUT_FILENO);
}

static void	restore_fd(int *fd)
{
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
}

int	builtin_pipe(char *cmd, t_list **envp, int status, int *old_in)
{
	if (cmd == NULL && envp == NULL)
		return (0);
// Salvar FD originais
	int	fd_saved[2];
	save_fd(fd_saved);
	
// criar pipe
	int	new_pipe[2];
	dup2(*old_in, STDIN_FILENO);
	if (*old_in != 0)
		close(*old_in);
	pipe(new_pipe);
	dup2(new_pipe[1], STDOUT_FILENO);
	close(new_pipe[1]);
	*old_in = dup(new_pipe[0]);
	close(new_pipe[0]);

	// builtin_env(*envp);
	char test[4];
	fflush(stdout);
	read(new_pipe[0], test, 5);
	
// restaurar FD
	restore_fd(fd_saved);

	printf("\nFuncionou!! - %s|\n", test);

	return (status);
}



int	builtin_pipe_to_all(char *cmd, t_list **envp, int status)
{
	int	fd_in;

	old_in(&fd_in);
	if (ft_ispipe(cmd))
	{
		status = builtin_pipe(cmd, envp, status, &fd_in);
	}
	else
	{
		char	**cmd_tkn = NULL;
		cmd_tkn = tokenizer(cmd, cmd_tkn);
		status = builtin_all(cmd, envp, status, cmd_tkn);	
	}
	return (status = 1);
}
