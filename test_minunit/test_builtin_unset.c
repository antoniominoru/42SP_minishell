/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_unset.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:45:19 by aminoru-          #+#    #+#             */
/*   Updated: 2023/01/16 23:49:43 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

char	*test_builtin_unset_initial(void)
{
	t_list *lst1 = NULL;
	ft_lstadd_back(&lst1, ft_lstnew("First=First"));
	ft_lstadd_back(&lst1, ft_lstnew("Second=Second"));
	ft_lstadd_back(&lst1, ft_lstnew("Third=Third"));
	builtin_unset("First", &lst1);
	
	mu_assert("ERROR: builtin_unset_finish() - 1", !strcmp(lst1->content, "Second=Second"));
	mu_assert("ERROR: builtin_unset_finish() - 2", !strcmp(lst1->next->content, "Third=Third"));
	return (0);
}

char	*test_builtin_unset_between(void)
{
	t_list *lst1 = NULL;
	ft_lstadd_back(&lst1, ft_lstnew("First=First"));
	ft_lstadd_back(&lst1, ft_lstnew("Second=Second"));
	ft_lstadd_back(&lst1, ft_lstnew("Third=Third"));
	builtin_unset("Second", &lst1);
	
	mu_assert("ERROR: builtin_unset_finish() - 1", !strcmp(lst1->content, "First=First"));
	mu_assert("ERROR: builtin_unset_finish() - 2", !strcmp(lst1->next->content, "Third=Third"));
	return (0);
}

char	*test_builtin_unset_finish(void)
{
	t_list *lst1 = NULL;
	ft_lstadd_back(&lst1, ft_lstnew("First=First"));
	ft_lstadd_back(&lst1, ft_lstnew("Second=Second"));
	ft_lstadd_back(&lst1, ft_lstnew("Third=Third"));
	builtin_unset("Third", &lst1);
	
	mu_assert("ERROR: builtin_unset_finish() - 1", !strcmp(lst1->content, "First=First"));
	mu_assert("ERROR: builtin_unset_finish() - 2", !strcmp(lst1->next->content, "Second=Second"));
	return (0);
}
