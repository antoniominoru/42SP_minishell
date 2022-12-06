/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builin_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 01:53:42 by aminoru-          #+#    #+#             */
/*   Updated: 2022/12/06 23:30:02 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_del(char *content)
{
	(void)content;
}

int builtin_unset(char *cmd, t_list *envp)
{
	t_list	*tmp;
	t_list	*to_remove;

	tmp = envp;
	while (tmp->next->next)
		tmp = tmp->next;
	to_remove = tmp->next;
	if (ft_strncmp(to_remove->content, cmd, ft_strlen(cmd)) == 0)
	{
		tmp->next = NULL;
		ft_del(to_remove->content);
		free(to_remove);
	}
	else
		printf("Error!\n");
	return (1);
}
