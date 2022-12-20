/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:18:23 by aminoru-          #+#    #+#             */
/*   Updated: 2022/12/20 23:11:44 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINUNIT_H
# define MINUNIT_H

# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line.h"
# include "../include/minishell.h"


/* file: minunit.h */
 #define mu_assert(message, test) do { if (!(test)) return message; } while (0)
 #define mu_run_test(test) do { char *message = test(); tests_run++; if (message) return message; } while (0)
 extern int tests_run;

#endif
 