/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tokenizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:42:23 by jvictor-          #+#    #+#             */
/*   Updated: 2023/01/17 01:28:17 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

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

char	*test_tokenizer(void)
{
	char **normal;
	char **multiple_spaces;
	int qtd_normal;
	int qtd_multiple;

	normal = NULL;
	multiple_spaces = NULL;
	qtd_normal = 0;
	qtd_multiple = 0;
	normal = tokenizer("esse teste tem espaços unicos entre as palavras", normal);
	multiple_spaces = tokenizer("esse         teste  tem. varios espaços     entre as palavras", multiple_spaces);
	while (normal[qtd_normal])
		qtd_normal++;
	while (multiple_spaces[qtd_multiple])
		qtd_multiple++;
	mu_assert("ERROR: tokenizer() com espaços unicos", qtd_normal == 8);
	mu_assert("ERROR: tokenizer() com varios espaços", qtd_multiple == 8);
	free_tkn(normal);
	free_tkn(multiple_spaces);
	return (0);
}