/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:49:47 by aminoru-          #+#    #+#             */
/*   Updated: 2023/01/27 02:24:08 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

char	*test_builtin_exit(void)
{
	int result = builtin_exit();
	
	mu_assert("ERROR: builtin_exit()", (result == 0));
	return (0);
}
