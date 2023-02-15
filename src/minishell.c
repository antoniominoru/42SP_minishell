/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:41:53 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/14 16:35:36 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(char	*cmd, t_list *lst_env, char **path)
{
	char	buffer[2048];
	int		have_quotes;

	have_quotes = 0;
	while (1)
	{
		define_signals();
		if (*path)
			free(*path);
		*path = ft_strjoin(getcwd(buffer, 2048), " | (~~miniHELL~~)> ");
		cmd = readline(*path);
		if (cmd == NULL)
			exit_m_sh(&lst_env, cmd, NULL, g_current_status);
		else if (have_cmd(cmd))
		{
			ft_add_history(cmd);
			have_quotes = have_two_quotes(cmd);
			if (have_quotes)
				quotes_pipe_to_all(cmd, &lst_env);
			else
				builtin_pipe_to_all(cmd, &lst_env);
		}
	}
}
