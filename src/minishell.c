/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:41:53 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/16 16:06:57 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(char	*cmd, t_list *lst_env, char **path)
{
	char	buffer[2048];

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
			builtin_pipe_to_all(cmd, &lst_env);
		}
	}
}
