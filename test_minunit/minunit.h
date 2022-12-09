/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:18:23 by aminoru-          #+#    #+#             */
/*   Updated: 2022/04/05 19:07:43 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* file: minunit.h */
 #define mu_assert(message, test) do { if (!(test)) return message; } while (0)
 #define mu_run_test(test) do { char *message = test(); tests_run++; if (message) return message; } while (0)
 extern int tests_run;