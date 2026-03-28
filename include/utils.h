/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:00:00 by woosekim          #+#    #+#             */
/*   Updated: 2026/03/28 12:00:00 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"
# include <limits.h>
# include <unistd.h>
# include "stack.h"

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

/* Argument Validation */
void	check_argv(int ac, char **av);
int		*argv_to_number(int ac, char **av, int av_idx, int *num_arr_count);
void	free_av_arr(char **av_arr, int av_arr_idx);

/* General Utilities */
long	ft_atol(const char *str);
void	exit_error(void);
char	*ft_strjoin(char *s1, char *s2);

#endif
