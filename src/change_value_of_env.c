/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_value_of_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 01:41:41 by aminoru-          #+#    #+#             */
/*   Updated: 2023/01/17 00:06:53 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_value_of_env(char *cmd, char *val, t_list **envp, int flag)
{
	builtin_export(ft_strjoin(cmd, ft_strjoin("=", val)), envp, flag);
	return (1);
}
