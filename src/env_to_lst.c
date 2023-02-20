/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:04:00 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/20 07:17:02 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*env_to_lst(char *envp[])
{
	t_list	*to_lst;
	int		i;

	i = 0;
	to_lst = NULL;
	while (envp[i])
	{
		if (to_lst == NULL)
			to_lst = ft_lstnew(ft_strdup(envp[i]));
		else
			ft_lstadd_back(&to_lst, ft_lstnew(ft_strdup(envp[i])));
		i++;
	}
	return (to_lst);
}
