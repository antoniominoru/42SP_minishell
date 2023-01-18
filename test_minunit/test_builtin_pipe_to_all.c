/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_pipe_to_all.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 00:46:42 by aminoru-          #+#    #+#             */
/*   Updated: 2023/01/18 00:55:04 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

char	*test_builtin_cd_ft_ispipe(void)
{
	int		result1;
	int		result2;
	int		result3;

	result1 = ft_ispipe("tert | wertt");	
	result2 = ft_ispipe("tert wertt");
	result3 = ft_ispipe("tert | wertt | fsfge");	

	mu_assert("ERROR: test_builtin_cd_ft_ispipe - 1", (result1 == 1));
	mu_assert("ERROR: test_builtin_cd_ft_ispipe - 2", (result2 == 0));
	mu_assert("ERROR: test_builtin_cd_ft_ispipe - 3", (result3 == 1));
	return (0);
}
