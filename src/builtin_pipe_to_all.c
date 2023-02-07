/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pipe_to_all.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:10:20 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/08 00:17:54 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**allocate2(char **s, int *j, int how_many, char **other)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < how_many - 1)
	{
		if (i == *j)
		{
			k++;
		}
		other[i] = ft_substr(s[k], 0, ft_strlen(s[k]));
		if (!other)
		{
			free_tkn(other);
			return (NULL);
		}
		i++;
		k++;
	}
	--*j;
	other[i] = NULL;
	return (other);
}
static	char	**reallocate_cmd2(char **s, int *j, int how_many)
{
	char	**other;

	other = malloc(how_many * sizeof(char *));
	if (!other)
		return (NULL);
	other = allocate2(s, j, how_many, other);
	s = other;
	return (s);
}
static int	ft_isredirect(char *cmd, char *redirect)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == redirect[0] && \
			cmd[i - 1] != redirect[0] && \
			cmd[i + 1] != redirect[0]
		)
			return (1);
		if (cmd[i] == redirect[0] && \
			cmd[i - 1] != redirect[0] && \
			cmd[i + 1] == redirect[0] && \
			cmd[i + 2] != redirect[0]
		)
			return (2);
		i++;
	}
	return (0);
}

static int	ft_tknredirect(char **cmd, char *redirect)
{
	int	i;
	char **tmp;

	i = 0;
	tmp = cmd;
	while (tmp[i])
	{
		if (ft_isredirect(tmp[i], redirect))
			return (ft_isredirect(tmp[i], redirect));
		i++;
	}
	return (0);
}

static int	ft_tknredirect2(char **cmd, char *redirect)
{
	int	i;
	char **tmp;

	i = 0;
	tmp = cmd;
	while (tmp[i])
	{
		if (ft_isredirect(tmp[i], redirect))
			return (i);
		i++;
	}
	return (0);
}


static void io_redirect(char *cmd, int config, int io_re)
{
	int	fd = 0;

	if (io_re == 0)
		fd = open(cmd, config);
	else if (io_re == 1)
		fd = open(cmd, config, 0777);
	dup2(fd, io_re);
	close(fd);
}

static int count_tkn(char **cmd)
{
	int	i;
	char **tmp;

	i = 0;
	tmp = cmd;
	while (tmp[i])
		i++;
	return (i);
}

char	**redirect_verify(char **cmd, int *old_in)
{
	if (!old_in)
		printf("error\n");
	int test;
	if (ft_tknredirect(cmd, ">") == 1)
	{
		test = ft_tknredirect2(cmd, ">") + 1;
		io_redirect(cmd[test], O_WRONLY | O_CREAT | O_TRUNC, 1);
		cmd = reallocate_cmd2(cmd, &test, count_tkn(cmd));
		cmd = reallocate_cmd2(cmd, &test, count_tkn(cmd));
	}
	else if (ft_tknredirect(cmd, ">>") == 2)
	{
		test = ft_tknredirect2(cmd, ">>") + 1;
		io_redirect(cmd[test], O_WRONLY | O_CREAT | O_APPEND, 1);
		cmd = reallocate_cmd2(cmd, &test, count_tkn(cmd));
		cmd = reallocate_cmd2(cmd, &test, count_tkn(cmd));
	}
	else if (ft_tknredirect(cmd, "<") == 1)
	{
		test = ft_tknredirect2(cmd, "<") + 1;
		io_redirect(cmd[test], O_RDONLY | O_CREAT, 0);
		cmd = reallocate_cmd2(cmd, &test, count_tkn(cmd));
		cmd = reallocate_cmd2(cmd, &test, count_tkn(cmd));
	}
	// else if (ft_isredirect(*cmd, "<<") == 2)
	// 	printf("redirect_verify - <<\n");
	return (cmd);
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

void	builtin_pipe_to_all(char *cmd, t_list **envp)
{
	int		old_in;
	char	**split_token;

	old_in = 0;
	split_token = ft_split(cmd, '|');
	line_in_pipe(split_token, envp, &old_in, 0);
	if (old_in != 0)
		close(old_in);
	free_tkn(split_token);
}
