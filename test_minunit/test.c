/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:53:44 by aminoru-          #+#    #+#             */
/*   Updated: 2022/12/20 23:45:41 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

int tests_run = 0;

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

static char *test_builtin_pwd(void)
{
	char *buffer_pwd;
	char *join;
	char test[25];
	int		fd[2];
	int	saved_stdout = dup(STDOUT_FILENO);

	if (pipe(fd) == -1)
		printf("pipex error");
  	dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
	builtin_pwd();
	fflush(stdout);
	read(fd[0], test, 26);
	dup2(saved_stdout, STDOUT_FILENO);
	buffer_pwd = getcwd(NULL, 0);
	join = ft_strjoin(buffer_pwd, "\n");
	mu_assert("ERROR: builtin_pwd()", !strcmp(test, join));
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
	mu_run_test(test_builtin_pwd);
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
