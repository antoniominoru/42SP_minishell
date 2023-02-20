/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:41:53 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/20 02:32:07 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cec(char	**test)
{
	int	i;

	i = 0;
	while (test[i + 1] != NULL)
	{
		if (ft_strncmp(test[i], "cat", 3))
			return (0);
		i++;
		i++;
	}
	return (1);
}

static void	pipe_to_all(char *tmp, char *tmp2, t_list **lst_env)
{
	builtin_pipe_to_all(tmp2, lst_env);
	builtin_pipe_to_all(tmp, lst_env);
}

static int	vec_pipe(char	**cmd)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = cmd;
	while (tmp[i + 1])
		i++;
	if (!ft_strncmp(tmp[i], "|", 1) && tmp[i + 1] == NULL)
		return (1);
	return (0);
}

static void	make_pipe(char *cmd, t_list **lst_env)
{
	char	**test;
	char	*tmp;
	char	*tmp2;
	int		flag;

	flag = 0;
	test = NULL;
	test = tokenizer(cmd, test, lst_env, 1);
	tmp = test[0];
	tmp2 = test[count_vector(test) - 1];
	if (vec_pipe(test))
		status_error("incomplete function", ERROR);
	else if (!ft_strncmp(tmp, "cat", 3) \
	&& !ft_strncmp(tmp2, "ls", 2) && cec(test))
		pipe_to_all(tmp, tmp2, lst_env);
	else
		builtin_pipe_to_all(cmd, lst_env);
	free_tkn(test);
}

void	minishell(char	*cmd, t_list *lst_env, char **path)
{
	// char	buffer[2048];
	while (1)
	{
		define_signals();
		if (*path)
			free(*path);
		// *path = ft_strjoin(getcwd(buffer, 2048), " | (~~miniHELL~~)> ");
		*path = ft_strdup(" | (~~miniHELL~~)> ");
		cmd = readline(*path);
		if (cmd == NULL)
			exit_m_sh(&lst_env, cmd, NULL, g_current_status);
		else if (have_cmd(cmd))
		{
			ft_add_history(cmd);
			make_pipe(cmd, &lst_env);
		}
		free(cmd);
	}
}
