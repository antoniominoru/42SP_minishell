/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:05:00 by jvictor-          #+#    #+#             */
/*   Updated: 2022/12/27 02:46:22 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**tokenizer(char *cmd, char **cmd_tkn)
{
	char	**cmd_tkn_new;

	if (cmd_tkn != NULL)
		free_tkn(cmd_tkn);
	cmd_tkn_new = ft_split(cmd, ' ');
	return (cmd_tkn_new);
}
