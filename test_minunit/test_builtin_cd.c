/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_cd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:48:28 by aminoru-          #+#    #+#             */
/*   Updated: 2023/01/10 00:26:45 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
// # Arrage
char	*test_builtin_cd(void)
{
	t_list	*lst1 = ft_lstnew("HOME=teste");
	int		test;
	int		espec = 1;
	
	// # Act
	test = builtin_cd(&lst1);
	// # Assert
	mu_assert("ERROR: builtin_cd()", (test == espec));
	free(lst1);
	return (0);
}
