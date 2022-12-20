/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_pwd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:27:17 by aminoru-          #+#    #+#             */
/*   Updated: 2022/12/21 00:27:53 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

char	*test_builtin_pwd(void)
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
