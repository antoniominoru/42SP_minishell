/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builin_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 01:53:42 by aminoru-          #+#    #+#             */
/*   Updated: 2022/12/08 23:12:33 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_del(char *content)
{
	(void)content;
}

int	builtin_unset_2(char *cmd, t_list *tmp, t_list *to_remove)
{
	while (tmp->next->next)
	{
		if (ft_strncmp(tmp->next->content, cmd, ft_strlen(cmd)) == 0)
			break ;
		tmp = tmp->next;
	}
	to_remove = tmp->next;
	if (ft_strncmp(to_remove->content, cmd, ft_strlen(cmd)) == 0)
	{
		tmp->next = tmp->next->next;
		ft_del(to_remove->content);
		free(to_remove);
	}
	else
		printf("Error!\n");
	return (1);
}

int	builtin_unset(char *cmd, t_list **envp)
{
	t_list	*tmp;
	t_list	*to_remove;

	tmp = *envp;
	to_remove = NULL;
	if (ft_strlen(cmd) > 2 && \
	ft_strncmp(tmp->content, cmd, ft_strlen(cmd)) == 0)
	{
		*envp = tmp->next;
		to_remove = tmp;
		ft_del(to_remove->content);
		free(to_remove);
		return (1);
	}
	builtin_unset_2(cmd, tmp, to_remove);
	return (1);
}
