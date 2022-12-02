/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:04:00 by jvictor-          #+#    #+#             */
/*   Updated: 2022/12/01 20:56:54 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_list2(t_list *lst);

t_list  env_to_lst(char *envp[])
{
    t_list	*to_lst;
    int     i;

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
    print_list2(to_lst);
	return (*to_lst);
}

void	print_list2(t_list *lst)
{
	while (lst->next)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
	printf("%s\n", lst->content);
}
