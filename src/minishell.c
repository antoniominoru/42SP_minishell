/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:41:53 by jvictor-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/05 23:28:13 by aminoru-         ###   ########.fr       */
=======
/*   Updated: 2022/12/05 20:15:53 by jvictor-         ###   ########.fr       */
>>>>>>> 94708d5 (update builtin all)
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*cmd;
	t_list	*lst_env;
	int		status;

	cmd = NULL;
	lst_env = NULL;
	status = 1;
	if (argc > 1 && argv && envp)
		return (printf("erro ao executar, correto é: ./minishell\n"), 1);
	lst_env = env_to_lst(envp);
	if (lst_env == NULL)
		printf("erro");
	while (status)
	{
		cmd = readline("MiniHELL>>");
		ft_add_history(cmd);
<<<<<<< HEAD
		
=======
		status = builtin_all(cmd);
>>>>>>> 94708d5 (update builtin all)
	}
	free(cmd);
}
