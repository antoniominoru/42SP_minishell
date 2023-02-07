/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:56:29 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/02 23:56:34 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_is_cmd(int c)
{
	if (c > ' ' && c <= '~')
		return (1);
	return (0);
}

int	have_cmd(char *cmd)
{
	while (*cmd)
	{
		if (ft_is_cmd(*cmd) == 1)
			return (1);
		cmd++;
	}
	return (0);
}
