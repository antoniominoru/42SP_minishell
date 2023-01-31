/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pipe_to_all.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:10:20 by aminoru-          #+#    #+#             */
/*   Updated: 2023/01/31 18:55:45 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isredirect(char *cmd, char *redirect)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == *redirect)
			return (1);
		i++;
	}
	return (0);
}

static void	redirect_verify(char *cmd, int *old_in)
{
	// if (ft_strncmp(const char *s1, const char *s2, size_t n))
	// split_token = ft_split(cmd, '>');
	if (!old_in)
		printf("error\n");
	if (ft_isredirect(cmd, ">"))
		printf("redirect_verify - 1\n");
}

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
	redirect_verify(cmd, old_in);//trabalhando aqui
	cmd_tkn = tokenizer(cmd, cmd_tkn, envp);
	builtin_all(cmd, envp, cmd_tkn);
	dup2(fd_saved[0], STDIN_FILENO);
	close(fd_saved[0]);
	dup2(fd_saved[1], STDOUT_FILENO);
	close(fd_saved[1]);
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

void	builtin_pipe_to_all(char *cmd, t_list **envp)
{
	int		old_in;
	char	**split_token;

	old_in = 0;
	split_token = ft_split(cmd, '|');
	line_in_pipe(split_token, envp, &old_in, 0);
	if (old_in != 0)
		close(old_in);
}