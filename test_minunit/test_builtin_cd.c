/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_cd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:48:28 by aminoru-          #+#    #+#             */
/*   Updated: 2023/01/11 00:40:23 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
// # Arrage
char	*test_builtin_cd(void)
{
	t_list	*lst1 = ft_lstnew("HOME=/home/coder");
	char	*test;
	char	*espec = "/home/coder";
	char	buffer[2048];
	
	// # Act
	builtin_cd("~", &lst1);
	test = getcwd(buffer, 2048);
	// # Assert
	mu_assert("ERROR: builtin_cd()", !strcmp(test, espec));
	free(lst1);
	return (0);
}

char	*test_builtin_cd2(void)
{
	t_list	*lst1 = ft_lstnew("HOME=/home/coder");
	char	*test;
	char	*espec = "/home/coder";
	char	buffer[2048];
	
	// # Act
	builtin_cd("~", &lst1);
	test = getcwd(buffer, 2048);
	// # Assert
	mu_assert("ERROR: builtin_cd()", !strcmp(test, espec));
	free(lst1);
	return (0);
}