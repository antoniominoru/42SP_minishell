/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_echo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 02:25:38 by jvictor-          #+#    #+#             */
/*   Updated: 2023/01/31 03:08:15 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

char	*test_builtin_echo(void)
{
	char *cmd = "echo joao victor shrek   $asdasd  $HOME";
	char **pp_cmd = NULL;
	char test[100];
	int		fd[2];
	int	saved_stdout = dup(STDOUT_FILENO);
	t_list	*lst1 = ft_lstnew("HOME=teste");

	pp_cmd = tokenizer(cmd, pp_cmd, &lst1);
	if (pipe(fd) == -1)
		printf("pipex error");
  	dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
	builtin_echo(pp_cmd);
	fflush(stdout);
	read(fd[0], test, 101);
	dup2(saved_stdout, STDOUT_FILENO);
	printf("que isso: \n\n%s\n\n\n", test);
	mu_assert("ERROR: builtin_echo()", !strcmp(test, "joao victor shrek teste\n"));
	return (0);
}
