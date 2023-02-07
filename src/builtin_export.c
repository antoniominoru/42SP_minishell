/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 02:02:38 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/08 00:51:40 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_export(char *cmd, t_list **envp)
{
	char	**cmd_args;
	char	*tmp;

	g_current_status = NO_ERROR;
	//precisa colocar os possiveis erros (tem card no kanban)
	tmp = NULL;
	cmd_args = ft_split(cmd, '=');
	builtin_unset(cmd_args[0], envp);
	tmp = ft_strjoin("=", cmd_args[1]);
	ft_lstadd_back(envp, ft_lstnew(ft_strjoin(cmd_args[0], tmp)));
	free_tkn(cmd_args);
	free(tmp);
}
