/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:04:00 by jvictor-          #+#    #+#             */
/*   Updated: 2022/12/06 01:20:28 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int builtin_all(char *cmd, t_list *lst)
{
    int status;

    status = 1;
	if (ft_strncmp(cmd, "env", 3) == 0)
		status = builtin_env(lst);
	if (ft_strncmp(cmd, "exit", 4) == 0)
    	status = builtin_exit(cmd);
    return (status);
}
