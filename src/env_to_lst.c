/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:04:00 by jvictor-          #+#    #+#             */
/*   Updated: 2022/12/09 02:47:15 by aminoru-         ###   ########.fr       */
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
			to_lst = ft_lstnew(envp[i]);
		else
			ft_lstadd_back(&to_lst, ft_lstnew(envp[i]));
		i++;
	}
	return (to_lst);
}
