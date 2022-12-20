/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_unset.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:45:19 by aminoru-          #+#    #+#             */
/*   Updated: 2022/12/20 23:47:21 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

// Arrage
char	*test_builtin_unset_initial(void)
{
	t_list *lst1 = ft_lstnew("First");

	// act
	builtin_export("Second", lst1);
	builtin_export("Third", lst1);
	builtin_unset("First", &lst1);
	
	//assert
	mu_assert("ERROR: builtin_unset_initial()", !strcmp(lst1->content, "Second"));
	mu_assert("ERROR: builtin_unset_initial()", !strcmp(lst1->next->content, "Third"));
	return (0);
}

char	*test_builtin_unset_between(void)
{
	t_list *lst1 = ft_lstnew("First");
	builtin_export("Second", lst1);
	builtin_export("Third", lst1);
	builtin_unset("Second", &lst1);
	
	mu_assert("ERROR: builtin_unset_between()", !strcmp(lst1->content, "First"));
	mu_assert("ERROR: builtin_unset_between()", !strcmp(lst1->next->content, "Third"));
	return (0);
}

char	*test_builtin_unset_finish(void)
{
	t_list *lst1 = ft_lstnew("First");
	builtin_export("Second", lst1);
	builtin_export("Third", lst1);
	builtin_unset("Third", &lst1);
	
	mu_assert("ERROR: builtin_unset_finish()", !strcmp(lst1->content, "First"));
	mu_assert("ERROR: builtin_unset_finish()", !strcmp(lst1->next->content, "Second"));
	return (0);
}
