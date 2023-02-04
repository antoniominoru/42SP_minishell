/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 02:02:38 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/04 01:21:49 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_export(char *cmd, t_list **envp)
{
	char	**cmd_args;
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	cmd_args = ft_split(cmd, '=');
	builtin_unset(cmd_args[0], envp);
	tmp = ft_strjoin("=", cmd_args[1]);
	tmp2 = ft_strjoin(cmd_args[0], tmp);
	ft_lstadd_back(envp, ft_lstnew(tmp2));
	free_tkn(cmd_args);
	free(tmp);
	free(tmp2);
}
