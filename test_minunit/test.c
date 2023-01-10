/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:53:44 by aminoru-          #+#    #+#             */
/*   Updated: 2023/01/10 23:38:38 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

int tests_run = 0;

static char *all_tests(void)
{
	mu_run_test(test_builtin_export);
	mu_run_test(test_builtin_unset_initial);
	mu_run_test(test_builtin_unset_between);
	mu_run_test(test_builtin_unset_finish);
	mu_run_test(test_builtin_exit);
	mu_run_test(test_builtin_env);
	mu_run_test(test_builtin_pwd);
	mu_run_test(test_builtin_cd);
	mu_run_test(test_take_value_of_env);
	mu_run_test(test_builtin_echo);
	mu_run_test(test_change_value_of_env);
	mu_run_test(test_tokenizer);
	
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
