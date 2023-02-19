/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:55:28 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/19 22:17:39 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	initialize_var(char **cmd, t_list **lst_env, char **path, char **envp)
{
	*cmd = NULL;
	*path = NULL;
	*lst_env = env_to_lst(envp);
	rl_bind_key ('\t', rl_insert);
}
