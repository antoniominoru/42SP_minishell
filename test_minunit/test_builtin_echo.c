/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_echo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 02:25:38 by jvictor-          #+#    #+#             */
/*   Updated: 2023/01/13 02:30:56 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

char	*test_builtin_echo(void)
{
	char *cmd = "test";
	char **pp_cmd = NULL;
	char test[10];
	int		fd[2];
	int	saved_stdout = dup(STDOUT_FILENO);
	t_list	*lst1 = ft_lstnew("HOME=teste");

	pp_cmd = tokenizer(cmd, pp_cmd);
	if (pipe(fd) == -1)
		printf("pipex error");
  	dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
	builtin_echo(pp_cmd, &lst1);
	fflush(stdout);
	read(fd[0], test, 11);
	dup2(saved_stdout, STDOUT_FILENO);
	printf("que isso: %s\n", test);
	mu_assert("ERROR: builtin_echo()", !strcmp(test, "test \n"));
	return (0);
}
