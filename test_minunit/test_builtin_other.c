/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_other.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:18:34 by aminoru-          #+#    #+#             */
/*   Updated: 2023/01/12 01:42:32 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
// # Arrage
char	*test_builtin_other(void)
{
	t_list	*lst1 = ft_lstnew(ft_strjoin("PATH=",getenv("PATH")));
	char	*espec = "teste";
	char test[40];
	int		fd[2];
	int	saved_stdout = dup(STDOUT_FILENO);

	if (pipe(fd) == -1)
		printf("pipex error");
  	dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
	
	// # Act
	// builtin_other("cat test.txt", &lst1);
	printf("teste");
		
	fflush(stdout);
	read(fd[0], test, 40);
	dup2(saved_stdout, STDOUT_FILENO);

	// # Assert
	mu_assert("ERROR: builtin_other()", !strcmp(test, espec));
	free(lst1);
	return (0);
}
