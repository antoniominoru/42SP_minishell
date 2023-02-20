/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_value_of_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 01:41:41 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/20 07:48:30 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_value_of_env(char *cmd, char *val, t_list **envp, int flag)
{
	char	*tmp_join;
	char	*tmp_join_2;
	
	tmp_join = ft_strjoin("=", val);
	tmp_join_2 = ft_strjoin(cmd, tmp_join);
	builtin_export(tmp_join_2, envp, flag);
	free(tmp_join);
	free(tmp_join_2);
	return (1);
}
