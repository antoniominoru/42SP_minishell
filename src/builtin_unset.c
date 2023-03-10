/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 01:53:42 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/20 07:43:07 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_unset_2(char *cmd, t_list *tmp, t_list *to_remove)
{
	while (tmp->next->next)
	{
		if (ft_strlen(cmd) > 1 && \
		ft_strncmp(tmp->next->content, cmd, ft_strlen(cmd)) == 0)
			break ;
		tmp = tmp->next;
	}
	to_remove = tmp->next;
	if (ft_strlen(cmd) > 1 && \
	ft_strncmp(to_remove->content, cmd, ft_strlen(cmd)) == 0)
	{
		tmp->next = tmp->next->next;
		free(to_remove->content);
		free(to_remove);
	}
	return (1);
}

int	builtin_unset(char *cmd, t_list **envp, int flag)
{
	t_list	*tmp;
	t_list	*to_remove;

	if (flag == F_BUILTIN)
		g_current_status = NO_ERROR;
	if (!cmd)
		return (0);
	tmp = *envp;
	to_remove = NULL;
	if (ft_strlen(cmd) > 1 && \
	ft_strncmp(tmp->content, cmd, ft_strlen(cmd)) == 0)
	{
		*envp = tmp->next;
		to_remove = tmp;
		free(to_remove->content);
		free(to_remove);
		return (1);
	}
	builtin_unset_2(cmd, tmp, to_remove);
	return (1);
}
