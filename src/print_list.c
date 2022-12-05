/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 21:08:18 by jvictor-          #+#    #+#             */
/*   Updated: 2022/12/01 21:17:12 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_list(t_list *lst)
{
	while (lst->next)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
	printf("%s\n", lst->content);
}
