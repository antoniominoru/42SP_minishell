/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_cd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:48:28 by aminoru-          #+#    #+#             */
/*   Updated: 2023/01/11 01:31:10 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
// # Arrage
char	*test_builtin_cd(void)
{
	t_list	*lst1 = ft_lstnew("HOME=/home/coder/01_minisHELL");
	char	*test;
	char	*espec = "/home/coder/01_minisHELL";
	char	buffer[2048];
	
	// # Act
	builtin_cd("~", &lst1);
	test = getcwd(buffer, 2048);
	// # Assert
	mu_assert("ERROR: builtin_cd() flag ~ ", !strcmp(test, espec));
	free(lst1);
	return (0);
}

char	*test_builtin_cd2(void)
{
	t_list	*lst1 = ft_lstnew("OLDPWD=/home/coder/01_minisHELL/test_minunit");
	char	*test = "erro";
	char	*espec = "/home/coder/01_minisHELL/test_minunit";
	char	buffer[2048];
	
	// # Act
	if (builtin_cd("-", &lst1) != 0)
		test = getcwd(buffer, 2048);
	// # Assert
	mu_assert("ERROR: builtin_cd() flag - ", !strcmp(test, espec));
	free(lst1);
	return (0);
}