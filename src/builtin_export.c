/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 02:02:38 by aminoru-          #+#    #+#             */
/*   Updated: 2023/01/17 02:24:22 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_export(char *cmd, t_list **envp)
{
	char	**cmd_args;
	char	*tmp;

	tmp = NULL;
	cmd_args = ft_split(cmd, '=');
	builtin_unset(cmd_args[0], envp);
	tmp = ft_strjoin(cmd_args[0], ft_strjoin("=", cmd_args[1]));
	ft_lstadd_back(envp, ft_lstnew(tmp));
	return (1);
}
