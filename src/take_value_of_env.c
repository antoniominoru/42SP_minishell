/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_value_of_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:26:30 by aminoru-          #+#    #+#             */
/*   Updated: 2022/12/22 23:28:07 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*take_value_of_env(char *cmd, t_list **envp)
{
	t_list	*tmp;
	char	*value;

	tmp = *envp;
	value = NULL;
	if (ft_strncmp(cmd, tmp->content, ft_strlen(cmd)) == 0)
		value = tmp->content + ft_strlen(cmd) + 1;
	while (tmp->next)
	{
		if (ft_strncmp(cmd, tmp->content, ft_strlen(cmd)) == 0)
			value = tmp->content + ft_strlen(cmd) + 1;
		tmp = tmp->next;
	}
	return (value);
}
