/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_other.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:17:36 by aminoru-          #+#    #+#             */
/*   Updated: 2023/01/12 01:34:38 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_other(char *cmd, t_list **envp)
{
	if (cmd == 0)
		return (0);
	if (ft_lstsize(*envp) == 0)
		return (0);
	return (1);
}