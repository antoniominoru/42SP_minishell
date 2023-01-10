/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_take_value_of_env.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:31:38 by aminoru-          #+#    #+#             */
/*   Updated: 2023/01/10 00:20:06 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
// # Arrage
char	*test_take_value_of_env(void)
{
	t_list	*lst1 = ft_lstnew("HOME=teste");
	char	*test;
	char	*espec = "teste";
	
	// # Act
	test = take_value_of_env("HOME", &lst1);
	// # Assert
	mu_assert("ERROR: test_take_value_of_env()", !strcmp(test, espec));
	free(lst1);	
	return (0);
}
