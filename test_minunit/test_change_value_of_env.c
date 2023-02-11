/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_change_value_of_env.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:31:38 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/11 01:08:51 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
// # Arrage
char	*test_change_value_of_env(void)
{
	t_list *lst1 = NULL;

	ft_lstadd_back(&lst1, ft_lstnew("HOME=First"));
	ft_lstadd_back(&lst1, ft_lstnew("Second=Second2"));
	
	// # Act
	change_value_of_env("HOME", "mudoud", &lst1, 0);
	// # Assert
	mu_assert("ERROR: test_change_value_of_env()", !strcmp(lst1->next->content, "HOME=mudoud"));
	free(lst1);	
	return (0);
}
