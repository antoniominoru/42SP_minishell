/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pipe_to_all.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:10:20 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/14 23:13:16 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	pipe_create(int *old_in, int last)
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
	int		fd_saved[2];
	char	**cmd_tkn;

	cmd_tkn = NULL;
	fd_saved[0] = dup(STDIN_FILENO);
	fd_saved[1] = dup(STDOUT_FILENO);
	pipe_create(old_in, last);
	cmd_tkn = tokenizer(cmd, cmd_tkn, envp);
	cmd_tkn = redirect_verify(cmd_tkn, old_in);
	builtin_all(cmd, envp, cmd_tkn);
	dup2(fd_saved[0], STDIN_FILENO);
	close(fd_saved[0]);
	dup2(fd_saved[1], STDOUT_FILENO);
	close(fd_saved[1]);
	free_tkn(cmd_tkn);
}

static void	line_in_pipe(char **split_token, t_list **envp, int *old_in, int id)
{
	if (split_token[id + 1])
	{
		builtin_pipe(split_token[id], envp, old_in, 0);
		line_in_pipe(split_token, envp, old_in, id + 1);
	}
	else
		builtin_pipe(split_token[id], envp, old_in, 1);
}

void	verify_cat(char **cmd, t_list **envp)
{
	char	**c_test;
	char	**c_test2;
	char	*new_cmd;

	c_test = NULL;
	c_test2 = NULL;
	new_cmd = NULL;
	if (ft_is_caract(*cmd, "|"))
	{
		c_test = ft_split(*cmd, '|');
		c_test2 = tokenizer(c_test[0], c_test2, envp);
		if (ft_strncmp(c_test2[0], "cat", 3) == 0 && count_vector(c_test2) == 1)
		{
			new_cmd = ft_strjoin("echo | ", *cmd);
			*cmd = new_cmd;
		}
	}
}

void	builtin_pipe_to_all(char *cmd, t_list **envp)
{
	int		old_in;
	char	**split_token;

	old_in = 0;
	verify_cat(&cmd, envp);
	split_token = ft_split(cmd, '|');
	line_in_pipe(split_token, envp, &old_in, 0);
	if (old_in != 0)
		close(old_in);
	free_tkn(split_token);
}
