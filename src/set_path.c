/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:37:38 by aminoru-          #+#    #+#             */
/*   Updated: 2023/02/16 17:53:00 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_path(t_list **envp)
{
	builtin_export("PATH=/usr/local/sbin:/usr/local/bin:\
	/usr/sbin:/usr/bin:/sbin:/bin:./", envp, F_BUILTIN);
}
