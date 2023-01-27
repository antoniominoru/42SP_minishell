/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pipe_to_all.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:10:20 by aminoru-          #+#    #+#             */
/*   Updated: 2023/01/27 02:15:54 by aminoru-         ###   ########.fr       */
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

static void pipe_create(int *old_in, int last)
{
	int	pipe_new[2];

	dup2(*old_in, STDIN_FILENO);
	if (*old_in != 0)
		close(*old_in);
	if (last)
		return ;
	pipe(pipe_new);
	dup2(pipe_new[1], STDOUT_FILENO);
	close(pipe_new[1]);
	*old_in = dup(pipe_new[0]);
	close(pipe_new[0]);
}

static void	builtin_pipe(char *cmd, t_list **envp, int *old_in, int last)
{
	if (!old_in)
		printf("%i\n", *old_in);
// Salvar FD originais
	int	fd_saved[2];
	save_fd(fd_saved);
// criar pipe
	pipe_create(old_in, last);
	char	**cmd_tkn = NULL;
	cmd_tkn = tokenizer(cmd, cmd_tkn);
	builtin_all(cmd, envp, cmd_tkn);
// restaurar FD
	restore_fd(fd_saved);
}

static void line_in_pipe(char *cmd, t_list **envp, int *old_in)
{
	int	i = 0;
	char	**split_token;

	while(cmd[i])
	{
		if (cmd[i] == '|')
		{
			split_token = ft_split(cmd, '|');
			builtin_pipe(split_token[0], envp, old_in, 0);
			line_in_pipe(split_token[1], envp, old_in);
			break;
		}
		i++;
	}
	if (!ft_ispipe(cmd))
		builtin_pipe(cmd, envp, old_in, 1);
}

int	builtin_pipe_to_all(char *cmd, t_list **envp)
{
	int	old_in;

	old_in = 0;
	line_in_pipe(cmd, envp, &old_in);
	if (old_in != 0)
		close(old_in);
	return (1);
}
