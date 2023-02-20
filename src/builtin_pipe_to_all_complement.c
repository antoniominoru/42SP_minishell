/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pipe_to_all_complement.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:09:31 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/20 11:07:54 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cont_pipe_token(char **cmd)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = cmd;
	while (*tmp)
	{
		if (!ft_strncmp(*tmp, "|", 1))
			i++;
		tmp++;
	}
	return (i);
}

char	**ft_s_token(int c_all, char *tmp, char	**end, char **cmd_tkn)
{
	char	*swap;

	while (*cmd_tkn)
	{
		if (!ft_strncmp(*cmd_tkn, "|", 1))
		{
			end[c_all] = tmp;
			tmp = NULL;
			c_all++;
			cmd_tkn++;
		}
		if (tmp == NULL)
			swap = ft_strdup("");
		else
		{
			swap = ft_strjoin(tmp, " ");
			free(tmp);
		}
		tmp = ft_strjoin(swap, *cmd_tkn);
		free(swap);
		cmd_tkn++;
	}
	end[c_all] = tmp;
	end[c_all + 1] = NULL;
	return (end);
}

char	**ft_split_token(char **cmd_tkn)
{
	int		c_all;
	char	*tmp;
	char	**end;

	c_all = 0;
	tmp = NULL;
	end = NULL;
	end = malloc((cont_pipe_token(cmd_tkn) + 2) * sizeof(char *));
	end = ft_s_token(c_all, tmp, end, cmd_tkn);
	return (end);
}

char	*ft_new_string(char **cmd_tkn)
{
	int		c_all;
	char	*new_str;
	char	*tmp;
	char	*tmp2;

	c_all = 0;
	new_str = NULL;
	new_str = ft_strdup("");
	while (*cmd_tkn)
	{
		tmp2 = new_str;
		tmp = ft_strjoin(new_str, " ");
		new_str = ft_strjoin(tmp, *cmd_tkn);
		cmd_tkn++;
		free(tmp);
		free(tmp2);
	}
	return (new_str);
}

void	line_in_pipe1(t_all *all, int id)
{
	if (all->split_token[id + 1] != NULL)
	{
		builtin_pipe1(all, 0, id);
		line_in_pipe1(all, id + 1);
	}
	else
		builtin_pipe1(all, 1, id);
}
