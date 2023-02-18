/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:41:53 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/18 20:43:57 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	verify_cat(char **cmd, t_list **envp)
// {
// 	char	**c_test;
// 	char	**c_test2;
// 	char	*new_cmd;

// 	c_test = NULL;
// 	c_test2 = NULL;
// 	new_cmd = NULL;
// 	if (ft_is_caract(*cmd, "|"))
// 	{
// 		c_test = ft_split(*cmd, '|');
// 		c_test2 = tokenizer(c_test[0], c_test2, envp);
// 		if (ft_strncmp(c_test2[0], "cat", 3) == 0 && count_vector(c_test2) == 1)
// 		{
// 			new_cmd = ft_strjoin("echo | ", *cmd);
// 			*cmd = new_cmd;
// 		}
// 	}
// }

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
