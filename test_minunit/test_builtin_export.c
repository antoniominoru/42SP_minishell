/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_export.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:08:09 by aminoru-          #+#    #+#             */
/*   Updated: 2023/01/16 23:53:33 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

char	*test_builtin_export(void)
{
	t_list *lst1 = NULL;
	ft_lstadd_back(&lst1, ft_lstnew("First=First"));
	ft_lstadd_back(&lst1, ft_lstnew("Second=Second"));
	builtin_export("Second=terceiro", &lst1);
	mu_assert("ERROR: builtin_export() - 1", !strcmp(lst1->content, "First=First"));
	mu_assert("ERROR: builtin_export() - 2", !strcmp(lst1->next->content, "Second=terceiro"));
	return (0);
}
