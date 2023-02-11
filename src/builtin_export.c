/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 02:02:38 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/11 01:06:24 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_export(char *cmd, t_list **envp, int flag)
{
	char	**cmd_args;
	char	*tmp;

	if (flag == F_BUILTIN)
		g_current_status = NO_ERROR;
	cmd_args = NULL;
	tmp = NULL;
	if (cmd)
	{
		cmd_args = ft_split(cmd, '=');
		if (count_vector(cmd_args) > 1)
		{
			builtin_unset(cmd_args[0], envp, F_INTERN);
			tmp = ft_strjoin("=", cmd_args[1]);
			ft_lstadd_back(envp, ft_lstnew(ft_strjoin(cmd_args[0], tmp)));
		}
		else
		{
			builtin_unset(cmd_args[0], envp, F_INTERN);
			ft_lstadd_back(envp, ft_lstnew(ft_strdup(cmd_args[0])));
		}
		free_tkn(cmd_args);
		free(tmp);
	}
	else
		print_env(*envp);
}

void	print_env(t_list *lst)
{
	while (lst->next)
	{
		printf("declare -x %s\n", lst->content);
		lst = lst->next;
	}
	printf("declare -x %s\n", lst->content);
}
