/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:53:44 by aminoru-          #+#    #+#             */
/*   Updated: 2022/12/09 20:40:42 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "minunit.h"
#include "../include/minishell.h"
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line.h"

int tests_run = 0;

static char	*test_builtin_export(void)
{
	t_list *lst1 = ft_lstnew("First");
	builtin_export("Second", lst1);
	mu_assert("ERROR: ft_lstadd_back()", !strcmp(lst1->content, "First"));
	mu_assert("ERROR: ft_lstadd_back()", !strcmp(lst1->next->content, "Second"));
	return (0);
}

static char *all_tests(void)
{
	mu_run_test(test_builtin_export);
	return (0);
}

int	main(void)
{
	char *result;

	result = all_tests();	
	if (result)
		printf("%s\n", result);
	else
		printf("All Tests Passed\n");
	printf("Test run: %d\n", tests_run);
	return (0);
}
