/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pipe_to_all.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:10:20 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/20 09:35:19 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_create(int *old_in, int last)
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

void	builtin_pipe(char *cmd, t_list **envp, int *old_in, int last)
{
	int		fd_saved[2];
	char	**cmd_tkn;

	cmd_tkn = NULL;
	fd_saved[0] = dup(STDIN_FILENO);
	fd_saved[1] = dup(STDOUT_FILENO);
	pipe_create(old_in, last);
	cmd_tkn = tokenizer(cmd, cmd_tkn, envp, 1);
	cmd_tkn = redirect_verify(cmd_tkn, old_in);
	builtin_all(cmd, envp, cmd_tkn);
	dup2(fd_saved[0], STDIN_FILENO);
	close(fd_saved[0]);
	dup2(fd_saved[1], STDOUT_FILENO);
	close(fd_saved[1]);
	free_tkn(cmd_tkn);
}

void	builtin_pipe1(t_all *all, int last, int id)
{
	int		fd_saved[2];
	char	**cmd_tkn;

	cmd_tkn = NULL;
	fd_saved[0] = dup(STDIN_FILENO);
	fd_saved[1] = dup(STDOUT_FILENO);
	pipe_create(all->old_in, last);
	cmd_tkn = tokenizer(all->split_token[id], cmd_tkn, all->envp, 1);
	cmd_tkn = redirect_verify(cmd_tkn, all->old_in);
	builtin_all1(all, cmd_tkn);
	dup2(fd_saved[0], STDIN_FILENO);
	close(fd_saved[0]);
	dup2(fd_saved[1], STDOUT_FILENO);
	close(fd_saved[1]);
	free_tkn(cmd_tkn);
}

void	line_in_pipe(char **split_token, t_list **envp, int *old_in, int id)
{
	if (split_token[id + 1] != NULL)
	{
		builtin_pipe(split_token[id], envp, old_in, 0);
		line_in_pipe(split_token, envp, old_in, id + 1);
	}
	else
		builtin_pipe(split_token[id], envp, old_in, 1);
}

void	line_in_pipe1(t_all *all, int id)
{
	if (all->split_token[id + 1] != NULL)
	{
		builtin_pipe1(all, 0, id);
		line_in_pipe1(all, id + 1);
	}
	else
		builtin_pipe1(all, 1, id);
}

int	cont_pipe_token(char **cmd)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = cmd;
	while (*tmp)
	{
		if (!ft_strncmp(*tmp, "|", 1))
			i++;
		tmp++;
	}
	return (i);
}

int	init_verify_cmd(t_list **envp, char **split_token, char **cmd_tkn, char *cmd)
{
	int		old_in;
    t_all   all;
	old_in = 0;

	if (verify_cmd(cmd_tkn) == -1)
	{
		status_error("Invalid caracter", ERROR);
		return (0);
	}
	else
    {
        all.cmd = cmd;
		all.split_token = split_token;
        all.envp = envp;
        all.old_in = &old_in;
        line_in_pipe1(&all, 0);
    }
	return (old_in);
}

void	builtin_pipe_to_all(char *cmd, t_list **envp)
{
	char	**split_token;
	char	**cmd_tkn;
	int		old_in;

	cmd_tkn = NULL;
	split_token = NULL;
	cmd_tkn = tokenizer(cmd, cmd_tkn, envp, 0);
	split_token = ft_split_token(cmd_tkn);
	if (have_two_quotes(cmd) == -1)
	{
		status_error("Invalid caracter, aspas nao fechadas", ERROR);
		return ;
	}
	old_in = init_verify_cmd(envp, split_token, cmd_tkn, cmd);
	if (old_in != 0)
		close(old_in);
	free_tkn(cmd_tkn);
	free_tkn(split_token);
}
