/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pipe_to_all.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:10:20 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/18 02:05:49 by jvictor-         ###   ########.fr       */
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

int		cont_pipe_token(char **cmd)
{
	int i;
	char **tmp;

	i = 0;
	tmp = cmd;
	while (*tmp)
	{
		if (!ft_strncmp(*tmp, "|",1))
			i++;
		tmp++;
	}
	return (i);
}

char	**ft_split_token(char **cmd_tkn)
{
	int		c_pipe;
	int		c_loop;
	int		c_new_tkn;
	char	*tmp;
	char	**fim;

	c_loop = 0;
	c_new_tkn = 0;
	tmp = NULL;
	fim = NULL;
	c_pipe = cont_pipe_token(cmd_tkn);
	fim = malloc((c_pipe + 2) * sizeof(char *));
	while(cmd_tkn[c_loop] != NULL)
	{
		if (!ft_strncmp(cmd_tkn[c_loop], "|",1))
		{
			fim[c_new_tkn] = tmp;
			printf("%s\n",fim[c_new_tkn]);
			tmp = NULL;
			c_new_tkn++;
			c_loop++;
		}
		if (tmp == NULL)
			tmp = ft_strdup(" \"");
		else
			tmp = ft_strjoin(tmp, " \"");
		tmp = ft_strjoin(tmp, cmd_tkn[c_loop]);
		tmp = ft_strjoin(tmp, "\" ");
		c_loop++;
	}
	fim[c_new_tkn] = tmp;
	fim[c_new_tkn + 1] = NULL;
	// printf("%s\n",fim[c_new_tkn]);
	return (fim);
}

void	builtin_pipe_to_all(char *cmd, t_list **envp)
{
	int		old_in;
	char	**split_token;
	char	**cmd_tkn;

	old_in = 0;
	cmd_tkn = NULL;
	cmd_tkn = tokenizer(cmd, cmd_tkn, envp);
	if (verify_cmd(cmd_tkn) == -1)
		status_error("Invalid caracter", ERROR);
	else
	{
		split_token = ft_split_token(cmd_tkn);
		// split_token = ft_split(cmd, '|');
		line_in_pipe(split_token, envp, &old_in, 0);
		free_tkn(split_token);
	}
	if (old_in != 0)
		close(old_in);
}
