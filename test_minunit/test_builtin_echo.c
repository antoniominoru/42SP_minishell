/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_echo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 02:25:38 by jvictor-          #+#    #+#             */
/*   Updated: 2023/01/11 00:39:33 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

char	*test_builtin_echo(void)
{
	char *cmd = "test";
	char test[10];
	int		fd[2];
	int	saved_stdout = dup(STDOUT_FILENO);

	if (pipe(fd) == -1)
		printf("pipex error");
  	dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
	builtin_echo(cmd);
	fflush(stdout);
	read(fd[0], test, 11);
	dup2(saved_stdout, STDOUT_FILENO);
	mu_assert("ERROR: builtin_echo()", !strcmp(test, "test\n"));
	return (0);
}
