/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:44:11 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/15 01:58:00 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//se tem menos de 2 aspas ret = 0
//se tem 2 aspas ret = 1
//se tem mais de 2 aspas ret = 2
int	have_two_quotes(char *cmd)
{
	int	how_many_single;
	int	how_many_double;
	int	len;

	len = ft_strlen(cmd) - 1;
	how_many_single = 0;
	how_many_double = 0;
	while (len)
	{
		if (cmd[len] == '\'')
			how_many_single++;
		if (cmd[len] == '\"')
			how_many_double++;
		len--;
	}
	if (how_many_single == 2
		|| how_many_double == 2)
		return (1);
	if (how_many_single > 2
		|| how_many_double > 2)
		return (2);
	return (0);
}
