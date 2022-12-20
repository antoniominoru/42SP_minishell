/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_builtin_export.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:08:09 by aminoru-          #+#    #+#             */
/*   Updated: 2022/12/20 23:22:16 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"

static char	*test_builtin_export(void)
{
	t_list *lst1 = ft_lstnew("TESTE=teste");
	builtin_export("FAST=fast", lst1);
	mu_assert("ERROR: builtin_export()", !strcmp(lst1->content, "TESTE=teste"));
	mu_assert("ERROR: builtin_export()", !strcmp(lst1->next->content, "FAST=fast"));
	return (0);
}
