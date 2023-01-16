/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 02:02:38 by aminoru-          #+#    #+#             */
/*   Updated: 2023/01/16 23:55:24 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_export(char *cmd, t_list **envp)
{
	char	**cmd_args;

	cmd_args = ft_split(cmd, '=');
	builtin_unset(cmd_args[0], envp);
	ft_lstadd_back(envp, ft_lstnew(cmd));
	return (1);
}
