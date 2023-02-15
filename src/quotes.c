/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:44:11 by jvictor-          #+#    #+#             */
/*   Updated: 2023/02/14 17:00:49 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	position_quotes(int pos, char q)
{
	if (!pos_quo_sin_2 && q == '\'')
		pos_quo_sin_2 = pos;
	else if (!pos_quo_sin_1 && q == '\'')
		pos_quo_sin_1 = pos;
	else if (!pos_quo_dbl_2 && q == '\"')
		pos_quo_dbl_2 = pos;
	else if (!pos_quo_dbl_1 && q == '\"')
		pos_quo_dbl_1 = pos;
}

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
		{
			position_quotes(len, '\'');
			how_many_single++;
		}
		if (cmd[len] == '\"')
		{
			position_quotes(len, '\"');
			how_many_double++;
		}
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

void	remove_quotes(char **cmd)
{
	char	*temp;

	temp = ft_strtrim(cmd[pos_quo_sin_1], "\'");
	//trim n da certo nessa situacao de agr pq ele tira tudo do comeco e do fim
	free(*cmd);
	*cmd = temp;
	// preciso saber onde elas estao
	// se elas sao iguais
}
