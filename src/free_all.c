/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 02:38:52 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/03 20:56:10 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_lst_env(t_list **lst_env)
{
	t_list	*aux;
	t_list	*temp;

	aux = *lst_env;
	if (aux == NULL)
		return ;
	while (aux != NULL)
	{
		temp = aux->next;
		free(aux);
		aux = temp;
	}
	*lst_env = NULL;
}

void	free_tkn(char **cmd_tkn)
{
	int	i;

	i = 0;
	while (cmd_tkn[i])
	{
		free(cmd_tkn[i]);
		i++;
	}
	free(cmd_tkn);
}

void	free_part(t_list **lst_env, char *cmd, char *path)
{
	rl_clear_history();
	free_lst_env(lst_env);
	free(cmd);
	free(path);
}

void	free_all(t_list **lst_env, char *cmd, char **cmd_tkn)
{
	rl_clear_history();
	free_lst_env(lst_env);
	if (cmd_tkn != NULL)
		free_tkn(cmd_tkn);
	free(cmd);
}
