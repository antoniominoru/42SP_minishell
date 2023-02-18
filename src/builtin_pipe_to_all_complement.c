/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pipe_to_all_complement.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:09:31 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/18 20:18:00 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_split_token(char **ctkn)
{
	int		c_all;
	char	*t;
	char	**end;

	c_all = 0;
	t = NULL;
	end = malloc((cont_pipe_token(ctkn) + 2) * sizeof(char *));
	while (*ctkn)
	{
		if (!ft_strncmp(*ctkn, "|", 1))
		{
			end[c_all] = t;
			t = NULL;
			c_all++;
			ctkn++;
		}
		if (t == NULL)
			t = ft_strjoin(" ", ft_strdup(";"));
		else
			t = ft_strjoin(t, ft_strjoin(" ", ft_strdup(";")));
		t = ft_strjoin(ft_strjoin(t, *ctkn), ft_strjoin(ft_strdup(";"), " "));
		ctkn++;
	}
	end[c_all] = t;
	return (end);
}

char	*ft_new_string(char **cmd_tkn)
{
	int		c_all;
	char	*new_string;
	char	*tmp;

	c_all = 0;
	new_string = NULL;
	new_string = ft_strdup("");
	while (*cmd_tkn)
	{

		tmp = ft_strjoin(new_string, " ");
		new_string = ft_strjoin(tmp, *cmd_tkn);
		cmd_tkn++;
		free(tmp);
	}
	return (new_string);
}
