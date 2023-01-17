/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_cd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:48:28 by aminoru-          #+#    #+#             */
/*   Updated: 2023/01/17 00:47:57 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
// # Arrage
char	*test_builtin_cd(void)
{
	t_list	*lst1 = NULL;
	char	*test = NULL;
	char	buffer[2048];
	char	*espec = getenv("HOME");
	
	lst1 = ft_lstnew(ft_strjoin("HOME=",getenv("HOME")));
	ft_lstadd_back(&lst1, ft_lstnew("OLDPWD=First"));
	ft_lstadd_back(&lst1, ft_lstnew("PWD=Second"));
	builtin_cd("~", &lst1);
	test = getcwd(buffer, 2048);

	// # Assert
	mu_assert("ERROR: builtin_cd() flag ~ ", !strcmp(test, espec));
	free(lst1);
	return (0);
}
