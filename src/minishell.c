/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:41:53 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/03 22:12:44 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(char	*cmd, t_list *lst_env, char **path)
{
	char	buffer[2048];

	while (1)
	{
		if (*path)
			free(*path);
		*path = ft_strjoin(getcwd(buffer, 2048), " | (~~miniHELL~~)> ");
		cmd = readline(*path);
		if (cmd == NULL)
			break ;
		else if (have_cmd(cmd))
		{
			ft_add_history(cmd);
			builtin_pipe_to_all(cmd, &lst_env);
		}
	}
}
