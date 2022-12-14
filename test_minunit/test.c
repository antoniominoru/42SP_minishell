/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:53:44 by aminoru-          #+#    #+#             */
/*   Updated: 2022/12/14 01:29:33 by aminoru-         ###   ########.fr       */
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
// Arrage
static char	*test_builtin_unset_initial(void)
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

static char	*test_builtin_unset_between(void)
{
	t_list *lst1 = ft_lstnew("First");
	builtin_export("Second", lst1);
	builtin_export("Third", lst1);
	builtin_unset("Second", &lst1);
	
	mu_assert("ERROR: builtin_unset_between()", !strcmp(lst1->content, "First"));
	mu_assert("ERROR: builtin_unset_between()", !strcmp(lst1->next->content, "Third"));
	return (0);
}

static char	*test_builtin_unset_finish(void)
{
	t_list *lst1 = ft_lstnew("First");
	builtin_export("Second", lst1);
	builtin_export("Third", lst1);
	builtin_unset("Third", &lst1);
	
	mu_assert("ERROR: builtin_unset_finish()", !strcmp(lst1->content, "First"));
	mu_assert("ERROR: builtin_unset_finish()", !strcmp(lst1->next->content, "Second"));
	return (0);
}

static char	*test_builtin_export(void)
{
	t_list *lst1 = ft_lstnew("First");
	builtin_export("Second", lst1);
	mu_assert("ERROR: builtin_export()", !strcmp(lst1->content, "First"));
	mu_assert("ERROR: builtin_export()", !strcmp(lst1->next->content, "Second"));
	return (0);
}

static char	*test_builtin_exit(void)
{
	int result = builtin_exit();
	
	mu_assert("ERROR: builtin_exit()", (result == 0));
	return (0);
}

static char	*test_builtin_env(void)
{
	t_list *lst1 = ft_lstnew("First");
	char test[10];
	int		fd[2];
	int	saved_stdout = dup(STDOUT_FILENO);

	if (pipe(fd) == -1)
		printf("pipex error");
  	dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
	builtin_env(lst1);
	fflush(stdout);
	read(fd[0], test, 11);
	dup2(saved_stdout, STDOUT_FILENO);
	mu_assert("ERROR: builtin_env()", !strcmp(test, "First\n"));
	
	return (0);
}

static char *all_tests(void)
{
	mu_run_test(test_builtin_export);
	mu_run_test(test_builtin_unset_initial);
	mu_run_test(test_builtin_unset_between);
	mu_run_test(test_builtin_unset_finish);
	mu_run_test(test_builtin_exit);
	mu_run_test(test_builtin_env);
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
