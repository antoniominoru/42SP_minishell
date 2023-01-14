/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_value_of_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 01:41:41 by aminoru-          #+#    #+#             */
/*   Updated: 2023/01/14 01:33:44 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_value_of_env(char *cmd, char *val, t_list **envp)
{
	t_list	*tmp;
	char	*value;

	tmp = *envp;
	value = ft_strjoin(cmd, ft_strjoin("=", val));
	if (ft_strncmp(cmd, tmp->content, ft_strlen(cmd)) == 0)
		tmp->content = value;
	while (tmp->next)
	{
		if (ft_strncmp(cmd, tmp->content, ft_strlen(cmd)) == 0)
		{
			tmp->content = value;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
