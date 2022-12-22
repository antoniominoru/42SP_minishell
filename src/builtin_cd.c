/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 01:43:33 by aminoru-          #+#    #+#             */
/*   Updated: 2022/12/22 02:29:44 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *take_env(char *cmd, t_list **envp)
{
	t_list	*tmp;
	char	*value;

	tmp = *envp;
	value = NULL;
	while(tmp->next)
	{
		if (ft_strncmp(cmd, tmp->content, ft_strlen(cmd)) == 0)
		{
			value = tmp->content + ft_strlen(cmd) + 1;
			printf("%s\n", value);
		}
		tmp = tmp->next;
	}
	return (value);
}

int	builtin_cd(char *cmd, t_list **envp)
{
	if (take_env(cmd, envp))
		return (1);
	return (0);
}
