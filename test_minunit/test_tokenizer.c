/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tokenizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:42:23 by jvictor-          #+#    #+#             */
/*   Updated: 2023/01/31 02:57:53 by jvictor-         ###   ########.fr       */
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
	t_list	*lst1 = ft_lstnew("HOME=teste");

	normal = NULL;
	multiple_spaces = NULL;
	qtd_normal = 0;
	qtd_multiple = 0;
	normal = tokenizer("esse teste tem espaços unicos entre as palavras", normal, &lst1);
	multiple_spaces = tokenizer("esse         teste  tem. varios espaços     entre as palavras", multiple_spaces, &lst1);
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